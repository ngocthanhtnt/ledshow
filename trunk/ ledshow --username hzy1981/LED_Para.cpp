#define LED_PARA_C
#include "Includes.h"

//�û������ļ���С����
const S_File_Para_Info Usr_Para_File_Info[] =
{
  //{C_SCREEN_WH, 0}  0x01
  {C_SCREEN_ADDR, 1 + 11},//0x02
  {C_SCREEN_IP,   4 + 11}, //0x03
  {C_SCREEN_BAUD, 1 + 11}, //0x04
  {C_SCREEN_OC_TIME, 16 + 11},//0x05 //��ʱ���ػ�ʱ��
  {C_SCREEN_LIGNTNESS, 8 + 11},//0x06 //����
  //{C_SCREEN_TIME, 0x07}, //ʱ��
  
};

//���������ļ���С����
const S_File_Para_Info Fac_Para_File_Info[] =
{
  {C_SCREEN_WH, 5 + 11},//0x02
  
};
/*
�ļ����֣�
fac_para.cfg //��������--����ǰ����
��Ļ��С
user_para.cfg //�û�����--�û����Լ�����
��ַ
IP��ַ
������
���ػ�ʱ��
����
��Ŀ��

prog_property00.cfg //��Ŀ0����
...
prog_propertyAA.cfg //��ĿN����

show-00-00-00.dat //�ļ�������: show-��Ŀ��-������-�ļ���
......
show-AA-BB-CC.dat    

fac_para�ļ���ʽ:
cmd=01 ����������ɫ֡

use_para.cfg �ļ���ʽ
cmd=0x02 ����ַ���ɶ���д
cmd=0x03 ��IP�������ɶ���д
cmd=0x04 ͨ�����ʣ��ɶ���д
cmd=0x05 ��ʱ���ػ����ɶ���д
cmd=0x07 �������ã��ɶ���д
cmd=0x08 ��Ŀ��
prog_property00.cfg �ļ���ʽ

*/

//��ȡ��Ŀ����
//��ȡ��ʾ�����ļ���
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
/*  
  File_Name[i++] = '-';
  File_Name[i++] = '0' + File_No / 10;
  File_Name[i++] = '0' + File_No % 10;
 */ 
  File_Name[i] = '\0';
  strcat(File_Name, ".dat");
  
  return File_Name;
}

//��ȡ��Ŀ�����ļ���
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

//��ȡ���������ļ���
char * Get_Fac_Para_File_Name(char File_Name[])
{
  strcpy(File_Name, "fac_para.cfg");  
  return File_Name;
}

//��ȡ�û������ļ���
char * Get_Usr_Para_File_Name(char File_Name[])
{
  strcpy(File_Name, "usr_para.cfg");
  return File_Name;
}



//���ļ��ж�ȡһ֡
//Offset ƫ��
//pDst Ŀ�껺����
//����-1��ȡ����,�޷�������0��ʾ�ļ�������β��>0������֡��
INT32S File_Read_One_Frame(FILE_T File, INT32U Offset, INT8U *pSeq, INT16U *pCtrl, INT8U *pDst, INT8U *pDst_Start, INT16U DstLen)
{
  INT8S Re;
  //INT8U Temp[10];
  INT16U Len;
  
  //��ȡOffsetƫ�ƴ���һ֡
  Re = File_Read(File, Offset, 4, pDst, pDst_Start, DstLen); //sizeof(Temp), Temp, Temp, sizeof(Temp));
  if(Re <= 0)
    return Re;
  
  //֡ͷ�Ƿ���ȷ
  if(!(pDst[0] EQ FRAME_HEAD0 && pDst[1] EQ FRAME_HEAD1))
  {
    ASSERT_FAILED();
    return FILE_FRAME_ERR;
  }
  
  Len = pDst[2] + (INT16U)pDst[3] * 256; //֡��
  Re = File_Read(File, Offset + 4, Len - 4, pDst + 4, pDst_Start, DstLen);
  if(Re <= 0)
    return Re;
  
  if(Check_Frame_Format(pDst, Len) EQ 0)//֡��ʽ�Ƿ���ȷ
  {
    ASSERT_FAILED();
    return FILE_FRAME_ERR;
  }
  else
    return Len;
}



