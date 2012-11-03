#define LED_PARA_C
#include "Includes.h"

#if QT_EN && QT_SIM_EN
extern S_Show_Data protoShowData;
#endif


//返回屏幕支持的颜色数
INT8U Get_Screen_Color_Num(void)
{
  return GET_COLOR_NUM(Screen_Para.Base_Para.Color);
/* 
  if(Screen_Para.Base_Para.Color < 3 || Screen_Para.Base_Para.Color EQ 4)
      return 1;
  else if(Screen_Para.Base_Para.Color EQ 3 || Screen_Para.Base_Para.Color EQ 5 || Screen_Para.Base_Para.Color EQ 6)
      return 2;
  else if(Screen_Para.Base_Para.Color EQ 7)
      return 3;
  else
      return 0;
*/
#if 0
    if(Screen_Para.Base_Para.Color < 3)// || Screen_Para.Base_Para.Color EQ 4)
        return 1;
    else if(Screen_Para.Base_Para.Color EQ 3)// || Screen_Para.Base_Para.Color EQ 5 || Screen_Para.Base_Para.Color EQ 6)
        return 2;
    else
        return 0;
#endif    
}

//获取不同显示参数的长度
INT8U Get_Show_Para_Len(INT8U Type)
{
  if(Type EQ SHOW_PIC)
    return sizeof(S_Pic_Para) - CHK_BYTE_LEN;
#if TXT_SHOW_EN
  else if(Type EQ SHOW_TXT)
    return sizeof(S_Txt_Para) - CHK_BYTE_LEN;
#endif
#if CLOCK_EN
#if CLOCK_SHOW_EN
  else if(Type EQ SHOW_CLOCK)
    return sizeof(S_Clock_Para) - CHK_BYTE_LEN;
#endif
#if TIME_SHOW_EN
  else if(Type EQ SHOW_TIME)
    return sizeof(S_Time_Para) - CHK_BYTE_LEN;
#endif
#if TIMER_SHOW_EN
  else if(Type EQ SHOW_TIMER)
    return sizeof(S_Timer_Para) - CHK_BYTE_LEN;
#endif
#if LUN_SHOW_EN
  else if(Type EQ SHOW_LUN)
    return sizeof(S_Lun_Para) - CHK_BYTE_LEN;
#endif
#endif
#if TEMP_SHOW_EN
  else if(Type EQ SHOW_TEMP)
    return sizeof(S_Temp_Para) - CHK_BYTE_LEN;
#endif
#if HUMIDITY_SHOW_EN
  else if(Type EQ SHOW_HUMIDITY)
    return sizeof(S_Humidity_Para) - CHK_BYTE_LEN;
#endif
#if NOISE_SHOW_EN
  else if(Type EQ SHOW_NOISE)
    return sizeof(S_Noise_Para) - CHK_BYTE_LEN;
#endif
  else
  {
    ASSERT_FAILED();
    return 0;
  }
  
}


void Set_File_Para_HT_Sum(U_File_Para *pPara)
{
    switch(pPara->Pic_Para.Flag)
    {
#if PIC_SHOW_EN      
    case SHOW_PIC:
     SET_HT((*pPara).Pic_Para);
     SET_SUM((*pPara).Pic_Para);
     break;
#endif
#if TXT_SHOW_EN
    case SHOW_TXT:
     SET_HT((*pPara).Txt_Para);
     SET_SUM((*pPara).Txt_Para);
     break;
#endif
#if CLOCK_SHOW_EN     
    case SHOW_CLOCK:
     SET_HT((*pPara).Clock_Para);
     SET_SUM((*pPara).Clock_Para);
     break;
#endif
#if TIME_SHOW_EN     
    case SHOW_TIME:
     SET_HT((*pPara).Time_Para);
     SET_SUM((*pPara).Time_Para);
     break;
#endif
#if TIMER_SHOW_EN     
    case SHOW_TIMER:
     SET_HT((*pPara).Timer_Para);
     SET_SUM((*pPara).Timer_Para);
     break;
#endif
#if TEMP_SHOW_EN     
    case SHOW_TEMP:
     SET_HT((*pPara).Temp_Para);
     SET_SUM((*pPara).Temp_Para);
     break;
#endif
#if LUN_SHOW_EN     
    case SHOW_LUN:
     SET_HT((*pPara).Lun_Para);
     SET_SUM((*pPara).Lun_Para);
     break;
#endif
#if HUMIDITY_SHOW_EN     
    case SHOW_HUMIDITY:
     SET_HT((*pPara).Humidity_Para);
     SET_SUM((*pPara).Humidity_Para);
     break;
#endif
#if NOISE_SHOW_EN     
    case SHOW_NOISE:
     SET_HT((*pPara).Noise_Para);
     SET_SUM((*pPara).Noise_Para);
     break;
#endif
#if PIC_SHOW_EN     
    case SHOW_NULL:
     SET_HT((*pPara).Pic_Para);
     SET_SUM((*pPara).Pic_Para);
     break;
#endif     
    default:
     ASSERT_FAILED();
     break;
    }

}

