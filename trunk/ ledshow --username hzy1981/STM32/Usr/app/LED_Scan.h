#ifndef LED_SCAN_H
#define LED_SCAN_H

#undef EXT
#ifdef LED_SCAN_C
#define EXT
#else
#define EXT extern
#endif

#pragma pack(1)
EXT INT8U Scan_Data[3][MAX_SCAN_BLOCK_NUM];// __attribute__((at(SCAN_DATA_ADDR)));
EXT INT8U Scan_Data0[3][MAX_SCAN_BLOCK_NUM];
#pragma pack()

EXT void transpose8(unsigned char i[8], unsigned char o[8]);
EXT void Build_Scan_Data_Index(void);
EXT INT16U Get_Scan_Data_Index(INT16U Block, INT16U Index);
#endif
