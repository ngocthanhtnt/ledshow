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

//获取版本号
INT16U Get_Soft_Version(INT8U *pDst, INT8U *pDst_Start, INT16U DstLen)
{
    INT16U Len = 0;

    mem_set(pDst, 0, SOFT_VERSION_LEN, pDst_Start, DstLen);

    mem_cpy(pDst + Len, (INT8U *)CARD_NAME, sizeof(CARD_NAME), pDst_Start, DstLen);
    Len += strlen(CARD_NAME);
    pDst[Len++] = ' ';

    mem_cpy(pDst + Len, (INT8U *)__DATE__, sizeof(__DATE__), pDst_Start, DstLen); //日期
    Len += strlen(__DATE__);
    pDst[Len++] = '\0';

    return SOFT_VERSION_LEN;
}

//根据屏幕参数获取当前波特率
INT32U Get_Com_Baud(void)
{
  if(Screen_Para.COM_Para.Baud EQ 0) //0-9600
    return 57600;
  else
    return 9600;

}


INT16U Make_Frame(INT8U *pData, INT16U Len, INT8U Addr[], INT8U Cmd, INT8U Cmd0, INT8U Seq, INT16U Seq0, char *pDst)
{
  INT16U sum;

  pDst[0] = FRAME_HEAD;//帧头
  memcpy(pDst + FADDR, Addr, 2); //地址
  memcpy(pDst + FDATA, pData, Len);

  pDst[FSEQ] = Seq;
  memcpy(pDst + FSEQ0, &Seq0, sizeof(Seq0));

  pDst[FCMD] = Cmd; //两个字节的控制码
  pDst[FCMD + 1] = Cmd0;

  Len += F_NDATA_LEN; //数据域 + 非数据域 = 整个帧长
  memcpy(pDst + FLEN, &Len, 2);

  sum = Sum_2Bytes((INT8U *)pDst, Len - 3); //后3个字节是校验和和帧尾
  memcpy((char *)pDst + Len - 3, (char *)&sum, 2);
  pDst[Len - 1] = FRAME_TAIL;

  return Len;
}

//读取节目参数帧处理
INT16U Read_Prog_Para_Frame_Proc(INT8U Frame[], INT16U FrameLen, INT16U Frame_Buf_Len)
{
  INT8U Prog_No;
  INT16U Len;

  Len = FrameLen - F_NDATA_LEN;//Frame[FLEN] + (INT16U)Frame[FLEN + 1]*256;

  Prog_No = *(Frame + FDATA); //节目号

  Len = _Read_Prog_Para(Prog_No, Frame + FDATA, Frame, Frame_Buf_Len);
  return Len;
}

//保存节目参数帧处理 
INT8U Save_Prog_Para_Frame_Proc(INT8U Frame[],INT16U FrameLen)
{
  INT8U Prog_No;
  INT16U Len;

  Len = FrameLen - F_NDATA_LEN;//Frame[FLEN] + (INT16U)Frame[FLEN + 1]*256;

  if(Len != PROG_PARA_LEN)
      ASSERT_FAILED();

  Prog_No = *(Frame + FDATA); //节目号
  if(Write_Prog_Para(Prog_No, Frame + FDATA, PROG_PARA_LEN))
  {
      //
      Prog_Status.Play_Status.Prog_No = Prog_No;
      SET_SUM(Prog_Status.Play_Status);
      memset(&Prog_Status.Block_Index, 0, sizeof(Prog_Status.Block_Index));

      SET_HT(Prog_Status.Block_Index);
      SET_SUM(Prog_Status.Block_Index);
      Write_Prog_Block_Index();
  }
  else
      ASSERT_FAILED();
  
  return 1;
}

