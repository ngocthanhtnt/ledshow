#ifndef STM32_H
#define STM32_H

//#if QT_EN == 0
//#include "LED_Cfg.h"

#undef EXT
#ifdef STM32_C
#define EXT
#else
#define EXT extern
#endif

//定义断言,多多使用，有益身心
#if ASSERT_EN>0
#define ASSERT(x) //Assert((BOOL)(x),__FILE__,__FUNCTION__,(INT16U)__LINE__)
#define ASSERT_FAILED() //Assert_Failed(__FILE__,__FUNCTION__,(INT16U)__LINE__)
#else
#define ASSERT(x)
#define ASSERT_FAILED()
#endif

#define NORMAL_STATUS    0x00//正常运行状态
#define SELF_TEST_STATUS 0x01//自检状态
#define FAC_STATUS       0x02//工厂状态

#define debug OS_Debug_Print

#define SPI_FLASH_CS_HIGH() SET_FLASH_CS(1)
#define SPI_FLASH_CS_LOW() SET_FLASH_CS(0)

#define STOP_SCAN_TIMER()  TIM_Cmd(TIM2, DISABLE);  //使能TIMx外设  
#define START_SCAN_TIMER() TIM_Cmd(TIM2, ENABLE);  //使能TIMx外设

#define STOP_SHOW_TIMER()  TIM_Cmd(TIM4, DISABLE);  //使能TIMx外设  
#define START_SHOW_TIMER() TIM_Cmd(TIM4, ENABLE);  //使能TIMx外设

#define CHK_JP_STATUS0  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)
#define CHK_JP_STATUS1  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14)
 
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

typedef unsigned int INT32U;
typedef int INT32S;
typedef unsigned short int INT16U;
typedef short int INT16S;
typedef unsigned char INT8U;
typedef char INT8S;
typedef unsigned char BOOL;


#ifndef DEF_WR_PHY_MEM
//读物理存储器
EXT INT8U Read_PHY_Mem(INT32U Offset, void *pDst, INT16U RD_Len, void *pDst_Start, INT16U DstLen);
//写物理存储器
EXT INT8U Write_PHY_Mem(INT32U Offset, void *pSrc, INT16U SrcLen);
//重新初始化存储器端口
EXT void ReInit_Mem_Port(void);
#endif

EXT void Delay_Init(void);
EXT void Delay_ms(INT16U nms);
EXT void Delay_us(INT32U nus);
EXT void SPI1_Init(void);
EXT void Com_Init(void);
EXT INT8U SPI1_ReadWrite(INT8U writedat);
EXT void Soft_Rest(void);
EXT void NVIC_Configuration(void);
EXT void TIM2_Configuration(void);
EXT void TIM4_Configuration(void);
EXT void TIM3_Configuration(void);
EXT void SPI1_FLASH_Init(void);
EXT void SPI1_CH376_Init(void);
EXT void Set_Block_OE_En(INT8U Value);
EXT void Set_Block_Row(INT8U Row);
EXT INT8U Chk_JP_Status(void);
EXT void UART2_Init(void); //串口2初始化
EXT void Com_Send_Byte(INT8U Ch, INT8U Data);
EXT void Unselect_SPI_Device(void);

#endif
