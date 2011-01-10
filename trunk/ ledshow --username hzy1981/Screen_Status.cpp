#define SCREEN_STATUS_C
#include "Includes.h"

//亮度控制--获取pTime所处时段的亮度
INT8U Get_Cur_Time_Lightness(S_Time *pTime)
{
  INT8U i;
  INT8U Min = 0xFF,Diff;
  INT8U Lightness;
  
  Lightness = MAX_LIGHTNESS_LEVEL; //最高亮度登记
  
  for(i = 0; i < MAX_LIGHTNESS_TIME; i++)
  {
    if(Screen_Para.Lightness[i].Flag > 0) //启用该时段的亮度控制
    {
      //计算当前时间和该段时间按的时间差
      Diff = (pTime->Time[T_HOUR] + 24 - Screen_Para.Lightness[i].Start_Hour) % 24;
      if(Diff < Min)
      {
        Min = Diff;
        Lightness = Screen_Para.Lightness[i].Value;
      }
    }
  }
  
  return Lightness; 
}

//获取当前开关机状态
//返回1表示应该在开机状态，0表示应该在关机状态
INT8U Get_Open_Close_Status(S_Time *pTime)
{
  INT8U i;
  INT16U Min, Min0,Min1;
  
  for(i = 0; i < MAX_OPEN_CLOSE_TIME; i++)
  {
    if(Screen_Para.Open_Close_Time[i].Flag > 0)
    {
      Min0 = Screen_Para.Open_Close_Time[i].Open_Hour*60 + Screen_Para.Open_Close_Time[i].Open_Min;
      Min1 = Screen_Para.Open_Close_Time[i].Close_Hour*60 + Screen_Para.Open_Close_Time[i].Close_Min;
      Min = pTime->Time[T_HOUR]*60 + pTime->Time[T_MIN];
      
      if(Min0 < Min1)
      {
        if(Min >= Min0 && Min <= Min1)
          return 1;
        else
          return 0;
      }
      else
      {
        if(Min >= Min0 || Min <= Min1)
          return 1;
        else
          return 0;      
      }
    }
  }
  
  return 1;
}

//亮度控制
void Lightness_Proc()
{
  Screen_Status.Lightness = Get_Cur_Time_Lightness(&Cur_Time);  
  
}

//开关机控制
void Open_Close_Proc()
{
  Screen_Status.Open_Flag = Get_Open_Close_Status(&Cur_Time);
  
}

//获取屏幕亮度
INT8U Get_Screen_Lightness()
{
  return Screen_Status.Lightness;
}

//获取屏幕开机状态
INT8U Get_Screen_Open_Status()
{
  return Screen_Status.Open_Flag;
}


void Screen_Proc()
{
  Lightness_Proc();
  Open_Close_Proc();
}