//保存节目数据帧
INT8U Save_Prog_Data_Frame_Proc(INT8U Frame[],INT16U FrameLen)
{
  static S_File_Para_Info File_Para_Info;
  INT8U Prog_No, Area_No, File_No, Type;
  INT16U Para_Len,Len;
  INT8U Re;
  INT16U Seq0;
  //INT16U Cmd1;
  //S_Prog_Show_Data *pShow_Data;

  memcpy(&Len, &Frame[FLEN], sizeof(Len)); //帧长
  //计算数据域长度
  if(Len > F_NDATA_LEN)
    Len = Len - F_NDATA_LEN;
  else
  {
    ASSERT_FAILED();
    return 0;
  }
  
  Seq0 = Frame[FSEQ0] + (INT16U)Frame[FSEQ0 + 1] * 256;
  //Cmd1 = Frame[FCMD + 1];

  if(Seq0 EQ 0) //参数帧--多帧中的第一帧
  {
      Type = Frame[FDATA];//*(Frame + 8); //哪类数据?
      Prog_No = Frame[FDATA + 1];//*(Frame + 9); //节目号
      Area_No = Frame[FDATA + 2];//*(Frame + 10); //分区号
      File_No = Frame[FDATA + 3];//*(Frame + 11); //文件号

      if(Prog_No >= MAX_PROG_NUM &&\
         Area_No >= MAX_AREA_NUM &&\
         File_No >= MAX_FILE_NUM)
      {
        ASSERT_FAILED();
        return 0;
      }

      Para_Len = Get_Show_Para_Len(Type); //参数长度
      if(Para_Len EQ Len)// 参数长度
      {     
        Re =  Write_File_Para(Prog_No, Area_No, File_No, &Frame[FDATA], FILE_PARA_LEN);//写入文件参数
        if(Re > 0)
        {
          File_Para_Info.Type = Type;
          File_Para_Info.Prog_No = Prog_No;
          File_Para_Info.Area_No = Area_No;
          File_Para_Info.File_No = File_No;
          //File_Para_Info.Block_Index = 
          //File_Para_Info.Seq0 = Seq0;

          if(Area_No EQ 0 && File_No EQ 0) //设置第0分区第0文件表示是一个新节目
          {
              Prog_Status.Play_Status.Prog_No = Prog_No;
              SET_SUM(Prog_Status.Play_Status);
              memset(&Prog_Status.Block_Index, 0, sizeof(Prog_Status.Block_Index));

              SET_HT(Prog_Status.Block_Index);
              SET_SUM(Prog_Status.Block_Index);
              //Read_Prog_Block_Index(Prog_No);
          }
          
        }
        
        return Re;
      }
      else
      {
        
        ASSERT_FAILED();
        return 0;
      }
  }
  else //if(Seq0 EQ File_Para_Info.Seq0 + 1) //下一帧
  {
    if(Len + BLOCK_HEAD_DATA_LEN> BLOCK_DATA_LEN)
    {
      ASSERT_FAILED();
      return 0;
    }

    if(Seq0 EQ 1) //第一条数据帧
    {
      //写当前节目的索引
      if(File_Para_Info.Prog_No < MAX_PROG_NUM &&\
         File_Para_Info.Area_No < MAX_AREA_NUM &&\
         File_Para_Info.File_No < MAX_FILE_NUM)
      {
        Prog_Status.Play_Status.Prog_No = File_Para_Info.Prog_No;
        Prog_Status.Block_Index.Index[File_Para_Info.Area_No][File_Para_Info.File_No] = Cur_Block_Index.Index;
        SET_SUM(Prog_Status.Block_Index);
        Write_Prog_Block_Index();//, Prog_Status.Block_Index.Index, sizeof(Prog_Status.Block_Index.Index));
      }
      else
      {
        ASSERT_FAILED();
      }
    }

    memset(Pub_Buf, 0, sizeof(Pub_Buf));
    
    Pub_Buf[0] = File_Para_Info.Prog_No;
    Pub_Buf[1] = (File_Para_Info.Area_No <<4) + File_Para_Info.File_No;
    Pub_Buf[2] = File_Para_Info.Type;   
    Pub_Buf[3] = (Seq0 - 1)%256; //Seq0不是数据是参数，数据从0计，因此-1
    Pub_Buf[4] = (Seq0 - 1)/256;
    Pub_Buf[5] = Len % 256;
    Pub_Buf[6] = Len / 256;
    Pub_Buf[7] = 0; //下一帧的存储索引--备用
    Pub_Buf[8] = 0;

#if BLOCK_HEAD_DATA_LEN != 9
#error "BLOCK_HEAD_DATA_LEN error"
#endif

    mem_cpy(Pub_Buf + BLOCK_HEAD_DATA_LEN, &Frame[FDATA], Len, Pub_Buf, sizeof(Pub_Buf));
    

    //当前分块数据
    Write_Storage_Data(SDI_SHOW_DATA + Cur_Block_Index.Index, Pub_Buf, BLOCK_DATA_LEN);
    
    //保存当前索引
    Cur_Block_Index.Index ++;
    SET_SUM(Cur_Block_Index);
    Write_Cur_Block_Index(&Cur_Block_Index, sizeof(Cur_Block_Index));
    

    return 1;
  }
    
    
  //return 0;

}

 //读取屏幕参数
 //Cmd表示控制码
