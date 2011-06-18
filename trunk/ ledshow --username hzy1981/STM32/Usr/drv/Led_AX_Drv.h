#ifndef LED_AX_DRV_H
#define LED_AX_DRV_H

#include "Pub.h"

#undef EXT
#ifdef LED_AX_DRV_C
#define EXT
#else
#define EXT  extern
#endif

//USE_STDPERIPH_DRIVER, STM32F10X_MD

/*
#define SPI_FLAG_RXNE           SPI_I2S_FLAG_RXNE
#define SPI_FLAG_TXE            SPI_I2S_FLAG_TXE
//#define SPI_FLAG_CRCERR                    ((u16)0x0010)
//#define SPI_FLAG_MODF                      ((u16)0x0020)
#define SPI_FLAG_OVR            SPI_I2S_FLAG_OVR
#define SPI_FLAG_BSY            SPI_I2S_FLAG_BSY

#define SPI_GetFlagStatus       SPI_I2S_GetFlagStatus
#define SPI_SendData            SPI_I2S_SendData
#define SPI_ReceiveData         SPI_I2S_ReceiveData
*/
//复位脚 -PB15
#define SE_RST(x) (x == 0)?GPIO_ResetBits(GPIOB,GPIO_Pin_15):GPIO_SetBits(GPIOB,GPIO_Pin_15)

//SPI Flash的选通脚-PA4
#define SET_FLASH_CS(x)	(x == 0)?GPIO_ResetBits(GPIOA,GPIO_Pin_4):GPIO_SetBits(GPIOA,GPIO_Pin_4)

//DS1302选通脚-PA8
#define SET_DS1302_CS(x) (x == 0)?GPIO_ResetBits(GPIOA,GPIO_Pin_8):GPIO_SetBits(GPIOA,GPIO_Pin_8)

//CH376选通脚-PA12
#define SET_CH376_CS(x)	(x == 0)?GPIO_ResetBits(GPIOA,GPIO_Pin_12):GPIO_SetBits(GPIOA,GPIO_Pin_12)

