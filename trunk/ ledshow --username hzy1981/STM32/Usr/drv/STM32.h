#ifndef STM32_H
#define STM32_H

//#if QT_EN == 0
#include "LED_Cfg.h"
//#include "BitBandIO.h"

#undef EXT
#ifdef STM32_C
#define EXT
#else
#define EXT extern
#endif

//定义断言,多多使用，有益身心
#if ASSERT_EN>0
#define ASSERT(x) OS_Assert((BOOL)(x),__FILE__,__FUNCTION__,(INT16U)__LINE__)
#define ASSERT_FAILED() OS_Assert_Failed(__FILE__,__FUNCTION__,(INT16U)__LINE__)
#else
#define ASSERT(x)
#define ASSERT_FAILED()
#endif

#define NORMAL_STATUS    0x00//正常运行状态
#define SELF_TEST_STATUS 0x01//自检状态
#define FAC_STATUS       0x02//工厂状态

#if ASSERT_EN
#define debug OS_Debug_Print
#else
#define debug(...)
#endif

#define _debug OS_Debug_Print

#define SPI_FLASH_CS_HIGH() SET_FLASH_CS(1)
#define SPI_FLASH_CS_LOW() SET_FLASH_CS(0)

#define SCAN_INT_DISABLE() TIM_ITConfig(TIM2,TIM_IT_Update|TIM_IT_Trigger,DISABLE)//TIM_ITConfig(TIM2,TIM_IT_Update|TIM_IT_Trigger,DISABLE)  //使能
#define SCAN_INT_ENABLE()  TIM_ITConfig(TIM2,TIM_IT_Update|TIM_IT_Trigger,ENABLE)//TIM_ITConfig(TIM2,TIM_IT_Update|TIM_IT_Trigger,ENABLE)

#define STOP_SCAN_TIMER() // TIM_ITConfig(TIM2,TIM_IT_Update|TIM_IT_Trigger,DISABLE)//SCAN_INT_DISABLE()//TIM_Cmd(TIM2, DISABLE);  //使能TIMx外设  
#define START_SCAN_TIMER()// TIM_ITConfig(TIM2,TIM_IT_Update|TIM_IT_Trigger,ENABLE)//SCAN_INT_ENABLE() //TIM_Cmd(TIM2, ENABLE);  //使能TIMx外设

#define STOP_SHOW_TIMER()  TIM_Cmd(TIM4, DISABLE);  //使能TIMx外设  
#define START_SHOW_TIMER() TIM_Cmd(TIM4, ENABLE);  //使能TIMx外设

//#define CLR_WDG()  IWDG_ReloadCounter()
//#define CHK_JP_STATUS1  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14)
 
