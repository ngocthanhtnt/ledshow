#define LED_SCAN_C
#include "Includes.h"

/* ------------ RCC registers bit address in the alias region ----------- */
#define RCC_OFFSET                (RCC_BASE - PERIPH_BASE)

/* --- CR Register ---*/

/* Alias word address of HSION bit */
#define CR_OFFSET                 (RCC_OFFSET + 0x00)
#define HSION_BitNumber           0x00
#define CR_HSION_BB               (PERIPH_BB_BASE + (CR_OFFSET * 32) + (HSION_BitNumber * 4))

/* Alias word address of PLLON bit */
#define PLLON_BitNumber           0x18
#define CR_PLLON_BB               (PERIPH_BB_BASE + (CR_OFFSET * 32) + (PLLON_BitNumber * 4))

#ifdef STM32F10X_CL
 /* Alias word address of PLL2ON bit */
 #define PLL2ON_BitNumber          0x1A
 #define CR_PLL2ON_BB              (PERIPH_BB_BASE + (CR_OFFSET * 32) + (PLL2ON_BitNumber * 4))

 /* Alias word address of PLL3ON bit */
 #define PLL3ON_BitNumber          0x1C
 #define CR_PLL3ON_BB              (PERIPH_BB_BASE + (CR_OFFSET * 32) + (PLL3ON_BitNumber * 4))
#endif /* STM32F10X_CL */ 

/* Alias word address of CSSON bit */
#define CSSON_BitNumber           0x13
#define CR_CSSON_BB               (PERIPH_BB_BASE + (CR_OFFSET * 32) + (CSSON_BitNumber * 4))

/* --- CFGR Register ---*/

/* Alias word address of USBPRE bit */
#define CFGR_OFFSET               (RCC_OFFSET + 0x04)

#ifndef STM32F10X_CL
 #define USBPRE_BitNumber          0x16
 #define CFGR_USBPRE_BB            (PERIPH_BB_BASE + (CFGR_OFFSET * 32) + (USBPRE_BitNumber * 4))
#else
 #define OTGFSPRE_BitNumber        0x16
 #define CFGR_OTGFSPRE_BB          (PERIPH_BB_BASE + (CFGR_OFFSET * 32) + (OTGFSPRE_BitNumber * 4))
#endif /* STM32F10X_CL */ 

/* --- BDCR Register ---*/

/* Alias word address of RTCEN bit */
#define BDCR_OFFSET               (RCC_OFFSET + 0x20)
#define RTCEN_BitNumber           0x0F
#define BDCR_RTCEN_BB             (PERIPH_BB_BASE + (BDCR_OFFSET * 32) + (RTCEN_BitNumber * 4))

/* Alias word address of BDRST bit */
#define BDRST_BitNumber           0x10
#define BDCR_BDRST_BB             (PERIPH_BB_BASE + (BDCR_OFFSET * 32) + (BDRST_BitNumber * 4))

/* --- CSR Register ---*/

/* Alias word address of LSION bit */
#define CSR_OFFSET                (RCC_OFFSET + 0x24)
#define LSION_BitNumber           0x00
#define CSR_LSION_BB              (PERIPH_BB_BASE + (CSR_OFFSET * 32) + (LSION_BitNumber * 4))

#ifdef STM32F10X_CL
/* --- CFGR2 Register ---*/

 /* Alias word address of I2S2SRC bit */
 #define CFGR2_OFFSET              (RCC_OFFSET + 0x2C)
 #define I2S2SRC_BitNumber         0x11
 #define CFGR2_I2S2SRC_BB          (PERIPH_BB_BASE + (CFGR2_OFFSET * 32) + (I2S2SRC_BitNumber * 4))

 /* Alias word address of I2S3SRC bit */
 #define I2S3SRC_BitNumber         0x12
 #define CFGR2_I2S3SRC_BB          (PERIPH_BB_BASE + (CFGR2_OFFSET * 32) + (I2S3SRC_BitNumber * 4))
#endif /* STM32F10X_CL */

/* ---------------------- RCC registers bit mask ------------------------ */

/* CR register bit mask */
#define CR_HSEBYP_Reset           ((uint32_t)0xFFFBFFFF)
#define CR_HSEBYP_Set             ((uint32_t)0x00040000)
#define CR_HSEON_Reset            ((uint32_t)0xFFFEFFFF)
#define CR_HSEON_Set              ((uint32_t)0x00010000)
#define CR_HSITRIM_Mask           ((uint32_t)0xFFFFFF07)

