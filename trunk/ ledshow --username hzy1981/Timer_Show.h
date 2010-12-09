#ifndef TIMER_SHOW_H
#define TIMER_SHOW_H

#include "Includes.h"

#undef EXT
#ifdef TIMER_SHOW_C
#define EXT
#else
#define EXT extern
#endif

EXT INT16U Get_Timer_Min_Width(INT8U Area_No);
EXT INT16U Get_Timer_Min_Height(INT8U Area_No);
EXT INT16U Show_Timer(S_Show_Data *pDst_Buf, INT8U Area_No, INT16U X, INT16U Y, S_Time *pCurTime, S_Time *pDstTime, INT8U Type, INT8U Font, INT8U Color);
EXT INT32U mktime(INT16U year, INT16U mon, \
                  INT16U day, INT16U hour, \
                  INT16U min, INT16U sec);
EXT void Update_Timer_Data(INT8U Area_No);
#endif
