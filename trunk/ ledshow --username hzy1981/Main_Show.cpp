#define MAIN_SHOW_C
#include "includes.h"


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
  SET_SUM(Prog_Status.File_Para[Area_No].Pic_Para);
}

//每隔MOVE_STEP_TIMER ms调用该函数,实现移动显示等效果
void Update_Show_Data()
{
  INT8U i;

  if(Screen_Status.Open_Flag EQ 0) //当前在关机状态
    return;
  
  for(i = 0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {
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

void Clr_Show_Data()
{
  memset(Show_Data.Color_Data, 0, sizeof(Show_Data.Color_Data));
  memset(Show_Data_Bak.Color_Data, 0, sizeof(Show_Data_Bak.Color_Data));
}

//读取一屏显示数据
//prog节目号
//area分区号
INT8U Update_Show_Data_Bak(INT8U Prog_No, INT8U Area_No)
{
  INT16U Len,SNum;
  INT16S Len0;
  INT16U X,Y,Width,Height;
  //INT8U File_No;
  //INT8U Counts;
  //所有分屏都显示了则切换到下个显示文件
  if(Prog_Status.New_Prog_Flag) //在节目更新状态中，不更新文件参数
      return 0;

  if(Prog_Para.Area_File_Num[Area_No] EQ 0)
      return 0;

  if(Prog_Status.Area_Status[Area_No].New_File_Flag EQ 0 &&\
     Prog_Status.Area_Status[Area_No].New_SCN_Flag EQ 0)
  {
      if(Prog_Status.Area_Status[Area_No].SNum >= Prog_Status.File_Para[Area_No].Pic_Para.SNum)
      {
          Prog_Status.Area_Status[Area_No].New_File_Flag = NEW_FLAG;
          Prog_Status.Area_Status[Area_No].File_No ++;
      }
  }

  //检查是否需要更新到下一文件
  if(Prog_Status.Area_Status[Area_No].New_File_Flag)//SNum > Prog_Status.File_Para[Area_No].Pic_Para.SNum)
  {

    //debug("prog %d area %d file %d play end!", Prog_Status.Prog_No, Area_No, Prog_Status.Area_Status[Area_No].File_No);

    Prog_Status.Area_Status[Area_No].SNum = 0;
    //文件参数读取失败则切换到下个文件

    if(Prog_Status.Area_Status[Area_No].File_No >= Prog_Para.Area_File_Num[Area_No] ||\
       Prog_Status.Area_Status[Area_No].File_No >= MAX_FILE_NUM) //所有文件全部都播放了一遍
    {
      Prog_Status.Area_Status[Area_No].File_No = 0;
      Prog_Status.Area_Status[Area_No].Counts++; //所有文件都播放了一次，则将播放次数+1

      Check_Prog_Play_Counts();
      if(Check_Prog_End() > 0) //节目结束了！
      {
         Prog_Status.New_Prog_Flag = NEW_FLAG;
         Prog_Status.Prog_No ++;
         return 0;
      }
   }

    debug("\r\nprog %d area %d play new file: %d", Prog_No, Area_No, Prog_Status.Area_Status[Area_No].File_No);
    //先将文件参数读出 
    Prog_Status.Area_Status[Area_No].Play_Flag = 0; //关闭本分区显示

    Len = 0;
#if DATA_PREP_EN
    if(Prep_Data.Para_Prog_No[Area_No] EQ Prog_Status.Prog_No &&\
       Prep_Data.Para_File_No[Area_No] EQ Prog_Status.Area_Status[Area_No].File_No &&\
       Prep_Data.File_Para_Ok_Flag[Area_No] EQ DATA_OK)
    {
        memcpy(&Prog_Status.File_Para[Area_No], &Prep_Data.File_Para[Area_No], sizeof(U_File_Para));
        Len = 1;
    }
    else
        Len = Read_File_Para(Prog_No, Area_No, Prog_Status.Area_Status[Area_No].File_No, \
                       &Prog_Status.File_Para[Area_No].Pic_Para.Flag, \
                       &Prog_Status.File_Para[Area_No], sizeof(U_File_Para));

    Prep_Data.File_Para_Read_Flag[Area_No] = DATA_READ;
#else
    Len = Read_File_Para(Prog_No, Area_No, Prog_Status.Area_Status[Area_No].File_No, \
                   &Prog_Status.File_Para[Area_No].Pic_Para.Flag, \
                   &Prog_Status.File_Para[Area_No], sizeof(U_File_Para)); 
#endif

    if(Len EQ 0)
    {
      ASSERT_FAILED();
      Prog_Status.Area_Status[Area_No].New_File_Flag = NEW_FLAG;
      Prog_Status.Area_Status[Area_No].File_No ++;

     // return 0;
    }
    else
    {
      Prog_Status.Area_Status[Area_No].New_File_Flag = 0;
      Prog_Status.Area_Status[Area_No].New_SCN_Flag = NEW_FLAG;
      Prog_Status.Area_Status[Area_No].SNum = 0;
    }
  }

  //更新文件参数过程中不更新分屏数据
  if(Prog_Status.Area_Status[Area_No].New_File_Flag)// EQ 0 &&
    return 0;

  //更新数据到新的一屏
  if(Prog_Status.Area_Status[Area_No].New_SCN_Flag)
  {
      //已经到了最大的一幕则切换到下个文件
      if(Prog_Status.Area_Status[Area_No].SNum >= Prog_Status.File_Para[Area_No].Pic_Para.SNum)
      {
          Prog_Status.Area_Status[Area_No].New_File_Flag = NEW_FLAG;
          Prog_Status.Area_Status[Area_No].File_No ++;
          return 0;
      }

      //读出显示数据
      Prog_Status.Area_Status[Area_No].Play_Flag = 0; //--读取显示数据过程中将播放标志置0，从而中断程序中不播放

      debug("\r\nread prog %d area %d, file %d %dth screen show data", \
            Prog_No, Area_No, Prog_Status.Area_Status[Area_No].File_No,Prog_Status.Area_Status[Area_No].SNum);

      Clear_Area_Data(&Show_Data_Bak, Area_No);

      Len0 = -1;
#if DATA_PREP_EN > 0      
      if(Prep_Data.Data_Prog_No[Area_No] EQ Prog_Status.Prog_No &&\
         Prep_Data.Data_File_No[Area_No] EQ Prog_Status.Area_Status[Area_No].File_No &&\
         Prep_Data.Data_Ok_Flag[Area_No] EQ DATA_OK &&\
         Prep_Data.Data_SNum[Area_No] EQ Prog_Status.Area_Status[Area_No].SNum)
      {

        S_Point P0;
        debug("use prepaid data: area_no:%d, snum:%d", Area_No, Prep_Data.Data_SNum[Area_No]);
        P0.X = Prep_Data.Data_X[Area_No];
        P0.Y = Prep_Data.Data_Y[Area_No];
        Copy_Filled_Rect(&Prep_Data.Show_Data, \
                         Area_No,\
                         &P0,\
                         Prep_Data.Data_Width[Area_No],\
                         Prep_Data.Data_Height[Area_No],\
                         &Show_Data_Bak,\
                         &P0);
        
        Len0 = 1;//GET_TEXT_LEN(Prep_Data.Data_Width[Area_No]
      }
      else
          Len0 = Read_Show_Data(Area_No, \
                         Prog_Status.Area_Status[Area_No].File_No, \
                         &Prog_Status.File_Para[Area_No],\
                         Prog_Status.Area_Status[Area_No].SNum,\
                         &Show_Data_Bak,&X,&Y,&Width,&Height);

      Prep_Data.Data_Read_Flag[Area_No] = DATA_READ;
#else      
      Len0 = Read_Show_Data(Area_No, \
                     Prog_Status.Area_Status[Area_No].File_No, \
                     &Prog_Status.File_Para[Area_No],\ 
                     Prog_Status.Area_Status[Area_No].SNum,\
                     &Show_Data_Bak,&X,&Y,&Width,&Height);
#endif
      if(Len0 >= 0)
      {
        Prog_Status.Area_Status[Area_No].Play_Flag = 1; //打开本分区显示
        Prog_Status.Area_Status[Area_No].New_SCN_Flag = 0;
      }
      else
      {
        //本屏显示数据没有读到则读下屏数据

        ASSERT_FAILED();
        Prog_Status.Area_Status[Area_No].New_SCN_Flag = NEW_FLAG;
        Prog_Status.Area_Status[Area_No].SNum ++; //显示屏数增加
      }
  }


//-----------------
  return AREA_OK;
}


//检测更新显示备份区数据
INT8U Check_Update_Show_Data_Bak()
{
  INT8U i;
  INT32U Stay_Time;
  S_Int8U Sec = {CHK_BYTE, 0xFF, CHK_BYTE};
  
  //if(Prog_Status.Play_Flag EQ 0)
      //return 0;

  for(i = 0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {
      /*
    Stay_Time = Get_File_Stay_Time(i);
    //目前显示的步进已经到100%并且目前停留时间已经达到文件的停留时间，则认为该屏已经显示完毕，切换到下屏
    if(Stay_Time < MIN_STAY_TIME)
      Set_File_Stay_Time(i, MIN_STAY_TIME);
*/
    //Step>=100表示整个移动过程完成，Stay_Time>=表示停留时间到，则需更新为下一屏数据
    /*
      if(Prog_Status.Area_Status[i].Play_Flag EQ 0 &&\
       Prog_Status.Area_Status[i].Step EQ 0 &&\
       Prog_Status.Area_Status[i].Stay_Time EQ 0)
    */
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

void Check_Update_Show_Data()
{
  
}

void Clr_Prog_Status()
{
  memset(&Prog_Status, 0, sizeof(Prog_Status));
  SET_HT(Prog_Status);
  
}

//检查节目是否播放结束
//返回1表示结束了，0表示还没有结束
INT8U Check_Prog_End()
{
  if(Check_Prog_Play_Time() EQ 0)
  {
     debug("prog %d now not play time, end", Prog_Status.Prog_No);
     return 1;
  }
  //次数模式
  if(Prog_Para.Mode EQ PROG_COUNTS_MODE)
  {
    if(Prog_Status.Counts >= Prog_Para.Counts)
    {
      debug("prog %d play counts %d, end", Prog_Status.Prog_No, Prog_Status.Counts);      
      return 1;
    }
    else
      return 0;
  }
  else if(Prog_Para.Mode EQ PROG_TIME_MODE)//时间模式
  {
    if(Prog_Status.Time >= Prog_Para.Time)
    {
      debug("prog %d play times %d, end", Prog_Status.Prog_No, Prog_Status.Time);      
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
INT8U Check_Prog_Play_Time()
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
void Show_Timer_Proc()
{
  Update_Show_Data(); //更新显示数据

}

INT8U Inc_Prog_No(INT8U Prog_No)
{
  return 1;
}

void Check_Prog_Play_Counts()
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

    Prog_Status.Counts = Min_Counts; //在所有分区内的最小播放次数就是节目的总播放次数

}
//检查是否需要更新节目参数
void Check_Update_Program_Para()
{
  INT8U Re;
  INT8U i,Prog_No,Count = 0;
  INT16U Len;
  static S_Int8U Sec = {CHK_BYTE, 0xFF, CHK_BYTE};
  static S_Int8U Min = {CHK_BYTE, 0xFF, CHK_BYTE};
  
  //if(Sec.Var EQ Cur_Time.Time[T_SEC])
    //return;
  
  //Sec.Var = Cur_Time.Time[T_SEC];
  
  Re = CHK_HT(Prog_Status);
  if(Re EQ 0)
    ASSERT_FAILED();
  
  if(Prog_Status.New_Prog_Flag EQ 0)//--当前在节目播放状态
  {
    if(Min.Var != Cur_Time.Time[T_MIN]) //每分钟+1，当前节目的播放时间
    {
      Min.Var = Cur_Time.Time[T_MIN];
      Prog_Status.Time ++;
    }
   
    
    //debug("check prog end! counts = %d", Min_Counts);
    if(Check_Prog_End() > 0)//==0表示节目结束
    {
      //读取该节目的存储索引
      Prog_Status.Play_Flag = 0;
      Prog_No = Prog_Status.Prog_No;

      Prog_Status.New_Prog_Flag = NEW_FLAG;
      Clr_Prog_Status(); //清除节目状态--进入下个节目

      Prog_Status.Prog_No = Prog_No ++;

    }
  }

  //if(Prog_Status.Play_Flag EQ 0) //还未进入节目播放状态
  //{
    if(Prog_Status.New_Prog_Flag)//while(1) //寻找下一个可播放的节目
    {

      //Prog_Status.Play_Flag = 0;

      //
      if(Prog_Status.Prog_No >= Screen_Para.Prog_Num ||\
         Prog_Status.Prog_No >= MAX_PROG_NUM)
        Prog_Status.Prog_No = 0;
#if QT_EN
      Prog_Status.Prog_No = Preview_Prog_No;
#endif

      debug("\r\n-----update new prog %d para-----\r\n", Prog_Status.Prog_No);

      Len = Read_Prog_Para(Prog_Status.Prog_No, &Prog_Para); //重新更新节目参数
      
      if(Len > 0 && Check_Prog_Play_Time() > 0)
      {
        Prog_No = Prog_Status.Prog_No;
        Clr_Prog_Status();
        Prog_Status.Prog_No = Prog_No;
        
        Len = Read_Prog_Block_Index(Prog_Status.Prog_No);//重新读取节目的存储索引
        
        if(Len > 0)
        {
          Clr_Show_Data();

          Prog_Status.New_Prog_Flag = 0;

          for(i = 0; i < MAX_AREA_NUM; i ++)
          {
            Prog_Status.Area_Status[i].New_File_Flag = NEW_FLAG;
            Prog_Status.Area_Status[i].File_No = 0;

          }
        }
      }
      else
      {
        Prog_Status.New_Prog_Flag = NEW_FLAG;
        Prog_Status.Prog_No ++;

        ASSERT_FAILED();
        if(Len EQ 0)
          debug("read prog para failed");
        else
          debug("prog %d now not play time", Prog_Status.Prog_No);
      }

      //Prog_Status.Prog_No ++; //在没有读到节目参数的情况下，读取下一个节目的参数
      //最多查询次数不超过Screen_Para.Prog_Num和MAX_PROG_NUM次
      //if(Count > Screen_Para.Prog_Num || Count > MAX_PROG_NUM)
        //break;
    }
  //}
}

//检查是否更新预准备数据
void Check_Update_Data_Prep()
{
  INT8U Prog_No,File_Flag;
  INT8U File_No, Prog_End_Flag;
  INT16U SNum,Len;
  INT16U Counts,i,j,X,Y,Width,Height;
  

  if(Prog_Status.New_Prog_Flag)
    return;
  
  //准备每个分区的参数和数据
  for(i =0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {
    if(Prog_Status.Area_Status[i].New_File_Flag ||\
       Prog_Status.Area_Status[i].New_SCN_Flag)
      return;
    
    //获取下一屏数据
    if(Prep_Data.Data_Read_Flag[i] EQ DATA_READ) //需要获取下一屏的参数
    {
      Prep_Data.Data_Read_Flag[i] = 0;
      SNum = Prog_Status.Area_Status[i].SNum + 1; //下一个屏号

      Prog_No = Prog_Status.Prog_No;
      File_No = Prog_Status.Area_Status[i].File_No;
            
      if(SNum >= Prog_Status.File_Para[i].Pic_Para.SNum) //读取下个文件
      {
        SNum = 0;
        File_No ++; 
        if(File_No >= Prog_Para.Area_File_Num[i])
          File_No = 0;

        //重新读取文件参数
        if(Prep_Data.File_Para_Read_Flag[i] EQ DATA_READ)
        {
          debug("\r\nprepaid prog %d, area %d,file %d para", Prog_No, i, File_No);
          
          Prep_Data.File_Para_Read_Flag[i] = 0;

          if(Prep_Data.File_Para_Ok_Flag[i] != DATA_OK ||\
             Prep_Data.Para_Prog_No[i] != Prog_No ||\
             Prep_Data.Para_File_No[i] != File_No)
          {
              Len = Read_File_Para(Prog_No, i, File_No, \
                 &Prep_Data.File_Para[i].Pic_Para.Flag, &Prep_Data.File_Para[i], sizeof(Prep_Data.File_Para[i]));

              Prep_Data.Para_Prog_No[i] = Prog_No;
              Prep_Data.Para_File_No[i] = File_No;
              Prep_Data.File_Para_Ok_Flag[i] = (Len >0)?DATA_OK:DATA_ERR;

              if(Len EQ 0)
                return;

              debug("\r\nprepaid prog %d, area %d, file %d, scn %d data",Prog_No, i, File_No, SNum);

              if(Prep_Data.Data_Ok_Flag[i] != DATA_OK ||\
                 Prep_Data.Data_Prog_No[i] != Prog_No ||\
                 Prep_Data.Data_SNum[i] != SNum)
              {
                  Len = Read_Show_Data(i, \
                               File_No, \
                               &Prep_Data.File_Para[i],\
                               SNum,\
                               &Prep_Data.Show_Data,&X,&Y,&Width,&Height);

                  Prep_Data.Data_Prog_No[i] = Prog_No;
                  Prep_Data.Data_File_No[i] = File_No;
                  Prep_Data.Data_SNum[i] = SNum;
                  Prep_Data.Data_X[i] = X;
                  Prep_Data.Data_Y[i] = Y;
                  Prep_Data.Data_Width[i] = Width;
                  Prep_Data.Data_Height[i] = Height;
                  Prep_Data.Data_Ok_Flag[i] = (Len > 0)?DATA_OK:DATA_ERR;
             }
              return;
          }
        }
      }

      debug("\r\nprepaid prog %d, file %d, area %d, scn %d data",Prog_No, i, File_No, SNum);

      if(Prep_Data.Data_Ok_Flag[i] != DATA_OK ||\
         Prep_Data.Data_Prog_No[i] != Prog_No ||\
         Prep_Data.Data_SNum[i] != SNum)
      {
          Len = Read_Show_Data(i, \
                       File_No, \
                       &Prog_Status.File_Para[i],\
                       SNum,\
                       &Prep_Data.Show_Data, &X, &Y, &Width, &Height);

         Prep_Data.Data_Prog_No[i] = Prog_No;
         Prep_Data.Data_File_No[i] = File_No;
         Prep_Data.Data_SNum[i] = SNum;
         Prep_Data.Data_X[i] = X;
         Prep_Data.Data_Y[i] = Y;
         Prep_Data.Data_Width[i] = Width;
         Prep_Data.Data_Height[i] = Height;
         Prep_Data.Data_Ok_Flag[i] = (Len > 0)?DATA_OK:DATA_ERR;
     }
      
    }
  }  
  
}

//检查内存中的数据或者参数是否正确
void Check_Show_Data_Para()
{
  INT8U i, Re = 1;
  INT8U Flag;

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
  
  Re = 1;
  for(i = 0; i < S_NUM(Prog_Status.Area_Status); i ++)
  {
    Re &= CHK_HT(Prog_Status.Area_Status[i]);
    if(Re EQ 0)
      ASSERT_FAILED();
    
    Flag = Prog_Status.File_Para[i].Pic_Para.Flag;
    if(Flag EQ SHOW_NULL)
      ;
    else if(Flag EQ SHOW_PIC)
      Re &= CHK_HT(Prog_Status.File_Para[i].Pic_Para);
#if CLOCK_SHOW_EN    
    else if(Flag EQ SHOW_CLOCK)
      Re &= CHK_HT(Prog_Status.File_Para[i].Clock_Para);
#endif
#if TIME_SHOW_EN    
    else if(Flag EQ SHOW_TIME)
      Re &= CHK_HT(Prog_Status.File_Para[i].Time_Para);
#endif
#if TIMER_SHOW_EN    
    else if(Flag EQ SHOW_TIMER)
      Re &= CHK_HT(Prog_Status.File_Para[i].Timer_Para);
#endif
#if TEMP_SHOW_EN    
    else if(Flag EQ SHOW_TEMP)
      Re &= CHK_HT(Prog_Status.File_Para[i].Temp_Para);
#endif
#if LUN_SHOW_EN    
    else if(Flag EQ SHOW_LUN)
      Re &= CHK_HT(Prog_Status.File_Para[i].Lun_Para);
#endif
#if HUMIDITY_SHOW_EN
    else if(Flag EQ SHOW_HUMIDITY)
      Re &= CHK_HT(Prog_Status.File_Para[i].Humidity_Para);
#endif
#if NOISE_SHOW_EN
    else if(Flag EQ SHOW_NOISE)
      Re &= CHK_HT(Prog_Status.File_Para[i].Noise_Para);
#endif
    else
      Re = 0;
    
    if(Re EQ 0)
      ASSERT_FAILED();
    
  }
  
}

//将内存中的变量初始化头尾
void Ram_Init()
{
  memset(&Screen_Para, 0, sizeof(Screen_Para));
  //memset(&Card_Para, 0, sizeof(Card_Para));
  memset(&Prog_Para, 0, sizeof(Prog_Para));
  memset(&Screen_Status, 0, sizeof(Screen_Status));
  memset(&Prog_Status, 0, sizeof(Prog_Status));
  memset(&Prep_Data, 0, sizeof(Prep_Data));
  memset(&Show_Data, 0, sizeof(Show_Data));
  memset(&Show_Data_Bak, 0, sizeof(Show_Data_Bak));
  memset(&Cur_Block_Index, 0, sizeof(Cur_Block_Index));
  memset(&Cur_Time, 0, sizeof(Cur_Time));

  SET_HT(Screen_Para);  
  //SET_HT(Card_Para);
  SET_HT(Prog_Para);
  SET_HT(Screen_Status);
  SET_HT(Prog_Status);
  SET_HT(Prep_Data);
  SET_HT(Cur_Block_Index);
  SET_HT(Show_Data);
  SET_HT(Show_Data_Bak);
  SET_HT(Cur_Block_Index);
  SET_HT(Cur_Time);

  Prog_Status.New_Prog_Flag = NEW_FLAG;
}

//显示相关处理
void Show_Main_Proc()
{
  Screen_Proc();
  if(Get_Screen_Open_Status() > 0) //当前在开机状态才进入
  {
    Check_Update_Program_Para(); //检查是否需要更新节目
    Check_Update_Show_Data_Bak(); //检查是否需要更新显示备份区数据
    Check_Update_Data_Prep();
  }
}

//显示初始化
void Show_Init()
{
  Ram_Init();
  Read_Screen_Para();
}
