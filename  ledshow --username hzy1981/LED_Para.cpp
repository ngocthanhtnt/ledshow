#define LED_PARA_C
#include "Includes.h"

//返回屏幕支持的颜色数
INT8U Get_Screen_Color_Num()
{
  if(Screen_Para.Base_Para.Color < 3 || Screen_Para.Base_Para.Color EQ 4)
      return 1;
  else if(Screen_Para.Base_Para.Color EQ 3 || Screen_Para.Base_Para.Color EQ 5 || Screen_Para.Base_Para.Color EQ 6)
      return 2;
  else if(Screen_Para.Base_Para.Color EQ 7)
      return 3;
  else
      return 0;
}

//获取不同显示参数的长度
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
INT8U Save_Screen_Para_Frame_Proc(INT8U Frame[], INT16U FrameLen)
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
INT8U Save_Prog_Para_Frame_Proc(INT8U Frame[],INT16U FrameLen)
{
  INT8U Prog_No;

  Prog_No = *(Frame + FDATA); //节目号
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

  //读出这个节目的存储索引
  Prog_Status.Prog_No = Prog_No;
  Read_Prog_Block_Index(Prog_No);
  return 1;
}

//获取节目prog_no分区Area_No的第File_No个文件的参数的存储索引
STORA_DI Get_Show_Para_Stora_DI(INT8U Prog_No, INT8U Area_No, INT8U File_No)
{
  if(Prog_No >= MAX_PROG_NUM || Area_No >= MAX_AREA_NUM || File_No >= MAX_FILE_NUM)
  {
    ASSERT_FAILED();
    return 0;
  }
  
  return SDI_FILE_PARA + (INT16U)Prog_No * MAX_AREA_NUM * MAX_FILE_NUM + (INT16U)Area_No * MAX_FILE_NUM + File_No; 
    
}

//节目数据块的索引
INT16U _Read_Prog_Block_Index(INT8U Prog_No, void *pDst, void *pDst_Start, INT16U DstLen)
{
  INT16U Len;
  
  Len = Read_Storage_Data(SDI_PROG_BLOCK_INDEX + Prog_No,  pDst, pDst_Start, DstLen);
#ifdef SDI_PROG_BLOCK_INDEX_BK0
  if(Len EQ 0)
    Len = Read_Storage_Data(SDI_PROG_BLOCK_INDEX_BK0 + Prog_No,  pDst, pDst_Start, DstLen);
#endif     
  
#ifdef SDI_PROG_BLOCK_INDEX_BK1
  if(Len EQ 0)
    Len = Read_Storage_Data(SDI_PROG_BLOCK_INDEX_BK1 + Prog_No,  pDst, pDst_Start, DstLen);
#endif 
  
  return Len;
  
}

//读取节目的存储索引

//Prog_No表示节目号
INT16U Read_Prog_Block_Index(INT8U Prog_No)
{
  INT16U Len;
  
  Len = _Read_Prog_Block_Index(Prog_No, Prog_Status.Block_Index.Index, &Prog_Status.Block_Index, sizeof(Prog_Status.Block_Index));
  
  if(Len > 0)
  {
    SET_HT(Prog_Status.Block_Index);
    SET_SUM(Prog_Status.Block_Index);
  }
  
  return Len;
}

INT8U Write_Prog_Block_Index(INT8U Prog_No, void *pSrc, INT16U SrcLen)
{
  INT8U Re = 1;
  
  Re &= Write_Storage_Data(SDI_PROG_BLOCK_INDEX + Prog_No, pSrc, SrcLen);
  
#ifdef SDI_PROG_BLOCK_INDEX_BK0
  Re &= Write_Storage_Data(SDI_PROG_BLOCK_INDEX_BK0 + Prog_No, pSrc, SrcLen);
#endif

#ifdef SDI_PROG_BLOCK_INDEX_BK1
  Re &= Write_Storage_Data(SDI_PROG_BLOCK_INDEX_BK1 + Prog_No, pSrc, SrcLen);
#endif
  
  return Re;
  
}

