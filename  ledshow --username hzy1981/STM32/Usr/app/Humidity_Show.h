#ifndef HUMIDITY_SHOW_H
#define HUMIDITY_SHOW_H

#include "Includes.h"

#if HUMIDITY_SHOW_EN

#undef EXT
#ifdef HUMIDITY_SHOW_C
#define EXT
#else
#define EXT extern
#endif

EXT INT16U Get_HumidityStr_Pix_Width(INT8U Type, INT8U Font);
EXT INT16U Get_Humidity_Min_Width(INT8U Area_No);
EXT INT16U Get_Humidity_Min_Height(INT8U Area_No);
EXT void Show_Humidity(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, INT16U Humidity, INT8U Type, INT8U Font, INT8U Color);
EXT void Update_Humidity_Data(S_Show_Data *pDst, INT8U Area_No);
#endif

#endif


