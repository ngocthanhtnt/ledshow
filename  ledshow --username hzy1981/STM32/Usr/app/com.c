#define COM_C
#include "Includes.h"

#if QT_EN EQ 0
const char version[] __attribute__((at(0x8000000 + APP_ADDRESS_OFF + 1000))) = CARD_NAME " " __TIME__ " " __DATE__ ;
#else
const char version[] = CARD_NAME " " __TIME__ " " __DATE__ ;
#endif
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

  if(Len > Frame_Len || Frame[Len - 1] != FRAME_TAIL) //尾正确
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
    //INT16U Len = 0;

    OS_memset(pDst, 0, SOFT_VERSION_LEN, pDst_Start, DstLen);
	mem_cpy(pDst, (INT8U *)version, sizeof(version), pDst_Start, DstLen);
/*
    mem_cpy(pDst + Len, (INT8U *)CARD_NAME, sizeof(CARD_NAME), pDst_Start, DstLen);
    Len += strlen(CARD_NAME);
    pDst[Len++] = ' ';

    mem_cpy(pDst + Len, (INT8U *)__DATE__, sizeof(__DATE__), pDst_Start, DstLen); //日期
    Len += strlen(__DATE__);
	pDst[Len++] = ' ';

    mem_cpy(pDst + Len, (INT8U *)__TIME__, sizeof(__TIME__), pDst_Start, DstLen); //日期
    Len += strlen(__TIME__);
    pDst[Len++] = '\0';
*/
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
  if(Len EQ 0)
    Screen_Status.Com_Err_Flag =  COM_ERR_WR_DATA;
  return Len;
}

