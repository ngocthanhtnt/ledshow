#ifndef OS_EVENT_H
#define OS_EVENT_H

#if (OS_MUTEX_EN>0) || (OS_SEM_EN>0) || (OS_MSG_EN>0) || (OS_MSG_Q_EN>0)

#undef OS_EXT
#ifndef OS_EVENT_C
#define OS_EXT extern
#else
#define OS_EXT
#endif

#define OS_MUTEX 1
#define OS_SEM   2
#define OS_MSG   3
#define OS_MSG_Q 4

//定义任务通信结构体,只对前16个任务支持
typedef struct{
  OS_INT8U Head;
  
  OS_INT8U Type;       //信号量或者消息
  OS_INT16U Value;      //值
  
  void *pData;//指向数据的指针

  OS_INT32U Rcv_Flag;    //第N位为1表示等待第N号任务来接收消息,为0表示已经开始接收消息,或者还没开始接收
    
#if OS_CS_EN>0 
  OS_INT8U CS[OS_CS_BYTES];//校验和
#endif
  OS_INT8U Tail;

}OS_Event_Info;

typedef struct{
  OS_INT8U Head;
  
  OS_INT16U Wait_Event_Flag;//等待事件标志
  OS_INT16U Hold_Event_Flag;//拥有时间标志
  
  OS_INT8U Tail; 
}OS_Task_Event_Info;

OS_EXT volatile OS_Event_Info OS_Event[OS_EVENT_NUM];

#if (OS_MUTEX_EN>0) && (OS_MUTEX_LOCK_CHK_EN>0) 
OS_EXT volatile OS_Task_Event_Info OS_Task_Event[OS_TASK_NUM];
#endif 

OS_EXT void OS_Event_Init(void);

#if OS_MUTEX_LOCK_CHK_EN>0
OS_EXT void OS_Task_Event_Init(void);
#endif

OS_EXT OS_INT8U OS_Check_Task_Event_Lock(OS_INT8U Task_ID);
OS_EXT void OS_Event_Check(void);
#endif

#endif