/* CFGR register bit mask */
#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL) || defined (STM32F10X_CL) 
 #define CFGR_PLL_Mask            ((uint32_t)0xFFC2FFFF)
#else
 #define CFGR_PLL_Mask            ((uint32_t)0xFFC0FFFF)
#endif /* STM32F10X_CL */ 

#define CFGR_PLLMull_Mask         ((uint32_t)0x003C0000)
#define CFGR_PLLSRC_Mask          ((uint32_t)0x00010000)
#define CFGR_PLLXTPRE_Mask        ((uint32_t)0x00020000)
#define CFGR_SWS_Mask             ((uint32_t)0x0000000C)
#define CFGR_SW_Mask              ((uint32_t)0xFFFFFFFC)
#define CFGR_HPRE_Reset_Mask      ((uint32_t)0xFFFFFF0F)
#define CFGR_HPRE_Set_Mask        ((uint32_t)0x000000F0)
#define CFGR_PPRE1_Reset_Mask     ((uint32_t)0xFFFFF8FF)
#define CFGR_PPRE1_Set_Mask       ((uint32_t)0x00000700)
#define CFGR_PPRE2_Reset_Mask     ((uint32_t)0xFFFFC7FF)
#define CFGR_PPRE2_Set_Mask       ((uint32_t)0x00003800)
#define CFGR_ADCPRE_Reset_Mask    ((uint32_t)0xFFFF3FFF)
#define CFGR_ADCPRE_Set_Mask      ((uint32_t)0x0000C000)

/* CSR register bit mask */
#define CSR_RMVF_Set              ((uint32_t)0x01000000)

#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL) || defined (STM32F10X_CL) 
/* CFGR2 register bit mask */
 #define CFGR2_PREDIV1SRC         ((uint32_t)0x00010000)
 #define CFGR2_PREDIV1            ((uint32_t)0x0000000F)
#endif
#ifdef STM32F10X_CL
 #define CFGR2_PREDIV2            ((uint32_t)0x000000F0)
 #define CFGR2_PLL2MUL            ((uint32_t)0x00000F00)
 #define CFGR2_PLL3MUL            ((uint32_t)0x0000F000)
#endif /* STM32F10X_CL */ 

/* RCC Flag Mask */
#define FLAG_Mask                 ((uint8_t)0x1F)

/* CIR register byte 2 (Bits[15:8]) base address */
#define CIR_BYTE2_ADDRESS         ((uint32_t)0x40021009)

/* CIR register byte 3 (Bits[23:16]) base address */
#define CIR_BYTE3_ADDRESS         ((uint32_t)0x4002100A)

/* CFGR register byte 4 (Bits[31:24]) base address */
#define CFGR_BYTE4_ADDRESS        ((uint32_t)0x40021007)

/* BDCR register base address */
#define BDCR_ADDRESS              (PERIPH_BASE + BDCR_OFFSET)

/**
  * @}
  */ 

/** @defgroup RCC_Private_Macros
  * @{
  */ 

/**
  * @}
  */ 

/** @defgroup RCC_Private_Variables
  * @{
  */ 

static __I uint8_t APBAHBPrescTable[16] = {0, 0, 0, 0, 1, 2, 3, 4, 1, 2, 3, 4, 6, 7, 8, 9};
static __I uint8_t ADCPrescTable[4] = {2, 4, 6, 8};

#define CR1_UE_Set                ((uint16_t)0x2000)  /*!< USART Enable Mask */
#define CR1_UE_Reset              ((uint16_t)0xDFFF)  /*!< USART Disable Mask */

/**
  * @brief  Enables or disables the PLL.
  * @note   The PLL can not be disabled if it is used as system clock.
  * @param  NewState: new state of the PLL. This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
void _RCC_PLLCmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  *(__IO uint32_t *) CR_PLLON_BB = (uint32_t)NewState;
}

/**
  * @brief  Configures the PLL clock source and multiplication factor.
  * @note   This function must be used only when the PLL is disabled.
  * @param  RCC_PLLSource: specifies the PLL entry clock source.
  *   For @b STM32_Connectivity_line_devices or @b STM32_Value_line_devices, 
  *   this parameter can be one of the following values:
  *     @arg RCC_PLLSource_HSI_Div2: HSI oscillator clock divided by 2 selected as PLL clock entry
  *     @arg RCC_PLLSource_PREDIV1: PREDIV1 clock selected as PLL clock entry
  *   For @b other_STM32_devices, this parameter can be one of the following values:
  *     @arg RCC_PLLSource_HSI_Div2: HSI oscillator clock divided by 2 selected as PLL clock entry
  *     @arg RCC_PLLSource_HSE_Div1: HSE oscillator clock selected as PLL clock entry
  *     @arg RCC_PLLSource_HSE_Div2: HSE oscillator clock divided by 2 selected as PLL clock entry 
  * @param  RCC_PLLMul: specifies the PLL multiplication factor.
  *   For @b STM32_Connectivity_line_devices, this parameter can be RCC_PLLMul_x where x:{[4,9], 6_5}
  *   For @b other_STM32_devices, this parameter can be RCC_PLLMul_x where x:[2,16]  
  * @retval None
  */
