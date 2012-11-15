#define OS_EXT_C
#include "OS_Includes.h"

//检查某任务堆栈使用情况，堆栈使用有误则返回0，否则返回1
//主要是查询堆栈的头尾字节,头尾字节正确,基本认为堆栈内容没有被破坏或者越界
OS_INT8U OS_Check_Task_Stk(OS_INT8U Task_ID)
{
  if(Task_ID>=Task_Info.Cur_Task_Num)
    OS_ASSERT_FAILED();
  
#if OS_STK_GROWTH>0//堆栈从高地址向低地址递减 
  if(CHK_STK_BYTE EQ *(OS_INT8U *)(Tcb[Task_ID].pStk) &&\
     CHK_STK_BYTE EQ *(OS_INT8U *)(Tcb[Task_ID].pStk-Tcb[Task_ID].Stk_Size/sizeof(OS_STK)+1))
    return 1;
#else  //堆栈从低地址向高地址增长
  if(CHK_STK_BYTE EQ *(OS_INT8U *)(Tcb[Task_ID].pStk) &&
     CHK_STK_BYTE EQ *(OS_INT8U *)(Tcb[Task_ID].pStk+Stk_Size-1))
    return 1;
#endif
  OS_ASSERT_FAILED();
  return 0;
}

//检查某个任务的堆栈还剩余多少空间
OS_INT16U OS_Get_Task_Stk_Left(OS_INT8U Task_ID)
{
  OS_INT16U i;
  OS_INT8U *p;
  
  if(Task_ID>=Task_Info.Cur_Task_Num)
    OS_ASSERT_FAILED();
  
#if OS_STK_GROWTH>0//堆栈从高地址向低地址递减 
  p=(OS_INT8U *)(Tcb[Task_ID].pStk-Tcb[Task_ID].Stk_Size/sizeof(OS_STK)+1);
#else  //堆栈从低地址向高地址增长
  p=(OS_INT8U *)(Tcb[Task_ID].pStk);
#endif  
  
  i=0;
  while(1)
  {
    if(CHK_STK_BYTE!=*(p+i))
      return i;
    i++;
  } 
}

//获取当前任务的ID号
OS_INT8U OS_Get_Cur_Task_ID(void)
{
  if(OS_CHECK_STRUCT_HT(Task_Info) EQ 0)
    OS_ASSERT_FAILED();

  return Task_Info.Cur_Task_ID;
}

//获取当前任务总数
OS_INT8U OS_Get_Cur_Task_Num(void)
{
  if(OS_CHECK_STRUCT_HT(Task_Info) EQ 0)
    OS_ASSERT_FAILED();

  return Task_Info.Cur_Task_Num;
}

#if OS_TASK_NAME_EN>0
//获取任务的名字
OS_INT8S * OS_Get_Task_Name(OS_INT8U Task_ID)
{
  if(Task_ID>=Task_Info.Cur_Task_Num)
    OS_ASSERT_FAILED();

  return Tcb[Task_ID].Name;  
}
#endif

//检查任务的上下文是否正确，注意：该函数中不能调用操作系统提供的调用
//只有OS_USE_CS该宏为1时，该函数才有意义
void OS_Check_Task_Env(void)
{
  OS_INT8U Next_Task_ID;
  
  if(OS_CHECK_STRUCT_HT(Task_Info) EQ 0)//检查Task_Info的头和尾
    OS_ASSERT_FAILED();
  
//如果要系统速度更快，可把校验和相关屏蔽，只保留头尾检验 
#if OS_CS_EN>0
  OS_SET_STRUCT_SUM(Tcb[Task_Info.Cur_Task_ID]);
#endif

  Next_Task_ID=(Task_Info.Cur_Task_ID+1)%Task_Info.Cur_Task_Num;//下个任务的ID

//如果要系统速度更快，可把校验和相关屏蔽，只保留头尾检验 
#if OS_CS_EN>0
  if(OS_CHECK_STRUCT_SUM(Tcb[Next_Task_ID]) EQ 0)//检查校验和
  {
    OS_ASSERT_FAILED();
    OS_Debug_Print("\r\nOS:Tcb[%d] sum error",Next_Task_ID);    
  }
#endif

  if(OS_CHECK_STRUCT_HT(Tcb[Next_Task_ID]) EQ 0)//检查头尾字节
  {
    OS_ASSERT_FAILED();
    OS_Debug_Print("\r\nOS:Tcb[%d] head or tail check error",Next_Task_ID);     
  }
  
  if(OS_Check_Task_Stk(Next_Task_ID) EQ 0)//检查堆栈的头和尾
  {
    OS_ASSERT_FAILED();
    OS_Debug_Print("\r\nOS:Task %d stack error",Next_Task_ID); 
  }
}

//对任务环境的检测
void OS_Task_Info_Check(void)
{
  OS_INT8U i;
  
#if OS_TICK_ISR_EN>0
  if(OS_CHECK_STRUCT_HT(Tick_ISR_Flag) EQ 0)
  {
    OS_ASSERT_FAILED();
    OS_Debug_Print("\r\nOS:Tick_ISR_Flag head or tail check error");
  }
#endif
  
  if(OS_CHECK_STRUCT_HT(Task_Info) EQ 0)
  {
    OS_ASSERT_FAILED();
    OS_Debug_Print("\r\nOS:Task Info head or tail check error");
  }

#if OS_CS_EN>0 
  if(OS_CHECK_STRUCT_SUM(Task_Info) EQ 0)
  {
    OS_ASSERT_FAILED();
    OS_Debug_Print("\r\nOS:Task_Info CS check error");
  }
#endif
  
  for(i=0;i<OS_TASK_NUM;i++)
  {
    if(OS_CHECK_STRUCT_HT(Tcb[i]) EQ 0)
    {
      OS_ASSERT_FAILED();
      OS_Debug_Print("\r\nOS:Task %d env head or tail check error", i);
    }
    
#if OS_CS_EN>0 
    if(OS_CHECK_STRUCT_SUM(Tcb[i]) EQ 0)
    {
      OS_ASSERT_FAILED();
      OS_Debug_Print("\r\nOS:Task %d env CS check error", i);
    }
#endif
  }
}

//打印任务相关的信息，堆栈剩余字节数
void OS_Task_Info_Print(void)
{
  OS_INT8U i,Task_Num;
  
  OS_Debug_Print("\r\nOS:Task remaining stack bytes:");
  Task_Num = OS_Get_Cur_Task_Num();
  for(i=0;i<Task_Num;i++)
    OS_Debug_Print("\r\n  Task %d:%d",i,OS_Get_Task_Stk_Left(i));
}

//获取操作系统版本号
OS_INT32U OS_Get_Version(void)
{
  return OS_VERSION;
}

//打印版本信息，格式：版本-编译时间-编译日期
void OS_Version_Info_Print(void)
{
  OS_Debug_Print("\r\nOS:Version:%ld-%s-%s", OS_VERSION, __TIME__, __DATE__);
}

#undef OS_EXT_C

