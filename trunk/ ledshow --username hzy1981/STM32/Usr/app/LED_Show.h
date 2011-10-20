#ifndef LED_SHOW_H
#define LED_SHOW_H

#include "Pub.h"
#include "LED_Para.h"
//#include "LED_Show.h"


#undef EXT
#ifdef LED_SHOW_C
#define EXT
#else
#define EXT extern
#endif

#define SNOW_RATIO 4 //飘雪的数据比例
#define PI 3.1415926535

#define MAX_STEP_NUM 100

#define RT_PLAY_FLAG 0x35

#define SLINE_MODE 0x00
#define MLINE_MODE 0x01

#define GET_LINE_Y(X0,Y0,X1,Y1,X) ((X1 != X0)?(((Y1)-(Y0))*((X)-(X0))/((X1)-(X0)) + (Y0) + 0.5):((Y0) + 0.5))
#define GET_LINE_X(X0,Y0,X1,Y1,Y) ((Y1 != Y0)?(((X1)-(X0))*((Y)-(Y0))/((Y1)-(Y0)) + (X0) + 0.5):((X0) + 0.5))

#define AREA_ERR 2 //更新显示文件出错
#define AREA_END 0 //该分区结束
#define AREA_OK  1 //更新成功

#define PROG_END 0 //节目结束
#define PROG_OK  1 //节目ok

#define WIN_LEAF_WIDTH 8
#define GET_BUF_BIT(Buf, Size, Index) ((Buf[(Index) >>3] & (0x01 << ((Index) & 0x07)))>0?1:0)
#define SET_BUF_BIT(Buf, Size, Index, Value)   do{\
if(Value EQ 0)\
    Buf[(Index) >>3] = (Buf[(Index) >>3] & (~(0x01 << ((Index) & 0x07))));\
else\
    Buf[(Index) >>3] = (Buf[(Index) >>3] | (0x01 << ((Index) & 0x07)));\
}while(0)
//#define Get_Buf_Bit GET_BUF_BIT

//INT8U Get_Buf_Bit(INT8U Buf[], INT32U Buf_Size, INT32U Index)

#pragma pack(1)
typedef struct
{
    INT8U Head;
    INT8U Buf[45];
    INT8U Tail;
}S_Print_Buf;

EXT S_Print_Buf _Print_Buf;

#define Print_Buf _Print_Buf.Buf
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
/*
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
*/
//点的定义
typedef struct
{
  INT16U X;
  INT16U Y;
}S_Point;

typedef struct
{
  INT8U Head;
  INT8U File_No;
  INT8U CS[CS_BYTES];
  INT8U Tail;
}S_File_No;

typedef struct
{
    INT8U Head;
    INT16U SCN_No;
    INT8U CS[CS_BYTES];
    INT8U Tail;
}S_SCN_No;

//定义分区状态
typedef struct
{
  INT8U Head;

  INT16U SCN_No;      //当前已经读到第几屏数据了?

  INT8U New_File_Flag:4;
  INT8U New_SCN_Flag:4;
  INT8U New_CStep_Flag; //新的连移步骤

  INT8U File_No;    //当前文件号

  INT8U Play_Counts; //播放次数
  //INT8U RT_Play_Flag; //实时播放标志
  //INT8U Play_Flag; //播放标志，0表示未进入播放状态，1表示进入播放状态--主要用于与中断显示同步
  //INT8U Restore_Border_Flag:4;
  //INT8U Update_BG_Flag:4;

  INT8U Last_File_No; //上次读取的文件参数
  INT16U Last_SCN_No; //前次读取的屏幕号

  INT8U CS[CS_BYTES];//前面的数据都带校验和

  INT16U Step;        //当前移动的阶梯
  INT16U Max_Step;
  INT32U Step_Timer;  //已经走过Timer，单位ms
  INT32U Stay_Time;   //已经停留的时间，单位ms
  //INT32U Out_Time;   //退出时间
  INT32U Bak_Ms100;
  INT16U Counts;
  
  INT8U In_Mode;
  INT8U Out_Mode;

  INT16U In_Step;
  INT16U Out_Step;

  INT16U In_Max_Step;
  INT16U Out_Max_Step;



  INT8U Tail;
}S_Area_Status;

