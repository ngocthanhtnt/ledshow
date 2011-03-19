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

INT16U Make_Frame(INT8U *pData, INT16U Len, INT8U Addr[], INT8U Cmd, INT8U Cmd0, INT8U Seq, INT16U Seq0, char *pDst)
{
  pDst[0] = FRAME_HEAD;//帧头
  memcpy(pDst + FADDR, Addr, 2); //地址
  memcpy(pDst + FDATA, pData, Len);

  pDst[FSEQ] = Seq;
  memcpy(pDst + FSEQ0, &Seq0, sizeof(Seq0));

  pDst[FCMD] = Cmd; //两个字节的控制码
  pDst[FCMD + 1] = Cmd0;

  Len += F_NDATA_LEN; //数据域 + 非数据域 = 整个帧长
  memcpy(pDst + FLEN, &Len, 2);

  INT16U sum = Sum_2Bytes((INT8U *)pDst, Len - 3); //后3个字节是校验和和帧尾
  memcpy((char *)pDst + Len - 3, (char *)&sum, 2);
  pDst[Len - 1] = FRAME_TAIL;

  return Len;
}


//从帧中读取工厂参数和用户参数到变量中
//Cmd控制码
//Frame数据域起始
//Len数据域长度
INT8U Screen_Para_Frame_Proc(INT16U Cmd, INT8U Data[], INT16U Len)
{
  if(Cmd EQ C_SCREEN_BASE_PARA && Len >= sizeof(Screen_Para.Base_Para))
  {
    if(memcmp((INT8U *)&Screen_Para.Base_Para, Data, sizeof(Screen_Para.Base_Para)) != 0)
      {
      Set_Screen_Replay_Flag(); //重播节目标志
      Screen_Para.Prog_Num = 0; //重置节目数
    }
    mem_cpy((INT8U *)&Screen_Para.Base_Para, Data, sizeof(Screen_Para.Base_Para), (INT8U *)&Screen_Para, sizeof(Screen_Para));//基本参数
  }
  else if(Cmd EQ C_SCREEN_COM_PARA && Len >= sizeof(Screen_Para.COM_Para))
    mem_cpy((INT8U *)&Screen_Para.COM_Para, Data, sizeof(Screen_Para.COM_Para), (INT8U *)&Screen_Para, sizeof(Screen_Para));//通信参数
  else if(Cmd EQ C_SCREEN_OC_TIME && Len >= sizeof(Screen_Para.OC_Time))
    mem_cpy((INT8U *)&Screen_Para.OC_Time, Data, sizeof(Screen_Para.OC_Time), (INT8U *)&Screen_Para, sizeof(Screen_Para)); //定时开关机时间
  else if(Cmd EQ C_SCREEN_LIGNTNESS && Len >= sizeof(Screen_Para.Lightness))
    mem_cpy((INT8U *)&Screen_Para.Lightness, Data, sizeof(Screen_Para.Lightness), (INT8U *)&Screen_Para, sizeof(Screen_Para)); //亮度参数
  else if(Cmd EQ C_PROG_NUM && Len>=sizeof(Screen_Para.Prog_Num))
  {
    if(memcmp((INT8U *)&Screen_Para.Prog_Num, Data, sizeof(Screen_Para.Prog_Num)!=0))
      Set_Screen_Replay_Flag(); //重播节目标志
    mem_cpy((INT8U *)&Screen_Para.Prog_Num, Data, sizeof(Screen_Para.Prog_Num), (INT8U *)&Screen_Para, sizeof(Screen_Para));
  }
  else
  {
    ASSERT_FAILED();
    return 0;
  }

  SET_SUM(Screen_Para);
  Write_Screen_Para(); //保存屏幕参数
  return 1;
}

