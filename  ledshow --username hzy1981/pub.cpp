#define PUB_C
#include "Includes.h"

//此函数内切不可有引起输出的函数！
INT8U OS_Debug_Print_En(void)
{
  if(OS_Check_Bg_Status() EQ 1 &&
     OS_Check_Bg_Print_En() EQ 0)
    return 0;
  else
    return 1;
}

void OS_Trace_Hook(void)
{

}

void OS_Assert_Hook(CONST OS_INT8S File[],CONST OS_INT8S Function[],OS_INT16U Line)
{

}

INT16U Sum_2Bytes(INT8U Src[], INT16U SrcLen)
{
  INT16U CS = 0;
  INT16U i;

  for(i = 0; i < SrcLen; i ++)
  {
    CS += Src[i]; 
  }
  return CS;
}

#undef PUB_C
