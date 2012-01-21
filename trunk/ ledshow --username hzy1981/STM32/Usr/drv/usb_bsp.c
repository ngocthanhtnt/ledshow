/**
  ******************************************************************************
  * @file    usb_bsp.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    22/07/2011
  * @brief   This file implements the board support package for the USB host library
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "Includes.h"
#include "usb_bsp.h"
//#include "stm3210c_eval_lcd.h"
//#include "stm32_eval.h"

/** @addtogroup USBH_USER
  * @{
  */

/** @defgroup IAP_OVER_USB_BSP
  * @brief
  * @{
  */

/* External variables --------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
ErrorStatus HSEStartUpStatus;
#ifdef USE_ACCURATE_TIME
__IO uint32_t BSP_delay = 0;
#endif
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
#ifdef USE_ACCURATE_TIME
static void BSP_SetTime(uint8_t Unit);
static void BSP_Delay(uint32_t nTime, uint8_t Unit);
#endif


/**
  * @brief  BSP_Init
  *         board user initializations
  * @param  None
  * @retval None
  */
void BSP_Init(void)
{
#if 0
  /* Configure PB9 pin: User Key pin */
  STM_EVAL_PBInit(Button_KEY, Mode_GPIO);

  /* Initialize the STM3210C-EVAL's LCD */
  STM3210C_LCD_Init();

  /* Display message on STM3210X-EVAL LCD */
  /* Clear the LCD */
  LCD_Clear(Black);

  /* Set the LCD Back Color */
  LCD_SetBackColor(Black);

  /* Set the LCD Text Color */
  LCD_SetTextColor(White);
#endif
}


/**
  * @brief  USB_OTG_BSP_Init
  *         Initilizes BSP configurations
  * @param  None
  * @retval None
  */
void USB_OTG_BSP_Init(void)
{
#ifdef STM32F10X_CL
  //GPIO_InitTypeDef GPIO_InitStructure;
  //EXTI_InitTypeDef EXTI_InitStructure;

  /* Select USBCLK source */
  RCC_OTGFSCLKConfig(RCC_OTGFSCLKSource_PLLVCO_Div3);

  /* Enable the USB clock */
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_OTG_FS, ENABLE) ;

#ifdef SOF_OUTPUT_ENABLED
  /* To enable SOF pulse out on PAD */

  RCC_APB2PeriphClockCmd(HOST_SOF_OUTPUT_RCC, ENABLE);

  /* Configure SOF Pin */
  GPIO_InitStructure.GPIO_Pin = HOST_SOF_SIGNAL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(HOST_SOF_PORT, &GPIO_InitStructure);
#endif

  /* Configure pin for overcurrent detection */

#ifdef   OVERCURRENT_DET
  RCC_APB2PeriphClockCmd(HOST_OVRCURR_PORT_RCC, ENABLE);

  /* Configure SOF Pin */
  GPIO_InitStructure.GPIO_Pin = HOST_OVRCURR_LINE;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
  GPIO_Init(HOST_OVRCURR_PORT, &GPIO_InitStructure);

  /* Connect Button EXTI Line to Button GPIO Pin */
  GPIO_EXTILineConfig(HOST_OVRCURR_PORT_SOURCE, HOST_OVRCURR_PIN_SOURCE);

  /* Configure Button EXTI line */
  EXTI_InitStructure.EXTI_Line = HOST_OVRCURR_EXTI_LINE;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

#endif
#endif
}

/**
  * @brief  USB_OTG_BSP_EnableInterrupt
  *         Configures USB Global interrupt
  * @param  None
  * @retval None
  */
