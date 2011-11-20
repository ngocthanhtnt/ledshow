/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.4.0
  * @date    10/15/2010
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "includes.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  static int FaultFlag = 0;
  /* Go to infinite loop when Hard Fault exception occurs */
  while (FaultFlag EQ 0)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  //volatile INT32U i = 0;

  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  //GPIO_SetBits(GPIOB,GPIO_Pin_9); //测试输出
  Show_Timer_Proc();
  //Delay_us(5);

  //GPIO_ResetBits(GPIOB,GPIO_Pin_9); //测试输出
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @brief  This function handles TIM2 global interrupt request.
  * @param  None
  * @retval None
  */
extern void LED_Scan_One_Row(void);
void TIM2_IRQHandler(void)   //TIM2中断
{
//#if RMDK_SIM_EN
    //GPIO_SetBits(GPIOB,GPIO_Pin_9); //测试输出
//#endif

//#if RMDK_SIM_EN
	//GPIO_ResetBits(GPIOB,GPIO_Pin_9);//测试输出
//#endif
}

/**
  * @brief  This function handles TIM4 global interrupt request.
  * @param  None
  * @retval None
  */
extern void Show_Timer_Proc(void);

void TIM3_IRQHandler(void)   //TIM3中断--100ms周期
{
//#if RMDK_SIM_EN
    //GPIO_SetBits(GPIOB,GPIO_Pin_9); //测试输出
//#endif 

	TIM_Cmd(TIM3, DISABLE);
	
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源 
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //清除TIMx的中断待处理位:TIM 中断源 
		LED_Scan_One_Row();
	}
	
	TIM_Cmd(TIM3, ENABLE);
	/* 
  TIM_Cmd(TIM3, DISABLE);

    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源 
	{
	 TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //清除TIMx的中断待处理位:TIM 中断源 
     //Delay_ms(5);
	 //Show_Timer_Proc();
	 //GPIO_SetBits(GPIOB,GPIO_Pin_9); //测试输出
	 Pub_Timer_Proc();//Effect_Proc();
	 //GPIO_ResetBits(GPIOB,GPIO_Pin_9);//测试输出
	}

  TIM_Cmd(TIM3, ENABLE);
  */
//#if RMDK_SIM_EN
	//GPIO_ResetBits(GPIOB,GPIO_Pin_9);//测试输出
//#endif  

}

void TIM4_IRQHandler(void)   //TIM3中断--100ms周期
{
//#if RMDK_SIM_EN
    //GPIO_SetBits(GPIOB,GPIO_Pin_9); //测试输出
//#endif 

	//TIM_Cmd(TIM4, DISABLE);
	
	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源 
	{
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update  );  //清除TIMx的中断待处理位:TIM 中断源 
		Pub_Timer_Proc();
	}
	
	//TIM_Cmd(TIM4, ENABLE);
	/* 
  TIM_Cmd(TIM3, DISABLE);

    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源 
	{
	 TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //清除TIMx的中断待处理位:TIM 中断源 
     //Delay_ms(5);
	 //Show_Timer_Proc();
	 //GPIO_SetBits(GPIOB,GPIO_Pin_9); //测试输出
	 Pub_Timer_Proc();//Effect_Proc();
	 //GPIO_ResetBits(GPIOB,GPIO_Pin_9);//测试输出
	}

  TIM_Cmd(TIM3, ENABLE);
  */
//#if RMDK_SIM_EN
	//GPIO_ResetBits(GPIOB,GPIO_Pin_9);//测试输出
//#endif  

}
/*
//extern void Border_Show_Proc(void);
void TIM1_UP_IRQHandler(void)   //TIM1中断
{
  TIM_Cmd(TIM1, DISABLE);

    if (TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源 
	{
	 TIM_ClearITPendingBit(TIM1, TIM_IT_Update  );  //清除TIMx的中断待处理位:TIM 中断源 
	 Pub_Timer_Proc();
	}

  TIM_Cmd(TIM1, ENABLE);

}
*/

/**
  * @brief  This function handles TIM3 global interrupt request.
  * @param  None
  * @retval None
  */
extern void Com_Rcv_Byte(u8 Ch, u8 Byte);	 
//注意,读取USARTx->SR能避免莫名其妙的错误 
void USART1_IRQHandler(void)	//串口1中断服务程序
{
   u8 Res;
   //STM_EVAL_LEDToggle(LED2);
    if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
	Res =USART_ReceiveData(USART1);//(USART1->DR);	//读取接收到的数据
  	Com_Rcv_Byte(CH_COM, Res);	 
	}
}

extern void Shell_Rcv_Byte(u8 Byte);
void USART2_IRQHandler(void)	//串口2中断服务程序
{
   u8 Res;
   //STM_EVAL_LEDToggle(LED2);
   if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
	Res =USART_ReceiveData(USART2);//(USART1->DR);	//读取接收到的数据
  	Shell_Rcv_Byte(Res);	 
	}
}

//串口中断3用于接收环境变量数据
void USART3_IRQHandler(void)	//串口3中断服务程序
{
   u8 Res;
   //STM_EVAL_LEDToggle(LED2);
   if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
	{
	Res =USART_ReceiveData(USART3);//(USART1->DR);	//读取接收到的数据
  
	 Env_Rcv_Byte(CH_ENV, Res); //接收环境变量
     //while (!(USART3->SR & USART_FLAG_TXE));
     //USART3->DR = (Res & (uint16_t)0x01FF);
    //Com_Rcv_Byte(CH_GPRS, Res);
	 
	}
}
/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
