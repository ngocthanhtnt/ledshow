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

  for(i = 0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {
    if(Prog_Status.File_Para[i].Pic_Para.Flag EQ SHOW_PIC)
      Update_Pic_Data(i);
    else if(Prog_Status.File_Para[i].Pic_Para.Flag EQ SHOW_CLOCK)
      Update_Clock_Data(i);
    else if(Prog_Status.File_Para[i].Pic_Para.Flag EQ SHOW_TIMER)
      Update_Timer_Data(i);
    else if(Prog_Status.File_Para[i].Pic_Para.Flag EQ SHOW_TIME)
      Update_Time_Data(i);
    else if(Prog_Status.File_Para[i].Pic_Para.Flag EQ SHOW_TEMP)
      Update_Temp_Data(i);
    else if(Prog_Status.File_Para[i].Pic_Para.Flag EQ SHOW_LUN)
      Update_Lun_Data(i);
  }
  Update_Border_Data(MAX_AREA_NUM); //更新边框数据
}

//读取一屏显示数据
//prog节目号
//area分区号
INT8U Update_Show_Data_Bak(INT8U Prog_No, INT8U Area_No)
{
  INT16U Len,SNum;
  
  if(Prog_Status.Area_Status[Area_No].SNum EQ 0) //第一屏显示--表示更新到一个新的文件了，必须重读文件参数
  {
    //先将文件参数读出
    Prog_Status.Area_Status[Area_No].File_No ++;
   
    //文件号
    if(Prog_Status.Area_Status[Area_No].File_No >= Prog_Para.Area_File_Num[Area_No]) //所有文件全部都播放了一遍
    {
      Prog_Status.Area_Status[Area_No].File_No = 0;
      Prog_Status.Area_Status[Area_No].Counts++; //所有文件都播放了一次，则将播放次数+1
    }
    
    Len = Read_File_Para(Prog_No, Area_No, Prog_Status.Area_Status[Area_No].File_No, \
                   &Prog_Status.File_Para[Area_No].Pic_Para.Flag, \
                   &Prog_Status.File_Para[Area_No], sizeof(U_File_Para)); 
    if(Len EQ 0)
    {
      ASSERT_FAILED();
      return AREA_END;
    }
  }

  Len = Read_Show_Data(Area_No, \
                 Prog_Status.Area_Status[Area_No].File_No, \
                 Prog_Status.File_Para[Area_No].Pic_Para.Flag,\
                 Prog_Status.Area_Status[Area_No].SNum,\
                 &Show_Data_Bak);

  if(Len EQ 0)
    ASSERT_FAILED();
  
  Prog_Status.Area_Status[Area_No].SNum ++; //显示屏数增加
  
  //SNum表示当前文件总的屏幕数，只有图文的屏幕数会大于1！！
  if(Prog_Status.File_Para[Area_No].Pic_Para.Flag EQ SHOW_PIC)
    SNum = Prog_Status.File_Para[Area_No].Pic_Para.SNum;
  else
    SNum = 1;
  
  if(Prog_Status.Area_Status[Area_No].SNum >= SNum)
    Prog_Status.Area_Status[Area_No].SNum = 0;

    
  return AREA_OK;
}


//检测更新显示备份区数据
INT8U Check_Update_Show_Data_Bak()
{
  INT8U i;
  INT32U Stay_Time;
  
  for(i = 0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {
    Stay_Time = Get_File_Stay_Time(i);
    //目前显示的步进已经到100%并且目前停留时间已经达到文件的停留时间，则认为该屏已经显示完毕，切换到下屏
    if(Stay_Time < MIN_STAY_TIME)
      Set_File_Stay_Time(i, MIN_STAY_TIME);

    //Step>=100表示整个移动过程完成，Stay_Time>=表示停留时间到，则需更新为下一屏数据
    if(Prog_Status.Area_Status[i].Step >= 100 &&\
       Prog_Status.Area_Status[i].Stay_Time >= Stay_Time)
    {
      Update_Show_Data_Bak(Prog_Para.Prog_No, i);// == FILE_END)

    }
  }
  return 1;
}

void Clr_Prog_Status()
{
  memset(&Prog_Status, 0, sizeof(Prog_Status));
  SET_HT(Prog_Status);
  
}

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
  else if(Prog_Para.Mode EQ PROG_TIME_MODE)
  {
    if(Prog_Status.Time >= Prog_Para.Time)
      return 0;
    else
      return 1;    
  }
  else
  {
    if(Prog_Status.Counts >= 1)
      return 0;
    else
      return 1;   
  } 
}

INT8U Check_Prog_Play_Time()
{
  
}

//每隔MOVE_STEP_TIMER ms 调用该函数，实现移动效果
void Show_Timer_Proc()
{
  Update_Show_Data(); //更新显示数据

}


void Check_Update_Program_Para()
{
  INT8U Re;
  INT8U i,Count = 0;
  INT16U Len, Min_Counts = 0xFFFF;
  static S_Int8U Sec = {CHK_BYTE, 0xFF, CHK_BYTE};
  static S_Int8U Min = {CHK_BYTE, 0xFF, CHK_BYTE};
  
  if(Sec.Var EQ Cur_Time.Time[T_SEC])
    return;
  
  Sec.Var = Cur_Time.Time[T_SEC];
  
  Re = CHK_HT(Prog_Status);
  if(Re EQ 0)
    ASSERT_FAILED();
  
  if(Prog_Status.Play_Flag EQ 0) //第一次播放该节目，则读取节目参数
  {
    while(1) //寻找下一个可播放的节目
    {
      Prog_Status.Prog_No ++;
      Count ++;
      
      if(Prog_Status.Prog_No >= Screen_Para.Prog_Num || Prog_Status.Prog_No >= MAX_PROG_NUM)
        Prog_Status.Prog_No = 0;
  
      Len = Read_Prog_Para(Prog_Status.Prog_No); //重新更新节目参数
      if(Len > 0 && Check_Prog_Play_Time() > 0)
      {
        //读取该节目的存储索引
        Clr_Prog_Status(); //清除节目状态
        Read_Prog_Block_Index(Prog_Status.Prog_No);//重新读取节目的存储索引
        break;
      }
      
      //最多查询次数不超过Screen_Para.Prog_Num和MAX_PROG_NUM次
      if(Count > Screen_Para.Prog_Num || Count > MAX_PROG_NUM)
        break;
    } 
  }
  
  Prog_Status.Play_Flag = 1; //进入节目播放状态
  
  if(Min.Var != Cur_Time.Time[T_MIN]) //每分钟+1，当前节目的播放时间
  {
    Min.Var = Cur_Time.Time[T_MIN];
    Prog_Status.Time ++;
  }
 
  
  //最小播放次数是节目的播放次数---次数也可采用主分区的播放次数
  for(i = 0; i < Prog_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {
    if(Prog_Status.Area_Status[i].Counts < Min_Counts)
      Min_Counts = Prog_Status.Area_Status[i].Counts;
  }
  
  Prog_Status.Counts = Min_Counts; //在所有分区内的最小播放次数就是节目的总播放次数
  
  
  if(Check_Prog_End() > 0)//>0表示节目结束
  {
    Prog_Status.Time = 0;
    Prog_Status.Counts = 0;
    Prog_Status.Play_Flag = 0; //--当前节目播放完毕
  }
}


//显示相关处理
void Show_Main_Proc()
{
  Check_Update_Program_Para(); //检查是否需要更新节目
  Check_Update_Show_Data_Bak(); //检查是否需要更新显示备份区数据
}


