#define PIC_SHOW_C
#include "Includes.h"

#if PIC_SHOW_EN
//数据移入方式
const S_Mode_Func Mode_Func[]=
{
  {&Move_Left_Continuous},//0
  {&Move_Right_Continuous},//1
  {&Move_Up_Continuous},//2
  {&Move_Down_Continuous},//3
  {&Move_Left},//0
  {&Move_Right},//1
  {&Move_Up},//2
  {&Move_Down},//3
  {&Move_Left_Cover},//4
  {&Move_Right_Cover},//5
  {&Move_Up_Cover},//6
  {&Move_Down_Cover},//7
  {&Move_Left_Up_Cover},//8
  {&Move_Right_Up_Cover},//9
  {&Move_Left_Down_Cover},//10
  {&Move_Right_Down_Cover},//11
  {&Move_Left_Right_Open},//12
  {&Move_Up_Down_Open},//13
  {&Move_Left_Right_Close},//14
  {&Move_Up_Down_Close},//15
  {&Move_Spin_CW},
  {&Move_Spin_CCW}

};

void Update_Pic_Data(INT8U Area_No)
{
  INT8U SNum;
  INT8U In_Mode, Out_Mode;
  INT32U Stay_Time,In_Delay, Out_Delay;
  INT32U Out_Time;
  
  if(Prog_Status.New_Prog_Flag ||\
     Prog_Status.Area_Status[Area_No].New_File_Flag ||\
     Prog_Status.Area_Status[Area_No].New_SCN_Flag) //该节目或该分区还没有进入播放状态?
    return;
  
  Stay_Time = Get_File_Stay_Time(Area_No);
  Out_Time = Get_File_Out_Time(Area_No);
  
  //还在移动状态
  if(Prog_Status.Area_Status[Area_No].Step < 100)
  {
    if(Prog_Status.Area_Status[Area_No].Stay_Time EQ 0)//在进入阶段
    {
        //第一次
      if(Prog_Status.Area_Status[Area_No].Step_Timer EQ 0 &&\
         Prog_Status.Area_Status[Area_No].Step EQ 0)
        {
         Update_XXX_Data(&Show_Data_Bak, Area_No);
      }

      In_Delay = Get_Area_In_Step_Delay(Area_No);
      if(Prog_Status.Area_Status[Area_No].Step_Timer < In_Delay)
        Prog_Status.Area_Status[Area_No].Step_Timer += MOVE_STEP_TIMER;
      else
      {
        Prog_Status.Area_Status[Area_No].Step_Timer = 0;
        In_Mode = Prog_Status.File_Para[Area_No].Pic_Para.In_Mode;
        Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
        (*(Mode_Func[In_Mode].Func))(Area_No);//执行移动操作

      }
    }
    else //在退出阶段
    {
        //刚进入
      if(Prog_Status.Area_Status[Area_No].Step EQ 0 &&\
         Prog_Status.Area_Status[Area_No].Step_Timer EQ 0)
        {
         if(Prog_Status.File_Para[Area_No].Pic_Para.In_Mode >= 4) //前4个是连续移动不清屏
            memset(Show_Data_Bak.Color_Data, 0, sizeof(Show_Data_Bak.Color_Data));
         else
           Prog_Status.Area_Status[Area_No].Step = 100;
       }

      //在移动阶段
      if(Prog_Status.Area_Status[Area_No].Step < 100)
      {
          Out_Delay = Get_Area_Out_Step_Delay(Area_No);
          if(Prog_Status.Area_Status[Area_No].Step_Timer < Out_Delay)
            Prog_Status.Area_Status[Area_No].Step_Timer += MOVE_STEP_TIMER;
          else
          {
            Prog_Status.Area_Status[Area_No].Step_Timer = 0;
            Out_Mode = Prog_Status.File_Para[Area_No].Pic_Para.Out_Mode;
            Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
            (*(Mode_Func[Out_Mode].Func))(Area_No);//执行移动操作
         }
     }

     if(Prog_Status.Area_Status[Area_No].Step >= 100)
     {
        //SNum表示当前文件总的屏幕数，只有图文的屏幕数会大于1！！
        //if(Prog_Status.File_Para[Area_No].Pic_Para.Flag EQ SHOW_PIC)
          //SNum = Prog_Status.File_Para[Area_No].Pic_Para.SNum;
        //else
          //SNum = 1;

        Prog_Status.Area_Status[Area_No].SNum ++;
        Prog_Status.Area_Status[Area_No].New_SCN_Flag = 1;
        Prog_Status.Area_Status[Area_No].Step = 0;
        Prog_Status.Area_Status[Area_No].Step_Timer = 0;
        Prog_Status.Area_Status[Area_No].Stay_Time = 0;
        Prog_Status.Area_Status[Area_No].Out_Time = 0;
        Prog_Status.Area_Status[Area_No].Play_Flag = 0;
    }
   }
  }
  else if(Prog_Status.Area_Status[Area_No].Stay_Time < Stay_Time) //停留时间未到
  {
    if(Prog_Status.Area_Status[Area_No].Stay_Time EQ 0)
    {
      Prog_Status.Area_Status[Area_No].Stay_Time += MOVE_STEP_TIMER;
      Prog_Status.Area_Status[Area_No].SNum = 0; //重新更新背景
      Prog_Status.Area_Status[Area_No].New_SCN_Flag = NEW_FLAG;
      return;
    }

    //if(Prog_Status.Area_Status[Area_No].Stay_Time % 1000 EQ 0)
      //  Update_XXX_Data(&Show_Data, Area_No);

    Prog_Status.Area_Status[Area_No].Stay_Time += MOVE_STEP_TIMER;
    if(Prog_Status.Area_Status[Area_No].Stay_Time >= Stay_Time)//进入退出的移动状态
    {
      Prog_Status.Area_Status[Area_No].Step = 0;
    }
  }
  else
  {
    ASSERT_FAILED(); 
  }

}
#endif

