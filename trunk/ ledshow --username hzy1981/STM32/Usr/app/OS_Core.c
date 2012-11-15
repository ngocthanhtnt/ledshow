#define OS_CORE_C
#include "OS_Includes.h"

//创建任务函数
//pEntry表示任务函数入口
//pStk表示堆栈的起始地址
//Stk_Size堆栈的长度，以字节为单位
//Name任务的名字,只有当OS_TASK_NAME_EN这个宏为1时该名字才有意义
OS_INT8U OS_Create_Task(void(*pEntry)(),OS_STK *pStk,OS_INT32U Stk_Size,CONST OS_INT8S Name[])
{
  OS_INT8U i=0;
  static OS_INT8U Task_ID;//使用静态局部变量，防止上下文变化时局部变量的变化

  if(Task_Info.Cur_Task_Num>=OS_TASK_NUM)
  {
    OS_ASSERT_FAILED();
    return 0;  
  }
  
  i=0;
  Task_ID=Task_Info.Cur_Task_Num;
  
  Task_Info.Cur_Task_Num++; 
  
#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(Task_Info);
#endif
  
  OS_SET_STRUCT_HT(Tcb[Task_ID]);
  Tcb[Task_ID].pEntry=pEntry;  
  Tcb[Task_ID].pStk=pStk;
  Tcb[Task_ID].Stk_Size=Stk_Size;
  Tcb[Task_ID].Time_Dly=0;
  Tcb[Task_ID].Status=OS_TASK_RUNNING;

#if OS_TASK_NAME_EN>0 //如果使用名字 
  while(i<OS_TASK_NAME_SIZE-1 && Name[i]!=0)
  {
    Tcb[Task_ID].Name[i]=Name[i];  
    i++;
  }
  Tcb[Task_ID].Name[i]=0;
#else
  (void)i;//防止编译警告
#endif
    
  //将堆栈内容初始化成特殊字符，以统计堆栈用量
  //同时保留堆栈的头尾两个字节，用于判断堆栈是否溢出或者被覆盖
#if OS_STK_GROWTH>0//堆栈从高地址向低地址递减
  OS_memset(pStk-Stk_Size/sizeof(OS_STK)+1,CHK_STK_BYTE,Stk_Size,pStk-Stk_Size/sizeof(OS_STK)+1,Stk_Size);
  pStk--;
#else  //堆栈从低地址向高地址增长
  OS_memset((OS_INT8U *)pStk,CHK_STK_BYTE,Stk_Size,(OS_INT8U *)pStk,Stk_Size);
  pStk++;
#endif
  
  SAVE_TASK_SP();//将SP保存到Old_SP
  New_SP=(OS_SP)pStk;
  RESTORE_TASK_SP();//将New_SP恢复到SP中
  //此处开始在任务堆栈中运行
  if(OS_Save_Env(Tcb[Task_ID].Env) EQ 0)//保存当前环境变量
  { 
    New_SP=Old_SP;
    RESTORE_TASK_SP();//恢复老的SP
    
#if OS_CS_EN>0
    OS_SET_STRUCT_SUM(Tcb[Task_ID]);//设置当前任务环境的校验和
#endif
  
  }
  else//else内程序在新任务中运行
  {
    Tcb[Task_Info.Cur_Task_ID].pEntry();//Entry在切换到任务堆栈后可能丢失，因此采用pEntry  
  }
  return 1;
}

//修改当前任务ID，以便调度到下一个任务
void OS_Change_Cur_Task_ID(void)
{
  OS_INT8U i=0;
  
  if(OS_CHECK_STRUCT_HT(Task_Info) EQ 0)
    OS_ASSERT_FAILED();
 
//如果要系统速度更快，可把校验和相关屏蔽，只保留头尾检验
#if OS_CS_EN>0
  if(OS_CHECK_STRUCT_SUM(Task_Info) EQ 0)
    OS_ASSERT_FAILED();
#endif 

#if OS_TASK_SUSPEND_EN>0 //开启任务挂起功能
  for(i=0;i<Task_Info.Cur_Task_Num;i++)
  {
    Task_Info.Cur_Task_ID++;
    
    if(Task_Info.Cur_Task_ID>=Task_Info.Cur_Task_Num) 
      Task_Info.Cur_Task_ID=0;     
    
    if(Tcb[Task_Info.Cur_Task_ID].Status!=OS_TASK_SUSPEND)//直到找到一个没有被挂起的任务
      break;
  }
#else  
  (void)i;
  
  Task_Info.Cur_Task_ID++;
  
  if(Task_Info.Cur_Task_ID>=Task_Info.Cur_Task_Num) 
    Task_Info.Cur_Task_ID=0;
#endif
  
//如果要系统速度更快，可把校验和相关屏蔽，只保留头尾检验  
#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(Task_Info);
#endif  
}

