#ifndef LED_PARA_H
#define LED_PARA_H

#include "pub.h"
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
#define SHOW_HUMIDITY 0x07
#define SHOW_NOISE    0x08
#define SHOW_FLASH 0x09 //动画

//#define MAX_FILE_NAME_SIZE 20

#define SPACE_WIDTH 8

#define CHK_BYTE_LEN 3 //结构体中用于校验的字节数--一般是Head、Tail和CS
#define CHK_HEAD_LEN 1 //结构体中用于校验的头字节数--一般是Head

//#define PROG_NULL_MODE 0x00
#define PROG_COUNTS_MODE 0x00
#define PROG_TIME_MODE  0x01

#define COM_RS232 0x01
#define COM_RS485 0x02
#define COM_UDISK 0x04
#define COM_ETH   0x08
#define COM_GPRS  0x10

#define GET_TEXT_LEN(W,H) (((W)%8) EQ 0)?((W)*(H)/8):(((W)/8+1)*(H))//((H%8) EQ 0)?(W*H/8):(W*(H/8+1))
#define GET_POINT_INDEX(W,X,Y) ((((W)%8)?((W)/8 + 1)*8:(W))*(Y) + (X))//((W)*(Y) + (X))//

#define GET_COLOR_NUM(X) (((X) < 3)?1:2)

#pragma pack(1)
typedef struct
{
  //INT8U Head;
  INT8U Flag;
  INT8U Value; //亮度值
  INT8U Start_Hour; //起始小时
  INT8U Start_Min;
  //INT8U Tail;
}S_Lightness;

typedef struct
{
  INT8U Direct; //进入方向
  INT8U Rows; //扫描1，2，4，8，16扫
  INT8U Rows_Fold; //每驱行折数,0表示不打折,1表示每1行打一次折，实际就有2行数据
  INT8U Cols_Fold; //每驱列折数,0表示不打折,1表示每1列打一次折
  INT8S Line_Order; //行序号,0,+1,-1
  
  INT8U Line_Hide; //行消隐时间
  INT8U Clk_Freq; //移位时钟频率
  INT8U Screen_Freq; //屏幕刷新频率
  
  INT8U Data_Polarity; //数据极性
  INT8U OE_Polarity; //OE极性
  INT8U RG_Reverse; //红绿反转

  INT8U _138Check; //是否138译码器，0表示有，1表示没有
}S_Scan_Para;

typedef struct
{
    INT8U Mode; //手动调节还是定时调节?
    INT8U Manual_Lightness;
    S_Lightness Time_Lightness[MAX_LIGHTNESS_TIME];

}S_Screen_Lightness;
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
    INT8U Flag; //是否定时开关机?
    S_Open_Close_Time Time[MAX_OPEN_CLOSE_TIME]; //定时开关机时段定义
}S_Screen_OC_Time;

