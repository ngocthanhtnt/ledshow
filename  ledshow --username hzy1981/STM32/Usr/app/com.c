#define COM_C
#include "Includes.h"
/*
0	0x5A	֡ͷ
1	Len0	֡���ȵ��ֽ�(��֡ͷ��֡β)
2	Len1	֡���ȸ��ֽ�
3	Addr0	��ַ���ֽ�
4       Addr1   ��ַ���ֽ�
5	Seq	֡���, 0-255 ѭ������,�ط���������Ų���
6       Seq00   ֡����ŵ��ֽ�
7       Seq01   ֡����Ÿ��ֽ�
8	Cmd0	��������ֽ�
9	Cmd1	��������ֽ�
A	��	֡����������
	��	
	CS0	У������ֽ�,��֡ͷ��CS0ǰһ���ֽڵĺ�
	CS1	У������ֽ�
	0xAA	֡β
*/

/*
#define FHEAD  0x00 //֡ͷ,1
#define FLEN   0x01 //֡����,1
#define FADDR  0x03 //֡��ַ,2
#define FSEQ   0x05 //֡���,1
#define FSEQ0  0x06 //֡�����,2
#define FCMD   0x08 //������,2
#define FDATA  0x0A //��������
*/
INT8U Check_Frame_Format(INT8U Frame[], INT16U Frame_Len)
{
  INT16U Len;
  INT16U Sum;
  
  if(Frame[FHEAD] != FRAME_HEAD) //ͷ��ȷ
  {
    ASSERT_FAILED();
    return 0;
  }
  
  Len = Frame[FLEN] + (INT16U)Frame[FLEN + 1] * 256; //֡��

  if(Len!= Frame_Len || Frame[Len - 1] != FRAME_TAIL) //β��ȷ
  {
    ASSERT_FAILED();
    return 0;
  }
  
  Sum = Sum_2Bytes(Frame, Len - 3); //��3���ֽ���У��ͺ�֡β
  if(memcmp((INT8U *)&Sum, Frame + Len - 3, 2) EQ 0)
    return 1;
  else
  {
    ASSERT_FAILED();
     return 0;
  }  
  
}

//��ȡ�汾��
INT16U Get_Soft_Version(INT8U *pDst, INT8U *pDst_Start, INT16U DstLen)
{
    INT16U Len = 0;

    mem_set(pDst, 0, SOFT_VERSION_LEN, pDst_Start, DstLen);

    mem_cpy(pDst + Len, (INT8U *)CARD_NAME, sizeof(CARD_NAME), pDst_Start, DstLen);
    Len += strlen(CARD_NAME);
    pDst[Len++] = ' ';

    mem_cpy(pDst + Len, (INT8U *)__DATE__, sizeof(__DATE__), pDst_Start, DstLen); //����
    Len += strlen(__DATE__);
	pDst[Len++] = ' ';

    mem_cpy(pDst + Len, (INT8U *)__TIME__, sizeof(__TIME__), pDst_Start, DstLen); //����
    Len += strlen(__TIME__);
    pDst[Len++] = '\0';

    return SOFT_VERSION_LEN;
}

//������Ļ������ȡ��ǰ������
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

  pDst[0] = FRAME_HEAD;//֡ͷ
  memcpy(pDst + FADDR, Addr, 2); //��ַ
  memcpy(pDst + FDATA, pData, Len);

  pDst[FSEQ] = Seq;
  memcpy(pDst + FSEQ0, &Seq0, sizeof(Seq0));

  pDst[FCMD] = Cmd; //�����ֽڵĿ�����
  pDst[FCMD + 1] = Cmd0;

  Len += F_NDATA_LEN; //������ + �������� = ����֡��
  memcpy(pDst + FLEN, &Len, 2);

  sum = Sum_2Bytes((INT8U *)pDst, Len - 3); //��3���ֽ���У��ͺ�֡β
  memcpy((char *)pDst + Len - 3, (char *)&sum, 2);
  pDst[Len - 1] = FRAME_TAIL;

  return Len;
}

//��ȡ��Ŀ����֡����
INT16U Read_Prog_Para_Frame_Proc(INT8U Frame[], INT16U FrameLen, INT16U Frame_Buf_Len)
{
  INT8U Prog_No;
  INT16U Len;

  Len = FrameLen - F_NDATA_LEN;//Frame[FLEN] + (INT16U)Frame[FLEN + 1]*256;

  Prog_No = *(Frame + FDATA); //��Ŀ��

  Len = _Read_Prog_Para(Prog_No, Frame + FDATA, Frame, Frame_Buf_Len);
  return Len;
}

