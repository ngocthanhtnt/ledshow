#define STM32_C
#include "Includes.h"

extern void Set_Clock_Normal_Speed(void);

/*
void Clr_Watch_Dog(void)
{
#if WDG_EN
  IWDG_ReloadCounter();
#endif
}
*/

/** 
  * @brief  Configures the clock 
  * @param  None 
  * @retval None 
  */ 
#if HSE_VALUE EQ 25000000 //外部晶振频率
void RCC_Configuration(void) 
{ 
 RCC_ClocksTypeDef RCC_ClockFreq; 
 ErrorStatus HSEStartUpStatus;
   /* RCC system reset(for debug purpose) */ 
  RCC_DeInit(); 

  /* Enable HSE */ 
  RCC_HSEConfig(RCC_HSE_ON); 

  /* Wait till HSE is ready */ 
  HSEStartUpStatus = RCC_WaitForHSEStartUp(); 

  if(HSEStartUpStatus != ERROR) 
  { 
    /* Enable Prefetch Buffer */ 
    FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable); 

 /****************************************************************/ 
 /*      HSE=25MHz, HCLK=72MHz, PCLK2=72MHz, PCLK1=36MHz         */ 
 /****************************************************************/ 
    /* Flash 2 wait state */ 
    FLASH_SetLatency(FLASH_Latency_2); 
    /* HCLK = SYSCLK */ 
    RCC_HCLKConfig(RCC_SYSCLK_Div1); 
    /* PCLK2 = HCLK */ 
    RCC_PCLK2Config(RCC_HCLK_Div1); 
    /* PCLK1 = HCLK/2 */ 
    RCC_PCLK1Config(RCC_HCLK_Div2); 
    /*  ADCCLK = PCLK2/4 */ 
    //RCC_ADCCLKConfig(RCC_PCLK2_Div6); 
     /* Get HSE clock = 25MHz on PA8 pin(MCO) */ 
    //RCC_MCOConfig(RCC_MCO_HSE); 
    /* Configure PLLs *********************************************************/ 
    /* PPL2 configuration: PLL2CLK = (HSE / 5) * 8 = 40 MHz */ 
    RCC_PREDIV2Config(RCC_PREDIV2_Div5); 
    RCC_PLL2Config(RCC_PLL2Mul_8); 

    /* Enable PLL2 */ 
    RCC_PLL2Cmd(ENABLE); 

    /* Wait till PLL2 is ready */ 
    while (RCC_GetFlagStatus(RCC_FLAG_PLL2RDY) == RESET) 
    {} 

    /* PPL1 configuration: PLLCLK = (PLL2 / 5) * 9 = 72 MHz */ 
    RCC_PREDIV1Config(RCC_PREDIV1_Source_PLL2, RCC_PREDIV1_Div5); 
    RCC_PLLConfig(RCC_PLLSource_PREDIV1, RCC_PLLMul_9);
	
	RCC->CFGR&=~0x400000;       //OTG prescale is 3, 72*2/3->48M 
    /* Enable PLL */ 
    RCC_PLLCmd(ENABLE); 

    /* Wait till PLL is ready */ 
    while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET) 
    {} 

    /* Select PLL as system clock source */ 
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK); 

    /* Wait till PLL is used as system clock source */ 
    while (RCC_GetSYSCLKSource() != 0x08) 
    {} 
  } 

  RCC_GetClocksFreq(&RCC_ClockFreq); 
#if 0
  /* Enable USART2 clock */ 
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); 


  /* Enable ETHERNET clock  */ 
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_ETH_MAC | RCC_AHBPeriph_ETH_MAC_Tx | 
                        RCC_AHBPeriph_ETH_MAC_Rx, ENABLE); 

  /* Enable GPIOs clocks */ 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | 
                         RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE| RCC_APB2Periph_AFIO, ENABLE); 
  /* Enable ADC1 clock */ 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); 
