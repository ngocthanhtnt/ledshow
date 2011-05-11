#define MAIN_SHOW_C
#include "includes.h"

/*
//每档速度的延时,单位为毫秒
const INT16U Step_Delay[]=
{
  10,
  20,
  30,
  40,
  50,
  60,
  70,
  80,
  90,
  100
};
*/

//获取某个窗口区域某个步进的停留时间
INT32U Get_Area_In_Step_Delay(INT8U Area_No)
{
  return CONVERT_TIME(Prog_Status.File_Para[Area_No].Pic_Para.In_Time);///(100/MOVE_STEP);
}

//获取某个窗口区域某个步进的停留时间
INT32U Get_Area_Out_Step_Delay(INT8U Area_No)
{
  return CONVERT_TIME(Prog_Status.File_Para[Area_No].Pic_Para.Out_Time);///(100/MOVE_STEP);
}

//获取文件引入时间
INT32U Get_File_In_Time(INT8U Area_No)
{
 return CONVERT_TIME(Prog_Status.File_Para[Area_No].Pic_Para.In_Time);
  
}

//获取文件的停留时间,单位为ms
//原参数最高为表示单位，0为s，1为ms
INT32U Get_File_Stay_Time(INT8U Area_No)
{
  return CONVERT_TIME(Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time);
}

//获取文件引出时间
INT32U Get_File_Out_Time(INT8U Area_No)
{
  return CONVERT_TIME(Prog_Status.File_Para[Area_No].Pic_Para.Out_Time);  
}

//设置文件的停留时间
void Set_File_Stay_Time(INT8U Area_No, INT16U ms)
{
  Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time = ms;
  Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time = Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time | 0x8000;
}

