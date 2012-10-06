#ifndef NET_PROC_H
#define NET_PROC_H

#undef EXT
#ifdef NET_PROC_C
#define EXT
#else
#define EXT extern
#endif

#define REM_DATA_FLAG 0x99
#define NET_PARA_MODI_FLAG 0x56289023

EXT INT32U Net_Para_Modi_Flag;

EXT void Net_Init(void);
EXT void Net_Proc(void); 
EXT void Make_Mac_Para(INT8U Mac[]);
#endif