//保存节目参数帧处理 
INT8U Save_Prog_Para_Frame_Proc(INT8U Frame[],INT16U FrameLen)
{
  INT8U Prog_No;
  INT16U Len;

  Len = FrameLen - F_NDATA_LEN;//Frame[FLEN] + (INT16U)Frame[FLEN + 1]*256;

  if(Len < PROG_PARA_LEN)
  {
      Screen_Status.Com_Err_Flag = COM_ERR_PARA_LEN_ERR;
      ASSERT_FAILED();
	  return 0;
  }

  if(Check_Prog_Para((S_Prog_Para *)(Frame + FDATA - 1)) EQ 0)
  {
	  Screen_Status.Com_Err_Flag = COM_ERR_PARA_INVALID;
	  ASSERT_FAILED();
	  return 0;
  }

  Prog_No = *(Frame + FDATA); //节目号
  if(Write_Prog_Para(Prog_No, Frame + FDATA, PROG_PARA_LEN))
  {
      /*
      Prog_Status.Play_Status.Prog_No = Prog_No;
      SET_SUM(Prog_Status.Play_Status);

      memset((void *)&Prog_Status.Block_Index, 0, sizeof(Prog_Status.Block_Index));

      SET_HT(Prog_Status.Block_Index);
      SET_SUM(Prog_Status.Block_Index);
      Write_Prog_Block_Index();
      */
      memset(Pub_Buf, 0, sizeof(Pub_Buf));
      Write_File_Para_Index(Prog_No, Pub_Buf);
  }
  else
  {
      Screen_Status.Com_Err_Flag = COM_ERR_WR_DATA;
      ASSERT_FAILED();
	  return 0;
   }
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
        Screen_Status.Com_Err_Flag =  COM_ERR_PROGRAM_NUM;
        return 0;
      }

      Para_Len = Get_Show_Para_Len(Type); //参数长度
      if(Para_Len <= Len)// || Para_Len + BORDER_DATA_LEN EQ Len)// 参数长度
      {
        memcpy(&Frame[FDATA] + S_OFF(S_Pic_Para, Data_Index) - 1, (INT8U *)&Cur_Block_Index.Index, 2);
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
          {   /*
              Prog_Status.Play_Status.Prog_No = Prog_No;
              SET_SUM(Prog_Status.Play_Status);

              memset((void *)&Prog_Status.Block_Index, 0, sizeof(Prog_Status.Block_Index));

              SET_HT(Prog_Status.Block_Index);
              SET_SUM(Prog_Status.Block_Index);
              //Read_Prog_Block_Index(Prog_No);*/
          }
          
        }
		else
		{
		  Screen_Status.Com_Err_Flag =  COM_ERR_WR_DATA;
		}
        
        return Re;
      }
      else
      {
        Screen_Status.Com_Err_Flag =  COM_ERR_PARA_LEN_ERR;
        ASSERT_FAILED();
        return 0;
      }
  }
  else //if(Seq0 EQ File_Para_Info.Seq0 + 1) //下一帧
  {
    if(Len + BLOCK_HEAD_DATA_LEN> BLOCK_DATA_LEN)
    {
      ASSERT_FAILED();
      Screen_Status.Com_Err_Flag =  COM_ERR_PARA_LEN_ERR;
      return 0;
    }

    if(Seq0 EQ 1) //第一条数据帧
    {
      //写当前节目的索引
      if(File_Para_Info.Prog_No < MAX_PROG_NUM &&\
         File_Para_Info.Area_No < MAX_AREA_NUM &&\
         File_Para_Info.File_No < MAX_FILE_NUM)
      { /*
        Prog_Status.Play_Status.Prog_No = File_Para_Info.Prog_No;
        SET_SUM(Prog_Status.Play_Status);

        Prog_Status.Block_Index.Index[File_Para_Info.Area_No][File_Para_Info.File_No] = Cur_Block_Index.Index;
        SET_SUM(Prog_Status.Block_Index);
        Write_Prog_Block_Index();//, Prog_Status.Block_Index.Index, sizeof(Prog_Status.Block_Index.Index));
        */
       }
      else
      {
        ASSERT_FAILED();
      }
    }
  /*
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
	*/

    Frame[FDATA - 9] = File_Para_Info.Prog_No;
    Frame[FDATA - 8] = File_Para_Info.Area_No;
    Frame[FDATA - 7] = File_Para_Info.File_No;
    Frame[FDATA - 6] = File_Para_Info.Type;
    Frame[FDATA - 5] = (Seq0 - 1)%256; //Seq0不是数据是参数，数据从0计，因此-1
    Frame[FDATA - 4] = (Seq0 - 1)/256;
    Frame[FDATA - 3] = Len % 256;
    Frame[FDATA - 2] = Len / 256;
    Frame[FDATA - 1] = 0; //下一帧的存储索引--备用
#if BLOCK_HEAD_DATA_LEN != 9
#error "BLOCK_HEAD_DATA_LEN error"
#endif

    //mem_cpy(Pub_Buf + BLOCK_HEAD_DATA_LEN, &Frame[FDATA], Len, Pub_Buf, sizeof(Pub_Buf));
    

    //当前分块数据
    Write_Storage_Data(SDI_SHOW_DATA + Cur_Block_Index.Index, Frame + FDATA - 9, BLOCK_DATA_LEN);
    
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
  else if(Cmd EQ C_ETH_MAC_PARA)
  {
    memcpy(pDst, ETH_Mac_Para.Mac, sizeof(ETH_Mac_Para.Mac));//基本参数
	return sizeof(ETH_Mac_Para.Mac);
  }/*
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
  else if(Cmd EQ C_SCREEN_LOCK_DATE)
  {
      mem_cpy(pDst, (INT8U *)&Screen_Para.Lock_Date, sizeof(Screen_Para.Lock_Date), pDst_Start, DstLen); //亮度参数
          return sizeof(Screen_Para.Lock_Date);
  }
  else if(Cmd EQ C_PROG_NUM)
  {
    mem_cpy(pDst, (INT8U *)&Prog_Num.Num, sizeof(Prog_Num.Num), pDst_Start, DstLen);
    return sizeof(Prog_Num.Num);
  }*/
  else
  {
    ASSERT_FAILED();
	return 0;
  }
}

//检查屏幕大小和颜色参数是否正确
INT8U Check_Screen_Base_Para(S_Screen_Base_Para *pPara)
{
  INT8U Color_Num;

  Color_Num = GET_COLOR_NUM(pPara->Color);

  if(pPara -> Width % 8 != 0 || pPara -> Height % 8 != 0)
    return 0;
  
  if((pPara -> Height) * (pPara->Width) * Color_Num >  MAX_POINTS * 2)
    return 0;

   return 1;
}