// 把“位带地址＋位序号”转换别名地址宏 
#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2)) 
//把该地址转换成一个指针 
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr)) 
// MEM_ADDR(BITBAND( (u32)&CRCValue,1)) = 0x1; 
/*
#define SET_SHIFT_BIT(Block, Data, i) do{\
     if(Block EQ 0)\
	 {\
	   SET_R1(MEM_ADDR(BITBAND((INT32U)&Data[0], i)));\
	   SET_G1(MEM_ADDR(BITBAND((INT32U)&Data[1], i)));\
	   SET_B1(MEM_ADDR(BITBAND((INT32U)&Data[2], i)));\
	 }\
	 else if(Block EQ 1)\
	 { \
	   SET_R2(MEM_ADDR(BITBAND((INT32U)&Data[0], i)));\
	   SET_G2(MEM_ADDR(BITBAND((INT32U)&Data[1], i)));\
	   SET_B2(MEM_ADDR(BITBAND((INT32U)&Data[2], i)));\
	 }\
	 else if(Block EQ 2)\
	 {\
	   SET_R3(MEM_ADDR(BITBAND((INT32U)&Data[0], i)));\
	   SET_G3(MEM_ADDR(BITBAND((INT32U)&Data[1], i)));\
	   SET_B3(MEM_ADDR(BITBAND((INT32U)&Data[2], i)));\
	 }\
	 else if(Block EQ 3)\
	 {\
	   SET_R4(MEM_ADDR(BITBAND((INT32U)&Data[0], i)));\
	   SET_G4(MEM_ADDR(BITBAND((INT32U)&Data[1], i)));\
	   SET_B4(MEM_ADDR(BITBAND((INT32U)&Data[2], i)));\
	 }\
	 else if(Block EQ 4)\
	 {\
	   SET_R5(MEM_ADDR(BITBAND((INT32U)&Data[0], i)));\
	   SET_G5(MEM_ADDR(BITBAND((INT32U)&Data[1], i)));\
	   SET_B5(MEM_ADDR(BITBAND((INT32U)&Data[2], i)));\
	 }\
	 else if(Block EQ 5)\
	 {\
	   SET_R6(MEM_ADDR(BITBAND((INT32U)&Data[0], i)));\
	   SET_G6(MEM_ADDR(BITBAND((INT32U)&Data[1], i)));\
	   SET_B6(MEM_ADDR(BITBAND((INT32U)&Data[2], i)));\
	 }\
	 else if(Block EQ 6)\
	 {\
	   SET_R7(MEM_ADDR(BITBAND((INT32U)&Data[0], i)));\
	   SET_G7(MEM_ADDR(BITBAND((INT32U)&Data[1], i)));\
	   SET_B7(MEM_ADDR(BITBAND((INT32U)&Data[2], i)));\
	 }\
	 else if(Block EQ 7)\
	 {\
	   SET_R8(MEM_ADDR(BITBAND((INT32U)&Data[0], i)));\
	   SET_G8(MEM_ADDR(BITBAND((INT32U)&Data[1], i)));\
	   SET_B8(MEM_ADDR(BITBAND((INT32U)&Data[2], i)));\
	 }\
	 else\
	 {\
       ASSERT_FAILED();\
	 }\
}while(0);
*/
/*
#define SET_SHIFT_BIT_0(Data, i) do{\
       SET_CLK_LOW();\
  	   SET_R1(GET_BIT(Data[0][0], i));\
	   SET_G1(GET_BIT(Data[0][1], i));\
	   SET_B1(GET_BIT(Data[0][2], i));\
	   SET_R2(GET_BIT(Data[1][0], i));\
	   SET_G2(GET_BIT(Data[1][1], i));\
	   SET_B2(GET_BIT(Data[1][2], i));\
	   SET_R3(GET_BIT(Data[2][0], i));\
	   SET_G3(GET_BIT(Data[2][1], i));\
	   SET_B3(GET_BIT(Data[2][2], i));\
	   SET_R4(GET_BIT(Data[3][0], i));\
	   SET_G4(GET_BIT(Data[3][1], i));\
	   SET_B4(GET_BIT(Data[3][2], i));\
	   SET_CLK_HIGH();}while(0);
  */
#define SCAN_DATA_ADDR 0x20001000
/*
#define SET_SHIFT_BIT_1(Block_Num, Data, i) do{\
       SET_CLK_LOW();\
  	   SET_R1(MEM_ADDR(BITBAND((INT32U)SCAN_DATA_ADDR, i)));\
	   if(Block_Num <= 1) {SET_CLK_HIGH();break;}\
	   SET_R2(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 3), i)));\
	   if(Block_Num <= 2) {SET_CLK_HIGH();break;}\
	   SET_R3(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 6), i)));\
	   if(Block_Num <= 3) {SET_CLK_HIGH();break;}\
	   SET_R4(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 9), i)));\
	   SET_CLK_HIGH();}while(0);

#define SET_SHIFT_BIT_2(Block_Num, Data, i) do{\
       SET_CLK_LOW();\
  	   SET_R1(MEM_ADDR(BITBAND((INT32U)SCAN_DATA_ADDR, i)));\
	   SET_G1(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 1), i)));\
	   if(Block_Num <= 1) {SET_CLK_HIGH();break;}\
	   SET_R2(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 3), i)));\
	   SET_G2(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 4), i)));\
	   if(Block_Num <= 2) {SET_CLK_HIGH();break;}\
	   SET_R3(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 6), i)));\
	   SET_G3(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 7), i)));\
	   if(Block_Num <= 3) {SET_CLK_HIGH();break;}\
	   SET_R4(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 9), i)));\
	   SET_G4(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 10), i)));\
	   SET_CLK_HIGH();}while(0);

#define SET_SHIFT_BIT_3(Block_Num, Data, i) do{\
       SET_CLK_LOW();\
  	   SET_R1(MEM_ADDR(BITBAND((INT32U)SCAN_DATA_ADDR, i)));\
	   SET_G1(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 1), i)));\
	   SET_B1(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 2), i)));\
	   if(Block_Num <= 1) {SET_CLK_HIGH();break;}\
	   SET_R2(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 3), i)));\
	   SET_G2(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 4), i)));\
	   SET_B2(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 5), i)));\
	   if(Block_Num <= 2) {SET_CLK_HIGH();break;}\
	   SET_R3(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 6), i)));\
	   SET_G3(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 7), i)));\
	   SET_B3(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 8), i)));\
	   if(Block_Num <= 3) {SET_CLK_HIGH();break;}\
	   SET_R4(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 9), i)));\
	   SET_G4(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 10), i)));\
	   SET_B4(MEM_ADDR(BITBAND((INT32U)(SCAN_DATA_ADDR + 11), i)));\
	   SET_CLK_HIGH();}while(0);

#define SET_SHIFT_BIT(Block, Data, i) do{\
     if(Block EQ 0)\
	 {\
	   SET_R1(GET_BIT(Data[0], i));\
	   SET_G1(GET_BIT(Data[1], i));\
	   SET_B1(GET_BIT(Data[2], i));\
	 }\
	 else if(Block EQ 1)\
	 { \
	   SET_R2(GET_BIT(Data[0], i));\
	   SET_G2(GET_BIT(Data[1], i));\
	   SET_B2(GET_BIT(Data[2], i));\
	 }\
	 else if(Block EQ 2)\
	 {\
	   SET_R3(GET_BIT(Data[0], i));\
	   SET_G3(GET_BIT(Data[1], i));\
	   SET_B3(GET_BIT(Data[2], i));\
	 }\
	 else if(Block EQ 3)\
	 {\
	   SET_R4(GET_BIT(Data[0], i));\
	   SET_G4(GET_BIT(Data[1], i));\
	   SET_B4(GET_BIT(Data[2], i));\
	 }\
	 else if(Block EQ 4)\
	 {\
	   SET_R5(GET_BIT(Data[0], i));\
	   SET_G5(GET_BIT(Data[1], i));\
	   SET_B5(GET_BIT(Data[2], i));\
	 }\
	 else if(Block EQ 5)\
	 {\
	   SET_R6(GET_BIT(Data[0], i));\
	   SET_G6(GET_BIT(Data[1], i));\
	   SET_B6(GET_BIT(Data[2], i));\
	 }\
	 else if(Block EQ 6)\
	 {\
	   SET_R7(GET_BIT(Data[0], i));\
	   SET_G7(GET_BIT(Data[1], i));\
	   SET_B7(GET_BIT(Data[2], i));\
	 }\
	 else if(Block EQ 7)\
	 {\
	   SET_R8(GET_BIT(Data[0], i));\
	   SET_G8(GET_BIT(Data[1], i));\
	   SET_B8(GET_BIT(Data[2], i));\
	 }\
	 else\
	 {\
       ASSERT_FAILED();\
	 }\
}while(0);
*/
typedef unsigned int INT32U;
typedef int INT32S;
typedef unsigned short int INT16U;
typedef short int INT16S;
typedef unsigned char INT8U;
typedef char INT8S;
//typedef unsigned char BOOL;


