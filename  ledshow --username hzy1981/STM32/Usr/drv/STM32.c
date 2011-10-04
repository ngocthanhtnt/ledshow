#define STM32_C
#include "Includes.h"

extern void Set_Clock_Normal_Speed(void);
extern void Set_OE_Duty_Polarity(INT8U Duty, INT8U Polarity);

void Clr_Watch_Dog(void)
{

}

/*******************************************************************************
* Function Name : RCC_Configuration     复位时钟控制配置
* Description    : Configures the different system clocks.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RCC_Configuration(void)
{
    RCC_ClocksTypeDef RCC_Clocks;
	/* system clocks configuration -----------------系统时钟配置-------------------*/
	/* RCC system reset(for debug purpose) */
	RCC_DeInit();                                    //将外设RCC寄存器重设为缺省值
	/* Enable HSE */
#if HSE_VALUE > 16000000
	RCC_HSEConfig(RCC_HSE_Bypass);                    //开启外部高速晶振（HSE）
#else
    RCC_HSEConfig(RCC_HSE_ON);                    //开启外部高速晶振（HSE）
#endif	
	/* Wait till HSE is ready */ 
	//HSEStartUpStatus = RCC_WaitForHSEStartUp();    //等待HSE起振
	if(RCC_WaitForHSEStartUp() == SUCCESS)               //若成功起振，（下面为系统总线时钟设置）
	{
		/* Enable Prefetch Buffer */
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable); //使能FLASH预取指缓存
		/* Flash 2 wait state */
		FLASH_SetLatency(FLASH_Latency_2);   //设置FLASH存储器延时时钟周期数(根据不同的系统时钟选取不同的值)
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);   //设置AHB分频系数为1
	    Set_Clock_Normal_Speed();
	}

	RCC_GetClocksFreq(&RCC_Clocks);
/*
  uint32_t SYSCLK_Frequency; 
  uint32_t HCLK_Frequency;   
  uint32_t PCLK1_Frequency;   
  uint32_t PCLK2_Frequency; 
  uint32_t ADCCLK_Frequency;
*/
	if(RCC_Clocks.SYSCLK_Frequency != HCLK_VALUE ||\
	   RCC_Clocks.HCLK_Frequency != HCLK_VALUE ||\
	   RCC_Clocks.PCLK1_Frequency != PCLK1_VALUE ||\
	   RCC_Clocks.PCLK2_Frequency != PCLK2_VALUE)
	{
	  ASSERT_FAILED();
	  while(1);
	}
}

//static INT8U  fac_us=0;//us延时倍乘数
//static INT16U fac_ms=0;//ms延时倍乘数
//初始化延迟函数
//SYSTICK的时钟固定为HCLK时钟的1/8
//SYSCLK:系统时钟
void SysTick_Configuration(void)
{
	SysTick->CTRL&=0xfffffffb;//bit2清空,选择外部时钟  HCLK/8
	//fac_us=SYSCLK/8;		    
	//fac_ms=(u16)fac_us*1000;
}	
//延时nms
//注意nms的范围
//SysTick->LOAD为24位寄存器,所以,最大延时为:
//nms<=0xffffff*8*1000/SYSCLK
//SYSCLK单位为Hz,nms单位为ms
//对72M条件下,nms<=1864 
void Delay_ms(INT16U nms)
{
  INT16U i;

  for(i = 0; i < nms*10; i++)
  {
    Delay_us(100);
  }
/*	 		  	  
	INT32U temp;
			   
	//SysTick->LOAD=(u32)nms*fac_ms;//时间加载(SysTick->LOAD为24bit)
	SysTick->LOAD=(u32)nms*(HCLK_VALUE / 8000000) * 1000;
	SysTick->VAL =0x00;           //清空计数器
	SysTick->CTRL=0x01 ;          //开始倒数  
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//等待时间到达   
	SysTick->CTRL=0x00;       //关闭计数器
	SysTick->VAL =0X00;       //清空计数器	  	    
*/
}   
//延时nus
//nus为要延时的us数.		    								   
void Delay_us(INT32U nus)
{		
	INT32U temp;	    	 
	//SysTick->LOAD=nus*fac_us; //时间加载	  		 
	SysTick->LOAD=nus*(HCLK_VALUE / 8000000);
	SysTick->VAL=0x00;        //清空计数器
	SysTick->CTRL=0x01 ;      //开始倒数 	 
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));//等待时间到达   
	SysTick->CTRL=0x00;       //关闭计数器
	SysTick->VAL =0X00;       //清空计数器	 
}

