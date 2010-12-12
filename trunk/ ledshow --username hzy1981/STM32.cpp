#define STM32_C
#include "Includes.h"

#if QT_EN == 0

void Put_Char(char c)
{
  
}

//获取当前时间
INT8U Get_Cur_Time(INT8U Time[])//S_Time *pTime)
{
  
}

//设置当前时间
INT8U Set_Cur_Time(INT8U Time[])
{
  
}
//文件打开
//File_Name表示文件名
//WR_Flag表示读写标志--当文件不存在时，创建该文件
FILE_T File_Open(char File_Name[], INT8U WR_Flag)
{
  
}

//文件读
//File_Name文件名
//Offset文件偏移
//Len读取长度
//返回-1表示失败，0表示文件结束，1表示成功
//FILE_ERR,FILL_END,FILE_OK
INT8S File_Read(FILE_T file, INT32U Offset, INT16U Len, INT8U *pDst, INT8U *pDst_Start, INT16U DstLen)
{
  
}

//文件写
//File_Name文件名
//offset偏移
//Buf写内容
//写长度
//0表示失败，>0 表示成功
//FILE_ERR,FILE_OK
INT8S File_Write(FILE_T file, INT32U Offset, INT8U Buf[], INT16U Len)
{
  
}

INT8S File_Close(FILE_T file)
{
  
}

//删除文件
INT8S File_Delete(char File_Name[])
{
  
}

INT8S File_Size(char File_Name[])
{

}

INT8U Read_PHY_Mem(INT32U Offset, void *pDst, INT16U RD_Len, void *pDst_Start, INT16U DstLen)
{
  return 1;
}

INT8U Write_PHY_Mem(INT32U Offset, void *pSrc, INT16U SrcLen)
{
  return 1;
}

#endif
