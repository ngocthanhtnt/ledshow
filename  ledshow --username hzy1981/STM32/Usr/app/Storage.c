#define STORAGE_C
#include "includes.h"
/*
typedef struct
{
  INT8U Head;
  INT8U Prog_No; //节目号
  
  INT8U Mode; //播放方式，0表示循环播放，1表示定长播放
  INT16U Counts; //循环次数
  INT32U Time; //停留秒数
  
  S_Program_Timing Timing[3];//[3]; //节目定时设置
  INT8U Area_Num; //分区数
  INT8U Main_Area_No; //主分区号
  INT8U Area_File_Num[MAX_AREA_NUM]; //每分区文件数
  S_Area Area[MAX_AREA_NUM]; //区域定义
  
  INT8U Border_Check; //是否显示边框
  INT16U Border_StayTime;
  //INT8U Border_Speed; //边框运行速度
  INT8U Border_Mode;  //边框模式
  INT8U Border_Width;   //边框宽度
  INT8U Border_Height;  //边框高度
  INT8U Temp;   //备用
//#if BORDER_SHOW_EN > 0  
  INT8U Border_Data[3*MAX_BORDER_POINTS/8]; //边框数据
//#endif  
  INT8U CS[CS_BYTES];
  
  INT8U Tail;
}S_Prog_Para;
*/

const S_Data_Para_Storage_Info Data_Para_Storage[] =
{
  //屏幕参数以及备份
  {SDI_SCREEN_PARA, SCREEN_PARA_LEN, 1},
#ifdef SDI_SCREEN_PARA_BK0 
  {SDI_SCREEN_PARA_BK0, SCREEN_PARA_LEN, 1},
#endif  
#ifdef SDI_SCREEN_PARA_BK1
  {SDI_SCREEN_PARA_BK1, SCREEN_PARA_LEN, 1},
#endif
#ifdef SDI_SCREEN_PARA_BK2
  {SDI_SCREEN_PARA_BK2, SCREEN_PARA_LEN, 1},  
#endif

  //节目参数及备份
  {SDI_PROG_PARA, PROG_PARA_LEN, MAX_PROG_NUM},
#ifdef  SDI_PROG_PARA_BK0
  {SDI_PROG_PARA_BK0, PROG_PARA_LEN, MAX_PROG_NUM},
#endif
#ifdef SDI_PROG_PARA_BK1
  {SDI_PROG_PARA_BK1, PROG_PARA_LEN, MAX_PROG_NUM},
#endif  

 //文件参数及备份
  {SDI_FILE_PARA, FILE_PARA_LEN, MAX_PROG_NUM * MAX_AREA_NUM * MAX_FILE_NUM},
#ifdef  SDI_FILE_PARA_BK0
  {SDI_FILE_PARA_BK0,  FILE_PARA_LEN, MAX_PROG_NUM * MAX_AREA_NUM * MAX_FILE_NUM},
#endif  

 //节目显示数据的存储索引
  {SDI_PROG_BLOCK_INDEX, BLOCK_INDEX_LEN, MAX_PROG_NUM}, 
#ifdef SDI_PROG_BLOCK_INDEX_BK0  
  {SDI_PROG_BLOCK_INDEX_BK0, BLOCK_INDEX_LEN, MAX_PROG_NUM}, 
#endif  
#ifdef SDI_PROG_BLOCK_INDEX_BK1  
  {SDI_PROG_BLOCK_INDEX_BK1, BLOCK_INDEX_LEN, MAX_PROG_NUM}, 
#endif  

  {SDI_CUR_BLOCK_INDEX, sizeof(S_Cur_Block_Index), 1},
#ifdef SDI_CUR_BLOCK_INDEX_BK0  
  {SDI_CUR_BLOCK_INDEX_BK0, sizeof(S_Cur_Block_Index), 1},
#endif
#ifdef SDI_CUR_BLOCK_INDEX_BK1
  {SDI_CUR_BLOCK_INDEX_BK1, sizeof(S_Cur_Block_Index), 1},
#endif                                   
                                   
  //节目显示数据
  {SDI_SHOW_DATA, BLOCK_DATA_LEN, MAX_BLOCK_NUM},

  {SDI_TEST_DATA, TEST_DATA_LEN, 1}
};

