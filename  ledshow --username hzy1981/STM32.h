#ifndef STM32_H
#define STM32_H

#if QT_EN == 0
//#include "LED_Cfg.h"

#undef EXT
#ifdef STM32_C
#define EXT
#else
#define EXT extern
#endif

//定义断言,多多使用，有益身心
#if ASSERT_EN>0
#define ASSERT(x) //Assert((BOOL)(x),__FILE__,__FUNCTION__,(INT16U)__LINE__)
#define ASSERT_FAILED() //Assert_Failed(__FILE__,__FUNCTION__,(INT16U)__LINE__)
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
typedef unsigned char BOOL;

#define FILE_T char *

#define FILE_R  0
#define FILE_W  1
#define FILE_WR 2

#define FILE_FRAME_ERR -2 //文件帧出错

#define FILE_NULL -2 //文件不存在
#define FILE_ERR -1 //文件出错
#define FILE_END 0  //文件结尾
#define FILE_OK  1 //文件ok

#define START_SHOW_TIMER_INT
#define STOP_SHOW_TIMER_INT

typedef struct
{
  INT8U Head;
  
  INT32U Ms10;  //10ms
  INT32U Sec;
  
  INT8U Tail;
}S_Pub_Timer;

EXT S_Pub_Timer Pub_Timer;
EXT void Put_Char(char c);
EXT INT8U Get_Cur_Time(INT8U Time[]);//S_Time *pTime);
EXT INT8U Set_Cur_Time(INT8U Time[]);//S_Time *pTime);
EXT FILE_T File_Open(char File_Name[], INT8U WR_Flag);
EXT INT8S File_Read(FILE_T file, INT32U Offset, INT16U Len, INT8U *pDst, INT8U *pDst_Start, INT16U DstLen);
EXT INT8S File_Write(FILE_T file, INT32U Offset, INT8U Buf[], INT16U Len);
EXT INT8S File_Close(FILE_T file);
EXT INT8S File_Delete(char File_Name[]);
EXT INT8S File_Size(char File_Name[]);
EXT INT8U Read_PHY_Mem(INT32U Offset, void *pDst, INT16U RD_Len, void *pDst_Start, INT16U DstLen);
EXT INT8U Write_PHY_Mem(INT32U Offset, void *pSrc, INT16U SrcLen);
#endif
#endif
