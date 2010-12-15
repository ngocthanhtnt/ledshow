#define LED_PARA_C
#include "Includes.h"

//用户参数文件大小配置
const S_File_Para_Info Usr_Para_File_Info[] =
{
  //{C_SCREEN_WH, 0}  0x01
  {C_SCREEN_ADDR, 1 + 11},//0x02
  {C_SCREEN_IP,   4 + 11}, //0x03
  {C_SCREEN_BAUD, 1 + 11}, //0x04
  {C_SCREEN_OC_TIME, 16 + 11},//0x05 //定时开关机时间
  {C_SCREEN_LIGNTNESS, 8 + 11},//0x06 //亮度
  //{C_SCREEN_TIME, 0x07}, //时间
  
};

//工厂参数文件大小配置
const S_File_Para_Info Fac_Para_File_Info[] =
{
  {C_SCREEN_WH, 5 + 11},//0x02
  
};
/*
文件布局：
fac_para.cfg //工厂参数--出厂前设置
屏幕大小
user_para.cfg //用户参数--用户可自己设置
地址
IP地址
波特率
开关机时间
亮度
节目数

prog_property00.cfg //节目0属性
...
prog_propertyAA.cfg //节目N数性

show-00-00-00.dat //文件名意义: show-节目号-分区号-文件号
......
show-AA-BB-CC.dat    

fac_para文件格式:
cmd=01 屏长度与颜色帧

use_para.cfg 文件格式
cmd=0x02 屏地址，可读可写
cmd=0x03 屏IP参数，可读可写
cmd=0x04 通信速率，可读可写
cmd=0x05 定时开关机，可读可写
cmd=0x07 亮度设置，可读可写
cmd=0x08 节目数
prog_property00.cfg 文件格式

*/
/*
//获取节目名字
//获取显示数据文件名
char * Get_Program_Data_File_Name(INT8U Prog_No, INT8U Area_No, char File_Name[])
{
  INT8U i;
  
  strcpy(File_Name, "show-");
  i = 5;
  
  File_Name[i++] = '0' + Prog_No / 10;
  File_Name[i++] = '0' + Prog_No % 10;
  
  File_Name[i++] = '-';
  File_Name[i++] = '0' + Area_No / 10;
  File_Name[i++] = '0' + Area_No % 10;
 
  File_Name[i] = '\0';
  strcat(File_Name, ".dat");
  
  return File_Name;
}

//获取节目数性文件名
char * Get_Program_Property_File_Name(INT8U Prog_No, char File_Name[])
{
  INT8U i;
  
  strcpy(File_Name, "program_property-");
  i = 17;
  
  File_Name[i++] = '0' + Prog_No / 10;
  File_Name[i++] = '0' + Prog_No % 10;
  File_Name[i] = '\0';
  strcat(File_Name, ".pro");
  
  return File_Name;
}

//获取工厂参数文件名
char * Get_Fac_Para_File_Name(char File_Name[])
{
  strcpy(File_Name, "fac_para.cfg");  
  return File_Name;
}

//获取用户参数文件名
char * Get_Usr_Para_File_Name(char File_Name[])
{
  strcpy(File_Name, "usr_para.cfg");
  return File_Name;
}



//从文件中读取一帧
//Offset 偏移
//pDst 目标缓冲区
//返回-1读取出错,无法读到，0表示文件已至结尾，>0读出的帧长
INT32S File_Read_One_Frame(FILE_T File, INT32U Offset, INT8U *pSeq, INT16U *pCtrl, INT8U *pDst, INT8U *pDst_Start, INT16U DstLen)
{
  INT8S Re;
  //INT8U Temp[10];
  INT16U Len;
  
  //读取Offset偏移处的一帧
  Re = File_Read(File, Offset, 4, pDst, pDst_Start, DstLen); //sizeof(Temp), Temp, Temp, sizeof(Temp));
  if(Re <= 0)
    return Re;
  
  //帧头是否正确
  if(!(pDst[0] EQ FRAME_HEAD0 && pDst[1] EQ FRAME_HEAD1))
  {
    ASSERT_FAILED();
    return FILE_FRAME_ERR;
  }
  
  Len = pDst[2] + (INT16U)pDst[3] * 256; //帧长
  Re = File_Read(File, Offset + 4, Len - 4, pDst + 4, pDst_Start, DstLen);
  if(Re <= 0)
    return Re;
  
  if(Check_Frame_Format(pDst, Len) EQ 0)//帧格式是否正确
  {
    ASSERT_FAILED();
    return FILE_FRAME_ERR;
  }
  else
    return Len;
}



//获取某一参数帧在参数文件中的存储位置和偏移以及存储在哪个文件中
INT8U Get_Para_Frame_File_Off_Size(INT16U Ctrl_Code, char File_Name[], INT16U *pOffset, INT16U *pLen)
{
  INT8U i;
  INT16U Off = 0;//Len = 0;
  
  if(Ctrl_Code EQ C_SCREEN_WH) //屏幕宽高
  {
    for(i = 0; i < S_NUM(Fac_Para_File_Info); i ++)
    {
      if(Ctrl_Code EQ Fac_Para_File_Info[i].Ctrl_Code)
      {
        *pOffset = Off;
        *pLen = Fac_Para_File_Info[i].Len;
        Get_Fac_Para_File_Name(File_Name);
        return 1;
      }
      else
        Off += Fac_Para_File_Info[i].Len;
    }
  }
  else //其他参数都存储在用户参数文件
  {
    for(i = 0; i < S_NUM(Usr_Para_File_Info); i ++)
    {
      if(Ctrl_Code EQ Usr_Para_File_Info[i].Ctrl_Code)
      {
        *pOffset = Off;
        *pLen = Usr_Para_File_Info[i].Len;
        Get_Usr_Para_File_Name(File_Name);
        return 1;
      }
      else
        Off += Usr_Para_File_Info[i].Len;
    }    
  }
  
  return 0;
}
*/