//sec为要延时的秒
void Delay_sec(INT16U sec)
{
  INT16U i;

  sec = sec * 10;
  for(i = 0; i < sec; i ++)
  {
    Delay_ms(100);
    Clr_Watch_Dog();
  }

}

//发送调试信息一个字节
void OS_Put_Char(char Data)
{
   while (!(USART2->SR & USART_FLAG_TXE));
   USART2->DR = (Data & (uint16_t)0x01FF);
}

//发送一个字节通信数据
void Com_Send_Byte(INT8U Ch, INT8U Data)
{
  if(Ch EQ CH_COM)
  {
     while (!(USART1->SR & USART_FLAG_TXE));
     USART1->DR = (Data & (uint16_t)0x01FF);
  }
  else if(Ch EQ CH_GPRS)
  {
#if GPRS_EN
     while (!(USART3->SR & USART_FLAG_TXE));
     USART3->DR = (Data & (uint16_t)0x01FF);
#else
     ASSERT_FAILED();
#endif
  }
  else if(Ch EQ CH_NET)
  {

  }
}
/*******************************************************************************
* Function Name  : SPI_FLASH_Init
* Description    : Initializes the peripherals used by the SPI FLASH driver.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI1_FLASH_Init(void)
{
  SPI_InitTypeDef  SPI_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable SPI1 and GPIO clocks */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1 | RCC_APB2Periph_GPIOA, ENABLE);

  /* Configure SPI1 pins: SCK, MISO and MOSI */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Configure I/O for Flash Chip select */
  //PA4用于Flash_CS
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Deselect the FLASH: Chip Select high */
  SPI_FLASH_CS_HIGH();
  SPI_Cmd(SPI1, DISABLE);
  /* SPI1 configuration */
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI1, &SPI_InitStructure);
  /* Enable SPI1  */
  SPI_Cmd(SPI1, ENABLE);
}

void SPI1_CH376_Init(void)
{
   SPI_InitTypeDef SPI_InitStructure;
   GPIO_InitTypeDef GPIO_InitStructure;

   /* Enable SPI1 and GPIOA clocks */
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1 | RCC_APB2Periph_GPIOA, ENABLE);

   /* Configure SPI1 pins: NSS, SCK, MISO and MOSI */
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
   GPIO_Init(GPIOA, &GPIO_InitStructure);
/*
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
   GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IPU;   //上拉输入
   GPIO_Init(GPIOA, &GPIO_InitStructure);

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_Init(GPIOA, &GPIO_InitStructure);           //CH376_CS
*/
   /* SPI1 configuration */ 
   SPI_Cmd(SPI1, DISABLE);

   SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
   SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
   SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
   SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
   SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
   SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
   SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
   SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
   SPI_InitStructure.SPI_CRCPolynomial = 7;
   SPI_Init(SPI1, &SPI_InitStructure);

   /* Enable SPI1  */
   SPI_Cmd(SPI1, ENABLE);

}

//SPI1读写一字节数据
INT8U SPI1_ReadWrite(INT8U writedat)
{
#if 0
   /* Loop while DR register in not emplty */
   while (SPI_GetFlagStatus(SPI1, SPI_FLAG_TXE) == RESET);

   /* Send byte through the SPI1 peripheral */
   SPI_SendData(SPI1, writedat);

   /* Wait to receive a byte */
   while (SPI_GetFlagStatus(SPI1, SPI_FLAG_RXNE) == RESET);

   /* Return the byte read from the SPI bus */
   return SPI_ReceiveData(SPI1);
#endif
   /* Loop while DR register in not emplty */
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);

  /* Send byte through the SPI1 peripheral */
  SPI_I2S_SendData(SPI1, writedat);

  /* Wait to receive a byte */
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);

  /* Return the byte read from the SPI bus */
  return SPI_I2S_ReceiveData(SPI1);
}

void NVIC_Configuration(void)
{
    //----------中断优先级设置--------

	NVIC_InitTypeDef NVIC_InitStructure = {0};
	
	/* Configure the NVIC Preemption Priority Bits */  
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);	//设置优先级分组：先占优先级0位,从优先级4位
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);		//设置优先级分组：先占优先级2位,从优先级2位
	
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);   //向量表位于FLASH
	
	
    /* Enable the USARTy Interrupt */
	//串口接收中断，优先级最高
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		//USART1中断
 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		//
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器USART1

	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;		//USART1中断
 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		//
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器USART1
	 	
	/* Enable the TIM4 global Interrupt*/ 
	//秒中断
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;  //TIM1中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //先占优先级2级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

	/* Enable the TIM2 global Interrupt */
	//刷屏中断优先级
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;  //先占优先级1级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

	/* Enable the TIM3 global Interrupt */
	//特效中断
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM4中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;  //先占优先级2级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
}

