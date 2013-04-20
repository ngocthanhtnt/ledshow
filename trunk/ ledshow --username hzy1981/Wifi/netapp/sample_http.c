/*
 *********************************************************************************************************
 *                                     lwIP TCP/IP Stack & uC/OS-II RTOS
 *                                         port for Freescale MCF5223x
 *
 * File : sample_http.c
 *
 * By   : Ming Zeng <vivimillin@gmail.com>, Changxing Lin
 *        Tsinghua Freescale Embedded System Center, Beijing, P.R.China, <2008.01>
 *********************************************************************************************************
 */

#include "sample_http.h"
#include "common.h"
#include "dev.h"
#include "marvell_ops.h"
#include "parmcfg.h"
#if LWIP_TCP


#define TEST_WEB_SRV 0

//by millin 2008-01 add counter & runtimer
u32_t runtime=0;
u32_t counter=0;



char html_buffer[512];



static void hex_trans(char *frm,char *dst)
{
	int iii;
	if(!memcmp(frm,"%3d",3)){
		iii=3;
		while(iii--){
			if(*dst==' ')
				*dst++='0';
		}
	}
	else if(!memcmp(frm,"%2x",3)){
		iii=2;
		while(iii--){
			if((*dst>'a'-1)&&(*dst<'g'))
				*dst-='a'-'A';
			else if(*dst==' ')
				*dst='0';
			*dst++;
		}
	}
}

#define snprintf(dst,n,frm,src) do{sprintf((char *)tmp,frm,(char *)src);memcpy((char *)dst,(char *)tmp,n);hex_trans(frm,(char *)dst);}while(0)

static void html_cgi(unsigned char *html,unsigned char *buffer,struct http_state *hs)
{ 
	int index=hs->index++;
	int len=hs->left<512?hs->left:512;
	char tmp[32];
	hs->len=len;
	memcpy(buffer,html+512*index,len);
	if(index==0){
		//net mode
		if(marvel_mode=='1'){
			snprintf(buffer+INFRA_INDEX,8,"%s",
					"        ");
			snprintf(buffer+ADHOC_INDEX,8,"%s",
					"selected");
		}
		else if(marvel_mode=='0'){
			snprintf(buffer+INFRA_INDEX,8,"%s",
					"selected");
			snprintf(buffer+ADHOC_INDEX,8,"%s",
					"        ");
		}	
	}
	else if(index==1){

		/*if(marvel_mode=='1')
		 *buffer='d';
		 else
		 *buffer=' ';*/

		//ssid
		memset(buffer+SSID_INDEX-512,0,64);
		sprintf((char *)buffer+SSID_INDEX-512,"\"%s\"",marvel_ssid);
		//key
		memset(buffer+KEY_INDEX-512,0,61);
		sprintf((char *)buffer+KEY_INDEX-512,"\"%s\"",marvel_key);
		//ip1
		snprintf(buffer+WIP1_INDEX-512,3,"%3d",wireless_ip[0]);
		//ip2
		snprintf(buffer+WIP2_INDEX-512,3,"%3d",wireless_ip[1]);

	}
	else if(index==2){
		//ip3
		snprintf(buffer+WIP3_INDEX-1024,3,"%3d",wireless_ip[2]);
		snprintf(buffer+WIP4_INDEX-1024,3,"%3d",wireless_ip[3]);

		//mask
		snprintf(buffer+MASK1_INDEX-1024,3,"%3d",wireless_mask[0]);
		snprintf(buffer+MASK2_INDEX-1024,3,"%3d",wireless_mask[1]);
		snprintf(buffer+MASK3_INDEX-1024,3,"%3d",wireless_mask[2]);
		snprintf(buffer+MASK4_INDEX-1024,3,"%3d",wireless_mask[3]);



	}
	else if(index==3){

		//gataway
		snprintf(buffer+GATAWAY1_INDEX-1536,3,"%3d",wireless_gw[0]);
		snprintf(buffer+GATAWAY2_INDEX-1536,3,"%3d",wireless_gw[1]);
		snprintf(buffer+GATAWAY3_INDEX-1536,3,"%3d",wireless_gw[2]);
		snprintf(buffer+GATAWAY4_INDEX-1536,3,"%3d",wireless_gw[3]);

		snprintf(buffer+DNS1_INDEX-1536,3,"%3d",wireless_dns[0]);
		snprintf(buffer+DNS2_INDEX-1536,3,"%3d",wireless_dns[1]);

	}
	else if(index==4){
		memcpy(wireless_mac,pgmarvel_priv->current_addr,6);//updata mac
		snprintf(buffer+DNS3_INDEX-2048,3,"%3d",wireless_dns[2]);
		snprintf(buffer+DNS4_INDEX-2048,3,"%3d",wireless_dns[3]);
		//mac
		snprintf(buffer+WMAC0_INDEX-2048,2,"%2x",wireless_mac[0]);
		snprintf(buffer+WMAC1_INDEX-2048,2,"%2x",wireless_mac[1]);
		snprintf(buffer+WMAC2_INDEX-2048,2,"%2x",wireless_mac[2]);
		snprintf(buffer+WMAC3_INDEX-2048,2,"%2x",wireless_mac[3]);
		snprintf(buffer+WMAC4_INDEX-2048,2,"%2x",wireless_mac[4]);

	}
	else if(index==5){
		snprintf(buffer+WMAC5_INDEX-2560,2,"%2x",wireless_mac[5]);

	}
}


