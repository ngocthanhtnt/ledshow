/*----------------------------------------------------------------------------
 *      RL-ARM - TCPnet
 *----------------------------------------------------------------------------
 *      Name:    NET_LIB.C
 *      Purpose: TCPnet System Configuration
 *      Rev.:    V4.22
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2011 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#pragma thumb
#pragma O3

/*----------------------------------------------------------------------------
 *      Library for Net_Config.c
 *---------------------------------------------------------------------------*/

#ifdef __NET_CONFIG__

#define TICK_RATE       (1000 / TICK_INTERVAL)

/* Some configuration error checking. */
#if !(SLIP_ENABLE || PPP_ENABLE || ETH_ENABLE)
 #error All network interfaces disabled in configuration
#endif

#if (SLIP_ENABLE && PPP_ENABLE)
 #error Both SLIP and PPP interfaces enabled
#endif

/* Check TCP Socket enable. */
#if (!TCP_ENABLE & (BSD_ENABLE | HTTP_ENABLE | TNET_ENABLE | FTP_ENABLE | SMTP_ENABLE))
 #error Application needs TCP Sockets enabled
#endif

/* Check UDP Socket enable */
#if (!UDP_ENABLE & (BSD_ENABLE | TFTP_ENABLE | DNS_ENABLE | SNMP_ENABLE | \
                    ((DHCP_ENABLE | NBNS_ENABLE) & ETH_ENABLE)))
 #error Application needs UDP Sockets enabled
#endif

/* Check number of TCP sockets available. */
#define __TCPNS    ((BSD_ENABLE  * BSD_NUMSOCKS)  +   \
                    (HTTP_ENABLE * HTTP_NUMSESS)  +   \
                    (TNET_ENABLE * TNET_NUMSESS)  +   \
                    (FTP_ENABLE  * FTP_NUMSESS*2) +   \
                    (SMTP_ENABLE * 1))

#if (__TCPNS > TCP_NUMSOCKS)
 #error Number of TCP Sockets too small
#endif

/* Check number of UDP sockets available. */
#define __UDPNS    ((BSD_ENABLE  * BSD_NUMSOCKS) +   \
                    (TFTP_ENABLE * TFTP_NUMSESS) +   \
                    (DNS_ENABLE  * 1)            +   \
                    (SNMP_ENABLE * 1)            +   \
                    ((DHCP_ENABLE + NBNS_ENABLE) * ETH_ENABLE))

#if (__UDPNS > UDP_NUMSOCKS)
 #error Number of UDP Sockets too small
#endif

/* Check BSD Server sockets */
#if (BSD_ENABLE && (BSD_SRVSOCKS > BSD_NUMSOCKS))
 #error Number of BSD Server sockets too large
#endif

/* Check BSD Hostname resolver */
#if (BSD_ENABLE && BSD_GETHOSTEN && !DNS_ENABLE)
 #error BSD Hostname resolver needs DNS enabled
#endif

/* Check PPP Authentication protocols */
#if (PPP_ENABLE && PPP_AUTHEN && !(PPP_PAPEN | PPP_CHAPEN))
 #error PPP Authentication needs PAP or/and CHAP enabled
#endif

/* Check Net_Config.c version */
#if (TNET_ENABLE && !defined(TNET_IDLETOUT))                     ||  \
    (FTP_ENABLE  && !defined(FTP_IDLETOUT))                      ||  \
    (PPP_ENABLE  && (defined(_ACCM1) || defined(LCP_MAXRETRY)))
 #error Net_Config.c too old, needs update
#endif

/* Non-Critical Net_Config.c upgrade */
#ifndef HTTP_SRVID
 #define HTTP_SRVID ""
#endif
#ifndef DHCP_VCID
 #define DHCP_VCID  ""
#endif
#ifndef DHCP_BOOTF
 #define DHCP_BOOTF 0
#endif

/* RTX environment */
#if (__RTX)
 #define __RTXENV   1
#else
 #define __RTXENV   0
#endif

