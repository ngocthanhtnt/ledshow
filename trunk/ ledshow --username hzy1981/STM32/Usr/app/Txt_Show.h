#ifndef TXT_SHOW_H
#define TXT_SHOW_H

#include "Includes.h"

#if TXT_SHOW_EN

#undef EXT
#ifdef TXT_SHOW_C
#define EXT
#else
#define EXT extern
#endif

#define RD_TXT_NORMAL_FLAG  0x00
#define RD_TXT_POINT_FLAG   0x01
#define RD_TXT_NODATA_FLAG  0x02

#define GET_FONT_SIZE(X) ((X + 2)*8)//0-16,1-24,2-32

#define GET_HZ_FONT_WIDTH(X)  (((X) == 0)?16:(((X) == 1)?24:32))
#define GET_HZ_FONT_HEIGHT(X) (((X) == 0)?16:(((X) == 1)?24:32))
#define GET_HZ_FONT_BYTES(X)  (((X) == 0)?32:(((X) == 1)?72:128))

#define GET_ASC_FONT_WIDTH(X)  (((X) == 0)?8:(((X) == 1)?12:16))
#define GET_ASC_FONT_HEIGHT(X) (((X) == 0)?16:(((X) == 1)?24:32))
#define GET_ASC_FONT_BYTES(X)  (((X) == 0)?16:(((X) == 1)?48:64))

#define GET_FONT_NUM() 3//获取字体个数

EXT void Read_Txt_Show_Chr_Data(INT16U Index, INT8U *pDst, INT16U DstLen);
EXT void Clr_Txt_Ram_Show_Data(void);
EXT INT16U Read_Txt_Show_Data(S_Show_Data *pDst, INT8U Area_No, S_Txt_Para *pPara, INT8U Data[], INT16U Data_Len, INT8U SCN_No, INT8U pointFlag, INT16U X, INT16U Y);
#endif
#endif // TXT_SHOW_H