//读取文件参数
INT16U Read_File_Para(INT8U Prog_No, INT8U Area_No, INT8U File_No, void *pDst, void *pDst_Start, INT16U DstLen)
{
  STORA_DI SDI;
  INT16U Len;
  
  SDI = SDI_FILE_PARA + (INT16U)Prog_No * MAX_AREA_NUM * MAX_FILE_NUM + (INT16U)Area_No * MAX_FILE_NUM + File_No;   
  Len = Read_Storage_Data(SDI, pDst, pDst_Start, DstLen); 
  
#ifdef SDI_FILE_PARA_BK0
  if(Len EQ 0)
  {
    SDI = SDI_FILE_PARA_BK0 + (INT16U)Prog_No * MAX_AREA_NUM * MAX_FILE_NUM + (INT16U)Area_No * MAX_FILE_NUM + File_No;   
    Len = Read_Storage_Data(SDI, pDst, pDst_Start, DstLen); 
  }
#endif
  
#ifdef SDI_FILE_PARA_BK1
  if(Len EQ 0)
  {
    SDI = SDI_FILE_PARA_BK1 + (INT16U)Prog_No * MAX_AREA_NUM * MAX_FILE_NUM + (INT16U)Area_No * MAX_FILE_NUM + File_No;   
    Len = Read_Storage_Data(SDI, pDst, pDst_Start, DstLen); 
  }
#endif 
  
  return Len;

}

//写文件参数
INT8U Write_File_Para(INT8U Prog_No, INT8U Area_No, INT8U File_No, void *pSrc, INT16U SrcLen)
{
  STORA_DI SDI;
  INT8U Re = 1;
  
  SDI = SDI_FILE_PARA + (INT16U)Prog_No * MAX_AREA_NUM * MAX_FILE_NUM + (INT16U)Area_No * MAX_FILE_NUM + File_No;   
  Re &=  Write_Storage_Data(SDI, pSrc, FILE_PARA_LEN); 
  
#ifdef SDI_FILE_PARA_BK0
  SDI = SDI_FILE_PARA_BK0 + (INT16U)Prog_No * MAX_AREA_NUM * MAX_FILE_NUM + (INT16U)Area_No * MAX_FILE_NUM + File_No;   
  Re &=  Write_Storage_Data(SDI, pSrc, FILE_PARA_LEN);   
#endif
  
#ifdef SDI_FILE_PARA_BK1
  SDI = SDI_FILE_PARA_BK1 + (INT16U)Prog_No * MAX_AREA_NUM * MAX_FILE_NUM + (INT16U)Area_No * MAX_FILE_NUM + File_No;   
  Re &=  Write_Storage_Data(SDI, pSrc, FILE_PARA_LEN);   
#endif 
  
  return Re;
}

//读取当前显示数据存储索引
INT16U Read_Cur_Block_Index(void *pDst, void *pDst_Start, INT16U DstLen)
{
  //STORA_DI SDI;
  INT16U Len;
  
  Len = Read_Storage_Data(SDI_CUR_BLOCK_INDEX, pDst, pDst_Start, DstLen); 
  
#ifdef SDI_CUR_BLOCK_INDEX_BK0
  if(Len EQ 0)
    Len = Read_Storage_Data(SDI_CUR_BLOCK_INDEX_BK0, pDst, pDst_Start, DstLen); 
#endif
  
#ifdef SDI_CUR_BLOCK_INDEX_BK1
  if(Len EQ 0)
     Len = Read_Storage_Data(SDI_CUR_BLOCK_INDEX_BK1, pDst, pDst_Start, DstLen); 
#endif 
  
  return Len;

}

//检查读出的数据是否是某节目某分区的某文件的数据
//Prog_No节目号
//Area_No分区号
//File_No文件号
//pData读出的数据
INT8U Check_Prog_Show_Data(INT8U Prog_No, INT8U Area_No, INT8U File_No, void *pData)
{
  S_File_Para_Info *p = (S_File_Para_Info *)pData;

  if(p->Prog_No EQ Prog_Para.Prog_No &&\
     p->Area_No EQ Area_No &&\
     p->File_No EQ File_No)
    return 1;
  else
    return 0;
  
}

