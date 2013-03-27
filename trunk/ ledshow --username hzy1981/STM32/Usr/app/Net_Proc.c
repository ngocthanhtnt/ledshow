#define NET_PROC_C
#include "Includes.h"

#if NET_EN

extern U8 own_hw_adr[];
extern U8 lhost_name[];
extern LOCALM localm[];

/* The following definitions should be read out of EEPROM. */
U8 const mac_adr[6] = { 0,1,2,50,60,70 };
LOCALM ip_config = {
  { 192,168,1,122 },             // IP address
  { 192,168,1,1 },               // Default Gateway
  { 255,255,255,0 },             // Net mask
  { 192,168,1,122 },              // Primary DNS server
  { 192,168,1,122 }               // Secondary DNS server
};
//U8 const DHCP_mode = 0;
U8 dev_name[16] = { "AL_CARD" };


U16 udp_callback (U8 socket, U8 *remip, U16 port, U8 *buf, U16 len)
{
  /* This function is called when UDP data has been received. */
  if(len <= sizeof(RCV_DATA_BUF))
  {
	memcpy((INT8U *)Screen_Status.Rem_IP, remip, 4);
	Screen_Status.Rem_Port = port;
	memcpy((INT8U *)RCV_DATA_BUF, buf, len);
	Screen_Status.Rem_Data_Flag = REM_DATA_FLAG;
	Screen_Status.Rem_Data_Len = len;
  }

  return (0);
}

//转换网络参数到需要的格式
void Trans_IP_Para(LOCALM *pNet)
{
  memcpy(pNet->IpAdr, (INT8U *)&Screen_Para.ETH_Para.IP, 4);
  memcpy(pNet->DefGW, (INT8U *)&Screen_Para.ETH_Para.Gate, 4);
  memcpy(pNet->NetMask, (INT8U *)&Screen_Para.ETH_Para.Mask, 4);

  memcpy(pNet->PriDNS, (INT8U *)&Screen_Para.ETH_Para.IP, 4); 
  memcpy(pNet->SecDNS, (INT8U *)&Screen_Para.ETH_Para.IP, 4);
}

void Trans_Mac_Para(INT8U Mac[])
{
  memcpy(Mac, ETH_Mac_Para.Mac, sizeof(ETH_Mac_Para.Mac));
}

void Net_Init(void)
{
  Read_ETH_Mac_Para(); //读取mac参数

  Unselect_SPI_Device();
  SPI1_ENC28J60_Init();

  Trans_Mac_Para(own_hw_adr);

  //memcpy (own_hw_adr, (U8 *)mac_adr, 6);
  //memcpy (&localm[NETIF_ETH], (U8 *)&ip_config, sizeof(ip_config));
  init_TcpNet ();
  
  Trans_IP_Para(&localm[NETIF_ETH]);
  //memcpy (&localm[NETIF_ETH], (U8 *)&ip_config, sizeof(ip_config));
    
  Screen_Status.UDP_Soc = udp_get_socket (0, UDP_OPT_SEND_CS | UDP_OPT_CHK_CS, udp_callback);
  udp_open (Screen_Status.UDP_Soc, 8000);
}

//发送心跳数据
void Send_Heart_Beat(void)
{
    INT8U Temp[20];
	INT16U Len;
    INT8U *sendBuf;

    Len = Make_Frame(Temp + FDATA, 0, (INT8U *)&Screen_Para.COM_Para.Addr, C_HEART_BEAT,  0, 0, 0, (char *)Temp);	
    sendBuf = udp_get_buf (Len);

	if(sendBuf)
	{
	  memcpy(sendBuf, Temp, Len);
	  udp_send (Screen_Status.UDP_Soc, (INT8U *)&Screen_Para.ETH_Para.Serv_IP, Screen_Para.ETH_Para.Serv_Port, sendBuf, Len);
	}
}

