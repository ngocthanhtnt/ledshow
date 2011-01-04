#ifndef CLOCK_SHOW_H
#define CLOCK_SHOW_H

#include "includes.h"

#if CLOCK_SHOW_EN

#undef EXT
#ifdef CLOCK_SHOW_C
#define EXT
#else
#define EXT extern
#endif


EXT void Show_Clock(S_Show_Data *pDst_Buf, INT8U Area_No, S_Time *pTime, S_Clock_Para *pClock_Para);
EXT void Update_Clock_Data_Bak(INT8U Area_No);
#endif

#endif

