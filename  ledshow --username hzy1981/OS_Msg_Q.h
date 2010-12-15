#ifndef OS_MSG_Q_H
#define OS_MSG_Q_H

#if OS_MSG_Q_EN>0

#undef OS_EXT
#ifndef OS_MSG_Q_C
#define OS_EXT extern
#else
#define OS_EXT
#endif

typedef struct
{
  OS_INT8U Head;
  
  OS_INT32U Rcv_Flag;//接收此消息的任务
  OS_INT16U Msg_Len;//消息的长度
  
#if OS_CS_EN>0
  OS_INT8U CS[OS_CS_BYTES];
#endif 
  
  OS_INT8U Tail;
}S_Msg_Q_H_Info;

//每个消息内存块内保留的大小,预留给消息头和尾
#define MSG_RESERVE_SIZE (sizeof(S_Msg_Q_H_Info)+1) 

typedef struct
{
  OS_INT8U Head;
  
  OS_INT8U Msg_Flag;//消息队列标志字
  OS_INT32U Msg_Rcv_Flag; //接收标志，标示哪些任务可以从这个消息队列中接收消息
  OS_INT8U Msg_Rcv_Index[OS_TASK_NUM]; //消息的接收索引
  OS_INT8U Msg_Send_Index;//消息的发送索引
  OS_INT8U Msg_Max_Num; //消息的个数
  OS_INT8U Msg_Mem_Size; //每条消息的长度,包括了头和尾的位置,因此并不是实际消息的最大长度
  void *pMsg;       //指向消息数据
  
#if OS_CS_EN>0
  OS_INT8U CS[OS_CS_BYTES];
#endif
  
  OS_INT8U Tail;
}S_Msg_Q_Info;  

//使用OS_ALIGN_TYPE保证每条消息对应的bug的起始位置都处于一个对齐的位置上
//因为每个消息bug的起始位置都放置着一个S_Msg_Q_H_Info结构体，必须处于一个对齐的位置上
#define DECLARE_MSG_Q(Q_Info_Name,Msg_Num,Msg_Len,Rcv_Flag) typedef struct{\
                                                                           OS_ALIGN_TYPE Head;\
                                                                           OS_INT8U Buf[(Msg_Num)][(((Msg_Len)+MSG_RESERVE_SIZE)/sizeof(OS_ALIGN_TYPE)+1)*sizeof(OS_ALIGN_TYPE)];\
                                                                           OS_ALIGN_TYPE Tail;\
                                                                           }S_##Q_Info_Name##_QBuf;\
                                 S_##Q_Info_Name##_QBuf Q_Info_Name##_QBuf={\
                                                                            CHK_BYTE,\
                                                                            {{0}},\
                                                                            CHK_BYTE,\
                                                                            };\
                                                  S_Msg_Q_Info Q_Info_Name={\
                                                                            CHK_BYTE,\
                                                                            OS_MSG_Q,\
                                                                            (Rcv_Flag),\
                                                                            {0},\
                                                                            0,\
                                                                            (Msg_Num),\
                                                                            (((Msg_Len)+MSG_RESERVE_SIZE)/sizeof(OS_ALIGN_TYPE)+1)*sizeof(OS_ALIGN_TYPE),\
                                                                            Q_Info_Name##_QBuf.Buf,\
                                                                            CHK_BYTE,};

OS_EXT OS_INT8U OS_Msg_Q_Init(OS_INT8U ID,S_Msg_Q_Info *pMsg_Q_Info);
OS_EXT OS_INT8U OS_Msg_Q_Send(OS_INT8U ID,void *pMsg,OS_INT16U Msg_Len,OS_INT16U Time_Out);
OS_EXT OS_INT16U OS_Msg_Q_Rcv_Start(OS_INT8U ID,OS_INT8U **ppMsg,OS_INT16U Time_Out);
OS_EXT OS_INT16U OS_Msg_Q_Rcv_End(OS_INT8U ID);
OS_EXT void OS_Msg_Q_Info_Print(void);
#endif

#endif

