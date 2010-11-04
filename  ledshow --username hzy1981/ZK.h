#ifndef ZK_H
#define ZK_H

#include "led_show.h"

#undef EXT
#ifdef ZK_C
#define EXT
#else
#define EXT extern
#endif

#define FONT0_WIDTH 16
#define FONT1_WIDTH 24
#define FONT2_WIDTH 32

#define FONT0 0
#define FONT1 1
#define FONT2 2

//extern char * Get_Program_Data_File_Name(INT8U Prog_No, INT8U Area_No, char File_Name[]);
typedef struct{
  INT16U Code;
  INT8U CN16_Dot[32]; //16*16
  INT8U CN24_Dot[72]; //24*24
  INT8U CN32_Dot[128]; //32*32
}CNZK_Info;

EXT INT8U Get_Font_Width(INT8U Font);
EXT INT8U Get_Font_Height(INT8U Font);
EXT INT16U Get_String_Width(INT8U Font, char Str[]);
EXT INT16U Get_String_Height(INT8U Font, char Str[]);
void LED_Print(INT8U Font, INT8U Color, S_Show_Data *pData,  INT8U Area_No, INT16U X, INT16U Y,const INT8S *format, ...);
#endif
