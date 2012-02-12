#ifndef QT_SIM_H
#define QT_SIM_H

#if QT_EN > 0
#include "..\Stm32\usr\app\LED_Cfg.h"
#include "stdio.h"
#include <QtGlobal>

#undef EXT
#ifdef QT_SIM_C
#define EXT
#else
#define EXT extern
#endif


//定义断言,多多使用，有益身心
#if ASSERT_EN>0
#define ASSERT(x) do{if(x==false) qDebug("file:%s, line:%d",__FILE__, __LINE__);}while(0)//Assert((BOOL)(x),__FILE__,__FUNCTION__,(INT16U)__LINE__)
#define ASSERT_FAILED() qDebug("file:%s, line:%d",__FILE__, __LINE__)//Assert_Failed(__FILE__,__FUNCTION__,(INT16U)__LINE__)
#else
#define ASSERT(x)
#define ASSERT_FAILED()
#endif

typedef unsigned int INT32U;
typedef int INT32S;
typedef unsigned short int INT16U;
typedef short int INT16S;
typedef unsigned char INT8U;
typedef char INT8S;
//typedef unsigned char BOOL;

#define FILE_R  0
#define FILE_W  1
#define FILE_WR 2

#define SELF_TEST_STATUS 0x00
#define NORMAL_STATUS 0x00
#define Chk_JP_Status() 0x01
#define Chk_UDisk_Processing() 0x00
#define Chk_Test_Key_Down() 0x00
#define Chk_Test_Key_Up() 0x00
#define Set_OE_Duty_Polarity(X,Y)
#define START_SCAN_TIMER()
#define STOP_SCAN_TIMER()

#define Soft_Rest()
/*
#define FILE_T char *

#define FILE_FRAME_ERR -2 //文件帧出错

#define FILE_NULL -2 //文件不存在 
#define FILE_ERR -1 //文件出错
#define FILE_END 0  //文件结尾
#define FILE_OK  1 //文件ok
*/
#define START_SHOW_TIMER_INT
#define STOP_SHOW_TIMER_INT

#define debug qDebug
#define Unselect_SPI_Device()
#define ReInit_Mem_Port()

#define SCAN_INT_DISABLE()
#define SCAN_INT_ENABLE()

#define TIM1_EN 1
typedef struct
{
    INT8U Head;
    FILE *file;
    INT8U CS[CS_BYTES];
    INT8U Tail;
}S_PFILE;

EXT S_PFILE pFile;

EXT void Delay_ms(int sec);
EXT void Delay_sec(int sec);
EXT void Put_Char(char c);
EXT void Com_Send_Byte(INT8U Ch, INT8U Chr);
EXT INT8U _Get_Cur_Time(INT8U Time[]);//S_Time *pTime);
EXT INT8U Set_Cur_Time(INT8U Time[]);//S_Time *pTime);
EXT INT16U Get_Cur_Humidity();
EXT INT16U Get_Cur_Noise();
EXT void Mem_Open();
EXT void Mem_Close();
EXT INT8U Read_PHY_Mem(INT32U Offset, void *pDst, INT16U RD_Len, void *pDst_Start, INT16U DstLen);
EXT INT8U Write_PHY_Mem(INT32U Offset, void *pSrc, INT16U SrcLen);
EXT INT16S Get_Cur_Temp();
EXT void Build_Scan_Data_Index();
#endif
#endif
