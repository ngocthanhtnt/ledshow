#ifndef LED_SHOW_H
#define LED_SHOW_H

//extern "c"
//{
//#include "LED_Cfg.h"
#include "pub.h"
#include "LED_Para.h"

#undef EXT
#ifdef LED_SHOW_C
#define EXT
#else
#define EXT extern
#endif

#define PI 3.1415926

#define SHOW_NULL  0x00
#define SHOW_PIC   0x01
#define SHOW_CLOCK 0x02
#define SHOW_TIME  0x03
#define SHOW_TIMER 0x04
#define SHOW_TEMP  0x05


#define FONT_SIZE16 0
#define FONT_SIZE24 1
#define FONT_SIZE48 2

#define GET_LINE_Y(X0,Y0,X1,Y1,X) ((X1 != X0)?(((Y1)-(Y0))*((X)-(X0))/((X1)-(X0)) + (Y0)):Y0)
#define GET_LINE_X(X0,Y0,X1,Y1,Y) ((Y1 != Y0)?(((X1)-(X0))*((Y)-(Y0))/((Y1)-(Y0)) + (X0)):X0)

#define AREA_ERR -1//更新显示文件出错
#define AREA_END 0 //该分区结束
#define AREA_OK  1 //更新成功

#define PROG_END 0 //节目结束
#define PROG_OK  1 //节目ok
//#define PUB_BUF Show_Data_Bak.Pub_Buf.Buf //公共数据区，与显示数据公用
/*
//时间
typedef struct
{
INT8U Head;
INT8U Time[5]; //年、月、日、时、分	
INT8U Tail;
}S_Time;
*/
//三色显示数据
typedef struct
{
  INT8U Head;
  INT8U Color0[MAX_POINTS/3]; //红色
  INT8U Color1[MAX_POINTS/3]; //蓝色
  INT8U Color2[MAX_POINTS/3]; //黄色
  INT8U Tail;
}S_Show_3Color_Data;

//双色显示数据
typedef struct
{
  INT8U Head;
  INT8U Color0[MAX_POINTS/2];
  INT8U Color1[MAX_POINTS/2];
  INT8U Tail;
}S_Show_2Color_Data;

//单色显示数据
typedef struct
{
  INT8U Head;
  INT8U Color0[MAX_POINTS];
  INT8U Tail;
}S_Show_1Color_Data;

//点的定义
typedef struct
{
  INT16U X;
  INT16U Y;
}S_Point;

typedef struct
{/*
  S_Pub_Buf Pub_Buf;  //公共buf
  S_Show_1Color_Data One_Color_Data;
  S_Show_2Color_Data Two_Color_Data;
  S_Show_3Color_Data Three_Color_Data;
  */
  INT8U Head;
  INT8U Color_Data[3*MAX_POINTS/8];
  INT8U Tail;
}S_Show_Data;

//定义分区状态
typedef struct
{
  INT8U Head;
  
  INT8U File_No; //当前文件号
  INT8U File_Type; //文件类型
  INT8U File_Offset; //当前文件偏移
  INT8U Step;        //当前移动的阶梯
  INT16U Step_Timer;  //已经走过Timer，单位ms
  INT32U Stay_Time;   //已经停留的时间，单位ms
  
  INT8U Tail;
}S_Area_Status;

//定义节目状态
typedef struct
{
  INT8U Time; //已经播放时长
  
}S_Program_Status;

//extern char * Get_Program_Data_File_Name(INT8U Prog_No, INT8U Area_No, char File_Name[]);
typedef struct{
  INT16U Unicode;
  INT8U CN16_Dot[32]; //16*16
  INT8U CN24_Dot[72]; //24*24
  INT8U CN36_Dot[162]; //36*36
}CNZK_Info;

typedef struct
{
  void (*Func)(INT8U);
}S_Mode_Func;

EXT S_Show_Data Show_Data;  //显示数据
EXT S_Show_Data Show_Data_Bak; //显示数据备份
EXT S_Area_Status Area_Status[MAX_AREA_NUM]; //分区状态信息
EXT S_Program_Status Program_Status;   //节目状态信息

