#ifndef TIMER_SHOW_H
#define TIMER_SHOW_H

#include "Includes.h"

#undef EXT
#ifdef TIMER_SHOW_C
#define EXT
#else
#define EXT extern
#endif

EXT void Update_Timer_Data(INT8U Area_No);
#endif