void _RCC_PLLConfig(uint32_t RCC_PLLSource, uint32_t RCC_PLLMul)
{
  uint32_t tmpreg = 0;

  /* Check the parameters */
  assert_param(IS_RCC_PLL_SOURCE(RCC_PLLSource));
  assert_param(IS_RCC_PLL_MUL(RCC_PLLMul));

  tmpreg = RCC->CFGR;
  /* Clear PLLSRC, PLLXTPRE and PLLMUL[3:0] bits */
  tmpreg &= CFGR_PLL_Mask;
  /* Set the PLL configuration bits */
  tmpreg |= RCC_PLLSource | RCC_PLLMul;
  /* Store the new value */
  RCC->CFGR = tmpreg;
}

/**
  * @brief  Configures the AHB clock (HCLK).
  * @param  RCC_SYSCLK: defines the AHB clock divider. This clock is derived from 
  *   the system clock (SYSCLK).
  *   This parameter can be one of the following values:
  *     @arg RCC_SYSCLK_Div1: AHB clock = SYSCLK
  *     @arg RCC_SYSCLK_Div2: AHB clock = SYSCLK/2
  *     @arg RCC_SYSCLK_Div4: AHB clock = SYSCLK/4
  *     @arg RCC_SYSCLK_Div8: AHB clock = SYSCLK/8
  *     @arg RCC_SYSCLK_Div16: AHB clock = SYSCLK/16
  *     @arg RCC_SYSCLK_Div64: AHB clock = SYSCLK/64
  *     @arg RCC_SYSCLK_Div128: AHB clock = SYSCLK/128
  *     @arg RCC_SYSCLK_Div256: AHB clock = SYSCLK/256
  *     @arg RCC_SYSCLK_Div512: AHB clock = SYSCLK/512
  * @retval None
  */
void _RCC_HCLKConfig(uint32_t RCC_SYSCLK)
{
  uint32_t tmpreg = 0;
  /* Check the parameters */
  assert_param(IS_RCC_HCLK(RCC_SYSCLK));
  tmpreg = RCC->CFGR;
  /* Clear HPRE[3:0] bits */
  tmpreg &= CFGR_HPRE_Reset_Mask;
  /* Set HPRE[3:0] bits according to RCC_SYSCLK value */
  tmpreg |= RCC_SYSCLK;
  /* Store the new value */
  RCC->CFGR = tmpreg;
}

/**
  * @brief  Configures the Low Speed APB clock (PCLK1).
  * @param  RCC_HCLK: defines the APB1 clock divider. This clock is derived from 
  *   the AHB clock (HCLK).
  *   This parameter can be one of the following values:
  *     @arg RCC_HCLK_Div1: APB1 clock = HCLK
  *     @arg RCC_HCLK_Div2: APB1 clock = HCLK/2
  *     @arg RCC_HCLK_Div4: APB1 clock = HCLK/4
  *     @arg RCC_HCLK_Div8: APB1 clock = HCLK/8
  *     @arg RCC_HCLK_Div16: APB1 clock = HCLK/16
  * @retval None
  */
void _RCC_PCLK1Config(uint32_t RCC_HCLK)
{
  uint32_t tmpreg = 0;
  /* Check the parameters */
  assert_param(IS_RCC_PCLK(RCC_HCLK));
  tmpreg = RCC->CFGR;
  /* Clear PPRE1[2:0] bits */
  tmpreg &= CFGR_PPRE1_Reset_Mask;
  /* Set PPRE1[2:0] bits according to RCC_HCLK value */
  tmpreg |= RCC_HCLK;
  /* Store the new value */
  RCC->CFGR = tmpreg;
}