//重置节目个数
void Set_Prog_Num(INT8U Num)
{

      Prog_Num.Num = Num; //重置节目数
	  SET_SUM(Prog_Num);
	  Write_Prog_Num();	
}

extern void Set_Def_SMS_Para(void);
extern void _TIM3_Set_Period(INT16U Period);
//从帧中读取工厂参数和用户参数到变量中
//Cmd控制码
//Frame数据域起始
//Len数据域长度
INT8U Save_Screen_Para_Frame_Proc(INT16U Cmd, INT8U Data[], INT16U Len)
{
#pragma pack(1)
  S_Screen_Base_Para Base_Para;
#pragma pack()
  INT8U Data_Polarity, DefSMSFlag = 0;;

  Data_Polarity = Screen_Para.Scan_Para.Data_Polarity;

  if(Cmd EQ C_SCREEN_PARA && Len >= sizeof(Screen_Para) - CHK_BYTE_LEN)
  {
    memcpy((INT8U *)&Base_Para, Data, sizeof(Base_Para));

	if(Check_Screen_Base_Para(&Base_Para) EQ 0)
	{
	  Screen_Status.Com_Err_Flag = COM_ERR_PARA_INVALID;
	  return 0;
	}

	//参数发生了修改则重新播放ss
    if(memcmp((INT8U *)&Screen_Para.Base_Para, (INT8U *)&Base_Para, sizeof(Screen_Para.Base_Para)) != 0)
    {
      Set_Screen_Replay_Flag(); //重播节目标志
  	  Set_Prog_Num(0); //重置节目个数为0

	  DefSMSFlag = 1; //重置短信分区参数
    }

	mem_cpy((INT8U *)&Screen_Para.Base_Para, Data, sizeof(Screen_Para) - CHK_BYTE_LEN, (INT8U *)&Screen_Para, sizeof(Screen_Para));
    //SET_SUM(Screen_Para);
#if NET_EN
    Net_Para_Modi_Flag = NET_PARA_MODI_FLAG;
#endif

#if SMS_EN
    if(DefSMSFlag EQ 1)
	  Set_Def_SMS_Para();
#endif
  }
  else if(Cmd EQ C_SCREEN_BASE_PARA && Len >= sizeof(Screen_Para.Base_Para))
  {
    memcpy((INT8U *)&Base_Para, Data, sizeof(Base_Para));

 	if(Check_Screen_Base_Para(&Base_Para) EQ 0) //基本参数不正确，则恢复以前的参数
	{
	  Screen_Status.Com_Err_Flag = COM_ERR_SCREEN_SIZE;	 //屏幕尺寸错误
	  return 0;
	}

	//参数发生了修改则重新播放ss
    if(memcmp((INT8U *)&Screen_Para.Base_Para, (INT8U *)&Base_Para, sizeof(Screen_Para.Base_Para)) != 0)
    {
      Set_Screen_Replay_Flag(); //重播节目标志
      Set_Prog_Num(0);	//重置节目个数为0
	  
	  DefSMSFlag = 1;  //重置短信分区参数 
    }

	memcpy((INT8U *)&Screen_Para.Base_Para, Data, sizeof(Screen_Para.Base_Para));
	SET_SUM(Screen_Para);
    Calc_Screen_Color_Num();

#if SMS_EN
    if(DefSMSFlag EQ 1)
	  Set_Def_SMS_Para();
#endif
  }
  else if(Cmd EQ C_ETH_MAC_PARA && Len >= sizeof(ETH_Mac_Para.Mac))
  {
	memcpy(ETH_Mac_Para.Mac, Data, sizeof(ETH_Mac_Para.Mac));
	SET_HT(ETH_Mac_Para);
	SET_SUM(ETH_Mac_Para);

	Write_ETH_Mac_Para();

#if NET_EN
    Net_Para_Modi_Flag = NET_PARA_MODI_FLAG;
#endif
  }
  else if(Cmd EQ C_SCAN_PARA && Len >= sizeof(Screen_Para.Scan_Para))
    mem_cpy((INT8U *)&Screen_Para.Scan_Para, Data, sizeof(Screen_Para.Scan_Para), (INT8U *)&Screen_Para, sizeof(Screen_Para));//扫描参数
  else if(Cmd EQ C_SCREEN_COM_PARA && Len >= sizeof(Screen_Para.COM_Para))
    mem_cpy((INT8U *)&Screen_Para.COM_Para, Data, sizeof(Screen_Para.COM_Para), (INT8U *)&Screen_Para, sizeof(Screen_Para));//通信参数 
#if NET_EN
  else if(Cmd EQ C_SCREEN_ETH_PARA && Len >= sizeof(Screen_Para.ETH_Para))
    mem_cpy((INT8U *)&Screen_Para.ETH_Para, Data, sizeof(Screen_Para.ETH_Para), (INT8U *)&Screen_Para, sizeof(Screen_Para));//通信参数
#endif  
  else if(Cmd EQ C_SCREEN_OC_TIME && Len >= sizeof(Screen_Para.OC_Time))
    mem_cpy((INT8U *)&Screen_Para.OC_Time, Data, sizeof(Screen_Para.OC_Time), (INT8U *)&Screen_Para, sizeof(Screen_Para)); //定时开关机时间
  else if(Cmd EQ C_SCREEN_LIGNTNESS && Len >= sizeof(Screen_Para.Lightness))
    mem_cpy((INT8U *)&Screen_Para.Lightness, Data, sizeof(Screen_Para.Lightness), (INT8U *)&Screen_Para, sizeof(Screen_Para)); //亮度参数
  else if(Cmd EQ C_SCREEN_LOCK_DATE && Len >= sizeof(Screen_Para.Lock_Date))
    mem_cpy(&Screen_Para.Lock_Date, Data, sizeof(Screen_Para.Lock_Date), (INT8U *)&Screen_Para, sizeof(Screen_Para));
  else if(Cmd EQ C_PROG_NUM && Len>=sizeof(Prog_Num.Num))
  {
    if(Data[0] <= MAX_PROG_NUM)
	{
	    if(Prog_Num.Num != Data[0])//, sizeof(Prog_Num.Num)!=0))
	      Set_Screen_Replay_Flag(); //重播节目标志
	 
	    Set_Prog_Num(Data[0]); //重置节目个数
            //Write_Prog_Num();
		return 1;
	}
	else
	{
	  Screen_Status.Com_Err_Flag = COM_ERR_PROGRAM_NUM; //节目数超
	  return 0;
	}
  }
  else
  {
    ASSERT_FAILED();
	Screen_Status.Com_Err_Flag = COM_ERR_PARA_LEN_ERR;	//参数长度或者控制码错误
    return 0;
  }
#if QT_EN == 0
  _TIM3_Set_Period((Screen_Para.Scan_Para.Screen_Freq + 1) * 100);
#endif
  SET_SUM(Screen_Para);
  Write_Screen_Para(); //保存屏幕参数

  Chk_Data_Polarity_Change(Data_Polarity); //该函数暂未作用
  return 1;
}

