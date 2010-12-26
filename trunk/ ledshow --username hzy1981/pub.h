#ifndef PUB_H
#define PUB_H

//extern "c"
//{

#include "LED_Cfg.h"
#include "STM32.h"
#include "QT_SIM.h"


#undef EXT
#ifndef PUB_C
#define EXT extern
#else
#define EXT
#endif

#define PUB_BUF_MUTEX_ID 0x00 //信号量ID，用于Pub_Buf使用的互斥

#define mem_cpy OS_memcpy
#define mem_set OS_memset
#define TRACE() //OS_Trace
#define Check_Sum OS_Check_Sum
#define Set_Sum OS_Set_Sum

#if QT_EN == 0
#define Debug_Print OS_Debug_Print
#else
#define Debug_Print qDebug
#endif

#define S_NUM(X) (sizeof(X)/sizeof(X[0]))

#define MAX_2(a,b) ((a)>(b)?(a):(b))
#define MIN_2(a,b) ((a)>(b)?(b):(a))

#define MAX_3(a,b,c) (MAX_2(a,b) > (c)?MAX_2(a,b):(c))
#define MIN_3(a,b,c) (MIN_2(a,b) < (c)?MIN_2(a,b):(c))

//定义设置某个变量的宏方法
#define SET_VAR(X,Y,X_Addr,X_Len) do{if(((INT8U *)&(X))>=(INT8U *)(X_Addr) && ((INT8U *)&(X))<(INT8U *)(X_Addr)+(X_Len))\
                                                                                   X=Y;\
                                                                                 else\
                                                                                   ASSERT_FAILED();\
                                                                                }while(0)

#define SET_SUM OS_SET_STRUCT_SUM
#define CHK_SUM OS_CHECK_STRUCT_SUM
#define SET_HT(V) do{V.Head = CHK_BYTE; V.Tail = CHK_BYTE;}while(0)
#define CHK_HT(V) ((V.Head == CHK_BYTE && V.Tail == CHK_BYTE)?1:0)

typedef struct
{
  INT8U Head;
  INT8U Buf[500];
  INT8U Tail;
}S_Pub_Buf;


//EXT NO_INIT S_Trace_Info Trace_Info;
#ifdef PUB_C
EXT S_Pub_Buf _Pub_Buf = {CHK_BYTE,{0}, CHK_BYTE};
#else
EXT S_Pub_Buf _Pub_Buf;
#endif

#define Pub_Buf _Pub_Buf.Buf


EXT INT16U Sum_2Bytes(INT8U Src[], INT16U SrcLen);
EXT void Check(void);
EXT void Info_Print(void);
//外部完成调试信息输出函数
extern void Put_Char(INT8S Chr);
//}
#endif