INT16U Read_Screen_Para_Frame_Proc(INT16U Cmd, INT8U *pDst, INT8U *pDst_Start, INT16U DstLen)
{
  if(Cmd EQ C_SCREEN_PARA)
    {
      mem_cpy(pDst, (INT8U *)&Screen_Para.Base_Para, sizeof(Screen_Para) - CHK_BYTE_LEN, pDst_Start, DstLen);//基本参数
          return sizeof(Screen_Para) - CHK_BYTE_LEN;
  }
  else if(Cmd EQ C_SCREEN_BASE_PARA)
  {
    mem_cpy(pDst, (INT8U *)&Screen_Para.Base_Para, sizeof(Screen_Para.Base_Para), pDst_Start, DstLen);//基本参数
	return sizeof(Screen_Para.Base_Para);
  }
  else if(Cmd EQ C_SCAN_PARA)
  {
    mem_cpy(pDst, (INT8U *)&Screen_Para.Scan_Para, sizeof(Screen_Para.Scan_Para), pDst_Start, DstLen);//扫描参数
	return sizeof(Screen_Para.Scan_Para);
  }
  else if(Cmd EQ C_SCREEN_COM_PARA)
  {
    mem_cpy(pDst, (INT8U *)&Screen_Para.COM_Para, sizeof(Screen_Para.COM_Para), pDst_Start, DstLen);//通信参数
	return sizeof(Screen_Para.COM_Para);
  }
  else if(Cmd EQ C_SCREEN_OC_TIME)
  {
    mem_cpy(pDst, (INT8U *)&Screen_Para.OC_Time, sizeof(Screen_Para.OC_Time), pDst_Start, DstLen); //定时开关机时间
    return sizeof(Screen_Para.OC_Time);
  }
  else if(Cmd EQ C_SCREEN_LIGNTNESS)
  { 
    mem_cpy(pDst, (INT8U *)&Screen_Para.Lightness, sizeof(Screen_Para.Lightness), pDst_Start, DstLen); //亮度参数
	return sizeof(Screen_Para.Lightness);
  }
  else if(Cmd EQ C_PROG_NUM)
  {
    mem_cpy(pDst, (INT8U *)&Screen_Para.Prog_Num, sizeof(Screen_Para.Prog_Num), (INT8U *)&Screen_Para, sizeof(Screen_Para));
    return sizeof(Screen_Para.Prog_Num);
  }
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
INT8U Save_Screen_Para_Frame_Proc(INT16U Cmd, INT8U Data[], INT16U Len)
{
  if(Cmd EQ C_SCREEN_PARA && Len >= sizeof(Screen_Para) - CHK_BYTE_LEN)
      mem_cpy((INT8U *)&Screen_Para.Base_Para, Data, sizeof(Screen_Para) - CHK_BYTE_LEN, (INT8U *)&Screen_Para, sizeof(Screen_Para));//
  else if(Cmd EQ C_SCREEN_BASE_PARA && Len >= sizeof(Screen_Para.Base_Para))
  {
    if(memcmp((INT8U *)&Screen_Para.Base_Para, Data, sizeof(Screen_Para.Base_Para)) != 0)
      {
      Set_Screen_Replay_Flag(); //重播节目标志
      Screen_Para.Prog_Num = 0; //重置节目数
    }
    mem_cpy((INT8U *)&Screen_Para.Base_Para, Data, sizeof(Screen_Para.Base_Para), (INT8U *)&Screen_Para, sizeof(Screen_Para));//基本参数
  }
  else if(Cmd EQ C_SCAN_PARA && Len >= sizeof(Screen_Para.Scan_Para))
    mem_cpy((INT8U *)&Screen_Para.Scan_Para, Data, sizeof(Screen_Para.Scan_Para), (INT8U *)&Screen_Para, sizeof(Screen_Para));//扫描参数
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

//控制码高2位用来表达应答帧是肯定应答还是否定应答,0x40表示肯定应答,0x80表示否定应答
//第5位表示读还是写,1表示写,0表示读
//第0-5位表示控制码
//对收到的一帧的处理
//Ch表示通道
INT16U Rcv_Frame_Proc(INT8U Ch, INT8U Frame[], INT16U FrameLen, INT16U Frame_Buf_Len)
{
  INT8U Cmd_Code;
  S_Time TempTime;
  INT8U Re;
  INT16U Len = 0;  //应答帧数据长
  INT8U Seq, Seq0;
  INT8U RW_Flag; //读写标志
  INT16U i;


  Re = 1;
  //pData = Frame + FDATA; 
  Cmd_Code = (Frame[FCMD] & 0x1F);// + (INT16U)Frame[FCMD + 1] * 256;
  RW_Flag = ((Frame[FCMD] & WR_CMD) >> 5);
  Seq = Frame[FSEQ];
  Seq0 = Frame[FSEQ0];

  for(i = 0; i < FrameLen - F_NDATA_LEN; i ++)
  {
    Frame[FDATA + i] -= 0x33;
  } 

  debug("Rcv Frame cmd = %d", Cmd_Code);

  if(Cmd_Code EQ  C_SCREEN_COM_PARA ||\
      Cmd_Code EQ C_SCREEN_OC_TIME ||\
      Cmd_Code EQ C_SCREEN_LIGNTNESS ||\
      Cmd_Code EQ C_SCREEN_BASE_PARA ||\
      Cmd_Code EQ C_SCAN_PARA ||\
      Cmd_Code EQ C_PROG_NUM ||\
      Cmd_Code EQ C_SCREEN_PARA)
  {
    if(RW_Flag EQ SET_FLAG)
      Re &= Save_Screen_Para_Frame_Proc(Cmd_Code, Frame + FDATA, FrameLen - F_NDATA_LEN); //更新内存中的参数
	else
	{
	  Len = Read_Screen_Para_Frame_Proc(Cmd_Code, Frame + FDATA, Frame, Frame_Buf_Len);
      Re &= (Len > 0)?1:0;  
	}
  }
  else if(Cmd_Code EQ C_PROG_PARA)//保存节目属性帧
  {
    if(RW_Flag EQ SET_FLAG)
	{
      Re &= Save_Prog_Para_Frame_Proc(Frame, FrameLen);
      Set_Screen_Replay_Flag(); //重播节目标志
	}
	else
	{
	  Len = Read_Prog_Para_Frame_Proc(Frame, FrameLen, Frame_Buf_Len - FDATA);
	  Re &= (Len > 0)?1:0;
	}
  }
  else if(Cmd_Code EQ C_PROG_DATA) //显示数据
  {
    if(RW_Flag EQ SET_FLAG)
	{
      Re &= Save_Prog_Data_Frame_Proc(Frame, FrameLen); //保存节目显示数据
      Set_Screen_Replay_Flag(); //重播节目标志
	}
	else
	  Re = 0;
  }
  else if(Cmd_Code EQ C_SCREEN_TIME) //设置时间
  {
    if(RW_Flag EQ SET_FLAG)
	{
      mem_cpy(TempTime.Time, Frame + FDATA, sizeof(TempTime.Time), TempTime.Time, sizeof(TempTime.Time));
	  SET_HT(TempTime);
	  SET_SUM(TempTime);
	  
	  if(Chk_Time(&TempTime))
	  {
        Re &= Set_Cur_Time(TempTime.Time);
		if(Re > 0)
		{
	   	    mem_cpy(Cur_Time.Time, TempTime.Time, sizeof(TempTime.Time), Cur_Time.Time, sizeof(Cur_Time.Time));
			SET_SUM(Cur_Time);
		}
	  }
	  else
	    Re = 0;
	}
	else
	{

	}
  }
  else if(Cmd_Code EQ C_SOFT_VERSION) //软件版本号码
  {
    if(RW_Flag EQ READ_FLAG)
      {
        Len = Get_Soft_Version(Frame + FDATA, Frame, Frame_Buf_Len - FDATA);
        Re = 1;
    }
  }
  else if(Cmd_Code EQ C_SCREEN_OC) //手动开关机
  {
    if(RW_Flag EQ SET_FLAG)
	{
      if(Frame[FDATA] EQ CLOSE_FLAG) //进入关机状态
	  {
	    Screen_Status.Manual_OC_Flag = CLOSE_FLAG; //手动关机
        //Self_Test(CMD_TEST);
	  }
	  else
	  {
        Screen_Status.Manual_OC_Flag = 0; //手动开机
	  }
	}
	else
	{  
	   if(Screen_Status.Manual_OC_Flag > 0)
	     Frame[FDATA] = Screen_Status.Manual_OC_Flag;
	   else
	     Frame[FDATA] = Screen_Status.Time_OC_Flag;

	   Len = 1;
	   Re = 1; 
	}
  }
  else if(Cmd_Code EQ C_SELF_TEST)
  {
    if(RW_Flag EQ SET_FLAG)
	{
      if(Frame[FDATA] EQ 0x00) //进入自检状态
	  {
                Self_Test(CMD_TEST);
	  }
	  else
	  {
        Soft_Rest(); //软件复位

	  }
	}

  }
  else
  {
    ASSERT_FAILED();
    Re = 0;
  }

  if(Re)
     Cmd_Code = Cmd_Code | 0x40; //肯定应答
  else
  {
     Cmd_Code = Cmd_Code | 0x80;
     Len = 1;
  }

  Len = Make_Frame(Frame + FDATA, Len, (INT8U *)&Screen_Para.COM_Para.Addr, Cmd_Code,  0, Seq, Seq0, (char *)Frame);
// INT16U Make_Frame(INT8U *pData, INT16U Len, INT8U Addr[], INT8U Cmd, INT8U Cmd0, INT8U Seq, INT16U Seq0, char *pDst)

  Clr_Rcv_Flag(); //发数据前清空接收标志
  Send_Frame_Proc(Ch, Frame, Len); //向来数据的通道发送应答数据
  
  
  //memset(Screen_Status.Rcv_Data, 0, sizeof(Screen_Status.Rcv_Data));
  
  return Len;
}

//发送一条帧数据
void Send_Frame_Proc(INT8U Ch, INT8U Frame[], INT16U FrameLen)
{
  INT16U i;

    for(i = 0; i < FrameLen; i ++)
      Com_Send_Byte(Ch, Frame[i]);
}

//收到一个字节,中断中调用该函数
void Com_Rcv_Byte(INT8U Ch, INT8U Byte)
{
  INT16U i;
  //static S_Int8U Head_Flag = {CHK_BYTE, 0x00, CHK_BYTE};//是否收到了帧头

  if(Screen_Status.Rcv_Flag EQ FRAME_FLAG) //当前已有一帧，停止继续接收，待该帧处理完
      return;

  if(Screen_Status.Rcv_Posi >= sizeof(Screen_Status.Rcv_Data))
    {
     Clr_Rcv_Flag();
  }

  if(Screen_Status.Head_Flag EQ 0) //--没有收到帧头，则收到的字节放到起始位置
    Screen_Status.Rcv_Posi = 0;

  Screen_Status.Rcv_Data[Screen_Status.Rcv_Posi] = Byte;
  Screen_Status.Rcv_Posi++;

  Screen_Status.Byte_Time = COM_STANDBY_SEC; //字节接收倒计时，倒计时结束还没有收到完整的一帧则清除接收到得数据

  //连续收到3个COM_BYTE认为要进入通信状态了!
  if(Byte EQ COM_BYTE)
  {
	Set_Screen_Com_Time(COM_STANDBY_SEC); //通信保持时间，在这段时间内，扫描中断不进行扫描.
  }
  else if(Byte EQ FRAME_HEAD)
  {	
	Screen_Status.Head_Flag = 1; //收到帧头
  }
  else if(Byte EQ FRAME_TAIL) //收到帧尾字符
  {
    Screen_Status.Rcv_Ch = Ch;
	Set_Screen_Com_Time(COM_STANDBY_SEC); //通信保持时间，在这段时间内，扫描中断不进行扫描.
  }
}

void Chk_Exit_Test_Scan_Mode()
{
	INT8U Cmd_Code;
	
	if(Screen_Status.Rcv_Flag EQ FRAME_FLAG)
	{	 
	   Cmd_Code = Screen_Status.Rcv_Data[FCMD];// + (INT16U)Frame[FCMD + 1] * 256;
	   if(Cmd_Code EQ C_SELF_TEST)
	   {
		 if(Screen_Status.Rcv_Data[FDATA] EQ 0x01) //退出
		 {
		   Soft_Rest(); //软件复位
		 }
	   }
	   Screen_Status.Rcv_Posi = 0;
	   Screen_Status.Rcv_Flag = 0;
	}
}

void Clr_Rcv_Flag(void)
{
   Screen_Status.Head_Flag = 0;
   Screen_Status.Rcv_Posi = 0;
   Screen_Status.Rcv_Flag = 0;  
}

void Screen_Com_Proc(void)
{
   static S_Int32U Sec = {CHK_BYTE, 0xFFFFFFFF, CHK_BYTE};
 /*
       //for(i = 0; i < Screen_Status.Rcv_Posi; i ++)
	  i = 0;
      {
          if(Screen_Status.Rcv_Data[i] EQ FRAME_HEAD && \
             Check_Frame_Format(Screen_Status.Rcv_Data + i, Screen_Status.Rcv_Posi - i))
          {
		    
			 Set_Screen_Com_Time(COM_STANDBY_SEC); //到计时5s，5秒后重新播放节目 
             
			 if(i != 0) //将数据复制到开始
              {
                 memcpy(Screen_Status.Rcv_Data, Screen_Status.Rcv_Data + i, Screen_Status.Rcv_Posi - i);
                 Screen_Status.Rcv_Posi = Screen_Status.Rcv_Posi - i;
             }

             Screen_Status.Rcv_Flag = FRAME_FLAG;
			 Screen_Status.Rcv_Ch = Ch;
             return;
          }
      
	 } */
   if(Screen_Status.Rcv_Data[0] EQ FRAME_HEAD && \
      Check_Frame_Format(Screen_Status.Rcv_Data, Screen_Status.Rcv_Posi))//(Screen_Status.Rcv_Flag EQ FRAME_FLAG)
   {
     Set_Screen_Com_Time(COM_STANDBY_SEC); //到计时5s，5秒后重新播放节目
     Rcv_Frame_Proc(Screen_Status.Rcv_Ch, Screen_Status.Rcv_Data, Screen_Status.Rcv_Posi, sizeof(Screen_Status.Rcv_Data));

   }

   //return;

   if(Sec.Var EQ SEC_TIMER)
     return;

   Sec.Var = SEC_TIMER;

   if(Screen_Status.Byte_Time > 0)
   {
	    Screen_Status.Byte_Time--;

        if(Screen_Status.Byte_Time EQ 0)
        {
		  Clr_Rcv_Flag();
		}
   }


   //收到最后一帧后的倒计时
   if(Screen_Status.Com_Time > 0)
   {
        Screen_Status.Com_Time--;
        //SET_SUM(Screen_Status);

        if(Screen_Status.Com_Time EQ 0)
        {
		  //Clr_Rcv_Flag();
          if(Screen_Status.Replay_Flag EQ REPLAY_FLAG) //有重新播放标志
          {
            debug("replay prog");

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
