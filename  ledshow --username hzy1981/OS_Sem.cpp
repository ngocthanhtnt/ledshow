#define OS_SEM_C
#include "OS_Includes.h"

#if OS_SEM_EN>0
//初始化信号量,信号量的ID由应用程序自己固定
//Val为信号量的初始值，表示可用资源数
//创建成功返回1，失败返回0
OS_INT8U OS_Sem_Init(OS_INT8U ID,OS_INT8U Val)
{
  if(ID>=OS_EVENT_NUM)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
  OS_Event[ID].Type=OS_SEM;  
  OS_Event[ID].Value=Val;
  
#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(OS_Event[ID]);//设置校验和
#endif
 
  OS_SET_STRUCT_HT(OS_Event[ID]);
  return 1; 
}

//Post信号量,成功返回1，失败返回0
OS_INT8U OS_Sem_Post(OS_INT8U ID)
{
#if OS_CS_EN>0
  if(OS_CHECK_STRUCT_SUM(OS_Event[ID]) EQ 0)
    OS_ASSERT_FAILED();
#endif
  
  if(ID>=OS_EVENT_NUM)
  {
    OS_ASSERT_FAILED();
    return 0;
  }

  if(OS_Event[ID].Type!=OS_SEM)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
  OS_Event[ID].Value++;
  
#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(OS_Event[ID]);
#endif
  return 1;
}

//申请信号量,成功返回1，失败返回0或者不返回 
OS_INT8U OS_Sem_Pend(OS_INT8U ID)
{
  OS_INT16U Counts;
  
#if OS_CS_EN>0
  if(OS_CHECK_STRUCT_SUM(OS_Event[ID]) EQ 0)
    OS_ASSERT_FAILED();
#endif
  
  if(ID>=OS_EVENT_NUM)
  {
    OS_ASSERT_FAILED();
    return 0;
  }
  
  if(OS_Event[ID].Type!=OS_SEM)
  {
    OS_ASSERT_FAILED();
    return 0;
  }  

  Counts=0;
  while(1)
  {
    OS_Core_Wait_Sec(OS_Event[ID].Value>0,OS_SEM_WAIT_WARN_TIME);
    if(OS_Event[ID].Value EQ 0)
    {
      OS_ASSERT_FAILED();
      Counts++;
      OS_Debug_Print("\r\nOS:Task %d pend sem %d time out,Counts=%d",Task_Info.Cur_Task_ID,ID,Counts);
    }
    else
      break;
  }
  OS_Event[ID].Value--;
   
#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(OS_Event[ID]);
#endif   
   return 1;  
}

//打印信号量的相关信息
void OS_Sem_Info_Print(void)
{
  OS_INT8U i;
  
  OS_Debug_Print("\r\nOS:Sem Use Info:");
  
  for(i=0;i<OS_EVENT_NUM;i++)
  {
    if(OS_Event[i].Type!=OS_SEM)
      continue;

    OS_Debug_Print("\r\n  Sem %d Val=0x%x",i,OS_Event[i].Value);
  }
}
#endif

#undef OS_SEM_C

