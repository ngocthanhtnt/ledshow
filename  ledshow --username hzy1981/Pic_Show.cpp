#define PIC_SHOW_C
#include "Includes.h"

#if PIC_SHOW_EN
//�������뷽ʽ
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
  INT32U Stay_Time;
  INT32U Out_Time;
  
  if(Prog_Status.Play_Flag EQ 0 ||\
     Prog_Status.Area_Status[Area_No].Play_Flag EQ 0) //�ý�Ŀ��÷�����û�н��벥��״̬?
    return;
  
  Stay_Time = Get_File_Stay_Time(Area_No);
  Out_Time = Get_File_Out_Time(Area_No);
  
  //�����ƶ�״̬
  if(Prog_Status.Area_Status[Area_No].Step < 100)
  {
    if(Prog_Status.Area_Status[Area_No].Stay_Time EQ 0)//�ڽ���׶�
    {
        //��һ��
      if(Prog_Status.Area_Status[Area_No].Step_Timer EQ 0 &&\
         Prog_Status.Area_Status[Area_No].Step EQ 0)
        {
         Update_XXX_Data_Bak(Area_No);
      }

      if(Prog_Status.Area_Status[Area_No].Step_Timer < Get_Area_In_Step_Delay(Area_No))
        Prog_Status.Area_Status[Area_No].Step_Timer += MOVE_STEP_TIMER;
      else
      {
        Prog_Status.Area_Status[Area_No].Step_Timer = 0;
        In_Mode = Prog_Status.File_Para[Area_No].Pic_Para.In_Mode;
        Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
        (*(Mode_Func[In_Mode].Func))(Area_No);//ִ���ƶ�����

      }
    }
    else //���˳��׶�
    {
        //�ս���
      if(Prog_Status.Area_Status[Area_No].Step EQ 0 &&\
         Prog_Status.Area_Status[Area_No].Step_Timer EQ 0)
        {
         if(Prog_Status.File_Para[Area_No].Pic_Para.In_Mode >= 4) //ǰ4���������ƶ�������
            memset(Show_Data_Bak.Color_Data, 0, sizeof(Show_Data_Bak.Color_Data));
         else
           Prog_Status.Area_Status[Area_No].Step = 100;
       }

      //���ƶ��׶�
      if(Prog_Status.Area_Status[Area_No].Step < 100)
      {
          if(Prog_Status.Area_Status[Area_No].Step_Timer < Get_Area_Out_Step_Delay(Area_No))
            Prog_Status.Area_Status[Area_No].Step_Timer += MOVE_STEP_TIMER;
          else
          {
            Prog_Status.Area_Status[Area_No].Step_Timer = 0;
            Out_Mode = Prog_Status.File_Para[Area_No].Pic_Para.Out_Mode;
            Prog_Status.Area_Status[Area_No].Step += MOVE_STEP;
            (*(Mode_Func[Out_Mode].Func))(Area_No);//ִ���ƶ�����
         }
     }

     if(Prog_Status.Area_Status[Area_No].Step >= 100)
     {
        //SNum��ʾ��ǰ�ļ��ܵ���Ļ����ֻ��ͼ�ĵ���Ļ�������1����
        //if(Prog_Status.File_Para[Area_No].Pic_Para.Flag EQ SHOW_PIC)
          SNum = Prog_Status.File_Para[Area_No].Pic_Para.SNum;
        //else
          //SNum = 1;

        Prog_Status.Area_Status[Area_No].SNum ++;
        //���з�������ʾ�����л����¸���ʾ�ļ�
        if(Prog_Status.Area_Status[Area_No].SNum >= SNum)
        {
          debug("prog %d area %d file %d play end!", Prog_Status.Prog_No, Area_No, Prog_Status.Area_Status[Area_No].File_No);

          //Prog_Status.Area_Status[Area_No].Play_Flag = 0; //�رձ�������ʾ
          Prog_Status.Area_Status[Area_No].SNum = 0;

          //�ļ���
          Prog_Status.Area_Status[Area_No].File_No ++;
          if(Prog_Status.Area_Status[Area_No].File_No >= Prog_Para.Area_File_Num[Area_No] ||\
             Prog_Status.Area_Status[Area_No].File_No >= MAX_FILE_NUM) //�����ļ�ȫ����������һ��
          {
            Prog_Status.Area_Status[Area_No].File_No = 0;
            Prog_Status.Area_Status[Area_No].Counts++; //�����ļ���������һ�Σ��򽫲��Ŵ���+1
          }
        }

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
    if(Prog_Status.Area_Status[Area_No].Stay_Time % 1000 EQ 0)
        Update_XXX_Data_Bak(Area_No);

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
