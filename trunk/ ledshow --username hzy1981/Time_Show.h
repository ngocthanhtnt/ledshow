#ifndef TIME_SHOW_H
#define TIME_SHOW_H

#include "Includes.h"

#undef EXT
#ifdef TIME_SHOW_C
#define EXT
#else
#define EXT extern
#endif


typedef struct
{
  char str[16];
  INT8U Len;

}S_Format_Str;

EXT INT16U Get_DateStr_Pix_Width(INT8U Type, INT8U Font);
EXT INT16U Get_WeekStr_Pix_Width(INT8U Type, INT8U Font, INT8U Week);
EXT INT16U Get_TimeStr_Pix_Width(INT8U Type, INT8U Font);
EXT void Show_Time(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, S_Time *pTime, INT8U Type, INT8U Font, INT8U Color);
EXT void Show_Date(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, S_Time *pTime, INT8U Type, INT8U Font, INT8U Color);
EXT void Show_Week(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, S_Time *pTime, INT8U Language, INT8U Font, INT8U Color);
EXT void Update_Time_Data(INT8U Area_No);

#endif
