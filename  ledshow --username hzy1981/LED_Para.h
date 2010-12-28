#ifndef LED_PARA_H
#define LED_PARA_H

#include "Storage.h"
#include "LED_Show.h"
//extern "c"
//{
#undef EXT
#ifdef LED_PARA_C
#define EXT
#else
#define EXT extern
#endif

//时间索引
#define T_YEAR  0 //--除了日和年其他都从0开始计起。日从1计起，年从1900年计起
#define T_MONTH 1
#define T_DATE  2
#define T_HOUR  3
#define T_MIN   4
#define T_SEC   5
#define T_WEEK  6

#define SHOW_NULL  0x00
#define SHOW_PIC   0x01 //图文--表格和图片也是这个
#define SHOW_CLOCK 0x02 //表盘
#define SHOW_TIME  0x03 //时间
#define SHOW_TIMER 0x04 //计时
#define SHOW_TEMP  0x05 //温度
#define SHOW_LUN   0x06 //农历
#define SHOW_FLASH 0x07 //动画

//#define MAX_FILE_NAME_SIZE 20

#define SPACE_WIDTH 8

#define CHK_BYTE_LEN 3 //结构体中用于校验的字节数--一般是Head、Tail和CS
#define CHK_HEAD_LEN 1 //结构体中用于校验的头字节数--一般是Head

#define PROG_NULL_MODE 0x00
#define PROG_COUNTS_MODE 0x01
#define PROG_TIME_MODE  0x02

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
  INT8U Flag;
  INT8U Value; //亮度值
  INT8U Start_Hour; //起始小时

  //INT8U Tail;
}S_Lightness;

//开关机时间设置
typedef struct
{
  //INT8U Head;
  INT8U Flag;
  INT8U Open_Hour;
  INT8U Open_Min;
  INT8U Close_Hour;
  INT8U Close_Min;

  //INT8U Tail;
}S_Open_Close_Time;

typedef struct
{
  INT8U Week; //星期--全0表示都播放，第0位表示星期日，1-6表示星期1-星期6
  
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

  S_Open_Close_Time Open_Close_Time[MAX_OPEN_CLOSE_TIME]; //开关机时间
  S_Lightness Lightness[MAX_LIGHTNESS_TIME]; //强度

  INT8U Prog_Num; //节目数
  INT8U CS[CS_BYTES];

  INT8U Tail;
}S_Screen_Para;


