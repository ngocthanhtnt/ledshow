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

#define PI 3.1415926535

#define MAX_STEP_NUM 100

#define RT_PLAY_FLAG 0x35

#define SLINE_MODE 0x00
#define MLINE_MODE 0x01

#define GET_LINE_Y(X0,Y0,X1,Y1,X) ((X1 != X0)?(((Y1)-(Y0))*((X)-(X0))/((X1)-(X0)) + (Y0) + 0.5):((Y0) + 0.5))
#define GET_LINE_X(X0,Y0,X1,Y1,Y) ((Y1 != Y0)?(((X1)-(X0))*((Y)-(Y0))/((Y1)-(Y0)) + (X0) + 0.5):((X0) + 0.5))

#define AREA_ERR 2 //¸üÐÂÏÔÊ¾ÎÄ¼þ³ö´í
#define AREA_END 0 //¸Ã·ÖÇø½áÊø
#define AREA_OK  1 //¸üÐÂ³É¹¦

#define PROG_END 0 //½ÚÄ¿½áÊø
#define PROG_OK  1 //½ÚÄ¿ok

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
//#define PUB_BUF Show_Data_Bak.Pub_Buf.Buf //¹«¹²Êý¾ÝÇø£¬ÓëÏÔÊ¾Êý¾Ý¹«ÓÃ
/*
//Ê±¼ä
typedef struct
{
INT8U Head;
INT8U Time[5]; //Äê¡¢ÔÂ¡¢ÈÕ¡¢Ê±¡¢·Ö	
INT8U Tail;
}S_Time;
*/
/*
//ÈýÉ«ÏÔÊ¾Êý¾Ý
typedef struct
{
  INT8U Head;
  INT8U Color0[MAX_POINTS/3]; //ºìÉ«
  INT8U Color1[MAX_POINTS/3]; //À¶É«
  INT8U Color2[MAX_POINTS/3]; //»ÆÉ«
  INT8U Tail;
}S_Show_3Color_Data;

//Ë«É«ÏÔÊ¾Êý¾Ý
typedef struct
{
  INT8U Head;
  INT8U Color0[MAX_POINTS/2];
  INT8U Color1[MAX_POINTS/2];
  INT8U Tail;
}S_Show_2Color_Data;

//µ¥É«ÏÔÊ¾Êý¾Ý
typedef struct
{
  INT8U Head;
  INT8U Color0[MAX_POINTS];
  INT8U Tail;
}S_Show_1Color_Data;
*/
//µãµÄ¶¨Òå
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

//¶¨Òå·ÖÇø×´Ì¬
typedef struct
{
  INT8U Head;

  INT16U SCN_No;      //µ±Ç°ÒÑ¾­¶Áµ½µÚ¼¸ÆÁÊý¾ÝÁË?

  INT8U New_File_Flag:4;
  INT8U New_SCN_Flag:4;
  INT8U New_CStep_Flag; //ÐÂµÄÁ¬ÒÆ²½Öè

  INT8U File_No;    //µ±Ç°ÎÄ¼þºÅ

  INT8U Play_Counts; //²¥·Å´ÎÊý
  //INT8U RT_Play_Flag; //ÊµÊ±²¥·Å±êÖ¾
  //INT8U Play_Flag; //²¥·Å±êÖ¾£¬0±íÊ¾Î´½øÈë²¥·Å×´Ì¬£¬1±íÊ¾½øÈë²¥·Å×´Ì¬--Ö÷ÒªÓÃÓÚÓëÖÐ¶ÏÏÔÊ¾Í¬²½
  //INT8U Restore_Border_Flag:4;
  //INT8U Update_BG_Flag:4;

  INT8U Last_File_No; //ÉÏ´Î¶ÁÈ¡µÄÎÄ¼þ²ÎÊý
  INT16U Last_SCN_No; //Ç°´Î¶ÁÈ¡µÄÆÁÄ»ºÅ

  INT8U CS[CS_BYTES];//Ç°ÃæµÄÊý¾Ý¶¼´øÐ£ÑéºÍ

  INT16U Step;        //µ±Ç°ÒÆ¶¯µÄ½×ÌÝ
  INT16U Max_Step;
  INT32U Step_Timer;  //ÒÑ¾­×ß¹ýTimer£¬µ¥Î»ms
  INT32U Stay_Time;   //ÒÑ¾­Í£ÁôµÄÊ±¼ä£¬µ¥Î»ms
  //INT32U Out_Time;   //ÍË³öÊ±¼ä
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
  INT32U Step;   //²½³¤
  INT16U Timer; //ÒÑ¾­×ß¹ýµÄTimer
  INT8U Tail;  
}S_Border_Status;

