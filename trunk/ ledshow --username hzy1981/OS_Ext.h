#ifndef OS_EXT_H
#define OS_EXT_H

#undef OS_EXT
#ifndef OS_EXT_C
#define OS_EXT extern
#else
#define OS_EXT
#endif

OS_EXT OS_INT8U OS_Check_Task_Stk(OS_INT8U Task_ID);
OS_EXT OS_INT16U OS_Get_Task_Stk_Left(OS_INT8U Task_ID);
OS_EXT OS_INT8U OS_Get_Cur_Task_ID(void);
OS_EXT OS_INT8U OS_Get_Cur_Task_Num(void);

#if OS_TASK_NAME_EN>0
OS_EXT OS_INT8S * OS_Get_Task_Name(OS_INT8U Task_ID);
#endif

OS_EXT void OS_Check_Task_Env(void);
OS_EXT void OS_Task_Info_Check(void);
OS_EXT void OS_Task_Info_Print(void);
OS_EXT OS_INT32U OS_Get_Version(void);

#endif