INT8U Chk_File_Para_HT_Sum(U_File_Para *pPara)
{
    INT8U Re = 1;

    switch(pPara->Pic_Para.Flag)
    {
#if PIC_SHOW_EN
    case SHOW_PIC:
     Re &= CHK_HT((*pPara).Pic_Para);
     Re &= CHK_SUM((*pPara).Pic_Para);
     break;
#endif
#if TXT_SHOW_EN
    case SHOW_TXT:
     Re &= CHK_HT((*pPara).Txt_Para);
     Re &= CHK_SUM((*pPara).Txt_Para);
     break;
#endif
#if CLOCK_SHOW_EN
    case SHOW_CLOCK:
     Re &= CHK_HT((*pPara).Clock_Para);
     Re &= CHK_SUM((*pPara).Clock_Para);
     break;
#endif
#if TIME_SHOW_EN
    case SHOW_TIME:
     Re &= CHK_HT((*pPara).Time_Para);
     Re &= CHK_SUM((*pPara).Time_Para);
     break;
#endif
#if TIMER_SHOW_EN
    case SHOW_TIMER:
     Re &= CHK_HT((*pPara).Timer_Para);
     Re &= CHK_SUM((*pPara).Timer_Para);
     break;
#endif
#if TEMP_SHOW_EN
    case SHOW_TEMP:
     Re &= CHK_HT((*pPara).Temp_Para);
     Re &= CHK_SUM((*pPara).Temp_Para);
     break;
#endif
#if LUN_SHOW_EN
    case SHOW_LUN:
     Re &= CHK_HT((*pPara).Lun_Para);
     Re &= CHK_SUM((*pPara).Lun_Para);
     break;
#endif
#if HUMIDITY_SHOW_EN
    case SHOW_HUMIDITY:
     Re &= CHK_HT((*pPara).Humidity_Para);
     Re &= CHK_SUM((*pPara).Humidity_Para);
     break;
#endif
#if NOISE_SHOW_EN
    case SHOW_NOISE:
     Re &= CHK_HT((*pPara).Noise_Para);
     Re &= CHK_SUM((*pPara).Noise_Para);
     break;
#endif
#if PIC_SHOW_EN
    case SHOW_NULL:
     Re &= CHK_HT((*pPara).Pic_Para);
     Re &= CHK_SUM((*pPara).Pic_Para);
     break;
#endif
    default:
     ASSERT_FAILED();
     Re = 0;
     break;
    }

    return Re;
}

//写入节目个数
INT8U Write_Prog_Num(void)
{
  //INT8U Prog_No = Prog_Para.Prog_No;
  Write_Storage_Data(SDI_PROG_NUM , &Prog_Num.Num, sizeof(Prog_Num.Num));
  
#ifdef SDI_SCREEN_PARA_BK0 
  Write_Storage_Data(SDI_PROG_NUM_BK0, &Prog_Num.Num, sizeof(Prog_Num.Num));
#endif

#ifdef SDI_SCREEN_PARA_BK1 
  Write_Storage_Data(SDI_PROG_NUM_BK1, &Prog_Num.Num, sizeof(Prog_Num.Num));
#endif  
 
  return 1;

}

//读取节目个数
INT8U Read_Prog_Num(void)
{
    INT16U Len;

    Len = Read_Storage_Data(SDI_PROG_NUM,  &Prog_Num.Num, &Prog_Num.Num, sizeof(Prog_Num.Num));
  #ifdef SDI_PROG_NUM_BK0
    if(Len EQ 0)
      Len = Read_Storage_Data(SDI_PROG_NUM_BK0,  &Prog_Num.Num, &Prog_Num.Num, sizeof(Prog_Num.Num));
  #endif

  #ifdef SDI_PROG_NUM_BK1
    if(Len EQ 0)
      Len = Read_Storage_Data(SDI_PROG_NUM_BK1,  &Prog_Num.Num, &Prog_Num.Num, sizeof(Prog_Num.Num));
  #endif

    if(Len EQ 0)
	  Prog_Num.Num = 0;

	SET_SUM(Prog_Num);
	return Len;
}

//写函数保留下来--D型卡需要不带网口的需要这个，焊接上网口部分就不需要重新设置mac地址了
void Write_ETH_Mac_Para(void)
{
  //INT8U Prog_No = Prog_Para.Prog_No;
  Write_Storage_Data(SDI_MAC_PARA , ETH_Mac_Para.Mac, sizeof(ETH_Mac_Para.Mac));
  
#ifdef SDI_MAC_PARA_BK0 
  Write_Storage_Data(SDI_MAC_PARA_BK0, ETH_Mac_Para.Mac, sizeof(ETH_Mac_Para.Mac));
#endif

#ifdef SDI_MAC_PARA_BK1 
  Write_Storage_Data(SDI_MAC_PARA_BK1, ETH_Mac_Para.Mac, sizeof(ETH_Mac_Para.Mac));
#endif  

#ifdef SDI_MAC_PARA_BK2 
  Write_Storage_Data(SDI_MAC_PARA_BK2, ETH_Mac_Para.Mac, sizeof(ETH_Mac_Para.Mac));
#endif 
  
  return;
}