void Net_Data_Proc(void)
{
  static S_Int32U Sec = {CHK_BYTE, 0xFFFFFFFF, CHK_BYTE};
  static S_Int16U Counts = {CHK_BYTE, 0xFFFE, CHK_BYTE}; //置一个较大数，上电就发送心跳

  if(Screen_Status.Rem_Data_Flag EQ REM_DATA_FLAG) //收到UDP数据了
  {
	if(Check_Frame_Format((INT8U *)RCV_DATA_BUF, Screen_Status.Rem_Data_Len))
    {
	  Set_Screen_Com_Time(COM_STANDBY_SEC); //到计时5s，5秒后重新播放节目
	  Rcv_Frame_Proc(CH_NET, (INT8U *)RCV_DATA_BUF, Screen_Status.Rem_Data_Len, sizeof(RCV_DATA_BUF));
	}
	//Send_Frame_Proc(CH_NET, (INT8U *)RCV_DATA_BUF, Screen_Status.Rem_Data_Len);

	Screen_Status.Rem_Data_Flag = 0;
	Screen_Status.Rem_Data_Len = 0;
  }

  if(Screen_Para.ETH_Para.Serv_En EQ 1) //使用服务器模式，需要定时向服务器发送心跳信息
  {
	  if(Sec.Var != Pub_Timer.Sec)
	  {
	    Sec.Var = Pub_Timer.Sec;
	    Counts.Var ++;
	
		if(Screen_Para.ETH_Para.Heart_Beat > 0 &&\
		   Counts.Var >= Screen_Para.ETH_Para.Heart_Beat &&\
		   Screen_Status.Com_Time EQ 0)
		{
		  Send_Heart_Beat(); //发送心跳
		  Counts.Var = 0;
		} 
	  }
  }
}

void Net_Para_Modi_Chk(void)
{
  if(Net_Para_Modi_Flag EQ NET_PARA_MODI_FLAG)
  {
    if(memcmp((INT8U *)&localm[NETIF_ETH].IpAdr, (INT8U *)&Screen_Para.ETH_Para.IP, 4) != 0 ||\
       memcmp((INT8U *)&localm[NETIF_ETH].DefGW, (INT8U *)&Screen_Para.ETH_Para.Gate, 4) != 0 ||\
       memcmp((INT8U *)&localm[NETIF_ETH].NetMask, (INT8U *)&Screen_Para.ETH_Para.Mask, 4) != 0 ||\
	   memcmp(own_hw_adr, ETH_Mac_Para.Mac, 6) != 0)
	{
		Net_Init();	
	}
	Net_Para_Modi_Flag = 0;
  }
}

/*
typedef struct
{
    //以太网
    INT32U IP; //IP地址
    //INT16U Port; //端口
    INT32U Mask; //子网掩码
    INT32U Gate; //网关
    INT8U Mode; //0固定ip方式，1自动获取方式

    INT8U Temp[20]; //保留30字节备用--升级程序时可以和老的兼容
}S_ETH_Para;
*/


void Net_Proc(void)
{
  static INT32U ms100Timer = 0xFFFFFFFF;

  if(ms100Timer != Pub_Timer.Ms100)
  {
    ms100Timer = Pub_Timer.Ms100;
    timer_tick();		  
  }

  Unselect_SPI_Device();								//Provide timer tick
  SPI1_ENC28J60_Init();
  Net_Para_Modi_Chk();
  poll_ether();
  //enc28j60Read(EPKTCNT);
  main_TcpNet ();								//Call the TCPnet library
  Net_Data_Proc();
}

//生成一个随机的mac地址
void Make_Mac_Para(INT8U Mac[])
{
  Mac[0] = Cur_Time.Time[T_SEC] + (((INT8U)Pub_Timer.Ms) << 6);
  Mac[1] = Cur_Time.Time[T_MIN] + (((INT8U)Pub_Timer.Ms100) << 6);
  Mac[2] = Cur_Time.Time[T_HOUR] + (((INT8U)Pub_Timer.Ms100_Counts) << 5);
  Mac[3] = Cur_Time.Time[T_DATE] + (((INT8U)Pub_Timer.Ms_Counts) << 5);
  Mac[4] = ((Cur_Time.Time[T_YEAR] - 10) << 4) + Cur_Time.Time[T_MONTH];
  Mac[5] = (INT8U)Pub_Timer.Ms;
}
#endif

