#ifndef LED_A0_DRV_H
#define LED_A0_DRV_H

#include "Pub.h"

#undef EXT
#ifdef LED_A0_DRV_C
#define EXT
#else
#define EXT  extern
#endif

#define debug OS_Debug_Print

EXT void Put_Char(char c);
EXT INT8U Get_Cur_Time();//S_Time *pTime);
EXT INT8U Set_Cur_Time(INT8U Time[]);//S_Time *pTime);
EXT INT16S Get_Cur_Temp();
EXT INT16U Get_Cur_Humidity();
EXT INT16U Get_Cur_Noise();

EXT void Mem_Init();
EXT INT8U Read_PHY_Mem(INT32U Offset, void *pDst, INT16U RD_Len, void *pDst_Start, INT16U DstLen);
EXT INT8U Write_PHY_Mem(INT32U Offset, void *pSrc, INT16U SrcLen);

EXT void Set_Shift_Bit(INT16U Block, INT8U RGB, INT8U Bit);
EXT void Set_Shift_Bit_Clk(INT8U Value);
EXT void Set_Block_OE(INT8U Value);
EXT void Delay_us(INT32U Value);
EXT void Set_Block_Latch(INT8U Value);
EXT void Set_Block_Row(INT16U Row);
EXT void Reset_Scan_Timer(INT32U Freq);

#endif