//控制码高2位用来表达应答帧是肯定应答还是否定应答,0x40表示肯定应答,0x80表示否定应答
//第5位表示读还是写,1表示写,0表示读
//第0-5位表示控制码
//对收到的一帧的处理
//Ch表示通道
INT8U Rcv_Frame_Proc(INT8U Ch, INT8U Frame[], INT16U FrameLen, INT16U Frame_Buf_Len)
{
  INT8U Cmd_Code,Baud;
#if CLOCK_EN
  S_Time TempTime;
#endif
  INT8U Re, Temp;
  INT16U Len = 0;  //应答帧数据长
  INT8U Seq;
  INT16U Seq0;
  INT8U RW_Flag; //读写标志
  INT16U i;


  Clr_Watch_Dog();

  Re = 1;
  //pData = Frame + FDATA;
  Screen_Status.Com_Err_Flag = 0;
  Baud = Screen_Para.COM_Para.Baud;
     
  Cmd_Code = (Frame[FCMD] & 0x1F);// + (INT16U)Frame[FCMD + 1] * 256;
  RW_Flag = ((Frame[FCMD] & WR_CMD) >> 5);
  Seq = Frame[FSEQ];
  //Seq0 = Frame[FSEQ0];
  memcpy(&Seq0, &Frame[FSEQ0], 2);

  for(i = 0; i < FrameLen - F_NDATA_LEN; i ++)
  {
    Frame[FDATA + i] -= 0x33;
  } 

#if QT_EN == 0 //非QT情况下判断地址
  if(Ch EQ CH_COM) //GPRS、短信不需要判地址，U盘以文件名作为地址判断
  {
	if(memcmp((INT8U *)&Frame[FADDR], (INT8U *)&Screen_Para.COM_Para.Addr, 2) != 0)
	{
	  debug("Frame addr err");
	  return 0;
	}  
  }
#endif

  debug("Rcv Frame cmd = %d", Cmd_Code);

  if(Cmd_Code EQ  C_SCREEN_COM_PARA ||\
      Cmd_Code EQ C_SCREEN_OC_TIME ||\
      Cmd_Code EQ C_SCREEN_LIGNTNESS ||\
      Cmd_Code EQ C_SCREEN_BASE_PARA ||\
	  Cmd_Code EQ C_ETH_MAC_PARA ||\
      Cmd_Code EQ C_SCAN_PARA ||\
      Cmd_Code EQ C_SCREEN_COM_PARA ||\
      Cmd_Code EQ C_PROG_NUM ||\
      Cmd_Code EQ C_SCREEN_LOCK_DATE ||\
      Cmd_Code EQ C_SCREEN_PARA)
  {
    if(RW_Flag EQ SET_FLAG)
	{
      Re &= Save_Screen_Para_Frame_Proc(Cmd_Code, Frame + FDATA, FrameLen - F_NDATA_LEN); //更新内存中的参数
	}
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
#if CLOCK_EN
    if(RW_Flag EQ SET_FLAG)
	{
          if(Screen_Status.Lock_Date_Flag EQ LOCK_DATE_FLAG) //已经进入锁定状态，不允许设置事件，否则可以解除锁定
      {
		Len = 0;
		Re = 0;
	  }
	  else
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
	}
	else
	{

	}
#else
    Re = 0;
#endif
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
       Frame[FDATA] = Screen_Status.Manual_OC_Flag;

	   Len = 1;
	   Re = 1; 
	}
  }
  else if(Cmd_Code EQ C_SELF_TEST) //控制器维护
  {
    if(RW_Flag EQ SET_FLAG)
	{
	  Temp = Frame[FDATA];

	  if(Temp EQ 0x03) //硬件自检命令
	  {
	    Frame[FDATA] = Self_Test();
		Len = 1;
		Re = 1;
	  }
	  else
	  {
	      //先发送应答
		  Cmd_Code = Cmd_Code | 0x40; //肯定应答
		  Len = Make_Frame(Frame + FDATA, 0, (INT8U *)&Screen_Para.COM_Para.Addr, Cmd_Code,  0, Seq, Seq0, (char *)Frame);
		  Send_Frame_Proc(Ch, Frame, Len); //向来数据的通道发送应答数据
		  //先发送应答
		  
	      if(Temp EQ 0x00) //进入自检状态
		  {
	        Scan_Mode_Test(CMD_TEST);
		  }
		  else if(Temp EQ 0x01)
		  {
	        Soft_Reset(); //软件复位
		  }
	#if QT_EN == 0
		  else if(Temp EQ 0x02) //固件升级--复位进入升级程序
		  {
		      BKP_Register_Init();
	
			  //RCC_AHBPeriphClockCmd(RCC_APB1Periph_BKP, ENABLE);
			
			  //BKP_ReadBackupRegister(BKP_DR1);
			  //BKP_ReadBackupRegister(BKP_DR2);
			  
			  BKP_WriteBackupRegister(BKP_DR1, 0xA789);
			  BKP_WriteBackupRegister(BKP_DR2, 0x5A23);	
			  
			  if(Get_Com_Baud() EQ 57600)
			    BKP_WriteBackupRegister(BKP_DR3, 0x00); 
			  else
			    BKP_WriteBackupRegister(BKP_DR3, 0x01);
				
		      Soft_Reset(); //软件复位		 
		  }
		  else if(Temp EQ 0x04)	//进入输出接口的测试状态
		  {
			 Scan_Interface_Test();
		  }
		  else if(Temp EQ 0x05) //
		  {
		  	Encrypt();
		  	Soft_Reset();
		  } 
	#endif
		  return Len;
	  }
	}

  }