/**
  * @brief  Configures the High Speed APB clock (PCLK2).
  * @param  RCC_HCLK: defines the APB2 clock divider. This clock is derived from 
  *   the AHB clock (HCLK).
  *   This parameter can be one of the following values:
  *     @arg RCC_HCLK_Div1: APB2 clock = HCLK
  *     @arg RCC_HCLK_Div2: APB2 clock = HCLK/2
  *     @arg RCC_HCLK_Div4: APB2 clock = HCLK/4
  *     @arg RCC_HCLK_Div8: APB2 clock = HCLK/8
  *     @arg RCC_HCLK_Div16: APB2 clock = HCLK/16
  * @retval None
  */
void _RCC_PCLK2Config(uint32_t RCC_HCLK)
{
  uint32_t tmpreg = 0;
  /* Check the parameters */
  assert_param(IS_RCC_PCLK(RCC_HCLK));
  tmpreg = RCC->CFGR;
  /* Clear PPRE2[2:0] bits */
  tmpreg &= CFGR_PPRE2_Reset_Mask;
  /* Set PPRE2[2:0] bits according to RCC_HCLK value */
  tmpreg |= RCC_HCLK << 3;
  /* Store the new value */
  RCC->CFGR = tmpreg;
}

/**
  * @brief  Returns the clock source used as system clock.
  * @param  None
  * @retval The clock source used as system clock. The returned value can
  *   be one of the following:
  *     - 0x00: HSI used as system clock
  *     - 0x04: HSE used as system clock
  *     - 0x08: PLL used as system clock
  */
uint8_t _RCC_GetSYSCLKSource(void)
{
  return ((uint8_t)(RCC->CFGR & CFGR_SWS_Mask));
}

/**
  * @brief  Configures the system clock (SYSCLK).
  * @param  RCC_SYSCLKSource: specifies the clock source used as system clock.
  *   This parameter can be one of the following values:
  *     @arg RCC_SYSCLKSource_HSI: HSI selected as system clock
  *     @arg RCC_SYSCLKSource_HSE: HSE selected as system clock
  *     @arg RCC_SYSCLKSource_PLLCLK: PLL selected as system clock
  * @retval None
  */
void _RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource)
{
  uint32_t tmpreg = 0;
  /* Check the parameters */
  assert_param(IS_RCC_SYSCLK_SOURCE(RCC_SYSCLKSource));
  tmpreg = RCC->CFGR;
  /* Clear SW[1:0] bits */
  tmpreg &= CFGR_SW_Mask;
  /* Set SW[1:0] bits according to RCC_SYSCLKSource value */
  tmpreg |= RCC_SYSCLKSource;
  /* Store the new value */
  RCC->CFGR = tmpreg;
}
/**
  * @brief  Checks whether the specified RCC flag is set or not.
  * @param  RCC_FLAG: specifies the flag to check.
  *   
  *   For @b STM32_Connectivity_line_devices, this parameter can be one of the
  *   following values:
  *     @arg RCC_FLAG_HSIRDY: HSI oscillator clock ready
  *     @arg RCC_FLAG_HSERDY: HSE oscillator clock ready
  *     @arg RCC_FLAG_PLLRDY: PLL clock ready
  *     @arg RCC_FLAG_PLL2RDY: PLL2 clock ready      
  *     @arg RCC_FLAG_PLL3RDY: PLL3 clock ready                           
  *     @arg RCC_FLAG_LSERDY: LSE oscillator clock ready
  *     @arg RCC_FLAG_LSIRDY: LSI oscillator clock ready
  *     @arg RCC_FLAG_PINRST: Pin reset
  *     @arg RCC_FLAG_PORRST: POR/PDR reset
  *     @arg RCC_FLAG_SFTRST: Software reset
  *     @arg RCC_FLAG_IWDGRST: Independent Watchdog reset
  *     @arg RCC_FLAG_WWDGRST: Window Watchdog reset
  *     @arg RCC_FLAG_LPWRRST: Low Power reset
  * 
  *   For @b other_STM32_devices, this parameter can be one of the following values:        
  *     @arg RCC_FLAG_HSIRDY: HSI oscillator clock ready
  *     @arg RCC_FLAG_HSERDY: HSE oscillator clock ready
  *     @arg RCC_FLAG_PLLRDY: PLL clock ready
  *     @arg RCC_FLAG_LSERDY: LSE oscillator clock ready
  *     @arg RCC_FLAG_LSIRDY: LSI oscillator clock ready
  *     @arg RCC_FLAG_PINRST: Pin reset
  *     @arg RCC_FLAG_PORRST: POR/PDR reset
  *     @arg RCC_FLAG_SFTRST: Software reset
  *     @arg RCC_FLAG_IWDGRST: Independent Watchdog reset
  *     @arg RCC_FLAG_WWDGRST: Window Watchdog reset
  *     @arg RCC_FLAG_LPWRRST: Low Power reset
  *   
  * @retval The new state of RCC_FLAG (SET or RESET).
  */
