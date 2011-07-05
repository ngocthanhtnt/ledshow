#define SCREEN_STATUS_C
#include "Includes.h"

//亮度控制--获取pTime所处时段的亮度
INT8U Get_Cur_Time_Lightness(S_Time *pTime)
{
  INT8U i;
  INT8U Min = 0xFF,Diff;
  INT8U Lightness;
  
  if(Screen_Para.Lightness.Mode EQ MANUAL_ADJ)
  {
    Lightness = Screen_Para.Lightness.Manual_Lightness;
  }
  else if(Screen_Para.Lightness.Mode EQ TIME_ADJ)
  {
      Lightness = MAX_LIGHTNESS_LEVEL-1; //最高亮度登记

      for(i = 0; i < MAX_LIGHTNESS_TIME; i++)
      {
        if(Screen_Para.Lightness.Time_Lightness[i].Flag > 0) //启用该时段的亮度控制
        {
          //计算当前时间和该段时间按的时间差
          Diff = (pTime->Time[T_HOUR] + 24 - Screen_Para.Lightness.Time_Lightness[i].Start_Hour) % 24;
          if(Diff < Min)
          {
            Min = Diff;
            Lightness = Screen_Para.Lightness.Time_Lightness[i].Value;
          }
        }
      }

      //return Lightness;
  }
  else
  {
    Lightness = MAX_LIGHTNESS_LEVEL / 2;
  }
  
  if(Lightness >= MAX_LIGHTNESS_LEVEL)
      Lightness = MAX_LIGHTNESS_LEVEL - 1;

  return Lightness; 
}

//获取当前开关机状态
//返回1表示应该在开机状态，0表示应该在关机状态
INT8U Get_Open_Close_Status(S_Time *pTime)
{
  INT8U Flag = 0;
  INT8U i;
  INT16U Min, Min0,Min1;
  
  for(i = 0; i < MAX_OPEN_CLOSE_TIME; i++)
  {
     //任何一个时段开启则将Flag置1
    if(Screen_Para.OC_Time.Time[i].Flag > 0)
    {
      Flag = 1;
      Min0 = Screen_Para.OC_Time.Time[i].Open_Hour*60 + Screen_Para.OC_Time.Time[i].Open_Min;
      Min1 = Screen_Para.OC_Time.Time[i].Close_Hour*60 + Screen_Para.OC_Time.Time[i].Close_Min;
      Min = pTime->Time[T_HOUR]*60 + pTime->Time[T_MIN];
      
      if(Min0 < Min1)
      {
        if(Min >= Min0 && Min <= Min1)
          return 1;
      }
      else
      {
        if(Min >= Min0 || Min <= Min1)
          return 1;

      }
    }
  }
  
  if(Flag EQ 1) //起码启用了一个时段，但不再改时段内
     return 0;
  else
     return 1; //没有设置启用
}

//亮度控制
void Screen_Lightness_Proc(void)
{
   INT8U Lightness;

   Lightness = Get_Cur_Time_Lightness(&Cur_Time); 
   Screen_Status.Lightness = 100 * Lightness / (MAX_LIGHTNESS_LEVEL - 1); //转化为百分数
  
}

//开关机控制
void Screen_Open_Close_Proc(void)
{
  if(Get_Open_Close_Status(&Cur_Time))
    Screen_Status.Time_OC_Flag = 0;
  else
    Screen_Status.Time_OC_Flag = CLOSE_FLAG;
  
}

//获取屏幕亮度
INT8U Get_Screen_Lightness(void)
{
  return Screen_Status.Lightness;
}

//获取屏幕开机状态
INT8U Get_Screen_Open_Status(void)
{
  return Screen_Status.Time_OC_Flag;
}

//设置重新播放标志
void Set_Screen_Replay_Flag(void)
{
    Screen_Status.Replay_Flag = REPLAY_FLAG;
    SET_SUM(Screen_Status);
}

//检查是否重新播放
INT8U Chk_Screen_Replay_Flag(void)
{
    if(Screen_Status.Replay_Flag EQ REPLAY_FLAG)
      return 1;
    else
      return 0;
}

//设置通信时间,在通信时间范围内，扫描中断不进行扫
void Set_Screen_Com_Time(INT8U Sec)
{
    Screen_Status.Com_Time = Sec;
    //SET_SUM(Screen_Status);
}

INT8U Get_Screen_Com_Time(void)
{
   return Screen_Status.Com_Time;
}

//获取当前时间
INT8U Get_Cur_Time()
{
  INT8U Re;
  INT8U Time[10];

  Re = _Get_Cur_Time(Time); //获取当前时间
  if(Re)
  {
     memcpy(Cur_Time.Time, Time, sizeof(Cur_Time.Time));
     SET_SUM(Cur_Time);
  }

  return Re;
}

INT8U Chk_Time(S_Time *pTime)
{
  if(CHK_SUM((*pTime)) && CHK_HT((*pTime)))
  {
	if(pTime->Time[T_SEC] < 60 && pTime->Time[T_MIN] < 60 && pTime->Time[T_HOUR] < 24 &&\
	   pTime->Time[T_DATE] > 0 && pTime->Time[T_DATE] < 32 &&\
	   pTime->Time[T_MONTH] > 0 && pTime->Time[T_MONTH] < 32)
	   return 1;

  }

  return 0;
}

//每分钟读取一次实时时钟
void Screen_Time_Proc()
{
  static S_Int32U Sec = {CHK_BYTE, 0, CHK_BYTE};
  INT32U Diff;
  
  Diff = Pub_Timer.Sec - Sec.Var;

  //if(Diff != 0)
  {
     Cur_Time.Time[T_SEC] += Diff;
	 if(Cur_Time.Time[T_SEC] >= 60 || Sec.Var EQ 0)
	 {
	   //Cur_Time.Time[T_SEC] = 0;
	   Get_Cur_Time();
	 }
         //Get_Cur_Time();//_Get_Cur_Time(Cur_Time.Time); //获取当前时间
   }

   Sec.Var = Pub_Timer.Sec;
 
}

void Screen_Proc(void)
{
  Screen_Time_Proc();
  Screen_Lightness_Proc();
  Screen_Open_Close_Proc();
  Screen_Com_Proc(); //屏幕通信处理
  //Get_Cur_Time(Cur_Time.Time);
}