//复制图文数据,从读取到的缓冲区复制到Show_Data中
//pSrc表示从存储器中读出的显示数据
//Off表示pSrc起始的数据在一屏显示数据中的偏移
//SrcLen表示pSrc起始的数据长度
//pDst表示目标显示缓冲区
//Area_No表示图文数据所在分区号
//X、Y表示目标图形显示的坐标
//Width,Height复制的图形的宽度和高度
INT16U Copy_Show_Data(void *pSrc, INT16U Off, INT16U SrcLen,\
                     S_Show_Data *pDst, INT8U Area_No, INT16U X, INT16U Y, INT16U Width, INT16U Height)
{
  //INT16U Width,Height;
  //INT32U X,Y;
  INT32U i,Len;
  INT8U Re;
  INT8U Screen_Color_Num;

  
  Screen_Color_Num = Get_Screen_Color_Num();
  Len = (INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1)); //每屏显示的数据长度
  Len = Len * Screen_Color_Num; //屏幕支持的颜色数
  
  Off = Off % Len; //Off在一屏显示数据中的偏移 

  for(i = 0; i <SrcLen*8/Screen_Color_Num && i<Len*8/Screen_Color_Num; i ++)
  {
    if(Screen_Color_Num EQ 1)  //单色屏
      Re = Get_Buf_Bit((INT8U *)pSrc, SrcLen, i);
    else if(Screen_Color_Num EQ 2) //双色屏
      Re = Get_Buf_Bit((INT8U *)pSrc, SrcLen, ((i>>3)<<4) + (i & 0x07)) +\
        (Get_Buf_Bit((INT8U *)pSrc, SrcLen, ((i>>3)<<4) + 8 + (i & 0x07))<<1);
    else if(Screen_Color_Num EQ 3) //三色屏
      Re = Get_Buf_Bit((INT8U *)pSrc, SrcLen, (i>>3)*24 + (i & 0x07)) +\
        (Get_Buf_Bit((INT8U *)pSrc, SrcLen, (i>>3)*24 + 8 + (i & 0x07))<<1)+
        (Get_Buf_Bit((INT8U *)pSrc, SrcLen, (i>>3)*24 + 16 + (i & 0x07))<<2);
  
    X = (Off*8 + i) % Width;
    Y = (Off*8 + i) / Width;
    
    if(X < Width && Y < Height) //X0,Y0必须在X_Len和Y_Len的范围内
      Set_Area_Point_Data(pDst, Area_No, X, Y, Re);
    else
      break;
  }
  
  return i/8;
}