typedef struct
{
  INT8U Head;
  INT32U Step;   //步长
  INT16U Timer; //已经走过的Timer
  INT8U Tail;  
}S_Border_Status;

typedef struct
{
    INT8U Head;
    INT8U Last_Prog_No; //上个节目
    INT8U Prog_No; //当前节目号

	INT8U RT_Play_Flag; //实时播放标志
	INT16U RT_Play_Time;	//实时播放时间

    INT32U Time; //已经播放时长
    INT16U Counts; //已经播放次数



    INT8U Play_Flag:4; //是否播放标志--主要用于与中断显示同步
    INT8U New_Prog_Flag:4;
    INT8U CS[CS_BYTES];

	INT32U Effect_Counts;
	INT8U Effect_Flag; //特效

	INT32U Max_Effect_Counts;

    INT8U Tail;
}S_Play_Status;

//定义节目状态
typedef struct
{
  INT8U Head;
  
  S_Play_Status Play_Status;

  S_Border_Status Border_Status[MAX_AREA_NUM + 1];
  U_File_Para File_Para[MAX_AREA_NUM]; //每个分区的当前文件参数


  S_Area_Status Area_Status[MAX_AREA_NUM]; //每个分区的状态 
  S_Prog_Block_Index Block_Index; //当前节目的索引

  INT8U CS[CS_BYTES];
  INT8U Tail;
}S_Prog_Status;

typedef struct
{
  INT8U Head;

  //INT8U RT_Play_Flag;
  //INT8U Com_Time; //通信倒计时
  INT8U JP_Status;	 //跳线状态

  INT8U Replay_Flag;
  INT8U Lightness;
  INT8U Color_Num;

  INT16U Temp;    //当前温度
  INT16U Humidity; //湿度
  INT16U Noise; //噪音

  INT8U Time_OC_Flag;	//定时开关机标志
  INT8U Manual_OC_Flag; //手动关机标志
  INT8U UDisk_Flag; //是否有U盘插入

  INT8U CS[CS_BYTES];

  INT32U Move_Step;
  //扫描数据
  INT16U Fold_Size;
  INT16U BRow_X_RowsFold;
  INT16U Rows_X_RowsFold;
  INT16U Block_Cols; //一条扫描线的宽度
  INT16U Block_Bytes; //一条扫描线的字节数
  INT16U Row0_Start_Index; //第0行第一个字节的索引
  INT16U ScanRow_X_BlockCols;

  INT8U Scan_Row;
  INT16S Block_Data_Off[16]; //扫描块内数据的偏移
  INT32S Block0_Index;//_Off[MAX_BLOCK_NUM];

  //接收帧数据
  INT8U Rcv_Ch; //接收通道
  INT8U Rcv_Flag; //接收到的数据
  INT8U Head_Flag; //收到头的标志
  INT8U Com_Time;  //通信维持时间
  INT8U Byte_Time; //接受字节倒计时
  INT16U Rcv_Posi;

  INT8U Rcv_Data[MAX_COM_BUF_LEN];//((BLOCK_DATA_LEN > SCREEN_PARA_LEN) ? BLOCK_DATA_LEN : SCREEN_PARA_LEN) + 20];
  INT8U Com_Err_Flag; //通信错误标志字

  INT8U Self_Test_Flag;
  INT8U Scan_Mode_Test_Flag;
  INT8U Tail;  
}S_Screen_Status;

#pragma pack()

#define MOVE_STEP Screen_Status.Move_Step
//EXT S_Area_Status Area_Status[MAX_AREA_NUM]; //分区状态信息
EXT volatile S_Prog_Status Prog_Status;   //节目状态信息
EXT volatile S_Screen_Status Screen_Status;