//��ȡĳһ����֡�ڲ����ļ��еĴ洢λ�ú�ƫ���Լ��洢���ĸ��ļ���
INT8U Get_Para_Frame_File_Off_Size(INT16U Ctrl_Code, char File_Name[], INT16U *pOffset, INT16U *pLen)
{
  INT8U i;
  INT16U Off = 0;//Len = 0;
  
  if(Ctrl_Code EQ C_SCREEN_WH) //��Ļ����
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
  else //�����������洢���û������ļ�
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

//�������֡����
INT8U Save_Para_Frame_Proc(INT8U Frame[], INT16U FrameLen)
{
  FILE_T File;
  INT16U Ctrl_Code, Off, Len;
  char File_Name[MAX_FILE_NAME_SIZE];
  
  Ctrl_Code = Frame[6] + (INT16U)Frame[7] * 256;
  
  if(Get_Para_Frame_File_Off_Size(Ctrl_Code, File_Name, &Off, &Len) > 0) //�Ƿ����ڲ���?
  {
    if(Len EQ FrameLen)
    {
      File = File_Open(File_Name, FILE_WR);
      File_Write(File, Off, Frame, Len);
      return 1;
    }
    else
    {
      ASSERT_FAILED();
      
    }
  }  
  return 0;
}

//�����Ŀ����֡
INT8U Save_Prog_Property_Frame_Proc(INT8U Frame[],INT16U FrameLen)
{
  INT8U Re;
  FILE_T File;
  INT16U Ctrl_Code;
  INT8U Prog_No;
  INT32U Size;
  char File_Name[MAX_FILE_NAME_SIZE];
  
  Ctrl_Code = Frame[6] + (INT16U)Frame[7] * 256;
  
  if(Ctrl_Code EQ C_PROG_PROPERTY) //��Ŀ����
  {
    Prog_No = *(Frame + 8); //��Ŀ��
    if(Prog_No >= MAX_PROGRAM_NUM)
    {
      ASSERT_FAILED();
      return 0;
    }
    
    Get_Program_Property_File_Name(Prog_No, File_Name);
    Re = 1;
    File = File_Open(File_Name, FILE_WR);
    if(Re EQ 0)
      ASSERT_FAILED();
    
    Size = File_Size(File_Name);
    Re &= File_Write(File, Size, Frame, FrameLen);
    if(Re EQ 0)
      ASSERT_FAILED();
    
    return Re;
  }
  
  return 0;
}

//�����Ŀ����֡
INT8U Save_Prog_Data_Frame_Proc(INT8U Frame[],INT16U FrameLen)
{
  FILE_T File;
  INT8U Re;
  INT16U Ctrl_Code;
  INT8U Prog_No, Area_No, File_No;
  INT32U Size;
  char File_Name[MAX_FILE_NAME_SIZE];
  
  Ctrl_Code = Frame[6] + (INT16U)Frame[7] * 256;
  
  if(Ctrl_Code EQ C_PROG_DATA) //��Ŀ����
  {
    Prog_No = *(Frame + 9); //��Ŀ��
    Area_No = *(Frame + 10); //������
    File_No = *(Frame + 11); //�ļ���
    
    if(Prog_No >= MAX_PROGRAM_NUM ||\
      Area_No >= MAX_AREA_NUM)
    {
      ASSERT_FAILED();
      return 0;
    }
    
    Get_Program_Data_File_Name(Prog_No, Area_No, File_Name);
    Re = 1;
    File = File_Open(File_Name, FILE_WR);
    if(Re EQ 0)
      ASSERT_FAILED();
    
    Size = File_Size(File);
    Re &= File_Write(File, Size, Frame, FrameLen);
    if(Re EQ 0)
      ASSERT_FAILED();
    
    return Re;
  }
  
  return 0;
}

//ɾ����Ŀ����
INT8U Del_Prog_Data(INT8U Frame[], INT16U FrameLen)
{
  INT8U *pData;
  INT16U Ctrl_Code;
  
  Ctrl_Code = Frame[6] + (INT16U)Frame[7] * 256;
  pData = Frame + 8; //������ 
  if(Ctrl_Code EQ C_DEL_PROG) //ɾ����Ŀ---�ݶ�Ϊɾ�����н�Ŀ,�������޸�
  {
    File_Delete("*.pro");  //ɾ����Ŀ�����ļ�
    File_Delete("*.dat"); //ɾ����Ŀ�����ļ�
    return 1;
  }
  
  return 0;
}




//��ȡ��Ŀ����
//Prog��Ŀ��
//����ֵ1 ��ʾ��ȡ�ɹ���0��ʾû�������Ŀ���߶�ȡ���ɹ�
INT8U Read_Program_Para(INT8U Prog_No)
{
  char File_Name[MAX_FILE_NAME_SIZE];
  FILE_T File;
  INT16U Ctrl, Len;
  INT8U Seq;
  
  Get_Program_Property_File_Name(Prog_No, File_Name);
  File = File_Open(File_Name, FILE_R);
  Len = File_Read_One_Frame(File, 0, &Seq, &Ctrl, (INT8U *)&Program_Para, (INT8U *)&Program_Para, sizeof(Program_Para));
  File_Close(File);
  if(Len > 0)
    return 1;
  else
  {
    ASSERT_FAILED();
    return 0;
  }
}

//��ʱ��Ϣ�У����ڵĵ�0λ��ʾ����1����6λ��ʾ������
INT8U Check_Program_Time()
{
  //INT8U i;//Re = 1;
  INT8U Temp[20];
  memset(Temp, 0xFF, sizeof(Temp));
  
  if(Program_Para.Timing[0].Week != 0xFF)  //�����ڶ�ʱ
  {
    if(GET_BIT(Program_Para.Timing[0].Week, Cur_Time.Time[T_WEEK]) EQ 0)
      return 0;
  }      
  
  
  //�����ڶ�ʱ
  if(memcmp(Program_Para.Timing[0].Start_Date, Temp, 3) != 0 &&\
    memcmp(Program_Para.Timing[0].End_Date, Temp, 3) != 0)
  {
    if(!(Cur_Time.Time[T_YEAR] >= Program_Para.Timing[0].Start_Date[0] &&\
      Cur_Time.Time[T_YEAR] <= Program_Para.Timing[0].End_Date[0] &&\
        Cur_Time.Time[T_MONTH] >= Program_Para.Timing[0].Start_Date[1] &&\
          Cur_Time.Time[T_MONTH] <= Program_Para.Timing[0].End_Date[1] &&\
            Cur_Time.Time[T_DATE] >= Program_Para.Timing[0].Start_Date[2] &&\
              Cur_Time.Time[T_DATE] <= Program_Para.Timing[0].End_Date[2]))
      return 0;
    
  } 
  
  //��ʱ�䶨ʱ
  if(memcmp(Program_Para.Timing[0].Start_Time, Temp, 2) != 0 &&\
    memcmp(Program_Para.Timing[0].End_Time, Temp, 2) != 0)
  {
    if(!(Cur_Time.Time[T_HOUR] >= Program_Para.Timing[0].Start_Time[0] &&\
      Cur_Time.Time[T_HOUR] <= Program_Para.Timing[0].End_Time[0] &&\
        Cur_Time.Time[T_MIN] >= Program_Para.Timing[0].Start_Time[1] &&\
          Cur_Time.Time[T_MIN] <= Program_Para.Timing[0].End_Time[1]))
      return 0;
    
  }         
  
  return 1;
}

//��ȡ��ʾ����--����Read_Prog_Para
INT8U Update_Program_Para()
{
  INT8U i;
  
  for(i = 0; i < MAX_PROGRAM_NUM; i ++)
  {
    if(Read_Program_Para(i)) //��ȡ�ɹ�
    {
      if(Check_Program_Time())//��ǰʱ���Ƿ�Ϊ��Ŀ����ʱ��?
        return 1;
    }
  }
  
  return 0;
  
}

//����Ƿ���Ҫ���½�Ŀ����
INT8U Check_Update_Program_Para()
{
  static S_Int8U Min_Bak = {CHK_BYTE, 0xFF, CHK_BYTE};
  
  if(Min_Bak.Var EQ Cur_Time.Time[T_MIN])
    return 0;
  
  Min_Bak.Var = Cur_Time.Time[T_HOUR];  
  Debug_Print("Min check update program para");
 	
  if(Check_Program_Time() EQ 0) //��ǰʱ���Ƿ��ڽ�Ŀ����ʱ����?
  {	
    if(Update_Program_Para())
    {
      Debug_Print("update program para ok!");
      return 1;
    }
    else
      Debug_Print("no program run");
  }
  
  return 0;
}

//��ȡ����
void Read_Para()
{
  FILE_T File;
  INT16U Ctrl_Code;
  char File_Name[20];
  INT32U Offset = 0;
  INT32S Len = 0;
  INT8U Counts = 0;
  INT8U Seq;
  
  //��ȡ��������
  Get_Fac_Para_File_Name(File_Name); //���������ļ�����
  File = File_Open(File_Name, FILE_R); //ֻ����
  
  Len = File_Read_One_Frame(File, Offset, &Seq, &Ctrl_Code, Pub_Buf, Pub_Buf, sizeof(Pub_Buf));
  if(Len > 0)
    Para_Frame_Proc(Ctrl_Code, Pub_Buf, Len);
  else
    ASSERT_FAILED();
  
  //��ȡ�û�����
  Get_Usr_Para_File_Name(File_Name); //���������ļ�����
  File = File_Open(File_Name, FILE_R); //ֻ����
  //ÿ�ζ�һ֡��������,���ļ�����10֡

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
  
  //��ȡ��Ŀ����
  Update_Program_Para();
}