#if OS_TASK_SWITCH_HOOK_EN>0
extern void OS_Task_Switch_Hook(void);
#endif 

#if OS_TICK_HOOK_EN>0
extern void OS_Tick_Hook(void);//时基钩子函数
#endif

//任务切换时的相关处理
void OS_Task_Switch_Proc(void)
{
  if(OS_Save_Env(Tcb[Task_Info.Cur_Task_ID].Env) EQ 0)
  {
  #if OS_TASK_SWITCH_HOOK_EN>0
    OS_Task_Switch_Hook();
  #endif  
  
    if(OS_Check_Sys_Tick())//操作系统的一个时基到
    {
      OS_TaskDly_Proc();//检查任务延时
      
  #if OS_TICK_HOOK_EN>0    
      OS_Tick_Hook();//时基钩子函数
  #endif
      
    }
    OS_Check_Task_Env();//检查任务环境
    OS_Change_Cur_Task_ID();//修改任务ID
    OS_Restore_Env(Tcb[Task_Info.Cur_Task_ID].Env);
  }
}

//将任务号为Task_ID的任务挂起
void OS_Task_Suspend(OS_INT8U Task_ID)
{
  if(Task_ID>=Task_Info.Cur_Task_Num || Task_ID>=OS_TASK_NUM)
  {
    OS_ASSERT_FAILED();
    return;
  }
  
  Tcb[Task_ID].Status=OS_TASK_SUSPEND;
  
  if(Task_ID EQ Task_Info.Cur_Task_ID)//如果挂起的就是当前任务，则马上挂起自己
    OS_Core_Wait(Tcb[Task_ID].Status!=OS_TASK_SUSPEND);
}

//将任务号为Task_ID的任务取消挂起
void OS_Task_Unsuspend(OS_INT8U Task_ID)
{
  if(Task_ID>=Task_Info.Cur_Task_Num || Task_ID>=OS_TASK_NUM)
  {
    OS_ASSERT_FAILED();
    return;
  }
  
  Tcb[Task_ID].Status=OS_TASK_RUNNING;
}

#if OS_TICK_ISR_EN>0 //使用中断作为Tick基准
void OS_Tick_ISR(void) //定衣ms定时器,每毫秒中断调用
{
  Tick_ISR_Flag.Var=1;
}
#endif

//操作系统启动函数
void OS_Start(void)
{
  OS_Restore_Env(Tcb[0].Env);//切换到第一个任务的执行环境   
}

//操作系统初始化函数
void OS_Init(void)
{
#if OS_TICK_ISR_EN>0
  Tick_ISR_Flag.Var=0;
  OS_SET_STRUCT_HT(Tick_ISR_Flag);
#endif

#if (OS_MUTEX_EN>0) && (OS_MUTEX_LOCK_CHK_EN>0)
  OS_Task_Event_Init();
#endif

#if (OS_MUTEX_EN>0) || (OS_SEM_EN>0) || (OS_MSG_EN>0) || (OS_MSG_Q_EN>0)
  OS_Event_Init();
#endif
  
#if OS_TRACE_EN>0
  OS_SET_STRUCT_HT(Trace_Info);
  Trace_Info.Entry_Flag=0;
#endif
  
  Task_Info.Cur_Task_ID=0;
  Task_Info.Cur_Task_Num=0;
  OS_SET_STRUCT_HT(Task_Info);
  
#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(Task_Info);
#endif
}

#undef OS_CORE_C
