#include "includes.h"
#if NET_EN

/*----------------------------------------------------------------------------
 *      EMAC Ethernet Driver Functions
 *----------------------------------------------------------------------------
 *  Required functions for Ethernet driver module:
 *  a. Polling mode: - void init_ethernet ()                       //轮询模式只要实现以下三个函数
 *                   - void send_frame (OS_FRAME *frame)
 *                   - void poll_ethernet (void)
 *  b. Interrupt mode: - void init_ethernet ()                    //中断模式要实现以下五个函数
 *                     - void send_frame (OS_FRAME *frame)
 *                     - void int_enable_eth ()
 *                     - void int_disable_eth ()
 *                     - interrupt function 
*---------------------------------------------------------------------------*/
 /*

 	在Net_config中，有这样的定义
    U8   own_hw_adr[ETH_ADRLEN] = { _MAC1, _MAC2, _MAC3, _MAC4, _MAC5, _MAC6 };
	而且通过界面可以修改这几个定义
	在驱动里有 extern U8 own_hw_adr[];	 然后再初始化函数里调用了该函数

   os_frame在net_config.h文件中有如下定义：
     typedef struct os_frame {          << System frame buffer structure >>    
      U16 length;                      Total Length of data in frame           
      U16 index;                       Buffer Position Index                   
      U8  data[1];                     Buffer data (protocol headers + data)  
     } OS_FRAME;


*---------------------------------------------------------------------------*/
extern U8 own_hw_adr[];

void init_ethernet(void) 
{
	SPInet_Init();
	enc28j60Init(own_hw_adr);
} 

void send_frame (OS_FRAME *frame)
{
	U32 len;
	U32 *dp,*sp;
	//U8 pdata[ETH_MTU];
	U8 *pdata;

    pdata = (U8 *)Pub_Buf;
	sp  = (U32 *)&frame->data[0];
	dp  = (U32 *)&pdata[0];

	for (len = (frame->length + 3) >> 2; len; len--) 
	{
  	  *dp++ = *sp++;
  	}

	enc28j60PacketSend(frame->length,pdata);
}

void poll_ether(void)//net(void)
{
	OS_FRAME *frame;
	//U8 pdata[ETH_MTU];
	U8 *pdata;
	U32 RxLen	;
	U32 *dp,*sp;

	pdata = (U8 *)Pub_Buf;
	RxLen=enc28j60PacketReceive(ETH_MTU, pdata);
	sp  = (U32 *)&pdata[0];

	if(RxLen!=0)
	{	 
		frame = alloc_mem (RxLen);
	    if(frame != 0)
		{
			RxLen = (RxLen + 3) >> 2;	
			dp = (U32 *)&frame->data[0];
			for (  ; RxLen; RxLen--)
			 {
	    		*dp++ =  *sp++;
	 		 }
			frame->length=RxLen-1;
			put_in_queue (frame);
		}
	}
	else return;
}
#endif


