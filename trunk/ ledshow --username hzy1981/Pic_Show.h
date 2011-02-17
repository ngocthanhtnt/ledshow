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

#define H_MODE  0x00
#define V_MODE  0x01
#define HV_MODE 0x02

typedef struct
{
  void (*Func)(INT8U);
  INT8U Step_Mode; //步进模式,0-横向，1纵向，3纵横同步
  INT8U Fac; //0,1表示1，其他表示
}S_Mode_Func;

EXT void Update_Pic_Data(INT8U Area_No);
#endif
#endif

