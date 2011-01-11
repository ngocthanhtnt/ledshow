#define COM_C
#include "Includes.h"
/*
1	0x5A	帧头低字节
2	0xA5	帧头高字节
3	Len0	帧长度低字节(从帧头到帧尾)
4	Len1	帧长度高字节
5	Addr	地址,0-255，0为广播地址(广播地址帧不应答)
6	Seq	帧序号, 0-255 循环计数,重发的数据序号不变
7	Cmd0	命令码低字节
8	Cmd1	命令码高字节
9	…	帧数据域内容
	…	
	CS0	校验码低字节,从帧头到CS0前一个字节的和
	CS1	校验码高字节
	0xAA	帧尾
*/
const INT16U Frame_Data_Size[]=
{
  0,
  5,
  1,
  4,
  1,
  20,
  8,
  7	
};

//

INT8U Check_Frame_Format(INT8U Frame[], INT16U Frame_Len)
{
  INT16U Len;
  INT16U Sum;
  
  if(Frame[0] != FRAME_HEAD) //头正确
  {
    ASSERT_FAILED();
    return 0;
  }
  
  Len = Frame[1] + (INT16U)Frame[2] * 256; //帧长

  if(Len!= Frame_Len || Frame[Len - 1] != FRAME_TAIL) //尾正确
  {
    ASSERT_FAILED();
    return 0;
  }
  
  Sum = Sum_2Bytes(Frame, Len - 3); //后3个字节是校验和和帧尾
  if(memcmp((INT8U *)&Sum, Frame + Len - 3, 2) EQ 0)
    return 1;
  else
  {
    ASSERT_FAILED();
     return 0;
  }  
  
}

//从帧中读取工厂参数和用户参数到变量中
//Ctrl控制码
//Frame数据域起始
//Len数据域长度
INT8U Para_Frame_Proc(INT16U Ctrl, INT8U Data[], INT16U Len)
{
  //INT16U Ctrl;
  //INT16U Len;
  
  //Ctrl = Frame[6] + (INT16U)Frame[7] * 256;
  //Len = FrameLen - 11;
  
  if(Ctrl EQ C_SCREEN_WH && Len >= Frame_Data_Size[Ctrl])
    mem_cpy((INT8U *)&Screen_Para.Base_Para.Width, Data, Frame_Data_Size[Ctrl], (INT8U *)&Screen_Para, sizeof(Screen_Para)); //屏幕参数
  else if(Ctrl EQ C_SCREEN_ADDR && Len >= Frame_Data_Size[Ctrl])
    mem_cpy((INT8U *)&Screen_Para.Base_Para.Addr, Data, Frame_Data_Size[Ctrl], (INT8U *)&Screen_Para, sizeof(Screen_Para)); //屏幕地址
  else if(Ctrl EQ C_SCREEN_IP && Len >= Frame_Data_Size[Ctrl])
    mem_cpy((INT8U *)&Screen_Para.Base_Para.IP, Data, Frame_Data_Size[Ctrl], (INT8U *)&Screen_Para, sizeof(Screen_Para)); //IP地址
  else if(Ctrl EQ C_SCREEN_BAUD && Len >= Frame_Data_Size[Ctrl])
    mem_cpy((INT8U *)&Screen_Para.Base_Para.Baud, Data, Frame_Data_Size[Ctrl], (INT8U *)&Screen_Para, sizeof(Screen_Para)); //通信波特率
  else if(Ctrl EQ C_SCREEN_OC_TIME && Len >= Frame_Data_Size[Ctrl]) 	
    mem_cpy((INT8U *)&Screen_Para.Open_Close_Time, Data, Frame_Data_Size[Ctrl], (INT8U *)&Screen_Para, sizeof(Screen_Para)); //定时开关机时间
  else if(Ctrl EQ C_SCREEN_LIGNTNESS && Len >= Frame_Data_Size[Ctrl])
    mem_cpy((INT8U *)&Screen_Para.Lightness, Data, Frame_Data_Size[Ctrl], (INT8U *)&Screen_Para, sizeof(Screen_Para)); //亮度参数
  else if(Ctrl EQ C_SCREEN_TIME && Len >= Frame_Data_Size[Ctrl])
    ;//mem_cpy((INT8U *)&Screen_Para.Open_Close_Time, Frame, Frame_Data_Size[Ctrl], (INT8U *)&Screen_Para, sizeof(Screen_Para)); //定时开关机时间
  else
  {
    ASSERT_FAILED();
    return 0;
  }	
  return 1;
}

//对收到的一帧的处理
void Rcv_Frame_Proc(INT8U Frame[], INT16U FrameLen)
{
  INT16U Ctrl_Code;
  S_Time TempTime;
  INT8U Re;
  
  Re = 1;
  Ctrl_Code = Frame[6] + (INT16U)Frame[7] * 256;
  if(Ctrl_Code EQ C_SCREEN_WH ||\
      Ctrl_Code EQ C_SCREEN_ADDR ||\
      Ctrl_Code EQ C_SCREEN_IP  ||\
      Ctrl_Code EQ C_SCREEN_BAUD ||\
      Ctrl_Code EQ C_SCREEN_OC_TIME ||\
      Ctrl_Code EQ C_SCREEN_LIGNTNESS)
  {
    Re &= Para_Frame_Proc(Ctrl_Code, Frame + 8, FrameLen - 11); //更新内存中的参数
    Re &= Save_Para_Frame_Proc(Frame, FrameLen); //保存参数
  }
  else if(Ctrl_Code EQ C_PROG_PARA)//保存节目属性帧
  {
    Re &= Save_Prog_Property_Frame_Proc(Frame, FrameLen); 
  }
  else if(Ctrl_Code EQ C_PROG_DATA) //显示数据 
  {
    Re &= Save_Show_Data_Frame_Proc(Frame, FrameLen); //保存节目显示数据
  }
  else if(Ctrl_Code EQ C_SCREEN_TIME) //设置时间
  {
    mem_cpy(TempTime.Time, Frame + 8, 7, TempTime.Time, sizeof(TempTime.Time));
    Re &= Set_Cur_Time(TempTime.Time);
  }
}