//获取当前颜色方案
EXT INT8U Get_Color(); //获取当前的颜色方案
EXT INT8U Get_Bit(INT8U *p,INT16U X_Size,INT16U X,INT16U Y);
EXT INT8U Get_Buf_Bit(INT8U Buf[], INT32U Buf_Size, INT32U Index);
EXT void Set_Buf_Bit(INT8U Buf[], INT32U Buf_Size, INT32U Index, INT8U Value);
EXT INT32U Get_Area_Point_Index(INT8U Area_No, INT16U X, INT16U Y); //获取某个区域的数据缓冲区起始
//多位的拷贝
EXT void Bits_Copy(INT8U *pSrc, INT16U Src_Len, INT32U Src_Index, INT32U Bits, INT8U *pDst, INT16U Dst_Len, INT32U Dst_Index);
//获取一个区域中的一个点
EXT INT8U Get_Area_Point_Data(S_Show_Data *pSrc_Buf, INT8U Area_No, INT16U X, INT16U Y); //获取一个区域内一个点的数据
//设置一个区域中的一个点
EXT void Set_Area_Point_Data(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, INT8U Data); //设置一个区域的点
//绘制一条线
EXT void Draw_Line(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1, INT8U Value);
//复制一条线
EXT void Copy_Line(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1, S_Show_Data *pDst_Buf, S_Point *pPoint2);
//复制一个填充好的矩形
EXT void Copy_Filled_Rect(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, INT16U X_Len, INT16U Y_Len, S_Show_Data *pDst_Buf, S_Point *pPoint1);
//填充一个矩形
EXT void Fill_Rect(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, INT16U X_Len, INT16U Y_Len,INT8U Value);
//复制一个三角形数据
EXT void Copy_Filled_Triangle(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pSrc_Point0, S_Point *pSrc_Point1,S_Point *pSrc_Point2,\
  S_Show_Data *pDst_Buf, S_Point *pDst_Point0);  //复制一个三角形区域
//填充一个三角区域
EXT void Fill_Triangle(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1,S_Point *pPoint2, INT8U Value);
//复制一个实心圆
EXT void Copy_Filled_Round(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pCenter0, INT16U Radius, S_Show_Data *pDst_Buf, S_Point *pCenter1);
//填充一个实心圆
EXT void Fill_Round(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pCenter, INT16U Radius, INT8U Value);
//复制一个多边形
EXT void Copy_Filled_Polygon(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1,S_Point *pPoint2, S_Point *pPoint3,S_Show_Data *pDst_Buf, S_Point *pPoint4);
//填充一个多边形
EXT void Fill_Polygon(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1,S_Point *pPoint2, S_Point *pPoint3, INT8U Value);
//获取某点对一个一个角度和长度的点
EXT void Get_Angle_Point(S_Point *pPoint0, INT16S Angle, INT16U Len, S_Point *pPoint1);
//填充表盘时钟整点
EXT void Fill_Clock_Point(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pCenter, INT16S Angle, INT16U Len, INT16U Radius, INT8U Value);
//填充时钟、分钟或秒钟的指针
EXT void Fill_Clock_Line(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pCenter, INT16S Angle, INT16U Len, INT16U Width, INT8U Value);

EXT void Move_Left(INT8U Area_No);
EXT void Move_Right(INT8U Area_No);
EXT void Move_Up(INT8U Area_No);
EXT void Move_Down(INT8U Area_No);
EXT void Move_Left_Cover(INT8U Area_No);
EXT void Move_Right_Cover(INT8U Area_No);
EXT void Move_Up_Cover(INT8U Area_No);
EXT void Move_Down_Cover(INT8U Area_No);
EXT void Move_Left_Up_Cover(INT8U Area_No);
EXT void Move_Right_Up_Cover(INT8U Area_No);
EXT void Move_Left_Down_Cover(INT8U Area_No);
EXT void Move_Right_Down_Cover(INT8U Area_No);
EXT void Move_Left_Right_Open(INT8U Area_No);
EXT void Move_Up_Down_Open(INT8U Area_No);
EXT void Move_Left_Right_Close(INT8U Area_No);
EXT void Move_Up_Down_Close(INT8U Area_No);
EXT INT8S Update_Show_Data_Bak(INT8U Prog_No, INT8U Area_No);
EXT INT8S Check_Update_Show_Data_Bak();
EXT void Show_Clock(S_Show_Data *pDst_Buf, INT8U Area_No, S_Time *pTime, S_Clock_Para *pClock_Para);
EXT void Clear_Area_Data(S_Show_Data *pDst_Buf, INT8U Area_No);
#endif
