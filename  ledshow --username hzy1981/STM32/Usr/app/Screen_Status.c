#define SCREEN_STATUS_C
#include "Includes.h"

#if QT_EN EQ 0
//获取当前温度
INT16S Get_Cur_Temp(void)
{
  return Screen_Status.Temperature; 
}

//获取当前湿度
INT16U Get_Cur_Humidity(void)
{
  return Screen_Status.Humidity; 
}

//获取当前噪音
INT16U Get_Cur_Noise(void)
{
  return Screen_Status.Noise;
}
#endif

//环境变量处理
void Screen_Env_Proc()
{
#if ENV_VAR_EN
  static S_Int32U Sec = {CHK_BYTE, 0xFFFFFFFF, CHK_BYTE};
  static S_Int32U Counts = {CHK_BYTE, 0x00, CHK_BYTE};

  //接收到数据达到一帧则处理
  if(Screen_Status.Env_Rcv_Posi >= 3 + F_NDATA_LEN)
  {
    Screen_Status.Env_Frame_Flag = 1;

    if(Check_Frame_Format((INT8U *)Screen_Status.Env_Rcv_Data, Screen_Status.Env_Rcv_Posi))	  
	  Rcv_Frame_Proc(CH_ENV, (INT8U *)Screen_Status.Env_Rcv_Data, Screen_Status.Env_Rcv_Posi, sizeof(Screen_Status.Env_Rcv_Data)); 

	Clr_Env_Rcv_Data();
  }

  //每秒发送一帧查询数据
  if(Sec.Var != Pub_Timer.Sec)
  {
    Sec.Var = Pub_Timer.Sec;
    Counts.Var ++;

	Clr_Env_Rcv_Data();

    Screen_Status.Env_Frame_Flag = 1; //利用接收缓冲区发送数据，因此在打包发送期间不能接收数据

	if(Counts.Var EQ 1)
      Send_Env_Frame(0x00);
	else if(Counts.Var EQ 2)
      Send_Env_Frame(0x01);
	else if(Counts.Var >= 3)
    { 
	  Send_Env_Frame(0x02);
	  Counts.Var = 0;
	 }

	 Screen_Status.Env_Frame_Flag = 0;
  }
#endif
}

//亮度控制--获取pTime所处时段的亮度
INT8U Get_Cur_Time_Lightness(S_Time *pTime)
{
  INT8U Lightness;
  
#if CLOCK_EN  
  INT8U i;
  INT8U Min = 0xFF,Diff;  

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
#else
  Lightness = Screen_Para.Lightness.Manual_Lightness;
#endif
  
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

#if CLOCK_EN
   Lightness = Get_Cur_Time_Lightness(&Cur_Time);
#else
   Lightness = Screen_Para.Lightness.Manual_Lightness;
#endif    
   //Lightness = 100 * Lightness / (MAX_LIGHTNESS_LEVEL - 1); //转化为百分数
   if(Lightness >= MAX_LIGHTNESS_LEVEL)
     Lightness = MAX_LIGHTNESS_LEVEL - 1;

   Screen_Status.Lightness = Lightness;

   Set_OE_Duty_Polarity(Screen_Status.Lightness + 1, Screen_Para.Scan_Para.OE_Polarity);  //设置亮度, 等级为0时有亮度，因此+1
}


//内部温度传感器的温度处理
void Screen_Temperature_Proc(void)
{
  INT32S TempCumu;
  INT8U i;
  static S_Int32U Sec = {CHK_BYTE, 0xFFFFFFFF, CHK_BYTE};

  if(Sec.Var != SEC_TIMER)
  {
    Sec.Var = SEC_TIMER;

	if(Screen_Status.Ext_Temperature_Sec_Counts)  //大于0表示通信接收到了外部传感器命令
	  Screen_Status.Ext_Temperature_Sec_Counts --;
    else
	{
	  if(Inter_Temp.Posi >= S_NUM(Inter_Temp.TempData))
		Inter_Temp.Posi = 0;

      Inter_Temp.TempData[Inter_Temp.Posi ++] = GetInterTemperature();// 0~17

	  if(Inter_Temp.Counts < S_NUM(Inter_Temp.TempData))
	    Inter_Temp.Counts ++;

	  TempCumu = 0;
	  for(i = 0; i < Inter_Temp.Counts; i ++)
	  {
	    TempCumu += Inter_Temp.TempData[i];
	  }

	  Screen_Status.Temperature = TempCumu / Inter_Temp.Counts;
      debug("temp = %d", Screen_Status.Temperature);
	}
  }
//INT16U GetADCValue(INT8U ADC_Channel)//ADC_Channel_x 0~17

}

