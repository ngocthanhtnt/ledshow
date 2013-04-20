/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : stm32f10x_it.c
* Author             : MCD Application Team
* Date First Issued  : 02/05/2007
* Description        : Main Interrupt Service Routines.
*                      This file can be used to describe all the exceptions 
*                      subroutines that may occur within user application.
*                      When an interrupt happens, the software will branch 
*                      automatically to the corresponding routine.
*                      The following routines are all empty, user can write code 
*                      for exceptions handlers and peripherals IRQ interrupts.
********************************************************************************
* History:
* 05/21/2007: V0.3
* 04/02/2007: V0.2
* 02/05/2007: V0.1
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include <stdio.h>

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/  
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : NMIException
* Description    : This function handles NMI exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NMIException(void)
{
}

/*******************************************************************************
* Function Name  : HardFaultException
* Description    : This function handles Hard Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void HardFaultException(void)
{
	printf("Hard Error!\n");
	while(1);
}

/*******************************************************************************
* Function Name  : MemManageException
* Description    : This function handles Memory Manage exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void MemManageException(void)
{
}

/*******************************************************************************
* Function Name  : BusFaultException
* Description    : This function handles Bus Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void BusFaultException(void)
{
}

/*******************************************************************************
* Function Name  : UsageFaultException
* Description    : This function handles Usage Fault exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void UsageFaultException(void)
{
}

/*******************************************************************************
* Function Name  : DebugMonitor
* Description    : This function handles Debug Monitor exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DebugMonitor(void)
{
}

/*******************************************************************************
* Function Name  : SVCHandler
* Description    : This function handles SVCall exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SVCHandler(void)
{
}

/*******************************************************************************
* Function Name  : PendSVC
* Description    : This function handles PendSVC exception.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void PendSVC(void)
{
}

/*******************************************************************************
* Function Name  : SysTickHandler
* Description    : This function handles SysTick Handler.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SysTickHandler(void)
{
}

/*******************************************************************************
* Function Name  : WWDG_IRQHandler
* Description    : This function handles WWDG interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void WWDG_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : PVD_IRQHandler
* Description    : This function handles PVD interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void PVD_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TAMPER_IRQHandler
* Description    : This function handles Tamper interrupt request. 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TAMPER_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : RTC_IRQHandler
* Description    : This function handles RTC global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RTC_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : FLASH_IRQHandler
* Description    : This function handles Flash interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void FLASH_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : RCC_IRQHandler
* Description    : This function handles RCC interrupt request. 
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RCC_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI0_IRQHandler
* Description    : This function handles External interrupt Line 0 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI0_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI1_IRQHandler
* Description    : This function handles External interrupt Line 1 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI2_IRQHandler
* Description    : This function handles External interrupt Line 2 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI3_IRQHandler
* Description    : This function handles External interrupt Line 3 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI4_IRQHandler
* Description    : This function handles External interrupt Line 4 request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void EXTI4_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMAChannel1_IRQHandler
* Description    : This function handles DMA Stream 1 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMAChannel1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMAChannel2_IRQHandler
* Description    : This function handles DMA Stream 2 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMAChannel2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMAChannel3_IRQHandler
* Description    : This function handles DMA Stream 3 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMAChannel3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMAChannel4_IRQHandler
* Description    : This function handles DMA Stream 4 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMAChannel4_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMAChannel5_IRQHandler
* Description    : This function handles DMA Stream 5 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMAChannel5_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMAChannel6_IRQHandler
* Description    : This function handles DMA Stream 6 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMAChannel6_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : DMAChannel7_IRQHandler
* Description    : This function handles DMA Stream 7 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void DMAChannel7_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : ADC_IRQHandler
* Description    : This function handles ADC global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void ADC_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USB_HP_CAN_TX_IRQHandler
* Description    : This function handles USB High Priority or CAN TX interrupts 
*                  requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USB_HP_CAN_TX_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USB_LP_CAN_RX0_IRQHandler
* Description    : This function handles USB Low Priority or CAN RX0 interrupts 
*                  requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USB_LP_CAN_RX0_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : CAN_RX1_IRQHandler
* Description    : This function handles CAN RX1 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void CAN_RX1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : CAN_SCE_IRQHandler
* Description    : This function handles CAN SCE interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void CAN_SCE_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI9_5_IRQHandler
* Description    : This function handles External lines 9 to 5 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/


/*******************************************************************************
* Function Name  : TIM1_BRK_IRQHandler
* Description    : This function handles TIM1 Break interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM1_BRK_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM1_UP_IRQHandler
* Description    : This function handles TIM1 overflow and update interrupt 
*                  request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM1_UP_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM1_TRG_COM_IRQHandler
* Description    : This function handles TIM1 Trigger and Commutation interrupts 
*                  requests.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM1_TRG_COM_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM1_CC_IRQHandler
* Description    : This function handles TIM1 capture compare interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM1_CC_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM2_IRQHandler
* Description    : This function handles TIM2 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void timer2_int(void);
void TIM2_IRQHandler(void)
{
	timer2_int();
}

/*******************************************************************************
* Function Name  : TIM3_IRQHandler
* Description    : This function handles TIM3 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : TIM4_IRQHandler
* Description    : This function handles TIM4 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM4_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : I2C1_EV_IRQHandler
* Description    : This function handles I2C1 Event interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void I2C1_EV_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : I2C1_ER_IRQHandler
* Description    : This function handles I2C1 Error interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void I2C1_ER_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : I2C2_EV_IRQHandler
* Description    : This function handles I2C2 Event interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void I2C2_EV_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : I2C2_ER_IRQHandler
* Description    : This function handles I2C2 Error interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void I2C2_ER_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : SPI1_IRQHandler
* Description    : This function handles SPI1 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : SPI2_IRQHandler
* Description    : This function handles SPI2 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USART1_IRQHandler
* Description    : This function handles USART1 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART1_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USART2_IRQHandler
* Description    : This function handles USART2 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART2_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USART3_IRQHandler
* Description    : This function handles USART3 global interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USART3_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : EXTI15_10_IRQHandler
* Description    : This function handles External lines 15 to 10 interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/


/*******************************************************************************
* Function Name  : RTCAlarm_IRQHandler
* Description    : This function handles RTC Alarm interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RTCAlarm_IRQHandler(void)
{
}

/*******************************************************************************
* Function Name  : USBWakeUp_IRQHandler
* Description    : This function handles USB WakeUp interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void USBWakeUp_IRQHandler(void)
{
}

//add some irq handle 
/*******************************************************************************
* Function Name  : TIM8_BRK_IRQHander
* Description    : This function handles timer8  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM8_BRK_IRQHander(void)
{

} 
/*******************************************************************************
* Function Name  : TIM8_UP_IRQHander
* Description    : This function handles timer8  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM8_UP_IRQHander(void)
{


} 
/*******************************************************************************
* Function Name  : TIM8_TRG_COM_IRQHander
* Description    : This function handles timer8  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void TIM8_TRG_COM_IRQHander(void)
{

}
/*******************************************************************************
* Function Name  : TIM8_CC_IRQHander
* Description    : This function handles timer8  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/      
void TIM8_CC_IRQHander(void)
{

}  
/*******************************************************************************
* Function Name  : ADC3_IRQHander
* Description    : This function handles adc3  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/               
void ADC3_IRQHander(void)
{

} 
/*******************************************************************************
* Function Name  : FSMC_IRQHander
* Description    : This function handles FSMC  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/                            
void FSMC_IRQHander(void)
{
}  

/*******************************************************************************
* Function Name  : SDIO_IRQHander
* Description    : This function handles SDIO  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void stm32_irq(void);
void SDIO_IRQHander(void)
{ 
	stm32_irq();
}
 /*******************************************************************************
* Function Name  : TIM5_IRQHander
* Description    : This function handles TIM5  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/             
void TIM5_IRQHander(void)
{

}
 /*******************************************************************************
* Function Name  : SPI3_IRQHander
* Description    : This function handles SPI3  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/                           
void SPI3_IRQHander(void)
{
} 
 /*******************************************************************************
* Function Name  : UART4_IRQHander
* Description    : This function handles UART4  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/                                        
void UART4_IRQHander(void)
{
} 
 /*******************************************************************************
* Function Name  : UART5_IRQHander
* Description    : This function handles UART5  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/                                        
            
void UART5_IRQHander(void)
{
}  
 /*******************************************************************************
* Function Name  : TIM6_IRQHander
* Description    : This function handles TIM6  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/                                                   
void TIM6_IRQHander(void)
{
} 
 /*******************************************************************************
* Function Name  : TIM7_IRQHander
* Description    : This function handles TIM7  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/                                                   
void TIM7_IRQHander(void)
{

}
 /*******************************************************************************
* Function Name  : DMA2_Channel1_IRQHander
* Description    : This function handles DMA2  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/                                                                 
void DMA2_Channel1_IRQHander(void)
{
} 
 /*******************************************************************************
* Function Name  : DMA2_Channel2_IRQHander
* Description    : This function handles DMA2  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/                                                                 
    
void DMA2_Channel2_IRQHander(void)
{
}
 /*******************************************************************************
* Function Name  : DMA2_Channel3_IRQHander
* Description    : This function handles DMA2  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/                                                                 
     
void DMA2_Channel3_IRQHander(void)
{
} 
 /*******************************************************************************
* Function Name  : DMA2_Channel4_5_IRQHander
* Description    : This function handles DMA2  interrupt request.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/                                                                 
    
void DMA2_Channel4_5_IRQHander(void)
{
}   

#define EXTI_Line0       ((u32)0x00001)  /* External interrupt line 0 */
#define EXTI_Line1       ((u32)0x00002)  /* External interrupt line 1 */
#define EXTI_Line2       ((u32)0x00004)  /* External interrupt line 2 */
#define EXTI_Line3       ((u32)0x00008)  /* External interrupt line 3 */
#define EXTI_Line4       ((u32)0x00010)  /* External interrupt line 4 */
#define EXTI_Line5       ((u32)0x00020)  /* External interrupt line 5 */
#define EXTI_Line6       ((u32)0x00040)  /* External interrupt line 6 */
#define EXTI_Line7       ((u32)0x00080)  /* External interrupt line 7 */
#define EXTI_Line8       ((u32)0x00100)  /* External interrupt line 8 */
#define EXTI_Line9       ((u32)0x00200)  /* External interrupt line 9 */
#define EXTI_Line10      ((u32)0x00400)  /* External interrupt line 10 */
#define EXTI_Line11      ((u32)0x00800)  /* External interrupt line 11 */
#define EXTI_Line12      ((u32)0x01000)  /* External interrupt line 12 */
#define EXTI_Line13      ((u32)0x02000)  /* External interrupt line 13 */
#define EXTI_Line14      ((u32)0x04000)  /* External interrupt line 14 */
#define EXTI_Line15      ((u32)0x08000)  /* External interrupt line 15 */
#define EXTI_Line16      ((u32)0x10000)  /* External interrupt line 16
                                            Connected to the PVD Output */
