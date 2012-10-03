#ifndef NET_PROC_H
#define NET_PROC_H

#undef EXT
#ifdef NET_PROC_C
#define EXT
#else
#define EXT extern
#endif

#define REM_DATA_FLAG 0x99

EXT void Net_Init(void);
EXT void Net_Proc(void); 
#endif