EXT S_Show_Data Show_Data;  //显示数据
EXT S_Show_Data Show_Data_Bak; //显示数据备份

#if DATA_PREP_EN
EXT S_Show_Data Show_Data_Prep;
#endif
//#define Pub_Buf Show_Data.Color_Data
#ifdef LED_SHOW_C
const INT8U Bit_Mask[9] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};
#endif

//获取当前颜色方案
EXT INT8U Get_Color(void); //获取当前的颜色方案
EXT INT8U Get_Bit(INT8U *p,INT16U X_Size,INT16U X,INT16U Y);
EXT INT8U Get_Buf_Bit(INT8U Buf[], INT32U Buf_Size, INT32U Index);
EXT INT8U Get_Rect_Buf_Bit(INT8U Buf[], INT16U Buf_Size, INT16U Width, INT16U X, INT16U Y);
EXT void Set_Buf_Bit(INT8U Buf[], INT32U Buf_Size, INT32U Index, INT8U Value);
EXT INT16U Get_Area_Width(INT8U Area_No);
EXT INT16U Get_Area_Height(INT8U Area_No);
EXT INT32U Get_Area_Size(INT8U Area_No);
EXT INT8U Get_Area_TopLeft(INT8U Area_No, S_Point *pPoint);
EXT INT32U Get_Area_Point_Index(INT8U Area_No, INT16U X, INT16U Y); //获取某个区域的数据缓冲区起始
//多位的拷贝
EXT INT16U Copy_Show_Data(INT8U *pSrc, INT32U Off, INT16U SrcLen,\
                          S_Show_Data *pDst, INT8U Area_No, INT16U X, INT16U Y, INT16U Width, INT16U Height);
EXT void Bits_Copy(INT8U *pSrc, INT16U Src_Len, INT32U Src_Index, INT32U Bits, INT8U *pDst, INT16U Dst_Len, INT32U Dst_Index);
EXT INT8U Get_Buf_Point_Data(INT8U Buf[], INT16U Buf_Len, INT8U Color, INT16U Width, INT16U X, INT16U Y);
EXT void Set_Buf_Point_Data(INT8U Buf[], INT16U Buf_Len, INT8U Color, INT8U Width, INT16U X, INT16U Y, INT8U Value);
//获取一个区域中的一个点
EXT INT8U Get_Area_Point_Data(S_Show_Data *pSrc_Buf, INT8U Area_No, INT16U X, INT16U Y); //获取一个区域内一个点的数据
//设置一个区域中的一个点
EXT void Set_Area_Point_Data(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, INT8U Data); //设置一个区域的点
//绘制一条线
EXT void Draw_Line(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1, INT8U Value);
//复制一条线
EXT void Copy_Line(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1, S_Show_Data *pDst_Buf, S_Point *pPoint2);
//复制一个填充好的矩形
EXT void Copy_Filled_Rect(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, INT16U X_Len, INT16U Y_Len, S_Show_Data *pDst_Buf, S_Point *pPoint1, INT8U Flag);
//反向复制一个填充好的举行
EXT void Rev_Copy_Filled_Rect(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, INT16U X_Len, INT16U Y_Len, S_Show_Data *pDst_Buf, S_Point *pPoint1);
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
EXT void Copy_Filled_Polygon(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, INT8U Point_Num, S_Show_Data *pDst_Buf, S_Point *pPoint1);
//填充一个多边形
EXT void Fill_Polygon(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, INT8U Point_Num, INT8U Value);
//获取某点对一个一个角度和长度的点
EXT void Get_Angle_Point(S_Point *pPoint0, INT16S Angle, INT16U Len, S_Point *pPoint1);
//填充表盘时钟整点
EXT void Fill_Clock_Point(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pCenter, INT16S Angle, INT16U Len, INT16U Radius, INT8U Style, INT8U Value);
//填充时钟、分钟或秒钟的指针
EXT void Fill_Clock_Line(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pCenter, INT16S Angle, INT16U Len, INT16U Width, INT8U Value);