#endif
} 
#else
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
		RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE); //设置外部时钟为HSE
		//_RCC_HCLKConfig(RCC_SYSCLK_Div1);   //设置AHB时钟=AHB_FREQ MHz
		RCC_PCLK1Config(PCLK1_DIV);   //设置APB1时钟=36 MHz(APB1时钟最大值)
		RCC_PCLK2Config(PCLK2_DIV);   //设置APB2时钟=72 MHz
		RCC_PLLCmd(DISABLE); //关闭PLL

   #if !defined (STM32F10X_LD_VL) && !defined (STM32F10X_MD_VL) && !defined (STM32F10X_HD_VL) && !defined (STM32F10X_CL)
	    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, HCLK_MUL); //PLL必须在其激活前完成配置（设置PLL时钟源及倍频系数）
   #else
		RCC_PLLConfig(RCC_PLLSource_PREDIV1, HCLK_MUL); //PLL必须在其激活前完成配置（设置PLL时钟源及倍频系数）
   #endif

		RCC_PLLCmd(ENABLE);
		// Wait till PLL is ready 
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
		{
		}
		// Select PLL as system clock source 
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		// Wait till PLL is used as system clock source 
		while(RCC_GetSYSCLKSource() != 0x08)
		{
		}
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
#endif
//static INT8U  fac_us=0;//us延时倍乘数
//static INT16U fac_ms=0;//ms延时倍乘数
//初始化延迟函数
//SYSTICK的时钟固定为HCLK时钟的1/8
//SYSCLK:系统时钟
void SysTick_Configuration(void)
{
	//SysTick->CTRL&=0xfffffffb;//bit2清空,选择外部时钟  HCLK/8
    if (SysTick_Config(HCLK_VALUE / 1000 * MOVE_STEP_PERIOD))     // (72MHz/1000)*SYSCLK=1MS
	{ 
	   /* Capture error */
	   ASSERT_FAILED(); 
	    while (1);
	}
}	
//延时nms
//注意nms的范围
//SysTick->LOAD为24位寄存器,所以,最大延时为:
//nms<=0xffffff*8*1000/SYSCLK
//SYSCLK单位为Hz,nms单位为ms
//对72M条件下,nms<=1864 
void Delay_ms(INT16U nms)
{
  INT32U ms,counts = 0;

  ms = Pub_Timer.Ms;

  Clr_Watch_Dog();
  while(1)
  {
    if(ms != Pub_Timer.Ms)
	{
	  ms = Pub_Timer.Ms;
	  counts ++;
	  if(counts > nms + 1)
	   return;

      Clr_Watch_Dog();
	}
	
  }
} 

 
//延时nus
//nus为要延时的us数.		    								   
void Delay_us(INT32U nus)
{
  volatile INT32S i;
  volatile INT32S j; 
   
  i =0;

#if WDG_EN
  IWDG->KR = ((uint16_t)0xAAAA);
#endif    
  //if(nus EQ 0)
    //return; 
  
  //j = (INT32S)(12 * nus - 2) * (HCLK_VALUE / 72000000);
  //48M、72M等均已验证正确
#ifdef CARD_A
  j = (INT32S)nus * (HCLK_VALUE / 2000000);// - HCLK_VALUE / 36000000;
  while(i < j) 
  {
    i++;
	}
#else
  j = (INT32S)nus * (HCLK_VALUE / 6000000) - HCLK_VALUE / 36000000;
  while(i < j) 
  {
    i++;
	}
#endif
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
   Clr_Watch_Dog();

   while (!(USART2->SR & USART_FLAG_TXE));
   USART2->DR = (Data & (uint16_t)0x01FF);
}

//发送一个字节通信数据
void Com_Send_Byte(INT8U Ch, INT8U Data)
{
  Clr_Watch_Dog();
  
  if(Ch EQ CH_COM)
  {
     while (!(USART1->SR & USART_FLAG_TXE));
     USART1->DR = (Data & (uint16_t)0x01FF);
  }
  else if(Ch EQ CH_GPRS)
  {
#if GPRS_EN || SMS_EN
     while (!(UART4->SR & USART_FLAG_TXE));
     UART4->DR = (Data & (uint16_t)0x01FF);
#else
     ASSERT_FAILED();
#endif
  }
  else if(Ch EQ CH_DBG)
  {
    if(Chk_JP_Status() EQ FAC_STATUS) //工厂状态
	{
      while (!(USART2->SR & USART_FLAG_TXE));
      USART2->DR = (Data & (uint16_t)0x01FF);
	}
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
   SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;
   SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
   SPI_InitStructure.SPI_CRCPolynomial = 7;
   SPI_Init(SPI1, &SPI_InitStructure);

   /* Enable SPI1  */
   SPI_Cmd(SPI1, ENABLE);

}

#if NET_EN
//SPI1初始化
void SPI1_ENC28J60_Init(void)
{
   SPI_InitTypeDef SPI_InitStructure;
   GPIO_InitTypeDef GPIO_InitStructure;

   RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1 | RCC_APB2Periph_GPIOA, ENABLE);
/////////////////////////////////////////////////////////////////////////////////////////////////

   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
   GPIO_Init(GPIOA, &GPIO_InitStructure);

   ENC28J60_CSH();
   SPI_Cmd(SPI1, DISABLE);

   /* SPI1 configuration */ 
   SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; //全双工
   SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
   SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
   SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
   SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
   SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;    //软件CS
   SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;  //16分频
   SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
   SPI_InitStructure.SPI_CRCPolynomial = 7;
   SPI_Init(SPI1, &SPI_InitStructure);


   /* Enable SPI1  */
   SPI_Cmd(SPI1, ENABLE);
}
#endif
/*******************************************************************************
* Function Name  : SPI_FLASH_Init
* Description    : Initializes the peripherals used by the SPI FLASH driver.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI2_Init(void)
{
  SPI_InitTypeDef  SPI_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable SPI1 and GPIO clocks */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);

  /* Configure SPI1 pins: SCK, MISO and MOSI */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* Deselect the FLASH: Chip Select high */
  //SPI_FLASH_CS_HIGH();
  //SPI_Cmd(SPI2, DISABLE);
  /* SPI1 configuration */
  SPI_InitStructure.SPI_Direction = SPI_Direction_1Line_Tx;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
#if 1// MAX_SCAN_BLOCK_NUM == 16
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_16b;//SPI_DataSize_8b;
#else
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
#endif
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI2, &SPI_InitStructure);
  /* Enable SPI1  */
  SPI_Cmd(SPI2, ENABLE);
/*
  while(1)
  {
  SPI_I2S_SendData(SPI2, 0x55);
  while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);
  }
*/
  SPI_I2S_SendData(SPI2, 0xFF);
  while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);
  
  //SPI_I2S_DMACmd(SPI2, SPI_I2S_DMAReq_Tx, ENABLE);
}