//每隔MOVE_STEP_TIMER ms调用该函数,实现移动显示等效果
void Update_Show_Data(void)
{
  INT8U i;

  if(Screen_Status.Open_Flag EQ 0)
    return;

  if(Prog_Status.Play_Status.RT_Play_Flag EQ RT_PLAY_FLAG) //当前在关机状态或者实时显示状态
	{/*
	  if(Prog_Status.Play_Status.RT_Play_Flag EQ RT_PLAY_FLAG)
	  {
	    Prog_Status.Play_Status.RT_Play_Time -= MOVE_STEP_PERIOD;
		if(Prog_Status.Play_Status.RT_Play_Time EQ 0)
		  RT_Play_Status_Exit();  
	  }    
	  */
	  return;
	}
  for(i = 0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {
      if(Screen_Status.Rcv_Flag EQ FRAME_FLAG) //收到一帧，先处理此帧
          return;
//#if PIC_SHOW_EN    
    //if(Prog_Status.File_Para[i].Pic_Para.Flag EQ SHOW_PIC)
      Update_Pic_Data(i);
//#endif
/*
#if CLOCK_SHOW_EN
    else if(Prog_Status.File_Para[i].Pic_Para.Flag EQ SHOW_CLOCK)
      Update_Clock_Data(i);
#endif
      */
    /*
#if TIMER_SHOW_EN
    else if(Prog_Status.File_Para[i].Pic_Para.Flag EQ SHOW_TIMER)
      Update_Timer_Data(i);
#endif
      */
    /*
#if TIME_SHOW_EN
    else if(Prog_Status.File_Para[i].Pic_Para.Flag EQ SHOW_TIME)
      Update_Time_Data(i);
#endif
      */
    /*
#if TEMP_SHOW_EN
    else if(Prog_Status.File_Para[i].Pic_Para.Flag EQ SHOW_TEMP)
      Update_Temp_Data(i);
#endif
      */
    /*
#if LUN_SHOW_EN
    else if(Prog_Status.File_Para[i].Pic_Para.Flag EQ SHOW_LUN)
      Update_Lun_Data(i);
#endif
      */
  }
#if BORDER_SHOW_EN
  Update_Border_Data(MAX_AREA_NUM); //更新边框数据
#endif  
}

//更新显示备份区数据、显示非固定文本类信息
INT8U Update_XXX_Data(S_Show_Data *pDst, INT8U Area_No)
{
  INT8U Flag; 
  
  Flag = Prog_Status.File_Para[Area_No].Pic_Para.Flag;
  
  //某些非图文数据需要定时刷新!应该保证每分钟进入一次
  if(Flag EQ SHOW_PIC)
    ;
#if CLOCK_SHOW_EN  
  else if(Flag EQ SHOW_CLOCK)
    Update_Clock_Data(pDst, Area_No);
#endif
#if TIME_SHOW_EN  
  else if(Flag EQ SHOW_TIME)
    Update_Time_Data(pDst, Area_No);
#endif
#if TIMER_SHOW_EN  
  else if(Flag EQ SHOW_TIMER)
    Update_Timer_Data(pDst, Area_No);
#endif
#if TEMP_SHOW_EN  
  else if(Flag EQ SHOW_TEMP)
    Update_Temp_Data(pDst, Area_No);
#endif
#if LUN_SHOW_EN  
  else if(Flag EQ SHOW_LUN)
    Update_Lun_Data(pDst, Area_No);
#endif
#if HUMIDITY_SHOW_EN
  else if(Flag EQ SHOW_HUMIDITY)
    Update_Humidity_Data(pDst, Area_No);
#endif
#if NOISE_SHOW_EN
  else if(Flag EQ SHOW_NOISE)
    Update_Noise_Data(pDst, Area_No);
#endif
  else
    ASSERT_FAILED(); 
  
  return 1;
}
/*
//清楚某个分区的状态
void Clr_Area_Status(INT8U Area_No)
{
  if(Area_No >= MAX_AREA_NUM)
  {
    ASSERT_FAILED();
    return;
  }
  
  memset(&Prog_Status.Area_Status[Area_No], 0, sizeof(Prog_Status.Area_Status[Area_No])); 
  SET_HT(Prog_Status.Area_Status[Area_No]);
}

void Clr_All_Area_Status()
{
    INT8U i;

    for(i = 0; i < MAX_AREA_NUM; i++)
    {
        Clr_Area_Status(i);
    }
}
*/
void Clr_Show_Data(void)
{
  memset(Show_Data.Color_Data, 0, sizeof(Show_Data.Color_Data));
  memset(Show_Data_Bak.Color_Data, 0, sizeof(Show_Data_Bak.Color_Data));
  SET_HT(Show_Data);
  SET_HT(Show_Data_Bak);
}

//读取一屏显示数据
//prog节目号
//area分区号
INT8U Update_Show_Data_Bak(INT8U Prog_No, INT8U Area_No)
{
  INT16U Len;//,SNum;
  INT16S Len0;
  INT16U X,Y,Width,Height;
  INT8U Re = 1;
  //INT8U File_No;
  //INT8U Counts;

  Re &= CHK_SUM(Prog_Status.Play_Status);
  if(Re EQ 0)
      ASSERT_FAILED();
  Re &= CHK_SUM(Prog_Status.Area_Status[Area_No]);
  if(Re EQ 0)
      ASSERT_FAILED();
  Re &= CHK_SUM(Prog_Para);
  if(Re EQ 0)
      ASSERT_FAILED();

  //所有分屏都显示了则切换到下个显示文件
  if(Prog_Status.Play_Status.New_Prog_Flag) //在节目更新状态中，不更新文件参数
      return 0;

  if(Prog_Para.Area_File_Num[Area_No] EQ 0)
      return 0;
/*
  if(Prog_Status.Area_Status[Area_No].New_File_Flag EQ 0 &&\
     Prog_Status.Area_Status[Area_No].New_SCN_Flag > 0)
  {
      if(Prog_Status.Area_Status[Area_No].SCN_No >= Prog_Status.File_Para[Area_No].Pic_Para.SNum)
      {
          Prog_Status.Area_Status[Area_No].New_File_Flag = NEW_FLAG; //到了最后一屏则切换到下一个文件
          Prog_Status.Area_Status[Area_No].File_No ++;
          SET_SUM(Prog_Status.Area_Status[Area_No]);
      }
  }
*/
  TRACE();

  //检查是否需要更新到下一文件
  if(Prog_Status.Area_Status[Area_No].New_File_Flag)//SNum > Prog_Status.File_Para[Area_No].Pic_Para.SNum)
  {
      TRACE();

    //debug("prog %d area %d file %d play end!", Prog_Status.Play_Status.Prog_No, Area_No, Prog_Status.Area_Status[Area_No].File_No);

    Prog_Status.Area_Status[Area_No].SCN_No = 0;
    SET_SUM(Prog_Status.Area_Status[Area_No]);
    //文件参数读取失败则切换到下个文件

    if(Prog_Status.Area_Status[Area_No].File_No >= Prog_Para.Area_File_Num[Area_No] ||\
       Prog_Status.Area_Status[Area_No].File_No >= MAX_FILE_NUM) //所有文件全部都播放了一遍
    {
      Prog_Status.Area_Status[Area_No].File_No = 0;
      Prog_Status.Area_Status[Area_No].Counts++; //文件播放一次+1
      SET_SUM(Prog_Status.Area_Status[Area_No]);

      Check_Prog_Play_Counts();
      if(Check_Prog_End() > 0) //节目结束了！
      {
         Prog_Status.Play_Status.New_Prog_Flag = NEW_FLAG; //新节目
         Prog_Status.Play_Status.Prog_No ++;
         SET_SUM(Prog_Status.Play_Status);
         return 0;
      }
   }

    debug("\r\nprog %d area %d play new file: %d", Prog_No, Area_No, Prog_Status.Area_Status[Area_No].File_No);
    //先将文件参数读出 
    //Prog_Status.Area_Status[Area_No].Play_Flag = 0; //关闭本分区显示
    //SET_SUM(Prog_Status.Area_Status[Area_No]);

    if(Prog_Status.Area_Status[Area_No].Last_File_No EQ Prog_Status.Area_Status[Area_No].File_No &&\
       CHK_HT(Prog_Status.Area_Status[Area_No]) &&\
       CHK_SUM(Prog_Status.Area_Status[Area_No]) &&\
       Prog_Status.File_Para[Area_No].Pic_Para.Flag != SHOW_NULL &&\
       Chk_File_Para_HT_Sum(&Prog_Status.File_Para[Area_No]))
    {
        debug("the same as last file ,no update");
       Len = 1;
    }
    else
    {
        Len = 0;
        Prog_Status.Area_Status[Area_No].Last_SCN_No = 0xFFFF;
        Prog_Status.Area_Status[Area_No].Last_File_No = 0xFF; //先预置一个不存在的文件号
        SET_SUM(Prog_Status.Area_Status[Area_No]);

    #if DATA_PREP_EN
        if(GET_VAR(Prep_Data.Para_Prog_No[Area_No]) EQ Prog_Status.Play_Status.Prog_No &&\
           GET_VAR(Prep_Data.Para_File_No[Area_No]) EQ Prog_Status.Area_Status[Area_No].File_No &&\
           GET_VAR(Prep_Data.File_Para_Ok_Flag[Area_No]) EQ DATA_OK &&\
           Chk_File_Para_HT_Sum(&Prep_Data.File_Para[Area_No]))
        {
            memcpy(&Prog_Status.File_Para[Area_No], &Prep_Data.File_Para[Area_No], sizeof(U_File_Para));
            Len = 1;
        }
        else
            Len = Read_File_Para(Prog_No, Area_No, Prog_Status.Area_Status[Area_No].File_No, \
                           &Prog_Status.File_Para[Area_No].Pic_Para.Flag, \
                           &Prog_Status.File_Para[Area_No], sizeof(U_File_Para));

        SET_VAR(Prep_Data.File_Para_Read_Flag[Area_No], DATA_READ);
    #else
        Len = Read_File_Para(Prog_No, Area_No, Prog_Status.Area_Status[Area_No].File_No, \
                       &Prog_Status.File_Para[Area_No].Pic_Para.Flag, \
                       &Prog_Status.File_Para[Area_No], sizeof(U_File_Para));
    #endif
    }

    if(Len EQ 0) //读不出来则继续读下一个文件参数
    {
      ASSERT_FAILED();

      Prog_Status.File_Para[Area_No].Pic_Para.Flag = SHOW_NULL;
      Prog_Status.Area_Status[Area_No].New_File_Flag = NEW_FLAG;
      Prog_Status.Area_Status[Area_No].File_No ++;
    }
    else
    {
        //Set_File_Para_HT_Sum(&Prog_Status.File_Para[Area_No]);
        //读出文件参数了，保留为上次读出的文件参数
        Prog_Status.Area_Status[Area_No].Last_File_No = Prog_Status.Area_Status[Area_No].File_No;
        Prog_Status.Area_Status[Area_No].New_File_Flag = 0;
        Prog_Status.Area_Status[Area_No].New_SCN_Flag = NEW_FLAG;
        Prog_Status.Area_Status[Area_No].SCN_No = 0;
    }

    SET_SUM(Prog_Status.Area_Status[Area_No]);
    Set_File_Para_HT_Sum(&Prog_Status.File_Para[Area_No]);
  }

  TRACE();
  //更新文件参数过程中不更新分屏数据
  if(Prog_Status.Area_Status[Area_No].New_File_Flag)// EQ 0 &&
    return 0;

  //更新数据到新的一屏
  if(Prog_Status.Area_Status[Area_No].New_SCN_Flag)
  {
      TRACE();
      //已经到了最大的一幕则切换到下个文件
      if(Prog_Status.Area_Status[Area_No].SCN_No >= Prog_Status.File_Para[Area_No].Pic_Para.SNum)
      {
          Prog_Status.Area_Status[Area_No].New_File_Flag = NEW_FLAG;
          Prog_Status.Area_Status[Area_No].File_No ++;
          SET_SUM(Prog_Status.Area_Status[Area_No]);
          return 0;
      }

      //读出显示数据
      //Prog_Status.Area_Status[Area_No].Play_Flag = 0; //--读取显示数据过程中将播放标志置0，从而中断程序中不播放
      //SET_SUM(Prog_Status.Area_Status[Area_No]);

      debug("\r\nread prog %d area %d, file %d %dth SCN show data", \
            Prog_No, Area_No, Prog_Status.Area_Status[Area_No].File_No,Prog_Status.Area_Status[Area_No].SCN_No);
#if 0
      if(Prog_Status.Area_Status[Area_No].Last_SCN_No EQ Prog_Status.Area_Status[Area_No].SCN_No &&\
         CHK_HT(Prog_Status.Area_Status[Area_No]) &&\
         CHK_SUM(Prog_Status.Area_Status[Area_No]) &&\
         Check_XXX_Data(Prog_Status.File_Para[Area_No].Pic_Para.Flag) EQ 0)
      {
         debug("the same as last SCN ,no update");
         Len0 = 1;
      }
      else
#endif
      {
          Clear_Area_Data(&Show_Data_Bak, Area_No);

          Prog_Status.Area_Status[Area_No].Last_SCN_No = 0xFFFF;
          SET_SUM(Prog_Status.Area_Status[Area_No]);

          Len0 = -1;
    #if DATA_PREP_EN > 0
          if(GET_VAR(Prep_Data.Data_Prog_No[Area_No]) EQ Prog_Status.Play_Status.Prog_No &&\
             GET_VAR(Prep_Data.Data_File_No[Area_No]) EQ Prog_Status.Area_Status[Area_No].File_No &&\
             GET_VAR(Prep_Data.Data_Ok_Flag[Area_No]) EQ DATA_OK &&\
             GET_VAR(Prep_Data.Data_SCN_No[Area_No]) EQ Prog_Status.Area_Status[Area_No].SCN_No)
          {

            S_Point P0;
            debug("use prepaid data: area_no:%d, SCN_No:%d", Area_No, GET_VAR(Prep_Data.Data_SCN_No[Area_No]));
            P0.X = GET_VAR(Prep_Data.Data_X[Area_No]);
            P0.Y = GET_VAR(Prep_Data.Data_Y[Area_No]);
            Copy_Filled_Rect(&Prep_Data.Show_Data, \
                             Area_No,\
                             &P0,\
                             GET_VAR(Prep_Data.Data_Width[Area_No]),\
                             GET_VAR(Prep_Data.Data_Height[Area_No]),\
                             &Show_Data_Bak,\
                             &P0);

            Len0 = 1;//GET_TEXT_LEN(Prep_Data.Data_Width[Area_No]
          }
          else
              Len0 = Read_Show_Data(Area_No, \
                             Prog_Status.Area_Status[Area_No].File_No, \
                             &Prog_Status.File_Para[Area_No],\
                             Prog_Status.Area_Status[Area_No].SCN_No,\
                             &Show_Data_Bak,&X,&Y,&Width,&Height);

          SET_VAR(Prep_Data.Data_Read_Flag[Area_No] , DATA_READ);
    #else
          Len0 = Read_Show_Data(Area_No, \
                         Prog_Status.Area_Status[Area_No].File_No, \
                         &Prog_Status.File_Para[Area_No],\
                         Prog_Status.Area_Status[Area_No].SCN_No,\
                         &Show_Data_Bak,&X,&Y,&Width,&Height);
    #endif
      }

      TRACE();

      if(Len0 >= 0)
      {
        Prog_Status.Area_Status[Area_No].Last_SCN_No = Prog_Status.Area_Status[Area_No].SCN_No;
        //Prog_Status.Area_Status[Area_No].Play_Flag = 1; //打开本分区显示
        Prog_Status.Area_Status[Area_No].New_SCN_Flag = 0;
        SET_SUM(Prog_Status.Area_Status[Area_No]);
      }
      else
      {
        //本屏显示数据没有读到则读下屏数据

        ASSERT_FAILED();
        Prog_Status.Area_Status[Area_No].New_SCN_Flag = NEW_FLAG;
        Prog_Status.Area_Status[Area_No].SCN_No ++; //显示屏数增加
        SET_SUM(Prog_Status.Area_Status[Area_No]);
      }
  }


//-----------------
  return AREA_OK;
}


//检测更新显示备份区数据
INT8U Check_Update_Show_Data_Bak(void)
{
  INT8U i;
  //INT32U Stay_Time;
  //S_Int8U Sec = {CHK_BYTE, 0xFF, {0},CHK_BYTE};
  
  //if(Prog_Status.Play_Status.Play_Flag EQ 0)
      //return 0;

  for(i = 0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {

     if(Screen_Status.Rcv_Flag EQ FRAME_FLAG) //收到一帧，先处理此帧
         return 1;

     if(Prog_Status.Area_Status[i].New_File_Flag ||\
        Prog_Status.Area_Status[i].New_SCN_Flag)
     {
      Update_Show_Data_Bak(Prog_Para.Prog_No, i);// == FILE_END)
    }
  }
 /*
  //每秒更新一下时钟、温度、计时等数据
  if(Sec.Var != Cur_Time.Time[T_SEC])
  {
    Sec.Var = Cur_Time.Time[T_SEC];    
    for(i = 0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
    {    
      Update_XXX_Data_Bak(i);
    }
  }
  */
  return 1;
}

void Check_Update_Show_Data(void)
{
  
}

void Clr_Prog_Status(void)
{
  memset(&Prog_Status, 0, sizeof(Prog_Status));
  //SET_HT(Prog_Status);
  
}

//检查节目是否播放结束
//返回1表示结束了，0表示还没有结束
INT8U Check_Prog_End(void)
{
  if(Check_Prog_Play_Time() EQ 0)
  {
     debug("prog %d now not play time, end", Prog_Status.Play_Status.Prog_No);
     return 1;
  }
  //次数模式
  if(Prog_Para.Mode EQ PROG_COUNTS_MODE)
  {
    if(Prog_Status.Play_Status.Counts >= Prog_Para.Counts)
    {
      debug("prog %d play counts %d, end", Prog_Status.Play_Status.Prog_No, Prog_Status.Play_Status.Counts);
      return 1;
    }
    else
      return 0;
  }
  else if(Prog_Para.Mode EQ PROG_TIME_MODE)//时间模式
  {
    if(Prog_Status.Play_Status.Time >= Prog_Para.Time)
    {
      debug("prog %d play times %d, end", Prog_Status.Play_Status.Prog_No, Prog_Status.Play_Status.Time);
      return 1;
    }
    else
      return 0;
  }
  else
  {
    ASSERT_FAILED();
    return 1;
  } 
}

//定时信息中，星期的第0位表示星期1，第6位表示星期六
//检查当前时间是否在节目播放允许时间内，是则返回1，否则返回0
INT8U Check_Prog_Play_Time(void)
{
  //INT8U i;//Re = 1;
  INT8U Temp[20];
  memset(Temp, 0xFF, sizeof(Temp));

  //按星期定时
  if(Prog_Para.Timing[0].Week_Check > 0)
  {
    if(GET_BIT(Prog_Para.Timing[0].Week_Flag, Cur_Time.Time[T_WEEK]) EQ 0)
      return 0;
  }


  //按日期定时
  if(Prog_Para.Timing[0].Date_Check > 0)
  {
    if(!(Cur_Time.Time[T_YEAR] >= Prog_Para.Timing[0].Start_Date[0] &&\
        Cur_Time.Time[T_YEAR] <= Prog_Para.Timing[0].End_Date[0] &&\
        Cur_Time.Time[T_MONTH] >= Prog_Para.Timing[0].Start_Date[1] &&\
        Cur_Time.Time[T_MONTH] <= Prog_Para.Timing[0].End_Date[1] &&\
        Cur_Time.Time[T_DATE] >= Prog_Para.Timing[0].Start_Date[2] &&\
        Cur_Time.Time[T_DATE] <= Prog_Para.Timing[0].End_Date[2]))
      return 0;

  }

  //按时间定时
  if(Prog_Para.Timing[0].Time_Check > 0)
  {
    if(!(Cur_Time.Time[T_HOUR] >= Prog_Para.Timing[0].Start_Time[0] &&\
        Cur_Time.Time[T_HOUR] <= Prog_Para.Timing[0].End_Time[0] &&\
        Cur_Time.Time[T_MIN] >= Prog_Para.Timing[0].Start_Time[1] &&\
        Cur_Time.Time[T_MIN] <= Prog_Para.Timing[0].End_Time[1]))
      return 0;

  }

  return 1;
}

/*
INT8U Check_Prog_Play_Time()
{
 return 1;
}
*/
//每隔MOVE_STEP_TIMER ms 调用该函数，实现移动效果
void Show_Timer_Proc(void)
{
  //Pub_Timer_Proc(); //定时器
  Update_Show_Data(); //更新显示数据

}

INT8U Inc_Prog_No(INT8U Prog_No)
{
  return 1;
}

void Check_Prog_Play_Counts(void)
{
    INT16U Min_Counts = 0xFFFF;
    INT8U i;

    //最小播放次数是节目的播放次数---次数也可采用主分区的播放次数
    Min_Counts = 0xFFFF;
    for(i = 0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
    {
      if(Prog_Status.Area_Status[i].Counts < Min_Counts)
        Min_Counts = Prog_Status.Area_Status[i].Counts;
    }

    Prog_Status.Play_Status.Counts = Min_Counts; //在所有分区内的最小播放次数就是节目的总播放次数
    SET_SUM(Prog_Status.Play_Status);
}
//检查是否需要更新节目参数
void Check_Update_Program_Para(void)
{
  INT8U Re;
  INT8U i,Prog_No;//,Count = 0;
  INT16U Len;
  static S_Int8U Sec = {CHK_BYTE, 0xFF, {0}, CHK_BYTE};
  static S_Int8U Min = {CHK_BYTE, 0xFF, {0}, CHK_BYTE};
  
  //Sec.Var = Cur_Time.Time[T_SEC];
  
  Re = CHK_HT(Prog_Status);
  if(Re EQ 0)
    ASSERT_FAILED();
 
  if(Sec.Var != Pub_Timer.Sec) //每秒对实时显示区计时
  {
    TRACE();

    Sec.Var = Pub_Timer.Sec;
	if(Prog_Status.Play_Status.RT_Play_Time > 0) //当前是否处于实时播放状态，是计时，并到时后退出
	{
	  Prog_Status.Play_Status.RT_Play_Time--;
	  if(Prog_Status.Play_Status.RT_Play_Time EQ 0)
	    RT_Play_Status_Exit();
	}
  }
    //return; 
  if(Prog_Status.Play_Status.New_Prog_Flag EQ 0)//--当前在节目播放状态
  {
    TRACE();

    if(GET_VAR(Min) != Cur_Time.Time[T_MIN]) //每分钟+1，当前节目的播放时间
    {
      Min.Var = Cur_Time.Time[T_MIN];
      Prog_Status.Play_Status.Time ++;
      SET_SUM(Prog_Status.Play_Status);
    }
   
    
    //debug("check prog end! counts = %d", Min_Counts);
    if(Check_Prog_End() > 0)//==0表示节目结束
    {
      //读取该节目的存储索引
      Prog_Status.Play_Status.Play_Flag = 0;
      Prog_Status.Play_Status.New_Prog_Flag = NEW_FLAG;
      Prog_Status.Play_Status.Prog_No ++;
      SET_SUM(Prog_Status.Play_Status);

    }
  }

  //if(Prog_Status.Play_Status.Play_Flag EQ 0) //还未进入节目播放状态
  //{
    if(Prog_Status.Play_Status.New_Prog_Flag)//while(1) //寻找下一个可播放的节目
    {
      TRACE();

#if QT_EN
    if(QT_SIM_EN EQ 0)//0表示预览模式
    {
      Prog_Status.Play_Status.Prog_No = Preview_Prog_No;
      SET_SUM(Prog_Status.Play_Status);
    }
#endif

      if(Prog_Status.Play_Status.Prog_No >= Screen_Para.Prog_Num ||\
         Prog_Status.Play_Status.Prog_No >= MAX_PROG_NUM)
      {
        Prog_Status.Play_Status.Prog_No = 0;
        SET_SUM(Prog_Status.Play_Status);
      }

      debug("\r\n-----update new prog %d para-----\r\n", Prog_Status.Play_Status.Prog_No);

      Re = 1;
      Re &=(Prog_Status.Play_Status.Prog_No EQ Prog_Status.Play_Status.Last_Prog_No)?1:0;
      Re &= CHK_HT(Prog_Status.Play_Status);
      Re &= CHK_SUM(Prog_Status.Play_Status);
      Re &= CHK_SUM(Prog_Para);
      Re &= CHK_SUM(Prog_Status.Block_Index);

      //如果上次播放和当次播放的节目是一样的，则不更新节目参数等
      if(Re)//Prog_Status.Play_Status.Play_Flag = 0;
      {
        TRACE();

        debug("same prog, no update");
        for(i = 0; i < MAX_AREA_NUM; i ++)
        {
          Prog_Status.Area_Status[i].Counts = 0;
          SET_SUM(Prog_Status.Area_Status[i]);
        }
            //memset((INT8U *)Prog_Status.Area_Status[i].CS + CS_BYTES, 0, S_OFF(S_Area_Status, Tail) - S_OFF(S_Area_Status, CS) - CS_BYTES);

        Prog_Status.Play_Status.Time = 0;
        Prog_Status.Play_Status.Counts = 0;
        Prog_Status.Play_Status.New_Prog_Flag = 0;
        SET_SUM(Prog_Status.Play_Status);

        //---------------------
        /*
        Prog_No = Prog_Status.Play_Status.Prog_No;
        Prog_Status_Init();//Clr_Prog_Status();换了个新节目，重新设置状态
        Prog_Status.Play_Status.Prog_No = Prog_No;

        INT8U i;

        memset(&Prog_Status, 0, sizeof(Prog_Status));
        SET_HT(Prog_Status);
        for(i = 0; i < MAX_AREA_NUM; i ++)
        {
          SET_HT(Prog_Status.Area_Status[i]);

          Prog_Status.Area_Status[i].Last_File_No = 0x00;
          Prog_Status.Area_Status[i].Last_SCN_No = 0x00;

          SET_SUM(Prog_Status.Area_Status[i]);
        }

        SET_HT(Prog_Status.Play_Status);
        SET_SUM(Prog_Status.Play_Status);

        SET_SUM(Prog_Status.Play_Status);
*/
        //Clr_Show_Data();

        return;
      }
      
      TRACE();

      Prog_Status.Play_Status.Last_Prog_No = 0xFF; //设置为一个不存在的节目号
      //SET_HT(Prog_Status.Play_Status);
      SET_SUM(Prog_Status.Play_Status);

      Len = Read_Prog_Para(Prog_Status.Play_Status.Prog_No, &Prog_Para); //重新更新节目参数
      
      if(Len > 0 && Check_Prog_Play_Time() > 0)
      {
        TRACE();

        Prog_No = Prog_Status.Play_Status.Prog_No;
        Prog_Status_Init();//Clr_Prog_Status();换了个新节目，重新设置状态
        Prog_Status.Play_Status.Prog_No = Prog_No;
        SET_SUM(Prog_Status.Play_Status);

        Len = Read_Prog_Block_Index(Prog_Status.Play_Status.Prog_No);//重新读取节目的存储索引

        if(Len > 0)
        {
          TRACE();

          Clr_Show_Data();

          Prog_Status.Play_Status.Last_Prog_No = Prog_No;
          Prog_Status.Play_Status.New_Prog_Flag = 0;
          //SET_HT(Prog_Status.Play_Status);
          SET_SUM(Prog_Status.Play_Status);

          for(i = 0; i < MAX_AREA_NUM; i ++)
          {
            Prog_Status.Area_Status[i].New_File_Flag = NEW_FLAG;
            Prog_Status.Area_Status[i].File_No = 0;
            Prog_Status.Area_Status[i].SCN_No = 0;

            Prog_Status.Area_Status[i].Last_File_No = 0xFF;
            Prog_Status.Area_Status[i].Last_SCN_No = 0xFFFF;
            SET_SUM(Prog_Status.Area_Status[i]);
          }
        }
      }
      else
      {
        TRACE();

        Prog_Status.Play_Status.New_Prog_Flag = NEW_FLAG;
        Prog_Status.Play_Status.Prog_No ++;
        SET_SUM(Prog_Status.Play_Status);

        ASSERT_FAILED();
        if(Len EQ 0)
          debug("read prog para failed");
        else
          debug("prog %d now not play time", Prog_Status.Play_Status.Prog_No);
      }

      //Prog_Status.Play_Status.Prog_No ++; //在没有读到节目参数的情况下，读取下一个节目的参数
      //最多查询次数不超过Screen_Para.Prog_Num和MAX_PROG_NUM次
      //if(Count > Screen_Para.Prog_Num || Count > MAX_PROG_NUM)
        //break;
    }
  //}
}

#if DATA_PREP_EN >0
//检查是否更新预准备数据
void Check_Update_Data_Prep(void)
{
  INT8U Prog_No,File_Flag;
  INT8U File_No, Prog_End_Flag;
  INT16U SNum,Len;
  INT16U Counts,i,j,X,Y,Width,Height;
  

  if(Prog_Status.Play_Status.New_Prog_Flag)
    return;
  
  //准备每个分区的参数和数据
  for(i =0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {
      if(Screen_Status.Rcv_Flag EQ FRAME_FLAG) //收到一帧，先处理此帧
          return;

    if(Prog_Status.Area_Status[i].New_File_Flag ||\
       Prog_Status.Area_Status[i].New_SCN_Flag)
      return;
    
    //获取下一屏数据
    if(GET_VAR(Prep_Data.Data_Read_Flag[i]) EQ DATA_READ) //需要获取下一屏的参数
    {
      SET_VAR(Prep_Data.Data_Read_Flag[i] , 0);
      SNum = Prog_Status.Area_Status[i].SCN_No + 1; //下一个屏号

      Prog_No = Prog_Status.Play_Status.Prog_No;
      File_No = Prog_Status.Area_Status[i].File_No;
            
      if(SNum >= Prog_Status.File_Para[i].Pic_Para.SNum) //读取下个文件
      {
        SNum = 0;
        File_No ++; 
        if(File_No >= Prog_Para.Area_File_Num[i])
          File_No = 0;

        //重新读取文件参数
        if(GET_VAR(Prep_Data.File_Para_Read_Flag[i]) EQ DATA_READ)
        {
          debug("\r\nprepaid prog %d, area %d,file %d para", Prog_No, i, File_No);
          
          SET_VAR(Prep_Data.File_Para_Read_Flag[i], 0);

          if(GET_VAR(Prep_Data.File_Para_Ok_Flag[i]) != DATA_OK ||\
             GET_VAR(Prep_Data.Para_Prog_No[i]) != Prog_No ||\
             GET_VAR(Prep_Data.Para_File_No[i]) != File_No)
          {
              Len = Read_File_Para(Prog_No, i, File_No, \
                 &Prep_Data.File_Para[i].Pic_Para.Flag, &Prep_Data.File_Para[i], sizeof(Prep_Data.File_Para[i]));

              SET_VAR(Prep_Data.Para_Prog_No[i], Prog_No);
              SET_VAR(Prep_Data.Para_File_No[i] , File_No);
              SET_VAR(Prep_Data.File_Para_Ok_Flag[i], (Len >0)?DATA_OK:DATA_ERR);

              if(Len EQ 0)
                return;

              debug("\r\nprepaid prog %d, area %d, file %d, scn %d data",Prog_No, i, File_No, SNum);

              if(GET_VAR(Prep_Data.Data_Ok_Flag[i]) != DATA_OK ||\
                 GET_VAR(Prep_Data.Data_Prog_No[i]) != Prog_No ||\
                 GET_VAR(Prep_Data.Data_SCN_No[i]) != SNum)
              {
                  Len = Read_Show_Data(i, \
                               File_No, \
                               &Prep_Data.File_Para[i],\
                               SNum,\
                               &Prep_Data.Show_Data,&X,&Y,&Width,&Height);

                  SET_VAR(Prep_Data.Data_Prog_No[i] , Prog_No);
                  SET_VAR(Prep_Data.Data_File_No[i] , File_No);
                  SET_VAR(Prep_Data.Data_SCN_No[i] , SNum);
                  SET_VAR(Prep_Data.Data_X[i] , X);
                  SET_VAR(Prep_Data.Data_Y[i] , Y);
                  SET_VAR(Prep_Data.Data_Width[i] , Width);
                  SET_VAR(Prep_Data.Data_Height[i] , Height);
                  SET_VAR(Prep_Data.Data_Ok_Flag[i] , (Len > 0)?DATA_OK:DATA_ERR);
             }
              return;
          }
        }
      }

      debug("\r\nprepaid prog %d, area %d, file %d, scn %d data",Prog_No, i, File_No, SNum);

      if(GET_VAR(Prep_Data.Data_Ok_Flag[i]) != DATA_OK ||\
         GET_VAR(Prep_Data.Data_Prog_No[i]) != Prog_No ||\
         GET_VAR(Prep_Data.Data_SCN_No[i]) != SNum)
      {
          Len = Read_Show_Data(i, \
                       File_No, \
                       &Prog_Status.File_Para[i],\
                       SNum,\
                       &Prep_Data.Show_Data, &X, &Y, &Width, &Height);

         SET_VAR(Prep_Data.Data_Prog_No[i] , Prog_No);
         SET_VAR(Prep_Data.Data_File_No[i] , File_No);
         SET_VAR(Prep_Data.Data_SCN_No[i] , SNum);
         SET_VAR(Prep_Data.Data_X[i] , X);
         SET_VAR(Prep_Data.Data_Y[i] , Y);
         SET_VAR(Prep_Data.Data_Width[i] , Width);
         SET_VAR(Prep_Data.Data_Height[i] , Height);
         SET_VAR(Prep_Data.Data_Ok_Flag[i] , (Len > 0)?DATA_OK:DATA_ERR);
     }
      
    }
  }  
  
}
#endif

//检查内存中的数据或者参数是否正确
void Check_Show_Data_Para(void)
{
  INT8U i, Re = 1;
  //INT8U Flag;

  Re &= CHK_HT(Screen_Para);
  Re &= CHK_HT(Card_Para);  
  Re &= CHK_HT(Prog_Para);
  Re &= CHK_HT(Prog_Status);
  Re &= CHK_HT(Cur_Block_Index);
  Re &= CHK_HT(Show_Data);
  Re &= CHK_HT(Show_Data_Bak);
  Re &= CHK_HT(Cur_Time);
  if(Re EQ 0)
    ASSERT_FAILED();

  for(i = 0; i < S_NUM(Prog_Status.Area_Status); i ++)
  {
    Re = CHK_HT(Prog_Status.Area_Status[i]);
    if(Re EQ 0)
      ASSERT_FAILED();

    Re = CHK_SUM(Prog_Status.Area_Status[i]);
    if(Re EQ 0)
        ASSERT_FAILED();

    Re = Chk_File_Para_HT_Sum(&Prog_Status.File_Para[i]);
    if(Re EQ 0)
        ASSERT_FAILED();
  }
}

//进入实时显示状态
void RT_Play_Status_Enter(INT16U Sec)
{
  //if(Area_No EQ 0)
  {
    Prog_Status.Play_Status.RT_Play_Flag = RT_PLAY_FLAG;
	Prog_Status.Play_Status.RT_Play_Time = Sec*1000; //ms为单位
    SET_SUM(Prog_Status.Play_Status);
  }/*
  else if(Area_No <= MAX_AREA_NUM)
  {
    Prog_Status.Area_Status[Area_No] = RT_PLAY_FLAG;
	SET_SUM(Screen_Status);
  }
  else
    ASSERT_FAILED();
	*/
}

//退出实时显示状态
void RT_Play_Status_Exit(void)
{
    Prog_Status.Play_Status.RT_Play_Flag = 0;
	Prog_Status.Play_Status.RT_Play_Time = 0;
    SET_SUM(Prog_Status.Play_Status);
}

void Prog_Status_Init(void)
{
    INT8U i;

  memset(&Prog_Status, 0, sizeof(Prog_Status));
  SET_HT(Prog_Status);
  for(i = 0; i < MAX_AREA_NUM; i ++)
  {
      SET_HT(Prog_Status.Area_Status[i]);

      Prog_Status.Area_Status[i].Last_File_No = 0xFF;
      Prog_Status.Area_Status[i].Last_SCN_No = 0xFFFF;

      SET_SUM(Prog_Status.Area_Status[i]);

      Set_File_Para_HT_Sum(&Prog_Status.File_Para[i]);
      if(Chk_File_Para_HT_Sum(&Prog_Status.File_Para[i]) EQ 0)
          ASSERT_FAILED();
  }

  SET_HT(Prog_Status.Play_Status);
  SET_SUM(Prog_Status.Play_Status);
}

//将内存中的变量初始化头尾
void Ram_Init(void)
{
  //INT8U i;

  memset(&Screen_Para, 0, sizeof(Screen_Para));
  //memset(&Card_Para, 0, sizeof(Card_Para));
  memset(&Prog_Para, 0, sizeof(Prog_Para));
  memset(&Screen_Status, 0, sizeof(Screen_Status));
  memset(&Prog_Status, 0, sizeof(Prog_Status));

#if DATA_PREP_EN >0
  memset(&Prep_Data, 0, sizeof(Prep_Data));
#endif  
  memset(&Show_Data, 0, sizeof(Show_Data));
  memset(&Show_Data_Bak, 0, sizeof(Show_Data_Bak));
  memset(&Cur_Block_Index, 0, sizeof(Cur_Block_Index));
  memset(&Cur_Time, 0, sizeof(Cur_Time));

  SET_HT(Screen_Para);
  SET_HT(Card_Para);
  SET_HT(Prog_Para);
  SET_HT(Screen_Status);
#if DATA_PREP_EN >0
  SET_HT(Prep_Data);
#endif  
  SET_HT(Cur_Block_Index);
  SET_HT(Show_Data);
  SET_HT(Show_Data_Bak);
  SET_HT(Cur_Block_Index);
  SET_HT(Cur_Time);

  Prog_Status_Init();

  Prog_Status.Play_Status.New_Prog_Flag = NEW_FLAG;
  Prog_Status.Play_Status.Last_Prog_No = 0xFF;
  SET_HT(Prog_Status.Play_Status);
  SET_SUM(Prog_Status.Play_Status);
}

//显示相关处理
void Show_Main_Proc(void)
{
  Screen_Proc();
  if(Get_Screen_Open_Status() > 0) //当前在开机状态才进入
  {
    Check_Update_Program_Para(); //检查是否需要更新节目
    Check_Update_Show_Data_Bak(); //检查是否需要更新显示备份区数据
#if DATA_PREP_EN >0    
    Check_Update_Data_Prep();
#endif    
    Check_Show_Data_Para();
  }
}

//建立一个实时显示区域,并保存原来的显示参数
void Set_RT_Show_Area(INT16U Width, INT16U Height)
{
//---备份当前参数
  RT_Show_Para.Area_Num = Prog_Para.Area_Num;
  RT_Show_Para.X = Prog_Para.Area[0].X;
  RT_Show_Para.Y = Prog_Para.Area[0].Y;
  RT_Show_Para.X_Len = Prog_Para.Area[0].X_Len;
  RT_Show_Para.Y_Len = Prog_Para.Area[0].Y_Len;	 
  RT_Show_Para.Open_Flag = Screen_Status.Open_Flag;
  RT_Show_Para.Screen_Width = Screen_Para.Base_Para.Width;
  RT_Show_Para.Screen_Height = Screen_Para.Base_Para.Height;
  RT_Show_Para.Screen_Color = Screen_Para.Base_Para.Color;
  SET_HT(RT_Show_Para);

  Prog_Para.Area_Num = 1; //分区数1
  Prog_Para.Area[0].X = 0;
  Prog_Para.Area[0].Y = 0;
  Prog_Para.Area[0].X_Len = Width;//Screen_Para.Base_Para.Width;
  Prog_Para.Area[0].Y_Len = Height;//Screen_Para.Base_Para.Height;
  SET_SUM(Prog_Para);

  Screen_Para.Base_Para.Width = Width;
  Screen_Para.Base_Para.Height = Height;
  Screen_Para.Base_Para.Color = 0x01;
  SET_SUM(Screen_Para);
 
  Screen_Status.Open_Flag = 1;
}

//恢复显示参数
void Restore_Show_Area(void)
{
  Prog_Para.Area_Num =RT_Show_Para.Area_Num; //分区数1
  Prog_Para.Area[0].X = RT_Show_Para.X;
  Prog_Para.Area[0].Y = RT_Show_Para.Y;
  Prog_Para.Area[0].X_Len = RT_Show_Para.X_Len;//Screen_Para.Base_Para.Width;
  Prog_Para.Area[0].Y_Len = RT_Show_Para.Y_Len;//Screen_Para.Base_Para.Height;
  SET_SUM(Prog_Para);

  Screen_Para.Base_Para.Width = RT_Show_Para.Screen_Width;
  Screen_Para.Base_Para.Height = RT_Show_Para.Screen_Height;
  Screen_Para.Base_Para.Color = RT_Show_Para.Screen_Color;
  SET_SUM(Screen_Para);
  Screen_Status.Open_Flag = RT_Show_Para.Open_Flag;
}




 //根据format和ap参数表输出调试信息
 // INT16U LED_Print(INT8U Font, INT8U Color, S_Show_Data *pData, INT8U Area_No, INT16U X, INT16U Y, const INT8S *format,...)

//显示初始化
void Para_Init(void)
{
  Ram_Init();
  Read_Screen_Para();
}

void Para_Show(void)
{
  INT16U Len;
  INT8U IP[4];
  INT32U Baud; //串口波特率

 //显示板卡地址和串口波特率
  Len = RT_LED_Print(FONT0, 0x01, 0, 0, 3, "%d-%d", Screen_Para.COM_Para.Addr, Screen_Para.COM_Para.Baud);

#if UDISK_EN  
  memcpy(IP, &Screen_Para.ETH_Para.IP, 4);	//显示IP地址和端口号
  Len = RT_LED_Print(FONT0, 0x01, Len, 0, 3, "%d.%d.%d.%d:%d", IP[3], IP[2], IP[1], IP[0], Screen_Para.ETH_Para.Port);
#endif

}