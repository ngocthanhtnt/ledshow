#ifndef SCREEN_STATUS_H
#define SCREEN_STATUS_H

#undef EXT
#ifdef LIGHTNESS_C
#define EXT
#else
#define EXT extern
#endif

#define REPLAY_FLAG 0x5F
#define COM_FLAG    0xF9

#define MANUAL_ADJ  0x00
#define TIME_ADJ    0x01
#define AUTO_ADJ    0x02

#define MAX_LIGHTNESS 16 //1-16

EXT void Set_Screen_Com_Time(INT8U Sec);
EXT INT8U Get_Screen_Com_Time(void);
EXT void Set_Screen_Replay_Flag(void);
EXT INT8U Chk_Screen_Replay_Flag(void);
EXT void Screen_Lightness_Proc(void);
EXT void Screen_Open_Close_Proc(void);
EXT INT8U Get_Screen_Lightness(void);
EXT INT8U Get_Screen_Open_Status(void);
EXT void Screen_Proc(void);
#endif