//SPI1读写一字节数据
INT8U SPI1_ReadWrite(INT8U writedat)
{
  Clr_Watch_Dog();
   /* Loop while DR register in not emplty */
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET);

  /* Send byte through the SPI1 peripheral */
  SPI_I2S_SendData(SPI1, writedat);

  /* Wait to receive a byte */
  while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET);

  /* Return the byte read from the SPI bus */
  return SPI_I2S_ReceiveData(SPI1);
}

//SPI2发送接收一个字节
INT8U SPI2_ReadWrite(INT8U writedat)
{
  Clr_Watch_Dog();
   /* Loop while DR register in not emplty */
  while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE) == RESET);

  /* Send byte through the SPI1 peripheral */
  SPI_I2S_SendData(SPI2, writedat);

  /* Wait to receive a byte */
  //while (SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE) == RESET);

  /* Return the byte read from the SPI bus */
  //return SPI_I2S_ReceiveData(SPI2);
  return 1;
}

void NVIC_Configuration(void)
{
    //----------中断优先级设置--------

	NVIC_InitTypeDef NVIC_InitStructure = {0};
	
	/* Configure the NVIC Preemption Priority Bits */  
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);	//设置优先级分组：先占优先级0位,从优先级4位
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		//设置优先级分组：先占优先级2位,从优先级2位
	
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, APP_ADDRESS_OFF);	//重新定期中断向量区
	
	
    /* Enable the USARTy Interrupt */
	//串口接收中断，优先级最高
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		//USART1中断,用于接收通信数据
 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		//
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器USART1

#if SMS_EN || GPRS_EN
	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;		//USART4中断,用于接收GPRS模块数据
 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		//
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器USART1
#endif

  //USB中断为PreemptionPriority = 0,SubPriority = 2
	
#if TIM1_EN
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;  //1ms中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
#else 	 	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //1ms中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
#endif

	//扫描中断
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //扫描特效
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
	
//USB_OTG_BSP_EnableInterrupt  函数中有设置，此处不设置
/*
#ifdef CHIP_USB_HOST	
	NVIC_InitStructure.NVIC_IRQChannel = OTG_FS_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
#endif
*/
    
	//特效中断
    NVIC_SetPriority (SysTick_IRQn, 0x0C);                //抢占优先级为3

}

//INT8U SPI2_DMA_Data[] = {0x24, 0x92, 0x49};
//INT8U SPI2_DMA_Data[] = {0x11, 0x11, 0x11, 0x11};
//INT16U SPI2_DMA_Data[] = {0x0303, 0x0303, 0x0303, 0x0303};
//INT16U SPI2_DMA_Data[] = {0x0204, 0x0810, 0x2040, 0x81FF};
//INT16U SPI2_DMA_Data[] = {0x0F0F, 0x0F0F, 0x0F0F, 0x0F0F};
//DMA初始化。
#if MAX_SCAN_BLOCK_NUM EQ 16
INT16U SPI2_DMA_Data[] = {0x0101, 0x0101, 0x0101, 0x0101};
void DMA_Configuration(void)
{
  DMA_InitTypeDef DMA_InitStructure;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
/*
  DMA_DeInit(DMA1_Channel5);

  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&SPI2->DR;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)SPI2_DMA_Data; //需要发送的Dma数据
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = 4;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;//DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
  DMA_InitStructure.DMA_Priority = DMA_Priority_Low;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

  DMA_Init(DMA1_Channel5, &DMA_InitStructure);
 */
  /* DMA1 Channel1 enable */
  //DMA_Cmd(DMA1_Channel1, ENABLE);

  DMA_DeInit(DMA1_Channel5);

  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&GPIOE->ODR;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&Scan_Data0[1][2]; //绿色数据起始地址
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = 8;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

  DMA_Init(DMA1_Channel5, &DMA_InitStructure);

  /* DMA1 Channel5 enable */
  DMA_Cmd(DMA1_Channel5, ENABLE);

  DMA_DeInit(DMA1_Channel7);

  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&GPIOD->ODR;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&Scan_Data0[0][2]; //红色数据起始地址
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = 8;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

  DMA_Init(DMA1_Channel7, &DMA_InitStructure);

  /* DMA1 Channel5 enable */
  DMA_Cmd(DMA1_Channel7, ENABLE);
}
#elif MAX_SCAN_BLOCK_NUM EQ 8
INT16U SPI2_DMA_Data[] = {0x0101, 0x0101, 0x0101, 0x0101};
void DMA_Configuration(void)
{
  DMA_InitTypeDef DMA_InitStructure;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

  DMA_DeInit(DMA1_Channel5);

  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&GPIOC->ODR;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&Scan_Data0[1][2]; //绿色数据起始地址
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = 8;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

  DMA_Init(DMA1_Channel5, &DMA_InitStructure);

  /* DMA1 Channel5 enable */
  DMA_Cmd(DMA1_Channel5, ENABLE);

  DMA_DeInit(DMA1_Channel7);

  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&GPIOB->ODR;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&Scan_Data0[0][2]; //红色数据起始地址
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = 8;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

  DMA_Init(DMA1_Channel7, &DMA_InitStructure);

  /* DMA1 Channel5 enable */
  DMA_Cmd(DMA1_Channel7, ENABLE);
}
#elif MAX_SCAN_BLOCK_NUM EQ 4
INT16U SPI2_DMA_Data[] = {0x0303, 0x0303, 0x0303, 0x0303};
//INT8U SPI2_DMA_Data[] = {0x0
//INT8U SPI2_DMA_Data[] = {0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x81};
//INT16U SPI2_DMA_Data[] = {0x0101, 0x0101, 0x0101, 0x0101};
 void DMA_Configuration(void)
{
  DMA_InitTypeDef DMA_InitStructure;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
/*
  DMA_DeInit(DMA1_Channel5);

  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&SPI2->DR;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)SPI2_DMA_Data; //需要发送的Dma数据
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = 4;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;//DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
  DMA_InitStructure.DMA_Priority = DMA_Priority_Low;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

  DMA_Init(DMA1_Channel5, &DMA_InitStructure);
 */
  DMA_DeInit(DMA1_Channel7);

  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&GPIOB->ODR;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&Scan_Data0[0][2]; //绿色数据起始地址
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = 8;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

  DMA_Init(DMA1_Channel7, &DMA_InitStructure);

  /* DMA1 Channel5 enable */
  DMA_Cmd(DMA1_Channel7, ENABLE);
}
#endif