//读取当前节目的分区Area_No的第File_No文件的第SIndex屏的显示数据
INT16U Read_Show_Data(INT8U Area_No, INT8U File_No, INT8U Flag, INT16U SIndex, \
                      S_Show_Data *pShow_Data)
{
  INT16U Width,Height,X,Y;
  INT32U Len,DstLen, Offset;
  INT16U Index;
   
#if PIC_SHOW_EN 
  if(Flag EQ SHOW_PIC) //图文
  {
     
    Width = Get_Area_Width(Area_No);
    Height = Get_Area_Height(Area_No);
   
    DstLen = (INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
    DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数
    
    Index = (DstLen * SIndex) / BLOCK_SHOW_DATA_LEN;//块偏移
    Index += Prog_Status.Block_Index.Index[Area_No][File_No]; //起始块号
      
    Offset = (DstLen * SIndex) % BLOCK_SHOW_DATA_LEN; //在该块中的索引   
    X = 0;
    Y = 0;   
  }  
#endif
#if CLOCK_SHOW_EN  
  else if(Flag EQ SHOW_CLOCK) //表盘
  {
    Width = Prog_Status.File_Para[Area_No].Clock_Para.Text_Width;
    Height = Prog_Status.File_Para[Area_No].Clock_Para.Text_Height;
    
    DstLen = (INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
    DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

    Index = Prog_Status.Block_Index.Index[Area_No][File_No];
    Offset = 0;
    X = Prog_Status.File_Para[Area_No].Clock_Para.Text_X;
    Y = Prog_Status.File_Para[Area_No].Clock_Para.Text_Y;    
  }
#endif
#if TIMER_SHOW_EN  
  else if(Flag EQ SHOW_TIMER) //计时
  {
    Width = Prog_Status.File_Para[Area_No].Timer_Para.Text_Width;
    Height = Prog_Status.File_Para[Area_No].Timer_Para.Text_Height;
    
    DstLen = (INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
    DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

    Index = Prog_Status.Block_Index.Index[Area_No][File_No];
    Offset = 0;
    X = Prog_Status.File_Para[Area_No].Timer_Para.Text_X;
    Y = Prog_Status.File_Para[Area_No].Timer_Para.Text_Y;     
  }
#endif
#if TIME_SHOW_EN  
  else if(Flag EQ SHOW_TIME) //日期时间
  {
    Width = Prog_Status.File_Para[Area_No].Time_Para.Text_Width;
    Height = Prog_Status.File_Para[Area_No].Time_Para.Text_Height;
    
    DstLen = (INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
    DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

    Index = Prog_Status.Block_Index.Index[Area_No][File_No];
    Offset = 0;
    X = Prog_Status.File_Para[Area_No].Time_Para.Text_X;
    Y = Prog_Status.File_Para[Area_No].Time_Para.Text_Y;     
  }
#endif
#if LUN_SHOW_EN  
  else if(Flag EQ SHOW_LUN) //农历
  {
    Width = Prog_Status.File_Para[Area_No].Lun_Para.Text_Width;
    Height = Prog_Status.File_Para[Area_No].Lun_Para.Text_Height;
    
    DstLen = (INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
    DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

    Index = Prog_Status.Block_Index.Index[Area_No][File_No];
    Offset = 0;
    X = Prog_Status.File_Para[Area_No].Lun_Para.Text_X;
    Y = Prog_Status.File_Para[Area_No].Lun_Para.Text_Y;    
  }
#endif
#if TEMP_SHOW_EN  
  else if(Flag EQ SHOW_TEMP) //温度
  {
    Width = Prog_Status.File_Para[Area_No].Temp_Para.Text_Width;
    Height = Prog_Status.File_Para[Area_No].Temp_Para.Text_Height;
    
    DstLen = (INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
    DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

    Index = Prog_Status.Block_Index.Index[Area_No][File_No];
    Offset = 0;
    X = Prog_Status.File_Para[Area_No].Temp_Para.Text_X;
    Y = Prog_Status.File_Para[Area_No].Temp_Para.Text_Y;    
  }
#endif  
  else
  {
    ASSERT_FAILED();
    return 0;
  }
  
  OS_Mutex_Pend(PUB_BUF_MUTEX_ID);
  
  Len = 0;
  while(Len < DstLen)
  {
    if(Read_Storage_Data(SDI_SHOW_DATA + Index, Pub_Buf, Pub_Buf, sizeof(Pub_Buf)) EQ 0)
      break;
    
    if(Check_Prog_Show_Data(Prog_Para.Prog_No, Area_No, File_No, Pub_Buf) EQ 0)
    {
      ASSERT_FAILED();
      break;
    }
    //复制数据
    //Len0 = 0;
    mem_cpy(Pub_Buf, Pub_Buf + BLOCK_HEAD_DATA_LEN + Offset, BLOCK_DATA_LEN - (BLOCK_HEAD_DATA_LEN + Offset), Pub_Buf, sizeof(Pub_Buf));   
    //将读到的数据复制到显示备份区
    
    Len += Copy_Show_Data(Pub_Buf, Len, BLOCK_DATA_LEN - (BLOCK_HEAD_DATA_LEN + Offset), \
                           pShow_Data, Area_No, X, Y, Width, Height);
    Index++;
    Offset = 0;
  }
  
  OS_Mutex_Post(PUB_BUF_MUTEX_ID);
  return Len;
  
}

//删除某个节目的所有显示数据
void Clr_Prog_Show_Data(INT8U Prog_No)
{
  
  
}

//清除所有的显示数据
void Clr_All_Show_Data()
{
  INT8U i;

  for(i = 0; i < Screen_Para.Prog_Num; i ++)
    Clr_Prog_Show_Data(i);
  
}

//写当前显示数据存储索引
INT8U Write_Cur_Block_Index(void *pSrc, INT16U SrcLen)
{
  //STORA_DI SDI;
  INT8U Re = 1;
  
  //SDI = SDI_FILE_PARA + (INT16U)Prog_No * MAX_AREA_NUM * MAX_FILE_NUM + (INT16U)Area_No * MAX_FILE_NUM + File_No;   
  Re &=  Write_Storage_Data(SDI_CUR_BLOCK_INDEX, pSrc, sizeof(S_Cur_Block_Index)); 
  
#ifdef SDI_CUR_BLOCK_INDEX_BK0
  //SDI = SDI_FILE_PARA_BK0 + (INT16U)Prog_No * MAX_AREA_NUM * MAX_FILE_NUM + (INT16U)Area_No * MAX_FILE_NUM + File_No;   
  Re &=  Write_Storage_Data(SDI_CUR_BLOCK_INDEX, pSrc, sizeof(S_Cur_Block_Index));   
#endif
  
#ifdef SDI_CUR_BLOCK_INDEX_BK1
  //SDI = SDI_FILE_PARA_BK1 + (INT16U)Prog_No * MAX_AREA_NUM * MAX_FILE_NUM + (INT16U)Area_No * MAX_FILE_NUM + File_No;   
  Re &=  Write_Storage_Data(SDI_CUR_BLOCK_INDEX, pSrc, sizeof(S_Cur_Block_Index));   
#endif 
  
  return Re;
}

/*
typedef struct
{
  INT8U Prog_No;  //节目号
  INT8U Area_No:4; //分区号
  INT8U File_No:4; //文件号
  INT16U Len;     //帧长度
  INT8U Buf[ONE_BLOCK_SIZE];
  
}S_Prog_Show_Data;
*/
//保存节目数据帧
INT8U Save_Prog_Data_Frame_Proc(INT8U Frame[],INT16U FrameLen)
{
  static S_File_Para_Info File_Para_Info;
  INT8U Prog_No, Area_No, File_No, Type;
  INT16U Para_Len,Len;
  INT8U Seq,Re;
  INT16U Seq0;
  STORA_DI SDI;
  S_Prog_Show_Data *pShow_Data;

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
  if(Seq0 EQ 0) //参数帧--多帧中的第一帧
  {
      Type = Frame[FDATA];//*(Frame + 8); //哪类数据?
      Prog_No = Frame[FDATA + 1];//*(Frame + 9); //节目号
      Area_No = Frame[FDATA + 2];//*(Frame + 10); //分区号
      File_No = Frame[FDATA + 3];//*(Frame + 11); //文件号
      //File_Para_Info.Seq0 = Seq0;

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
          File_Para_Info.Seq0 = Seq0;

          if(Prog_No != Prog_Status.Prog_No)
          {
              Prog_Status.Prog_No = Prog_No;
              Read_Prog_Block_Index(Prog_No);
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
  else if(Seq0 EQ File_Para_Info.Seq0 + 1) //下一帧
  {
    if(Seq0 EQ 1) //第一条数据帧
      Prog_Status.Block_Index.Index[File_Para_Info.Area_No][File_Para_Info.File_No] = Cur_Block_Index.Index;
    
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
    
    if(Len + BLOCK_HEAD_DATA_LEN> BLOCK_DATA_LEN)
    {
        ASSERT_FAILED();
        return 0;
    }
    //当前分块数据
    Write_Storage_Data(SDI_SHOW_DATA + Cur_Block_Index.Index, Pub_Buf, BLOCK_DATA_LEN);
    
    //保存当前索引
    Cur_Block_Index.Index ++;
    SET_SUM(Cur_Block_Index);
    Write_Cur_Block_Index(&Cur_Block_Index, sizeof(Cur_Block_Index));
    
    //写当前节目的索引
    if(File_Para_Info.Prog_No < MAX_PROG_NUM &&\
       File_Para_Info.Area_No < MAX_AREA_NUM &&\
       File_Para_Info.File_No < MAX_FILE_NUM)
    {
      Prog_Status.Block_Index.Index[File_Para_Info.Area_No][File_Para_Info.File_No + 1] = Cur_Block_Index.Index;
      SET_SUM(Prog_Status.Block_Index);
      Write_Prog_Block_Index(File_Para_Info.Prog_No, Prog_Status.Block_Index.Index, sizeof(Prog_Status.Block_Index.Index));
    }
    else
    {
      ASSERT_FAILED();
    }
    return 1;
  }
    
    
  return 0;

}

//删除节目数据
INT8U Del_Prog_Data(INT8U Frame[], INT16U FrameLen)
{
  return 1;
}




//读取节目参数
//Prog节目号
//返回值1 表示读取成功。0表示没有这个节目或者读取不成功
INT16U Read_Prog_Para(INT8U Prog_No)
{
  INT16U Len;
  
  Len = Read_Storage_Data(SDI_PROG_PARA + Prog_No, &Prog_Para.Prog_No, &Prog_Para, sizeof(Prog_Para));

#ifdef SDI_PROG_PARA_BK0
  if(Len EQ 0)
    Len = Read_Storage_Data(SDI_PROG_PARA_BK0 + Prog_No, &Prog_Para.Prog_No, &Prog_Para, sizeof(Prog_Para));
#endif

#ifdef SDI_PROG_PARA_BK1
  if(Len EQ 0)
    Len = Read_Storage_Data(SDI_PROG_PARA_BK1 + Prog_No, &Prog_Para.Prog_No, &Prog_Para, sizeof(Prog_Para));
#endif 
  
  return Len;
}


/*
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
*/
/*
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
*/
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
    Screen_Para_Frame_Proc(Ctrl_Code, Pub_Buf, Len);
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
      Screen_Para_Frame_Proc(Ctrl_Code, Pub_Buf, Len);
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