#define EXTI_Line17      ((u32)0x20000)  /* External interrupt line 17 
                                            Connected to the RTC Alarm event */
#define EXTI_Line18      ((u32)0x40000)  /* External interrupt line 18 
                                            Connected to the USB Wakeup from 
                                            suspend event */

#include "config.h"
#if USEOV2640 == 1

#include "dcmi_ov2640.h"

u8 g_img_buf[1024*6];
int g_imgbuf_index;
static u8 VsyncActive  = 0;


static u8 * find_ffd8(int xi ,u8 * buf, int size)
{
        int i = xi;
        u8 x8[] = {0xFF,0xD8};
        u16 *x16 = (u16*)&x8;
        for(;i<size;i++)
        {
                if (i == size-1)
                        return 0;
                //printf("[%d][%d]\r\n",*x16,*(u16*)(buf+i));
                if (*x16 == *(u16*)(buf+i))
                        return buf+i;
        }
        return 0;
}

static u8 * find_ffd9(int xi ,u8 * buf, int size)
{
        int i = xi;
        u8 x8[] = {0xFF,0xD9};
        u16 *x16 = (u16*)&x8;
        for(;i<size;i++)
        {
                if (i == size-1)
                        return 0;
                //printf("[%d][%d]\r\n",*x16,*(u16*)(buf+i));
                if (*x16 == *(u16*)(buf+i))
                        return buf+i;
        }
        return 0;
}

