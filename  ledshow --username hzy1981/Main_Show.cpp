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

  Step = File_Para[Area_No].Pic_Para.In_Speed; //引入速度
  if(Step >= sizeof(Step_Delay)/sizeof(Step_Delay))
    Step = sizeof(Step_Delay)/sizeof(Step_Delay);

  return Step_Delay[Step];
}

//获取文件的停留时间,单位为ms
//原参数最高为表示单位，0为s，1为ms
INT32U Get_File_Stay_Time(INT8U Area_No)
{
  if((File_Para[Area_No].Pic_Para.Stay_Time & 0x8000) > 0)
    return (INT32U)(File_Para[Area_No].Pic_Para.Stay_Time & 0x7FFF);
  else
    return (INT32U)File_Para[Area_No].Pic_Para.Stay_Time * 1000;
}

//设置文件的停留时间
void Set_File_Stay_Time(INT8U Area_No, INT16U ms)
{
  File_Para[Area_No].Pic_Para.Stay_Time = ms;
  File_Para[Area_No].Pic_Para.Stay_Time = File_Para[Area_No].Pic_Para.Stay_Time | 0x80;
}

//每隔MOVE_STEP_TIMER ms调用该函数,实现移动显示等效果
void Update_Show_Data()
{
  INT8U i;
  //static S_Int8U Ms10_Timer
  for(i = 0; i < Program_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {
    if(File_Para[i].Pic_Para.Flag EQ SHOW_PIC)
      Update_Pic_Data(i);
    else if(File_Para[i].Pic_Para.Flag EQ SHOW_CLOCK)
      Update_Clock_Data(i);
    else if(File_Para[i].Pic_Para.Flag EQ SHOW_TIMER)
      Update_Timer_Data(i);
    else if(File_Para[i].Pic_Para.Flag EQ SHOW_TIME)
      Update_Time_Data(i);
    else if(File_Para[i].Pic_Para.Flag EQ SHOW_TEMP)
      Update_Temp_Data(i);
  }
}

//读取一屏显示数据
//prog节目号
//area分区号
INT8S Update_Show_Data_Bak(INT8U Prog_No, INT8U Area_No)
{
  INT8S Re;
  INT8U Seq;
  char File_Name[MAX_FILE_NAME_SIZE];
  FILE_T File;
  INT16U Ctrl_Code;
  INT32S Len, Len0;
  INT32U Dst_Index, Size;
  INT16U X,Y,X_Len,Y_Len;

  Re = AREA_OK;
  //Read_Para();
  Get_Program_Data_File_Name(Prog_No, Area_No, File_Name); //获取该分区的显示文件

  File = File_Open(File_Name, FILE_R); //Read_

  Len = File_Read_One_Frame(File, Area_Status[Area_No].File_Offset, &Seq, &Ctrl_Code, Pub_Buf, Pub_Buf, sizeof(Pub_Buf));
  if(Len EQ FILE_END) //文件结束--从头开始重新
  {
    Area_Status[Area_No].File_Offset = 0;
    Area_Status[Area_No].File_Type = 0;
    Len = File_Read_One_Frame(File, Area_Status[Area_No].File_Offset, &Seq, &Ctrl_Code, Pub_Buf, Pub_Buf, sizeof(Pub_Buf));
  }

  if(Seq EQ 0)//---必须是第一帧,先将显示相关参数复制到File_Para结构体中
  {
    Area_Status[Area_No].File_Offset += Len;

    if(Len > (sizeof(S_Pic_Para) - 2)) //第一帧
    {
      Len0 = 0;

      Dst_Index = Get_Area_Point_Index(Area_No, 0, 0);
      Size = 0;
      Area_Status[Area_No].File_Type = Pub_Buf[0];

      if(Pub_Buf[0] EQ SHOW_PIC) //图文
      {
        Len0 =  sizeof(File_Para[Area_No].Pic_Para) - 2;
        mem_cpy(&File_Para[Area_No].Pic_Para.Flag, Pub_Buf, Len0, &File_Para[Area_No].Pic_Para, sizeof(File_Para[Area_No].Pic_Para));
        X = 0;
        Y = 0;
        X_Len = Program_Para.Area[Area_No].X_Len;
        Y_Len = Program_Para.Area[Area_No].Y_Len;
      }
      else if(Pub_Buf[0] EQ SHOW_CLOCK)//表盘
      {
        Len0 =  sizeof(File_Para[Area_No].Clock_Para) - 2;
        mem_cpy(&File_Para[Area_No].Clock_Para.Flag, Pub_Buf, Len0, &File_Para[Area_No].Clock_Para, sizeof(File_Para[Area_No].Clock_Para));

        X = File_Para[Area_No].Clock_Para.Text_X;
        Y = File_Para[Area_No].Clock_Para.Text_Y;
        X_Len = File_Para[Area_No].Clock_Para.Text_Width;
        Y_Len = File_Para[Area_No].Clock_Para.Text_Height;
      }
      else if(Pub_Buf[0] EQ SHOW_TIME)//时间
      {
        Len0 =  sizeof(File_Para[Area_No].Time_Para) - 2;
        mem_cpy(&File_Para[Area_No].Time_Para.Flag, Pub_Buf, Len0, &File_Para[Area_No].Time_Para, sizeof(File_Para[Area_No].Time_Para));

        X = File_Para[Area_No].Clock_Para.Text_X;
        Y = File_Para[Area_No].Clock_Para.Text_Y;
        X_Len = File_Para[Area_No].Clock_Para.Text_Width;
        Y_Len = File_Para[Area_No].Clock_Para.Text_Height;
      }
      else if(Pub_Buf[0] EQ SHOW_TIMER)//定时器
      {
        Len0 =  sizeof(File_Para[Area_No].Timer_Para) - 2;
        mem_cpy(&File_Para[Area_No].Timer_Para.Flag, Pub_Buf, Len0, &File_Para[Area_No].Timer_Para, sizeof(File_Para[Area_No].Timer_Para));

        X = File_Para[Area_No].Clock_Para.Text_X;
        Y = File_Para[Area_No].Clock_Para.Text_Y;
        X_Len = File_Para[Area_No].Clock_Para.Text_Width;
        Y_Len = File_Para[Area_No].Clock_Para.Text_Height;
      }
      else if(Pub_Buf[0] EQ SHOW_TEMP)//温度
      {
        Len0 =  sizeof(File_Para[Area_No].Temp_Para) - 2;
        mem_cpy(&File_Para[Area_No].Temp_Para.Flag, Pub_Buf, Len0, &File_Para[Area_No].Temp_Para, sizeof(File_Para[Area_No].Temp_Para));

        X = File_Para[Area_No].Clock_Para.Text_X;
        Y = File_Para[Area_No].Clock_Para.Text_Y;
        X_Len = File_Para[Area_No].Clock_Para.Text_Width;
        Y_Len = File_Para[Area_No].Clock_Para.Text_Height;
      }

      //Bits_Copy(Pub_Buf, sizeof(Pub_Buf), 0, (Len - Len0)* 8, Show_Data.Color_Data + Dst_Index, sizeof(Show_Data.Color_Data), Dst_Index);
      Copy_Buf_2_Area_Rect_0(Pub_Buf, Len - Len0, 0, &Show_Data_Bak, Area_No, X, Y, X_Len, Y_Len);
      Dst_Index += (Len - Len0)*8;
      Size += (Len - Len0);
    }
  }
  else
  {
    ASSERT_FAILED();
    return 0;
  }

  if((Ctrl_Code & 0x10) == 0x10) //有后续帧
  {
    STOP_SHOW_TIMER_INT; //关闭显示中断

    do
    { //继续读下一帧
      Len = File_Read_One_Frame(File, Area_Status[Area_No].File_Offset, &Seq, &Ctrl_Code, Pub_Buf, Pub_Buf, sizeof(Pub_Buf)); //读取一帧

      if(Len > 0) //正常读出一帧
      {
        if((Size + Len) * 8 > Get_Area_Size(Area_No)) //超过了分区的范围！
        {
          ASSERT_FAILED();
          break;
        }

        //位复制
        Copy_Buf_2_Area_Rect_0(Pub_Buf, Len - Len0, Size, &Show_Data_Bak, Area_No, X, Y, X_Len, Y_Len);
        //Bits_Copy(Pub_Buf, sizeof(Pub_Buf), 0, Len * 8, Show_Data.Color_Data + Dst_Index, sizeof(Show_Data.Color_Data), Dst_Index);
        Dst_Index += Len*8;
        Size += Len;
        //修改读文件偏移
        Area_Status[Area_No].File_Offset += Len;

        if((Ctrl_Code & 0x10) != 0x10) //没有后续帧则退出
          break;
      }
      else //读不出一条完整的帧数据了，认为该分区所有数据结束了
      {
        Area_Status[Area_No].File_Offset = 0;
        Re = AREA_END;
        break;
      }
    }while(1); //是同一屏数据,有后续帧表示---一个完整的屏数据用一帧传输，数据太大则拆帧

    START_SHOW_TIMER_INT; //打开显示中断
  }

  File_Close(File); //关闭

  return 1;
}


//检测更新显示备份区数据
INT8S Check_Update_Show_Data_Bak()
{
  INT8U i, Re;
  INT32U Area_End_Flag = 0;
  INT8U All_End_Flag = 1; //有一个分区没有结束则将其置0

  for(i = 0; i < Program_Para.Area_Num && i < MAX_AREA_NUM; i ++)
  {
    //目前显示的步进已经到100%并且目前停留时间已经达到文件的停留时间，则认为该屏已经显示完毕，切换到下屏
    if(Get_File_Stay_Time(i) < MIN_STAY_TIME)
      Set_File_Stay_Time(i, MIN_STAY_TIME);

    //Step>=100表示整个移动过程完成，Stay_Time>=表示停留时间到，则需更新为下一屏数据
    if(Area_Status[i].Step >= 100 && Area_Status[i].Stay_Time >= Get_File_Stay_Time(i))
    {
      Re = Update_Show_Data_Bak(Program_Para.Program_No, i);// == FILE_END)
      if(Re EQ AREA_END) //分区完成
      {
        SET_BIT(Area_End_Flag, i); //第i分区节目播放完成
        if(i + 1 EQ Program_Para.Main_Area_No)
          return PROG_END;
      }
      else
        All_End_Flag = 0; //有一个分区没有结束则清楚该标志
    }
  }

  if(All_End_Flag EQ 1) //所有分区都结束了
    return PROG_END;
  else
    return PROG_OK;
}



//每隔MOVE_STEP_TIMER ms 调用该函数，实现移动效果
void Show_Timer_Proc()
{
  Update_Show_Data(); //更新显示数据

}




//显示相关处理
void Show_Main_Proc()
{
  //Check_Update_Program_Para(); //检查是否需要更新节目
  Check_Update_Show_Data_Bak(); //检查是否需要更新显示备份区数据
  //Check_Update_Show_Data(); //检查是否更新显示区数据

}


