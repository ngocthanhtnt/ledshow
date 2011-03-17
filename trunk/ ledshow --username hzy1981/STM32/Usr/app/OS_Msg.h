#ifndef OS_MSG_H
#define OS_MSG_H

#if OS_MSG_EN>0

#undef OS_EXT
#ifndef OS_MSG_C
#define OS_EXT extern
#else
#define OS_EXT
#endif

OS_EXT OS_INT8U OS_Msg_Init(OS_INT8U ID);
//OS_EXT OS_INT8U OS_Msg_Wait_Free(OS_INT8U ID,OS_INT16U Time_Out);
//OS_EXT OS_INT8U OS_Msg_Send_NoWait(OS_INT8U ID,OS_INT16U Val,void *pMsg,OS_INT8U Rcv_Flag);
OS_EXT OS_INT8U OS_Msg_Send(OS_INT8U ID,OS_INT16U Val,void *pMsg,OS_INT8U Rcv_Flag,OS_INT16U Time_Out);
OS_EXT OS_INT8U OS_Msg_Rcv_Start(OS_INT8U ID,OS_INT16U *pVal,OS_INT8U **ppMsg,OS_INT8U Time_Out);
OS_EXT OS_INT8U OS_Msg_Rcv_End(OS_INT8U ID);
OS_EXT void OS_Msg_Info_Print(void);
#endif

#endif