/* Local Machine info */
LOCALM const nlocalm[3] = {
 /* Ethernet: Local IP address */
#if (ETH_ENABLE)
 {{_IP1,_IP2,_IP3,_IP4},
  /* Default Gateway IP address */
  {_GW1,_GW2,_GW3,_GW4},
  /* Subnet IP Mask */
  {_MSK1,_MSK2,_MSK3,_MSK4},
  /* Primary DNS Server IP */
  {_pDNS1,_pDNS2,_pDNS3,_pDNS4},
  /* Secondary DNS Server IP */
  {_sDNS1,_sDNS2,_sDNS3,_sDNS4}},
#else
 {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
#endif
 /* PPP: Local IP address */
#if (PPP_ENABLE)
 {{_IP1P,_IP2P,_IP3P,_IP4P},
  /* Default Gateway IP address */
  {0,0,0,0},
  /* Subnet IP Mask */
  {_MSK1P,_MSK2P,_MSK3P,_MSK4P},
  /* Primary DNS Server IP */
  {_pDNS1P,_pDNS2P,_pDNS3P,_pDNS4P},
  /* Secondary DNS Server IP */
  {_sDNS1P,_sDNS2P,_sDNS3P,_sDNS4P}},
#else
 {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
#endif
 /* SLIP: Local IP address */
#if (SLIP_ENABLE)
 {{_IP1S,_IP2S,_IP3S,_IP4S},
  /* Default Gateway IP address */
  {0,0,0,0},
  /* Subnet IP Mask */
  {_MSK1S,_MSK2S,_MSK3S,_MSK4S},
  /* Primary DNS Server IP */
  {_pDNS1S,_pDNS2S,_pDNS3S,_pDNS4S},
  /* Secondary DNS Server IP */
  {_sDNS1S,_sDNS2S,_sDNS3S,_sDNS4S}}
#else
 {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
#endif
};
/* System configuration */
static U32 mem_pool[MEM_SIZE];
static U8  lhost_name[16] = LHOST_NAME;
SYS_CFG sys_config = {
  mem_pool,
  sizeof (mem_pool),
  TICK_RATE,
  (PPP_GETIP<<5   | SLIP_DEFGW<<4 | PPP_DEFGW<<3 |
   SLIP_ENABLE<<2 | PPP_ENABLE<<1 | ETH_ENABLE),
  lhost_name
};
/* Ethernet network interface */
#if (ETH_ENABLE)
 static ARP_INFO arp_table[ARP_TABSIZE];
 U8     own_hw_adr[ETH_ADRLEN] = {_MAC1,_MAC2,_MAC3,_MAC4,_MAC5,_MAC6};
 ARP_CFG arp_config = {
   arp_table,
   ARP_TABSIZE,
   ARP_TIMEOUT,
   ARP_MAXRETRY,
   ARP_RESEND
 };
#endif
#if (PPP_ENABLE)
 PPP_CFG ppp_config = {
   PPP_ACCM,
   5 * TICK_RATE,
   PPP_RETRYTOUT * TICK_RATE,
   PPP_ECHOTOUT,
   PPP_MAXRETRY,
   ((PPP_CHAPEN << 1) | PPP_PAPEN) * PPP_AUTHEN
 };
#endif
#if (SLIP_ENABLE)
 U16 const slip_SerTout  = 5 * TICK_RATE;
#endif
#if (ETH_ENABLE && IGMP_ENABLE)
 static IGMP_INFO igmp_table[IGMP_TABSIZE];
 IGMP_CFG  igmp_config = {
   igmp_table,
   IGMP_TABSIZE,
   TICK_RATE / 5
 };
#endif
#if (ETH_ENABLE && DHCP_ENABLE)
 DHCP_CFG dhcp_config = {
   DHCP_VCID,
   DHCP_BOOTF
 };
#endif
#if (UDP_ENABLE)
 static UDP_INFO udp_scb[UDP_NUMSOCKS];
 UDP_CFG udp_config = {
   udp_scb,
   UDP_NUMSOCKS,
 };
#endif
#if (TCP_ENABLE)
 static TCP_INFO tcp_scb[TCP_NUMSOCKS+1];
 TCP_CFG tcp_config = {
   tcp_scb,
   TCP_NUMSOCKS,
   TCP_MAXRETRY,
   TCP_RETRYTOUT * TICK_RATE,
   (200 + TICK_INTERVAL - 1) / TICK_INTERVAL,
   TCP_SYN_RETRY_TOUT * TICK_RATE,
   TCP_INIT_RETRY_TOUT * TICK_RATE,
   TCP_DEFTOUT,
   TCP_CONRETRY
 };
#endif
#if (HTTP_ENABLE)
 static HTTP_INFO http_scb[HTTP_NUMSESS];
 static U8 http_passw[PASSW_SZ] = HTTP_AUTHPASSW;
 HTTP_CFG  http_config = {
   http_scb,
   HTTP_NUMSESS,
   HTTP_ENAUTH,
   HTTP_PORTNUM,
   HTTP_SRVID,
 #if (HTTP_ENAUTH)
   HTTP_AUTHREALM,
   HTTP_AUTHUSER,
   http_passw
 #else
   "","",""
 #endif
 };
#endif
#if (TNET_ENABLE)
 static TNET_INFO tnet_scb[TNET_NUMSESS];
 static U8 tnet_passw[PASSW_SZ] = TNET_AUTHPASSW;
 TNET_CFG  tnet_config = {
   tnet_scb,
   TNET_NUMSESS,
   TNET_ENAUTH,
   TNET_PORTNUM,
   TNET_IDLETOUT,
 #if (TNET_ENAUTH)
   TNET_AUTHUSER,
   tnet_passw
 #else
   "",""
 #endif
 };
#endif
#if (TFTP_ENABLE)
 static TFTP_INFO tftp_scb[TFTP_NUMSESS];
 TFTP_CFG tftp_config = {
   &tftp_scb[0],
   TFTP_NUMSESS,
   TFTP_MAXRETRY,
   TFTP_PORTNUM,
   TFTP_DEFTOUT
 };
#endif
#if (FTP_ENABLE)
 static FTP_INFO ftp_scb[FTP_NUMSESS];
 static U8 ftp_passw[PASSW_SZ] = FTP_AUTHPASSW;
 FTP_CFG ftp_config = {
   ftp_scb,
   FTP_NUMSESS,
   FTP_ENAUTH,
   FTP_PORTNUM,
   FTP_IDLETOUT,
 #if (FTP_ENAUTH)
   FTP_AUTHUSER,
   ftp_passw
 #else
   "",""
 #endif
 };
#endif
#if (DNS_ENABLE)
 static DNS_CACHE dns_table[DNS_TABSIZE];
DNS_CFG dns_config = {
   dns_table,
   DNS_TABSIZE
 };
#endif
#if (SMTP_ENABLE)
 U16 const smtp_DefTout  = SMTP_DEFTOUT;
#endif
#if (SNMP_ENABLE)
 SNMP_CFG snmp_config = {
   SNMP_PORTNUM,
   SNMP_TRAPPORT,
   { SNMP_TRAPIP1, SNMP_TRAPIP2, SNMP_TRAPIP3, SNMP_TRAPIP4 },
   SNMP_COMMUNITY,
   TICK_INTERVAL / 5
 };
#endif
#if (BSD_ENABLE) 
 static BSD_INFO bsd_scb[BSD_NUMSOCKS + BSD_SRVSOCKS];
 #ifdef __RTX
 static OS_MUT bsd_mutex;
 #endif
 BSD_CFG bsd_config = {
   bsd_scb,
   BSD_NUMSOCKS + BSD_SRVSOCKS,
   TICK_RATE / 5,
   BSD_RCVTOUT * TICK_RATE
 };
#endif

/*----------------------------------------------------------------------------
 *      Library Interface
 *---------------------------------------------------------------------------*/


/*--------------------------- init_system -----------------------------------*/

void init_system (void) {
  /* Initialize configured interfaces and applications. */

#if (ETH_ENABLE)
  eth_init_link ();
#endif
#if (PPP_ENABLE)
  ppp_init_link ();
#endif
#if (SLIP_ENABLE)
  slip_init_link ();
#endif

  icmp_init ();
#if (ETH_ENABLE && IGMP_ENABLE)
  igmp_init ();
#endif
#if (UDP_ENABLE)
  udp_init ();
#endif
#if (TCP_ENABLE)
  tcp_init ();
#endif
#if (BSD_ENABLE)
  bsd_init (__RTXENV);
 #if (BSD_GETHOSTEN)
  bsd_init_host (__RTXENV);
 #endif
#endif
#if (HTTP_ENABLE)
  http_init ();
#endif
#if (TNET_ENABLE)
  tnet_init ();
#endif
#if (TFTP_ENABLE)
  tftp_init ();
#endif
#if (FTP_ENABLE)
  ftp_init ();
#endif
#if (ETH_ENABLE && NBNS_ENABLE)
  nbns_init ();
#endif
#if (ETH_ENABLE && DHCP_ENABLE)
  dhcp_init ();
#elif (ETH_ENABLE)
  arp_notify ();
#endif
#if (DNS_ENABLE)
  dns_init ();
#endif
#if (SMTP_ENABLE)
  smtp_init ();
#endif
#if (SNMP_ENABLE)
  snmp_init ();
#endif

#if (BSD_ENABLE && __RTX)
  os_mut_init (bsd_mutex);
#endif
}


/*--------------------------- run_system ------------------------------------*/

void run_system (void) {
  /* Run configured interfaces and applications. */

#if (BSD_ENABLE && __RTX)
  os_mut_wait (bsd_mutex, 0xFFFF);
#endif

#if (ETH_ENABLE)
  eth_run_link ();
#endif
#if (PPP_ENABLE)
  ppp_run_link ();
#endif
#if (SLIP_ENABLE)
  slip_run_link ();
#endif

  icmp_run_engine ();
#if (ETH_ENABLE && IGMP_ENABLE)
  igmp_run_host ();
#endif
#if (TCP_ENABLE)
  tcp_poll_sockets ();
#endif
#if (BSD_ENABLE)
  bsd_poll_sockets ();
#endif
#if (HTTP_ENABLE)
  http_run_server ();
#endif
#if (TNET_ENABLE)
  tnet_run_server ();
#endif
#if (TFTP_ENABLE)
  tftp_run_server ();
#endif
#if (FTP_ENABLE)
  ftp_run_server ();
#endif
#if (ETH_ENABLE && DHCP_ENABLE)
  dhcp_run_client ();
#endif
#if (DNS_ENABLE)
  dns_run_client ();
#endif
#if (SMTP_ENABLE)
  smtp_run_client ();
#endif
#if (SNMP_ENABLE)
  snmp_run_agent ();
#endif

#if (BSD_ENABLE && __RTX)
  os_mut_release (bsd_mutex);
#endif
}


/*--------------------------- arp_notify ------------------------------------*/

#if (ETH_ENABLE && ARP_NOTIFY)
__used void arp_notify (void) {
  arp_send_req (0);
}
#endif


/*--------------------------- bsd_suspend/resume ----------------------------*/

#if (BSD_ENABLE && __RTX)
__used void bsd_suspend (U8 *tsk_id) {
  /* Suspend a socket owner task. */
  *tsk_id = (U8)os_tsk_self ();
  os_mut_release (bsd_mutex);
  os_evt_wait_or (0x8000, 0xFFFF);
  os_mut_wait (bsd_mutex, 0xFFFF);
}

__used void bsd_resume (U8 tsk_id) {
  /* Resume a task waiting for a socket event. */
  if (tsk_id) {
    os_evt_set (0x8000, tsk_id);
  }
}
#endif


/*--------------------------- bsd_lock/unlock -------------------------------*/

#if (BSD_ENABLE && __RTX)
__used void bsd_lock (void) {
  /* Acquire mutex - Lock TCPnet functions. */
  os_mut_wait (bsd_mutex, 0xFFFF);
}

__used void bsd_unlock (void) {
  /* Release mutex - Unlock TCPnet functions. */
  os_mut_release (bsd_mutex);
}
#endif


/*--------------------------- size optimization -----------------------------*/

#if !(ETH_ENABLE)
/* Empty functions when Ethernet Interface is disabled. */
BOOL eth_chk_adr (OS_FRAME *frame)   { return (__FALSE); }
U8  *eth_get_adr (U8 *ipadr)         { return (NULL); }
BOOL eth_send_frame (OS_FRAME *frame){ return (__FALSE); }
#endif

#if !(ETH_ENABLE && IGMP_ENABLE)
/* Empty functions when IP Multicasting is not enabled. */
BOOL igmp_is_member (U8 *ipadr)      { return (__FALSE); }
void igmp_process (OS_FRAME *frame)  { ; }
#endif

#if !(PPP_ENABLE)
/* Empty function when PPP Interface is disabled. */
BOOL ppp_send_frame (OS_FRAME *frame, U16 prot) { return (__FALSE); }
#endif

#if (PPP_ENABLE && !(PPP_AUTHEN && PPP_PAPEN))
/* Empty functions when PAP authentication not enabled. */
void pap_init (void)                 { ; }
void pap_run (void)                  { ; }
void pap_process (OS_FRAME *frame)   { ; }
#endif

#if (PPP_ENABLE && !(PPP_AUTHEN && PPP_CHAPEN))
/* Empty functions when CHAP authentication not enabled. */
void chap_init (void)                { ; }
void chap_run (void)                 { ; }
void chap_process (OS_FRAME *frame)  { ; }
#endif

#if !(SLIP_ENABLE)
/* Empty function when SLIP Interface is disabled. */
BOOL slip_send_frame (OS_FRAME *frame) { return (__FALSE); }
#endif

#if !(UDP_ENABLE)
/* Empty function when UDP socket not enabled. */
void udp_process (OS_FRAME *frame)   { ; }
#endif

#if !(TCP_ENABLE)
/* Empty function when TCP socket not enabled. */
void tcp_process (OS_FRAME *frame)   { ; }
#endif

#if (BSD_ENABLE && !__RTX)
/* Empty functions for non RTX environment. */
__used U8   bsd_wait   (BSD_INFO *bsd_s, U8 evt) { return (0);}
__used void bsd_enable (BSD_INFO *bsd_s, U8 evt) { ; }
#endif

#endif    /* __NET_CONFIG__ */


/*----------------------------------------------------------------------------
 *      Library for Net_Debug.c
 *---------------------------------------------------------------------------*/

#ifdef __NET_DEBUG__

/*--------------------------- __debug__ -------------------------------------*/

void __debug__ (U32 proc, const char *fmt, ...) {
  /* Print TCPnet Debug messages. */
  va_list args;

  switch (proc) {
    case MODULE_MEM:
      /* Memory Management Debug Messages */
#if (DBG_MEM > 1)
      printf ("MEM: ");
      break;
#else
      return;
#endif

    case MODULE_ETH:
      /* Ethernet Debug Messages */
#if (DBG_ETH > 1)
      printf ("ETH: ");
      break;
#else
      return;
#endif

    case MODULE_PPP:
      /* PPP Link Debug Messages */
#if (DBG_PPP > 1)
      printf ("PPP: ");
      break;
#else
      return;
#endif

    case MODULE_SLIP:
      /* SLIP Link Debug Messages */
#if (DBG_SLIP > 1)
      printf ("SLIP:");
      break;
#else
      return;
#endif

    case MODULE_ARP:
      /* ARP Debug Messages */
#if (DBG_ARP > 1)
      printf ("ARP: ");
      break;
#else
      return;
#endif

    case MODULE_IP:
      /* IP Debug Messages */
#if (DBG_IP > 1)
      printf ("IP : ");
      break;
#else
      return;
#endif

    case MODULE_ICMP:
      /* ICMP Debug Messages */
#if (DBG_ICMP > 1)
      printf ("ICMP:");
      break;
#else
      return;
#endif

    case MODULE_IGMP:
      /* IGMP Debug Messages */
#if (DBG_IGMP > 1)
      printf ("IGMP:");
      break;
#else
      return;
#endif

    case MODULE_UDP:
      /* UDP Debug Messages */
#if (DBG_UDP > 1)
      printf ("UDP: ");
      break;
#else
      return;
#endif

    case MODULE_TCP:
      /* TCP Debug Messages */
#if (DBG_TCP > 1)
      printf ("TCP: ");
      break;
#else
      return;
#endif

    case MODULE_NBNS:
      /* NBNS Debug Messages */
#if (DBG_NBNS > 1)
      printf ("NBNS:");
      break;
#else
      return;
#endif

    case MODULE_DHCP:
      /* DHCP Debug Messages */
#if (DBG_DHCP > 1)
      printf ("DHCP:");
      break;
#else
      return;
#endif

    case MODULE_DNS:
      /* DNS Debug Messages */
#if (DBG_DNS > 1)
      printf ("DNS: ");
      break;
#else
      return;
#endif

    case MODULE_SNMP:
      /* SNMP Debug Messages */
#if (DBG_SNMP > 1)
      printf ("SNMP:");
      break;
#else
      return;
#endif

    case MODULE_BSD:
      /* BSD Debug Messages */
#if (DBG_BSD > 1)
      printf ("BSD: ");
      break;
#else
      return;
#endif

    case MODULE_APP:
      /* TCPnet Application Debug Messages */
#if (DBG_APP > 1)
      break;
#else
      return;
#endif

  }
  va_start (args,fmt);
  vprintf (fmt,args);
  va_end (args);
}


/*--------------------------- __error__ -------------------------------------*/

void __error__ (U32 proc, const char *fmt, ...) {
  /* Print TCPnet Error messages. */
  va_list args;

  switch (proc) {
    case MODULE_MEM:
      /* Memory Management Error Messages */
#if (DBG_MEM > 0)
      printf ("MEM ERR: ");
      break;
#else
      return;
#endif

    case MODULE_ETH:
      /* Ethernet Error Messages */
#if (DBG_ETH > 0)
      printf ("ETH ERR: ");
      break;
#else
      return;
#endif

    case MODULE_PPP:
      /* PPP Link Debug Messages */
#if (DBG_PPP > 0)
      printf ("PPP ERR: ");
      break;
#else
      return;
#endif

    case MODULE_SLIP:
      /* SLIP Link Debug Messages */
#if (DBG_SLIP > 0)
      printf ("SLIP ERR:");
      break;
#else
      return;
#endif

    case MODULE_ARP:
      /* ARP Error Messages */
#if (DBG_ARP > 0)
      printf ("ARP ERR: ");
      break;
#else
      return;
#endif

    case MODULE_IP:
      /* IP Error Messages */
#if (DBG_IP > 0)
      printf ("IP ERR: ");
      break;
#else
      return;
#endif

    case MODULE_ICMP:
      /* ICMP Error Messages */
#if (DBG_ICMP > 0)
      printf ("ICMP ERR:");
      break;
#else
      return;
#endif

    case MODULE_IGMP:
      /* IGMP Error Messages */
#if (DBG_IGMP > 0)
      printf ("IGMP ERR:");
      break;
#else
      return;
#endif

    case MODULE_UDP:
      /* UDP Error Messages */
#if (DBG_UDP > 0)
      printf ("UDP ERR: ");
      break;
#else
      return;
#endif

    case MODULE_TCP:
      /* TCP Error Messages */
#if (DBG_TCP > 0)
      printf ("TCP ERR: ");
      break;
#else
      return;
#endif

    case MODULE_NBNS:
      /* NBNS Error Messages */
#if (DBG_NBNS > 0)
      printf ("NBNS ERR:");
      break;
#else
      return;
#endif

    case MODULE_DHCP:
      /* DHCP Error Messages */
#if (DBG_DHCP > 0)
      printf ("DHCP ERR:");
      break;
#else
      return;
#endif

    case MODULE_DNS:
      /* DNS Error Messages */
#if (DBG_DNS > 0)
      printf ("DNS ERR: ");
      break;
#else
      return;
#endif

    case MODULE_SNMP:
      /* SNMP Error Messages */
#if (DBG_SNMP > 0)
      printf ("SNMP ERR:");
      break;
#else
      return;
#endif

    case MODULE_BSD:
      /* BSD Error Messages */
#if (DBG_BSD > 0)
      printf ("BSD ERR: ");
      break;
#else
      return;
#endif

    case MODULE_APP:
      /* TCPnet Application Error Messages */
#if (DBG_APP > 0)
      break;
#else
      return;
#endif
  }
  va_start (args,fmt);
  vprintf (fmt,args);
  va_end (args);
}

#endif    /* __NET_DEBUG__ */


/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/