void USB_OTG_BSP_EnableInterrupt(void)
{
#ifdef STM32F10X_CL
  NVIC_InitTypeDef NVIC_InitStructure;
  /* Enable USB Interrupt */
  //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

  NVIC_InitStructure.NVIC_IRQChannel = OTG_FS_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
#if 0
  /* Enable the Overcurrent Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = HOST_OVRCURR_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);
#endif
#endif
}

/**
  * @brief  BSP_Drive_VBUS
  *         Drives the Vbus signal through IO
  * @param  state : VBUS states
  * @retval None
  */
void USB_OTG_BSP_DriveVBUS(uint8_t state)
{
  /*
  On-chip 5 V VBUS generation is not supported. For this reason, a charge pump 
  or, if 5 V are available on the application board, a basic power switch, must 
  be added externally to drive the 5 V VBUS line. The external charge pump can 
  be driven by any GPIO output. When the application decides to power on VBUS 
  using the chosen GPIO, it must also set the port power bit in the host port 
  control and status register (PPWR bit in OTG_FS_HPRT).

  Bit 12 PPWR: Port power
  The application uses this field to control power to this port, and the core 
  clears this bit on an overcurrent condition.
  */
#if 0
  if (0 == state)
  {
    /* DISABLE is needed on output of the Power Switch */
    GPIO_SetBits(HOST_POWERSW_PORT, HOST_POWERSW_VBUS);
  }
  else
  {
    /*ENABLE the Power Switch by driving the Enable LOW */
    GPIO_ResetBits(HOST_POWERSW_PORT, HOST_POWERSW_VBUS);
  }
#endif
}

/**
  * @brief  USB_OTG_BSP_ConfigVBUS
  *         Configures the IO for the Vbus and OverCurrent
  * @param  None
  * @retval None
  */
void  USB_OTG_BSP_ConfigVBUS(void)
{
#if 0
  GPIO_InitTypeDef GPIO_InitStructure;


  RCC_APB2PeriphClockCmd(HOST_POWERSW_PORT_RCC, ENABLE);


  /* Configure Power Switch Vbus Pin */
  GPIO_InitStructure.GPIO_Pin = HOST_POWERSW_VBUS;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(HOST_POWERSW_PORT, &GPIO_InitStructure);

  /* By Default, DISABLE is needed on output of the Power Switch */
  GPIO_SetBits(HOST_POWERSW_PORT, HOST_POWERSW_VBUS);
#endif
  USB_OTG_BSP_mDelay(200);   /* Delay is need for stabilising the Vbus Low
      in Reset Condition, when Vbus=1 and Reset-button is pressed by user */

}

/**
  * @brief  USB_OTG_BSP_TimeInit
  *         Initializes delay unit using Timer2
  * @param  None
  * @retval None
  */
void USB_OTG_BSP_TimeInit (void)
{
#ifdef USE_ACCURATE_TIME
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Set the Vector Table base address at 0x08000000 */
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x00);

  /* Configure the Priority Group to 2 bits */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

  /* Enable the TIM2 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
#endif
}

/**
  * @brief  USB_OTG_BSP_uDelay
  *         This function provides delay time in micro sec
  * @param  usec : Value of delay required in micro sec
  * @retval None
  */
void USB_OTG_BSP_uDelay (const uint32_t usec)
{

#ifdef USE_ACCURATE_TIME
  BSP_Delay(usec, TIM_USEC_DELAY);
#else
  __IO uint32_t count = 0;
  const uint32_t utime = (120 * usec / 7);
  do
  {
    if ( ++count > utime )
    {
      return ;
    }
  }
  while (1);
#endif

}

/**
  * @brief  USB_OTG_BSP_mDelay
  *          This function provides delay time in milli sec
  * @param  msec : Value of delay required in milli sec
  * @retval None
  */
void USB_OTG_BSP_mDelay (const uint32_t msec)
{
#ifdef USE_ACCURATE_TIME
  BSP_Delay(msec, TIM_MSEC_DELAY);
#else
  USB_OTG_BSP_uDelay(msec * 1000);
#endif

}

/**
  * @brief  USB_OTG_BSP_TimerIRQ
  *         Time base IRQ
  * @param  None
  * @retval None
  */
void USB_OTG_BSP_TimerIRQ (void)
{
#ifdef USE_ACCURATE_TIME
  if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
  {
    TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    if (BSP_delay > 0x00)
    {
      BSP_delay--;
    }
    else
    {
      TIM_Cmd(TIM2, DISABLE);
    }
  }
#endif
}

#ifdef USE_ACCURATE_TIME

/**
  * @brief  BSP_Delay
  *         Delay routine based on TIM2
  * @param  nTime : Delay Time
  * @param  unit : Delay Time unit : mili sec / micro sec
  * @retval None
  */
static void BSP_Delay(uint32_t nTime, uint8_t unit)
{

  BSP_delay = nTime;
  BSP_SetTime(unit);
  while (BSP_delay != 0);
  TIM_Cmd(TIM2, DISABLE);
}

/**
  * @brief  BSP_SetTime
  *         Configures TIM2 for delay routine based on TIM2
  * @param  unit : msec /usec
  * @retval None
  */
static void BSP_SetTime(uint8_t unit)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

  TIM_Cmd(TIM2, DISABLE);
  TIM_ITConfig(TIM2, TIM_IT_Update, DISABLE);


  if (unit == TIM_USEC_DELAY)
  {
    TIM_TimeBaseStructure.TIM_Period = 11;
  }
  else if (unit == TIM_MSEC_DELAY)
  {
    TIM_TimeBaseStructure.TIM_Period = 11999;
  }
  TIM_TimeBaseStructure.TIM_Prescaler = 5;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
  TIM_ClearITPendingBit(TIM2, TIM_IT_Update);

  TIM_ARRPreloadConfig(TIM2, ENABLE);

  /* TIM IT enable */
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

  /* TIM2 enable counter */
  TIM_Cmd(TIM2, ENABLE);
}

#endif

/**
* @}
*/

/**
* @}
*/

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