#if SMS_EN || GPRS_EN
  else if(Cmd_Code EQ C_ZK_DATA)
  {
    if(RW_Flag EQ SET_FLAG)
	{
	   Len = 0;
	   Re = Write_Storage_Data_NoCS(SDI_ZK_DATA, Seq0 * ZK_DATA_LEN, &Frame[FDATA], FrameLen - F_NDATA_LEN); 
	}
  }
#endif
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

	 if(Screen_Status.Com_Err_Flag EQ 0)
	   Screen_Status.Com_Err_Flag = COM_ERR_OTHER;

	 Frame[FDATA] = Screen_Status.Com_Err_Flag; //错误信息字
     Len = 1;
  }

  Len = Make_Frame(Frame + FDATA, Len, (INT8U *)&Screen_Para.COM_Para.Addr, Cmd_Code,  0, Seq, Seq0, (char *)Frame);
// INT16U Make_Frame(INT8U *pData, INT16U Len, INT8U Addr[], INT8U Cmd, INT8U Cmd0, INT8U Seq, INT16U Seq0, char *pDst)

  Clr_Rcv_Flag(); //发数据前清空接收标志
  Send_Frame_Proc(Ch, Frame, Len); //向来数据的通道发送应答数据
  
  Chk_Baud_Change(Baud); //检查波特率参数是否发生修改
  //memset(RCV_DATA_BUF, 0, sizeof(RCV_DATA_BUF));
  
  return Re;
}

