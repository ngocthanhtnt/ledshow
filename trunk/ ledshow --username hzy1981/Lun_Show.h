#ifndef LUN_SHOW_H
#define LUN_SHOW_H

#include "Includes.h"

#if LUN_SHOW_EN

#undef EXT
#ifdef LUN_SHOW_C
#define EXT
#else
#define EXT extern
#endif

EXT INT16U Get_Lun_Min_Width(INT8U Area_No);
EXT INT16U Get_Lun_Min_Height(INT8U Area_No);
EXT INT16U Get_TianganStr_Width(INT8U Font);
EXT INT16U Get_NongliStr_Width(INT8U Font, char str[]);
EXT INT16U Get_JieqiStr_Width(INT8U Font);
EXT void Update_Lun_Data_Bak(INT8U Area_No);
#endif
#endif

