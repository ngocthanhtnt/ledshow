#ifndef LED_PARA_H
#define LED_PARA_H

//extern "c"
//{
#undef EXT
#ifdef LED_PARA_C
#define EXT
#else
#define EXT extern
#endif

//时间索引
#define T_YEAR  0
#define T_MONTH 1
#define T_DATE  2
#define T_HOUR  3
#define T_MIN   4
#define T_SEC   5
#define T_WEEK  6

#define FAC_PARA_FILE  0 //工厂参数文件
#define USR_PARA_FILE  1 //用户参数文件
#define PROG_PARA_FILE 2 //节目擦数文件
#define PROG_DATA_FILE 3 //节目数据文件

#define FILE_R 0//文件读
#define FILE_W 1//文件写
#define FILE_WR 2//文件读和写

#define MAX_FILE_NAME_SIZE 20

typedef struct
{
    INT8U Head;
  INT8U Time[7];
  //INT8U CS[CS_BYTES];
  INT8U Tail;
}S_Time;

typedef struct
{
  //INT8U Head;

  INT8U Value; //亮度值
  INT8U Start_Hour; //起始小时

  //INT8U Tail;
}S_Lightness;

//开关机时间设置
typedef struct
{
  //INT8U Head;

  INT8U Open_Hour;
  INT8U Open_Min;
  INT8U Close_Hour;
  INT8U Close_Min;

  //INT8U Tail;
}S_Open_Close_Time;

typedef struct
{
  INT8U Week; //星期
  INT8U Start_Date[3]; //起始年月日
  INT8U End_Date[3];	//结束年月日  
  INT8U Start_Time[2]; //起始时分
  INT8U End_Time[2];	//结束时分
}S_Program_Timing;

//位置
typedef struct
{
  INT16U X;
  INT16U Y;
  INT16U X_Len;
  INT16U Y_Len; 	
}S_Area;

//屏幕参数
typedef struct
{
  INT8U Head;

  INT16U Width; //宽度
  INT16U Height; //高度
  INT8U Color; //颜色 0单色，1双色，2三色，3-255级灰度
  
  INT8U Addr; //地址
  INT32U IP; //IP地址
  INT8U Baud;  //波特率

  S_Open_Close_Time Open_Close_Time; //开关机时间
  S_Lightness Lightness; //强度

  INT8U Program_Num; //节目数
  INT8U CS[CS_BYTES];

  INT8U Tail;
}S_Screen_Para;


//节目属性
typedef struct
{
  INT8U Program_No; //节目号
  //INT8U Program_Cycles; //循环次数
  //INT16U Program_Stay_Sec; //停留秒数
  S_Program_Timing Timing[3]; //节目定时设置
  INT8U Area_Num; //分区数
  S_Area Area[MAX_AREA_NUM]; //区域定义
  INT8U Main_Area_No; //主分区号
  INT8U CS[CS_BYTES];
}S_Program_Para;

typedef struct
{
  INT8U Head;
  
  INT8U Flag; //标志
  INT8U Prog_No; //节目号
  INT8U Area_No; //分区号
  INT8U File_No; //文件号
  INT8U In_Mode; //引入方式
  INT8U In_Speed; //进入速度
  INT8U Add_Mode; //追加方式
  INT16U Stay_Time; //停留时间，最高位为单位，0表示s，1表示ms
  INT8U Out_Mode; //引出方式  
  
  INT8U Tail;
}S__Para;

//图文参数
typedef struct
{
  INT8U Head;
  
  INT8U Flag; //标志
  INT8U Prog_No; //节目号
  INT8U Area_No; //分区号
  INT8U File_No; //文件号
  INT8U In_Mode; //引入方式
  INT8U In_Speed; //进入速度
  INT8U Add_Mode; //追加方式
  INT16U Stay_Time; //停留时间，最高位为单位，0表示s，1表示ms
  INT8U Out_Mode; //引出方式	
  INT8U Color; //颜色
 
  INT8U Tail;
}S_Pic_Para;

//表盘参数
typedef struct
{
  INT8U Head;
  
  INT8U Flag; //标志
  INT8U Prog_No; //节目号
  INT8U Area_No; //分区号
  INT8U File_No; //文件号
  INT8U In_Mode; //引入方式
  INT8U In_Speed; //进入速度
  INT8U Add_Mode; //追加方式
  INT16U Stay_Time; //停留时间，最高位为单位，0表示s，1表示ms
  INT8U Out_Mode; //引出方式	
  
  INT8U Hour_Point_Radius; //整点半径
  INT8U Hour_Point_Color; ///整点颜色
  
  INT8U Hour369_Point_Radius; //369点半径
  INT8U Hour369_Point_Color;  //369点颜色
  
  INT8U Hour_Line_Width;  //时钟宽度
  INT8U Hour_Line_Color;  //时钟颜色
  
  INT8U Min_Line_Width; //分钟宽度
  INT8U Min_Line_Color;  //分钟颜色
  
  INT8U Sec_Line_Width; //秒钟宽度
  INT8U Sec_Line_Color; //秒钟颜色
  
  INT8U Bk_Color; //背景颜色
  INT16U Bk_X; //背景X
  INT16U Bk_Y; //背景Y
  INT16U Bk_Width; //背景宽度
  INT16U Bk_Height; //背景高度
  
  INT8U Tail;
}S_Clock_Para;

