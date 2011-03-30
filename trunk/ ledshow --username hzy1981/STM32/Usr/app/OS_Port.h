#ifndef OS_PORT_H
#define OS_PORT_H

#include "LED_Cfg.h"
#include "setjmp.h"

#undef OS_EXT
#ifndef OS_PORT_C
#define OS_EXT extern
#else
#define OS_EXT
#endif

//#define QT_EN 1
#if QT_EN > 0
//iar 编译器支持
#define CONST const       //定义Flash变量
#define NO_INIT //定义非初始化变量

typedef unsigned int OS_INT32U;
typedef int OS_INT32S;
typedef unsigned short int OS_INT16U;
typedef short int OS_INT16S;
typedef unsigned char OS_INT8U;
typedef char OS_INT8S;
typedef unsigned int OS_STK;
typedef unsigned int OS_SP;
typedef unsigned char OS_BOOL;
typedef unsigned int OS_ALIGN_TYPE;//定义对齐的类型

#define OS_Task_Env jmp_buf
#define OS_Save_Env(x) setjmp(x)
#define OS_Restore_Env(x) longjmp(x,1) 

//使用内嵌汇编，请勿打开任何优化选项!
//将SP保存到Old_SP

#define SAVE_TASK_SP()   __asm("mov %esp,%ebx");\
                         __asm("mov %ebx,_Old_SP")

//将New_SP保存到SP
#define RESTORE_TASK_SP()  __asm("mov _New_SP,%ebx");\
                           __asm("mov %ebx,%esp")

//VC6.0编译器不支持__FUCNTION__这个宏
#define __FUNCTION__ "FUNCTION"

#else
//iar 编译器支持
#define CONST const       //定义Flash变量
#define NO_INIT __no_init //定义非初始化变量

typedef unsigned int OS_INT32U;
typedef int OS_INT32S;
typedef unsigned short int OS_INT16U;
typedef short int OS_INT16S;
typedef unsigned char OS_INT8U;
typedef char OS_INT8S;
typedef unsigned int OS_STK;
typedef unsigned int OS_SP;
typedef unsigned char OS_BOOL;
typedef unsigned int OS_ALIGN_TYPE;

#define OS_Task_Env jmp_buf
#define OS_Save_Env(x) setjmp(x)
#define OS_Restore_Env(x) longjmp(x,1)

//OS_EXT OS_SP Save_Task_SP();
//OS_EXT void Restore_Task_SP(OS_SP Sp);

//将SP保存到Old_SP
#define SAVE_TASK_SP()  //Old_SP=Save_Task_SP()

//将New_SP保存到SP
#define RESTORE_TASK_SP()  Old_SP//Restore_Task_SP(New_SP)


/*
#define SAVE_TASK_SP()    asm("MOV R0,SP");\
                          asm("MOV Old_SP,R0")
#define RESTORE_TASK_SP() asm("MOV R0,New_SP");\
                          asm("MOV SP,R0")
*/
//OS_EXT void OS_Tick_Task_Init();
//OS_EXT OS_INT8U OS_Check_Tick();

#endif


OS_EXT OS_INT8U OS_Check_Tick();
#endif