#if NET_EN
//读取屏幕的mac地址
INT8U Read_ETH_Mac_Para(void)
{
    INT16U Len;
	//INT8U Temp;

    Len = Read_Storage_Data(SDI_MAC_PARA,  ETH_Mac_Para.Mac, ETH_Mac_Para.Mac, sizeof(ETH_Mac_Para.Mac));
  #ifdef SDI_MAC_PARA_BK0
    if(Len EQ 0)
      Len = Read_Storage_Data(SDI_MAC_PARA_BK0,  ETH_Mac_Para.Mac, ETH_Mac_Para.Mac, sizeof(ETH_Mac_Para.Mac));
  #endif

  #ifdef SDI_MAC_PARA_BK1
    if(Len EQ 0)
      Len = Read_Storage_Data(SDI_MAC_PARA_BK1,  ETH_Mac_Para.Mac, ETH_Mac_Para.Mac, sizeof(ETH_Mac_Para.Mac));
  #endif

  #ifdef SDI_MAC_PARA_BK2
    if(Len EQ 0)
      Len = Read_Storage_Data(SDI_MAC_PARA_BK2,  ETH_Mac_Para.Mac, ETH_Mac_Para.Mac, sizeof(ETH_Mac_Para.Mac));
  #endif

  if(Len EQ 0)
  {
	Make_Mac_Para(ETH_Mac_Para.Mac);
	Len = sizeof(ETH_Mac_Para.Mac);
  }

  SET_HT(ETH_Mac_Para);
  SET_SUM(ETH_Mac_Para);
  return Len;

}

#endif

//保存参数帧处理
INT8U _Write_Screen_Para(INT8U *pSrc, INT16U SrcLen)
{
  //INT8U Prog_No = Prog_Para.Prog_No;
  Write_Storage_Data(SDI_SCREEN_PARA , pSrc, SrcLen);
  
#ifdef SDI_SCREEN_PARA_BK0 
  Write_Storage_Data(SDI_SCREEN_PARA_BK0, pSrc, SrcLen);
#endif

#ifdef SDI_SCREEN_PARA_BK1 
  Write_Storage_Data(SDI_SCREEN_PARA_BK1, pSrc, SrcLen);
#endif  
  
  
#ifdef SDI_SCREEN_PARA_BK2 
  Write_Storage_Data(SDI_SCREEN_PARA_BK2, pSrc, SrcLen);
#endif 
  
  return 1;
}

//写屏幕参数
INT8U Write_Screen_Para(void)
{
  return _Write_Screen_Para(&Screen_Para.Head + 1, SCREEN_PARA_LEN);
}

INT16U _Read_Screen_Para(INT8U *pDst, INT8U *pDst_Start, INT16U DstLen)
{
    INT16U Len;

    Len = Read_Storage_Data(SDI_SCREEN_PARA,  pDst, pDst_Start, DstLen);
  #ifdef SDI_SCREEN_PARA_BK0
    if(Len EQ 0)
      Len = Read_Storage_Data(SDI_SCREEN_PARA_BK0,  pDst, pDst_Start, DstLen);
  #endif

  #ifdef SDI_SCREEN_PARA_BK1
    if(Len EQ 0)
      Len = Read_Storage_Data(SDI_SCREEN_PARA_BK1,  pDst, pDst_Start, DstLen);
  #endif

   #ifdef SDI_SCREEN_PARA_BK2
    if(Len EQ 0)
      Len = Read_Storage_Data(SDI_SCREEN_PARA_BK2,  pDst, pDst_Start, DstLen);
  #endif
 /*
    if(Len EQ 0)
    {
        Len = Get_Storage_Data_Len(SDI_SCREEN_PARA);
        mem_set(pDst, 0, Len, pDst_Start, DstLen);
    }
 */
    return Len;
}

//检查数据极性参数是否发生修改
void Chk_Data_Polarity_Change(INT8U Old_Polarity)
{
#if QT_EN EQ 0
    /*
    INT16U i;

	if(Screen_Para.Scan_Para.Data_Polarity != Old_Polarity)
	{
	  for(i = 0; i < sizeof(Show_Data.Color_Data); i ++)
	    Show_Data.Color_Data[i] = ~Show_Data.Color_Data[i];
	}
        */
#endif
}

//检查波特率参数是否发生修改
void Chk_Baud_Change(INT8U Old_Baud)
{
#if QT_EN EQ 0
  if(Old_Baud != Screen_Para.COM_Para.Baud)
  {
    Delay_ms(5);
    UART1_Init(); //重新初始化通信端口
  }
#endif
}

//读取屏幕参数
INT16U Read_Screen_Para(void)
{
    INT16U Len;
	INT8U Data_Polarity;

    Data_Polarity = Screen_Para.Scan_Para.Data_Polarity;

    Len = _Read_Screen_Para(&Screen_Para.Head + 1, &Screen_Para.Head, sizeof(Screen_Para));
	if(Len EQ 0)
	{
	  memset(&Screen_Para, 0, sizeof(Screen_Para));
#if NET_EN
	  Screen_Para.ETH_Para.IP = 0xFB01A8C0; //192.168.1.251
	  Screen_Para.ETH_Para.Gate = 0x0101A8C0; //192.168.1.1
	  Screen_Para.ETH_Para.Mask = 0x00FFFFFF; //255.255.255.0
#endif
	}

	Chk_Data_Polarity_Change(Data_Polarity); //检查数据极性是否发生修改

	SET_HT(Screen_Para);
	SET_SUM(Screen_Para);

	return Len;
}

