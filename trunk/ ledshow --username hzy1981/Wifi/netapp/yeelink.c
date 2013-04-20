#include "yeelink.h"
#include "lwip.h"
#include "common.h"

//#define xdbug_buf(...)

#define xDEBUG_ON


struct YeeTcpClientCon YeeClient;
static char empty[] = {0xff,0xff,0xff,0xff};
static char api_key[] = "94cdf56bdb733d185f6e080126dd4f44";
static char status_str[] = "http://api.yeelink.net/v1.0/device/1938/sensor/2488/datapoints";

static void process_recv_html(char * body)
{
	char * find = strstr(body,"}");
	if (find == NULL)
	{
		printf("ERROR\n");

		return ;
	}
	find = find -1 ;
	if (find[0] == '1' )
	{
		LED1(0);
		LED2(0);
		LED3(0);
		printf("ON\n");
	}
	if (find[0] == '0' )
	{
		LED1(1);
		LED2(1);  
		LED3(1);  //PB8 为继电器控制管脚
		printf("OFF\n");
	}
	//
}

static err_t
yee_client_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
	if(err == ERR_OK && p != NULL) {
		/* Inform TCP that we have taken the data. */
			tcp_recved(pcb, p->tot_len);
			//xdbug_buf("RECV HTTP RESPONSE",p->payload,p->tot_len);
			//tcp_write(pcb,p->payload,p->tot_len,0);   
			#ifdef DEBUG_ON
			printf("<-------------[%s]",p->payload);
			#endif
			process_recv_html(p->payload);
	}
	else if(err == ERR_OK && p == NULL) {
		tcp_close(pcb);
			YeeClient.connected=0;
	}
	pbuf_free(p);
		return ERR_OK;
}


const static char TCP_TestData[]="This is LwIP TCP Client  在Luminary Cortex-M3 上的测试！\r\n"; 


static err_t YeeCli_Connected(void *arg,struct tcp_pcb *pcb,err_t err) 
{ 
	
	tcp_arg(pcb,(void *)TCP_TestData);
	tcp_recv(pcb,yee_client_recv);
	YeeClient.connected=1;
	return ERR_OK; 
		
}

static void YeeConError(void *arg, err_t err)
{
	YeeClient.connected=0;
	printf("connect to server errcode : %d \n",err);
		
}


void REQUEST_YEE()
{
	#define BUFSIZE 1024
	char request[BUFSIZE];
	memset(request,0,BUFSIZE);
	strcat(request,"GET ");
	strcat(request,/*get_path*/status_str + 22);
	strcat(request," HTTP/1.1\r\n");//至此为http请求行的信息

	strcat(request,"Accept: text/html, image/jpeg, image/png, vedio/x-mng, text/*, image/*, */*\r\n");
	strcat(request,"Accept-Lauguage: zh-cn\r\n");
	//strcat(request,"Accept-Encoding: x-gzip, x-deflate, gzip, deflat\r\n");
	strcat(request,"Accept-charset: utf-8, utf-8; q=0.5, *; q=0.5\r\n");
	strcat(request,"U-ApiKey: ");
	strcat(request,api_key);
	strcat(request,"\r\n");
	strcat(request,"HOST: ");
	strcat(request,"api.yeelink.net");
	strcat(request,"\r\n");
	//strcat(request,"Content-Type: text/html\r\n");
	//strcat(request,"Content-Length: 1024\r\n");
	strcat(request,"Connection: Keep-Alive\r\n");
	strcat(request,"Cache-Control: no-cache\r\n\r\n");

	//xdbug_buf("RECV HTTP REQUEST",request,strlen(request));
	
	Yee_send_data(request,strlen(request));
}

void Yee_send_data(u8 * buf , int len )
{

	if (YeeClient.connected)
	{
		printf("[%s]",buf);
		tcp_write(YeeClient.pcb,buf,len,0);
		
	}
}

static void dns_found_callbackx(const char *name, struct ip_addr *ipaddr, void *callback_arg){
}

void Yee_Client_Init(void) 
{ 
	YeeClient.connected=1;

	IP4_ADDR(&YeeClient.ipaddr,202,136,56,203); 
	YeeClient.port=80;
	YeeClient.pcb=tcp_new();   /*  建立通信的TCP 控制块(Clipcb)                */ 
	tcp_bind(YeeClient.pcb,IP_ADDR_ANY,0);/*  绑定本地IP 地址和端口号*/ 
	tcp_err(YeeClient.pcb, YeeConError);
	tcp_connect(YeeClient.pcb,&YeeClient.ipaddr,
	YeeClient.port,YeeCli_Connected); 
}

void Yee_Client_ReInit(void)
{
	if (YeeClient.connected != 1)
		Yee_Client_Init();	
} 