//定时器中断，用于直接扫描屏
void TIM2_Configuration(void)
{
    //RCC_ClocksTypeDef RCC_Clocks;
//void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks)
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};
	/* TIM2 clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

    //RCC_GetClocksFreq(&RCC_Clocks);	
	
	/* ---------------------------------------------------------------
	TIM2CLK 即PCLK1=36MHz
	TIM2CLK = 36 MHz, Prescaler = 7200, TIM2 counter clock = 5K,即改变一次为5K,周期就为10K
	--------------------------------------------------------------- */
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = SCAN_SCREEN_PERIOD / 100; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
    TIM_TimeBaseStructure.TIM_Prescaler =(PCLK1_VALUE * 2/10000-1); //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	
	/* Enables the Update event for TIM2 */
	//TIM_UpdateDisableConfig(TIM2,ENABLE); 	//使能 TIM2 更新事件 
	
	/* TIM IT enable */
	TIM_ITConfig(  //使能或者失能指定的TIM中断
		TIM2, //TIM2
		TIM_IT_Update  |  //TIM 中断源
		TIM_IT_Trigger,   //TIM 触发中断源 
		ENABLE  //使能
		);
	
	/* TIM2 enable counter */
	TIM_Cmd(TIM2, ENABLE);  //使能TIMx外设

}

//定时器中断，用于实现特效，定时从备份显示数据区复制到数据区
void TIM3_Configuration(void)
{
    //RCC_ClocksTypeDef RCC_Clocks;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};
	/* TIM4 clock enable */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	//RCC_GetClocksFreq(&RCC_Clocks);
	/* ---------------------------------------------------------------
	TIM4CLK 即PCLK1=36MHz
	TIM4CLK = 36 MHz, Prescaler = 7200, TIM4 counter clock = 5K,即改变一次为5K,周期就为10K
	--------------------------------------------------------------- */
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = MOVE_STEP_PERIOD * 10; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
    TIM_TimeBaseStructure.TIM_Prescaler =(PCLK1_VALUE * 2/10000-1); //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	
	/* Enables the Update event for TIM3 */
	//TIM_UpdateDisableConfig(TIM3,ENABLE); 	//使能 TIM4 更新事件 
	
	/* TIM IT enable */
	TIM_ITConfig(  //使能或者失能指定的TIM中断
		TIM3, //TIM4
		TIM_IT_Update  |  //TIM 中断源
		TIM_IT_Trigger,   //TIM 触发中断源 
		ENABLE  //使能
		);
	
	/* TIM4 enable counter */
	TIM_Cmd(TIM3, ENABLE);  //使能TIMx外设

}

//定时器中断，用于绘制边框
void TIM1_Configuration(void)
{
    //RCC_ClocksTypeDef RCC_Clocks;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); 

	TIM_TimeBaseStructure.TIM_Period = 100 * 10; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms

#if  PCLK2_VALUE ==	HCLK_VALUE   
	TIM_TimeBaseStructure.TIM_Prescaler =(PCLK2_VALUE /10000-1); //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
#else
	TIM_TimeBaseStructure.TIM_Prescaler =(PCLK2_VALUE * 2 /10000-1); 
#endif

	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0; 
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

	TIM_ClearFlag(TIM1, TIM_FLAG_Update); 
	TIM_ARRPreloadConfig(TIM1, DISABLE); 
	
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE); 
	TIM_Cmd(TIM1, ENABLE);
}
//设置OE占空比和极性

//用于OE-PWM输出.
void TIM4_Configuration(void)
{
    //RCC_ClocksTypeDef RCC_Clocks;
 	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};
	TIM_OCInitTypeDef  TIM_OCInitStructure = {0};
	GPIO_InitTypeDef GPIO_InitStructure = {0};
