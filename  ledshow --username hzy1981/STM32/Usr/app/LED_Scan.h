#ifndef LED_SCAN_H
#define LED_SCAN_H

#include "LED_Cfg.h"

#undef EXT
#ifdef LED_SCAN_C
#define EXT
#else
#define EXT extern
#endif

//#pragma pack(1)
#if MAX_SCAN_BLOCK_NUM == 16
EXT INT8U Scan_Data[2][MAX_SCAN_BLOCK_NUM];// __attribute__((at(SCAN_DATA_ADDR)));
EXT INT8U Scan_Data0[2][MAX_SCAN_BLOCK_NUM];
EXT INT8U Scan_Data1[2][MAX_SCAN_BLOCK_NUM];
#else//  MAX_SCAN_BLOCK_NUM == 16
EXT INT8U Scan_Data[2][MAX_SCAN_BLOCK_NUM];// __attribute__((at(SCAN_DATA_ADDR)));
EXT INT8U Scan_Data0[2][(MAX_SCAN_BLOCK_NUM + 1)*2];
EXT INT8U Scan_Data1[2][(MAX_SCAN_BLOCK_NUM + 1)*2];
#endif
//#pragma pack()

EXT void transpose8(unsigned char i[8], unsigned char o[8]/*, unsigned char flag*/);
EXT void transpose4(unsigned char i[8], unsigned char o[8]/*, unsigned char flag*/);
EXT void Build_Scan_Data_Index(void);
EXT INT16U Get_Scan_Data_Index(INT16U Block, INT16U Index);
#endif
