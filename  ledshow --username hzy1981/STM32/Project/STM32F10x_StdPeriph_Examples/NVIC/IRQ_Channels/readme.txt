/**
  @page NVIC_IRQ_Channels NVIC_IRQ_Channels
  
  @verbatim
  ******************** (C) COPYRIGHT 2010 STMicroelectronics *******************
  * @file    NVIC/IRQ_Channels/readme.txt 
  * @author  MCD Application Team
  * @version V3.4.0
  * @date    10/15/2010
  * @brief   Description of the NVIC IRQ Channels Example.
  ******************************************************************************
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  ******************************************************************************
   @endverbatim

@par Example Description 

This example demonstrates the use of the Nested Vectored Interrupt Controller (NVIC)
IRQ Channels configuration: 

- Configuration of 3 TIM (TIM2..TIM4)timers to generate an interrupt on each 
  counter update event.
- The three timers are linked to their correspondant Update IRQ channel.
- Assignment of a ascendant IRQ priority for each IRQ channel :
  TIM2 has a preemption priority of 0 and TIM4 has a preemption priority of 2.
- In each interrupt routine: 
   - TIM2 toggles a LED1 each 1s 
   - TIM3 toggles a LED2 each 2s 
   - TIM4 toggles a LED3 each 3s 

@par Directory contents 

  - NVIC/IRQ_Channels/stm32f10x_conf.h    Library Configuration file
  - NVIC/IRQ_Channels/stm32f10x_it.c      Interrupt handlers
  - NVIC/IRQ_Channels/stm32f10x_it.h      Interrupt handlers header file
  - NVIC/IRQ_Channels/main.c              Main program
  - NVIC/IRQ_Channels/system_stm32f10x.c  STM32F10x system source file
  
@par Hardware and Software environment 

  - This example runs on STM32F10x Connectivity line, High-Density, High-Density 
    Value line, Medium-Density, XL-Density, Medium-Density Value line, Low-Density 
    and Low-Density Value line Devices.
  
  - This example has been tested with STMicroelectronics STM32100E-EVAL (High-Density 
    Value line), STM32100B-EVAL (Medium-Density Value line), STM3210C-EVAL (Connectivity line), 
    STM3210E-EVAL (High-Density and XL-Density) and STM3210B-EVAL (Medium-Density) 
    evaluation boards and can be easily tailored to any other supported device 
    and development board.
    To select the STMicroelectronics evaluation board used to run the example, 
    uncomment the corresponding line in stm32_eval.h file (under Utilities\STM32_EVAL)

  - STM32100E-EVAL Set-up 
    - Use LED1, LED2 and LED3 leds connected respectively to PF.06, PF0.7 and PF.08
    
  - STM32100B-EVAL Set-up  
    - Use LED1, LED2 and LED3 leds connected respectively to PC.06, PC.07 and PC.08
    
  - STM3210C-EVAL Set-up 
    - Use LED1, LED2 and LED3 connected respectively to PD.07, PD.13 and PF.03 
          
  - STM3210E-EVAL Set-up 
    - Use LED1, LED2 and LED3 leds connected respectively to PF.06, PF0.7 and PF.08

  - STM3210B-EVAL Set-up  
    - Use LED1, LED2 and LED3 leds connected respectively to PC.06, PC.07 and PC.08
	
@par How to use it ? 

In order to make the program work, you must do the following :
- Create a project and setup all project configuration
- Add the required Library files :
  - stm32f10x_gpio.c 
  - stm32f10x_rcc.c 
  - stm32f10x_exti.c  
  - misc.c 
  - stm32f10x_tim.c 
  - stm32f10x_usart.c
  - stm32f10x_i2c.c
  - stm32f10x_spi.c
  - stm32_eval.c (under Utilities\STM32_EVAL)
    
- Edit stm32f10x.h file to select the device you are working on.
- Edit stm32_eval.h file to select the evaluation board you will use.
  
@b Tip: You can tailor the provided project template to run this example, for 
        more details please refer to "stm32f10x_stdperiph_lib_um.chm" user 
        manual; select "Peripheral Examples" then follow the instructions 
        provided in "How to proceed" section.   
- Link all compiled files and load your image into target memory
- Run the example

@note
 - Low-density Value line devices are STM32F100xx microcontrollers where the 
   Flash memory density ranges between 16 and 32 Kbytes.
 - Low-density devices are STM32F101xx, STM32F102xx and STM32F103xx 
   microcontrollers where the Flash memory density ranges between 16 and 32 Kbytes.
 - Medium-density Value line devices are STM32F100xx microcontrollers where
   the Flash memory density ranges between 64 and 128 Kbytes.  
 - Medium-density devices are STM32F101xx, STM32F102xx and STM32F103xx 
   microcontrollers where the Flash memory density ranges between 64 and 128 Kbytes.
 - High-density Value line devices are STM32F100xx microcontrollers where
   the Flash memory density ranges between 256 and 512 Kbytes.
 - High-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 256 and 512 Kbytes.
 - XL-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 512 and 1024 Kbytes.
 - Connectivity line devices are STM32F105xx and STM32F107xx microcontrollers.
    
 * <h3><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h3>
 */
