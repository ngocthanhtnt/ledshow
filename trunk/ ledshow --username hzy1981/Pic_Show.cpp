#define PIC_SHOW_C
#include "Includes.h"

#if PIC_SHOW_EN
//�������뷽ʽ
const S_Mode_Func In_Mode_Func[]=
{
  {&Move_Show_RightNow},
  {&Move_Left_Continuous},//0
  //{&Move_Right_Continuous},//1
  {&Move_Up_Continuous},//2
  //{&Move_Down_Continuous},//3
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

//�������뷽ʽ
const S_Mode_Func Out_Mode_Func[]=
{
  {&Move_Show_RightNow},
  //{&Move_Left_Continuous},//0
  //{&Move_Right_Continuous},//1
  //{&Move_Up_Continuous},//2
  //{&Move_Down_Continuous},//3
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

INT8U Check_XXX_Data(INT8U Area_No)
{
    INT8U Flag;

    Flag = Prog_Status.File_Para[Area_No].Pic_Para.Flag;
  if(Flag EQ SHOW_CLOCK ||\
     Flag EQ SHOW_TIME ||\
     Flag EQ SHOW_TIMER ||\
     Flag EQ SHOW_TEMP ||\
     Flag EQ SHOW_LUN)
      return 1;
  else
      return 0;
}

void Update_Pic_Data(INT8U Area_No)
{
  INT8U SNum;
  INT8U In_Mode, Out_Mode;
  INT16U Area_Width, Area_Height;
  INT32U Stay_Time,In_Delay, Out_Delay;
  INT32U Out_Time;
  S_Point P0;
  
  if(Prog_Status.New_Prog_Flag ||\
     Prog_Status.Area_Status[Area_No].New_File_Flag ||\
     Prog_Status.Area_Status[Area_No].New_SCN_Flag) //�ý�Ŀ��÷�����û�н��벥��״̬?
    return;
  
  Stay_Time = Get_File_Stay_Time(Area_No);
  Out_Time = Get_File_Out_Time(Area_No);
  
  //�����ƶ�״̬
  if(Prog_Status.Area_Status[Area_No].Step < 100)
  {
    if(Prog_Status.Area_Status[Area_No].Stay_Time EQ 0)//�ڽ���׶�
    {
      In_Delay = Get_Area_In_Step_Delay(Area_No);
        //��һ��
      if(Prog_Status.Area_Status[Area_No].Step_Timer EQ 0 &&\
         Prog_Status.Area_Status[Area_No].Step EQ 0)
        {
          Prog_Status.Area_Status[Area_No].Step_Timer = In_Delay;///---������һ��ֱ����ʾ��һ�εĲ���Ч��

          //---------
          In_Mode = Prog_Status.File_Para[Area_No].Pic_Para.In_Mode;
          if(In_Mode EQ 0) //���
              In_Mode = Cur_Time.Time[T_SEC] % S_NUM(In_Mode_Func);
          else
              In_Mode = In_Mode - 1;

          Prog_Status.Area_Status[Area_No].In_Mode = In_Mode;
          //---------

          if(Check_XXX_Data(Area_No))
            Update_XXX_Data(&Show_Data_Bak, Area_No);
      }


      if(Prog_Status.Area_Status[Area_No].Step_Timer < In_Delay)
        Prog_Status.Area_Status[Area_No].Step_Timer += MOVE_STEP_TIMER;

      if(Prog_Status.Area_Status[Area_No].Step_Timer >= In_Delay)
      {
        Prog_Status.Area_Status[Area_No].Step_Timer = 0;
        Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;

        In_Mode = Prog_Status.Area_Status[Area_No].In_Mode;

        if(In_Mode >= S_NUM(In_Mode_Func))
        {
            In_Mode = 0;
            ASSERT_FAILED();
        }

        (*(In_Mode_Func[In_Mode].Func))(Area_No);//ִ���ƶ�����

        if(In_Mode EQ 0) //������ʾ
          Prog_Status.Area_Status[Area_No].Step = 100;

        //����׶�����ﵽ100%ͬʱͣ��ʱ��Ϊ0��ֱ�������˳��׶�
        if(Prog_Status.Area_Status[Area_No].Step >= 100)
        {
          if(Stay_Time EQ 0) //����׶����꣬���ͣ��ʱ����0��ֱ�ӽ����˳��׶�!
          {
            Prog_Status.Area_Status[Area_No].Stay_Time = 1;
            Prog_Status.Area_Status[Area_No].Step = 0;
            Prog_Status.Area_Status[Area_No].Step_Timer = 0;
           }

        }
      }
    }
    //else
    if(Prog_Status.Area_Status[Area_No].Stay_Time > 0)//���˳��׶�
    {
      Out_Delay = Get_Area_Out_Step_Delay(Area_No);
        //�ս���
      if(Prog_Status.Area_Status[Area_No].Step EQ 0 &&\
         Prog_Status.Area_Status[Area_No].Step_Timer EQ 0)
        {
         Prog_Status.Area_Status[Area_No].Step_Timer = Out_Delay;

         //------------
         Out_Mode = Prog_Status.File_Para[Area_No].Pic_Para.Out_Mode;
         if(Out_Mode EQ 0) //���
           Out_Mode = Cur_Time.Time[T_SEC] % S_NUM(Out_Mode_Func);
         else if(Out_Mode >= 2)
           Out_Mode = Out_Mode - 2;

         Prog_Status.Area_Status[Area_No].Out_Mode = Out_Mode;
         //-------------------------

         if(Prog_Status.Area_Status[Area_No].In_Mode != 1 &&\
            Prog_Status.Area_Status[Area_No].In_Mode != 2) //ǰ4���������ƶ�������
            memset(Show_Data_Bak.Color_Data, 0, sizeof(Show_Data_Bak.Color_Data));
         else
           Prog_Status.Area_Status[Area_No].Step = 100;
       }

      //���ƶ��׶�
      if(Prog_Status.Area_Status[Area_No].Step < 100)
      {
          if(Prog_Status.Area_Status[Area_No].Step_Timer < Out_Delay)
            Prog_Status.Area_Status[Area_No].Step_Timer += MOVE_STEP_TIMER;

          if(Prog_Status.Area_Status[Area_No].Step_Timer >= Out_Delay)
          {
            Prog_Status.Area_Status[Area_No].Step_Timer = 0;
            Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;

            //---------
            Out_Mode = Prog_Status.Area_Status[Area_No].Out_Mode;
            if(Out_Mode EQ 1) //������
            {
               Prog_Status.Area_Status[Area_No].Step = 100;
            }
            else
            {
              if(Out_Mode >= S_NUM(Out_Mode_Func))
              {
                Out_Mode = 0;
                ASSERT_FAILED();
              }

              //---------
              (*(Out_Mode_Func[Out_Mode].Func))(Area_No);//ִ���ƶ�����

              if(Out_Mode EQ 0) //������ʾ
                Prog_Status.Area_Status[Area_No].Step = 100;
           }
         }
     }

     if(Prog_Status.Area_Status[Area_No].Step >= 100)
     {
        //SNum��ʾ��ǰ�ļ��ܵ���Ļ����ֻ��ͼ�ĵ���Ļ�������1����
        //if(Prog_Status.File_Para[Area_No].Pic_Para.Flag EQ SHOW_PIC)
          //SNum = Prog_Status.File_Para[Area_No].Pic_Para.SNum;
        //else
          //SNum = 1;

        Prog_Status.Area_Status[Area_No].New_SCN_Flag = 1;
        Prog_Status.Area_Status[Area_No].SNum ++;
        Prog_Status.Area_Status[Area_No].Step = 0;
        Prog_Status.Area_Status[Area_No].Step_Timer = 0;
        Prog_Status.Area_Status[Area_No].Stay_Time = 0;
        Prog_Status.Area_Status[Area_No].Out_Time = 0;
        Prog_Status.Area_Status[Area_No].Play_Flag = 0;
    }
   }
  }
  else if(Prog_Status.Area_Status[Area_No].Stay_Time < Stay_Time) //ͣ��ʱ��δ��
  {
    if(Check_XXX_Data(Area_No))
    {
        if(Prog_Status.Area_Status[Area_No].Stay_Time EQ 0)
        {
          Prog_Status.Area_Status[Area_No].Stay_Time += MOVE_STEP_TIMER;
          Prog_Status.Area_Status[Area_No].New_SCN_Flag = NEW_FLAG;
          Prog_Status.Area_Status[Area_No].SNum = 0; //���¸��±���
          return;
        }

        if(Prog_Status.Area_Status[Area_No].Stay_Time EQ MOVE_STEP_TIMER ||\
           Prog_Status.Area_Status[Area_No].Stay_Time % 500 EQ 0)
        {
          //Clear_Area_Data(&Show_Data, Area_No);
          P0.X = P0.Y = 0;
          Area_Width = Get_Area_Width(Area_No);
          Area_Height = Get_Area_Height(Area_No);
          Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Area_Width, Area_Height, &Show_Data, &P0);
          Update_XXX_Data(&Show_Data, Area_No);
        }
    }

    Prog_Status.Area_Status[Area_No].Stay_Time += MOVE_STEP_TIMER;
    if(Prog_Status.Area_Status[Area_No].Stay_Time >= Stay_Time)//�����˳����ƶ�״̬
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