/*
   static int get_parmer(unsigned char *str,unsigned char *name,unsigned char *context,unsigned char chr)
   {
   int cnt=0;
   unsigned char *parm;
   while(*context){
   if((*(context-1)!=chr)&&(*(context-1)!='?')){
   context++;
   continue;
   }
   if((memcmp(context,name,strlen((const char *)name))==0)&&
   (*(context+strlen((const char *)name))=='=')){//名字匹配而且以‘=’开始参数
   parm=context+strlen((const char *)name)+1;//"name=
   context+=(strlen((const char *)name)+1);
   while((*context!=chr)&&(*context!='\0')){//&标示参数结束
   cnt++;
   context++;
   }
   memcpy(str,parm,cnt);//copy parm to str
 *(str+cnt)='\0';
 return 0;
 }
 else
 context++;	
 }
 return -1;//cann't find the parm
 }
 */
/*StartAddr 必须保证按页对齐，len的长度以字节为单位*/


/*-----------------------------------------------------------------------------------*/
	static void
conn_err(void *arg, err_t err)
{
	struct http_state *hs;

	hs = arg;
	mem_free(hs);
}
/*-----------------------------------------------------------------------------------*/
	static void
close_conn(struct tcp_pcb *pcb, struct http_state *hs)
{
	tcp_arg(pcb, NULL);
	tcp_sent(pcb, NULL);
	tcp_recv(pcb, NULL);
	mem_free(hs);
	tcp_close(pcb);
}
/*-----------------------------------------------------------------------------------*/
	static void
send_data(struct tcp_pcb *pcb, struct http_state *hs)
{
	err_t err;
	u16_t len;
	/* We cannot send more data than space available in the send
	   buffer. */ 
	if(1000 < hs->len)
		len = 1000;
	else 
		len =hs->len;
	err = tcp_write(pcb,html_buffer, len, 0);  
	if(err == ERR_OK) {
		hs->file += len;
		hs->left -= len;
	}

}
/*-----------------------------------------------------------------------------------*/
#if 0
	static err_t
http_poll(void *arg, struct tcp_pcb *pcb)
{
	struct http_state *hs;

	hs = arg;

	/*  printf("Polll\n");*/
	if(hs == NULL) {
		/*    printf("Null, close\n");*/
		tcp_abort(pcb);
		return ERR_ABRT;
	} else {
		++hs->retries;
		if(hs->retries == 4) {
			tcp_abort(pcb);
			return ERR_ABRT;
		}
		send_data(pcb, hs);
	}

	return ERR_OK;
}
#endif
/*-----------------------------------------------------------------------------------*/
	static err_t
http_sent(void *arg, struct tcp_pcb *pcb, u16_t len)
{
	struct http_state *hs;
	hs = arg;
	hs->retries = 0;
	if(hs->left > 0) {
		html_cgi((unsigned char *)html,(unsigned char *)html_buffer,hs);
		send_data(pcb, hs);
	} 
	else{
		close_conn(pcb,hs);
		if(hs->cfg)
			NVIC_GenerateSystemReset();//reboot system to updata config

	}
	return ERR_OK;
}




#if TEST_WEB_SRV
	static err_t
