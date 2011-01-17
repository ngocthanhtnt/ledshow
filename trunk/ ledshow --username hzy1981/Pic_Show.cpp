#define PIC_SHOW_C
#include "Includes.h"

#if PIC_SHOW_EN
//数据移入方式
const S_Mode_Func Mode_Func[]=
{
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

};

void Update_Pic_Data(INT8U Area_No)
{
  INT8U In_Mode, Out_Mode;
  INT32U Stay_Time;
  INT32U Out_Time;
  
  if(Prog_Status.Play_Flag EQ 0 ||\
     Prog_Status.Area_Status[Area_No].Play_Flag EQ 0) //该节目或该分区还没有进入播放状态?
    return;
  
  Stay_Time = Get_File_Stay_Time(Area_No);
  Out_Time = Get_File_Out_Time(Area_No);
  
  //还在移动状态
  if(Prog_Status.Area_Status[Area_No].Step < 100)
  {
    if(Prog_Status.Area_Status[Area_No].Stay_Time EQ 0)
    {
      if(Prog_Status.Area_Status[Area_No].Step_Timer < Get_Area_In_Step_Delay(Area_No))
        Prog_Status.Area_Status[Area_No].Step_Timer += MOVE_STEP_TIMER;
      else
      {
        In_Mode = Prog_Status.File_Para[Area_No].Pic_Para.In_Mode;

        (*(Mode_Func[In_Mode].Func))(Area_No);//执行移动操作
        Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
      }
    }
    else
    {
       if(Prog_Status.Area_Status[Area_No].Step_Timer < Get_Area_Out_Step_Delay(Area_No))
        Prog_Status.Area_Status[Area_No].Step_Timer += MOVE_STEP_TIMER;
      else
      {
        Out_Mode = Prog_Status.File_Para[Area_No].Pic_Para.Out_Mode;

        (*(Mode_Func[Out_Mode].Func))(Area_No);//执行移动操作
        Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;

        if(Prog_Status.Area_Status[Area_No].Step >= 100)
        {
          Prog_Status.Area_Status[Area_No].Step = 0;
          Prog_Status.Area_Status[Area_No].Step_Timer = 0;
          Prog_Status.Area_Status[Area_No].Stay_Time = 0;
          Prog_Status.Area_Status[Area_No].Out_Time = 0;
          Prog_Status.Area_Status[Area_No].Play_Flag = 0;          
        }
      }     
    }
  }
  else if(Prog_Status.Area_Status[Area_No].Stay_Time < Stay_Time) //停留时间未到
  {
    Prog_Status.Area_Status[Area_No].Stay_Time += MOVE_STEP_TIMER;
    if(Prog_Status.Area_Status[Area_No].Stay_Time >= Stay_Time)
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

