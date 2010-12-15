#ifndef OS_SEM_H
#define OS_SEM_H

#if OS_SEM_EN>0

#undef OS_EXT
#ifndef OS_SEM_C
#define OS_EXT extern
#else
#define OS_EXT
#endif

OS_EXT OS_INT8U OS_Sem_Init(OS_INT8U ID,OS_INT8U Val);
OS_EXT OS_INT8U OS_Sem_Post(OS_INT8U ID);
OS_EXT OS_INT8U OS_Sem_Pend(OS_INT8U ID);
OS_EXT void OS_Sem_Info_Print(void);
#endif

#endif