#ifndef DEF_WR_PHY_MEM
//读物理存储器
EXT INT8U Read_PHY_Mem(INT32U Offset, void *pDst, INT16U RD_Len, void *pDst_Start, INT16U DstLen);
//写物理存储器
EXT INT8U Write_PHY_Mem(INT32U Offset, void *pSrc, INT16U SrcLen);
//重新初始化存储器端口
EXT void ReInit_Mem_Port(void);
#endif

EXT void Clr_Watch_Dog(void);
EXT void RCC_Configuration(void);
EXT void SysTick_Configuration(void);
EXT void Delay_ms(INT16U nms);
EXT void Delay_us(INT32U nus);
EXT void Delay_sec(INT16U sec);
EXT void SPI1_Init(void);
EXT void RST_Periph(void);
EXT void Com_Init(void);
EXT INT8U SPI1_ReadWrite(INT8U writedat);
EXT INT8U SPI2_ReadWrite(INT8U writedat);
EXT void Soft_Reset(void);
EXT void NVIC_Configuration(void);
EXT void TIM2_Configuration(void);
EXT void TIM4_Configuration(void);
EXT void TIM3_Configuration(void);
EXT void TIM1_Configuration(void);
EXT void SPI1_FLASH_Init(void);
EXT void SPI1_CH376_Init(void);
EXT void SPI1_ENC28J60_Init(void);
EXT void SPI2_Init(void);
EXT void Set_Block_OE_En(INT8U Value);
EXT void Set_OE_Duty_Polarity(INT8U Duty, INT8U Polarity);
EXT INT8U Chk_JP_Status(void);
EXT void UART1_Init(void);
EXT void UART2_Init(void); //串口2初始化
EXT void UART3_Init(void);
EXT void UART4_Init(void);
EXT void Com_Send_Byte(INT8U Ch, INT8U Data);
EXT void Unselect_SPI_Device(void);
EXT INT16U Self_Test(void);
EXT void IWDG_Init(void);
EXT INT8U Chk_Test_Key_Down(void);
EXT INT8U Chk_Test_Key_Up(void);
EXT void Fac_Status_Self_Test(void);
EXT void BKP_Register_Init(void);
EXT void DMA_Configuration(void);
EXT void ADC_configuration(void);
EXT INT16S GetInterTemperature(void);
EXT INT32U CRC32(INT8U *pBuf, INT16U nSize);
#endif
