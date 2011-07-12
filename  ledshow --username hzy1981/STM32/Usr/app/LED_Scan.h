#ifndef LED_SCAN_H
#define LED_SCAN_H

#undef EXT
#ifdef LED_SCAN_C
#define EXT
#else
#define EXT extern
#endif

EXT void transpose8(unsigned char i[8], unsigned char o[8]);
EXT void Build_Scan_Data_Index(void);
EXT INT16U Get_Scan_Data(INT16U Block, INT16U Rows, INT16U BRow, INT16U Cols, INT16U Index,\
                          INT8U Direct, INT8U Rows_Fold, INT8U Cols_Fold, INT8U *pDst);
#endif
