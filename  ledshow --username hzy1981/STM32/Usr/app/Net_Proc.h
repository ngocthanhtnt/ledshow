#ifndef NET_PROC_H
#define NET_PROC_H

#undef EXT
#ifdef NET_PROC_C
#define EXT
#else
#define EXT extern
#endif

EXT void Net_Init(void);
EXT void Net_Proc(void); 
#endif
