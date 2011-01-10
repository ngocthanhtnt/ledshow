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
INT8U Get_Area_Step_Delay(INT8U Area_No)
{
  INT8U Step;

  if(Area_No >= MAX_AREA_NUM)
  {
    ASSERT_FAILED();
    return Step_Delay[0];
  }

  Step = Prog_Status.File_Para[Area_No].Pic_Para.In_Speed; //引入速度
  
  if(Step >= S_NUM(Step_Delay))
    Step = S_NUM(Step_Delay) - 1;

  return Step_Delay[Step];
}

//获取文件的停留时间,单位为ms
//原参数最高为表示单位，0为s，1为ms
INT32U Get_File_Stay_Time(INT8U Area_No)
{
  if((Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time & 0x8000) > 0)
    return (INT32U)(Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time & 0x7FFF);
  else
    return (INT32U)Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time * 1000;
}

//设置文件的停留时间
void Set_File_Stay_Time(INT8U Area_No, INT16U ms)
{
  Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time = ms;
  Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time = Prog_Status.File_Para[Area_No].Pic_Para.Stay_Time | 0x80;
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
INT8U Update_XXX_Data_Bak(INT8U Area_No)
{
  INT8U Flag; 
  
  Flag = Prog_Status.File_Para[Area_No].Pic_Para.Flag;
  
  //某些非图文数据需要定时刷新!应该保证每分钟进入一次
  if(Flag EQ SHOW_PIC)
    ;
#if CLOCK_SHOW_EN  
  else if(Flag EQ SHOW_CLOCK)
    Update_Clock_Data_Bak(Area_No);
#endif
#if TIME_SHOW_EN  
  else if(Flag EQ SHOW_TIME)
    Update_Time_Data_Bak(Area_No);
#endif
#if TIMER_SHOW_EN  
  else if(Flag EQ SHOW_TIMER)
    Update_Timer_Data_Bak(Area_No);
#endif
#if TEMP_SHOW_EN  
  else if(Flag EQ SHOW_TEMP)
    Update_Temp_Data_Bak(Area_No);
#endif
#if LUN_SHOW_EN  
  else if(Flag EQ SHOW_LUN)
    Update_Lun_Data_Bak(Area_No);
#endif  
  //else if(Flag EQ SHOW_FLASH)
    //Update_Flash_Data_Bak(Area_No);
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

//读取一屏显示数据
//prog节目号
//area分区号
INT8U Update_Show_Data_Bak(INT8U Prog_No, INT8U Area_No)
{
  INT16U Len,SNum;
  INT8U File_No;
  INT8U Counts;
  
  if(Prog_Status.Area_Status[Area_No].SNum EQ 0) //第一屏显示--表示更新到一个新的文件了，必须重读文件参数
  {
    //先将文件参数读出 
    Prog_Status.Area_Status[Area_No].Play_Flag = 0; //关闭本分区显示
    Len = Read_File_Para(Prog_No, Area_No, Prog_Status.Area_Status[Area_No].File_No, \
                   &Prog_Status.File_Para[Area_No].Pic_Para.Flag, \
                   &Prog_Status.File_Para[Area_No], sizeof(U_File_Para)); 
    if(Len EQ 0)
    {
      ASSERT_FAILED();
      
      Prog_Status.Area_Status[Area_No].File_No ++;
      if(Prog_Status.Area_Status[Area_No].File_No >= Prog_Para.Area_File_Num[Area_No] ||\
         Prog_Status.Area_Status[Area_No].File_No >= MAX_FILE_NUM) //所有文件全部都播放了一遍
      {
        Prog_Status.Area_Status[Area_No].File_No = 0;
        Prog_Status.Area_Status[Area_No].Counts++; //所有文件都播放了一次，则将播放次数+1
      } 
      return 0;
    }

  }

  //读出显示数据
  Prog_Status.Area_Status[Area_No].Play_Flag = 0; //--读取显示数据过程中将播放标志置0，从而中断程序中不播放
  Len = Read_Show_Data(Area_No, \
                 Prog_Status.Area_Status[Area_No].File_No, \
                 Prog_Status.File_Para[Area_No].Pic_Para.Flag,\
                 Prog_Status.Area_Status[Area_No].SNum,\
                 &Show_Data_Bak);
  
  Prog_Status.Area_Status[Area_No].SNum ++; //显示屏数增加
  
  if(Len > 0)
    Prog_Status.Area_Status[Area_No].Play_Flag = 1; //打开本分区显示
  else
    ASSERT_FAILED();
  
  //SNum表示当前文件总的屏幕数，只有图文的屏幕数会大于1！！
  if(Prog_Status.File_Para[Area_No].Pic_Para.Flag EQ SHOW_PIC)
    SNum = Prog_Status.File_Para[Area_No].Pic_Para.SNum;
  else
    SNum = 1;
  
  
  //所有分屏都显示了则切换到下个显示文件
  if(Prog_Status.Area_Status[Area_No].SNum >= SNum)
  {
    Prog_Status.Area_Status[Area_No].Play_Flag = 0; //关闭本分区显示
    Prog_Status.Area_Status[Area_No].SNum = 0; 
    
    //文件号
    Prog_Status.Area_Status[Area_No].File_No ++;
    if(Prog_Status.Area_Status[Area_No].File_No >= Prog_Para.Area_File_Num[Area_No] ||\
       Prog_Status.Area_Status[Area_No].File_No >= MAX_FILE_NUM) //所有文件全部都播放了一遍
    {
      Prog_Status.Area_Status[Area_No].File_No = 0;
      Prog_Status.Area_Status[Area_No].Counts++; //所有文件都播放了一次，则将播放次数+1
    }  
  }
  
  
  return AREA_OK;
}


//检测更新显示备份区数据
INT8U Check_Update_Show_Data_Bak()
{
  INT8U i;
  INT32U Stay_Time;
  S_Int8U Sec = {CHK_BYTE, 0xFF, CHK_BYTE};
  
  for(i = 0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {
    Stay_Time = Get_File_Stay_Time(i);
    //目前显示的步进已经到100%并且目前停留时间已经达到文件的停留时间，则认为该屏已经显示完毕，切换到下屏
    if(Stay_Time < MIN_STAY_TIME)
      Set_File_Stay_Time(i, MIN_STAY_TIME);

    //Step>=100表示整个移动过程完成，Stay_Time>=表示停留时间到，则需更新为下一屏数据
    if(Prog_Status.Area_Status[i].Step EQ 0 &&\
       Prog_Status.Area_Status[i].Stay_Time EQ 0)
    {   
      Update_Show_Data_Bak(Prog_Para.Prog_No, i);// == FILE_END)
    }
  }
  
  //每秒更新一下时钟、温度、计时等数据
  if(Sec.Var != Cur_Time.Time[T_SEC])
  {
    Sec.Var = Cur_Time.Time[T_SEC];    
    for(i = 0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
    {    
      Update_XXX_Data_Bak(i);
    }
  }
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
//返回0表示结束了，1表示还没有结束
INT8U Check_Prog_End()
{
  //次数模式
  if(Prog_Para.Mode EQ PROG_COUNTS_MODE)
  {
    if(Prog_Status.Counts >= Prog_Para.Counts)
      return 0;
    else
      return 1;
  }
  else if(Prog_Para.Mode EQ PROG_TIME_MODE)//时间模式
  {
    if(Prog_Status.Time >= Prog_Para.Time)
      return 0;
    else
      return 1;    
  }
  else
  {
    ASSERT_FAILED();
    return 0;
  } 
}

INT8U Check_Prog_Play_Time()
{
 return 1;
}

//每隔MOVE_STEP_TIMER ms 调用该函数，实现移动效果
void Show_Timer_Proc()
{
  Update_Show_Data(); //更新显示数据

}

INT8U Inc_Prog_No(INT8U Prog_No)
{
  return 1;
}

//检查是否需要更新节目参数
void Check_Update_Program_Para()
{
  INT8U Re;
  INT8U i,Prog_No,Count = 0;
  INT16U Len, Min_Counts = 0xFFFF;
  static S_Int8U Sec = {CHK_BYTE, 0xFF, CHK_BYTE};
  static S_Int8U Min = {CHK_BYTE, 0xFF, CHK_BYTE};
  
  if(Sec.Var EQ Cur_Time.Time[T_SEC])
    return;
  
  Sec.Var = Cur_Time.Time[T_SEC];
  
  Re = CHK_HT(Prog_Status);
  if(Re EQ 0)
    ASSERT_FAILED();
  
  if(Prog_Status.Play_Flag EQ 0) //还未进入节目播放状态
  {
    while(1) //寻找下一个可播放的节目
    {
      Count ++;
      
      if(Prog_Status.Prog_No >= Screen_Para.Prog_Num ||\
         Prog_Status.Prog_No >= MAX_PROG_NUM)
        Prog_Status.Prog_No = 0;
  
      Len = Read_Prog_Para(Prog_Status.Prog_No); //重新更新节目参数
      if(Len > 0)
      {   
        Len = Read_Prog_Block_Index(Prog_Status.Prog_No);//重新读取节目的存储索引
        if(Len > 0)
        {       
          Prog_Status.Play_Flag = 1; //进入播放状态！
          break;
        }
      }
      
      Prog_Status.Prog_No ++; //在没有读到节目参数的情况下，读取下一个节目的参数
      //最多查询次数不超过Screen_Para.Prog_Num和MAX_PROG_NUM次
      if(Count > Screen_Para.Prog_Num || Count > MAX_PROG_NUM)
        break;
    } 
  }
  
  if(Prog_Status.Play_Flag > 0)//--当前在节目播放状态
  {
    if(Min.Var != Cur_Time.Time[T_MIN]) //每分钟+1，当前节目的播放时间
    {
      Min.Var = Cur_Time.Time[T_MIN];
      Prog_Status.Time ++;
    }
   
    
    //最小播放次数是节目的播放次数---次数也可采用主分区的播放次数
    Min_Counts = 0xFFFF;
    for(i = 0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
    {
      if(Prog_Status.Area_Status[i].Counts < Min_Counts)
        Min_Counts = Prog_Status.Area_Status[i].Counts;
    }
    
    Prog_Status.Counts = Min_Counts; //在所有分区内的最小播放次数就是节目的总播放次数
    
    if(Check_Prog_End() > 0)//>0表示节目结束
    {
      //读取该节目的存储索引
      Prog_Status.Play_Flag = 0;
      Prog_No = Prog_Status.Prog_No;
      Clr_Prog_Status(); //清除节目状态--进入下个节目
      Prog_Status.Prog_No = Prog_No + 1;

      //节目循环播放
      if(Prog_Status.Prog_No >= Screen_Para.Prog_Num ||\
         Prog_Status.Prog_No >= MAX_PROG_NUM)
        Prog_Status.Prog_No = 0;
    }
  }
}

//检查当前是否在正常播放时段，可能开启了定时开关机
INT8U Check_Screen_Play_Time()
{
  
  
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
    else
      Re = 0;
    
    if(Re EQ 0)
      ASSERT_FAILED();
    
  }
  
}

//将内存中的变量初始化头尾
void Ram_Init()
{
  SET_HT(Screen_Para);  
  SET_HT(Card_Para);
  SET_HT(Prog_Para);
  SET_HT(Prog_Status);
  SET_HT(Cur_Block_Index);
  SET_HT(Show_Data);
  SET_HT(Show_Data_Bak);
  SET_HT(Cur_Time);  
}

//显示相关处理
void Show_Main_Proc()
{
  Screen_Proc();
  if(Get_Screen_Open_Status() > 0) //当前在开机状态才进入
  {
    Check_Update_Program_Para(); //检查是否需要更新节目
    Check_Update_Show_Data_Bak(); //检查是否需要更新显示备份区数据
  }
}