//从存储器中读取某个重要等级的数据
//Imp_Flag，表示数据的重要等级标志
//Offset, 表示数据在存储器中的偏移
//pDst，表示数据读取后的目标指针
//RD_Len，表示需要读取的数据的长度
//pDst_Start和DstLeny一起对pDst和RD_Len的范围进行约束
//返回1表示成功
INT8U Read_Data_Width_CS(INT32U Offset, void* pDst, INT16U RD_Len, void* pDst_Start, INT16U DstLen)
{
  //INT16U i;//, j;
  INT32U Sum;
  INT8U Re;

  TRACE();

  //读该逻辑存储器中的数据

      Re = Read_PHY_Mem(Offset, pDst, RD_Len, pDst_Start, DstLen);
      if(1!=Re)//ASSERT(1 EQ Re)) //确保返回正确
      {
        ASSERT_FAILED();
        return 0;
      }

      //读校验和
      Re = Read_PHY_Mem(Offset + RD_Len, &Sum, ROM_CS_BYTES, &Sum, sizeof(Sum));
      if(1!=Re)//ASSERT(1 EQ Re))
      {
        ASSERT_FAILED();
        return 0;
      }
      //检查校验和是否正确
      if(Check_Sum(pDst, RD_Len, &Sum, ROM_CS_BYTES))//校验和正确则直接返回1，否则继续读取下个LOG_MEM
        return 1;
      else
        return 0;
  //ASSERT_FAILED();
  //return 0;
}

//将某个重要标志的数据写入到存储器中
//Imp_Flag，表示数据的重要等级标志
//Offset, 表示数据在存储器中的偏移
//pSrc，表示数据的起始指针
//SrcLen，表示数据的长度
//返回1表示写成功
//返回WR_IMP_DATA_ERR表示写数据失败
INT8U Write_Data_With_CS(INT32U Offset, void* pSrc, INT16U SrcLen)
{
  //INT8U i;
  INT8U Re;
  INT32U Sum;

  TRACE();

    Set_Sum(pSrc, SrcLen, &Sum, ROM_CS_BYTES, &Sum, sizeof(Sum)); //生成校验和

    Re = Write_PHY_Mem(Offset, pSrc, SrcLen); //写数据
    if(0 EQ Re)
    {
      ASSERT_FAILED();
      return 0;
    }

    Re = Write_PHY_Mem(Offset + SrcLen, &Sum, ROM_CS_BYTES); //写校验和
    if(0 EQ Re)
    {
      ASSERT_FAILED();
      return 0;
    }
    
    return 1;
}

//获取某个存储的数据项的存储偏移，该偏移表示该数据项在同Imp_Flag数据中的存储品偏移
//也表示在逻辑存储器中的整体偏移
INT32U Get_Storage_Data_Off(STORA_DI SDI)
{
  INT16U i; 
  INT32U Offset = 0; 
  //INT8U Re;

  for(i = 0; i < S_NUM(Data_Para_Storage); i ++)
  {
    if(Data_Para_Storage[i].SDI EQ SDI)
    {
      return Offset;
    }
    else if(Data_Para_Storage[i].Num > 1 && Data_Para_Storage[i].SDI < SDI && SDI < Data_Para_Storage[i].SDI + Data_Para_Storage[i].Num)
    {
      Offset += (Data_Para_Storage[i].Len + ROM_CS_BYTES) * (SDI - Data_Para_Storage[i].SDI); 
      return Offset;
    }
    else
    {
      Offset += (Data_Para_Storage[i].Len + ROM_CS_BYTES) * Data_Para_Storage[i].Num;
    }
  }

  debug("get_storage_data_off error, data 0x%x not found\r\n", SDI);
  return NULL_4BYTES;
}

//获取某个存储的数据项的长度, DI只能是Data_Para_Storage中定义的数据
INT16U Get_Storage_Data_Len(STORA_DI SDI)
{
  INT16U i; 

  TRACE();

  for(i = 0; i < S_NUM(Data_Para_Storage); i ++)
  {
    if((Data_Para_Storage[i].Num > 0 && Data_Para_Storage[i].SDI EQ SDI) || \
       (Data_Para_Storage[i].Num > 1 && \
	  Data_Para_Storage[i].SDI < SDI && \
	  Data_Para_Storage[i].SDI + Data_Para_Storage[i].Num> SDI))
    {
      return Data_Para_Storage[i].Len;
    }
  }
  debug("get_storage_data_len err, SDI = 0x%x",SDI);
  ASSERT_FAILED(); 
  return 0;
}

