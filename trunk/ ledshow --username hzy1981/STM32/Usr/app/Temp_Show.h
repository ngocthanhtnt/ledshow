#ifndef TEMP_SHOW_H
#define TEMP_SHOW_H

#include "Includes.h"

#if TEMP_SHOW_EN

#undef EXT
#ifdef TEMP_SHOW_C
#define EXT
#else
#define EXT extern
#endif

EXT INT16U Get_TempStr_Pix_Width(INT8U Type, INT8U Font);
EXT INT16U Get_Temp_Min_Width(INT8U Area_No);
EXT INT16U Get_Temp_Min_Height(INT8U Area_No);
EXT void Show_Temp(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, INT16S Temp, INT8U Type, INT8U Font, INT8U Color);
EXT void Update_Temp_Data(S_Show_Data *pDst, INT8U Area_No);
#endif

#endif


