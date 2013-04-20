#ifndef __yeelink_h__
#define __yeelink_h__
#include "lwip.h"
struct YeeTcpClientCon{
	struct tcp_pcb *pcb;
	struct ip_addr ipaddr;//server ip
	long port;
	char connected;
};

extern struct YeeTcpClientCon YeeClient;
extern void Yee_send_data(u8 * buf , int len );
extern void Yee_Client_Init(void);
extern void Yee_Client_ReInit(void);

#endif
