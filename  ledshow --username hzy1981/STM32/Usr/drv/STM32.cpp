#define STM32_C
#include "Includes.h"

void NVIC_Configuration(void)
{
    //----------中断优先级设置--------

	NVIC_InitTypeDef NVIC_InitStructure = {0};
	
	/* Configure the NVIC Preemption Priority Bits */  
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);	//设置优先级分组：先占优先级0位,从优先级4位
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);		//设置优先级分组：先占优先级2位,从优先级2位
	
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);   //向量表位于FLASH
	
	
    /* Enable the USARTy Interrupt */
	//串口接收中断，优先级最高
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		//USART1中断
 	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		//
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器USART1

	/* Enable the TIM2 global Interrupt */
	//刷屏中断优先级
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;  //TIM2中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;  //先占优先级1级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

	/* Enable the TIM4 global Interrupt */
	//特效中断
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;  //TIM4中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;  //先占优先级2级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;  //从优先级0级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器

}

//定时器中断，用于直接扫描屏
void TIM2_Configuration(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};
	/* TIM2 clock enable */
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	
	/* ---------------------------------------------------------------
	TIM2CLK 即PCLK1=36MHz
	TIM2CLK = 36 MHz, Prescaler = 7200, TIM2 counter clock = 5K,即改变一次为5K,周期就为10K
	--------------------------------------------------------------- */
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = SCAN_SCREEN_PERIOD * 10; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
	TIM_TimeBaseStructure.TIM_Prescaler =(SystemCoreClock/10000-1); //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
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
void TIM4_Configuration(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};
	/* TIM4 clock enable */
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	
	/* ---------------------------------------------------------------
	TIM4CLK 即PCLK1=36MHz
	TIM4CLK = 36 MHz, Prescaler = 7200, TIM4 counter clock = 5K,即改变一次为5K,周期就为10K
	--------------------------------------------------------------- */
	/* Time base configuration */
	TIM_TimeBaseStructure.TIM_Period = MOVE_STEP_PERIOD * 10; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
	TIM_TimeBaseStructure.TIM_Prescaler =(SystemCoreClock/10000-1); //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	
	/* Enables the Update event for TIM4 */
	//TIM_UpdateDisableConfig(TIM4,ENABLE); 	//使能 TIM4 更新事件 
	
	/* TIM IT enable */
	TIM_ITConfig(  //使能或者失能指定的TIM中断
		TIM4, //TIM4
		TIM_IT_Update  |  //TIM 中断源
		TIM_IT_Trigger,   //TIM 触发中断源 
		ENABLE  //使能
		);
	
	/* TIM4 enable counter */
	TIM_Cmd(TIM4, ENABLE);  //使能TIMx外设

}

//用于OE-PWM输出.
void TIM3_Configuration(void)
{
 	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure = {0};
	TIM_OCInitTypeDef  TIM_OCInitStructure = {0};
	/* TIM3 clock enable */
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
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
	TIM_TimeBaseStructure.TIM_Period = (SystemCoreClock / OE_PWM_FREQ); //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =0; //设置用来作为TIMx时钟频率除数的预分频值  不分频
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	
	/* Output Compare Active Mode configuration: Channel1 */
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //选择定时器模式:TIM脉冲宽度调制模式2
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0; //设置待装入捕获比较寄存器的脉冲值
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //根据TIM_OCInitStruct中指定的参数初始化外设TIMx
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIMx在CCR2上的预装载寄存器
	
	TIM_ARRPreloadConfig(TIM3, ENABLE); //使能TIMx在ARR上的预装载寄存器
	
	/* TIM3 enable counter */
	TIM_Cmd(TIM3, ENABLE);  //使能TIMx外设

	TIM_SetCompare3(TIM3,150);	//通过改变TIM3->CCR2的值来改变占空比，从而控制LED0的亮度 
}

//共有的驱动函数等在此文件中定义
//读物理存储器
#ifndef DEF_WR_PHY_MEM
INT8U Read_PHY_Mem(INT32U Offset, void *pDst, INT16U RD_Len, void *pDst_Start, INT16U DstLen)
{
  return 1;
}

//写物理存储器
INT8U Write_PHY_Mem(INT32U Offset, void *pSrc, INT16U SrcLen)
{
  return 1;
}
#endif