//发送一条帧数据
void Send_Frame_Proc(INT8U Ch, INT8U Frame[], INT16U FrameLen)
{
  INT16U i;
#if NET_EN && (QT_EN EQ 0)
  INT8U *sendBuf;
#endif  
  if(Ch EQ CH_COM || Ch EQ CH_GPRS) //发送串口数据
  {
    if(Ch EQ CH_COM)
	{
	  Com_Send_Byte(Ch, 0xEE);
	  Com_Send_Byte(Ch, 0xEE);
	  Com_Send_Byte(Ch, 0xEE);
	}

    for(i = 0; i < FrameLen; i ++)
      Com_Send_Byte(Ch, Frame[i]);
  }
  else if(Ch EQ CH_NET) //发送网络数据，实际是UDP数据
  {
#if NET_EN && (QT_EN EQ 0)
    sendBuf = udp_get_buf (FrameLen);
    if(sendBuf)
	{
	  memcpy(sendBuf, Frame, FrameLen);
	  
	  Unselect_SPI_Device();								//Provide timer tick
      SPI1_ENC28J60_Init();

      udp_send (Screen_Status.UDP_Soc, (INT8U *)Screen_Status.Rem_IP, Screen_Status.Rem_Port, sendBuf, FrameLen);
    }
#endif
  }
}

//接收环境变量数据,温度、湿度、噪音等
void Env_Rcv_Byte(INT8U Ch, INT8U Byte)
{
 
}

//清除环境变量缓冲区
void Clr_Env_Rcv_Data(void)
{

}

//INT16U Make_Frame(INT8U *pData, INT16U Len, INT8U Addr[], INT8U Cmd, INT8U Cmd0, INT8U Seq, INT16U Seq0, char *pDst)
//发送环境变量帧
void Send_Env_Frame(INT8U Flag)
{
}