test_sent(void *arg, struct tcp_pcb *pcb, u16_t len)
{
	struct http_state *hs;
	hs = arg;
	hs->retries = 0;
	if(hs->left > 0) {
		test_cgi((unsigned char *)test_html,(unsigned char *)html_buffer,hs);
		send_data(pcb, hs);
	} 
	else{
		close_conn(pcb,hs);
		if(hs->cfg)
			NVIC_GenerateSystemReset();//reboot system to updata config

	}
	return ERR_OK;
}
#endif



const static char http_html_hdr[]="HTTP/1.1 200 OK\r\nContent-type: text/html\r\n\r\n";

/*-----------------------------------------------------------------------------------*/
	static err_t
http_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
	// int i;
	char *data;
	struct http_state *hs;
	//added by millin, 2008.01
	//u8_t hour,min,sec;
	//u16_t day;

	hs = arg;

	if(err == ERR_OK && p != NULL) {

		/* Inform TCP that we have taken the data. */
		tcp_recved(pcb, p->tot_len);
		printf("%s",p->payload);


		if(hs->file == NULL) {
			data = p->payload;
#if (USEOV2640 == 1)
			//针对wificam做特殊处理
			if(!memcmp(data,"GET /wificam",strlen("GET /wificam"))){//GET /Route?http
				//para_string((unsigned char *)data);
				//NVIC_GenerateSystemReset();
				//hs->cfg=1;
				int wret;
				int clen = 0;
				int len = 0;
				char * xxx;
				extern int g_imgbuf_index;


				g_imgbuf_index = 0;//清空图像计数器
				enable_ov2640();
				while(g_imgbuf_index < 1024*10){} // wait for img
				disable_ov2640();

				xxx = (char*)get_img_data(&len);
				printf("current jpeg %d .........\n",len);
				//xdbug_buf("image",xxx,len);

#define BLK 128
				while(clen < len)
				{

					if ((len-clen) > BLK)
					{
						wret = tcp_write(pcb,xxx+clen, BLK , 0);
						if (wret == -1)
							pollmac();
						else
							clen += BLK;
					}
					else
					{
						wret = tcp_write(pcb,xxx+clen, len-clen , 0);
						if (wret == -1)
							pollmac();
						else
							clen += (len-clen);
					}

					//printf("current wret %d\n",wret);

				}

				pbuf_free(p);
				close_conn(pcb, hs);
				enable_ov2640();
				return ERR_OK;

			}
#endif
			if(!memcmp(data,"GET /",strlen("GET /"))) {//GET /

				err = tcp_write(pcb,http_html_hdr,strlen(http_html_hdr), 0);  
				hs->file =(char *)&html;
				hs->left =sizeof(html);
				hs->len =512;
				hs->index=0;
				if(!memcmp(data,"GET /Route?",strlen("GET /Route?"))){//GET /Route?http
					//para_string((unsigned char *)data);
					write_flash_config((u16 *)data,512);
					hs->cfg=1;

				}	
				if(!memcmp(data,"GET /J_OPEN?",strlen("GET /J_OPEN?"))){//GET /Route?http
					//para_string((unsigned char *)data);
					//write_flash_config((u16 *)data,512);
					LED2(0);
					LED3(1);
					hs->cfg=0;

				}
				if(!memcmp(data,"GET /J_CLOSE?",strlen("GET /J_CLOSE?"))){//GET /Route?http
					//para_string((unsigned char *)data);
					LED2(1);
					LED3(0);
					hs->cfg=0;

				}
				if(!memcmp(data,"GET /LED_OPEN?",strlen("GET /LED_OPEN?"))){//GET /Route?http
					//para_string((unsigned char *)data);
					//hs->cfg=1;

				}
				if(!memcmp(data,"GET /CLOSE?",strlen("GET /LED_CLOSE?"))){//GET /Route?http
					//para_string((unsigned char *)data);
					//hs->cfg=1;

				}

				if(!memcmp(data,"GET /RESET_SYS?",strlen("GET /RESET_SYS?"))){//GET /Route?http
					//para_string((unsigned char *)data);
					NVIC_GenerateSystemReset();
					//hs->cfg=1;

				}

				if(!memcmp(data,"GET /TEST_BUTTON?",strlen("GET /TEST_BUTTON?"))){//GET /Route?http
					//para_string((unsigned char *)data);
					//NVIC_GenerateSystemReset();
					//hs->cfg=1;
					printf("TEST BUTTON .........\n");

				}



				html_cgi((unsigned char *)html,(unsigned char *)html_buffer,hs);
				pbuf_free(p);
				tcp_sent(pcb,http_sent);
				send_data(pcb, hs);
			} //if(*data =='G')       
			else {
				pbuf_free(p);
				close_conn(pcb, hs);
			} //else if(*data =='G')

		} //if(hs->file == NULL) 

		else {
			pbuf_free(p);
		}
	}

	if(err == ERR_OK && p == NULL) {
		close_conn(pcb, hs);
	}
	return ERR_OK;
}