//定时器2,输入捕获中断!!两个通道，下降沿捕获！
void TIM2_Configuration(void)
{
  TIM_ICInitTypeDef  TIM_ICInitStructure;
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

#if TIM1_EN EQ 0
	TIM_TimeBaseStructure.TIM_Period = 1000 / 10; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
  TIM_TimeBaseStructure.TIM_Prescaler =(PCLK1_VALUE * 2/100000-1); //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
#else
	TIM_TimeBaseStructure.TIM_Period = 100 / 10 * (PCLK1_VALUE * 2/100000); //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
	TIM_TimeBaseStructure.TIM_Prescaler =0;//(PCLK1_VALUE * 2/100000-1); //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
#endif	
	/* Enables the Update event for TIM3 */
	//TIM_UpdateDisableConfig(TIM3,ENABLE); 	//使能 TIM4 更新事件 
	
	/* TIM IT enable */
#if TIM1_EN EQ 0
	TIM_ITConfig(  //使能或者失能指定的TIM中断
		TIM2, //TIM4
		TIM_IT_Update,   //TIM 触发中断源 
		ENABLE  //使能
		);
#endif

  TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;// | TIM_Channel_1;
  TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;//TIM_ICPolarity_Falling;
  TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
  TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
  TIM_ICInitStructure.TIM_ICFilter = 0x0;

  TIM_ICInit(TIM2, &TIM_ICInitStructure);

  TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;// | TIM_Channel_2;
  TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;//TIM_ICPolarity_Falling;
  TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
  TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
  TIM_ICInitStructure.TIM_ICFilter = 0x0;

  TIM_ICInit(TIM2, &TIM_ICInitStructure);
    
  /* TIM enable counter */
  TIM_Cmd(TIM2, ENABLE);

  /* Enable the CC2 Interrupt Request */
  TIM_DMACmd(TIM2, TIM_DMA_CC1, ENABLE);

  TIM_DMACmd(TIM2, TIM_DMA_CC2, ENABLE);

}


//定时器3的周期设置
//Period
void _TIM3_Set_Period(INT16U Period)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};

    TIM_Cmd(TIM3, DISABLE);  //使能TIMx外设
	/* ---------------------------------------------------------------
	TIM4CLK 即PCLK1=36MHz
	TIM4CLK = 36 MHz, Prescaler = 7200, TIM4 counter clock = 5K,即改变一次为5K,周期就为10K
	--------------------------------------------------------------- */
	/* Time base configuration */
	
	//周期为1ms
	if(Period > 1000)
	  Period = 1000;

	TIM_TimeBaseStructure.TIM_Period = Period / 10; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
    TIM_TimeBaseStructure.TIM_Prescaler =(PCLK1_VALUE * 2/100000-1); //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

	TIM_Cmd(TIM3, ENABLE);  //使能TIMx外设
}

#if 1
//扫描中断
void TIM3_Configuration(void)
{
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

    _TIM3_Set_Period(100); //默认100ms一次
	
	TIM_Cmd(TIM3, DISABLE);  //使能TIMx外设
	/* TIM IT enable */
	TIM_ITConfig(  //使能或者失能指定的TIM中断
		TIM3, //TIM4
		TIM_IT_Update,   //TIM 触发中断源 
		ENABLE  //使能
		);
	
	/* TIM4 enable counter */
	TIM_Cmd(TIM3, ENABLE);  //使能TIMx外设

}
#else
void TIM3_Configuration(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	TIM_TimeBaseStructure.TIM_Period = SCAN_SCREEN_PERIOD / 10; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
    TIM_TimeBaseStructure.TIM_Prescaler =(PCLK1_VALUE * 2/100000-1); //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位

	/* TIM IT enable */
	TIM_ITConfig(  //使能或者失能指定的TIM中断
		TIM3, //TIM4
		TIM_IT_Update,   //TIM 触发中断源 
		ENABLE  //使能
		);
	
	/* TIM4 enable counter */
	TIM_Cmd(TIM3, ENABLE);  //使能TIMx外设

}
#endif
//101系列不存在TIM1定时器

//定时器中断，用于绘制边框

void TIM1_Configuration(void)
{
#if TIM1_EN
    //RCC_ClocksTypeDef RCC_Clocks;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); 

	TIM_TimeBaseStructure.TIM_Period = 1000; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms

#if  PCLK2_VALUE ==	HCLK_VALUE   
	TIM_TimeBaseStructure.TIM_Prescaler =(PCLK2_VALUE /1000000-1); //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
#else
	#error "此处代码没有验证，需要重新验证下"
	TIM_TimeBaseStructure.TIM_Prescaler =(PCLK2_VALUE * 2 /1000000-1); 
#endif

	TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0; 
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

	TIM_ClearFlag(TIM1, TIM_FLAG_Update); 
	TIM_ARRPreloadConfig(TIM1, DISABLE); 
	
	TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE); 
	TIM_Cmd(TIM1, ENABLE);
