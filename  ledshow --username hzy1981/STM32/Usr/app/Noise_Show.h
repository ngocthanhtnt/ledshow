#ifndef NOISE_SHOW_H
#define NOISE_SHOW_H

#include "Includes.h"

#if NOISE_SHOW_EN

#undef EXT
#ifdef NOISE_SHOW_C
#define EXT
#else
#define EXT extern
#endif

EXT INT16U Get_NoiseStr_Pix_Width(INT8U Type, INT8U Font);
EXT INT16U Get_Noise_Min_Width(INT8U Area_No);
EXT INT16U Get_Noise_Min_Height(INT8U Area_No);
EXT void Show_Noise(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, INT16U Noise, INT8U Type, INT8U Font, INT8U Color);
EXT void Update_Noise_Data(S_Show_Data *pDst, INT8U Area_No);
#endif

#endif


