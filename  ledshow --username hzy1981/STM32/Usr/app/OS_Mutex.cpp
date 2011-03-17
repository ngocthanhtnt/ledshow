#define OS_MUTEX_C
#include "OS_Includes.h"

#if OS_MUTEX_EN>0
//初始化互斥信号量,互斥信号量的ID由应用程序自己固定
//Val为互斥信号量的初始值，1表示资源被占用，0表示资源已释放
//创建成功返回1，失败返回0
OS_INT8U OS_Mutex_Init(OS_INT8U ID,OS_INT8U Val)
{
  if(ID>=OS_EVENT_NUM)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
  OS_Event[ID].Type=OS_MUTEX;
  OS_Event[ID].Value=(Val EQ 0)?0:1;
  
#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(OS_Event[ID]);//设置校验和
#endif
  
  OS_SET_STRUCT_HT(OS_Event[ID]);
  return 1; 
}

//Post互斥信号量,成功返回1，失败返回0
OS_INT8U OS_Mutex_Post(OS_INT8U ID)
{
#if OS_CS_EN>0
  if(OS_CHECK_STRUCT_SUM(OS_Event[ID]) EQ 0)
    OS_ASSERT_FAILED();
#endif

#if OS_MUTEX_LOCK_CHK_EN>0
  if(OS_CHECK_STRUCT_HT(OS_Task_Event[Task_Info.Cur_Task_ID]) EQ 0)
    OS_ASSERT_FAILED();
#endif
  
  if(ID>=OS_EVENT_NUM)
  {
    OS_ASSERT_FAILED();
    return 0;
  }

  if(OS_Event[ID].Type!=OS_MUTEX)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
#if OS_MUTEX_LOCK_CHK_EN>0
  /*
  //如果系统中的信号量都是资源互斥型(不是用来同步)，可以打开这段程序，避免错误的释放信号量
  if(OS_GET_BIT(Tcb[Task_Info.Cur_Task_ID].Hold_Event_Flag,ID) EQ 0)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  */
  OS_CLR_BIT(OS_Task_Event[Task_Info.Cur_Task_ID].Hold_Event_Flag,ID);//清除任务占有互斥信号量标志
#endif

  if(OS_Event[ID].Value!=0)//不能连续post多次
  {
    OS_ASSERT_FAILED();
    OS_Debug_Print("\r\nOS:Mutex %d post multi-times,Cur task ID:%d",ID,Task_Info.Cur_Task_ID);
  }
  
  OS_Event[ID].Value=1;
  
#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(OS_Event[ID]);
#endif
 
  return 1;
}

//申请互斥信号量,成功返回1，失败返回0或者不返回 
OS_INT8U OS_Mutex_Pend(OS_INT8U ID)
{
  OS_INT16U Counts;
  
#if OS_CS_EN>0
  if(OS_CHECK_STRUCT_SUM(OS_Event[ID]) EQ 0)
    OS_ASSERT_FAILED();
#endif

#if OS_MUTEX_LOCK_CHK_EN>0  
  if(OS_CHECK_STRUCT_HT(OS_Task_Event[Task_Info.Cur_Task_ID]) EQ 0)
    OS_ASSERT_FAILED();
#endif
  
  if(ID>=OS_EVENT_NUM)
  {
    OS_ASSERT_FAILED();
    return 0;
  }

  if(OS_Event[ID].Type!=OS_MUTEX)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
  if(OS_Event[ID].Value!=0)
  {
#if OS_MUTEX_LOCK_CHK_EN>0
    OS_SET_BIT(OS_Task_Event[Task_Info.Cur_Task_ID].Hold_Event_Flag,ID); 
#endif
    
    OS_Event[ID].Value=0;
    
#if OS_CS_EN>0
    OS_SET_STRUCT_SUM(OS_Event[ID]);
#endif
    
    return 1;
  }
  else
  {
    Counts=0;
#if OS_MUTEX_LOCK_CHK_EN>0
    OS_SET_BIT(OS_Task_Event[Task_Info.Cur_Task_ID].Wait_Event_Flag,ID);//设置任务等待互斥信号量标志
    //在等待不到互斥信号量的情况下，每隔OS_MUTEX_WAIT_WARN_TIME S检查一次是否陷入死锁状态
    while(1)
    {
      OS_Core_Wait_Sec(OS_Event[ID].Value!=0,OS_MUTEX_WAIT_WARN_TIME);
      //等待1S后仍然申请不到互斥信号量，则需要查询是否有死锁现象
      if(OS_Event[ID].Value EQ 0)
      {
        if(OS_Check_Task_Event_Lock(Task_Info.Cur_Task_ID))//当前任务申请的互斥信号量导致锁死
        {
        #if OS_MUTEX_LOCK_CHK_EN>0
          OS_SET_BIT(OS_Task_Event[Task_Info.Cur_Task_ID].Wait_Event_Flag,ID);//不再等待该互斥信号量
        #endif
          OS_ASSERT_FAILED();
          OS_Debug_Print("\r\nOS:Task %d pend mutex %d locked!",Task_Info.Cur_Task_ID,ID);
          OS_Mutex_Info_Print();
          OS_Debug_Print("\r\nOS:Task %d suspend!",Task_Info.Cur_Task_ID);
          OS_Core_Wait(0);
        }

        Counts++;
        OS_Debug_Print("\r\nOS:Task %d pend mutex %d time out,Counts=%d",Task_Info.Cur_Task_ID,ID,Counts);
      }
      else//已经申请到
      {
        OS_CLR_BIT(OS_Task_Event[Task_Info.Cur_Task_ID].Wait_Event_Flag,ID);//清除任务等待互斥信号量标志
        OS_SET_BIT(OS_Task_Event[Task_Info.Cur_Task_ID].Hold_Event_Flag,ID);//设置任务占有互斥信号量标志
        break;
      }
    }
#else
    while(1)
    {
      OS_Core_Wait_Sec(OS_Event[ID].Value!=0,OS_MUTEX_WAIT_WARN_TIME);
      if(OS_Event[ID].Value EQ 0)
      {
        Counts++;
        OS_Debug_Print("\r\nOS:Task %d pend mutex %d time out,Counts=%d",Task_Info.Cur_Task_ID,ID,Counts);        
      }
      else
        break;
    }
#endif
  }
  
  OS_Event[ID].Value=0;
   
#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(OS_Event[ID]);
#endif   
   return 1;  
}

//打印互斥信号量的相关信息
void OS_Mutex_Info_Print(void)
{
  OS_INT8U i;
  
  OS_Debug_Print("\r\nOS:Mutex Use Info:");
  
  for(i=0;i<OS_EVENT_NUM;i++)
  {
    if(OS_Event[i].Type!=OS_MUTEX)
      continue;

    OS_Debug_Print("\r\n  Mutex %d Val=0x%x",i,OS_Event[i].Value);
  }
  
#if OS_MUTEX_LOCK_CHK_EN>0
  for(i=0;i<OS_TASK_NUM;i++)
  {
    OS_Debug_Print("\r\n  Task %d Wait_Flag=0x%x, Hold_Flag=0x%x",i,OS_Task_Event[i].Wait_Event_Flag,OS_Task_Event[i].Hold_Event_Flag);
  }
#endif  
}
#endif

#undef OS_MUTEX_C