#endif
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
	TIM_TimeBaseStructure.TIM_Period = (PCLK1_VALUE * 2 / OE_PWM_FREQ / 10)/10; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 80K
	TIM_TimeBaseStructure.TIM_Prescaler = 0; //设置用来作为TIMx时钟频率除数的预分频值  不分频
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
/*
#if TIM1_EN EQ 0	
	TIM_ITConfig(  //使能或者失能指定的TIM中断
		TIM4, //TIM4
		TIM_IT_Update,   //TIM 触发中断源 
		ENABLE  //使能
		);
#endif
*/
	/* TIM3 enable counter */
	TIM_Cmd(TIM4, ENABLE);  //使能TIMx外设

    Set_OE_Duty_Polarity(MAX_LIGHTNESS_LEVEL / 2, 0);

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
  /*
	//PA3串口1接收
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
*/	
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
	USART_InitStructure.USART_Mode                = USART_Mode_Tx;	//只发不收
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

//GPRS模块接口
void UART4_Init(void)
{
    USART_InitTypeDef USART_InitStructure = {0};
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE );

	//PC11串口4接收
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //内部上拉，防止模块没初始化好，总是进中断
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	//PC10串口4发送
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	//串口4用于GPRS接口
	USART_InitStructure.USART_BaudRate            = 57600;//Get_Com_Baud();
	USART_InitStructure.USART_WordLength          = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits            = USART_StopBits_1;
	USART_InitStructure.USART_Parity              = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(UART4, &USART_InitStructure);
	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);
	USART_Cmd(UART4, ENABLE);
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