//保存节目属性帧
INT8U Write_Prog_Para(INT8U Prog_No, INT8U *pSrc,INT16U SrcLen)
{

  Write_Storage_Data(SDI_PROG_PARA + Prog_No , pSrc, SrcLen);
  
#ifdef SDI_PROG_PARA_BK0 
  Write_Storage_Data(SDI_PROG_PARA_BK0 + Prog_No, pSrc, SrcLen);
#endif

#ifdef SDI_PROG_PARA_BK1 
  Write_Storage_Data(SDI_PROG_PARA_BK1 + Prog_No, pSrc, SrcLen);
#endif  
    
#ifdef SDI_PROG_PARA_BK2 
  Write_Storage_Data(SDI_PROG_PARA_BK2 + Prog_No, pSrc, SrcLen);
#endif

  //读出这个节目的存储索引
  //Prog_Status.Play_Status.Prog_No = Prog_No;
  //Read_Prog_Block_Index(Prog_No);
  return 1;
}
/*
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
*/

/*
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
  
  Len = _Read_Prog_Block_Index(Prog_No, (void *)Prog_Status.Block_Index.Index, (void *)&Prog_Status.Block_Index, sizeof(Prog_Status.Block_Index));
  
  if(Len EQ 0)
  {
      memset((void *)Prog_Status.Block_Index.Index, 0, sizeof(Prog_Status.Block_Index.Index));
  }

  SET_HT(Prog_Status.Block_Index);
  SET_SUM(Prog_Status.Block_Index);
  return Len;
}

INT8U _Write_Prog_Block_Index(INT8U Prog_No, void *pSrc, INT16U SrcLen)
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


INT8U Write_Prog_Block_Index(void)
{
  return _Write_Prog_Block_Index(Prog_Status.Play_Status.Prog_No, (INT8U *)&Prog_Status.Block_Index.Head + 1, BLOCK_INDEX_LEN);
}
*/
INT16U Read_File_Para_Index(INT8U Prog_No, INT8U *pDst, INT16U DstLen)
{
  INT16U Len;

  if(DstLen < FILE_PARA_INDEX_LEN)
  {
     ASSERT_FAILED();
     return 0;
  }

  Len = Read_Storage_Data(SDI_FILE_PARA_INDEX + Prog_No, pDst, pDst, DstLen);

#ifdef SDI_FILE_PARA_INDEX_BK0
  if(Len EQ 0)
    Len = Read_Storage_Data(SDI_FILE_PARA_INDEX_BK0 + Prog_No, pDst, pDst, DstLen);
#endif

  if(Len EQ 0)
  {
      memset(pDst, 0, FILE_PARA_INDEX_LEN);
  }

  return FILE_PARA_INDEX_LEN;
}

INT8U Write_File_Para_Index(INT8U Prog_No, INT8U *pSrc)
{
    INT8U Re = 1;

    Re &= Write_Storage_Data(SDI_FILE_PARA_INDEX + Prog_No, pSrc, FILE_PARA_INDEX_LEN);
    
#ifdef SDI_FILE_PARA_INDEX_BK0
    Re &= Write_Storage_Data(SDI_FILE_PARA_INDEX_BK0 + Prog_No, pSrc, FILE_PARA_INDEX_LEN);
#endif
	
	return Re;
}

//读取文件参数
INT16U Read_File_Para(INT8U Prog_No, INT8U Area_No, INT8U File_No, void *pDst, void *pDst_Start, INT16U DstLen)
{
  STORA_DI SDI;
  INT16U Len;
  INT16U i;
  S_File_Para_Index *p;

  Read_File_Para_Index(Prog_No, Pub_Buf, sizeof(Pub_Buf));
  p = (S_File_Para_Index *)Pub_Buf;

  for(i = 0; i < MAX_FILE_NUM; i ++)
  {
    if(p->Area_No[i] EQ (0x80 | Area_No) &&\
       p->File_No[i] EQ File_No) //找到没有使用的存储位置
        break;
  }

  if(i EQ MAX_FILE_NUM)
      return 0;

  SDI = SDI_FILE_PARA + (INT16U)Prog_No *  MAX_FILE_NUM + i;//(INT16U)Area_No * MAX_FILE_NUM + File_No;
  Len = Read_Storage_Data(SDI, Pub_Buf, Pub_Buf, sizeof(Pub_Buf));
  
#ifdef SDI_FILE_PARA_BK0
  if(Len EQ 0)
  {
    SDI = SDI_FILE_PARA_BK0 + (INT16U)Prog_No * MAX_FILE_NUM + i;//(INT16U)Area_No * MAX_FILE_NUM + File_No;
    Len = Read_Storage_Data(SDI, Pub_Buf, Pub_Buf, sizeof(Pub_Buf));
  }
#endif
  
#ifdef SDI_FILE_PARA_BK1
  if(Len EQ 0)
  {
    SDI = SDI_FILE_PARA_BK1 + (INT16U)Prog_No * MAX_FILE_NUM + i;//(INT16U)Area_No * MAX_FILE_NUM + File_No;
    Len = Read_Storage_Data(SDI, Pub_Buf, Pub_Buf, sizeof(Pub_Buf));
  }
#endif 
/*
  if(Len EQ 0)
  {
    Len = Get_Storage_Data_Len(SDI_FILE_PARA);
    mem_set(pDst, 0, Len, pDst_Start, DstLen);
  }
*/
  if(Len > 0)
  {

  }
  return Len;

}

