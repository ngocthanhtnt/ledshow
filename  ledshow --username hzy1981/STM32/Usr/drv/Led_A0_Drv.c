#define LED_A0_DRV_C
#include "Includes.h"

#if CARD_TYPE == CARD_A0


void RCC_Configuration()
{
  //SystemInit();
  //------打开外设时钟1和2-----------
  //RCC_APB1PeriphClockCmd(RCC_APB1Periph_ALL, ENABLE);
  //RCC_APB2PeriphClockCmd(RCC_APB2Periph_ALL, ENABLE);
  //RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 | RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4, ENABLE);  
  //RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //使能GPIO外设和AFIO复用功能模块时钟使能

}

 //IO口初始化 -只需初始化完全作为IO口用的引脚，其他复用的引脚在相应的功能模块中初始化
void GPIO_Configuration()
{
  GPIO_InitTypeDef GPIO_InitStructure = {0};  
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);

  //-------------------IO口初始化-----------------------
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  //PA的输出口
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_12 | GPIO_Pin_15;   
  GPIO_Init(GPIOA, &GPIO_InitStructure);

 
  //PB的输出口
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 |GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 |\
                                GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 |GPIO_Pin_15;   
  GPIO_Init(GPIOB, &GPIO_InitStructure);
/*
  //PB0作为OE-PWM输出
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; //TIM_CH3
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
   
  //PC的输出口
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_5 | GPIO_Pin_6 |\
                                GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12;   
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  
   //PD的输出口
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  */
}


/*
//GPIO初始化
void GPIO_Init()
{
  
}

//SPI初始化
void SPI_Init()
{
  
}

//UART初始化
void UART_Init()
{
  
}
*/



void Put_Char(char c)
{
  
}

//存储器初始化
void Mem_Init(void)
{

}

//获取当前温度
INT16S Get_Cur_Temp(void)
{
  return -215; 
}

//获取当前湿度
INT16U Get_Cur_Humidity(void)
{
  return 60; 
}

//获取当前噪音
INT16U Get_Cur_Noise(void)
{
  return 60;
}
//设置移位数据
//Block表示块号
//RGB表示颜色0-R，1-G，2-B
//Bit表示位
/*
void Set_Shift_Bit(INT16U Block, INT8U RGB, INT8U Bit)
{
  
}


//设置移位时钟
void Set_Shift_Bit_Clk(INT8U Value)
{
  
}





//设置块锁存信号
void Set_Block_Latch(INT8U Value)
{
  
}
*/




void Set_OE_Duty(INT8U Duty)
{


}

void Set_OE_Polarity(INT8U flag)
{


}

void Hardware_Init(void)
{
  RCC_Configuration();

  NVIC_Configuration();

  GPIO_Configuration();
    
  TIM2_Configuration();
  TIM3_Configuration();
  TIM4_Configuration();

  UART2_Init();

  Unselect_SPI_Device(); //不选中任何一个SPI设备

  SPI1_FLASH_Init();



}
#endif