#if TEST_WEB_SRV

	static err_t
test_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err)
{
	// int i;
	char *data;
	struct http_state *hs;
	//added by millin, 2008.01
	// u8_t hour,min,sec;
	//  u16_t day;

	hs = arg;

	if(err == ERR_OK && p != NULL) {

		/* Inform TCP that we have taken the data. */
		tcp_recved(pcb, p->tot_len);
		printf("%s",(char *)p->payload);
		if(hs->file == NULL) {
			data = p->payload;
			if(!memcmp(data,"GET /",strlen("GET /"))) {//GET /
				hs->file =(char *)&test_html;
				hs->left =sizeof(test_html);
				hs->len =512;
				hs->index=0;
				test_cgi((unsigned char *)test_html,(unsigned char *)html_buffer,hs);
				pbuf_free(p);
				tcp_sent(pcb, test_sent);
				send_data(pcb, hs);

			} //if(*data =='G')       
			else {
				pbuf_free(p);
				close_conn(pcb, hs);
			} //else if(*data =='G')

		} //if(hs->file == NULL) 

		else {
			pbuf_free(p);
		}
	}

	if(err == ERR_OK && p == NULL) {
		close_conn(pcb, hs);
	}
	return ERR_OK;
}


#endif









/*-----------------------------------------------------------------------------------*/
	static err_t
http_accept(void *arg, struct tcp_pcb *pcb, err_t err)
{
	struct http_state *hs;
	/* Allocate memory for the structure that holds the state of the
	   connection. */
	hs = mem_malloc(sizeof(struct http_state));

	if(hs == NULL) {
		return ERR_MEM;
	}

	/* Initialize the structure. */
	hs->file = NULL;
	hs->left = 0;
	hs->retries = 0;
	hs->cfg=0;
	/* Tell TCP that this is the structure we wish to be passed for our
	   callbacks. */
	tcp_arg(pcb, hs);

	/* Tell TCP that we wish to be informed of incoming data by a call
	   to the http_recv() function. */
	tcp_recv(pcb, http_recv);
	tcp_err(pcb, conn_err);

	//tcp_poll(pcb, http_poll, 20);
	return ERR_OK;
}


#if TEST_WEB_SRV

	static err_t
test_accept(void *arg, struct tcp_pcb *pcb, err_t err)
{
	struct http_state *hs;
	/* Allocate memory for the structure that holds the state of the
	   connection. */
	hs = mem_malloc(sizeof(struct http_state));

	if(hs == NULL) {
		return ERR_MEM;
	}

	/* Initialize the structure. */
	hs->file = NULL;
	hs->left = 0;
	hs->retries = 0;
	hs->cfg=0;
	/* Tell TCP that this is the structure we wish to be passed for our
	   callbacks. */
	tcp_arg(pcb, hs);

	/* Tell TCP that we wish to be informed of incoming data by a call
	   to the http_recv() function. */
	tcp_recv(pcb, test_recv);
	tcp_err(pcb, conn_err);

	//tcp_poll(pcb, http_poll, 20);
	return ERR_OK;
}

#endif




/*-----------------------------------------------------------------------------------*/
void httpd_init(void)
{
	struct tcp_pcb *pcb;
	counter = (u32_t) 0x00000000;   
	pcb = tcp_new();
	tcp_bind(pcb, IP_ADDR_ANY, 80);
	pcb = tcp_listen(pcb);
	tcp_accept(pcb, http_accept);


#if TEST_WEB_SRV

	//test web

	pcb = tcp_new();
	tcp_bind(pcb, IP_ADDR_ANY, 81);
	pcb = tcp_listen(pcb);
	tcp_accept(pcb, test_accept);
#endif



}

#endif //LWIP_TCP