/*
 	//----------PB0作为OE-PWM输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; //TIM_CH3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	return;
	//---------------------------
  */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //使能GPIO外设和AFIO复用功能模块时钟使能

	//PB0的输出口
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0; 
	//GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	//PB0作为OE-PWM输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; //TIM_CH3
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);


	/* TIM3 clock enable */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	//不分频。PWM频率=72000000/900=80Khz
	/* ---------------------------------------------------------------
	TIM3CLK 即PCLK1=36MHz
	TIM3 Configuration: generate 1 PWM signals :
    TIM3CLK = 36 MHz, Prescaler = 0x0, TIM3 counter clock = 36 MHz
    TIM3 ARR Register = 900 => TIM3 Frequency = TIM3 counter clock/(ARR + 1)
    TIM3 Frequency = 36 KHz.
    TIM3 Channel2 duty cycle = (TIM3_CCR2/ TIM3_ARR)* 100 
	TIM3CLK = 36 MHz, Prescaler = 0, TIM3 counter clock = 36MHz
	--------------------------------------------------------------- */
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = (PCLK1_VALUE * 2 / OE_PWM_FREQ); //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =0; //设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	
	/* Output Compare Active Mode configuration: Channel1 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);  //使能TIMx在CCR2上的预装载寄存器
	
	TIM_ARRPreloadConfig(TIM4, ENABLE); //使能TIMx在ARR上的预装载寄存器

	/* TIM3 enable counter */
	TIM_Cmd(TIM4, ENABLE);  //使能TIMx外设

    Set_OE_Duty_Polarity(50, 0);
}

INT8U Chk_JP_Status(void)
{
  //return SELF_TEST_STATUS;
 /*
  if(CHK_JP_STATUS0 && CHK_JP_STATUS1) //自检状态
  {
    return SELF_TEST_STATUS;
  }
  else if(CHK_JP_STATUS0)
  {
	return SELF_TEST_STATUS; //自检状态
  }
  else if(CHK_JP_STATUS1)
  {
	return FAC_STATUS; //工厂状态
  }
  else
    return NORMAL_STATUS;  //正常运行状态
	*/

  if(CHK_FAC_JP_STATUS())
    return FAC_STATUS;
  else
    return NORMAL_STATUS;
}

void UART2_Init(void) //串口2初始化
{
    USART_InitTypeDef USART_InitStructure = {0};
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE );

	//PA3串口1接收
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//PA2串口1发送
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//串口2用作调试信息输出
	USART_InitStructure.USART_BaudRate            = 115200;//Get_Com_Baud();
	USART_InitStructure.USART_WordLength          = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits            = USART_StopBits_1;
	USART_InitStructure.USART_Parity              = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART2, &USART_InitStructure);
	//USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART2, ENABLE);

}

//传感器接收数据的串口
void UART3_Init(void)
{
    USART_InitTypeDef USART_InitStructure = {0};
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE );

	//PB11串口3接收
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	//PB10串口3发送
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//串口3用作接收传感器数据
	USART_InitStructure.USART_BaudRate            = 9600;//Get_Com_Baud();
	USART_InitStructure.USART_WordLength          = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits            = USART_StopBits_1;
	USART_InitStructure.USART_Parity              = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART3, &USART_InitStructure);
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART3, ENABLE);
}

//串口1用于232/485通信
void UART1_Init(void)
{
	USART_InitTypeDef USART_InitStructure = {0};
    GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE );

	//PA10串口1接收
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//PA9串口1发送
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
  	
	//串口1用作与主机通信					    
	USART_InitStructure.USART_BaudRate            = Get_Com_Baud();
	USART_InitStructure.USART_WordLength          = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits            = USART_StopBits_1;
	USART_InitStructure.USART_Parity              = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART1, ENABLE); 
}

//初始化串口
void Com_Init(void) 
{
   UART1_Init();

//	Com_Send_Byte(CH_COM, 0x77);
//	Com_Send_Byte(CH_COM, 0x88);
}

void Soft_Rest(void) //软件复位
{

}

/*
typedef struct
{
  INT8U Direct; //进入方向
  INT8U Rows; //扫描1，2，4，8，16扫
  INT8U Rows_Fold; //每驱行折数
  INT8U Cols_Fold; //每驱列折数
  INT8S Line_Order; //行序号,0,+1,-1
  
  INT8U Line_Hide; //行消隐时间
  INT8U Clk_Freq; //移位时钟频率
  INT8U Screen_Freq; //屏幕刷新频率
  
  INT8U Data_Polarity; //数据极性
  INT8U OE_Polarity; //OE极性
  INT8U RG_Reverse; //红绿反转
}S_Scan_Para;
*/

//设置块使能信号
void Set_Block_OE_En(INT8U Value)
{
  if(Value > 0)
    TIM_Cmd(TIM3, ENABLE);
  else
   	TIM_Cmd(TIM3, DISABLE);
}

void Unselect_SPI_Device(void)
{
  SET_FLASH_CS(1); //不选中Flash
  SET_CH376_CS(1);	//不选中CH376
  SET_DS1302_CS(0);	//不选中DS1302

}