char * get_img_data(int * len)
{
        u8 * _res = find_ffd8(0,(u8*)g_img_buf,sizeof(g_img_buf));
        u8 * _res2;
        if (_res > 0)
        {
                _res2 = find_ffd9(_res-g_img_buf,(u8*)g_img_buf,sizeof(g_img_buf));
        }

        if (_res2>0)
        {
                *len = (_res2-_res) + 2;
                return (char*)_res;
                //
        }
        return 0;

        //
}


void EXTI9_5_IRQHandler(void)
{


        //if(EXTI_GetITStatus(EXTI_Line8) != RESET)             //检查指定的EXTI0线路触发请求发生与否
        {
                //RUN_TEST;
                EXTI_ClearITPendingBit(EXTI_Line8);             //清除EXTI0线路挂起位
                //GPIOA->ODR ^= (1 << 0);                                               //LED闪烁一次

                if(GPIOB->IDR & (1<< 8))
                {       //上升沿->高电平->有效场同步信号
                        EXTI->IMR |= EXTI_Line15;                               //使能像素同步中断
                        EXTI->EMR |= EXTI_Line15;
                        VsyncActive = 1;
                }
                else
                {       //下降沿->场同步信号结束
                        //EXTI->IMR |= EXTI_Line15;
                        //EXTI->EMR |= EXTI_Line15;
                        EXTI->IMR &= ~EXTI_Line15;                              //关闭像素同步中断
                        EXTI->EMR &= ~EXTI_Line15;

                        if(VsyncActive == 1)
                        {       //已经经历了一个完整的场同步阶段
                                VsyncActive = 2;

                                EXTI->IMR &= ~EXTI_Line8;                               //关闭场同步中断
                                EXTI->EMR &= ~EXTI_Line8;


                                EXTI->IMR |= EXTI_Line8;                                //使能场同步中断，准备下次采集
                                EXTI->EMR |= EXTI_Line8;

                        }
                        else
                        {
                                VsyncActive = 0;
                        }
                }


        }

}

static int put_img_data(u8 data)
{
        extern u8 g_img_buf[];
        extern int g_imgbuf_index;
        if (g_imgbuf_index == sizeof(g_img_buf))
        {
                return 0;
        }

		

        g_img_buf[g_imgbuf_index++]     = data;
        return -1;
}



void EXTI15_10_IRQHandler(void)
{


                EXTI_ClearITPendingBit(EXTI_Line15);                    //清除EXTI0线路挂起位
                //JpegBuffer[JpegDataCnt++] = (u8)(GPIOC->IDR); //存储数据
                if (put_img_data((u8)(GPIOC->IDR)) == 0)
                {
                        EXTI->IMR &= ~EXTI_Line15;                              //关闭像素同步中断
                        EXTI->EMR &= ~EXTI_Line15;

                        EXTI->IMR &= ~EXTI_Line8;                               //关闭场同步中断
                        EXTI->EMR &= ~EXTI_Line8;
                        //
                }


}

#else
void EXTI15_10_IRQHandler(void){}
void EXTI9_5_IRQHandler(void){}
#endif

/******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE****/