//节目属性
typedef struct
{
  INT8U Head;
  INT8U Prog_No; //节目号
  
  INT8U Mode; //播放方式，0表示循环播放，1表示定长播放
  INT16U Counts; //循环次数
  INT32U Time; //停留秒数
  
  S_Program_Timing Timing[3]; //节目定时设置
  INT8U Area_Num; //分区数
  INT8U Main_Area_No; //主分区号
  INT8U Area_File_Num[MAX_AREA_NUM]; //每分区文件数
  S_Area Area[MAX_AREA_NUM]; //区域定义
  
  INT8U Border_Speed; //边框运行速度
  INT8U Border_Mode;  //边框模式
  INT8U Border_Width;   //边框宽度
  INT8U Border_Height;  //边框高度
  INT8U Temp;   //备用
  INT8U Border_Data[3*MAX_BORDER_POINTS/8]; //边框数据
  
  INT8U CS[CS_BYTES];
  
  INT8U Tail;
}S_Prog_Para;

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
  INT16U SNum; //分屏个数
  INT8U CS[CS_BYTES];
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
 
  INT8U Diff_Flag;  //时差标志,0加，1减  
  INT8U Hour_Diff;  //时差小时
  INT8U Min_Diff;   //时差分钟
  //INT8U Sec_Diff;   //时差秒钟
  
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
  
  INT8U Date_Type;  //日期标志,0表示不显示日期
  INT8U Date_Font; //字体
  INT8U Date_Color; //日期颜色
  INT16U Date_X; //中心位置在X轴上的比例
  INT16U Date_Y; //中心位置在Y轴上的比例

  INT8U Week_Type;  //星期标志，0表示不显示星期
  INT8U Week_Font;  //字体
  INT8U Week_Color; //星期颜色
  INT16U Week_X; //中心位置在X轴上的比例
  INT16U Week_Y; //中心位置在Y轴上的比例

  INT8U Text_Color; //背景颜色
  INT16U Text_X; //背景X
  INT16U Text_Y; //背景Y
  INT16U Text_Width; //背景宽度
  INT16U Text_Height; //背景高度
  
  INT8U CS[CS_BYTES];
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
  INT8U Dst_Sec; //目标秒
  
  INT8U SmLineFlag; //单多行标志
  INT8U LineSpace;  //行间距，在多行显示时用--备用

  INT8U Timer_Type;  //显示方式
  INT8U Timer_Color; //显示颜色
  INT8U Timer_Font; //显示字号
  //INT8U Show_Posi; //显示位置
  
  INT8U Temp; //备用
  
  INT8U Text_Color; //背景颜色
  INT16U Text_X; //背景X
  INT16U Text_Y; //背景Y
  INT16U Text_Width; //背景宽度
  INT16U Text_Height; //背景高度
  
  INT8U CS[CS_BYTES];
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

  INT8U Diff_Flag;  //时差标志,0加，1减
  INT8U Hour_Diff;  //时差小时
  INT8U Min_Diff;   //时差分钟
  //INT8U Sec_Diff;   //时差秒钟
  
  INT8U Show_Mode;  //显示方式 
  INT8U Show_Color; //显示颜色
  INT8U Show_Font; //显示字号
  INT8U Show_Posi; //显示位置
  
  INT8U Temp; //备用

  INT8U SmLineFlag; //单多行标志
  INT8U LineSpace;  //行间距，在多行显示时用--备用
  
  INT8U Date_Type;  //日期标志,0表示不显示日期
  INT8U Date_Font; //字体
  INT8U Date_Color; //日期颜色
  INT16U Date_X;
  INT16U Date_Y;

  INT8U Week_Type;  //星期标志，0表示不显示星期
  INT8U Week_Font;  //字体
  INT8U Week_Color; //星期颜色
  INT16U Week_X;
  INT16U Week_Y;

  INT8U Time_Type;  //星期标志，0表示不显示星期
  INT8U Time_Font;  //字体
  INT8U Time_Color; //星期颜色
  INT16U Time_X;
  INT16U Time_Y;

  INT8U Text_Color; //背景颜色
  INT16U Text_X; //背景X
  INT16U Text_Y; //背景Y
  INT16U Text_Width; //背景宽度
  INT16U Text_Height; //背景高度
  
  INT8U CS[CS_BYTES];
  INT8U Tail;
}S_Time_Para;

//农历显示参数
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

  INT8U SmLineFlag; //单多行标志
  INT8U LineSpace;  //行间距，在多行显示时用--备用
  
  INT8U Tiangan_Type;  //天干地支标志,0表示不显示天干
  INT8U Tiangan_Font; //字体
  INT8U Tiangan_Color; //天干颜色
  INT16U Tiangan_X;
  INT16U Tiangan_Y;

  INT8U Nongli_Type;  //农历标志，0表示不显示农历
  INT8U Nongli_Font;  //字体
  INT8U Nongli_Color; //农历颜色
  INT16U Nongli_X;
  INT16U Nongli_Y;

  INT8U Jieqi_Type;  //星期标志，0表示不显示星期
  INT8U Jieqi_Font;  //字体
  INT8U Jieqi_Color; //星期颜色
  INT16U Jieqi_X;
  INT16U Jieqi_Y;

  INT8U Text_Color; //背景颜色
  INT16U Text_X; //背景X
  INT16U Text_Y; //背景Y
  INT16U Text_Width; //背景宽度
  INT16U Text_Height; //背景高度

  INT8U CS[CS_BYTES];
  INT8U Tail;
}S_Lun_Para;

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

  INT8U Temp_Type;  //温度显示方式
  INT8U Temp_Font;  //温度字体
  INT8U Temp_Color; //温度颜色
  INT16U Temp_X;    
  INT16U Temp_Y;
  
  INT8U Text_Color; //背景颜色
  INT16U Text_X; //背景X
  INT16U Text_Y; //背景Y
  INT16U Text_Width; //背景宽度
  INT16U Text_Height; //背景高度

  INT8U CS[CS_BYTES];
  INT8U Tail;
}S_Temp_Para;

//所有参数的联合
typedef union
{
  S_Pic_Para Pic_Para;
  S_Clock_Para Clock_Para;
  S_Timer_Para Timer_Para;
  S_Time_Para Time_Para;
  S_Lun_Para Lun_Para;
  S_Temp_Para Temp_Para;
  
}U_File_Para;