INT8U Get_Show_Para_Len(INT8U Type)
{
  if(Type EQ SHOW_PIC)
    return sizeof(S_Pic_Para) - CHK_BYTE_LEN;
  else if(Type EQ SHOW_CLOCK)
    return sizeof(S_Clock_Para) - CHK_BYTE_LEN;
  else if(Type EQ SHOW_TIME)
    return sizeof(S_Time_Para) - CHK_BYTE_LEN;
  else if(Type EQ SHOW_TIMER)
    return sizeof(S_Timer_Para) - CHK_BYTE_LEN;
  else if(Type EQ SHOW_TEMP)
    return sizeof(S_Temp_Para) - CHK_BYTE_LEN;
  else if(Type EQ SHOW_LUN)
    return sizeof(S_Lun_Para) - CHK_BYTE_LEN;
  else
  {
    ASSERT_FAILED();
    return 0;
  }
  
}

//保存参数帧处理
INT8U Save_Para_Frame_Proc(INT8U Frame[], INT16U FrameLen)
{
  //INT8U Prog_No = Prog_Para.Prog_No;
  Write_Storage_Data(SDI_SCREEN_PARA , (INT8U *)&Screen_Para + CHK_HEAD_LEN, SCREEN_PARA_LEN);
  
#ifdef SDI_SCREEN_PARA_BK0 
  Write_Storage_Data(SDI_SCREEN_PARA_BK0, (INT8U *)&Screen_Para + CHK_HEAD_LEN, SCREEN_PARA_LEN);
#endif

#ifdef SDI_SCREEN_PARA_BK1 
  Write_Storage_Data(SDI_SCREEN_PARA_BK1, (INT8U *)&Screen_Para + CHK_HEAD_LEN, SCREEN_PARA_LEN);
#endif  
  
  
#ifdef SDI_SCREEN_PARA_BK2 
  Write_Storage_Data(SDI_SCREEN_PARA_BK2, (INT8U *)&Screen_Para + CHK_HEAD_LEN, SCREEN_PARA_LEN);
#endif 
  
  return 1;
}

//保存节目属性帧
INT8U Save_Prog_Property_Frame_Proc(INT8U Frame[],INT16U FrameLen)
{
  INT8U Prog_No;

  Prog_No = *(Frame + 8); //节目号
  Write_Storage_Data(SDI_PROG_PARA + Prog_No , (INT8U *)&Prog_Para + CHK_HEAD_LEN, PROG_PARA_LEN);
  
#ifdef SDI_PROG_PARA_BK0 
  Write_Storage_Data(SDI_PROG_PARA_BK0 + Prog_No, (INT8U *)&Prog_Para + CHK_HEAD_LEN, PROG_PARA_LEN);
#endif

#ifdef SDI_PROG_PARA_BK1 
  Write_Storage_Data(SDI_PROG_PARA_BK1 + Prog_No, (INT8U *)&Prog_Para + CHK_HEAD_LEN, PROG_PARA_LEN);
#endif  
  
  
#ifdef SDI_PROG_PARA_BK2 
  Write_Storage_Data(SDI_PROG_PARA_BK2 + Prog_No, (INT8U *)&Prog_Para + CHK_HEAD_LEN, PROG_PARA_LEN);
#endif     
 
  return 1;
}

//保存节目数据帧
INT8U Save_Prog_Data_Frame_Proc(INT8U Frame[],INT16U FrameLen)
{
  INT8U Type,Prog_No,Area_No,File_No;
  INT16U Para_Len;
//if(Ctrl_Code EQ C_PROG_DATA) //节目属性
//{
  Type = *(Frame + 8);
  Prog_No = *(Frame + 9); //节目号
  Area_No = *(Frame + 10); //分区号
  File_No = *(Frame + 11); //文件号
  
  if(Prog_No >= MAX_PROG_NUM ||\
    Area_No >= MAX_AREA_NUM)
  {
    ASSERT_FAILED();
    return 0;
  }
    
  Para_Len = Get_Show_Para_Len(Type);
  {
    
  }
    
    
  return 0;

}

