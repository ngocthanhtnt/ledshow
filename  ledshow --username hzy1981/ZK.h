#ifndef ZK_H
#define ZK_H

#include "led_show.h"

#define FONT16_WIDTH 16
#define FONT24_WIDTH 24
#define FONT32_WIDTH 32

#define FONT16 0
#define FONT24 1
#define FONT32 2

//extern char * Get_Program_Data_File_Name(INT8U Prog_No, INT8U Area_No, char File_Name[]);
typedef struct{
  INT16U Code;
  INT8U CN16_Dot[32]; //16*16
  INT8U CN24_Dot[72]; //24*24
  INT8U CN32_Dot[128]; //32*32
}CNZK_Info;

void LED_Print(INT8U Font, INT8U Color, S_Show_Data *pData,  INT8U Area_No, INT16U X, INT16U Y,const INT8S *format, ...);
#endif
