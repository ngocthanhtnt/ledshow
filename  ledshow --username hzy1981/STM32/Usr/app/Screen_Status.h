#ifndef SCREEN_STATUS_H
#define SCREEN_STATUS_H

#undef EXT
#ifdef LIGHTNESS_C
#define EXT
#else
#define EXT extern
#endif

//#define MAX_LIGHTNESS_LEVEL 0x09

EXT void Screen_Lightness_Proc();
EXT void Screen_Open_Close_Proc();
EXT INT8U Get_Screen_Lightness();
EXT INT8U Get_Screen_Open_Status();
EXT void Screen_Proc();
#endif