typedef struct
{
  INT8U Week_Check;
  INT8U Week_Flag; //星期--全0表示都播放，第0位表示星期日，1-6表示星期1-星期6
  
  INT8U Date_Check;
  INT8U Start_Date[3]; //起始年月日
  INT8U End_Date[3];	//结束年月日  
  
  INT8U Time_Check;
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

typedef struct
{
  INT8U Head;
  INT32U Max_Points; //最大支持点数字
  INT16U Max_Height; //最大高度
  INT16U Flag; //第0表示表示是否支持全彩，1支持，2不支持，其他位备用
  INT8U Font_Num; //板上字体个数
  INT8U InMode_Num; //引入特效个数
  INT8U OutMode_Num; //引出特效个数

  INT8U Max_Prog_Num; //最大节目数
  INT8U Max_Area_Num; //最大分区数
  INT8U Max_File_Num; //每分区最大文件数

  INT8U Com_Mode; //支持的通信方式,第0位RS232、第1位RS485、第2位以太网、第3位GPRS/GSM
  INT16U ROM_Size; //存储空间大小,单位KB
  INT16U File_En_Word; //支持的节目类型
  INT8U Tail;
}S_Card_Para;

typedef struct
{

    INT16U Width; //宽度
    INT16U Height; //高度
    INT8U Color; //第0位红色，第一位绿色，第二位蓝色

}S_Screen_Base_Para;

//基本通信参数
typedef struct
{

    INT16U Addr; //地址
    //串口
    INT8U Baud;  //波特率,0表示57600,1表示9600

    INT8U Bak; //备用
}S_COM_Para;

//以太网参数
typedef struct
{
    //以太网
    INT32U IP; //IP地址
    INT16U Port; //端口
    INT32U Mac; //Mac地址
    INT32U Mask; //子网掩码
    INT8U Mode; //0固定ip方式，1自动获取方式
}S_ETH_Para;

typedef struct
{
    //以太网
    //GPRS服务器地址
    INT32U Srv_IP; //服务器IP
    INT16U Srv_Port; //服务器端口
    INT8U APN[40];
    INT8U Mode; //0唤醒方式，1在线方式
}S_GPRS_Para;

typedef struct
{
    INT8U Time[5];
}S_Valid_Date;

//屏幕参数
//数据级性--正、反
//OE级性--低有效、高有效
//行顺序--正常、+1、-1
//行消隐时间--正常、加长、超长
//扫描方式
typedef struct
{
  INT8U Head;

  //命令0
  /*
  INT8U Polarity; //数据极性
  INT8U OE; //OE极性

  INT16U Width; //宽度
  INT16U Height; //高度
  INT8U Color; //颜色 0单色，1双色，2三色，3-255级灰度
  
  INT16U Addr; //地址
  INT32U IP; //IP地址
  INT8U Baud;  //波特率
*/
  S_Screen_Base_Para Base_Para; //基本参数
//#if QT_EN > 0
  //INT8U Com_Port; //串口的端口号-主台用
  //INT8U Com_Mode; //选用通信模式-主台用
//#endif

  S_COM_Para COM_Para; //通信参数-基本通信参数

  S_ETH_Para ETH_Para; //以太网参数

  S_GPRS_Para GPRS_Para; //GPRS参数

  S_Scan_Para Scan_Para; //扫描参数
  //命令1
  S_Screen_OC_Time OC_Time;//Open_Close_Time[MAX_OPEN_CLOSE_TIME]; //开关机时间
  //命令2
  S_Screen_Lightness Lightness;//[MAX_LIGHTNESS_TIME]; //强度

  S_Valid_Date Valid_Date; //有效日期--到达改日期后自动关闭--全0表示不启用改参数
  //命令3
  //INT8U Prog_Num; //节目数
  INT8U CS[CS_BYTES];

  INT8U Tail;
}S_Screen_Para;

typedef struct
{
  INT8U Head;
  INT8U Num;
  INT8U Tail;
  INT8U CS[CS_BYTES];
}S_Prog_Num;

//节目属性
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
  INT8U Border_Mode;  //边框模式
  INT8U Border_Speed;

  INT8U Border_Width;   //边框宽度
  INT8U Border_Height;  //边框高度
  INT8U Temp;   //备用
//#if BORDER_SHOW_EN > 0  
  INT8U Border_Data[2*MAX_BORDER_POINTS/8]; //边框数据
//#endif  
  INT8U CS[CS_BYTES];
  
  INT8U Tail;
}S_Prog_Para;

/*
  INT8U Flag; \//标志
  INT8U Prog_No; \//节目号
  INT8U Area_No; \//分区号
  INT8U File_No; \//文件号
  INT8U In_Mode; \//引入方式
  INT16U In_Speed; \//进入速度
  INT8U Add_Mode; \//追加方式
  INT16U Stay_Time; \//停留时间，最高位为单位，0表示s，1表示ms
  INT8U Out_Mode; \//引出方式
  INT16U Out_Speed; \//引出时间
  INT16U SNum; \//分屏个数
  INT8U Play_Counts; \
  INT8U Border_Check; \//是否边框
  INT8U Border_Type; \//边框类型
  INT8U Border_Color; \//边框颜色
  INT8U Border_Mode; \//边框模式
  INT8U Border_Speed //停留时间
*/
#define BASE_PIC_PARA  INT8U Flag; \
  INT8U Prog_No; \
  INT8U Area_No; \
  INT8U File_No; \
  INT8U In_Mode; \
  INT8U In_Speed; \
  INT16U Stay_Time; \
  INT8U Out_Mode; \
  INT8U Out_Speed; \
  INT16U SNum; \
  INT8U Play_Counts; \
  INT8U Border_Check; \
  INT8U Border_Type; \
  INT8U Border_Color; \
  INT8U Border_Mode; \
  INT8U Border_Speed;\

//图文参数
typedef struct
{
  INT8U Head;
/*  
  INT8U Flag; //标志
  INT8U Prog_No; //节目号
  INT8U Area_No; //分区号
  INT8U File_No; //文件号
  INT8U In_Mode; //引入方式
  INT16U In_Speed; //进入速度
  INT8U Add_Mode; //追加方式
  INT16U Stay_Time; //停留时间，最高位为单位，0表示s，1表示ms
  INT8U Out_Mode; //引出方式
  INT16U Out_Speed; //引出时间
  INT16U SNum; //分屏个数

  INT8U Play_Counts;

  INT8U Border_Check; //是否边框
  INT8U Border_Type; //边框类型
  INT8U Border_Color; //边框颜色
  INT8U Border_Mode; //边框模式
  INT8U Border_Speed; //停留时间
 */
  BASE_PIC_PARA
//-------------------------------------------

  //INT8U Color; //颜色

  INT8U CS[CS_BYTES];
  INT8U Tail;
}S_Pic_Para;