void Soft_Reset(void) //软件复位
{
  Delay_ms(5);
  *((INT32U *)0xE000ED0C) = 0x05fa0004; //实现系统复位
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


void Set_OE_Duty_Polarity(INT8U Duty, INT8U Polarity)
{

  if(Duty > MAX_LIGHTNESS_LEVEL)
  {
    Duty = MAX_LIGHTNESS_LEVEL;
    ASSERT_FAILED();
  }
 
  //TIM_Cmd(TIM4, DISABLE);  //使能TIMx外设

  if(Polarity EQ 0)
    TIM4->CCR3 = TIM4->ARR * Duty / MAX_LIGHTNESS_LEVEL;
  else
    TIM4->CCR3 = TIM4->ARR * (MAX_LIGHTNESS_LEVEL - Duty) / MAX_LIGHTNESS_LEVEL;

  //TIM_Cmd(TIM4, ENABLE);  //使能TIMx外设

}

void Unselect_SPI_Device(void)
{
  SET_FLASH_CS(1); //不选中Flash
  SET_CH376_CS(1);	//不选中CH376
  SET_DS1302_CS(0);	//不选中DS1302
#if NET_EN
  ENC28J60_CSH(); //不选中ENC28J60
#endif
}

void RST_Periph(void)
{
#if SMS_EN || GPRS_EN
  ModuleReset();
#endif

  SET_RST(0);
  Delay_us(100);
  SET_RST(1);
  Delay_ms(100);
  SET_RST(0);

#if NET_EN
  SET_ENC28J60_RST(1);
  Delay_us(100);
  SET_ENC28J60_RST(0);
  Delay_ms(100);
  SET_ENC28J60_RST(1);
#endif
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

static const INT8U TempTime1[] = {12, 12, 31, 23, 59, 59, 0};
//自身硬件的检测
//返回错误代码,0表示没有错误
//第0位,存储器错误
//第1位,时钟错误
//第2位,加密数据错误
INT16U Self_Test(void)
{
  INT32U Data = 0x55AA5AA5;
  INT8U Re = 1;
  INT16U ErrFlag = 0;// i;
  S_Time TempTime, TempTime2;

/*#define T_YEAR  0 //--除了日和年其他都从0开始计起。日从1计起，年从1900年计起
#define T_MONTH 1
#define T_DATE  2
#define T_HOUR  3
#define T_MIN   4
#define T_SEC   5
#define T_WEEK  6
*/
  Screen_Status.Self_OC_Flag = CLOSE_FLAG; //先关闭显示

  if(Screen_Status.Encryption_Err_Flag)	//加密数据错误后不能进入自检状态，这样生产自检环节就可检测出来
  { 
    debug("加密数据检测失败\r\n"); 
	Re = 0;
	ErrFlag	|= 0x04;
  }

  debug("---系统自检开始---");
#if QT_EN EQ 0
  //--------对存储器的测试---------------
  Write_Storage_Data(SDI_TEST_DATA, &Data, sizeof(Data));
  Delay_ms(10);
  memset(&Data, 0x00, sizeof(Data));
  Read_Storage_Data(SDI_TEST_DATA, &Data, &Data, sizeof(Data));

  if(0x55AA5AA5 EQ Data)
  {
    debug("SPI Flash 自检成功\r\n");
    Re = Re & 1;
  }
  else
  { 
    debug("SPI Flash 自检失败\r\n"); 
	Re = 0;
	ErrFlag	|= 0x01;

	//Test_LED_Flash(1, 500);
  }
/*
  memset(Show_Data_Bak.Color_Data, 0xAA, sizeof(Show_Data_Bak.Color_Data));
  for(i = 0; i < DATA_FLASH_SIZE / sizeof(Show_Data.Color_Data); i ++)
  {
    Write_PHY_Mem(i * sizeof(Show_Data_Bak.Color_Data), Show_Data_Bak.Color_Data, sizeof(Show_Data_Bak.Color_Data));
	Read_PHY_Mem(i * sizeof(Show_Data.Color_Data), Show_Data.Color_Data, sizeof(Show_Data.Color_Data), Show_Data.Color_Data, sizeof(Show_Data.Color_Data)); 
    if(memcmp(Show_Data.Color_Data, Show_Data_Bak.Color_Data, sizeof(Show_Data.Color_Data)) != 0)
	  ErrFlag	|= 0x01;	  
  }
*/
  //-----------------------------------------

  //--------对时钟的测试---------------------
  
  //while(1)
  {
 // DS1302_Init();
#if CLOCK_EN
  _Get_Cur_Time(TempTime.Time); //保存当前时间
  Print_Cur_Time();

  Set_Cur_Time((INT8U *)TempTime1); //置时间到零点前，跨日
  Delay_sec(2);//Delay_sec(2);
  _Get_Cur_Time(TempTime2.Time);

  Set_Cur_Time(TempTime.Time); //恢复时间
#endif
  }
 
  if(TempTime2.Time[T_YEAR] EQ 13 && TempTime2.Time[T_MONTH] EQ 1 &&\
     TempTime2.Time[T_DATE] EQ 1 && TempTime2.Time[T_HOUR] EQ 0 &&\
	 TempTime2.Time[T_MIN] EQ 0 && TempTime2.Time[T_SEC] < 3)
  {
    debug("时钟自检成功\r\n");
    Re = Re & 1;
  }
  else
  {
    debug("时钟自检失败\r\n"); 
	Re = 0;
	ErrFlag	|= 0x02;

	//Test_LED_Flash(2, 500);
  }
  //-----------------------------------------
/*
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
*/
  if(Re EQ 0)
	debug("外围器件自检失败！\r\n");
  else
	debug("外围器件自检成功！\r\n");

#endif

  Screen_Status.Self_OC_Flag = OPEN_FLAG; //先关闭显示

  return ErrFlag;
}

 //工厂状态自检
void Fac_Status_Self_Test(void)
{
  INT8U Re;

    //当前在工厂状态且按下测试键则进入自检状态
  if(!(Chk_Test_Key_Down() && Chk_JP_Status() EQ FAC_STATUS))
    return;
  Re = Self_Test(); //自身硬件检测

  if(Re)
   Test_LED_Flash(5, 500);
}


/*
//用于测试DMA方式
//--------------------------------------------
void DMA_Configuration(void)
{
  DMA_InitTypeDef DMA_InitStructure;

  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

  DMA_DeInit(DMA1_Channel5);

  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&GPIOD->ODR;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)SRC_Buffer;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = 1;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

  DMA_Init(DMA1_Channel5, &DMA_InitStructure);

  DMA_Cmd(DMA1_Channel5, ENABLE);
}
*/
extern void PWR_BackupAccessCmd(FunctionalState NewState);
//备份寄存器初始化
void BKP_Register_Init(void)
{
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE); 
  /* Enable write access to Backup domain */
  PWR_BackupAccessCmd(ENABLE);

  BKP_ClearFlag();
}

void IWDG_Init(void)
{
  RCC_LSICmd(ENABLE);
  while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY)==RESET);//等待直到LSI稳定
  
  if (RCC_GetFlagStatus(RCC_FLAG_IWDGRST) != RESET)
  {
    /* Clear reset flags */
    RCC_ClearFlag();
  }
  else
  {

  }
  /* IWDG timeout equal to 280 ms (the timeout may varies due to LSI frequency
     dispersion) */
  /* Enable write access to IWDG_PR and IWDG_RLR registers */
  IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);

  /* IWDG counter clock: 40KHz(LSI) / 64 = 0.625 KHz, 1.6ms */
  IWDG_SetPrescaler(IWDG_Prescaler_64);

  /* Set counter reload value to 349, 1.28S */
  IWDG_SetReload(800);

  /* Reload IWDG counter */
  IWDG_ReloadCounter();

  /* Enable IWDG (the LSI oscillator will be enabled by hardware) */
  IWDG_Enable();
}
//-------------------------------------

void ADC_configuration(void)
{
#if TEMP_SHOW_EN
	ADC_InitTypeDef ADC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	ADC_InitStructure.ADC_Mode=ADC_Mode_Independent;//独立模式
	ADC_InitStructure.ADC_ScanConvMode=DISABLE;//连续多通道模式	
	ADC_InitStructure.ADC_ContinuousConvMode=DISABLE;//单次转换	
	ADC_InitStructure.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;//转换由软件而不是外部触发启动
	ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right;//右对齐
	ADC_InitStructure.ADC_NbrOfChannel=1;//扫描通道数
	ADC_Init(ADC1,&ADC_InitStructure);
	ADC_Cmd(ADC1,ENABLE);//使能或者失能指定的ADC

	ADC_ResetCalibration(ADC1);//重置指定的ADC的校准寄存器
	while(ADC_GetResetCalibrationStatus(ADC1));//等待校准寄存器初始化
	ADC_StartCalibration(ADC1);//开始校准
	while(ADC_GetCalibrationStatus(ADC1));//等待校准完成
	//ADC_SoftwareStartConvCmd(ADC1,ENABLE);//使能指定的ADC的软件转换启动功能
	ADC_TempSensorVrefintCmd(ENABLE);
	/*
	//上电后进行一次转换。
	ADC_RegularChannelConfig(ADC1,ADC_Channel_16,1,ADC_SampleTime_239Cycles5);
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);//使能指定的ADC的软件转换启动功能

	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC)==RESET);//检查制定ADC标志位置1与否 ADC_FLAG_EOC 转换结束标志位
	ADC_GetConversionValue(ADC1);
	//开始下一次转化
	ADC_RegularChannelConfig(ADC1,ADC_Channel_16,1,ADC_SampleTime_239Cycles5);
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);//使能指定的ADC的软件转换启动功能
	*/
#endif
}

