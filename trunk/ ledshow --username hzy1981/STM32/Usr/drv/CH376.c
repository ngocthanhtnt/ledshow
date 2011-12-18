/*******************************************************************************

 * * * 文件名称：ch376.c

 * * * 文件说明：CH376芯片 SPI串行连接的硬件抽象层 V1.0

 * * * 创建日期：PowerAVR / 2009-12-19

 * * * 修改日期： 


*******************************************************************************/
/*
#include "stm32f10x.h"
#include "LED_Cfg.h"
#include "CH376INC.h"
#include "ch376.h"
#include "stm32.h"
*/
#include "includes.h"

UINT8	Wait376Interrupt( void )  /* 等待CH376中断(INT#低电平)，返回中断状态码, 超时则返回ERR_USB_UNKNOWN */
{

	UINT32	i;
	for ( i = 0; i < 2000000; i ++ ) {  /* 计数防止超时,默认的超时时间,与单片机主频有关 */
		if ( Query376Interrupt( ) ) return( CH376GetIntStatus( ) );  /* 检测到中断 */
		Delay_us(1);
/* 在等待CH376中断的过程中,可以做些需要及时处理的其它事情 */
	}
	return( ERR_USB_UNKNOWN );  /* 不应该发生的情况 */

}
/*****************************************************

 * Name:     mInitCH376Host

 * Function: 初始化CH376

 * Input: 	 no

 * Output:   no 

 * Author:   PowerAVR / 2009-12-19

 * Update:   	

*****************************************************/
u8 mInitCH376Host( void )  
{
 static u8 res;
 
 xWriteCH376Cmd( CMD11_CHECK_EXIST );  			/* 测试单片机与CH376之间的通讯接口 */
 xWriteCH376Data( 0x65 );
 res = xReadCH376Data( );
 xEndCH376Cmd( );								// 结束通信测试
 if ( res != 0x9A ) 
 {
 	//USART1_SendByte(0xe1);
 	return( ERR_USB_UNKNOWN );  				/* 通讯接口不正常,可能原因有:接口连接异常,其它设备影响(片选不唯一),串口波特率,一直在复位,晶振不工作 */
 }
 xWriteCH376Cmd( CMD11_SET_USB_MODE );  		/* 设备USB工作模式 */
 xWriteCH376Data( 0x06 );						// 模式代码为0x06,表示切换到已启用的USB主机方式，自动产生SOF包
 Delay_us( 50 );
 res = xReadCH376Data( );						// 返回操作状态
 xEndCH376Cmd( );							    // 工作模式设置结束

 //xWriteCH376Cmd( CMD20_SET_SDO_INT );  			/* 设置SPI的SDO引脚的中断方式 */
 //xWriteCH376Data( 0x16 );
 //xWriteCH376Data( 0x90 );  						/* SDO引脚在SCS片选无效时兼做中断请求输出 */
 //xEndCH376Cmd( );							    // 结束设置SDO引脚方式


 if ( res == CMD_RET_SUCCESS ) 
 	return( USB_INT_SUCCESS );
 else 
 {
 	//USART1_SendByte(0xe2);
 	return( ERR_USB_UNKNOWN );  				/* 设置模式错误 */
 }	
}
/*****************************************************

 * Name:     CH376_PORT_INIT

 * Function: 初始化CH376的SPI IO！

 * Input: 	 no

 * Output:   no 

 * Author:   PowerAVR / 2009-12-19

 * Update:   	

*****************************************************/
u8 mWaitInterrupt( void ) 
{								/* 等待CH376中断并获取状态,主机端等待操作完成,返回操作状态 */
 while ( Query376Interrupt( ) == FALSE );  		/* 一直等中断 */ 				
 xWriteCH376Cmd( CMD_GET_STATUS );  			/* 产生操作完成中断,获取中断状态 */
 return( xReadCH376Data( ) );
}

