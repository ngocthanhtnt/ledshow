/**
* @file lwIP.c
* @brief A brief file description.
* @details
*     A more elaborated file description.
* @author Wang Mengyin
* @date 2010Jul19 15:53:34
* @note
*               Copyright 2010 Wang Mengyin.ALL RIGHTS RESERVED.
*                            http://tigerwang202.blogbus.com
*    This software is provided under license and contains proprietary and
* confidential material which is the property of Company Name tech.
*/


#define __LW_IP_C


/* Includes ------------------------------------------------------------------*/
#include "lwip/memp.h"
#include "lwIP.h"
#include "lwIP/tcp.h"
#include "lwIP/udp.h"
#include "lwIP/tcpip.h"
#include "netif/etharp.h"
#include "lwIP/dhcp.h"
#include "lwIP/dns.h"

#include "netif/ethernetif.h"
#include "system.h"
#include <stdio.h>
#include "parmcfg.h"


#define MAX_DHCP_TRIES        4

struct netif netif;
struct netif enc_netif;
struct netif default_netif;
static char slow_timer=0;
static char time_flag=0;
static char dns_time=0;
int app_time=0;
int app_time2=0;
void timer2_int(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){
		 TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
		 time_flag=1;
		 dns_time++;
		 slow_timer=slow_timer? 0:1;
		 app_time++;
		 app_time2++;
	}
}
void timer_thread(void)
{
	char fast_flag=0;
	char slow_flag=0;
	//char dns_flag=0;
	
	disable_timer();//变量重入	
	fast_flag=time_flag;
	time_flag=0;
	slow_flag=slow_timer;
	if(dns_time>4){
		dns_time=0;
	}
	enable_timer();
	if(fast_flag){//lwip不可重入解决方法
		time_flag=0;
		tcp_fasttmr();
		if(slow_flag)
			tcp_slowtmr();
//		if(dns_flag)
//	 	 	dns_tmr();//dns updata
	}
}





/**
* @brief Init_lwIP initialize the LwIP
*/
void Init_lwIP(void)
{
	struct ip_addr ipaddr;
	struct ip_addr netmask;
	struct ip_addr gw;
	struct ip_addr dnsserver;
	long *cfg_ip=(long *)wireless_ip;
	//  sys_init();	 
	/* Initializes the dynamic memory heap defined by MEM_SIZE.*/
	mem_init();
	/* Initializes the memory pools defined by MEMP_NUM_x.*/
	memp_init();	
	pbuf_init();	
	netif_init();
	printf("TCP/IP initializing...\n");
	if(*cfg_ip==0){//no ip addr,use DHCP
	/* 启用DHCP服务器 */
	ipaddr.addr = 0;
	netmask.addr = 0;
	gw.addr = 0;
	printf("using dhcp!\n");
	netif_add(&netif, &ipaddr, &netmask, &gw, NULL, &ethernetif_init, &ethernet_input);
	netif_set_default(&netif);
	netif_set_up(&netif);
	dhcp_start(&netif);
	}
	else{
	printf("using static ip!\n");
	/* 启用静态IP */
	IP4_ADDR(&ipaddr,wireless_ip[0], wireless_ip[1],
	wireless_ip[2], wireless_ip[3]);
	IP4_ADDR(&netmask, wireless_mask[0], wireless_mask[1], 
					wireless_mask[2], wireless_mask[3]);
	IP4_ADDR(&gw, wireless_gw[0], wireless_gw[1],
				wireless_gw[2], wireless_gw[3]);
	IP4_ADDR(&dnsserver, wireless_dns[0], wireless_dns[1],
				wireless_dns[2], wireless_dns[3]);
	dns_init();
	dns_setserver(0, &dnsserver);//set dns server addr	
	netif_add(&netif, &ipaddr, &netmask, &gw, NULL, &ethernetif_init, &ethernet_input);
	netif_set_default(&netif);
	netif_set_up(&netif);
	}
	timerbase_config();
	printf("TCP/IP initialized.\n");
}

void rest_sys_mem(void)
{
	mem_init();
    /* Initializes the memory pools defined by MEMP_NUM_x.*/
    memp_init();    
    pbuf_init();	
}