//写文件参数
INT8U Write_File_Para(INT8U Prog_No, INT8U Area_No, INT8U File_No, void *pSrc, INT16U SrcLen)
{
  STORA_DI SDI;
  INT8U Re = 1;
  INT16U i;
  S_File_Para_Index *p;

  Read_File_Para_Index(Prog_No, Pub_Buf, sizeof(Pub_Buf));
  p = (S_File_Para_Index *)Pub_Buf;

  for(i = 0; i < MAX_FILE_NUM; i ++)
  {
    if((p->Area_No[i] & 0x80) EQ 0) //找到没有使用的存储位置
        break;
  }

  if(i EQ MAX_FILE_NUM)
      return 0;

  p->Area_No[i] = Area_No | 0x80;
  p->File_No[i] = File_No;

  SDI = SDI_FILE_PARA + (INT16U)Prog_No * MAX_FILE_NUM + i;//(INT16U)Area_No * MAX_FILE_NUM + File_No;
  Re &=  Write_Storage_Data(SDI, pSrc, FILE_PARA_LEN); 
  
#ifdef SDI_FILE_PARA_BK0
  SDI = SDI_FILE_PARA_BK0 + (INT16U)Prog_No * MAX_FILE_NUM + i;//(INT16U)Area_No * MAX_FILE_NUM + File_No;
  Re &=  Write_Storage_Data(SDI, pSrc, FILE_PARA_LEN);   
#endif
  
#ifdef SDI_FILE_PARA_BK1
  SDI = SDI_FILE_PARA_BK1 + (INT16U)Prog_No * MAX_FILE_NUM + i;//(INT16U)Area_No * MAX_FILE_NUM + File_No;
  Re &=  Write_Storage_Data(SDI, pSrc, FILE_PARA_LEN);   
#endif 

  if(Re)
  {
      Write_File_Para_Index(Prog_No, Pub_Buf);
  }
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
  
  if(Len EQ 0)
  {
      Len = Get_Storage_Data_Len(SDI_CUR_BLOCK_INDEX);
      OS_memset(pDst, 0, Len, pDst_Start, DstLen);
  }

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


/*
//读取当前节目的分区Area_No的第File_No文件的第SIndex屏的显示数据
INT16S Read_Show_Data(INT8U Area_No, INT8U File_No, INT8U Flag, INT16U SIndex, \
                      S_Show_Data *pShow_Data, INT16U *pX, INT16U *pY, INT16U *pWidth, INT6U *pHeight)
{
  INT16U Width,Height,X,Y;
  INT32U Offset;
  INT16U Len,DstLen,Index;
  //S_Point Point;
   
#if PIC_SHOW_EN 
  if(Flag EQ SHOW_PIC) //图文
  {
     
    Width = Get_Area_Width(Area_No);
    Height = Get_Area_Height(Area_No);
   
    DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
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
    
    DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
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
    
    DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
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
    
    DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
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
    
    DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
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
    
    DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
    DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

    Index = Prog_Status.Block_Index.Index[Area_No][File_No];
    Offset = 0;
    X = Prog_Status.File_Para[Area_No].Temp_Para.Text_X;
    Y = Prog_Status.File_Para[Area_No].Temp_Para.Text_Y;    
  }
#endif
#if HUMIDITY_SHOW_EN
    else if(Flag EQ SHOW_HUMIDITY) //湿度
    {
        Width = Prog_Status.File_Para[Area_No].Humidity_Para.Text_Width;
        Height = Prog_Status.File_Para[Area_No].Humidity_Para.Text_Height;

        DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
        DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

        Index = Prog_Status.Block_Index.Index[Area_No][File_No];
        Offset = 0;
        X = Prog_Status.File_Para[Area_No].Humidity_Para.Text_X;
        Y = Prog_Status.File_Para[Area_No].Humidity_Para.Text_Y;
    }
#endif
#if NOISE_SHOW_EN
    else if(Flag EQ SHOW_NOISE) //噪音
    {
        Width = Prog_Status.File_Para[Area_No].Noise_Para.Text_Width;
        Height = Prog_Status.File_Para[Area_No].Noise_Para.Text_Height;

        DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
        DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

        Index = Prog_Status.Block_Index.Index[Area_No][File_No];
        Offset = 0;
        X = Prog_Status.File_Para[Area_No].Noise_Para.Text_X;
        Y = Prog_Status.File_Para[Area_No].Noise_Para.Text_Y;
    }
#endif
  else
  {
    ASSERT_FAILED();
    return 0;
  }
  
  //OS_Mutex_Pend(PUB_BUF_MUTEX_ID);
  
  Len = 0;
  while(Len < DstLen)
  {
    if(Read_Storage_Data(SDI_SHOW_DATA + Index, Pub_Buf, Pub_Buf, sizeof(Pub_Buf)) EQ 0)
      return -1;
    
    if(Check_Prog_Show_Data(Prog_Para.Prog_No, Area_No, File_No, Pub_Buf) EQ 0)
    {
      ASSERT_FAILED();
      return -1;
    }
    //复制数据
    //Len0 = 0;
    mem_cpy(Pub_Buf, Pub_Buf + BLOCK_HEAD_DATA_LEN + Offset, BLOCK_SHOW_DATA_LEN - Offset, Pub_Buf, sizeof(Pub_Buf));
    //将读到的数据复制到显示备份区
    
    Len += Copy_Show_Data(Pub_Buf, Len, BLOCK_SHOW_DATA_LEN - Offset,\
                           pShow_Data, Area_No, X, Y, Width, Height);
    Index++;
    Offset = 0;
  }
  
  *pX =X;
  *pY =Y;
  *pWidth =Width;
  *pHeight = Height;
  return Len;
  
}
*/
INT16S Read_Show_Data_Point(INT8U Area_No, INT8U File_No, U_File_Para *pFile_Para, INT16U SIndex, \
                              S_Show_Data *pShow_Data, INT16U X, INT16U Y)
{
    INT16U Width,Height,Bk_X;//,Bk_Y;
    INT32U Offset;
    INT16U Len,DstLen,Index;
    INT8U Flag, Screen_Color_Num;
    INT8U Border_Height = 0;
    INT8U Re, i;

    Flag = pFile_Para->Pic_Para.Flag;
    Index = pFile_Para->Pic_Para.Data_Index;

    if(pFile_Para->Pic_Para.Border_Check > 0)
    {
      Border_Height = Get_Area_Border_Height(Area_No);//Get_Simple_Border_Height(Prog_Status.File_Para[Area_No].Pic_Para.Border_Type);
    }

    Screen_Color_Num = Get_Screen_Color_Num();
    Bk_X = X;
    //Bk_Y = Y;

 // #if PIC_SHOW_EN
    if(Flag EQ SHOW_PIC) //图文
    {

      Width = Get_Area_Width(Area_No);
      Height = Get_Area_Height(Area_No);

      Width = Width - 2*Border_Height;
      Height = Height - 2*Border_Height;

      DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
      DstLen = DstLen * Screen_Color_Num; //屏幕支持的颜色数//每屏的字节数

      Index += (DstLen * SIndex + GET_POINT_INDEX(Width, X, Y)/8*Screen_Color_Num) / BLOCK_SHOW_DATA_LEN;//块偏移
      //Index += Prog_Status.Block_Index.Index[Area_No][File_No]; //起始块号

      Offset = (DstLen * SIndex + GET_POINT_INDEX(Width, X, Y)/8*Screen_Color_Num) % BLOCK_SHOW_DATA_LEN; //在该块中的索引
      X += Border_Height;
      Y += Border_Height;

    Len = Screen_Color_Num;
    //INT8U temp[500];
    //Read_Storage_Data(SDI_SHOW_DATA + Index,temp, temp, sizeof(temp));
    //memcpy(temp, temp + BLOCK_HEAD_DATA_LEN, BLOCK_SHOW_DATA_LEN);
    //Read_Storage_Data_NoCS(SDI_SHOW_DATA + Index, BLOCK_HEAD_DATA_LEN +  Offset, BLOCK_SHOW_DATA_LEN,  Pub_Buf, Pub_Buf, sizeof(Pub_Buf));
    if(Read_Storage_Data_NoCS(SDI_SHOW_DATA + Index, BLOCK_HEAD_DATA_LEN +  Offset,  Len, \
                              Pub_Buf, Pub_Buf, sizeof(Pub_Buf)) EQ 0)
        return -1;

    //pSrc = Pub_Buf;
    i = Bk_X % 8;

    while(i < 8 && (X + i - (Bk_X % 8)) < (Width + Border_Height))
    {
        if(Screen_Color_Num EQ 1)  //单色屏
          Re = GET_BIT(Pub_Buf[0], i);
        else if(Screen_Color_Num EQ 2) //双色屏
          Re = GET_BIT(Pub_Buf[0], i) +\
            ( GET_BIT(Pub_Buf[1], i)<<1);
        else if(Screen_Color_Num EQ 3) //三色屏
          Re =  GET_BIT(Pub_Buf[0], i) +\
             ( GET_BIT(Pub_Buf[1], i)<<1)+\
             ( GET_BIT(Pub_Buf[2], i)<<2);
	    else
		  Re = 0;

        Set_Area_Point_Data(pShow_Data, Area_No, X + i - (Bk_X % 8), Y, Re);
        i++;

        //if(HV_Flag EQ 0)
          //  break;
    }
  }
#if SHOW_TXT
  else if(Flag EQ SHOW_TXT)
  {
    Read_Txt_Show_Chr_Data(SDI_SHOW_DATA + Index, Pub_Buf, sizeof(Pub_Buf));

    Read_Txt_Show_Data(pShow_Data, Area_No, pFile_Para, Pub_Buf + 9, sizeof(Pub_Buf) - 9, SIndex, 1, X, Y);

    return 1;
  }
#endif
  else
  {
    ASSERT_FAILED();
    return 0;
  }
	return 1;
    /*

    Copy_Show_Data(Pub_Buf, GET_POINT_INDEX(Width, Bk_X, Bk_Y)*Screen_Color_Num/8, Len,\
                   pShow_Data, Area_No, X, Y, Width, Height);
                   */

    //Offset = Screen_Color_Num * GET_POINT_INDEX(Screen_Para.Base_Para.Width, Prog_Para.Area[Area_No].X + X, Prog_Para.Area[Area_No].Y + Y);
    //mem_cpy((INT8U *)pShow_Data->Color_Data + Offset, Pub_Buf, Screen_Color_Num, (INT8U *)pShow_Data->Color_Data, sizeof(pShow_Data->Color_Data));
}

//读取当前节目的分区Area_No的第File_No文件的第SIndex屏的显示数据
INT16S Read_Show_Data(INT8U Area_No, INT8U File_No, U_File_Para *pFile_Para, INT16U SIndex, \
                      S_Show_Data *pShow_Data, INT16U *pX, INT16U *pY, INT16U *pWidth, INT16U *pHeight)
{
  INT16U Width,Height,X,Y;
  INT32U Offset;
  INT16U Len,DstLen,Index;
  INT8U Flag;
  INT8U Border_Height = 0;
  
  Flag = pFile_Para->Pic_Para.Flag;
  Index = pFile_Para->Pic_Para.Data_Index;

  if(pFile_Para->Pic_Para.Border_Check > 0)
  {
    Border_Height = Get_Area_Border_Height(Area_No);//Get_Simple_Border_Height(Prog_Status.File_Para[Area_No].Pic_Para.Border_Type);
  }

#if PIC_SHOW_EN 
  if(Flag EQ SHOW_PIC) //图文
  {
     
    Width = Get_Area_Width(Area_No);
    Height = Get_Area_Height(Area_No);

    Width = Width - 2*Border_Height;
    Height = Height - 2*Border_Height;
   
    DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
    DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数
    
    Index += (DstLen * SIndex) / BLOCK_SHOW_DATA_LEN;//块偏移
    //Index += Prog_Status.Block_Index.Index[Area_No][File_No]; //起始块号
      
    Offset = (DstLen * SIndex) % BLOCK_SHOW_DATA_LEN; //在该块中的索引
    X = Border_Height;
    Y = Border_Height;
  }  
#endif
#if TXT_SHOW_EN
  else if(Flag EQ SHOW_TXT) //内码
  {
    //读取Txt内码
    //if(Read_Storage_Data(SDI_SHOW_DATA + Index, Pub_Buf, Pub_Buf, sizeof(Pub_Buf)) == 0)
        //memset(Pub_Buf, 0, sizeof(Pub_Buf));
    Read_Txt_Show_Chr_Data(SDI_SHOW_DATA + Index, Pub_Buf, sizeof(Pub_Buf));
    //读取第SIndex屏
    Read_Txt_Show_Data(pShow_Data, Area_No, pFile_Para, Pub_Buf + 9, sizeof(Pub_Buf) - 9, SIndex, 0, 0, 0);

    return 1;
  }
#endif
#if CLOCK_SHOW_EN  
  else if(Flag EQ SHOW_CLOCK) //表盘
  {
    Width = pFile_Para->Clock_Para.Text_Width;
    Height = pFile_Para->Clock_Para.Text_Height;
    
    DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
    DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

    //Index = Prog_Status.Block_Index.Index[Area_No][File_No];
    Offset = 0;
    X = pFile_Para->Clock_Para.Text_X;
    Y = pFile_Para->Clock_Para.Text_Y;

    Update_Clock_Point(&Show_Data_Bak, Area_No); //表盘的点也作为背景
  }
#endif
#if TIMER_SHOW_EN  
  else if(Flag EQ SHOW_TIMER) //计时
  {
    Width = pFile_Para->Timer_Para.Text_Width;
    Height = pFile_Para->Timer_Para.Text_Height;
    
    DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
    DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

    //Index = Prog_Status.Block_Index.Index[Area_No][File_No];
    Offset = 0;
    X = pFile_Para->Timer_Para.Text_X;
    Y = pFile_Para->Timer_Para.Text_Y;     
  }
#endif
#if TIME_SHOW_EN
  else if(Flag EQ SHOW_TIME) //日期时间
  {
    Width = pFile_Para->Time_Para.Text_Width;
    Height = pFile_Para->Time_Para.Text_Height;
    
    DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
    DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

    //Index = Prog_Status.Block_Index.Index[Area_No][File_No];
    Offset = 0;
    X = pFile_Para->Time_Para.Text_X;
    Y = pFile_Para->Time_Para.Text_Y;     
  }
#endif
#if LUN_SHOW_EN  
  else if(Flag EQ SHOW_LUN) //农历
  {
    Width = pFile_Para->Lun_Para.Text_Width;
    Height = pFile_Para->Lun_Para.Text_Height;
    
    DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
    DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

    //Index = Prog_Status.Block_Index.Index[Area_No][File_No];
    Offset = 0;
    X = pFile_Para->Lun_Para.Text_X;
    Y = pFile_Para->Lun_Para.Text_Y;    
  }
#endif
#if TEMP_SHOW_EN  
  else if(Flag EQ SHOW_TEMP) //温度
  {
    Width = pFile_Para->Temp_Para.Text_Width;
    Height = pFile_Para->Temp_Para.Text_Height;
    
    DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
    DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

    //Index = Prog_Status.Block_Index.Index[Area_No][File_No];
    Offset = 0;
    X = pFile_Para->Temp_Para.Text_X;
    Y = pFile_Para->Temp_Para.Text_Y;    
  }
#endif
#if HUMIDITY_SHOW_EN
    else if(Flag EQ SHOW_HUMIDITY) //湿度
    {
        Width = pFile_Para->Humidity_Para.Text_Width;
        Height = pFile_Para->Humidity_Para.Text_Height;

        DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
        DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

        //Index = Prog_Status.Block_Index.Index[Area_No][File_No];
        Offset = 0;
        X = pFile_Para->Humidity_Para.Text_X;
        Y = pFile_Para->Humidity_Para.Text_Y;
    }
#endif
#if NOISE_SHOW_EN
    else if(Flag EQ SHOW_NOISE) //噪音
    {
        Width = pFile_Para->Noise_Para.Text_Width;
        Height = pFile_Para->Noise_Para.Text_Height;

        DstLen = GET_TEXT_LEN(Width,Height);//(INT32U)Width * ((Height % 8) EQ 0 ? (Height / 8) : (Height / 8 + 1));
        DstLen = DstLen * Get_Screen_Color_Num(); //屏幕支持的颜色数//每屏的字节数

        //Index = Prog_Status.Block_Index.Index[Area_No][File_No];
        Offset = 0;
        X = pFile_Para->Noise_Para.Text_X;
        Y = pFile_Para->Noise_Para.Text_Y;
    }
#endif
  else
  {
    ASSERT_FAILED();
    return 0;
  }

  //X = X + Border_Height;
  //Y = Y + Border_Height;
  //OS_Mutex_Pend(PUB_BUF_MUTEX_ID);
  
  Len = 0;
  while(Len < DstLen)
  {
    if(Read_Storage_Data(SDI_SHOW_DATA + Index, Pub_Buf, Pub_Buf, sizeof(Pub_Buf)) EQ 0)
      return -1;
    
    if(Check_Prog_Show_Data(Prog_Para.Prog_No, Area_No, File_No, Pub_Buf) EQ 0)
    {
      ASSERT_FAILED();
      return -1;
    }
    //复制数据
    //Len0 = 0;
    mem_cpy(Pub_Buf, Pub_Buf + BLOCK_HEAD_DATA_LEN + Offset, BLOCK_SHOW_DATA_LEN - Offset, Pub_Buf, sizeof(Pub_Buf));
    //将读到的数据复制到显示备份区
    
    Len += Copy_Show_Data(Pub_Buf, Len, BLOCK_SHOW_DATA_LEN - Offset,\
                           pShow_Data, Area_No, X, Y, Width, Height);
    Index++;
    Offset = 0;
  }
  
  *pX =X;
  *pY =Y;
  *pWidth =Width;
  *pHeight = Height;
  return Len;
  
}

//删除某个节目的所有显示数据
void Clr_Prog_Show_Data(INT8U Prog_No)
{
  
  
}

//清除所有的显示数据
void Clr_All_Show_Data(void)
{
  memset(Show_Data.Color_Data, 0x00, sizeof(Show_Data.Color_Data));
  memset(Show_Data_Bak.Color_Data, 0x00, sizeof(Show_Data_Bak.Color_Data));
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

//删除节目数据
INT8U Del_Prog_Data(INT8U Frame[], INT16U FrameLen)
{
  return 1;
}


INT16U _Read_Prog_Para(INT8U Prog_No, INT8U *pDst, INT8U *pDst_Start, INT16U DstLen)
{
  INT16U Len;
  
  Len = Read_Storage_Data(SDI_PROG_PARA + Prog_No, pDst, pDst_Start, DstLen);

#ifdef SDI_PROG_PARA_BK0
  if(Len EQ 0)
    Len = Read_Storage_Data(SDI_PROG_PARA_BK0 + Prog_No, pDst, pDst_Start, DstLen);
#endif

#ifdef SDI_PROG_PARA_BK1
  if(Len EQ 0)
    Len = Read_Storage_Data(SDI_PROG_PARA_BK1 + Prog_No, pDst, pDst_Start, DstLen);
#endif 

  return Len;
}

//读取节目参数
//Prog节目号
//返回值1 表示读取成功。0表示没有这个节目或者读取不成功
INT16U Read_Prog_Para(INT8U Prog_No, void *pDst, void *pDst_Start, INT16U DstLen)
{
  INT16U Len;

  //memset(Pub_Buf, 0, sizeof(Pub_Buf));
  //Len = _Read_Prog_Para(SDI_PROG_PARA + Prog_No, (INT8U *)&(pProg_Para->Prog_No), (INT8U *)pProg_Para, sizeof(S_Prog_Para));
  Len = _Read_Prog_Para(SDI_PROG_PARA + Prog_No, (INT8U *)pDst, (INT8U *)pDst_Start, DstLen);

  if(Len > 0)
  {


  }
  else
  {
    OS_memset(pDst, 0, PROG_PARA_LEN, pDst_Start, DstLen);
  }

  //SET_HT((*pProg_Para));
  //SET_SUM((*pProg_Para));
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
void Read_Para(void)
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