//读取某个SDI内的数据，不进行CS校验
INT16U Read_Storage_Data_NoCS(STORA_DI SDI, INT16U Offset, INT16U Len, void* pDst, void* pDst_Start, INT16U DstLen)
{
    INT32U Off;
    INT8U Re;

    TRACE();

    Unselect_SPI_Device();
    ReInit_Mem_Port();//重新初始化端口

    Off = Get_Storage_Data_Off(SDI); //获取数据偏移
    if(NULL_4BYTES EQ Off)//ASSERT(NULL_4BYTES != Off))
    {
      ASSERT_FAILED();
      //*pErr = RD_STORAGE_DATA_DI_ERR;
      return 0;
    }

    debug("read data:ID = 0x%x, Addr = %d, Off = %d, Len = %d", SDI, Off, Offset, Len);

    Off += Offset; // + 内部偏移

    //OS_Mutex_Pend(PUB_RW_ROM_ID); //申请写ROM的信号量ID
    //if(Check_Power_Status() EQ POWER_ON_STATUS)
    Re = Read_PHY_Mem(Off, pDst, Len, pDst_Start, DstLen);

    if(Re > 0)
        return Len;
    else
        return 0;

}

//读取存储器中的某项数据的固定长度，DI的值可参考Data_Para_Storage的定义
//DI, 需要读取的数据项标识
//Offset, 读取DI数据的起始偏移
//Len, 需要读取的数据长度
//pDst表示读取参数后放到该缓冲区
//pDst_Start和DstLen一起界定目标缓冲区的范围
//*pErr表示读取失败时的原因, 1表示读取成功, 其他错误原因参见Pub_Err.h
//返回值：读取的数据长度, 读取失败时返回0
INT16U Read_Storage_Data_Fix_Len(STORA_DI SDI, INT16U Offset, INT16U Len, void* pDst, void* pDst_Start, INT16U DstLen)
{
  INT32U Off; 
  INT8U Re; 

  TRACE();

  Unselect_SPI_Device();
  ReInit_Mem_Port();//重新初始化端口

  Off = Get_Storage_Data_Off(SDI); //获取数据偏移
  if(NULL_4BYTES EQ Off)//ASSERT(NULL_4BYTES != Off))
  {
    ASSERT_FAILED();
    //*pErr = RD_STORAGE_DATA_DI_ERR; 
    return 0;
  }

  debug("read data:ID = 0x%x, Addr = %d, Off = %d, Len = %d", SDI, Off, Offset, Len);

  Off += Offset; // + 内部偏移

  //OS_Mutex_Pend(PUB_RW_ROM_ID); //申请写ROM的信号量ID
  //if(Check_Power_Status() EQ POWER_ON_STATUS)
  Re = Read_Data_Width_CS(Off, pDst, Len, pDst_Start, DstLen);
  //else
  //*pErr = PD_Read_Imp_Data(Imp_Flag, Off, pDst, Len, pDst_Start, DstLen); 
  //OS_Mutex_Post(PUB_RW_ROM_ID); //释放写ROM的信号量ID
  if(1 EQ Re)
  {
    return Len;
  }
  else//读存储失败则读取默认参数
  {
    //*pErr = RD_FIX_DATA_ERR; 
    return 0;
  }
  //return 0;   

}

//写存储器中的某项数据的固定长度，DI的值可参考Data_Para_Storage的定义
//DI, 需要写的数据项标识
//Offset, 写DI数据的起始偏移
//SrcLen, 需要写的数据长度
//pSrc表示写的源数据缓冲区
//SrcLen表示源数据的长度
//返回1表示成功，其他表示失败
INT8U Write_Storage_Data_Fix_Len(STORA_DI SDI, INT16U Offset, void* pSrc, INT16U SrcLen)
{
  INT32U Off; 
  INT8U Re; 

  TRACE();

  Unselect_SPI_Device();
  ReInit_Mem_Port();//重新初始化端口

  Off = Get_Storage_Data_Off(SDI); //获取数据偏移
  if(NULL_4BYTES EQ Off)
  {
    ASSERT_FAILED();
    return 0;
  }

  debug("write data:ID = 0x%x, Addr = %d, Off = %d, Len = %d", SDI, Off, Offset, SrcLen);

  Off += Offset; // + 内部偏移
  //OS_Mutex_Pend(PUB_RW_ROM_ID);
  //if(Check_Power_Status() EQ POWER_ON_STATUS)
  Re = Write_Data_With_CS(Off, pSrc, SrcLen);
  //else
  //Re = PD_Write_Imp_Data(Imp_Flag, Off, pSrc, SrcLen);     
  //OS_Mutex_Post(PUB_RW_ROM_ID);

  //OS_TimeDly_Ms(20); //延时20ms

  if(1 EQ Re)
  {
    return 1;
  }
  else//读存储失败则读取默认参数
  {
    return 0;
  }
}