//表盘参数
typedef struct
{
  INT8U Head;
  
  BASE_PIC_PARA
//-------------------------------------------
  INT8U Diff_Flag;  //时差标志,0加，1减  
  INT8U Hour_Diff;  //时差小时
  INT8U Min_Diff;   //时差分钟
  //INT8U Sec_Diff;   //时差秒钟
  
  INT8U Hour_Point_Radius; //整点半径
  INT8U Hour_Point_Color; ///整点颜色
  INT8U Hour_Point_Style; //整点样式
  
  INT8U Hour369_Point_Radius; //369点半径
  INT8U Hour369_Point_Color;  //369点颜色
  INT8U Hour369_Point_Style;  //369点样式

  INT8U Min_Point_Radius; //分点半径
  INT8U Min_Point_Color;  //分点颜色
  INT8U Min_Point_Style;  //分点样式,0圆形，1方形，2数字，3线型

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
  
  BASE_PIC_PARA
//-------------------------------------------
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
  
  BASE_PIC_PARA
//-------------------------------------------
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

  BASE_PIC_PARA
//-------------------------------------------
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
  
  BASE_PIC_PARA
//-------------------------------------------
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

//湿度参数
typedef struct
{
  INT8U Head;
  
  BASE_PIC_PARA
//-------------------------------------------
  INT8U Show_Mode;  //显示方式 
  INT8U Show_Color; //显示颜色
  INT8U Show_Font; //显示字号
  INT8U Show_Posi; //显示位置
  
  INT8U Humidity; //备用

  INT8U Humidity_Type;  //湿度显示方式
  INT8U Humidity_Font;  //湿度字体
  INT8U Humidity_Color; //湿度颜色
  INT16U Humidity_X;    
  INT16U Humidity_Y;
  
  INT8U Text_Color; //背景颜色
  INT16U Text_X; //背景X
  INT16U Text_Y; //背景Y
  INT16U Text_Width; //背景宽度
  INT16U Text_Height; //背景高度

  INT8U CS[CS_BYTES];
  INT8U Tail;
}S_Humidity_Para;

//噪音参数
typedef struct
{
  INT8U Head;
  
  BASE_PIC_PARA
//-------------------------------------------
  INT8U Show_Mode;  //显示方式 
  INT8U Show_Color; //显示颜色
  INT8U Show_Font; //显示字号
  INT8U Show_Posi; //显示位置
  
  INT8U Noise; //备用

  INT8U Noise_Type;  //噪音显示方式
  INT8U Noise_Font;  //噪音字体
  INT8U Noise_Color; //噪音颜色
  INT16U Noise_X;    
  INT16U Noise_Y;
  
  INT8U Text_Color; //背景颜色
  INT16U Text_X; //背景X
  INT16U Text_Y; //背景Y
  INT16U Text_Width; //背景宽度
  INT16U Text_Height; //背景高度

  INT8U CS[CS_BYTES];
  INT8U Tail;
}S_Noise_Para;

//所有参数的联合
typedef union
{
#if PIC_SHOW_EN  
  S_Pic_Para Pic_Para;
#endif
#if CLOCK_SHOW_EN  
  S_Clock_Para Clock_Para;
#endif
#if TIMER_SHOW_EN  
  S_Timer_Para Timer_Para;
#endif
#if TIME_SHOW_EN  
  S_Time_Para Time_Para;
#endif
#if LUN_SHOW_EN  
  S_Lun_Para Lun_Para;
#endif
#if TEMP_SHOW_EN  
  S_Temp_Para Temp_Para;
#endif  
#if HUMIDITY_SHOW_EN
  S_Humidity_Para Humidity_Para;
#endif
#if NOISE_SHOW_EN
  S_Noise_Para Noise_Para;
#endif  
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
/*
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
*/
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
  
  INT16U Seq0;
   
  INT16U Len;
  INT16U Bak;
  
}S_File_Para_Info;

#pragma pack()

typedef struct
{/*
  S_Pub_Buf Pub_Buf;  //公共buf
  S_Show_1Color_Data One_Color_Data;
  S_Show_2Color_Data Two_Color_Data;
  S_Show_3Color_Data Three_Color_Data;
  */
  INT8U Head;
  INT8U Color_Data[2*MAX_POINTS/8];//---连续的2个字节表示八个点3个颜色!!
  INT8U Tail;
}S_Show_Data;

#define SCREEN_PARA_LEN (sizeof(S_Screen_Para) -CHK_BYTE_LEN)
#define PROG_PARA_LEN   (sizeof(S_Prog_Para)-CHK_BYTE_LEN)
#define PROG_NUM_LEN    (sizeof(S_Prog_Num)-CHK_BYTE_LEN)
#define FILE_PARA_LEN (sizeof(U_File_Para)-CHK_BYTE_LEN)
#define BLOCK_INDEX_LEN (sizeof(S_Prog_Block_Index) - CHK_BYTE_LEN)
//#define BLOCK_DATA_LEN 249
#define BLOCK_HEAD_DATA_LEN 9
#define BLOCK_SHOW_DATA_LEN (BLOCK_DATA_LEN -BLOCK_HEAD_DATA_LEN)


#define MAX(a,b,c,d) (((a)>(b)?(a):(b))>(c)?((a)>(b)?(a):(b)):(c))>(d)?(((a)>(b)?(a):(b))>(c)?((a)>(b)?(a):(b)):(c)):(d)
#define MAX_COM_BUF_LEN (MAX(BLOCK_DATA_LEN , SCREEN_PARA_LEN, FILE_PARA_LEN, PROG_PARA_LEN)) + 20

typedef struct
{
  INT8U Head;
  INT8U Buf[MAX_COM_BUF_LEN];
  INT8U Tail;
}S_Pub_Buf;

#ifdef LED_PARA_C
EXT S_Pub_Buf _Pub_Buf = {CHK_BYTE,{0}, CHK_BYTE};
#else
EXT S_Pub_Buf _Pub_Buf;
#endif

EXT S_Screen_Para Screen_Para; //显示屏相关参数
EXT S_Card_Para Card_Para;   //板卡支持的参数
EXT S_Prog_Para Prog_Para;  //当前节目属性[MAX_PROGRAM_NUM]; //节目个数
EXT S_Prog_Num Prog_Num;
//EXT S_Prog_Block_Index Prog_Block_Index; //当前节目的存储参数
EXT S_Cur_Block_Index Cur_Block_Index;
//EXT S_Clock_Para Clock_Para;
//EXT S_Rcv_Show_Data Rcv_Show_Data;

EXT S_Time Cur_Time; //当前时间 
EXT INT8U Get_Screen_Color_Num(void);
EXT void Chk_Baud_Change(INT8U Old_Baud);
EXT void Clr_All_Show_Data(void);
EXT void Chk_Data_Polarity_Change(INT8U Old_Polarity);
EXT INT8U Write_Prog_Num(void);
EXT INT8U Read_Prog_Num(void);
EXT INT16U Read_Screen_Para(void);
EXT INT8U Write_Screen_Para(void);
EXT INT16U _Read_Prog_Para(INT8U Prog_No, INT8U *pDst, INT8U *pDst_Start, INT16U DstLen);
EXT INT16U Read_Prog_Para(INT8U Prog_No, S_Prog_Para *pProg_Para);
EXT INT8U Write_Prog_Para(INT8U Prog_No, INT8U *pSrc,INT16U SrcLen);
EXT INT8U Write_File_Para(INT8U Prog_No, INT8U Area_No, INT8U File_No, void *pSrc, INT16U SrcLen);
EXT INT8U Write_Cur_Block_Index(void *pSrc, INT16U SrcLen);
EXT INT8U Get_Show_Para_Len(INT8U Type);
EXT STORA_DI Get_Show_Para_Stora_DI(INT8U Prog_No, INT8U Area_No, INT8U File_No);
EXT INT16U Read_File_Para(INT8U Prog_No, INT8U Area_No, INT8U File_No, void *pDst, void *pDst_Start, INT16U DstLen);
EXT INT8U Chk_File_Para_HT_Sum(U_File_Para *pPara);
EXT void Set_File_Para_HT_Sum(U_File_Para *pPara);
EXT INT8U Write_Prog_Block_Index(void);
EXT INT16U Read_Prog_Para(INT8U Prog_No, S_Prog_Para *pProg_Para);
EXT INT16U Read_Prog_Block_Index(INT8U Prog_No);
EXT INT16U _Read_Prog_Block_Index(INT8U Prog_No, void *pDst, void *pDst_Start, INT16U DstLen);
EXT INT16S Read_Show_Data_Point(INT8U Area_No, INT8U File_No, U_File_Para *pFile_Para, INT16U SIndex, \
                                  S_Show_Data *pShow_Data, INT16U X, INT16U Y);
EXT INT16S Read_Show_Data(INT8U Area_No, INT8U File_No, U_File_Para *pFile_Para, INT16U SIndex, \
                      S_Show_Data *pShow_Data, INT16U *pX, INT16U *pY, INT16U *pWidth, INT16U *pHeight);
//}
#endif // LED_PARA_H
