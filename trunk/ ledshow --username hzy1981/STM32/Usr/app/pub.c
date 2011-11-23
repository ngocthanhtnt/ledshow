#define PUB_C
#include "Includes.h"

extern void Check_Show_Data_Para(void);
void TRACE()
{

}

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

//S_Time类型转到tm类型
void S_Time_2_tm(S_Time *pTime, struct tm *ptm)
{
  ptm -> tm_sec = pTime->Time[T_SEC];
  ptm -> tm_min = pTime->Time[T_MIN];
  ptm -> tm_hour = pTime->Time[T_HOUR];
  ptm -> tm_mday = pTime->Time[T_DATE];
  ptm -> tm_mon = pTime->Time[T_MONTH] - 1;
  ptm -> tm_year = (int)pTime->Time[T_YEAR] + 2000 - 1900; 
  ptm -> tm_isdst = 0;
}

//tm类型转到S_Time类型
void tm_2_S_Time(struct tm *ptm, S_Time *pTime)
{
  pTime->Time[T_SEC] = (INT8U)(ptm -> tm_sec);
  pTime->Time[T_MIN] = (INT8U)(ptm -> tm_min);
  pTime->Time[T_HOUR] = (INT8U)(ptm -> tm_hour);
  pTime->Time[T_DATE] = (INT8U)(ptm -> tm_mday);
  pTime->Time[T_MONTH] = (INT8U)(ptm -> tm_mon + 1);
  pTime->Time[T_YEAR] = (INT8U)(ptm -> tm_year + 1900 - 2000); 
}

float Sqrt(float number) 
{ 
    long i; 
    float x, y; 
    const float f = 1.5F; 

    x = number * 0.5F; 
    y  = number; 
    i  = * ( long * ) &y; 
    i  = 0x5f3759df - ( i >> 1 );  //卡马克 
  //i  = 0x5f375a86 - ( i >> 1 );  //Lomont 
    y  = * ( float * ) &i; 
    y  = y * ( f - ( x * y * y ) ); 
    y  = y * ( f - ( x * y * y ) ); 
    return number * y; 
}

//检查BCD数据缓冲区的数据是否都是BCD码,是BCD的缓冲区则返回1，否则返回0
INT8U Check_BCD_Data(void* pBCD, INT16U Len)
{
  INT16U i;
  INT8U* p;

  p = (INT8U *) pBCD;

  for(i = 0; i < Len; i++)
  {
    if(!((p[i] & 0x0F) < 0x0A && (p[i] & 0xF0) < 0xA0))
    {
      return 0;
    }
  }
  return 1;
}

//字节Hex2Bcd转换
INT8U Hex2Bcd_Byte(INT8U Byte)
{
  if(Byte >= 100)
    ASSERT_FAILED();
  
  return (Byte % 10) + ((Byte / 10) << 4);
}

//字节Hex2Bcd转换
INT8U Bcd2Hex_Byte(INT8U Byte)
{
  INT8U Re;
  Re = Check_BCD_Data(&Byte, 1);
  if(Re EQ 0)
    ASSERT_FAILED();
  
  return (Byte & 0x0F) + ((Byte & 0xF0) >> 4) * 10;
}

void Pub_Timer_Proc(void)
{
//GPIO_SetBits(GPIOB,GPIO_Pin_9); //测试输出
#if TIM1_EN
	Pub_Timer.Ms++;
	Pub_Timer.Ms_Counts++;
	if(Pub_Timer.Ms_Counts >= 100)
	{
	    Pub_Timer.Ms_Counts = 0;

	    Pub_Timer.Ms100++;
	    Pub_Timer.Ms100_Counts ++;
	
		if(Pub_Timer.Ms100_Counts >= 10)
		{
		  Pub_Timer.Ms100_Counts = 0;
		  Pub_Timer.Sec ++;
		}
	}
#else
    Pub_Timer.Us100_Counts++;
	if(Pub_Timer.Us100_Counts >= 10)
	{
	    Pub_Timer.Us100_Counts = 0;

		Pub_Timer.Ms++;
		Pub_Timer.Ms_Counts++;
		if(Pub_Timer.Ms_Counts >= 100)
		{
		    Pub_Timer.Ms_Counts = 0;
	
		    Pub_Timer.Ms100++;
		    Pub_Timer.Ms100_Counts ++;
		
			if(Pub_Timer.Ms100_Counts >= 10)
			{
			  Pub_Timer.Ms100_Counts = 0;
			  Pub_Timer.Sec ++;
			}
		}
	}
#endif

//GPIO_ResetBits(GPIOB,GPIO_Pin_9); //测试输出
}
#undef PUB_C