//�����Ŀ����֡���� 
INT8U Save_Prog_Para_Frame_Proc(INT8U Frame[],INT16U FrameLen)
{
  INT8U Prog_No;
  INT16U Len;

  Len = FrameLen - F_NDATA_LEN;//Frame[FLEN] + (INT16U)Frame[FLEN + 1]*256;

  if(Len != PROG_PARA_LEN)
      ASSERT_FAILED();

  Prog_No = *(Frame + FDATA); //��Ŀ��
  if(Write_Prog_Para(Prog_No, Frame + FDATA, PROG_PARA_LEN))
  {
      //
      Prog_Status.Play_Status.Prog_No = Prog_No;
      SET_SUM(Prog_Status.Play_Status);
      memset((void *)&Prog_Status.Block_Index, 0, sizeof(Prog_Status.Block_Index));

      SET_HT(Prog_Status.Block_Index);
      SET_SUM(Prog_Status.Block_Index);
      Write_Prog_Block_Index();
  }
  else
      ASSERT_FAILED();
  
  return 1;
}

//�����Ŀ����֡
INT8U Save_Prog_Data_Frame_Proc(INT8U Frame[],INT16U FrameLen)
{
  static S_File_Para_Info File_Para_Info;
  INT8U Prog_No, Area_No, File_No, Type;
  INT16U Para_Len,Len;
  INT8U Re;
  INT16U Seq0;
  //INT16U Cmd1;
  //S_Prog_Show_Data *pShow_Data;

  memcpy(&Len, &Frame[FLEN], sizeof(Len)); //֡��
  //���������򳤶�
  if(Len > F_NDATA_LEN)
    Len = Len - F_NDATA_LEN;
  else
  {
    ASSERT_FAILED();
    return 0;
  }
  
  Seq0 = Frame[FSEQ0] + (INT16U)Frame[FSEQ0 + 1] * 256;
  //Cmd1 = Frame[FCMD + 1];

  if(Seq0 EQ 0) //����֡--��֡�еĵ�һ֡
  {
      Type = Frame[FDATA];//*(Frame + 8); //��������?
      Prog_No = Frame[FDATA + 1];//*(Frame + 9); //��Ŀ��
      Area_No = Frame[FDATA + 2];//*(Frame + 10); //������
      File_No = Frame[FDATA + 3];//*(Frame + 11); //�ļ���

      if(Prog_No >= MAX_PROG_NUM &&\
         Area_No >= MAX_AREA_NUM &&\
         File_No >= MAX_FILE_NUM)
      {
        ASSERT_FAILED();
        return 0;
      }

      Para_Len = Get_Show_Para_Len(Type); //��������
      if(Para_Len EQ Len)// ��������
      {     
        Re =  Write_File_Para(Prog_No, Area_No, File_No, &Frame[FDATA], FILE_PARA_LEN);//д���ļ�����
        if(Re > 0)
        {
          File_Para_Info.Type = Type;
          File_Para_Info.Prog_No = Prog_No;
          File_Para_Info.Area_No = Area_No;
          File_Para_Info.File_No = File_No;
          //File_Para_Info.Block_Index = 
          //File_Para_Info.Seq0 = Seq0;

          if(Area_No EQ 0 && File_No EQ 0) //���õ�0������0�ļ���ʾ��һ���½�Ŀ
          {
              Prog_Status.Play_Status.Prog_No = Prog_No;
              SET_SUM(Prog_Status.Play_Status);
              memset((void *)&Prog_Status.Block_Index, 0, sizeof(Prog_Status.Block_Index));

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
  else //if(Seq0 EQ File_Para_Info.Seq0 + 1) //��һ֡
  {
    if(Len + BLOCK_HEAD_DATA_LEN> BLOCK_DATA_LEN)
    {
      ASSERT_FAILED();
      return 0;
    }

    if(Seq0 EQ 1) //��һ������֡
    {
      //д��ǰ��Ŀ������
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
  /*
    memset(Pub_Buf, 0, sizeof(Pub_Buf));
    
    Pub_Buf[0] = File_Para_Info.Prog_No;
    Pub_Buf[1] = (File_Para_Info.Area_No <<4) + File_Para_Info.File_No;
    Pub_Buf[2] = File_Para_Info.Type;   
    Pub_Buf[3] = (Seq0 - 1)%256; //Seq0���������ǲ��������ݴ�0�ƣ����-1
    Pub_Buf[4] = (Seq0 - 1)/256;
    Pub_Buf[5] = Len % 256;
    Pub_Buf[6] = Len / 256;
    Pub_Buf[7] = 0; //��һ֡�Ĵ洢����--����
    Pub_Buf[8] = 0;
	*/

    Frame[FDATA - 9] = File_Para_Info.Prog_No;
    Frame[FDATA - 8] = (File_Para_Info.Area_No <<4) + File_Para_Info.File_No;
    Frame[FDATA - 7] = File_Para_Info.Type;   
    Frame[FDATA - 6] = (Seq0 - 1)%256; //Seq0���������ǲ��������ݴ�0�ƣ����-1
    Frame[FDATA - 5] = (Seq0 - 1)/256;
    Frame[FDATA - 4] = Len % 256;
    Frame[FDATA - 3] = Len / 256;
    Frame[FDATA - 2] = 0; //��һ֡�Ĵ洢����--����
    Frame[FDATA - 1] = 0; 
#if BLOCK_HEAD_DATA_LEN != 9
#error "BLOCK_HEAD_DATA_LEN error"
#endif

    //mem_cpy(Pub_Buf + BLOCK_HEAD_DATA_LEN, &Frame[FDATA], Len, Pub_Buf, sizeof(Pub_Buf));
    

    //��ǰ�ֿ�����
    Write_Storage_Data(SDI_SHOW_DATA + Cur_Block_Index.Index, Frame + FDATA - 9, BLOCK_DATA_LEN);
    
    //���浱ǰ����
    Cur_Block_Index.Index ++;
    SET_SUM(Cur_Block_Index);
    Write_Cur_Block_Index(&Cur_Block_Index, sizeof(Cur_Block_Index));
    

    return 1;
  }
    
    
  //return 0;

}

 //��ȡ��Ļ����
 //Cmd��ʾ������
INT16U Read_Screen_Para_Frame_Proc(INT16U Cmd, INT8U *pDst, INT8U *pDst_Start, INT16U DstLen)
{
  if(Cmd EQ C_SCREEN_PARA)
    {
      mem_cpy(pDst, (INT8U *)&Screen_Para.Base_Para, sizeof(Screen_Para) - CHK_BYTE_LEN, pDst_Start, DstLen);//��������
          return sizeof(Screen_Para) - CHK_BYTE_LEN;
  }
  else if(Cmd EQ C_SCREEN_BASE_PARA)
  {
    mem_cpy(pDst, (INT8U *)&Screen_Para.Base_Para, sizeof(Screen_Para.Base_Para), pDst_Start, DstLen);//��������
	return sizeof(Screen_Para.Base_Para);
  }
  else if(Cmd EQ C_SCAN_PARA)
  {
    mem_cpy(pDst, (INT8U *)&Screen_Para.Scan_Para, sizeof(Screen_Para.Scan_Para), pDst_Start, DstLen);//ɨ�����
	return sizeof(Screen_Para.Scan_Para);
  }
  else if(Cmd EQ C_SCREEN_COM_PARA)
  {
    mem_cpy(pDst, (INT8U *)&Screen_Para.COM_Para, sizeof(Screen_Para.COM_Para), pDst_Start, DstLen);//ͨ�Ų���
	return sizeof(Screen_Para.COM_Para);
  }
  else if(Cmd EQ C_SCREEN_OC_TIME)
  {
    mem_cpy(pDst, (INT8U *)&Screen_Para.OC_Time, sizeof(Screen_Para.OC_Time), pDst_Start, DstLen); //��ʱ���ػ�ʱ��
    return sizeof(Screen_Para.OC_Time);
  }
  else if(Cmd EQ C_SCREEN_LIGNTNESS)
  { 
    mem_cpy(pDst, (INT8U *)&Screen_Para.Lightness, sizeof(Screen_Para.Lightness), pDst_Start, DstLen); //���Ȳ���
	return sizeof(Screen_Para.Lightness);
  }
  else if(Cmd EQ C_PROG_NUM)
  {
    mem_cpy(pDst, (INT8U *)&Prog_Num.Num, sizeof(Prog_Num.Num), pDst_Start, DstLen);
    return sizeof(Prog_Num.Num);
  }
  else
  {
    ASSERT_FAILED();
	return 0;
  }
}

//�����Ļ��С����ɫ�����Ƿ���ȷ
INT8U Check_Screen_Base_Para(S_Screen_Base_Para *pPara)
{
  INT8U Color_Num;

  Color_Num = GET_COLOR_NUM(pPara->Color);

  if(pPara -> Height /16 > MAX_SCAN_BLOCK_NUM)
    return 0;
  
  if((pPara -> Height) * (pPara->Width) * Color_Num >  MAX_POINTS * 2)
    return 0;

   return 1;
}

//���ý�Ŀ����
void Set_Prog_Num(INT8U Num)
{

      Prog_Num.Num = 0; //���ý�Ŀ��
	  SET_SUM(Prog_Num);
	  Write_Prog_Num();	
}
//��֡�ж�ȡ�����������û�������������
//Cmd������
//Frame��������ʼ
//Len�����򳤶�
INT8U Save_Screen_Para_Frame_Proc(INT16U Cmd, INT8U Data[], INT16U Len)
{
#pragma pack(1)
  S_Screen_Base_Para Base_Para;
#pragma pack()
  INT8U Data_Polarity;

  Data_Polarity = Screen_Para.Scan_Para.Data_Polarity;

  if(Cmd EQ C_SCREEN_PARA && Len >= sizeof(Screen_Para) - CHK_BYTE_LEN)
  {
    memcpy((INT8U *)&Base_Para, Data, sizeof(Base_Para));

	if(Check_Screen_Base_Para(&Base_Para) EQ 0)
	{
	  Screen_Status.Com_Err_Flag = COM_ERR_PARA_INVALID;
	  return 0;
	}

	//�����������޸������²���ss
    if(memcmp((INT8U *)&Screen_Para.Base_Para, (INT8U *)&Base_Para, sizeof(Screen_Para.Base_Para)) != 0)
    {
      Set_Screen_Replay_Flag(); //�ز���Ŀ��־
  	  Set_Prog_Num(0); //���ý�Ŀ����Ϊ0
    }

	mem_cpy((INT8U *)&Screen_Para.Base_Para, Data, sizeof(Screen_Para) - CHK_BYTE_LEN, (INT8U *)&Screen_Para, sizeof(Screen_Para));
    SET_SUM(Screen_Para);
  }
  else if(Cmd EQ C_SCREEN_BASE_PARA && Len >= sizeof(Screen_Para.Base_Para))
  {
    memcpy((INT8U *)&Base_Para, Data, sizeof(Base_Para));

 	if(Check_Screen_Base_Para(&Base_Para) EQ 0) //������������ȷ����ָ���ǰ�Ĳ���
	{
	  Screen_Status.Com_Err_Flag = COM_ERR_PARA_INVALID;
	  return 0;
	}

	//�����������޸������²���ss
    if(memcmp((INT8U *)&Screen_Para.Base_Para, (INT8U *)&Base_Para, sizeof(Screen_Para.Base_Para)) != 0)
    {
      Set_Screen_Replay_Flag(); //�ز���Ŀ��־
      Set_Prog_Num(0);	//���ý�Ŀ����Ϊ0  
    }

	memcpy((INT8U *)&Screen_Para.Base_Para, Data, sizeof(Screen_Para.Base_Para));
	SET_SUM(Screen_Para);
    Calc_Screen_Color_Num();
  }
  else if(Cmd EQ C_SCAN_PARA && Len >= sizeof(Screen_Para.Scan_Para))
    mem_cpy((INT8U *)&Screen_Para.Scan_Para, Data, sizeof(Screen_Para.Scan_Para), (INT8U *)&Screen_Para, sizeof(Screen_Para));//ɨ�����
  else if(Cmd EQ C_SCREEN_COM_PARA && Len >= sizeof(Screen_Para.COM_Para))
    mem_cpy((INT8U *)&Screen_Para.COM_Para, Data, sizeof(Screen_Para.COM_Para), (INT8U *)&Screen_Para, sizeof(Screen_Para));//ͨ�Ų���
  else if(Cmd EQ C_SCREEN_OC_TIME && Len >= sizeof(Screen_Para.OC_Time))
    mem_cpy((INT8U *)&Screen_Para.OC_Time, Data, sizeof(Screen_Para.OC_Time), (INT8U *)&Screen_Para, sizeof(Screen_Para)); //��ʱ���ػ�ʱ��
  else if(Cmd EQ C_SCREEN_LIGNTNESS && Len >= sizeof(Screen_Para.Lightness))
    mem_cpy((INT8U *)&Screen_Para.Lightness, Data, sizeof(Screen_Para.Lightness), (INT8U *)&Screen_Para, sizeof(Screen_Para)); //���Ȳ���
  else if(Cmd EQ C_PROG_NUM && Len>=sizeof(Prog_Num.Num))
  {
    if(Data[0] <= MAX_PROG_NUM)
	{
	    if(Prog_Num.Num != Data[0])//, sizeof(Prog_Num.Num)!=0))
	      Set_Screen_Replay_Flag(); //�ز���Ŀ��־
	 
	    Set_Prog_Num(Data[0]); //���ý�Ŀ����
		return 1;
	}
	else
	  return 0;
  }
  else
  {
    ASSERT_FAILED();
	Screen_Status.Com_Err_Flag = COM_ERR_PARA_LEN_ERR;
    return 0;
  }

  SET_SUM(Screen_Para);
  Write_Screen_Para(); //������Ļ����

  Chk_Data_Polarity_Change(Data_Polarity); //�ú�����δ����
  return 1;
}

//�������2λ��������Ӧ��֡�ǿ϶�Ӧ���Ƿ�Ӧ��,0x40��ʾ�϶�Ӧ��,0x80��ʾ��Ӧ��
//��5λ��ʾ������д,1��ʾд,0��ʾ��
//��0-5λ��ʾ������
//���յ���һ֡�Ĵ���
//Ch��ʾͨ��
INT16U Rcv_Frame_Proc(INT8U Ch, INT8U Frame[], INT16U FrameLen, INT16U Frame_Buf_Len)
{
  INT8U Cmd_Code,Baud;
  S_Time TempTime;
  INT8U Re, Temp;
  INT16U Len = 0;  //Ӧ��֡���ݳ�
  INT8U Seq, Seq0;
  INT8U RW_Flag; //��д��־
  INT16U i;


  Re = 1;
  //pData = Frame + FDATA;
  Screen_Status.Com_Err_Flag = 0;
  Baud = Screen_Para.COM_Para.Baud;
     
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
	  Cmd_Code EQ C_SCREEN_COM_PARA ||\
      Cmd_Code EQ C_PROG_NUM ||\
      Cmd_Code EQ C_SCREEN_PARA)
  {
    if(RW_Flag EQ SET_FLAG)
	{
      Re &= Save_Screen_Para_Frame_Proc(Cmd_Code, Frame + FDATA, FrameLen - F_NDATA_LEN); //�����ڴ��еĲ���
	}
	else
	{
	  Len = Read_Screen_Para_Frame_Proc(Cmd_Code, Frame + FDATA, Frame, Frame_Buf_Len);
      Re &= (Len > 0)?1:0;  
	}
  }
  else if(Cmd_Code EQ C_PROG_PARA)//�����Ŀ����֡
  {
    if(RW_Flag EQ SET_FLAG)
	{
      Re &= Save_Prog_Para_Frame_Proc(Frame, FrameLen);
      Set_Screen_Replay_Flag(); //�ز���Ŀ��־
	}
	else
	{
	  Len = Read_Prog_Para_Frame_Proc(Frame, FrameLen, Frame_Buf_Len - FDATA);
	  Re &= (Len > 0)?1:0;
	}
  }
  else if(Cmd_Code EQ C_PROG_DATA) //��ʾ����
  {
    if(RW_Flag EQ SET_FLAG)
	{
      Re &= Save_Prog_Data_Frame_Proc(Frame, FrameLen); //�����Ŀ��ʾ����
      Set_Screen_Replay_Flag(); //�ز���Ŀ��־
	}
	else
	  Re = 0;
  }
  else if(Cmd_Code EQ C_SCREEN_TIME) //����ʱ��
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
  else if(Cmd_Code EQ C_SOFT_VERSION) //�����汾����
  {
    if(RW_Flag EQ READ_FLAG)
      {
        Len = Get_Soft_Version(Frame + FDATA, Frame, Frame_Buf_Len - FDATA);
        Re = 1;
    }
  }
  else if(Cmd_Code EQ C_SCREEN_OC) //�ֶ����ػ�
  {
    if(RW_Flag EQ SET_FLAG)
	{
      if(Frame[FDATA] EQ CLOSE_FLAG) //����ػ�״̬
	  {
	    Screen_Status.Manual_OC_Flag = CLOSE_FLAG; //�ֶ��ػ�
        //Self_Test(CMD_TEST);
	  }
	  else
	  {
        Screen_Status.Manual_OC_Flag = 0; //�ֶ�����
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
	  Temp = Frame[FDATA];
      //�ȷ���Ӧ��
	  Cmd_Code = Cmd_Code | 0x40; //�϶�Ӧ��
	  Len = Make_Frame(Frame + FDATA, 0, (INT8U *)&Screen_Para.COM_Para.Addr, Cmd_Code,  0, Seq, Seq0, (char *)Frame);
	  Send_Frame_Proc(Ch, Frame, Len); //�������ݵ�ͨ������Ӧ������
	  //�ȷ���Ӧ��
	  
      if(Temp EQ 0x00) //�����Լ�״̬
	  {
        Scan_Mode_Test(CMD_TEST);
	  }
	  else
	  {
        Soft_Rest(); //������λ
	  }
	  return Len;
	}

  }
  else if(Cmd_Code EQ C_ENV_VAR)  //�����������¶ȡ�ʪ�ȡ�������
  {
    if(RW_Flag EQ SET_FLAG)
	{
	  Re = 1;
	  if(Frame[FDATA] EQ 0x00)
	    memcpy((void *)&Screen_Status.Temp, Frame + FDATA + 1, sizeof(Screen_Status.Temp));//, (void *)&Screen_Status.Temp, sizeof(Screen_Status.Temp));
	  else if(Frame[FDATA] EQ 0x01)
	    memcpy((void *)&Screen_Status.Humidity, Frame + FDATA + 1, sizeof(Screen_Status.Humidity));//, (void *)&Screen_Status.Humidity, sizeof(Screen_Status.Humidity));
	  else if(Frame[FDATA] EQ 0x02)
	    memcpy((void *)&Screen_Status.Noise, Frame + FDATA + 1, sizeof(Screen_Status.Noise));//, (void *)&Screen_Status.Humidity, sizeof(Screen_Status.Noise));
	  else
	    Re = 0;
	}
	else
	{
	  Re = 1;
	  if(Frame[FDATA] EQ 0x00)
	    memcpy(Frame + FDATA + 1, (void *)&Screen_Status.Temp, sizeof(Screen_Status.Temp));//, &Screen_Status.Temp, sizeof(Screen_Status.Temp));
	  else if(Frame[FDATA] EQ 0x01)
	    memcpy(Frame + FDATA + 1, (void *)&Screen_Status.Humidity, sizeof(Screen_Status.Humidity));
	  else if(Frame[FDATA] EQ 0x02)
	    memcpy(Frame + FDATA + 1, (void *)&Screen_Status.Noise, sizeof(Screen_Status.Noise));
	  else
	    Re = 0;

	}

	return 1;
  }
  else
  {
    ASSERT_FAILED();
    Re = 0;
  }

  if(Re)
     Cmd_Code = Cmd_Code | 0x40; //�϶�Ӧ��
  else
  {
     Cmd_Code = Cmd_Code | 0x80;
	 Frame[FDATA] = Screen_Status.Com_Err_Flag; //������Ϣ��
     Len = 1;
  }

  Len = Make_Frame(Frame + FDATA, Len, (INT8U *)&Screen_Para.COM_Para.Addr, Cmd_Code,  0, Seq, Seq0, (char *)Frame);
// INT16U Make_Frame(INT8U *pData, INT16U Len, INT8U Addr[], INT8U Cmd, INT8U Cmd0, INT8U Seq, INT16U Seq0, char *pDst)

  Clr_Rcv_Flag(); //������ǰ��ս��ձ�־
  Send_Frame_Proc(Ch, Frame, Len); //�������ݵ�ͨ������Ӧ������
  
  Chk_Baud_Change(Baud); //��鲨���ʲ����Ƿ����޸�
  //memset(RCV_DATA_BUF, 0, sizeof(RCV_DATA_BUF));
  
  return Len;
}

//����һ��֡����
void Send_Frame_Proc(INT8U Ch, INT8U Frame[], INT16U FrameLen)
{
  INT16U i;

    for(i = 0; i < FrameLen; i ++)
      Com_Send_Byte(Ch, Frame[i]);
}

//���ջ�����������,�¶ȡ�ʪ�ȡ�������
void Env_Rcv_Byte(INT8U Ch, INT8U Byte)
{
#if ENV_VAR_EN
  if(Screen_Status.Env_Rcv_Posi >= sizeof(Screen_Status.Env_Rcv_Data) ||\
     Screen_Status.Env_Frame_Flag > 0)//��ǰ��֡���ڴ������߷����򲻽�������
    return;

  Screen_Status.Env_Rcv_Data[Screen_Status.Env_Rcv_Posi ++] = 0;
#endif  
}

//�����������������
void Clr_Env_Rcv_Data(void)
{
#if ENV_VAR_EN
    Screen_Status.Env_Frame_Flag = 1;

	memset((void *)&Screen_Status.Env_Rcv_Data, 0, sizeof(Screen_Status.Env_Rcv_Data));
  	Screen_Status.Env_Rcv_Posi = 0;

    Screen_Status.Env_Frame_Flag = 0;  
#endif
}

//INT16U Make_Frame(INT8U *pData, INT16U Len, INT8U Addr[], INT8U Cmd, INT8U Cmd0, INT8U Seq, INT16U Seq0, char *pDst)
//���ͻ�������֡
void Send_Env_Frame(INT8U Flag)
{
#if ENV_VAR_EN
  INT16U Len;

  Len =  Make_Frame((INT8U *)Screen_Status.Env_Rcv_Data, 1, (INT8U *)&Screen_Para.COM_Para.Addr, C_ENV_VAR, 0, 0, 0, (char *)&Flag);
  Send_Frame_Proc(CH_ENV, (INT8U *)Screen_Status.Env_Rcv_Data, Len); //�������ݵ�ͨ������Ӧ������
#endif
}

//�յ�һ���ֽ�,�ж��е��øú���
void Com_Rcv_Byte(INT8U Ch, INT8U Byte)
{
//  INT16U i;
  //static S_Int8U Head_Flag = {CHK_BYTE, 0x00, CHK_BYTE};//�Ƿ��յ���֡ͷ

  if(Screen_Status.Rcv_Flag EQ FRAME_FLAG) //��ǰ����һ֡��ֹͣ�������գ�����֡������
      return;

  if(Screen_Status.Rcv_Posi >= sizeof(RCV_DATA_BUF))
  {
     Clr_Rcv_Flag();
  }

  if(Screen_Status.Head_Flag EQ 0) //--û���յ�֡ͷ�����յ����ֽڷŵ���ʼλ��
    Screen_Status.Rcv_Posi = 0;

  Screen_Status.Byte_Time = COM_STANDBY_SEC; //�ֽڽ��յ���ʱ������ʱ������û���յ�������һ֡��������յ�������

  if(Byte EQ FRAME_HEAD)
  {	
	Screen_Status.Head_Flag = 1; //�յ�֡ͷ
	Set_Screen_Com_Time(COM_STANDBY_SEC); //ͨ�ű���ʱ�䣬�����ʱ���ڣ�ɨ���жϲ�����ɨ��
  }
  else if(Byte EQ FRAME_TAIL) //�յ�֡β�ַ�
  {
    Screen_Status.Rcv_Ch = Ch;
	Set_Screen_Com_Time(COM_STANDBY_SEC); //ͨ�ű���ʱ�䣬�����ʱ���ڣ�ɨ���жϲ�����ɨ��.
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
		 if(RCV_DATA_BUF[FDATA] EQ 0x01) //�˳�
		 {
		   Soft_Rest(); //������λ
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
		    
			 Set_Screen_Com_Time(COM_STANDBY_SEC); //����ʱ5s��5������²��Ž�Ŀ 
             
			 if(i != 0) //�����ݸ��Ƶ���ʼ
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
     Set_Screen_Com_Time(COM_STANDBY_SEC); //����ʱ5s��5������²��Ž�Ŀ
     Rcv_Frame_Proc(Screen_Status.Rcv_Ch, (INT8U *)RCV_DATA_BUF, Screen_Status.Rcv_Posi, sizeof(RCV_DATA_BUF));

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


   //�յ����һ֡��ĵ���ʱ
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
	   if(Prog_Status.Play_Status.RT_Play_Time EQ 0 && Screen_Status.Com_Time EQ 0) //�����²��ű�־
	    Replay_Prog();
   }		   
}