void RST_Periph(void)
{
  SET_RST(0);
  Delay_us(100);
  SET_RST(1);
  Delay_ms(100);
  SET_RST(0);
}

//共有的驱动函数等在此文件中定义
//读物理存储器
#ifndef DEF_WR_PHY_MEM
INT8U Read_PHY_Mem(INT32U Offset, void *pDst, INT16U RD_Len, void *pDst_Start, INT16U DstLen)
{
#ifdef USE_SPI_FLASH
  SPI_FLASH_BufferRead(pDst, Offset, RD_Len);
#else
#endif
  return 1;
}

//写物理存储器
INT8U Write_PHY_Mem(INT32U Offset, void *pSrc, INT16U SrcLen)
{
#ifdef USE_SPI_FLASH
  SPI_FLASH_BufferWrite(pSrc, Offset, SrcLen);
#else
#endif
  return 1;
}

//重新初始化内存的端口，SPIFlash需要调用该函数
void ReInit_Mem_Port(void)
{
#ifdef USE_SPI_FLASH
  SPI1_FLASH_Init();
#else
#endif
}

//测试显示灯的闪烁
void Test_LED_Flash(INT8U Counts, INT16U nms)
{
  INT8U i;

  for(i = 0; i < Counts; i ++)
  {
    SET_STATUS_LED_OFF();
	Delay_ms(nms);
	SET_STATUS_LED_ON();
	Delay_ms(nms);
  }
}

INT8U Chk_Test_Key_Up(void)
{
  INT8U i;

  for(i = 0; i < 20; i ++)
  {
	  if(CHK_TEST_KEY_STATUS())
	    break;

	  Delay_ms(1);
  }

  if(i EQ 20)
    return 1;

  return 0;

}

INT8U Chk_Test_Key_Down(void)
{
  INT8U i;

  for(i = 0; i < 20; i ++)
  {
	  if(CHK_TEST_KEY_STATUS() EQ 0)
	    break;

	  Delay_ms(1);
  }

  if(i EQ 20)
    return 1;

  return 0;
}

//自身硬件的检测
void Self_Test(void)
{
  INT32U Data = 0x55AA5AA5;
  INT8U Re = 1;
  INT8U ErrFlag = 0;
  S_Time TempTime,TempTime1;

   //当前在工厂状态且按下测试键则进入自检状态
  if(!(Chk_Test_Key_Down() && Chk_JP_Status() EQ FAC_STATUS))
    return;

  debug("-----------系统自检开始---------------");
#if QT_EN EQ 0
  //--------对存储器的测试---------------
  Write_Storage_Data(SDI_TEST_DATA, &Data, sizeof(Data));
  Delay_ms(10);
  memset(&Data, 0x00, sizeof(Data));
  Read_Storage_Data(SDI_TEST_DATA, &Data, &Data, sizeof(Data));

  if(0x55AA5AA5 EQ Data)
  {
    debug("SPI Flash 自检成功");
    Re = Re & 1;
  }
  else
  { 
    debug("SPI Flash 自检失败"); 
	Re = 0;
	ErrFlag	|= 0x01;

	Test_LED_Flash(1, 500);
  }
  //-----------------------------------------

  //--------对时钟的测试---------------------
  
  //while(1)
  {
 // DS1302_Init();

  Re &= _Get_Cur_Time(TempTime.Time);
  Print_Cur_Time();
  Delay_sec(1);//Delay_sec(2);
  Re &=_Get_Cur_Time(TempTime1.Time);

  }
 
  if(Re > 0 && TempTime.Time[T_SEC] != TempTime1.Time[T_SEC])
  {
    debug("时钟自检成功");
    Re = Re & 1;
  }
  else
  {
    debug("时钟自检失败"); 
	Re = 0;
	ErrFlag	|= 0x02;

	Test_LED_Flash(2, 500);
  }
  //-----------------------------------------

  //---------对485和232的测试---------------
  Screen_Status.Rcv_Posi = 0;
  Com_Send_Byte(CH_COM, 0xA5);
  Delay_ms(5); 
  if(RCV_DATA_BUF[0] EQ 0xA5) //自检成功
  {
    debug("串口自检成功");
    Re = Re & 1;
  }
  else
  {
    debug("串口自检失败"); 
	Re = 0;
	ErrFlag	|= 0x04;

	Test_LED_Flash(3, 500);
  }
  //---------------------------------------

  if(Re EQ 0)
	debug("外围器件自检失败！");
  else
	debug("外围器件自检成功！");

#endif
}

 //工厂状态自检
 void Fac_Status_Self_Test(void)
 {
  Self_Test(); //自身硬件检测

 }

#endif
