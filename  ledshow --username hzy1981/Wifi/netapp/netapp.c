#include "netapp.h"

extern const unsigned char html[];
void send_char(char ch);

struct TcpClientCon{
	struct tcp_pcb *pcb;
	struct ip_addr ipaddr;//server ip
	long port;
	char connected;
};


static struct TcpClientCon TcpClient;

static void app_delay()
{
	int i;
	for(i=0;i<1000;i++);
}
	
void UDP_Receive(void *arg, struct udp_pcb *upcb, struct pbuf *p,struct ip_addr *addr, u16_t port) 
{ 
	struct ip_addr ipaddr=*addr;
	if(p != NULL){ 
	app_delay();
    udp_sendto(upcb,p,&ipaddr,port);  /* 将收到的数据再发送出去                   */ 	
    pbuf_free(p);                                           /*  释放缓冲区数据                      */ 
    } 
} 
const static char UDPData[]={"LwIP UDP客户端测试\r\n"}; 
void UDP_Test(void) 
{ 
    struct udp_pcb *UdpPcb; 
	struct ip_addr ipaddr;
	struct pbuf *p;
	p = pbuf_alloc(PBUF_RAW,sizeof(UDPData),PBUF_RAM); 
	if(p==NULL)
		return;
	p->payload=(void *)UDPData; 
    UdpPcb=udp_new();                                     /*  建立UDP 通信的控制块(pcb)             */ 
    udp_bind(UdpPcb,IP_ADDR_ANY,8080);                     /*  绑定本地IP 地址                      */ 
    IP4_ADDR(&ipaddr,192, 168, 10, 100);
    udp_sendto(UdpPcb,p,&ipaddr,8080);                      /* 将收到的数据再发送出去                   */ 
    udp_sendto(UdpPcb,p,&ipaddr,8080); 
    udp_sendto(UdpPcb,p,&ipaddr,8080); 
    udp_recv(UdpPcb,UDP_Receive,NULL);                     /* 设置数据接收时的回调函数                   */ 
} 


const static char TCP_TestData[]="This is LwIP TCP Client  在Luminary Cortex-M3 上的测试！\r\n"; 

/*******  这是一个回调函数，当TCP 客户端请求的连接建立时被调用********/ 
extern const char demo[];

err_t tcp_sended(void *arg, struct tcp_pcb *tpcb, u16_t len)
{
	//printf("send len=%d\n",len);
    //   tcp_write(tpcb,html,1200,0);    
   return 0;
}



static err_t
tcp_client_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
  if(err == ERR_OK && p != NULL) {
    /* Inform TCP that we have taken the data. */
    tcp_recved(pcb, p->tot_len);
	tcp_write(pcb,p->payload,p->tot_len,0);   
  }
  else if(err == ERR_OK && p == NULL) {
    tcp_close(pcb);
	TcpClient.connected=0;
  }
  pbuf_free(p);
  return ERR_OK;
}




err_t TcpCli_Connected(void *arg,struct tcp_pcb *pcb,err_t err) 
{ 
  //printf("tcp connect %s",err ?"error":"ok");
  // tcp_write(pcb,html,1200,0);    
  // tcp_sent(pcb, tcp_sended); 
  tcp_arg(pcb,(void *)TCP_TestData);
  tcp_recv(pcb,tcp_client_recv);
  TcpClient.connected=1;
   return ERR_OK; 

} 
void TCP_Client_Init(void);

static void ClientConError(void *arg, err_t err)
{
	TcpClient.connected=0;
	//printf("xxxxxxxxxxxxxxxxxxxxxxxxx %d \n",err);
	
}

void TCP_Client_Init(void) 
{ 
  TcpClient.connected=1;
  IP4_ADDR(&TcpClient.ipaddr,192,168,10,100); 
  TcpClient.port=8080;
  TcpClient.pcb=tcp_new();   /*  建立通信的TCP 控制块(Clipcb)                */ 
  tcp_bind(TcpClient.pcb,IP_ADDR_ANY,0);/*  绑定本地IP 地址和端口号*/ 
  tcp_err(TcpClient.pcb, ClientConError);
  tcp_connect(TcpClient.pcb,&TcpClient.ipaddr,
  TcpClient.port,TcpCli_Connected); 
} 

void ReConTcpServer(void)
{
	if(!TcpClient.connected){
		TCP_Client_Init();
	}
}



static err_t
server_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
  if(err == ERR_OK && p != NULL) {
    /* Inform TCP that we have taken the data. */
    tcp_recved(pcb, p->tot_len);
	tcp_write(pcb,p->payload,p->tot_len,0);
	#define LED_OPEN "LED_OPEN"
	#define LED_CLOSE "LED_CLOSE"
	if (strstr(p->payload,LED_OPEN) > 0)
	{
		LED1(0);
		LED2(0);
	}

	if (strstr(p->payload,LED_CLOSE) > 0)
	{
		LED1(1);
		LED2(1);
	}
	 
	
	pbuf_free(p);
  }
  if(err == ERR_OK && p == NULL) {
	tcp_abort(pcb);
    tcp_close(pcb);
  }
  return ERR_OK;
}



static err_t
server_accept(void *arg, struct tcp_pcb *pcb, err_t err)
{
  /* Tell TCP that this is the structure we wish to be passed for our callbacks. */
  tcp_arg(pcb, NULL);
  /* Tell TCP that we wish to be informed of incoming data by a call to the http_recv() function. */
  tcp_recv(pcb, server_recv);
  return ERR_OK;
}


void tcp_server_init(void)
{
  struct tcp_pcb *pcb;
  pcb = tcp_new();
  tcp_bind(pcb, IP_ADDR_ANY,8080);
  pcb = tcp_listen(pcb);
  tcp_accept(pcb, server_accept);

}













