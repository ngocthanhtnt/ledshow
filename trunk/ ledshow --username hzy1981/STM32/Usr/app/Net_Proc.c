#define NET_PROC_C
#include "Includes.h"

#if NET_EN

extern U8 own_hw_adr[];
extern U8 lhost_name[];
extern LOCALM localm[];

/* The following definitions should be read out of EEPROM. */
U8 const mac_adr[6] = { 0,1,2,50,60,70 };
LOCALM const ip_config = {
  { 192,168,1,122 },             // IP address
  { 192,168,1,1 },               // Default Gateway
  { 255,255,255,0 },             // Net mask
  { 192,168,1,122 },              // Primary DNS server
  { 192,168,1,122 }               // Secondary DNS server
};
//U8 const DHCP_mode = 0;
U8 dev_name[16] = { "Keil_MCB" };


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

void Net_Init(void)
{
  Unselect_SPI_Device();
  SPI1_ENC28J60_Init();

  //U8 const DHCP_mode = 0;
  memcpy (own_hw_adr, (U8 *)mac_adr, 6);

  init_TcpNet ();
  
  //strcpy ((char *)&lhost_name, (char *)dev_name);
  memcpy (&localm[NETIF_ETH], (U8 *)&ip_config, sizeof(ip_config));

  Screen_Status.UDP_Soc = udp_get_socket (0, UDP_OPT_SEND_CS | UDP_OPT_CHK_CS, udp_callback);
  udp_open (Screen_Status.UDP_Soc, 8000);
}

void Net_Data_Proc(void)
{
  if(Screen_Status.Rem_Data_Flag EQ REM_DATA_FLAG) //收到UDP数据了
  {
    Set_Screen_Com_Time(COM_STANDBY_SEC); //到计时5s，5秒后重新播放节目
	
	//if(Check_Frame_Format((INT8U *)RCV_DATA_BUF, Screen_Status.Rem_Data_Len))
      //Rcv_Frame_Proc(CH_NET, (INT8U *)RCV_DATA_BUF, Screen_Status.Rem_Data_Len, sizeof(RCV_DATA_BUF));
	Send_Frame_Proc(CH_NET, (INT8U *)RCV_DATA_BUF, Screen_Status.Rem_Data_Len);

	Screen_Status.Rem_Data_Flag = 0;
	Screen_Status.Rem_Data_Len = 0;
  }
}

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
  poll_ether();
  //enc28j60Read(EPKTCNT);
  main_TcpNet ();								//Call the TCPnet library
  Net_Data_Proc();
}
#endif