typedef struct
{
    INT8U Head;
    INT8U Last_Prog_No; //ÉÏ¸ö½ÚÄ¿
    INT8U Prog_No; //µ±Ç°½ÚÄ¿ºÅ

	INT8U RT_Play_Flag; //ÊµÊ±²¥·Å±êÖ¾
	INT16U RT_Play_Time;	//ÊµÊ±²¥·ÅÊ±¼ä

    INT32U Time; //ÒÑ¾­²¥·ÅÊ±³¤
    INT16U Counts; //ÒÑ¾­²¥·Å´ÎÊý



    INT8U Play_Flag:4; //ÊÇ·ñ²¥·Å±êÖ¾--Ö÷ÒªÓÃÓÚÓëÖÐ¶ÏÏÔÊ¾Í¬²½
    INT8U New_Prog_Flag:4;
    INT8U CS[CS_BYTES];

	INT32U Effect_Counts;
	INT8U Effect_Flag; //ÌØÐ§±ê¾
	INT32U Max_Effect_Counts;

    INT8U Tail;
}S_Play_Status;

//¶¨Òå½ÚÄ¿×´Ì¬
typedef struct
{
  INT8U Head;
  
  S_Play_Status Play_Status;

  S_Border_Status Border_Status[MAX_AREA_NUM + 1];
  U_File_Para File_Para[MAX_AREA_NUM]; //Ã¿¸ö·ÖÇøµÄµ±Ç°ÎÄ¼þ²ÎÊý


  S_Area_Status Area_Status[MAX_AREA_NUM]; //Ã¿¸ö·ÖÇøµÄ×´Ì¬ 
  S_Prog_Block_Index Block_Index; //µ±Ç°½ÚÄ¿µÄË÷Òý

  INT8U CS[CS_BYTES];
  INT8U Tail;
}S_Prog_Status;

typedef struct
{
  INT8U Head;

  //INT8U RT_Play_Flag;
  //INT8U Com_Time; //Í¨ÐÅµ¹¼ÆÊ±
  INT8U JP_Status;	 //ÌøÏß×´Ì¬

  INT8U Replay_Flag;
  INT8U Lightness;
  INT8U Color_Num;

  INT16U Temp;    //µ±Ç°ÎÂ¶È
  INT16U Humidity; //Êª¶È
  INT16U Noise; //ÔëÒô

  INT8U Time_OC_Flag;	//¶¨Ê±¿ª¹Ø»ú±êÖ¾
  INT8U Manual_OC_Flag; //ÊÖ¶¯¹Ø»ú±êÖ¾
  INT8U UDisk_Flag; //ÊÇ·ñÓÐUÅÌ²åÈë

  INT8U CS[CS_BYTES];

  //É¨ÃèÊý¾Ý
  INT16U Fold_Size;
  INT16U BRow_X_RowsFold;
  INT16U Rows_X_RowsFold;
  INT16U Block_Cols; //Ò»ÌõÉ¨ÃèÏßµÄ¿í¶È

  INT8U Scan_Row;

  //½ÓÊÕÖ¡Êý¾Ý
  INT8U Rcv_Ch; //½ÓÊÕÍ¨µÀ
  INT8U Rcv_Flag; //½ÓÊÕµ½µÄÊý¾Ý
  INT8U Head_Flag; //ÊÕµ½Í·µÄ±êÖ¾
  INT8U Com_Time;  //Í¨ÐÅÎ¬³ÖÊ±¼ä
  INT8U Byte_Time; //½ÓÊÜ×Ö½Úµ¹¼ÆÊ±
  INT16U Rcv_Posi;

  INT8U Rcv_Data[((BLOCK_DATA_LEN > SCREEN_PARA_LEN) ? BLOCK_DATA_LEN : SCREEN_PARA_LEN) + 20];

  INT8U Self_Test_Flag;
  INT8U Tail;  
}S_Screen_Status;

#pragma pack()

//EXT S_Area_Status Area_Status[MAX_AREA_NUM]; //·ÖÇø×´Ì¬ÐÅÏ¢
EXT volatile S_Prog_Status Prog_Status;   //½ÚÄ¿×´Ì¬ÐÅÏ¢
EXT volatile S_Screen_Status Screen_Status;

EXT S_Show_Data Show_Data;  //ÏÔÊ¾Êý¾Ý
EXT S_Show_Data Show_Data_Bak; //ÏÔÊ¾Êý¾Ý±¸·Ý

#if DATA_PREP_EN
EXT S_Show_Data Show_Data_Prep;
#endif
//#define Pub_Buf Show_Data.Color_Data