EXT void Copy_Buf_2_Area_Rect_0(INT8U *pSrc, INT16U Src_Len, INT16U Src_Off, \
                            S_Show_Data *pDst, INT8U Area_No, INT16U X, INT16U Y, INT16U X_Len, INT16U Y_Len);

EXT void Move_Show_RightNow(INT8U Area_No);
EXT void Move_Left_Continuous(INT8U Area_No);
EXT void Move_Right_Continuous(INT8U Area_No);
EXT void Move_Up_Continuous(INT8U Area_No);
EXT void Move_Down_Continuous(INT8U Area_No);
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
EXT void Move_Left_Right_Reel_Open(INT8U Area_No);
EXT void Move_Left_Right_Reel_Close(INT8U Area_No);
EXT void Move_Up_Down_Reel_Open(INT8U Area_No);
EXT void Move_Up_Down_Reel_Close(INT8U Area_No);
EXT void Move_Up_Down_Close(INT8U Area_No);
EXT void Move_Spin_CW(INT8U Area_No);
EXT void Move_Spin_CCW(INT8U Area_No);
EXT void Move_Up_Snow(INT8U Area_No);
EXT void Move_Down_Snow(INT8U Area_No);
EXT void Move_Flash(INT8U Area_No);
EXT void Move_Left_Laser(INT8U Area_No);
EXT void Move_Right_Laser(INT8U Area_No);
EXT void Move_Up_Laser(INT8U Area_No);
EXT void Move_Down_Laser(INT8U Area_No);
EXT void Move_Left_Tensile(INT8U Area_No);//左拉伸
EXT void Move_Right_Tensile(INT8U Area_No);//右拉伸
EXT void Move_Up_Tensile(INT8U Area_No);//上拉伸
EXT void Move_Down_Tensile(INT8U Area_No);//下拉伸
EXT void Move_Vertical_Tensile(INT8U Area_No);//水平拉伸
EXT void Move_Horizontal_Tensile(INT8U Area_No);//垂直拉伸
EXT void Move_Left_Stretch(INT8U Area_No);
EXT void Move_Right_Stretch(INT8U Area_No);
EXT void Move_Up_Stretch(INT8U Area_No);
EXT void Move_Down_Stretch(INT8U Area_No);
EXT void Move_Horizontal_Window(INT8U Area_No);
EXT void Move_Vertical_Window(INT8U Area_No);
EXT void Move_Left_Compress(INT8U Area_No);
EXT void Move_Right_Compress(INT8U Area_No);
EXT void Move_Up_Compress(INT8U Area_No);
EXT void Move_Down_Compress(INT8U Area_No);
EXT void Move_Fade_In(INT8U Area_No);
EXT void Move_Left_Up_In(INT8U Area_No);
EXT void Move_Right_Up_In(INT8U Area_No);
EXT void Move_Left_Down_In(INT8U Area_No);
EXT void Mofe_Right_Down_In(INT8U Area_No);
EXT void Move_Left_Compress_0(INT8U Area_No);
EXT void Move_Right_Compress_0(INT8U Area_No);
EXT void Move_Up_Compress_0(INT8U Area_No);
EXT void Move_Down_Compress_0(INT8U Area_No);
EXT void Clear_Area_Data(S_Show_Data *pDst_Buf, INT8U Area_No);

EXT void vsPrintf(char Buf[], CONST INT8S *format, va_list ap);
EXT void Show_String(INT8U Str[], INT8U Font, INT8U Color, S_Show_Data *pData, INT8U Area_No, INT16U X,INT16U Y);
EXT INT16U LED_Print(INT8U Font, INT8U Color, S_Show_Data *pData,  INT8U Area_No, INT16U X, INT16U Y,const INT8S *format, ...);
EXT INT16U RT_LED_Print(INT8U Font, INT8U Color, INT16U X, INT16U Y, INT16U Sec, const INT8S *format,...);
#endif