//CH376 INT引脚
#define CHK_CH376_INT() GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)
/*
//ENC28J60_CS脚
#define SET_ENC28J60_CS(x) (x == 0)?GPIO_ResetBits(GPIOB,GPIO_Pin_15):GPIO_SetBits(GPIOB,GPIO_Pin_15)

//ENC28J60_INT脚
#define CHK_ENC28J60_INT() (x == 0)?GPIO_ResetBits(GPIOB,GPIO_Pin_15):GPIO_SetBits(GPIOB,GPIO_Pin_15)
*/
//A-PB6
#define SET_A(x)  (x == 0)?(GPIOB->BRR = GPIO_Pin_6):(GPIOB->BSRR = GPIO_Pin_6)//GPIO_ResetBits(GPIOB,GPIO_Pin_6):GPIO_SetBits(GPIOB,GPIO_Pin_6) //do{if(x==0) GPIO_ResetBits(GPIOB,GPIO_Pin_6); else GPIO_SetBits(GPIOB,GPIO_Pin_6);}while(0)//
//B-PB7
#define SET_B(x)  (x == 0)?(GPIOB->BRR = GPIO_Pin_7):(GPIOB->BSRR = GPIO_Pin_7)//GPIO_ResetBits(GPIOB,GPIO_Pin_7):GPIO_SetBits(GPIOB,GPIO_Pin_7)
//C-PB8
#define SET_C(x)  (x == 0)?(GPIOB->BRR = GPIO_Pin_8):(GPIOB->BSRR = GPIO_Pin_8)//GPIO_ResetBits(GPIOB,GPIO_Pin_8):GPIO_SetBits(GPIOB,GPIO_Pin_8)
//D-PB9
#define SET_D(x)  (x == 0)?(GPIOB->BRR = GPIO_Pin_9):(GPIOB->BSRR = GPIO_Pin_9)//GPIO_ResetBits(GPIOB,GPIO_Pin_9):GPIO_SetBits(GPIOB,GPIO_Pin_9)
//LAT-STB-PA0
#define SET_LAT(x) (x == 0)?(GPIOA->BRR = GPIO_Pin_0):(GPIOA->BSRR = GPIO_Pin_0)//GPIO_ResetBits(GPIOA,GPIO_Pin_0):GPIO_SetBits(GPIOA,GPIO_Pin_0)
//OE-PB0
#define SET_OE(x) (x == 0)?(GPIOB->BRR = GPIO_Pin_0):(GPIOB->BSRR = GPIO_Pin_0)//GPIO_ResetBits(GPIOB,GPIO_Pin_0):GPIO_SetBits(GPIOB,GPIO_Pin_0)
//CLK-PA1
#define SET_CLK(x) (x == 0)?(GPIOA->BRR = GPIO_Pin_1):(GPIOA->BSRR = GPIO_Pin_1)//GPIO_ResetBits(GPIOA,GPIO_Pin_1):GPIO_SetBits(GPIOA,GPIO_Pin_1)
//R1-PB2
#define SET_R1(x) (x == 0)?(GPIOB->BRR = GPIO_Pin_2):(GPIOB->BSRR = GPIO_Pin_2)
//R2-PB12					  
#define SET_R2(x) (x == 0)?(GPIOB->BRR = GPIO_Pin_12):(GPIOB->BSRR = GPIO_Pin_12)
//R3-PB13
#define SET_R3(x) (x == 0)?(GPIOB->BRR = GPIO_Pin_13):(GPIOB->BSRR = GPIO_Pin_13)
//R4-PB14
#define SET_R4(x) (x == 0)?(GPIOB->BRR = GPIO_Pin_14):(GPIOB->BSRR = GPIO_Pin_14)
//R5
#define SET_R5(x) 
//R6
#define SET_R6(x)
//R7
#define SET_R7(x) 
//R8
#define SET_R8(x) 
//G1-PA15
#define SET_G1(x) (x == 0)?(GPIOA->BRR = GPIO_Pin_15):(GPIOA->BSRR = GPIO_Pin_15)
//G2
#define SET_G2(x) (x == 0)?(GPIOB->BRR = GPIO_Pin_3):(GPIOB->BSRR = GPIO_Pin_3) 
//G3
#define SET_G3(x) (x == 0)?(GPIOB->BRR = GPIO_Pin_4):(GPIOB->BSRR = GPIO_Pin_4) 
//G4
#define SET_G4(x) (x == 0)?(GPIOB->BRR = GPIO_Pin_5):(GPIOB->BSRR = GPIO_Pin_5)  
//G5
#define SET_G5(x) 
//G6
#define SET_G6(x)  
//G7
#define SET_G7(x) 
//G8
#define SET_G8(x) 
//B1
#define SET_B1(x)
//B2
#define SET_B2(x)
//B3
#define SET_B3(x)
//B4
#define SET_B4(x)
//B5
#define SET_B5(x)
//B6
#define SET_B6(x)
//B7
#define SET_B7(x)
//B8
#define SET_B8(x)



EXT void Put_Char(char c);
//EXT INT8U Get_Cur_Time(void);//S_Time *pTime);
//EXT INT8U Set_Cur_Time(INT8U Time[]);//S_Time *pTime);
EXT INT16S Get_Cur_Temp(void);
EXT INT16U Get_Cur_Humidity(void);
EXT INT16U Get_Cur_Noise(void);

EXT void Mem_Init(void);
EXT void SPI1_Init(void);
EXT unsigned char SPI1_ReadWrite(unsigned char writedat);
EXT INT8U Read_PHY_Mem(INT32U Offset, void *pDst, INT16U RD_Len, void *pDst_Start, INT16U DstLen);
EXT INT8U Write_PHY_Mem(INT32U Offset, void *pSrc, INT16U SrcLen);

//EXT void Set_Shift_Bit(INT16U Block, INT8U RGB, INT8U Bit);
//EXT void Set_Shift_Bit_Clk(INT8U Value);
//EXT void Set_Block_OE(INT8U Value);
//EXT void delay_us(INT32U Value);
//EXT void Set_Block_Latch(INT8U Value);
//EXT void Reset_Scan_Timer(INT32U Freq);
EXT void Hardware_Init(void);
#endif
