#ifndef CLOCK_SHOW_H
#define CLOCK_SHOW_H

#include "includes.h"

#undef EXT
#ifdef CLOCK_SHOW_C
#define EXT
#else
#define EXT extern
#endif

EXT void S_Time_2_tm(S_Time *pTime, struct tm *ptm);
EXT void tm_2_S_Time(struct tm *ptm, S_Time *pTime);
EXT void Show_Clock(S_Show_Data *pDst_Buf, INT8U Area_No, S_Time *pTime, S_Clock_Para *pClock_Para);
EXT void Update_Clock_Data(INT8U Area_No);
#endif