INT16S GetInterTemperature(void)//ADC_Channel_x 0~17
{
#if TEMP_SHOW_EN
	INT16U adc_value, VrefintAD;
	INT16S temp;

	ADC_RegularChannelConfig(ADC1,ADC_Channel_17,1,ADC_SampleTime_239Cycles5);
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);//使能指定的ADC的软件转换启动功能
	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC)==RESET);//检查制定ADC标志位置1与否 ADC_FLAG_EOC 转换结束标志位
	VrefintAD=ADC_GetConversionValue(ADC1);
	debug("VrefintAD = %d", VrefintAD);

    //启动下一次转化
	ADC_RegularChannelConfig(ADC1,ADC_Channel_16,1,ADC_SampleTime_239Cycles5);
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);//使能指定的ADC的软件转换启动功能

	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC)==RESET);//检查制定ADC标志位置1与否 ADC_FLAG_EOC 转换结束标志位
	adc_value=ADC_GetConversionValue(ADC1);
	//debug("adc_value = %d", adc_value);

	//temp = (INT16S)(((float)1.43 * 1.2 / VrefintAD / (3.3 / 4096)  - (float)adc_value * 1.2 / VrefintAD) * 1000 / 4.35 + 25);
	//temp = (INT16S)((1.43 - (float)adc_value * 3.3 / 4096) * 1000 / 4.35 + 25);
	temp = (INT16S)((1.43 - (float)adc_value * 1.2 / VrefintAD) * 1000 / 4.35 + 25);

	return temp * 10; //单位为0.1度
#else
  return 0;
#endif
}

//CRC模块初始化
void CRC_Init(void)
{
 RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC, ENABLE);
}

extern void CRC_ResetDR(void);

INT32U CRC32(INT8U *pBuf, INT16U nSize)  
{  
    INT32U index = 0;  
    CRC_ResetDR();        //复位CRC    
    for(index = 0; index < nSize; index++)  
    {  
       CRC->DR = (INT32U)pBuf[index];  
     }  
    return (CRC->DR);  
}

//传感器初始化
void Sensor_Init(void)
{
#if TEMP_SHOW_EN || HUMIDITY_SHOW_EN

#if TEMP_SHOW_EN
  DS18B20_Init();
/*  
  GPIO_DQ_Out_Mode() ;  
  while(1)
  {
    DQ_Write_0() ;  //复位脉冲
    Delay_us(100) ; //至少保持480us
    DQ_Write_1() ;  //加速上升沿速度
    Delay_us(100) ; //至少保持480us
  }
*/
#endif

#if TEMP_SHOW_EN && HUMIDITY_SHOW_EN
  SHT1X_Init();
#endif
   
#endif
}