//开关机控制
void Screen_Open_Close_Proc(void)
{
#if CLOCK_EN
  if(Get_Open_Close_Status(&Cur_Time))
    Screen_Status.Time_OC_Flag = OPEN_FLAG;
  else
    Screen_Status.Time_OC_Flag = CLOSE_FLAG;
#else
  Screen_Status.Time_OC_Flag = OPEN_FLAG;  //没有时钟,则直接设置时钟判断为打开
#endif  
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

#if CLOCK_EN
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
#endif
//每分钟读取一次实时时钟
void Screen_Time_Proc()
{
#if CLOCK_EN
#if QT_EN
  Get_Cur_Time();
#else
  static S_Int32U Sec = {CHK_BYTE, 0, CHK_BYTE};
  static S_Int8U Flag = {CHK_BYTE, 0xAA, CHK_BYTE};
  INT32U Diff;
  
  Diff = Pub_Timer.Sec - Sec.Var;

  if(Diff != 0)
  {
    Cur_Time.Time[T_SEC] += Diff;
    SET_SUM(Cur_Time);
  }

  if(Cur_Time.Time[T_SEC] >= 60 || Flag.Var EQ 0xAA)
  {
    Flag.Var = 0;
    Get_Cur_Time();
  }

   Sec.Var = Pub_Timer.Sec;
#endif
#endif 
}


void Screen_Check_Lock_Date() //检查是否在有限显示日期内
{

#if QT_EN
  return;
#endif

#if CLOCK_EN
  //valid_date为全0或者格式不正确 
  if(Screen_Para.Lock_Date.Lock_Date_Flag != LOCK_DATE_FLAG || \
     Screen_Para.Lock_Date.Time[1] > 12 || Screen_Para.Lock_Date.Time[0] > 31)
  {
    Screen_Status.Lock_Date_Flag = 0;
    return;
   }

  //当前时间在截止日期后
  if(Cur_Time.Time[T_YEAR] > Screen_Para.Lock_Date.Time[2] ||\
    (Cur_Time.Time[T_YEAR] EQ Screen_Para.Lock_Date.Time[2] && Cur_Time.Time[T_MONTH] > Screen_Para.Lock_Date.Time[1]) ||\
    (Cur_Time.Time[T_YEAR] EQ Screen_Para.Lock_Date.Time[2] && Cur_Time.Time[T_MONTH] EQ Screen_Para.Lock_Date.Time[1] && Cur_Time.Time[T_DATE] >= Screen_Para.Lock_Date.Time[0]))
   {
     Screen_Status.Lock_Date_Flag = LOCK_DATE_FLAG;

     Set_RT_Show_Area(0, 0, Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height);
	 
	 RT_Play_Status_Enter(20);	 //进入实时显示状态,全屏显示XXXXXXXXXX
	 LED_Print(FONT0, Screen_Para.Base_Para.Color, &Show_Data, 0, 0, 0, "XXXXXXXXXXXXXXXX");
   }
   else
   {
     RT_Play_Status_Exit();
	 if(Screen_Status.Lock_Date_Flag EQ LOCK_DATE_FLAG)//退出锁定状态，复位！！！
     {
	   Soft_Rest();
	   //Screen_Status.Lock_Date_Flag = 0;
	 }
   }
#endif
}

void Screen_Proc(void)
{
  Screen_Time_Proc();
  Screen_Lightness_Proc();
  Screen_Temperature_Proc();
  Screen_Open_Close_Proc();
  Screen_Com_Proc(); //屏幕通信处理
  Screen_Check_Lock_Date();
}