//读取存储器中的某项数据，DI的值可参考Data_Para_Storage的定义
//DI, 需要读取的数据项标识
//pPara，在读取某些参数或数据时需要的参数，例如HIS_ENERGY, HIS_DEMAND, HIS_DEMAND_TIME时需要加入时间参数
//时间参数的格式定义如下pPara[0]-pPara[4]分别是分、时、日、月、年, 其他情况下该参数无意义
//pDst表示读取参数后放到该缓冲区
//pDst_Start和DstLen一起界定目标缓冲区的范围
//*pErr表示读取失败时的原因, 1表示读取成功, 其他错误原因参见Pub_Err.h
//返回值：读取的数据长度, 读取失败时返回0
INT16U Read_Storage_Data(STORA_DI SDI, void* pDst, void* pDst_Start, INT16U DstLen)
{
  INT16U Len, Len1; 

  TRACE();

  //Clear_CPU_Dog();     //清CPU内部看门狗
  //Clear_Ext_Dog();     //清CPU外部看门狗
  //Cur_Task_ID = Get_Cur_Task_ID(); 
  //debug("Read Storage Data:0x%x", DI, Tcb[Cur_Task_ID].Name);
  Len = Get_Storage_Data_Len(SDI); 
  if(Len > 0)
  {
    //OS_TimeDly_Ms(20); //延时给其他任务，防止某任务连续读多个参数占用CPU
    Len1 = Read_Storage_Data_Fix_Len(SDI, 0, Len, pDst, pDst_Start, DstLen); 
    if(Len != Len1)
    {
      return 0;
    }
    else
      return Len;
  }
  else
  {
    ASSERT_FAILED(); 
    return 0;
  }
}

//读取连续DI的多条存储数据
INT16U Read_Multi_Storage_Data(STORA_DI SDI, INT16U Num, void *pDst, void *pDst_Start, INT16U DstLen)
{
  INT16U i;
  INT16U Len;
  
  Len = 0;
  for(i = 0; i < Num; i ++)
  {
    Len += Read_Storage_Data(SDI + i, (INT8U *)pDst + Len, (INT8U *)pDst_Start, DstLen); 
  }
  
  return Len;
}

//向存储器中写某项数据，DI的值可参考Data_Para_Storage的定义
//DI, 需要写的数据项标识
//pPara，在写某些参数或数据时需要的参数，例如HIS_ENERGY, HIS_DEMAND, HIS_DEMAND_TIME时需要加入时间参数
//时间参数的格式定义如下pPara[0]-pPara[4]分别是分、时、日、月、年, 其他情况下该参数无意义
//pSrc表示写数据的源缓冲区
//返回值：1表示成功，其他表示失败
INT8U Write_Storage_Data(STORA_DI SDI, void* pSrc, INT16U SrcLen)
{
  INT16U Len; 
  INT8U Re; 

  TRACE();

  //Unselect_SPI_Device();
  //Cur_Task_ID = Get_Cur_Task_ID(); 
  //debug("Write Storage Data:0x%x", DI, Tcb[Cur_Task_ID].Name);
  //获取并比较数据长度
  Len = Get_Storage_Data_Len(SDI); 
  if(Len != SrcLen)//ASSERT(Len EQ SrcLen))
  {
    ASSERT_FAILED();
    debug("wr_len err, SDI = 0x%x len = %d, srclen = %d", SDI, Len, SrcLen);
    return 0;
  } 

  //写Imp数据
  //OS_Mutex_Pend(PUB_RW_ROM_ID); //申请写ROM的信号量ID
  Re = Write_Storage_Data_Fix_Len(SDI, 0, pSrc, SrcLen); 
  //OS_Mutex_Post(PUB_RW_ROM_ID); //释放该信号量
  if(1 != Re)//ASSERT(1 EQ Re))
  {
    ASSERT_FAILED();
    return 0;
  } 
  return 1;
}


#undef STORAGE_C