//定时参数
typedef struct
{
  INT8U Head;
  
  INT8U Flag; //标志
  INT8U Prog_No; //节目号
  INT8U Area_No; //分区号
  INT8U File_No; //文件号
  INT8U In_Mode; //引入方式
  INT8U In_Speed; //进入速度
  INT8U Add_Mode; //追加方式
  INT16U Stay_Time; //停留时间，最高位为单位，0表示s，1表示ms
  INT8U Out_Mode; //引出方式	

  INT8U Dst_Year; //目标年
  INT8U Dst_Month; //目标月
  INT8U Dst_Date; //目标日
  INT8U Dst_Hour; //目标时
  INT8U Dst_Min; //目标分
  
  INT8U Show_Mode;  //显示方式 
  INT8U Show_Color; //显示颜色
  INT8U Show_Font; //显示字号
  INT8U Show_Posi; //显示位置
  
  INT8U Temp; //备用
  
  INT8U Bk_Color; //背景颜色
  INT16U Bk_X; //背景X
  INT16U Bk_Y; //背景Y
  INT16U Bk_Width; //背景宽度
  INT16U Bk_Height; //背景高度
  
  INT8U Tail;
}S_Timer_Para;

//日期时间参数
typedef struct
{
  INT8U Head;
  
  INT8U Flag; //标志
  INT8U Prog_No; //节目号
  INT8U Area_No; //分区号
  INT8U File_No; //文件号
  INT8U In_Mode; //引入方式
  INT8U In_Speed; //进入速度
  INT8U Add_Mode; //追加方式
  INT16U Stay_Time; //停留时间，最高位为单位，0表示s，1表示ms
  INT8U Out_Mode; //引出方式	

  INT8U Show_Mode;  //显示方式 
  INT8U Show_Color; //显示颜色
  INT8U Show_Font; //显示字号
  INT8U Show_Posi; //显示位置
  
  INT8U Temp; //备用
  
  INT8U Bk_Color; //背景颜色
  INT16U Bk_X; //背景X
  INT16U Bk_Y; //背景Y
  INT16U Bk_Width; //背景宽度
  INT16U Bk_Height; //背景高度
  
  INT8U Tail;
}S_Time_Para;

//温度参数
typedef struct
{
  INT8U Head;
  
  INT8U Flag; //标志
  INT8U Prog_No; //节目号
  INT8U Area_No; //分区号
  INT8U File_No; //文件号
  INT8U In_Mode; //引入方式
  INT8U In_Speed; //进入速度
  INT8U Add_Mode; //追加方式
  INT16U Stay_Time; //停留时间，最高位为单位，0表示s，1表示ms
  INT8U Out_Mode; //引出方式	

  INT8U Show_Mode;  //显示方式 
  INT8U Show_Color; //显示颜色
  INT8U Show_Font; //显示字号
  INT8U Show_Posi; //显示位置
  
  INT8U Temp; //备用
  
  INT8U Bk_Color; //背景颜色
  INT16U Bk_X; //背景X
  INT16U Bk_Y; //背景Y
  INT16U Bk_Width; //背景宽度
  INT16U Bk_Height; //背景高度
  
  INT8U Tail;
}S_Temp_Para;

//所有参数的联合
typedef union
{
  S_Pic_Para Pic_Para;
  S_Clock_Para Clock_Para;
  S_Timer_Para Timer_Para;
  S_Time_Para Time_Para;
  S_Temp_Para Temp_Para;
  
}U_File_Para;


//文件中某个参数的偏移
typedef struct
{
  INT8U Ctrl_Code;
  INT16U Len;
}S_File_Para_Info;

EXT S_Screen_Para Screen_Para; //显示屏相关参数
EXT U_File_Para File_Para[MAX_AREA_NUM]; //当前分区的文件参数，更换文件时刷新之
EXT S_Program_Para Program_Para;  //当前节目属性[MAX_PROGRAM_NUM]; //节目个数

//EXT S_Clock_Para Clock_Para;

EXT S_Time Cur_Time; //当前时间 
EXT void Read_Screen_Para();
EXT char * Get_Program_Data_File_Name(INT8U Prog_No, INT8U Area_No, char File_Name[]);
EXT INT32S File_Read_One_Frame(FILE_T File, INT32U Offset, INT8U *pSeq, INT16U *pCtrl, INT8U *pDst, INT8U *pDst_Start, INT16U DstLen);
EXT INT8U Save_Para_Frame_Proc(INT8U Frame[], INT16U FrameLen);
EXT INT8U Save_Prog_Property_Frame_Proc(INT8U Frame[],INT16U FrameLen);
EXT INT8U Save_Prog_Data_Frame_Proc(INT8U Frame[],INT16U FrameLen);
EXT INT8U Del_Prog_Data(INT8U Frame[], INT16U FrameLen);
EXT INT8U Check_Update_Program_Para();
EXT void Read_Para();
//}
#endif // LED_PARA_H