//»ñÈ¡µ±Ç°ÑÕÉ«·½°¸
EXT INT8U Get_Color(void); //»ñÈ¡µ±Ç°µÄÑÕÉ«·½°¸
EXT INT8U Get_Bit(INT8U *p,INT16U X_Size,INT16U X,INT16U Y);
EXT INT8U Get_Buf_Bit(INT8U Buf[], INT32U Buf_Size, INT32U Index);
EXT INT8U Get_Rect_Buf_Bit(INT8U Buf[], INT16U Buf_Size, INT16U Width, INT16U X, INT16U Y);
EXT void Set_Buf_Bit(INT8U Buf[], INT32U Buf_Size, INT32U Index, INT8U Value);
EXT INT16U Get_Area_Width(INT8U Area_No);
EXT INT16U Get_Area_Height(INT8U Area_No);
EXT INT32U Get_Area_Size(INT8U Area_No);
EXT INT8U Get_Area_TopLeft(INT8U Area_No, S_Point *pPoint);
EXT INT32U Get_Area_Point_Index(INT8U Area_No, INT16U X, INT16U Y); //»ñÈ¡Ä³¸öÇøÓòµÄÊý¾Ý»º³åÇøÆðÊ¼
//¶àÎ»µÄ¿½±´
EXT void Bits_Copy(INT8U *pSrc, INT16U Src_Len, INT32U Src_Index, INT32U Bits, INT8U *pDst, INT16U Dst_Len, INT32U Dst_Index);
EXT INT8U Get_Buf_Point_Data(INT8U Buf[], INT16U Buf_Len, INT8U Color, INT16U Width, INT16U X, INT16U Y);
EXT void Set_Buf_Point_Data(INT8U Buf[], INT16U Buf_Len, INT8U Color, INT8U Width, INT16U X, INT16U Y, INT8U Value);
//»ñÈ¡Ò»¸öÇøÓòÖÐµÄÒ»¸öµã
EXT INT8U Get_Area_Point_Data(S_Show_Data *pSrc_Buf, INT8U Area_No, INT16U X, INT16U Y); //»ñÈ¡Ò»¸öÇøÓòÄÚÒ»¸öµãµÄÊý¾Ý
//ÉèÖÃÒ»¸öÇøÓòÖÐµÄÒ»¸öµã
EXT void Set_Area_Point_Data(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, INT8U Data); //ÉèÖÃÒ»¸öÇøÓòµÄµã
//»æÖÆÒ»ÌõÏß
EXT void Draw_Line(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1, INT8U Value);
//¸´ÖÆÒ»ÌõÏß
EXT void Copy_Line(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1, S_Show_Data *pDst_Buf, S_Point *pPoint2);
//¸´ÖÆÒ»¸öÌî³äºÃµÄ¾ØÐÎ
EXT void Copy_Filled_Rect(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, INT16U X_Len, INT16U Y_Len, S_Show_Data *pDst_Buf, S_Point *pPoint1, INT8U Flag);
//·´Ïò¸´ÖÆÒ»¸öÌî³äºÃµÄ¾ÙÐÐ
EXT void Rev_Copy_Filled_Rect(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, INT16U X_Len, INT16U Y_Len, S_Show_Data *pDst_Buf, S_Point *pPoint1);
//Ìî³äÒ»¸ö¾ØÐÎ
EXT void Fill_Rect(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, INT16U X_Len, INT16U Y_Len,INT8U Value);
//¸´ÖÆÒ»¸öÈý½ÇÐÎÊý¾Ý
EXT void Copy_Filled_Triangle(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pSrc_Point0, S_Point *pSrc_Point1,S_Point *pSrc_Point2,\
  S_Show_Data *pDst_Buf, S_Point *pDst_Point0);  //¸´ÖÆÒ»¸öÈý½ÇÐÎÇøÓò
//Ìî³äÒ»¸öÈý½ÇÇøÓò
EXT void Fill_Triangle(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, S_Point *pPoint1,S_Point *pPoint2, INT8U Value);
//¸´ÖÆÒ»¸öÊµÐÄÔ²
EXT void Copy_Filled_Round(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pCenter0, INT16U Radius, S_Show_Data *pDst_Buf, S_Point *pCenter1);
//Ìî³äÒ»¸öÊµÐÄÔ²
EXT void Fill_Round(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pCenter, INT16U Radius, INT8U Value);
//¸´ÖÆÒ»¸ö¶à±ßÐÎ
EXT void Copy_Filled_Polygon(S_Show_Data *pSrc_Buf, INT8U Area_No, S_Point *pPoint0, INT8U Point_Num, S_Show_Data *pDst_Buf, S_Point *pPoint1);
//Ìî³äÒ»¸ö¶à±ßÐÎ
EXT void Fill_Polygon(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pPoint0, INT8U Point_Num, INT8U Value);
//»ñÈ¡Ä³µã¶ÔÒ»¸öÒ»¸ö½Ç¶ÈºÍ³¤¶ÈµÄµã
EXT void Get_Angle_Point(S_Point *pPoint0, INT16S Angle, INT16U Len, S_Point *pPoint1);
//Ìî³ä±íÅÌÊ±ÖÓÕûµã
EXT void Fill_Clock_Point(S_Show_Data *pDst_Buf, INT8U Area_No, S_Point *pCenter, INT16S Angle, INT16U Len, INT16U Radius, INT8U Style, INT8U Value);
//Ìî³äÊ±ÖÓ¡¢·ÖÖÓ»òÃëÖÓµÄÖ¸Õë
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
EXT void Move_Left_Tensile(INT8U Area_No);//×óÀ­Éì
EXT void Move_Right_Tensile(INT8U Area_No);//ÓÒÀ­Éì
EXT void Move_Up_Tensile(INT8U Area_No);//ÉÏÀ­Éì
EXT void Move_Down_Tensile(INT8U Area_No);//ÏÂÀ­Éì
EXT void Move_Vertical_Tensile(INT8U Area_No);//Ë®Æ½À­Éì
EXT void Move_Horizontal_Tensile(INT8U Area_No);//´¹Ö±À­Éì
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
