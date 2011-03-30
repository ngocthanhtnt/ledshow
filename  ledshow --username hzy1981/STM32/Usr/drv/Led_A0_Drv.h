#ifndef LED_A0_DRV_H
#define LED_A0_DRV_H

#include "Pub.h"

#undef EXT
#ifdef LED_A0_DRV_C
#define EXT
#else
#define EXT  extern
#endif

#define SPI_FLAG_RXNE           SPI_I2S_FLAG_RXNE
#define SPI_FLAG_TXE            SPI_I2S_FLAG_TXE
//#define SPI_FLAG_CRCERR                    ((u16)0x0010)
//#define SPI_FLAG_MODF                      ((u16)0x0020)
#define SPI_FLAG_OVR            SPI_I2S_FLAG_OVR
#define SPI_FLAG_BSY            SPI_I2S_FLAG_BSY

#define SPI_GetFlagStatus       SPI_I2S_GetFlagStatus
#define SPI_SendData            SPI_I2S_SendData
#define SPI_ReceiveData         SPI_I2S_ReceiveData


#define debug OS_Debug_Print

EXT void Put_Char(char c);
EXT INT8U Get_Cur_Time(void);//S_Time *pTime);
EXT INT8U Set_Cur_Time(INT8U Time[]);//S_Time *pTime);
EXT INT16S Get_Cur_Temp(void);
EXT INT16U Get_Cur_Humidity(void);
EXT INT16U Get_Cur_Noise(void);

EXT void Mem_Init(void);
EXT void SPI1_Init(void);
EXT unsigned char SPI1_ReadWrite(unsigned char writedat);
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
