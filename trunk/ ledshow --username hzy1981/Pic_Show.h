#ifndef PIC_SHOW_H
#define PIC_SHOW_H

#include "Includes.h"

#if PIC_SHOW_EN

#undef EXT
#ifdef PIC_SHOW_C
#define EXT
#else
#define EXT extern
#endif

typedef struct
{
  void (*Func)(INT8U);
}S_Mode_Func;

EXT void Update_Pic_Data(INT8U Area_No);
#endif
#endif

