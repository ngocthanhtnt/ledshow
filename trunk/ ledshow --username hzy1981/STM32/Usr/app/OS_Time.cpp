#define OS_TIME_C
#include "OS_Includes.h"

//检查操作系统的一个时基是否到
OS_INT8U OS_Check_Sys_Tick(void)
{
#if OS_TICK_ISR_EN>0 //使用OS_Tick_ISR中Tick_ISR_Flag置1
  if(1 EQ Tick_ISR_Flag.Var)//在中断中该标志置1表示一个时基周期到
  {
    Tick_ISR_Flag.Var=0;
    return 1;
  }
#else
  if(OS_Check_Tick())//查询定时器等确定时基，该函数根据具体CPU来实现
    return 1;
#endif
  return 0;
  
}

//检查任务的延时时间,每个时基调用一次该函数
void OS_TaskDly_Proc(void)
{
  OS_INT16U i;

  for(i=0;i<Task_Info.Cur_Task_Num;i++)//修改每个任务的延时时间
  {
    if(0!=Tcb[i].Time_Dly)//对延时非0的函数，减少其延时
    {
      //对每个任务的延时进行减数
      if(Tcb[i].Time_Dly>OS_MS_PER_TICK)
        Tcb[i].Time_Dly-=OS_MS_PER_TICK;
      else
        Tcb[i].Time_Dly=0;
    }
  }
}

//设置任务的延时，但并不马上进入延时状态
void OS_Set_Task_TimeDly(OS_INT16U Hour,OS_INT16U Min,OS_INT16U Sec,OS_INT16U m_Sec)
{
  Tcb[Task_Info.Cur_Task_ID].Time_Dly=(OS_INT32U)Hour*3600L*1000L+(OS_INT32U)Min*60L*1000L+(OS_INT32U)Sec*1000L+(OS_INT32U)m_Sec+(OS_INT32U)OS_MS_PER_TICK;
}  

//任务延时调用
void OS_TimeDly(OS_INT16U Hour,OS_INT16U Min,OS_INT16U Sec,OS_INT16U m_Sec)
{
  OS_Set_Task_TimeDly(Hour, Min, Sec, m_Sec);		
  OS_Core_Wait((Tcb[Task_Info.Cur_Task_ID].Time_Dly EQ 0));
}

//检查当前任务是否处于延时状态，是返回1，否则返回0
OS_INT8U OS_Check_Task_TimeDly(void)
{
  if(Tcb[Task_Info.Cur_Task_ID].Time_Dly!=0)
    return 1;
  else
    return 0;
}

#undef OS_TIME_C
