#ifndef SCREEN_STATUS_H
#define SCREEN_STATUS_H

#undef EXT
#ifdef SCREEN_STATUS_C
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


typedef struct
{
  INT8U Head;
  
  INT8U Posi;
  INT8U Counts;
  INT16S TempData[10];

  INT8U Tail;
}S_Inter_Temperature;

#ifdef SCREEN_STATUS_C
EXT S_Inter_Temperature Inter_Temp = {CHK_BYTE, 0, 0, {0}, CHK_BYTE};
#else
EXT S_Inter_Temperature Inter_Temp;
#endif

EXT INT16S Get_Cur_Temp(void);
EXT INT16U Get_Cur_Humidity(void);
EXT INT16U Get_Cur_Noise(void);
EXT INT8U Get_Cur_Time(void);
EXT INT8U Chk_Time(S_Time *pTime);
EXT void Set_Screen_Com_Time(INT8U Sec);
EXT INT8U Get_Screen_Com_Time(void);
EXT void Set_Screen_Replay_Flag(void);
EXT INT8U Chk_Screen_Replay_Flag(void);
EXT void Screen_Lightness_Proc(void);
EXT void Screen_Open_Close_Proc(void);
EXT INT8U Get_Screen_Lightness(void);
EXT INT8U Get_Screen_Open_Status(void);
EXT INT32U Get_Encryption_Code(INT32U Serial0, INT32U Serial1, INT32U Serial2);
EXT void Encrypt(void);
EXT void Encrypt_Chk(void);
EXT void Screen_Proc(void);
#endif
