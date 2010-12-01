#ifndef TEMP_SHOW_H
#define TEMP_SHOW_H

#include "Includes.h"

#undef EXT
#ifdef TEMP_SHOW_C
#define EXT
#else
#define EXT extern
#endif

EXT void Update_Temp_Data(INT8U Area_No);
#endif

