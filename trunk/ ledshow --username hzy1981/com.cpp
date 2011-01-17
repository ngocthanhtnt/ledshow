#define COM_C
#include "Includes.h"
/*
0	0x5A	帧头
1	Len0	帧长度低字节(从帧头到帧尾)
2	Len1	帧长度高字节
3	Addr0	地址低字节
4       Addr1   地址高字节
5	Seq	帧序号, 0-255 循环计数,重发的数据序号不变
6       Seq00   帧内序号低字节
7       Seq01   帧内序号高字节
8	Cmd0	命令码低字节
9	Cmd1	命令码高字节
A	…	帧数据域内容
	…	
	CS0	校验码低字节,从帧头到CS0前一个字节的和
	CS1	校验码高字节
	0xAA	帧尾
*/

/*
#define FHEAD  0x00 //帧头,1
#define FLEN   0x01 //帧长度,1
#define FADDR  0x03 //帧地址,2
#define FSEQ   0x05 //帧序号,1
#define FSEQ0  0x06 //帧内序号,2
#define FCMD   0x08 //命令码,2
#define FDATA  0x0A //数据域名
*/
INT8U Check_Frame_Format(INT8U Frame[], INT16U Frame_Len)
{
  INT16U Len;
  INT16U Sum;
  
  if(Frame[FHEAD] != FRAME_HEAD) //头正确
  {
    ASSERT_FAILED();
    return 0;
  }
  
  Len = Frame[FLEN] + (INT16U)Frame[FLEN + 1] * 256; //帧长

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
//Cmd控制码
//Frame数据域起始
//Len数据域长度
INT8U Screen_Para_Frame_Proc(INT16U Cmd, INT8U Data[], INT16U Len)
{
  //INT16U Cmd;
  //INT16U Len;
  
  //Cmd = Frame[6] + (INT16U)Frame[7] * 256;
  //Len = FrameLen - 11;
  
  if(Cmd EQ C_SCREEN_WH && Len >= sizeof(Screen_Para.Base_Para.Width))
    mem_cpy((INT8U *)&Screen_Para.Base_Para.Width, Data, sizeof(Screen_Para.Base_Para.Width), (INT8U *)&Screen_Para, sizeof(Screen_Para)); //屏幕参数
  else if(Cmd EQ C_SCREEN_ADDR && Len >= sizeof(Screen_Para.Base_Para.Addr))
    mem_cpy((INT8U *)&Screen_Para.Base_Para.Addr, Data, sizeof(Screen_Para.Base_Para.Addr), (INT8U *)&Screen_Para, sizeof(Screen_Para)); //屏幕地址
  else if(Cmd EQ C_SCREEN_IP && Len >= sizeof(Screen_Para.Base_Para.IP))
    mem_cpy((INT8U *)&Screen_Para.Base_Para.IP, Data, sizeof(Screen_Para.Base_Para.IP), (INT8U *)&Screen_Para, sizeof(Screen_Para)); //IP地址
  else if(Cmd EQ C_SCREEN_BAUD && Len >= sizeof(Screen_Para.Base_Para.Baud))
    mem_cpy((INT8U *)&Screen_Para.Base_Para.Baud, Data, sizeof(Screen_Para.Base_Para.Baud), (INT8U *)&Screen_Para, sizeof(Screen_Para)); //通信波特率
  else if(Cmd EQ C_SCREEN_OC_TIME && Len >= sizeof(Screen_Para.OC_Time))
    mem_cpy((INT8U *)&Screen_Para.OC_Time, Data, sizeof(Screen_Para.OC_Time), (INT8U *)&Screen_Para, sizeof(Screen_Para)); //定时开关机时间
  else if(Cmd EQ C_SCREEN_LIGNTNESS && Len >= sizeof(Screen_Para.Lightness))
    mem_cpy((INT8U *)&Screen_Para.Lightness, Data, sizeof(Screen_Para.Lightness), (INT8U *)&Screen_Para, sizeof(Screen_Para)); //亮度参数
  else if(Cmd EQ C_SCREEN_TIME && Len >= sizeof(Cur_Time.Time))
    ;//mem_cpy((INT8U *)&Screen_Para.Open_Close_Time, Frame, Frame_Data_Size[Cmd], (INT8U *)&Screen_Para, sizeof(Screen_Para)); //定时开关机时间
  else if(Cmd EQ C_SCREEN_BASE_PARA && Len >= sizeof(Screen_Para.Base_Para))
    mem_cpy((INT8U *)&Screen_Para.Base_Para, Data, sizeof(Screen_Para.Base_Para), (INT8U *)&Screen_Para, sizeof(Screen_Para));
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
  INT16U Cmd_Code;
  S_Time TempTime;
  INT8U Re;
  
  if(Check_Frame_Format(Frame, FrameLen) EQ 0)
  {
      ASSERT_FAILED();
      return;
  }

  Re = 1;
  Cmd_Code = Frame[FCMD];// + (INT16U)Frame[FCMD + 1] * 256;
  if(Cmd_Code EQ C_SCREEN_WH ||\
      Cmd_Code EQ C_SCREEN_ADDR ||\
      Cmd_Code EQ C_SCREEN_IP  ||\
      Cmd_Code EQ C_SCREEN_BAUD ||\
      Cmd_Code EQ C_SCREEN_OC_TIME ||\
      Cmd_Code EQ C_SCREEN_LIGNTNESS ||\
      Cmd_Code EQ C_SCREEN_BASE_PARA)
  {
    Re &= Screen_Para_Frame_Proc(Cmd_Code, Frame + FDATA, FrameLen - F_NDATA_LEN); //更新内存中的参数
    Re &= Save_Screen_Para_Frame_Proc(Frame, FrameLen); //保存参数
  }
  else if(Cmd_Code EQ C_PROG_PARA)//保存节目属性帧
  {
    Re &= Save_Prog_Para_Frame_Proc(Frame, FrameLen);
  }
  else if(Cmd_Code EQ C_PROG_DATA) //显示数据
  {
     Re &= Save_Prog_Data_Frame_Proc(Frame, FrameLen); //保存节目显示数据
  }
  else if(Cmd_Code EQ C_SCREEN_TIME) //设置时间
  {
    mem_cpy(TempTime.Time, Frame + FDATA, sizeof(TempTime.Time), TempTime.Time, sizeof(TempTime.Time));
    Re &= Set_Cur_Time(TempTime.Time);
  }
}