FlagStatus _RCC_GetFlagStatus(uint8_t RCC_FLAG)
{
  uint32_t tmp = 0;
  uint32_t statusreg = 0;
  FlagStatus bitstatus = RESET;
  /* Check the parameters */
  assert_param(IS_RCC_FLAG(RCC_FLAG));

  /* Get the RCC register index */
  tmp = RCC_FLAG >> 5;
  if (tmp == 1)               /* The flag to check is in CR register */
  {
    statusreg = RCC->CR;
  }
  else if (tmp == 2)          /* The flag to check is in BDCR register */
  {
    statusreg = RCC->BDCR;
  }
  else                       /* The flag to check is in CSR register */
  {
    statusreg = RCC->CSR;
  }

  /* Get the flag position */
  tmp = RCC_FLAG & FLAG_Mask;
  if ((statusreg & ((uint32_t)1 << tmp)) != (uint32_t)RESET)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }

  /* Return the flag status */
  return bitstatus;
}

void _USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* Enable the selected USART by setting the UE bit in the CR1 register */
    USARTx->CR1 |= CR1_UE_Set;
  }
  else
  {
    /* Disable the selected USART by clearing the UE bit in the CR1 register */
    USARTx->CR1 &= CR1_UE_Reset;
  }
}

//高速情况下的延时
void _Delay_us(INT32U nus)
{		
	INT32U temp;	    	 
	//SysTick->LOAD=nus*fac_us; //时间加载	  		 
	SysTick->LOAD=nus*(H_HCLK_VALUE / 8000000);;
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
//-------------------------
void Set_Clock_Hight_Speed(void)
{
	_RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE); //设置外部时钟为HSE
	//_RCC_HCLKConfig(RCC_SYSCLK_Div1);   //设置AHB时钟=AHB_FREQ MHz
	_RCC_PCLK1Config(H_PCLK1_DIV);   //设置APB1时钟=36 MHz(APB1时钟最大值)
	_RCC_PCLK2Config(H_PCLK2_DIV);   //设置APB2时钟=72 MHz
	_RCC_PLLCmd(DISABLE); //关闭PLL
	_RCC_PLLConfig(RCC_PLLSource_HSE_Div1, H_HCLK_MUL); //PLL必须在其激活前完成配置（设置PLL时钟源及倍频系数）
	_RCC_PLLCmd(ENABLE);
	// Wait till PLL is ready 
	while(_RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
	{
	}
	// Select PLL as system clock source 
	_RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	// Wait till PLL is used as system clock source 
	while(_RCC_GetSYSCLKSource() != 0x08)
	{
	}
}

void Set_Clock_Normal_Speed(void)
{
	_RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE); //设置外部时钟为HSE
	//_RCC_HCLKConfig(RCC_SYSCLK_Div1);   //设置AHB时钟=AHB_FREQ MHz
	_RCC_PCLK1Config(PCLK1_DIV);   //设置APB1时钟=36 MHz(APB1时钟最大值)
	_RCC_PCLK2Config(PCLK2_DIV);   //设置APB2时钟=72 MHz
	_RCC_PLLCmd(DISABLE); //关闭PLL
	_RCC_PLLConfig(RCC_PLLSource_HSE_Div1, HCLK_MUL); //PLL必须在其激活前完成配置（设置PLL时钟源及倍频系数）
	_RCC_PLLCmd(ENABLE);
	// Wait till PLL is ready 
	while(_RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
	{
	}
	// Select PLL as system clock source 
	_RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	// Wait till PLL is used as system clock source 
	while(_RCC_GetSYSCLKSource() != 0x08)
	{
	}

}

void Set_OE_Duty_Polarity(INT8U Duty, INT8U Polarity)
{
  if(Duty > 100)
  {
    Duty = 100;
    ASSERT_FAILED();
  }

  if(Polarity EQ 0)
    TIM3->CCR3 = TIM3->ARR * Duty / 100;
  else
    TIM3->CCR3 = TIM3->ARR * (100 - Duty) / 100;
}
//获取第Rows行第Index个字节的移动数据对应的在屏幕数据中的坐标
//Block表示扫描块的块号
//Rows表示行号，该行号对应接口中的ABCD的行号,几分之几扫?
//BRow表示该块号内的第几条扫描线
//Cols表示宽度，595个数,实际为屏幕宽度/8
//Index表示该扫描线中的第Index个字节
//*pX和*pY返回坐标
//Direct表示数据进入方向,Rows_Fold表示行折叠数，Cols_Fold表示列折数
void Get_Shift_Data(INT16U Block, INT16U Rows, INT16U BRow, INT16U Cols, INT16U Index,\
                          INT8U Direct, INT8U Rows_Fold, INT8U Cols_Fold, INT8U *pDst)
{
  INT16U Fold_Size,X,Y;
  INT8U Screen_Color_Num, *p;
  INT8U Off;
  //INT16U Cols;
  
  X = Y = 0; 

  Rows_Fold ++;

  if(Direct EQ 0x00 || Direct EQ 0x01) //从左边进入，则索引应该转换
    Index = Cols - 1 - Index; //Index从0开始计数
		  
  if(Rows_Fold EQ 0 || Cols_Fold EQ 0) //没有打折的现象
  {
      X = Index;
	   //每个Block对应的屏幕上的行数是 Rows*Rows_Fold
	   //BRow表示第几条扫描线,每条扫描线对应到屏幕上的有Rows_Fold行
	  Y = Block * Rows* Rows_Fold + BRow * Rows_Fold;// + (Index % Fold_Size) / Cols_Fold;
  }
  else
  { 
	  Fold_Size = Rows_Fold*Cols_Fold;  
	  if(Direct EQ 0x00 || Direct EQ 0x02)//左上进入、右上进入
	  {
	    X = Index / Fold_Size * Cols_Fold + (Index % Fold_Size) % Cols_Fold;
	    //每个Block对应的屏幕上的行数是 Rows*Rows_Fold
	    //BRow表示第几条扫描线,每条扫描线对应到屏幕上的有Rows_Fold行
	    Y = Block * Rows* Rows_Fold + BRow * Rows_Fold + (Index % Fold_Size) / Cols_Fold;
	  }
	  else if(Direct EQ 0x01 || Direct EQ 0x03) //左下进入、右下进入
	  {
	    X = Index / Fold_Size * Cols_Fold + (Index % Fold_Size) % Cols_Fold;
	    //每个Block对应的屏幕上的行数是 Rows*Rows_Fold
	    //BRow表示第几条扫描线,每条扫描线对应到屏幕上的有Rows_Fold行
	    Y = Block * Rows* Rows_Fold + (BRow + 1) * Rows_Fold - (Index % Fold_Size) / Cols_Fold - 1;//Y = (Block  + 1)*  Rows * Rows_Fold - BRow * Rows_Fold - (Index % Rows_Fold);//(Index % Fold_Size) / Cols_Fold;    
	  }
	  else
	    ASSERT_FAILED();
   }
  Screen_Color_Num = Get_Screen_Color_Num();  

  p = Show_Data.Color_Data + (Y*Cols + X)*Screen_Color_Num;
  
  Off = 0;
  
  //获取三色数据
  //红
  if(GET_BIT(Screen_Para.Base_Para.Color, 0))
    *pDst = 0xFF - *(p + Off++);//Show_Data.Color_Data[Data_Index];
  else 
    *pDst = 0xFF;
  
  //绿
  if(GET_BIT(Screen_Para.Base_Para.Color, 1))
    *(pDst + 1) = 0xFF - *(p + Off ++);//Show_Data.Color_Data[Data_Index];
  else 
    *(pDst + 1) = 0xFF;
  
  //蓝
  if(GET_BIT(Screen_Para.Base_Para.Color, 2))
    *(pDst + 2) = 0xFF - *(p + Off ++);//Show_Data.Color_Data[Data_Index];
  else 
    *(pDst + 2) = 0xFF;  
  //memcpy(pDst, Show_Data.Color_Data + Data_Index*Screen_Color_Num, Screen_Color_Num);
  return ;//ReIndex;
}

/*
INT8U Get_Next_Byte_Posi(INT16U X, INT16U Y, INT16U *pX, INT16U *pY,\
                         INT8U Direct, INT8U Rows_Fold, INT8U Cols_Fold)
{
  if(Direct EQ 0x00)//左上进入
  {
    if(X % Cols_Fold EQ 0 && Y % Rows_Fold EQ 0)
    {
      *pX = X - 1;
      *pY = Y + Rows_Fold - 1;
    }
    else if(X % Cols_Fold EQ 0)
    {
      *pX = X + Cols_Fold - 1;
      *pY = Y - 1;
    }
    else
    {
       *pX = X - 1; 
       *pY = Y;
    }
  }
  else if(Direct EQ 0x01) //左下进入
  {
    if(X % Cols_Fold EQ 0 && Y % Rows_Fold EQ (Rows_Fold - 1))
    {
      *pX = X - 1;
      *pY = Y - (Rows_Fold - 1);
    }
    else if(X % Cols_Fold EQ 0)
    {
      *pX = X + (Cols_Fold - 1);
      *pY = Y + 1;
    }
    else
    {
       *pX = X - 1; 
       *pY = Y;
    }     
  }  
  else if(Direct EQ 0x02) //右上进入
  {
    if(X % Cols_Fold EQ (Cols_Fold - 1) && Y % Rows_Fold EQ 0)
    {
      *pX = X + 1;
      *pY = Y + Rows_Fold - 1;
    }
    else if(X % Cols_Fold EQ (Cols_Fold - 1))
    {
      *pX = X - (Cols_Fold - 1);
      *pY = Y - 1;
    }
    else
    {
       *pX = X + 1; 
       *pY = Y;
    }    
  }
  else if(Direct EQ 0x03) //右下进入
  {
    if(X % Cols_Fold EQ (Cols_Fold - 1) && Y % Rows_Fold EQ (Rows_Fold - 1))
    {
      *pX = X + 1;
      *pY = Y - (Rows_Fold - 1);
    }
    else if(X % Cols_Fold EQ (Cols_Fold - 1))
    {
      *pX = X - (Cols_Fold - 1);
      *pY = Y + 1;
    }
    else
    {
       *pX = X + 1; 
       *pY = Y;
    }     
  }
  else
  {
    ASSERT_FAILED();
    *pX = 0;
    *pY = 0;
  }
  
  return 1;
}
*/
   
 //设置块行号
void Set_Block_Row(INT8U Row)
{
  //Row = Screen_Status.Scan_Row;
  if(Screen_Para.Scan_Para.Rows EQ 0)
  {
    Screen_Para.Scan_Para.Rows = 16;
	SET_SUM(Screen_Para);
  }

  Row = (INT8U)(((INT8S)Screen_Status.Scan_Row + Screen_Para.Scan_Para.Line_Order) % Screen_Para.Scan_Para.Rows);
    
  SET_A((Row & 0x01));
  SET_B(((Row & 0x02) >> 1));
  SET_C(((Row & 0x04) >> 2));
  SET_D(((Row & 0x08) >> 3));
}

#pragma pack(1)
/*  
typedef struct {
    int b0: 1;
    int b1: 1;
    int b2: 1;
	int b3: 1;
	int b4: 1;
	int b5: 1;
	int b6: 1;
	int b7: 1;
}BB __attribute__((bitband));
*/
INT8U Scan_Data[MAX_SCAN_BLOCK_NUM][3] __attribute__((at(SCAN_DATA_ADDR)));
#pragma pack()
                       
//调用该函数每次扫描一行
//每中断一次调用一次该函数
void LED_Scan_One_Row(void)
{
  INT16U i,j,Cols;
  INT16U Blocks;
  INT8U Color_Num;
  //INT32U Row_Freq;
  
  if(Screen_Status.Open_Flag EQ 0 || Screen_Status.Com_Time > 0) //关机状态，不显示,或当前在通信状态也不显示
    return;
 

  //Set_Clock_Hight_Speed(); //设置为高速运行模式
  /*
	_RCC_SYSCLKConfig(RCC_SYSCLKSource_HSE); //设置外部时钟为HSE
	//_RCC_HCLKConfig(RCC_SYSCLK_Div1);   //设置AHB时钟=AHB_FREQ MHz
	_RCC_PCLK1Config(H_PCLK1_DIV);   //设置APB1时钟=36 MHz(APB1时钟最大值)
	_RCC_PCLK2Config(H_PCLK2_DIV);   //设置APB2时钟=72 MHz
	_RCC_PLLCmd(DISABLE); //关闭PLL
	_RCC_PLLConfig(RCC_PLLSource_HSE_Div1, H_HCLK_MUL); //PLL必须在其激活前完成配置（设置PLL时钟源及倍频系数）
	_RCC_PLLCmd(ENABLE);
	
	// Wait till PLL is ready 
	while(_RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET)
	{
	}
	// Select PLL as system clock source 
	_RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	// Wait till PLL is used as system clock source 
	while(_RCC_GetSYSCLKSource() != 0x08)
	{
	}
	 */
  if(Screen_Para.Scan_Para.Rows EQ 0)
  {
	Screen_Para.Scan_Para.Rows = 16;
	SET_SUM(Screen_Para);
  }

  Color_Num = Get_Screen_Color_Num();
  //Block数可以理解为单元板纵向的个数
  Blocks = Screen_Para.Base_Para.Height / (Screen_Para.Scan_Para.Rows * (Screen_Para.Scan_Para.Rows_Fold + 1)); //1.2.4.8.16扫？
 
  if(Blocks > MAX_SCAN_BLOCK_NUM)
	 Blocks = MAX_SCAN_BLOCK_NUM;

  Cols = Screen_Para.Base_Para.Width / 8;
  //对每个Blocks进行扫描
  //每一条扫描线需要Screen_Para.Base_Para.Width / 8 * Screen_Para.Scan_Para.Rows_Fold个字节
  for(i = 0; i < Cols * (Screen_Para.Scan_Para.Rows_Fold + 1); i ++)
  {
    //对每个Block的每条扫描线同时输出一个字节
    for(j = 0; j < Blocks; j++)
    {
    //获取该扫描线上的所有字节并输出
      Get_Shift_Data(j, \
              Screen_Para.Scan_Para.Rows, \
              Screen_Status.Scan_Row,\
              Cols, \
              i, \
              Screen_Para.Scan_Para.Direct, \
              Screen_Para.Scan_Para.Rows_Fold, \
              Screen_Para.Scan_Para.Cols_Fold,\
              /*Screen_Status.*/Scan_Data[j]);
    }
    
    //对所有的block输出一个字节
    //如果是从左向右，应该先输出高位再输出低位
    if(Screen_Para.Scan_Para.Direct EQ 0x00 || Screen_Para.Scan_Para.Direct EQ 0x01)
    {/*
      for(j = 0; j < 8 ; j++)
      {
	    m = 7 - j;	    

        SET_CLK(0);

        for(k = 0; k < Blocks; k++)
        {
		 SET_SHIFT_BIT(k, Scan_Data[k], m); 
		}

		SET_CLK(1);
      }*/
	 if(Color_Num EQ 1)
	 {  
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,7); 
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,6);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,5);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,4);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,3);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,2);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,1); 
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,0);
	  }
	  else if(Color_Num EQ 2)
	  {
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,7); 
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,6);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,5);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,4);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,3);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,2);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,1); 
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,0);
	  }	
	  else
	  {
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,7); 
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,6);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,5);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,4);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,3);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,2);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,1); 
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,0);	  
	  }   
     }
     else //如果从右往左输出应该先输出低位
     {/*
       for(j = 0; j < 8 ; j++)
       {
		 SET_CLK(0);
        
         for(k = 0; k < Blocks; k++)
         {
	 	   SET_SHIFT_BIT(k, Scan_Data[k], j);
		 }
        
		 SET_CLK(1);
       }
	   	*/
	 
	 if(Color_Num EQ 1)
	 {  
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,0); 
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,1);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,2);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,3);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,4);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,5);
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,6); 
	   SET_SHIFT_BIT_1(Blocks, Scan_Data,7);
	  }
	  else if(Color_Num EQ 2)
	  {
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,0); 
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,1);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,2);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,3);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,4);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,5);
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,6); 
	   SET_SHIFT_BIT_2(Blocks, Scan_Data,7);
	  }
	  else
	  {
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,0); 
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,1);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,2);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,3);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,4);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,5);
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,6); 
	   SET_SHIFT_BIT_3(Blocks, Scan_Data,7);
	  }
	       
     }
	}
	 
	//关闭OE使能
	Set_OE_Duty_Polarity(0, Screen_Para.Scan_Para.OE_Polarity);

	if(Screen_Para.Scan_Para.Line_Hide > 0)
	  _Delay_us(Screen_Para.Scan_Para.Line_Hide*10); //行消隐时间
    _Delay_us(20);
    SET_LAT(0); //锁存信号输出
    SET_LAT(1); //锁存信号输出
    
    Set_Block_Row(Screen_Status.Scan_Row);
    Screen_Status.Scan_Row++;
    if(Screen_Status.Scan_Row >= Screen_Para.Scan_Para.Rows)
      Screen_Status.Scan_Row = 0;
	
	//重新打开OE
	Set_OE_Duty_Polarity(100, Screen_Para.Scan_Para.OE_Polarity);
	//_USART_Cmd(USART1, DISABLE);
    //Set_Clock_Normal_Speed();
	//_USART_Cmd(USART1, ENABLE); 
	//USART_Clar
   
}
