#ifndef OS_CORE_H
#define OS_CORE_H

#undef OS_EXT
#ifndef OS_CORE_C
#define OS_EXT extern
#else
#define OS_EXT
#endif

//定义堆栈检查字
#define CHK_STK_BYTE (OS_INT8U)0x00

#define OS_TASK_WAITING 0x00//等待状态
#define OS_TASK_SUSPEND 0x11//挂起状态
#define OS_TASK_RUNNING 0x22//运行状态

//定义三个位操作宏
#define OS_SET_BIT(x,y) ((x)|=0x01<<(y))
#define OS_CLR_BIT(x,y) ((x)&=~(0x01<<(y)))
#define OS_GET_BIT(x,y) (((x)>>(y))&0x01)

//条件等待,注意Condition中的全局变量必须是Volatile类型
#define OS_Core_Wait(Condition)\
do{ while(!(Condition))\
      OS_Task_Switch_Proc();\
  }while(0)

//定义任务控制块信息
typedef struct{
  OS_ALIGN_TYPE Head;   //用于校验的头,采用OS_Align_Type是为了在某些编译器下确保 Env处于一个对齐的地址
 
  OS_Task_Env Env;          //当前任务环境
  void (*pEntry)();         //函数入口
  OS_STK *pStk;             //堆栈起始指针
  OS_INT32U Stk_Size;       //堆栈大小

#if OS_TASK_NAME_EN>0        //使用任务名称
  OS_INT8S Name[OS_TASK_NAME_SIZE];//任务名字,多保留一个字节填0
#endif

#if OS_CS_EN>0            //使用校验和,用于保护TCB信息
  OS_INT8U CS[OS_CS_BYTES];
#endif

  volatile OS_INT8U Status;//任务状态标志标志
  
  volatile OS_INT32U Time_Dly;       //延时时间，单位ms,延时数据因为经常需要修改，不参与校验计算,防止操作系统调度占用太多cpu时间
  
  OS_ALIGN_TYPE Tail;
}OS_TCB;

typedef struct{
  OS_INT8U Head;
  
  OS_INT8U Cur_Task_ID;   //当前任务ID号
  OS_INT8U Cur_Task_Num;  //当前任务总数 
  
#if OS_CS_EN>0           //使用校验和,用于保护Task_Info信息
  OS_INT8U CS[OS_CS_BYTES];
#endif
  
  OS_INT16U Tail;
  
}OS_Task_Info;

#ifdef OS_CORE_C //只提供给OS_Core.c文件
OS_EXT volatile OS_SP Old_SP;//用于创建任务时保存老的任务堆栈指针,SAVE_TASK_SP()将当前SP保存到Old_SP中
OS_EXT volatile OS_SP New_SP;//用于创建任务时恢复老的任务堆栈指针,RESTORE_TASK_SP()将当前New_SP保存到SP中
#endif

#if OS_TICK_ISR_EN>0
OS_EXT volatile S_Int8U Tick_ISR_Flag;//中断标志，该标志置1表示一个时基周期过去
#endif

OS_EXT OS_TCB Tcb[OS_TASK_NUM];//任务控制信息块
OS_EXT volatile OS_Task_Info Task_Info;//当前任务信息

OS_EXT void OS_Init(void);
OS_EXT void OS_Change_Cur_Task_ID(void);
OS_EXT void OS_Task_Switch_Proc(void);
OS_EXT OS_INT8U OS_Create_Task(void(*pEntry)(),OS_STK *pStk,OS_INT32U Stk_Size,CONST OS_INT8S Name[]);
OS_EXT void OS_Task_Suspend(OS_INT8U Task_ID);
OS_EXT void OS_Task_Unsuspend(OS_INT8U Task_ID);
OS_EXT void OS_Start(void);

#if OS_TICK_ISR_EN>0
OS_EXT void OS_Tick_ISR(void);//定义时基中断服务
#endif

#endif