void Warn_Ctrl_Init(void)
{
#if GPRS_EN || SMS_EN
  GPIO_InitTypeDef GPIO_InitStructure = {0};

  GPIO_InitStructure.GPIO_Pin =  CTRL_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(CTRL_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin =  WARN_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //上拉输入
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(WARN_PORT, &GPIO_InitStructure);

  GPIO_ResetBits(CTRL_PORT,CTRL_PIN);
#endif
}
//以上CRC代码在上位机中对应的C#代码
/*
static readonly uint[] Crc32Table =  
04.        {  
05.            0x00000000,0x04C11DB7,0x09823B6E,0x0D4326D9,0x130476DC,0x17C56B6B,0x1A864DB2,0x1E475005,  
06.            0x2608EDB8,0x22C9F00F,0x2F8AD6D6,0x2B4BCB61,0x350C9B64,0x31CD86D3,0x3C8EA00A,0x384FBDBD,  
07.            0x4C11DB70,0x48D0C6C7,0x4593E01E,0x4152FDA9,0x5F15ADAC,0x5BD4B01B,0x569796C2,0x52568B75,  
08.            0x6A1936C8,0x6ED82B7F,0x639B0DA6,0x675A1011,0x791D4014,0x7DDC5DA3,0x709F7B7A,0x745E66CD,  
09.            0x9823B6E0,0x9CE2AB57,0x91A18D8E,0x95609039,0x8B27C03C,0x8FE6DD8B,0x82A5FB52,0x8664E6E5,  
10.            0xBE2B5B58,0xBAEA46EF,0xB7A96036,0xB3687D81,0xAD2F2D84,0xA9EE3033,0xA4AD16EA,0xA06C0B5D,  
11.            0xD4326D90,0xD0F37027,0xDDB056FE,0xD9714B49,0xC7361B4C,0xC3F706FB,0xCEB42022,0xCA753D95,  
12.            0xF23A8028,0xF6FB9D9F,0xFBB8BB46,0xFF79A6F1,0xE13EF6F4,0xE5FFEB43,0xE8BCCD9A,0xEC7DD02D,  
13.            0x34867077,0x30476DC0,0x3D044B19,0x39C556AE,0x278206AB,0x23431B1C,0x2E003DC5,0x2AC12072,  
14.            0x128E9DCF,0x164F8078,0x1B0CA6A1,0x1FCDBB16,0x018AEB13,0x054BF6A4,0x0808D07D,0x0CC9CDCA,  
15.            0x7897AB07,0x7C56B6B0,0x71159069,0x75D48DDE,0x6B93DDDB,0x6F52C06C,0x6211E6B5,0x66D0FB02,  
16.            0x5E9F46BF,0x5A5E5B08,0x571D7DD1,0x53DC6066,0x4D9B3063,0x495A2DD4,0x44190B0D,0x40D816BA,  
17.            0xACA5C697,0xA864DB20,0xA527FDF9,0xA1E6E04E,0xBFA1B04B,0xBB60ADFC,0xB6238B25,0xB2E29692,  
18.            0x8AAD2B2F,0x8E6C3698,0x832F1041,0x87EE0DF6,0x99A95DF3,0x9D684044,0x902B669D,0x94EA7B2A,  
19.            0xE0B41DE7,0xE4750050,0xE9362689,0xEDF73B3E,0xF3B06B3B,0xF771768C,0xFA325055,0xFEF34DE2,  
20.            0xC6BCF05F,0xC27DEDE8,0xCF3ECB31,0xCBFFD686,0xD5B88683,0xD1799B34,0xDC3ABDED,0xD8FBA05A,  
21.            0x690CE0EE,0x6DCDFD59,0x608EDB80,0x644FC637,0x7A089632,0x7EC98B85,0x738AAD5C,0x774BB0EB,  
22.            0x4F040D56,0x4BC510E1,0x46863638,0x42472B8F,0x5C007B8A,0x58C1663D,0x558240E4,0x51435D53,  
23.            0x251D3B9E,0x21DC2629,0x2C9F00F0,0x285E1D47,0x36194D42,0x32D850F5,0x3F9B762C,0x3B5A6B9B,  
24.            0x0315D626,0x07D4CB91,0x0A97ED48,0x0E56F0FF,0x1011A0FA,0x14D0BD4D,0x19939B94,0x1D528623,  
25.            0xF12F560E,0xF5EE4BB9,0xF8AD6D60,0xFC6C70D7,0xE22B20D2,0xE6EA3D65,0xEBA91BBC,0xEF68060B,  
26.            0xD727BBB6,0xD3E6A601,0xDEA580D8,0xDA649D6F,0xC423CD6A,0xC0E2D0DD,0xCDA1F604,0xC960EBB3,  
27.            0xBD3E8D7E,0xB9FF90C9,0xB4BCB610,0xB07DABA7,0xAE3AFBA2,0xAAFBE615,0xA7B8C0CC,0xA379DD7B,  
28.            0x9B3660C6,0x9FF77D71,0x92B45BA8,0x9675461F,0x8832161A,0x8CF30BAD,0x81B02D74,0x857130C3,  
29.            0x5D8A9099,0x594B8D2E,0x5408ABF7,0x50C9B640,0x4E8EE645,0x4A4FFBF2,0x470CDD2B,0x43CDC09C,  
30.            0x7B827D21,0x7F436096,0x7200464F,0x76C15BF8,0x68860BFD,0x6C47164A,0x61043093,0x65C52D24,  
31.            0x119B4BE9,0x155A565E,0x18197087,0x1CD86D30,0x029F3D35,0x065E2082,0x0B1D065B,0x0FDC1BEC,  
32.            0x3793A651,0x3352BBE6,0x3E119D3F,0x3AD08088,0x2497D08D,0x2056CD3A,0x2D15EBE3,0x29D4F654,  
33.            0xC5A92679,0xC1683BCE,0xCC2B1D17,0xC8EA00A0,0xD6AD50A5,0xD26C4D12,0xDF2F6BCB,0xDBEE767C,  
34.            0xE3A1CBC1,0xE760D676,0xEA23F0AF,0xEEE2ED18,0xF0A5BD1D,0xF464A0AA,0xF9278673,0xFDE69BC4,  
35.            0x89B8FD09,0x8D79E0BE,0x803AC667,0x84FBDBD0,0x9ABC8BD5,0x9E7D9662,0x933EB0BB,0x97FFAD0C,  
36.            0xAFB010B1,0xAB710D06,0xA6322BDF,0xA2F33668,0xBCB4666D,0xB8757BDA,0xB5365D03,0xB1F740B4  
37.        };  
38.        //查表法   
39.        public static uint CRC32Software(byte[] pData, int Length)  
40.        {  
41.  
42.            uint nReg;//CRC寄存器   
43.            uint nTemp = 0;  
44.            int i, n;  
45.            nReg = 0xFFFFFFFF;//   
46.            for (n = 0; n < Length; n++)  
47.            {  
48.                nReg ^= (uint)pData[n];  
49.                for (i = 0; i < 4; i++)  
50.                {  
51.                    nTemp = Crc32Table[(nReg >> 24) & 0xff]; //取一个字节，查表   
52.                    nReg <<= 8;                        //丢掉计算过的头一个BYTE   
53.                    nReg ^= nTemp;                //与前一个BYTE的计算结果异或    
54.                }  
55.            }  
56.            return nReg;  
57.        }  

*/
#endif