/*****************************************************

 * Name:     xWriteCH376Cmd

 * Function: 写命令到CH376去

 * Input: 	 no

 * Output:   no 

 * Author:   PowerAVR / 2009-12-19

 * Update:   	

*****************************************************/
void	xWriteCH376Cmd( u8 mCmd )  /* 向CH376写命令 */
{
    SET_CH376_CS(1);
	//GPIO_SetBits(GPIOA,GPIO_Pin_1);  /* 防止之前未通过xEndCH376Cmd禁止SPI片选 */
	mDelay0_5uS( );
/* 对于双向I/O引脚模拟SPI接口,那么必须确保已经设置SPI_SCS,SPI_SCK,SPI_SDI为输出方向,SPI_SDO为输入方向 */
	//GPIO_ResetBits(GPIOA,GPIO_Pin_1);  /* SPI片选有效 */
	SET_CH376_CS(0);
	CH376_ReadWrite( mCmd );  /* 发出命令码 */

    Delay_ms(1);
//	DelayXms(1);;  /* 延时1.5uS确保读写周期大于1.5uS,或者用上面一行的状态查询代替 */

}
/*****************************************************

 * Name:     xWriteCH376Data

 * Function: 写1字节数据到CH376

 * Input: 	 no

 * Output:   no 

 * Author:   PowerAVR / 2009-12-19

 * Update:   	

*****************************************************/
void	xWriteCH376Data( u8 mData )  /* 向CH376写数据 */
{
	CH376_ReadWrite( mData );
	mDelay0_5uS( );  /* 确保读写周期大于0.6uS */
}

/*****************************************************

 * Name:     xReadCH376Data

 * Function: 从CH376读取1字节数据

 * Input: 	 no

 * Output:   no 

 * Author:   PowerAVR / 2009-12-19

 * Update:   	

*****************************************************/
u8	xReadCH376Data( void )  /* 从CH376读数据 */
{
	mDelay0_5uS( );  /* 确保读写周期大于0.6uS */
	return( CH376_ReadWrite( 0xff) );
}
/*****************************************************

 * Name:     Query376Interrupt

 * Function: 查询CH376中断(INT#低电平)

 * Input: 	 no

 * Output:   no 

 * Author:   PowerAVR / 2009-12-19

 * Update:   	

*****************************************************/
u8	Query376Interrupt( void )
{
  return (CHK_CH376_INT()?FALSE:TRUE);
 //return( GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_6)? FALSE : TRUE );  			/* 如果未连接CH376的中断引脚则查询兼做中断输出的SDO引脚状态 */
}

/*****************************************************

 * Name:     mDelayuS

 * Function: delay

 * Input: 	 no

 * Output:   no 

 * Author:   PowerAVR / 2009-12-19

 * Update:   	

*****************************************************/
void mDelayuS(u8 us)
{
  Delay_us(us);
 //while(us--);
}

/*****************************************************

 * Name:     mDelayuS

 * Function: delay

 * Input: 	 no

 * Output:   no 

 * Author:   PowerAVR / 2009-12-19

 * Update:   	

*****************************************************/

void mDelaymS(u8 ms)
{/*
 unsigned int i;
 for(;ms>0;ms--)
     for(i=0;i<940;i++);
  */
  Delay_ms(ms);
}

/*****************************************************

 * Name:     mDelayuS

 * Function: delay

 * Input: 	 no

 * Output:   no 

 * Author:   PowerAVR / 2009-12-19

 * Update:   	

*****************************************************/
void	mDelay0_5uS( void )  /* 至少延时0.5uS,根据单片机主频调整 */
{/*
 u8 i;
 i=20;
 while(i--);
 */
 Delay_us(1);

}
/*
void main(void)
{
   volatile int a ;

   a = 10;
   
}
*/
#if 0
void SPI_CH376_Init(void)
{
   SPI_InitTypeDef SPI_InitStructure;
   GPIO_InitTypeDef GPIO_InitStructure;

   /* Enable SPI1 and GPIOA clocks */
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
/*
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_Init(GPIOD, &GPIO_InitStructure);
*/
   /* Configure SPI1 pins: NSS, SCK, MISO and MOSI */
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
   GPIO_Init(GPIOA, &GPIO_InitStructure);

   SET_CH376_CS(1);
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
   SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
   SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
   SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
   SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
   SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
   SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
   SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
   SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
   SPI_InitStructure.SPI_CRCPolynomial = 7;
   SPI_Init(SPI1, &SPI_InitStructure);

   /* Enable SPI1  */
   SPI_Cmd(SPI1, ENABLE);
}
#endif

