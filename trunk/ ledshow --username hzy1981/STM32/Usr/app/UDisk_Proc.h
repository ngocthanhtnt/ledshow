#ifndef UDISK_PROC_H
#define UDISK_PROC_H

#undef EXT
#ifdef UDISK_PROC_C
#define EXT
#else
#define EXT extern
#endif

#define UDISK_NULL 0x00
#define UDISK_ING 0x01
#define UDISK_END 0x02

EXT void UDisk_Init(void);
EXT void UDisk_Proc(void); 
#endif