//对收到的一帧的处理
INT8U Rcv_Frame_Proc(INT8U Frame[], INT16U FrameLen)
{
  INT16U Cmd_Code;
  S_Time TempTime;
  INT8U Re;

  Set_Screen_Com_Time(5); //到计时5s，5秒后重新播放节目

  Re = 1;
  Cmd_Code = Frame[FCMD];// + (INT16U)Frame[FCMD + 1] * 256;
  if(Cmd_Code EQ  C_SCREEN_COM_PARA ||\
      Cmd_Code EQ C_SCREEN_OC_TIME ||\
      Cmd_Code EQ C_SCREEN_LIGNTNESS ||\
      Cmd_Code EQ C_SCREEN_BASE_PARA ||\
      Cmd_Code EQ C_PROG_NUM)
  {
    Re &= Screen_Para_Frame_Proc(Cmd_Code, Frame + FDATA, FrameLen - F_NDATA_LEN); //更新内存中的参数
    //Re &= Write_Screen_Para();//Save_Screen_Para_Frame_Proc(Frame, FrameLen); //保存参数
  }
  else if(Cmd_Code EQ C_PROG_PARA)//保存节目属性帧
  {
    Re &= Save_Prog_Para_Frame_Proc(Frame, FrameLen);
    Set_Screen_Replay_Flag(); //重播节目标志
  }
  else if(Cmd_Code EQ C_PROG_DATA) //显示数据
  {
     Re &= Save_Prog_Data_Frame_Proc(Frame, FrameLen); //保存节目显示数据
     Set_Screen_Replay_Flag(); //重播节目标志
  }
  else if(Cmd_Code EQ C_SCREEN_TIME) //设置时间
  {
    mem_cpy(TempTime.Time, Frame + FDATA, sizeof(TempTime.Time), TempTime.Time, sizeof(TempTime.Time));
    Re &= Set_Cur_Time(TempTime.Time);
  }

  return Re;
}

//收到一个字节,中断中调用该函数
void Rcv_One_Byte(INT8U Byte)
{
  INT16U i;

  if(Screen_Status.Rcv_Flag EQ FRAME_FLAG) //当前已有一帧，停止继续接收，待该帧处理完
      return;

  if(Screen_Status.Rcv_Posi < sizeof(Screen_Status.Rcv_Data))
    {
      Screen_Status.Rcv_Data[Screen_Status.Rcv_Posi] = Byte;
      Screen_Status.Rcv_Posi++;
  }
  else
  {
      Screen_Status.Rcv_Data[0] = Byte;
      Screen_Status.Rcv_Posi = 0;
  }

  if(Byte EQ FRAME_TAIL) //收到帧尾字符
  {
      for(i = 0; i < Screen_Status.Rcv_Posi; i ++)
      {
          if(Screen_Status.Rcv_Data[i] EQ FRAME_HEAD && \
             Check_Frame_Format(Screen_Status.Rcv_Data + i, Screen_Status.Rcv_Posi - i))
          {
             if(i != 0) //将数据复制到开始
                 memcpy(Screen_Status.Rcv_Data, Screen_Status.Rcv_Data + i, Screen_Status.Rcv_Posi - i);
             Screen_Status.Rcv_Flag = FRAME_FLAG;
             return;
          }
      }
  }
}

void Screen_Com_Proc()
{
    static S_Int32U Sec = {CHK_BYTE, 0xFFFFFFFF, CHK_BYTE};
   INT8U Re;

   if(Screen_Status.Rcv_Flag EQ FRAME_FLAG)
    {
     Re = Rcv_Frame_Proc(Screen_Status.Rcv_Data, Screen_Status.Rcv_Posi);

     Screen_Status.Rcv_Posi = 0;
     Screen_Status.Rcv_Flag = 0;

   }

   //收到最后一帧后的倒计时
   if(Screen_Status.Com_Time > 0)
   {
      if(Sec.Var != SEC_TIMER)
       {
        Sec.Var = SEC_TIMER;

        Screen_Status.Com_Time--;
        //SET_SUM(Screen_Status);

        if(Screen_Status.Com_Time EQ 0)
        {
          if(Screen_Status.Replay_Flag EQ REPLAY_FLAG) //有重新播放标志
          {
            //Clear_Show_Data()
            memset(Show_Data.Color_Data, 0, sizeof(Show_Data.Color_Data));
            memset(Show_Data_Bak.Color_Data, 0, sizeof(Show_Data_Bak.Color_Data));
#if DATA_PREP_EN
            memset(&Prep_Data, 0, sizeof(Prep_Data));
            SET_HT(Prep_Data);
#endif
            Screen_Status.Replay_Flag = 0; //清除重新播放标志
            SET_SUM(Screen_Status);

            //重新开始从第0节目播放
            Prog_Status.Play_Status.Last_Prog_No = 0xFF;
            Prog_Status.Play_Status.Prog_No = 0;
            Prog_Status.Play_Status.New_Prog_Flag = NEW_FLAG;
            SET_SUM(Prog_Status);
          }
        }
      }
   }
}
