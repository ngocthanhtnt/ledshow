#ifndef UDISK_PROC_H
#define UDISK_PROC_H

#undef EXT
#ifdef UDISK_PROC_C
#define EXT
#else
#define EXT extern
#endif

EXT void UDisk_Init(void);
EXT void UDisk_Proc(void); 
#endif