//删除节目数据
INT8U Del_Prog_Data(INT8U Frame[], INT16U FrameLen)
{

}




//读取节目参数
//Prog节目号
//返回值1 表示读取成功。0表示没有这个节目或者读取不成功
INT8U Read_Prog_Para(INT8U Prog_No)
{/*
  char File_Name[MAX_FILE_NAME_SIZE];
  FILE_T File;
  INT16U Ctrl, Len;
  INT8U Seq;
  
  Get_Program_Property_File_Name(Prog_No, File_Name);
  File = File_Open(File_Name, FILE_R);
  Len = File_Read_One_Frame(File, 0, &Seq, &Ctrl, (INT8U *)&Prog_Para, (INT8U *)&Prog_Para, sizeof(Prog_Para));
  File_Close(File);
  if(Len > 0)
    return 1;
  else
  {
    ASSERT_FAILED();
    return 0;
  }*/
}

//定时信息中，星期的第0位表示星期1，第6位表示星期六
INT8U Check_Program_Time()
{
  //INT8U i;//Re = 1;
  INT8U Temp[20];
  memset(Temp, 0xFF, sizeof(Temp));
  
  if(Prog_Para.Timing[0].Week != 0xFF)  //按星期定时
  {
    if(GET_BIT(Prog_Para.Timing[0].Week, Cur_Time.Time[T_WEEK]) EQ 0)
      return 0;
  }      
  
  
  //按日期定时
  if(memcmp(Prog_Para.Timing[0].Start_Date, Temp, 3) != 0 &&\
    memcmp(Prog_Para.Timing[0].End_Date, Temp, 3) != 0)
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
  if(memcmp(Prog_Para.Timing[0].Start_Time, Temp, 2) != 0 &&\
    memcmp(Prog_Para.Timing[0].End_Time, Temp, 2) != 0)
  {
    if(!(Cur_Time.Time[T_HOUR] >= Prog_Para.Timing[0].Start_Time[0] &&\
      Cur_Time.Time[T_HOUR] <= Prog_Para.Timing[0].End_Time[0] &&\
        Cur_Time.Time[T_MIN] >= Prog_Para.Timing[0].Start_Time[1] &&\
          Cur_Time.Time[T_MIN] <= Prog_Para.Timing[0].End_Time[1]))
      return 0;
    
  }         
  
  return 1;
}

//读取显示参数--调用Read_Prog_Para
INT8U Update_Prog_Para()
{
  INT8U i;
  
  for(i = 0; i < MAX_PROG_NUM; i ++)
  {
    if(Read_Prog_Para(i)) //读取成功
    {
      if(Check_Program_Time())//当前时间是否为节目播放时间?
        return 1;
    }
  }
  
  return 0;
  
}

//检查是否需要更新节目参数
INT8U Check_Update_Prog_Para()
{
  static S_Int8U Min_Bak = {CHK_BYTE, 0xFF, CHK_BYTE};
  
  if(Min_Bak.Var EQ Cur_Time.Time[T_MIN])
    return 0;
  
  Min_Bak.Var = Cur_Time.Time[T_HOUR];  
  Debug_Print("Min check update program para");
 	
  if(Check_Program_Time() EQ 0) //当前时间是否在节目播放时间中?
  {	
    if(Update_Prog_Para())
    {
      Debug_Print("update program para ok!");
      return 1;
    }
    else
      Debug_Print("no program run");
  }
  
  return 0;
}

//读取参数
void Read_Para()
{/*
  FILE_T File;
  INT16U Ctrl_Code;
  char File_Name[20];
  INT32U Offset = 0;
  INT32S Len = 0;
  INT8U Counts = 0;
  INT8U Seq;
  
  //读取工厂参数
  Get_Fac_Para_File_Name(File_Name); //工厂参数文件名称
  File = File_Open(File_Name, FILE_R); //只读打开
  
  Len = File_Read_One_Frame(File, Offset, &Seq, &Ctrl_Code, Pub_Buf, Pub_Buf, sizeof(Pub_Buf));
  if(Len > 0)
    Para_Frame_Proc(Ctrl_Code, Pub_Buf, Len);
  else
    ASSERT_FAILED();
  
  //读取用户参数
  Get_Usr_Para_File_Name(File_Name); //工厂参数文件名称
  File = File_Open(File_Name, FILE_R); //只读打开
  //每次读一帧，并处理,该文件最多读10帧

  while(1)
  {
    Len = File_Read_One_Frame(File, Offset, &Seq, &Ctrl_Code, Pub_Buf, Pub_Buf, sizeof(Pub_Buf));
    if(Len > 0)
    {
      Counts ++;
      Para_Frame_Proc(Ctrl_Code, Pub_Buf, Len);
    }
    else
    {
      if(Len != FILE_END)
        ASSERT_FAILED();
      break;
    }
  }
  
  //获取节目参数
  Update_Prog_Para();
  */
}