//收到一个字节,中断中调用该函数
void Com_Rcv_Byte(INT8U Ch, INT8U Byte)
{
//  INT16U i;
  //static S_Int8U Head_Flag = {CHK_BYTE, 0x00, CHK_BYTE};//是否收到了帧头

  if(Screen_Status.Rcv_Flag EQ FRAME_FLAG) //当前已有一帧，停止继续接收，待该帧处理完
      return;

  if(Screen_Status.Rcv_Posi >= sizeof(RCV_DATA_BUF))
  {
     Clr_Rcv_Flag();
  }

  if(Screen_Status.Head_Flag EQ 0) //--没有收到帧头，则收到的字节放到起始位置
    Screen_Status.Rcv_Posi = 0;

  Screen_Status.Byte_Time = COM_STANDBY_SEC; //字节接收倒计时，倒计时结束还没有收到完整的一帧则清除接收到得数据

  if(Byte EQ FRAME_HEAD)
  {	
	Screen_Status.Head_Flag = 1; //收到帧头
	Set_Screen_Com_Time(COM_STANDBY_SEC); //通信保持时间，在这段时间内，扫描中断不进行扫描
  }
  else if(Byte EQ FRAME_TAIL) //收到帧尾字符
  {
    Screen_Status.Rcv_Ch = Ch;
	Set_Screen_Com_Time(COM_STANDBY_SEC); //通信保持时间，在这段时间内，扫描中断不进行扫描.
  }
  else if(Byte EQ 0xEE)
  {
	Set_Screen_Com_Time(COM_STANDBY_SEC); //前导字符
  }

  if(Screen_Status.Head_Flag)
  {
	RCV_DATA_BUF[Screen_Status.Rcv_Posi] = Byte;
	Screen_Status.Rcv_Posi++;
  }								   
}

void Chk_Exit_Test_Scan_Mode()
{
	INT8U Cmd_Code;
	
	if(Screen_Status.Rcv_Flag EQ FRAME_FLAG)
	{	 
	   Cmd_Code = RCV_DATA_BUF[FCMD];// + (INT16U)Frame[FCMD + 1] * 256;
	   if(Cmd_Code EQ C_SELF_TEST)
	   {
		 if(RCV_DATA_BUF[FDATA] EQ 0x01) //退出
		 {
		   Soft_Reset(); //软件复位
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
          if(RCV_DATA_BUF[i] EQ FRAME_HEAD && \
             Check_Frame_Format(RCV_DATA_BUF + i, Screen_Status.Rcv_Posi - i))
          {
		    
			 Set_Screen_Com_Time(COM_STANDBY_SEC); //到计时5s，5秒后重新播放节目 
             
			 if(i != 0) //将数据复制到开始
              {
                 memcpy(RCV_DATA_BUF, RCV_DATA_BUF + i, Screen_Status.Rcv_Posi - i);
                 Screen_Status.Rcv_Posi = Screen_Status.Rcv_Posi - i;
             }

             Screen_Status.Rcv_Flag = FRAME_FLAG;
			 Screen_Status.Rcv_Ch = Ch;
             return;
          }
      
	 } */
   if(Screen_Status.Head_Flag > 0 &&\
      Check_Frame_Format((INT8U *)RCV_DATA_BUF, Screen_Status.Rcv_Posi))//(Screen_Status.Rcv_Flag EQ FRAME_FLAG)
   {
     Set_Screen_Com_Time(COM_STANDBY_SEC); //到计时5s，5秒后重新播放节目
     Rcv_Frame_Proc(Screen_Status.Rcv_Ch, (INT8U *)RCV_DATA_BUF, Screen_Status.Rcv_Posi, sizeof(RCV_DATA_BUF));

   }

#if NET_EN
   Net_Proc();
#endif

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

        }
	 }

  if(Screen_Status.Replay_Flag EQ REPLAY_FLAG)
  {
	   if(Prog_Status.Play_Status.RT_Play_Time EQ 0 && Screen_Status.Com_Time EQ 0) //有重新播放标志
	   {
	    Replay_Prog();
	    Screen_Status.Replay_Flag = 0;
		SET_SUM(Screen_Status);
		}
   }		   
}