typedef struct
{
  INT8U Head;
  STORA_DI Index[MAX_AREA_NUM][MAX_FILE_NUM+1]; //后一个文件的起始就是前一个文件的结束,[MAX_FILE_NUM + 1]表示最后一个文件的结束位置
  //INT16U Block_End;
  INT8U CS[CS_BYTES];
  INT8U Tail;
}S_Prog_Block_Index;

//文件中某个参数的偏移
/*
typedef struct
{
  INT8U Ctrl_Code;
  INT16U Len;
}S_File_Para_Info;
*/
typedef struct
{
  INT8U Prog_No;  //节目号
  INT8U Area_No:4; //分区号
  INT8U File_No:4; //文件号
  //INT8U Screen_No; //屏号
  //INT8U Block_No; //块号
  INT16U Len;     //帧长度
  INT8U Buf[ONE_BLOCK_SIZE];
  
}S_Prog_Show_Data;

typedef struct
{
  INT8U Head;
  INT16U Index;
  INT8U CS[CS_BYTES];
  INT8U Tail;
}S_Cur_Block_Index;
/*
typedef struct
{
    INT8U Head;
    INT8U Buf[ONE_BLOCK_SIZE];
    INT16U Index;
    INT8U Tail;
}S_Rcv_Show_Data;
*/
typedef struct
{
  INT8U Prog_No;
  INT8U File_No:4;  
  INT8U Area_No:4;
  INT8U Type;
  
  INT8U Seq0;
   
  INT16U Len;
  INT16U Bak;
  
}S_File_Para_Info;

typedef struct
{/*
  S_Pub_Buf Pub_Buf;  //公共buf
  S_Show_1Color_Data One_Color_Data;
  S_Show_2Color_Data Two_Color_Data;
  S_Show_3Color_Data Three_Color_Data;
  */
  INT8U Head;
  INT8U Color_Data[3*MAX_POINTS/8];//---连续的3个字节表示八个点3个颜色!!
  INT8U Tail;
}S_Show_Data;

#define SCREEN_PARA_LEN (sizeof(S_Screen_Para) -CHK_BYTE_LEN)
#define PROG_PARA_LEN   (sizeof(S_Prog_Para)-CHK_BYTE_LEN)
#define FILE_PARA_LEN (sizeof(U_File_Para)-CHK_BYTE_LEN)
#define BLOCK_INDEX_LEN (sizeof(S_Prog_Block_Index) - CHK_BYTE_LEN)
#define BLOCK_DATA_LEN 300
#define BLOCK_HEAD_DATA_LEN 8
#define BLOCK_SHOW_DATA_LEN (BLOCK_DATA_LEN -BLOCK_HEAD_DATA_LEN)

EXT S_Screen_Para Screen_Para; //显示屏相关参数

EXT S_Prog_Para Prog_Para;  //当前节目属性[MAX_PROGRAM_NUM]; //节目个数
//EXT S_Prog_Block_Index Prog_Block_Index; //当前节目的存储参数
EXT S_Cur_Block_Index Cur_Block_Index;
//EXT S_Clock_Para Clock_Para;
//EXT S_Rcv_Show_Data Rcv_Show_Data;

EXT S_Time Cur_Time; //当前时间 

EXT INT8U Get_Screen_Color_Num();
EXT void Read_Screen_Para();
EXT INT8U Get_Show_Para_Len(INT8U Type);
EXT STORA_DI Get_Show_Para_Stora_DI(INT8U Prog_No, INT8U Area_No, INT8U File_No);
EXT INT8U Save_Para_Frame_Proc(INT8U Frame[], INT16U FrameLen);
EXT INT8U Save_Prog_Property_Frame_Proc(INT8U Frame[],INT16U FrameLen);
EXT INT8U Save_Show_Data_Frame_Proc(INT8U Frame[],INT16U FrameLen);
EXT INT16U Read_File_Para(INT8U Prog_No, INT8U Area_No, INT8U File_No, void *pDst, void *pDst_Start, INT16U DstLen);

EXT INT8U Check_Update_Prog_Para();
EXT INT16U Read_Prog_Para(INT8U Prog_No);
EXT INT16U Read_Prog_Block_Index(INT8U Prog_No);
EXT INT16U Read_Show_Data(INT8U Area_No, INT8U File_No, INT8U Flag, INT16U SIndex, \
                      S_Show_Data *pShow_Data);
//}
#endif // LED_PARA_H
