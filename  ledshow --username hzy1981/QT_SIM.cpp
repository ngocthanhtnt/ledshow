#define QT_SIM_C
#include "Includes.h"

#if QT_EN > 0
#include <QDateTime>
#include <QFile>

void OS_Put_Char(char Chr)
{
  qDebug("%c", Chr);
}

void Put_Char(char c)
{
  c =c;

}

//获取当前时间
INT8U Get_Cur_Time(INT8U Time[])//S_Time *pTime)
{
    QDateTime temp;

  temp =  QDateTime::currentDateTime();
  Time[T_SEC] = temp.time().second();
  Time[T_MIN] = temp.time().minute();
  Time[T_HOUR] = temp.time().hour();
  Time[T_DATE] = temp.date().day();
  Time[T_MONTH] = temp.date().month();
  if(temp.date().year() >= 2000)
    Time[T_YEAR] = temp.date().year() - 2000;
  else
    Time[T_YEAR] = 0;
  //qDebug("year = %d", Time[T_YEAR]);
  return 1;
}

//设置当前时间
INT8U Set_Cur_Time(INT8U Time[])//S_Time *pTime)
{
  return 1;
}

//文件打开
//File_Name表示文件名
//WR_Flag表示读写标志--当文件不存在时，创建该文件
FILE_T File_Open(char File_Name[], INT8U WR_Flag)
{
  return (FILE_T)0;
}

//文件读
//File_Name文件名
//Offset文件偏移
//Len读取长度
//返回-1表示失败，0表示文件结束，1表示成功
//FILE_ERR,FILL_END,FILE_OK
INT8S File_Read(FILE_T file, INT32U Offset, INT16U Len, INT8U *pDst, INT8U *pDst_Start, INT16U DstLen)
{
    file = file;
  return 1;
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
  return 1;
}

INT8S File_Close(FILE_T file)
{
 return 1;
}

INT32S File_Size(FILE_T File)
{
    return 1;
}

//删除文件
INT8S File_Delete(char File_Name[])
{
  return 1;
}
/*
#include <stdio.h>

void printError(const char* msg)
{
    QFile file;
    file.open(stderr, QIODevice::WriteOnly);
    file.write(msg, qstrlen(msg));        // write to stderr
    file.close();
}
*/
void Mem_Init()
{

}

INT8U Read_PHY_Mem(INT32U Offset, void *pDst, INT16U RD_Len, void *pDst_Start, INT16U DstLen)
{
    QFile file("d:\\phy.dat");
    file.open(QIODevice::ReadWrite);
    file.seek(Offset);
    //file.write(msg, qstrlen(msg));        // write to stderr
    file.read((char *)pDst, RD_Len);
    file.close();

  return RD_Len;
}

INT8U Write_PHY_Mem(INT32U Offset, void *pSrc, INT16U SrcLen)
{
    QFile file("d:\\phy.dat");
    file.open(QIODevice::WriteOnly);
    file.seek(Offset);
    //file.write(msg, qstrlen(msg));        // write to stderr
    file.write((char *)pSrc, SrcLen);
    file.close();

  return 1;
}

INT16S Get_Cur_Temp()
{
  return 215;
}
#endif


