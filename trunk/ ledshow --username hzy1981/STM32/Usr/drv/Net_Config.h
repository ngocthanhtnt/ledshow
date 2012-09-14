/*----------------------------------------------------------------------------
 *      R T L  -  T C P N E T
 *----------------------------------------------------------------------------
 *      Name:    NET_CONFIG.H
 *      Purpose: Common TcpNet Definitions
 *      Rev.:    V3.50
 *----------------------------------------------------------------------------
 *      This code is part of the RealView Run-Time Library.
 *      Copyright (c) 2004-2009 KEIL - An ARM Company. All rights reserved.
 *---------------------------------------------------------------------------*/

#ifndef __NET_CONFIG_H__
#define __NET_CONFIG_H__

#include <RTL.h>

/*----------------------------------------------------------------------------
 *      General Data Types
 *---------------------------------------------------------------------------*/

#define SWAPB(w)        ((w>>8)|(w<<8)&0xFFFF)/* Swap-exchange Hi<->Lo Bytes */
#define HIB(w)          (U8)(w>>8)          /* Extract Hi byte of Word       */
#define LOB(w)          (U8)(w)             /* Extract Lo byte of Word       */

#define OS_HEADER_LEN   4         /* TcpNet 'os_frame' header size           */

/* Network Interfaces */
#define NETIF_ETH       0         /* Network interface: Ethernet             */
#define NETIF_PPP       1         /* Network interface: PPP                  */
#define NETIF_SLIP      2         /* Network interface: Slip                 */

/* Ethernet Defines */
#define ETH_ADRLEN      6         /* Ethernet Address Length in bytes        */
#define IP_ADRLEN       4         /* IP Address Length in bytes              */
                                  /* Frame Header length common for all      */
#define PHY_HEADER_LEN  (2*ETH_ADRLEN + 2) /* network interfaces.            */

#define ARP_HEADER_LEN  (2*(ETH_ADRLEN + IP_ADRLEN) + 8)
#define ETH_MTU         1514      /* Ethernet Frame Max Transfer Unit        */
#define HW_TYPE_ETH     0x0001    /* Hardware type: Ethernet                 */
#define ETH_PROT_IP     0x0800    /* Ethernet Protocol type: IP              */
#define ETH_PROT_ARP    0x0806    /* Ethernet Protocol type: ARP, RARP       */

/* PPP Defines */
#define PPP_ESC         0x7D      /* PPP ESC character                       */
#define PPP_FLAG        0x7E      /* PPP Start/Stop framing flag             */

#define PPP_MTU         1500      /* PPP Frame Max Transfer Unit             */
#define PPP_FRMOFS      (2*ETH_ADRLEN - 2)
#define PPP_HEADER_LEN  4         /* PPP Header Length                       */
#define PPP_PROT_LCP    0xC021    /* PPP Protocol type: LCP                  */
#define PPP_PROT_PAP    0xC023    /* PPP Protocol type: PAP                  */
#define PPP_PROT_CHAP   0xC223    /* PPP Protocol type: CHAP                 */
#define PPP_PROT_IPCP   0x8021    /* PPP Protocol type: IPCP                 */
#define PPP_PROT_IP     0x0021    /* PPP Protocol type: IP                   */

/* PPP-LCP Defines */
#define LCP_HEADER_LEN  4         /* LCP Header length                       */

#define LCP_CONF_RQ     1         /* LCP Configure-Request                   */
#define LCP_CONF_ACK    2         /* LCP Configure-Ack                       */
#define LCP_CONF_NAK    3         /* LCP Configure-Nak                       */
#define LCP_CONF_REJ    4         /* LCP Configure-Reject                    */
#define LCP_TERM_RQ     5         /* LCP Terminate-Request                   */
#define LCP_TERM_ACK    6         /* LCP Terminate-Ack                       */
#define LCP_CODE_REJ    7         /* LCP Code-Reject                         */
#define LCP_PROT_REJ    8         /* LCP Protocol-Reject                     */
#define LCP_ECHO_RQ     9         /* LCP Echo-Request                        */
#define LCP_ECHO_REP    10        /* LCP Echo-Reply                          */
#define LCP_DISC_RQ     11        /* LCP Discard-Request                     */

/* PPP-LCP Options */
#define LCP_OPT_MRU     1         /* LCP Opt: Maximum Receive Unit           */
#define LCP_OPT_ACCMAP  2         /* LCP Opt: Async Control Character Map    */
#define LCP_OPT_AUTHP   3         /* LCP Opt: Authentication Protocol        */
#define LCP_OPT_QUALP   4         /* LCP Opt: Quality Protocol               */
#define LCP_OPT_MAGIC   5         /* LCP Opt: Magic Number                   */
#define LCP_OPT_PROTC   7         /* LCP Opt: Protocol Field Compression     */
#define LCP_OPT_ADDRC   8         /* LCP Opt: Addr and Ctrl Field Comression */

/* PPP State Flags */
#define PPP_SYNC        0x01      /* Synchronized, HDLC open flag received   */
#define PPP_IS_ESC      0x02      /* Previous char received was ESC char     */
#define PPP_MALLOC      0x04      /* PPP memory buffer allocated             */
#define PPP_IS_FRAME    0x08      /* PPP valid frame received                */
#define PPP_TX_ESC      0x10      /* PPP transmit ESC character              */
#define PPP_PAP_AUTH    0x20      /* PPP PAP authent. start for client mode  */
#define PPP_LCP_CONF    0x40      /* PPP LCP config. start for client mode   */
#define PPP_IPCP_CONF   0x80      /* PPP IPCP config. start for client mode  */

/* PPP-PAP Defines */
#define PAP_HEADER_LEN  4         /* PAP Header length                       */

#define PAP_AUTH_RQ     1         /* PAP Authenticate request                */
#define PAP_AUTH_ACK    2         /* PAP Authenticate acknowledge            */
#define PAP_AUTH_NAK    3         /* PAP Authenticate Not acknowledge        */

/* PPP-IPCP Defines */
#define IPCP_HEADER_LEN 4         /* IPCP Header length                      */

#define IPCP_CONF_RQ    1         /* IPCP Configure-Request                  */
#define IPCP_CONF_ACK   2         /* IPCP Configure-Ack                      */
#define IPCP_CONF_NAK   3         /* IPCP Configure-Nak                      */
#define IPCP_CONF_REJ   4         /* IPCP Configure-Reject                   */
#define IPCP_TERM_RQ    5         /* IPCP Terminate-Request                  */
#define IPCP_TERM_ACK   6         /* IPCP Terminate-Ack                      */
#define IPCP_CODE_REJ   7         /* IPCP Code-Reject                        */

/* PPP-IPCP Options */
#define IPCP_OPT_IPADDRS 1        /* IPCP Opt: IP Addressess                 */
#define IPCP_OPT_IPCOMPR 2        /* IPCP Opt: IP Compression Protocol       */
#define IPCP_OPT_IPADDR  3        /* IPCP Opt: IP Address                    */

/* SLIP Defines */
#define SLIP_END        0xC0      /* SLIP end of packet                      */
#define SLIP_ESC        0xDB      /* SLIP escape characters (bit stuffing)   */
#define SLIP_ESC_END    0xDC      /* SLIP end data byte                      */
#define SLIP_ESC_ESC    0xDD      /* SLIP esc data byte                      */

#define SLIP_MTU        1500      /* SLIP Frame Max Transfer Unit            */
#define SLIP_FRMOFS     PHY_HEADER_LEN  /* SLIP frame offset                 */

/* SLIP State Flags */
#define SLIP_SYNC       0x01      /* Synchronized, Start of Packet received  */
#define SLIP_IS_ESC     0x02      /* Previous char received was ESC char     */
#define SLIP_MALLOC     0x04      /* PPP memory buffer allocated             */
#define SLIP_IS_FRAME   0x08      /* PPP valid frame received                */
#define SLIP_TX_ESC     0x10      /* PPP transmit ESC character              */

/* ARP, RARP Opcode for 'Operation Field' value */
#define ARP_RQ          0x0001    /* ARP Request opcode                      */
#define ARP_REP         0x0002    /* ARP Reply 'opcode                       */
#define RARP_RQ         0x0003    /* RARP Request opcode                     */
#define RARP_REP        0x0004    /* RARP Reply opcode                       */

/* ARP Info States  */
#define ARP_STATE_FREE     0      /* Unused entry (initial value)            */
#define ARP_STATE_RESERVED 1      /* Reserved entry (allocated)              */
#define ARP_STATE_PENDING  2      /* Entry is used but incomplete            */
#define ARP_STATE_RESOLVED 3      /* Resolved entry                          */
#define ARP_STATE_REFRESH  4      /* Entry is being refreshed                */

/* ARP Info Types   */
#define ARP_FIXED_IP    0         /* Fixed IP adrs is refreshed after tout   */
#define ARP_TEMP_IP     1         /* Temp adrs is removed after timeout      */

/* IP Defines */
#define IP_HEADER_LEN   20        /* IP Header Length in bytes               */
#define IP_OPT_LEN      40        /* Max IP Header option field length       */
#define IP_MAX_HLEN     (IP_HEADER_LEN + IP_OPT_LEN)
#define IP_DATA_OFS     (PHY_HEADER_LEN + IP_HEADER_LEN)

#define IP_DEF_VERHLEN  0x45      /* Default IP Version and Header Length    */
#define IP_NO_FRAGMENT  0x4000    /* Don't Fragment Flag                     */
#define IP_FRAGOFFMASK  0x1FFF    /* Fragment offset mask                    */
#define IP_MOREFRAGS    0x2000    /* More fragments Flag                     */

/* Protocol over IP */
#define IP_ICMP         0x01      /* ICMP over IP                            */
#define IP_IGMP         0x02      /* IGMP over IP                            */
#define IP_UDP          0x11      /* UDP over IP                             */
#define IP_TCP          0x06      /* TCP over IP                             */

/* ICMP Defines */
#define ICMP_HEADER_LEN 4         /* ICMP Header Length in bytes             */

/* ICMP message types */
#define ICMP_ECHO_REP   0         /* ICMP Echo Reply                         */
#define ICMP_ECHO_RQ    8         /* ICMP Echo Request                       */

/* IGMP Defines */
#define IGMP_HEADER_LEN 8         /* IGMP Header Length in bytes             */

/* IGMP Info States */
#define IGMP_STATE_NON   0        /* Non-Member - free Entry                 */
#define IGMP_STATE_DELAY 1        /* Delaying Member wait for Querry/Report  */
#define IGMP_STATE_IDLE  2        /* Idle Member of a group                  */

/* IGMP message types */
#define IGMP_MEM_QUERRY 0x11      /* IGMP Host Membership Querry (IGMPv1)    */
#define IGMP_MEM_REPORT 0x12      /* IGMP Host Membership Report (IGMPv1)    */

/* UDP Defines */
#define UDP_HEADER_LEN  8         /* UDP Header Length in bytes              */
#define UDP_DATA_OFS    (PHY_HEADER_LEN + IP_HEADER_LEN + UDP_HEADER_LEN)
#define UDP_MTU         (ETH_MTU - PHY_HEADER_LEN - IP_HEADER_LEN)

/* UDP Options */
#define UDP_OPT_SEND_CS 0x01      /* Calculate Checksum for UDP send frames  */
#define UDP_OPT_CHK_CS  0x02      /* Verify Checksum for received UDP frames */

/* UDP States */
#define UDP_STATE_FREE     0      /* Entry is free and unused                */
#define UDP_STATE_CLOSED   1      /* Entry allocated, socket still closed    */
#define UDP_STATE_OPENED   2      /* Socket opened for communication         */

/* TCP Defines */
#define TCP_HEADER_LEN  20        /* TCP Header Length in bytes              */
#define TCP_OPT_LEN     40        /* Max TCP Header option field length      */
#define TCP_MAX_HLEN    (TCP_HEADER_LEN + TCP_OPT_LEN)
#define TCP_DATA_OFS    (PHY_HEADER_LEN + IP_HEADER_LEN + TCP_HEADER_LEN)
#define TCP_TOS_NORMAL  0         /* TCP Type of Service                     */
#define TCP_MTU         1460      /* TCP default max. transfer unit          */
#define TCP_DEF_MSS     1460      /* TCP default max. segment size option    */
#define TCP_DEF_WINSIZE 4380      /* TCP default window size                 */

/* TCP Flags */
#define TCP_FLAG_URG    0x20      /* Urgent Pointer Field significant        */
#define TCP_FLAG_ACK    0x10      /* Acknowledgment field significant        */
#define TCP_FLAG_PSH    0x08      /* Push Function                           */
#define TCP_FLAG_RST    0x04      /* Reset the connection                    */
#define TCP_FLAG_SYN    0x02      /* Synchronize sequence numbers            */
#define TCP_FLAG_FIN    0x01      /* Finished, No more data from sender      */
#define TCP_FLAG_MASK   0x3F      /* Mask of all TCP Flags                   */

/* TCP Internal Flags */
#define TCP_IFLAG_CLOSING  0x01   /* Socket Close Pending                    */
#define TCP_IFLAG_SENDOPT  0x02   /* Send Max. Segment Size option           */
#define TCP_IFLAG_SPLIT    0x04   /* Split Frame Sent                        */
#define TCP_IFLAG_WINUPD   0x08   /* Window Size Update flag                 */

/* TCP States */
#define TCP_STATE_FREE     0      /* Entry is free and unused                */
#define TCP_STATE_CLOSED   1      /* Entry allocated, socket still closed    */
#define TCP_STATE_LISTEN   2      /* Socket waiting for incoming connection  */
#define TCP_STATE_SYN_REC  3      /* SYN frame received                      */
#define TCP_STATE_SYN_SENT 4      /* SYN packet sent to establish a connect. */
#define TCP_STATE_FINW1    5      /* Tcp_close started FIN packet was sent   */
#define TCP_STATE_FINW2    6      /* Our FIN ack-ed, waiting for remote FIN  */
#define TCP_STATE_CLOSING  7      /* Received FIN independently of our FIN   */
#define TCP_STATE_LAST_ACK 8      /* Waiting for last ACK for our FIN        */
#define TCP_STATE_TWAIT    9      /* Timed waiting for 2MSL                  */
#define TCP_STATE_CONNECT  10     /* TCP Connection established              */

/* TCP Socket Types */
#define TCP_TYPE_NONE      0x00   /* Socket type not assigned                */
#define TCP_TYPE_SERVER    0x01   /* Socket Type Server (open for listening) */
#define TCP_TYPE_CLIENT    0x02   /* Socket Type Client (initiate connect)   */
#define TCP_TYPE_DELAY_ACK 0x04   /* Socket Type Delayed Acknowledge         */
#define TCP_TYPE_FLOW_CTRL 0x08   /* Socket Type Flow Control                */
#define TCP_TYPE_CLIENT_SERVER (TCP_TYPE_SERVER | TCP_TYPE_CLIENT)
#define TCP_TYPE_MASK      0x0F   /* Mask for checking the Tcp Type          */

/* TCP Callback Events */
#define TCP_EVT_CONREQ     0      /* Connect request received event          */
#define TCP_EVT_CONNECT    1      /* Connection established event            */
#define TCP_EVT_CLOSE      2      /* Connection was properly closed          */
#define TCP_EVT_ABORT      3      /* Connection is for some reason aborted   */
#define TCP_EVT_ACK        4      /* Previously send data acknowledged       */
#define TCP_EVT_DATA       5      /* Data received event                     */

/* HTTP Defines */
#define HTTP_SERVER_PORT   80     /* HTTP Server standard port               */
#define HTTP_CGI_MAXLINE   120    /* HTTP CGI Script max. size of one line   */

/* HTTP States */
#define HTTP_STATE_IDLE     0     /* Session is free and unused              */
#define HTTP_STATE_ERROR    1     /* Error, session not initialized          */
#define HTTP_STATE_RESERVED 2     /* Reserved, session not activated         */
#define HTTP_STATE_ACTIVE   3     /* Active, waiting for GET or POST         */
#define HTTP_STATE_FILE     4     /* Sending file                            */
#define HTTP_STATE_CGI      5     /* Processiong CGI script file             */
#define HTTP_STATE_TEXT     6     /* Sending CGI generated data              */
#define HTTP_STATE_UNAUTH   7     /* Unauthorized access to Web Server       */
#define HTTP_STATE_UPLOAD   8     /* File upload with POST                   */
#define HTTP_STATE_NOTIMP   9     /* Not implemented request method          */

/* HTTP File Types */
#define HTTP_TYPE_HTML      0     /* File type: html text                    */
#define HTTP_TYPE_CGI       1     /* File type: cgi script                   */
#define HTTP_TYPE_CSS       2     /* File type: css style sheet              */
#define HTTP_TYPE_JAVA      3     /* File type: java script                  */
#define HTTP_TYPE_XML       4     /* File type: xml text                     */
#define HTTP_TYPE_XSLT      5     /* File type: xslt style sheet             */
#define HTTP_TYPE_GIF       6     /* File type: gif image                    */
#define HTTP_TYPE_JPEG      7     /* File type: jpeg image                   */
#define HTTP_TYPE_BMP       8     /* File type: bmp image                    */
#define HTTP_TYPE_PNG       9     /* File type: png image                    */
#define HTTP_TYPE_ICO       10    /* File type: icon image                   */
#define HTTP_TYPE_BIN       11    /* File type: binary stream                */
#define HTTP_TYPE_CGX       12    /* File type: cgi-xml script               */
#define HTTP_TYPE_XAP       13    /* File type: xap Silverlight application  */
#define HTTP_TYPE_XAML      14    /* File type: extended xml                 */

/* HTTP Internal Flags */
#define HTTP_FLAG_CGI      0x0001 /* Processing CGI Script file              */
#define HTTP_FLAG_HEADER   0x0002 /* HTTP Header has been sent               */
#define HTTP_FLAG_NOFILE   0x0004 /* Requested file not found.               */
#define HTTP_FLAG_CGIREP   0x0008 /* Repeat again CGI Script line            */
#define HTTP_FLAG_POSTWAIT 0x0010 /* Waiting for POST data for Netscape      */
#define HTTP_FLAG_NEXT     0x0020 /* Next CGI line already fetched           */
#define HTTP_FLAG_DFILE    0x0040 /* External Data File opened               */
#define HTTP_FLAG_SFILE    0x0080 /* External Script File opened             */
#define HTTP_FLAG_UFILE    0x0100 /* Upload File opened                      */
#define HTTP_FLAG_MULTI    0x0200 /* Multipart POST form data                */
#define HTTP_FLAG_HEADM    0x0400 /* HEAD method, send only HTTP headers     */

/* Telnet Defines */
#define TNET_SERVER_PORT   23     /* Telnet Server standard port             */
#define TNET_CMD_SE        240    /* End of Subnegotiation parameters        */
#define TNET_CMD_NOP       241    /* No Operation                            */
#define TNET_CMD_DMARK     242    /* Data Mark                               */
#define TNET_CMD_BREAK     243    /* NVT Character Break                     */
#define TNET_CMD_IP        244    /* Interrupt Process                       */
#define TNET_CMD_AO        245    /* Abort Output                            */
#define TNET_CMD_AYT       246    /* Are You There                           */
#define TNET_CMD_EC        247    /* Erase Character                         */
#define TNET_CMD_EL        248    /* Erase Line                              */
#define TNET_CMD_GA        249    /* Go Ahead                                */
#define TNET_CMD_SB        250    /* Subnegotiation Begin                    */
#define TNET_CMD_WILL      251    /* Telnet Command WILL                     */
#define TNET_CMD_WONT      252    /* Telnet Command WON'T                    */
#define TNET_CMD_DO        253    /* Telnet Command DO                       */
#define TNET_CMD_DONT      254    /* Telnet Command DON'T                    */
#define TNET_CMD_IAC       255    /* Telnet Command IAC                      */
#define TNET_OPT_ECHO      1      /* Telnet Option Echo                      */
#define TNET_OPT_SUPGOAH   3      /* Telnet Option Supress Go Ahead          */
#define TNET_OPT_STATUS    5      /* Telnet Option Status                    */
#define TNET_OPT_TMARK     6      /* Telnet Option Timing-Mark               */
#define TNET_OPT_TERMTYPE  24     /* Telnet Option Terminal Type             */
#define TNET_OPT_WINSIZE   31     /* Terminal Option window size             */
#define TNET_LBUFSZ        96     /* Command Line buffer size (bytes)        */
#define TNET_HISTSZ        128    /* Command History buffer size (bytes)     */
#define TNET_FIFOSZ        128    /* Input character Fifo buffer (bytes)     */
#define TNET_FIFOMSK       (TNET_FIFOSZ-1)

/* Telnet ASCII Key Codes */
#define ASCII_ESC          27     /* ESC ascii code                          */
#define ASCII_CTRLC        3      /* ^C ascii code                           */
#define ASCII_BS           8      /* Back Space                              */
#define ASCII_DEL          127    /* Delete Key                              */
#define ASCII_CR           13     /* Carriage Return, Enter key              */
#define ASCII_LF           10     /* Line Feed, New Line                     */

/* Telnet Local Key Codes */
#define TNET_KEY_UP        0x80   /* Cursor Up key code                      */
#define TNET_KEY_DOWN      0x81   /* Cursor Down key code                    */
#define TNET_KEY_RIGHT     0x82   /* Cursor Right key code                   */
#define TNET_KEY_LEFT      0x83   /* Cursor Left key code                    */

/* Telnet States */
#define TNET_STATE_IDLE      0    /* Session is free and unused              */
#define TNET_STATE_ERROR     1    /* Session Error, not initialized          */
#define TNET_STATE_RESERVED  2    /* Session reserved, not activated         */
#define TNET_STATE_ACTIVE    3    /* Session active                          */
#define TNET_STATE_NEGOTIATE 4    /* Connected, negotiate parameters         */
#define TNET_STATE_CONNECT   5    /* Connected, Send a header reply          */
#define TNET_STATE_AUTHUSER  6    /* User Authorization state                */
#define TNET_STATE_SENDING   7    /* Sending data in repeated loop           */

/* Telnet Flags */
#define TNET_FLAG_FIRST   0x01    /* First Telnet Header                     */
#define TNET_FLAG_WACK    0x02    /* Waiting for Data Acknowledge            */
#define TNET_FLAG_CLOSE   0x04    /* Telnet Session Close request            */
#define TNET_FLAG_PASSW   0x08    /* Password is not echoed back             */
#define TNET_FLAG_USEROK  0x10    /* Username valid                          */
#define TNET_FLAG_DELAY   0x20    /* Delay function is active                */

/* TFTP Defines */
#define TFTP_SERVER_PORT  69      /* TFTP Server standard port               */

/* TFTP States */
#define TFTP_STATE_IDLE   0       /* Session is idle                         */
#define TFTP_STATE_ACTIVE 1       /* Session is active                       */

/* TFTP Opcodes */
#define TFTP_OPCODE_RRQ   1       /* Packet is Read Request                  */
#define TFTP_OPCODE_WRQ   2       /* Packet is Write Request                 */
#define TFTP_OPCODE_DATA  3       /* Data Packet                             */
#define TFTP_OPCODE_ACK   4       /* ACK Packet                              */
#define TFTP_OPCODE_ERR   5       /* Error Packet                            */

/* TFTP Error codes */
#define TFTP_NOT_DEFINED       0  /* Not Definet Error                       */
#define TFTP_FILE_NOT_FOUND    1  /* File Not Found Error                    */
#define TFTP_ACCESS_VIOLATION  2  /* Access Violation Error                  */
#define TFTP_DISK_FULL         3  /* Disk Full Error                         */
#define TFTP_ILLEGAL_OPERATION 4  /* Not supported Opcode                    */
#define TFTP_FILE_EXIST        6  /* File Already Exists Error               */

/* TFTP Flags */
#define TFTP_FLAG_LASTB   0x01    /* Last block sent                         */


/* SMTP Defines */
#define SMTP_SERVER_PORT   25     /* BOOTP Server standard port              */

/* SMTP States */
#define SMTP_STATE_IDLE    0      /* SMTP Client is idle                     */
#define SMTP_STATE_ERROR   1      /* Error, not initialized                  */
#define SMTP_STATE_OPEN    2      /* User has requested sending email        */
#define SMTP_STATE_OPENED  3      /* TCP Socket Connected                    */
#define SMTP_STATE_EHLO    4      /* Send EHLO Command try ESMTP             */
#define SMTP_STATE_HELO    5      /* Send HELO Command for SMTP              */
#define SMTP_STATE_AUTH    6      /* ESMTP Authentication                    */
#define SMTP_STATE_USER    7      /* Send Username and Password              */
#define SMTP_STATE_HEADER  8      /* Send SMTP Header to server              */
#define SMTP_STATE_DATA    9      /* Send DATA Command to server             */
#define SMTP_STATE_MSGBODY 10     /* Send Message Body to server             */
#define SMTP_STATE_MSGEND  11     /* Send End Sequence to server             */
#define SMTP_STATE_QUIT    12     /* Send QUIT to server                     */
#define SMTP_STATE_DONE    13     /* Email send, close                       */

/* SMTP Flags */
#define SMTP_FLAG_WACK     0x01   /* Waiting for Data Acknowledge            */
#define SMTP_FLAG_RESP     0x02   /* Waiting for SMTP response               */
#define SMTP_FLAG_PASSW    0x04   /* Send a password to server               */
#define SMTP_FLAG_FROM     0x08   /* Header 'MAIL FROM:' sent to server      */
#define SMTP_FLAG_RCPT     0x10   /* Header 'RCPT TO:' sent to server        */
#define SMTP_FLAG_MSGHEAD  0x20   /* Message Header sent to server           */
#define SMTP_FLAG_ERROR    0x40   /* Error sending email                     */

/* SMTP Authentication Modes */
#define SMTP_AUTH_NONE     0      /* Authentication not required             */
#define SMTP_AUTH_PLAIN    1      /* Plain authentication type               */
#define SMTP_AUTH_LOGIN    2      /* Login authentication type               */
#define SMTP_AUTH_MD5      3      /* Digest-MD5 authentication type          */
#define SMTP_AUTH_CRAM_MD5 4      /* Cram-MD5 authentication type            */
#define SMTP_AUTH_NTLM     5      /* NTLM authentication type                */
#define SMTP_AUTH_UNKNOWN  6      /* Unknown authentication type             */

/* SMTP Callback Events */
#define SMTP_EVT_SUCCESS   0      /* Email successfully sent                 */
#define SMTP_EVT_TIMEOUT   1      /* Timeout sending email                   */
#define SMTP_EVT_ERROR     2      /* Error when sending email                */

/* SMTP server reply codes */
#define SMTP_RESP_READY    0      /* Server is ready                         */
#define SMTP_RESP_QUITOK   1      /* Service closing transmission Channel    */
#define SMTP_RESP_AUTHOK   2      /* User Authentication Success             */
#define SMTP_RESP_OK       3      /* Requested mail action ok, ready         */
#define SMTP_RESP_CONTINUE 4      /* Continue Request                        */
#define SMTP_RESP_DATAOK   5      /* Start mail input; end with <CRLF>.<CRLF>*/
#define SMTP_RESP_UNKNOWN  6      /* Unrecognised response                   */

/* NBNS Defines */
#define NBNS_SERVER_PORT   137    /* NBNS Server UDP port                    */
#define NBNS_CLIENT_PORT   137    /* NBNS Client UDP port                    */
#define NBNS_FLAGS_NQUERRY 0x0110 /* Name Querry Flags                       */
#define NBNS_FLAGS_NQURESP 0x8500 /* Name Querry Response No Errors          */

/* BOOTP Defines */
#define BOOTP_SERVER_PORT  67     /* BOOTP Server standard port              */
#define BOOTP_CLIENT_PORT  68     /* BOOTP Client standard port              */
#define BOOTP_REQ          1      /* BOOTP Request Opcode                    */
#define BOOTP_REPLY        2      /* BOOTP Reply Opcode                      */
#define BOOTP_FLG_UNICAST  0x0000 /* Flags - unicast message                 */
#define BOOTP_FLG_BROADC   0x8000 /* Flags - broadcast message               */
#define BOOTP_TRANS_ID     0xE20317E2 /* Transaction ID                      */
#define BOOTP_MAGIC_COOKIE 0x63825363 /* Magic Cookie                        */

/* BOOTP Options */
#define BOOTP_OPT_NETMASK  1      /* Subnet mask option BOOTP client         */
#define BOOTP_OPT_DEFGW    3      /* Default gateway option BOOTP client     */
#define BOOTP_OPT_END      0xFF   /* End of options marker                   */

/* BOOTP States */
#define BOOTP_STATE_DISABLED   0  /* BOOTP Client is disabled                */
#define BOOTP_STATE_ENABLED    1  /* BOOTP Client is enabled                 */
#define BOOTP_STATE_SEND_REQ   2  /* Send Request is required                */
#define BOOTP_STATE_REPLY_WAIT 4  /* BOOTP Client is waiting for reply       */
#define BOOTP_STATE_REPLY_GET  5  /* BOOTP Client has received reply         */

/* DHCP Defines */
#define DHCP_SERVER_PORT   67     /* DHCP Server standard port               */
#define DHCP_CLIENT_PORT   68     /* DHCP Client standard port               */

/* DHCP States */
#define DHCP_STATE_DISABLED    0  /* DHCP Client is disabled.                */
#define DHCP_STATE_INIT_REBOOT 1  /* DHCP Reboot, request existing IP        */
#define DHCP_STATE_REBOOTING   2  /* DHCP Client is rebooting                */
#define DHCP_STATE_INIT        3  /* Initialize DHCP Client, request new IP  */
#define DHCP_STATE_SELECTING   4  /* Select DHCP Server, get offer           */
#define DHCP_STATE_REQUESTING  5  /* Request sent, waiting for reply         */
#define DHCP_STATE_BOUND       6  /* IP address resolved and valid           */
#define DHCP_STATE_RENEWING    7  /* IP address will expire, renewing        */
#define DHCP_STATE_REBINDING   8  /* Renew failed, find HTTP Server, rebind  */

/* DHCP messages */
#define DHCP_DISCOVER      1      /* Choose an IP address for Client         */
#define DHCP_OFFER         2      /* Offer new IP address to Client          */
#define DHCP_REQUEST       3      /* Request an IP address for Client        */
#define DHCP_DECLINE       4      /* Reject offered IP address               */
#define DHCP_ACK           5      /* IP Address lease acknowledge            */
#define DHCP_NAK           6      /* Lease not acked, offer withdrawn        */
#define DHCP_RELEASE       7      /* Release Leased IP Address               */
#define DHCP_INFORM        8      /* Send DHCP Options to Client             */

/* DHCP options */
#define DHCP_OPT_PAD           0  /* Pad option used for aligning            */
#define DHCP_OPT_END           255/* End of valid information in vendor field*/
#define DHCP_OPT_SUBNET_MASK   1  /* Client's subnet mask                    */
#define DHCP_OPT_TIME_OFFSET   2  /* Client's subnet offset from UTC(seconds)*/
#define DHCP_OPT_ROUTER        3  /* Routers IP address in Client's subnet   */
#define DHCP_OPT_TIME_SERVER   4  /* Time servers available to the Client    */
#define DHCP_OPT_NAME_SERVER   5  /* Name servers available to the Client    */
#define DHCP_OPT_DNS_SERVER    6  /* DNS servers available to the Client     */
#define DHCP_OPT_HOST_NAME     12 /* Host Name of the Client                 */
#define DHCP_OPT_POP3_SERVER   70 /* POP3 servers available to the Client    */
#define DHCP_OPT_REQUESTED_IP  50 /* Client's requested IP Address           */
#define DHCP_OPT_LEASE_TIME    51 /* Lease Time for the IP Address           */
#define DHCP_OPT_OVERLOAD      52 /* Overload sname,file fields for options  */
#define DHCP_OPT_MSG_TYPE      53 /* DHCP Message Type option                */
#define DHCP_OPT_SERV_IDENT    54 /* DHCP Server's IP Address                */
#define DHCP_OPT_PARAM_REQUEST 55 /* Parameter Request List of options       */
#define DHCP_OPT_T1_VALUE      58 /* Renewal Time value option (T1)          */
#define DHCP_OPT_T2_VALUE      59 /* Rebinding Time value option (T2)        */
#define DHCP_OPT_CLIENT_IDENT  61 /* Client Identifier option                */

/* DNS defines */
#define DNS_SERVER_PORT   53      /* DNS Server UDP standard port            */
#define DNS_FLAGS_STQUER  0x0100  /* Name Querry Flags                       */

/* DNS States */
#define DNS_STATE_READY   0       /* DNS Ready, waiting for user request     */
#define DNS_STATE_BUSY    1       /* DNS Busy with resolving host IP         */
#define DNS_STATE_RESEND  2       /* Request timed out, resending            */

/* DNS user event codes */
#define DNS_EVT_SUCCESS   0       /* Host name successfully resolved         */
#define DNS_EVT_NONAME    1       /* DNS Error, no such name                 */
#define DNS_EVT_TIMEOUT   2       /* Timeout resolving host                  */
#define DNS_EVT_ERROR     3       /* Erroneous response packet               */

/* DNS 'get_host_by_name()' result codes */
#define DNS_RES_OK        0       /* Function finished OK                    */
#define DNS_ERROR_BUSY    1       /* DNS Client busy, can't process request  */
#define DNS_ERROR_LABEL   2       /* Host name Label too long                */
#define DNS_ERROR_NAME    3       /* Host name loo long                      */
#define DNS_ERROR_NOSRV   4       /* Prim. DNS server not specified (0.0.0.0)*/
#define DNS_ERROR_UDPSEND 5       /* UDP Send frame error                    */

/* Debug Module Definitions */
#define MEM               0       /* Dynamic Memory Module ID                */
#define ETH               1       /* Ethernet Module ID                      */
#define PPP               2       /* PPP Module ID                           */
#define SLIP              3       /* SLIP Module ID                          */
#define ARP               4       /* ARP Module ID                           */
#define IP                5       /* IP Module ID                            */
#define ICMP              6       /* ICMP Module ID                          */
#define IGMP              7       /* IGMP Module ID                          */
#define UDP               8       /* UDP Module ID                           */
#define TCP               9       /* TCP Module ID                           */
#define NBNS             10       /* NBNS Module ID                          */
#define DHCP             11       /* DHCP Module ID                          */
#define DNS              12       /* DNS Module ID                           */
#define APP              13       /* Application Modules ID                  */

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus               // EC++
extern "C"  {
#endif

typedef struct mem {              /* << Memory Pool management struct >>     */
   struct mem  *next;             /* Next Memory Block in the list           */
   U32    len;                    /* Length of following block               */
   U8     content[1];             /* Memory Block Data content               */
} MEMP;


typedef struct os_frame {         /* << TcpNet system frame buffer struct >> */
   U16 length;                    /* Total Length of data in frame           */
   U16 index;                     /* Buffer Position Index                   */
   U8  data[1];                   /* Buffer data (protocol headers + data)   */
} OS_FRAME;


typedef struct eth_header {       /* << Ethernet Header format >>            */
   U8  DestHwAdr[ETH_ADRLEN];     /* Ethernet destination hardware address   */
   U8  SrcHwAdr[ETH_ADRLEN];      /* Ethernet source hardware address        */
   U16 Prot;                      /* Protocol field of the Ethernet header.  */
   U8  Data[1];                   /* Frame data  46-1500 bytes               */
} ETH_HEADER;

#define ETH_FRAME(frame)        ((ETH_HEADER *)&frame->data[0])

typedef struct ppp_header {       /* << PPP Header format >>                 */
   U16 Fcs;                       /* PPP frame control checksum - appended   */
   U8  Unused[8];                 /* Unused array.                           */
   U8  Adr;                       /* PPP Address Field - usually 0xFF        */
   U8  Ctrl;                      /* PPP Control Field - usually 0x03        */
   U16 Prot;                      /* Protocol field of the PPP header        */
   U8  Data[1];                   /* Frame data  46-1500 bytes               */
} PPP_HEADER;

#define PPP_FRAME(frame)        ((PPP_HEADER *)&frame->data[0])

typedef struct lcp_header {       /* << LCP Header format >>                 */
   U8  Code;                      /* LCP Code field                          */
   U8  Id;                        /* Code identification                     */
   U16 Len;                       /* Code length                             */
} LCP_HEADER;

#define LCP_FRAME(frame)        ((LCP_HEADER *)&frame->data[PPP_FRMOFS+PPP_HEADER_LEN])

/* PPP-PAP Header is the same format as LCP */
#define PAP_HEADER        LCP_HEADER
#define PAP_FRAME         LCP_FRAME

/* PPP-IPCP Header is the same format as LCP */
#define IPCP_HEADER       LCP_HEADER
#define IPCP_FRAME        LCP_FRAME

/* PPP-CP Header - common header for PPP Control Protocols */
#define PPP_CP_FRAME      LCP_FRAME
#define PPP_CP_CODE_REJ   LCP_CODE_REJ
#define PPP_CP_PROT_REJ   LCP_PROT_REJ
#define PPP_CP_HEADER_LEN LCP_HEADER_LEN

typedef struct arp_header {       /* << ARP Header format >>                 */
   U16 HwAdrSpace;                /* Hardware Address Space                  */
   U16 ProtAdrSpace;              /* Protocol Address Space                  */
   U8  HwLen;                     /* MAC address len                         */
   U8  ProtLen;                   /* IP address length                       */
   U16 OpCode;                    /* ARP/RARP Opcode                         */
   U8  SrcHwAdr[ETH_ADRLEN];      /* Source Hardware Address                 */
   U8  SrcIpAdr[IP_ADRLEN];       /* Source IP Address                       */
   U8  DestHwAdr[ETH_ADRLEN];     /* Destination Hardware Address            */
   U8  DestIpAdr[IP_ADRLEN];      /* Destination IP Address                  */
} ARP_HEADER;

#define ARP_FRAME(frame)        ((ARP_HEADER *)&ETH_FRAME(frame)->Data[0])


typedef struct ip_header {        /* << IP Header format >>                  */
   U8  VerHLen;                   /* Version & Header Length field           */
   U8  Tos;                       /* Type Of Service field                   */
   U16 Len;                       /* Total Length of IP packet               */
   U16 Id;                        /* IP Identification number                */
   U16 FragOfs;                   /* IP Flags & Fragment offsett             */
   U8  Ttl;                       /* Time to live                            */
   U8  Prot;                      /* High level Protocol over IP             */
   U16 Chksum;                    /* IP Header Checksum                      */
   U8  SrcIpAdr[IP_ADRLEN];       /* Source IP address                       */
   U8  DestIpAdr[IP_ADRLEN];      /* Destination IP address                  */
} IP_HEADER;

#define IP_FRAME(frame)         ((IP_HEADER *)&ETH_FRAME(frame)->Data[0])


typedef struct icmp_header {      /* << ICMP Header format >>                */
   U8  Type;                      /* Type of the message                     */
   U8  Code;                      /* Message Code byte                       */
   U16 Chksum;                    /* Checksum of ICMP header                 */
   U8  Data[1];                   /* ICMP frame start of Data field          */
} ICMP_HEADER;


typedef struct igmp_header {      /* << IGMP Header format >>                */
   U8  VerType;                   /* Version & Type of the message           */
   U8  Unused;                    /* Unused field                            */
   U16 Chksum;                    /* Checksum of IGMP message                */
   U8  GrpIpAdr[IP_ADRLEN];       /* Group IP address                        */
} IGMP_HEADER;

#define IGMP_FRAME(frame)       ((IGMP_HEADER *)&frame->data[IP_DATA_OFS])

typedef struct udp_header {       /* << UDP Header format >>                 */
   U16 SrcPort;                   /* Source port                             */
   U16 DestPort;                  /* Destination port                        */
   U16 Len;                       /* Length of UDP frame                     */
   U16 Chksum;                    /* UDP frame checksum                      */
   U8  Data[1];                   /* UDP frame start of Data field           */
} UDP_HEADER;


typedef struct tcp_header {       /* << TCP Header format >>                 */
   U16 SrcPort;                   /* Source port                             */
   U16 DestPort;                  /* Destination port                        */
   U32 SeqNr;                     /* Frame Sequence Number                   */
   U32 AckNr;                     /* Frame Acknowledgment Number             */
   U8  HLen;                      /* Header Lenght of frame                  */
   U8  Flags;                     /* TCP Frame Flags                         */
   U16 Window;                    /* Size of Window                          */
   U16 Chksum;                    /* TCP frame checksum                      */
   U16 UrgentPtr;                 /* Urgent pointer                          */
} TCP_HEADER;


typedef struct nbns_header {      /* << NBNS Header Format >>                */
   U16 TransId;                   /* NBNS Transaction Id                     */
   U16 Flags;                     /* NBNS Frame Flags                        */
   U16 QdCount;                   /* Num.of entries in Question section      */
   U16 AnCount;                   /* Answer Name Count                       */
   U16 NsCount;                   /* Name Service Resource Record Count      */
   U16 ArCount;                   /* Name Service Additional Record Count    */
   U8  Data[1];                   /* Message Data Field starts here          */
} NBNS_HEADER;

#define NBNS_FRAME(buf)         ((NBNS_HEADER *)buf)
#define DNS_FRAME(buf)          ((NBNS_HEADER *)buf)


typedef struct arp_info {         /* << ARP Cache Entry info >>              */
   U8  State;                     /* ARP Cache entry current state           */
   U8  Type;                      /* Cache Entry type                        */
   U8  Retries;                   /* Number of Retries left                  */
   U8  Tout;                      /* Cache Entry Timeout                     */
   U8  HwAdr[ETH_ADRLEN];         /* Ethernet Hardware Address               */
   U8  IpAdr[IP_ADRLEN];          /* Ethernet IP Address                     */
} ARP_INFO;


typedef struct igmp_info {        /* << IGMP Group info >>                   */
   U8  State;                     /* Group membership current state          */
   U8  Tout;                      /* Timeout Timer for sending reports       */
   U8  GrpIpAdr[IP_ADRLEN];       /* Group IP address                        */
} IGMP_INFO;


typedef struct udp_info {         /* << UDP Socket info >>                   */
   U8  State;                     /* UDP Socket entry current state          */
   U8  McastTtl;                  /* MultiCast Time To Live                  */
   U16 LocPort;                   /* Local UDP port of Socket                */
   U8  Tos;                       /* UDP Type of Service                     */
   U8  Opt;                       /* UDP Socket Options                      */
                                  /* Application Event CallBack function     */
   U16 (*cb_func)(U8 socket, U8 *rem_ip, U16 port, U8 *buf, U16 len);
} UDP_INFO;


typedef struct tcp_info {         /* << TCP Socket info >>                   */
   U8  State;                     /* TCP Socket entry current state          */
   U8  Type;                      /* TCP Socket type                         */
   U8  Flags;                     /* State machine flags                     */
   U8  Tos;                       /* Type of service allocated               */
   U8  RemIpAdr[IP_ADRLEN];       /* Remote IP address                       */
   U16 RemPort;                   /* Remote TCP port                         */
   U16 LocPort;                   /* Local TCP port                          */
   U16 MaxSegSize;                /* Transmit Max. Segment Size              */
   U16 WinSize;                   /* Receive Window Size                     */
   U32 SendSeq;                   /* Current Send Sequence Number not acked  */
   U32 SendSeqNext;               /* Next Send Sequence Number               */
   U32 RecSeqNext;                /* Next Receive Sequence Number            */
   U16 Tout;                      /* Socket idle timeout (in seconds)        */
   U16 AliveTimer;                /* Keep Alive timer value                  */
   U16 RetryTimer;                /* Retransmission timer value              */
   U8  TxFlags;                   /* TCP Transmit Flags                      */
   U8  Retries;                   /* Number of retries left before aborting  */
   OS_FRAME *ReTransFrm;          /* Retransmission frame                    */
                                  /* Application Event-CallBack function     */
   U16 (*cb_func)(U8 socket, U8 event, U8 *p1, U16 p2);
} TCP_INFO;


typedef struct http_info {        /* << HTTP Session info >>                 */
   U8  State;                     /* HTTP Session current state              */
   U8  Socket;                    /* binded TCP Socket                       */
   U16 Flags;                     /* State machine Flags                     */
   U8  FType;                     /* File Type: html, jpeg, gif,...          */
   U8  PostSt;                    /* POST method Processing Status           */
   U8  DelimSz;                   /* Boundary delimiter size                 */
   U32 CGIvar;                    /* CGI session private variable (cgi_func) */
   U32 DLen;                      /* Data length (number of bytes to send)   */
   U32 Count;                     /* Total number of bytes sent              */
   U16 BCnt;                      /* Number of bytes sent in last packet     */
   U8  Lang[6];                   /* Selected Web Language: en-us, de, fr .. */
   U8 *Script;                    /* Script Buffer pointer                   */
   U8 *pDelim;                    /* Multipart Boundary delimiter value      */
   void *sFile;                   /* Script Interpreter File pointer         */
   void *dFile;                   /* Data File pointer                       */
} HTTP_INFO;


typedef struct http_file {        /* << HTTP File info >>                    */
   U8  Name[30];                  /* File Name                               */
   U8  *Start;                    /* File Start Address in ROM               */
   U32 Size;                      /* File Size in bytes                      */
} HTTP_FILE;


typedef struct http_ftype {       /* << HTTP File type >>                    */
   U8 ext[5];                     /* Finename Extension                      */
   U8 id;                         /* Internal Server Type id                 */
} HTTP_FTYPE;


typedef struct tnet_info {        /* << Telnet Session info >>               */
   U8  State;                     /* Telnet Session current state            */
   U8  Socket;                    /* binded TCP Socket                       */
   U8  Flags;                     /* State machine Flags                     */
   U8  BCnt;                      /* Received Data byte count                */
   U16 Tout;                      /* Timeout delay counter                   */
   U8  Widx;                      /* Fifo buffer Write index                 */
   U8  Ridx;                      /* Fifo buffer Read index                  */
   U32 SVar;                      /* Session private var. (tnet_process_cmd) */
   U8  LBuf[TNET_LBUFSZ];         /* Data Line Buffer                        */
   U8  Fifo[TNET_FIFOSZ];         /* Fifo Buffer for received line/keycodes  */
   U8  hNext;                     /* History command next position           */
   U8  hCurr;                     /* History command current position        */
   U8  Hist[TNET_HISTSZ];         /* Command History buffer                  */
} TNET_INFO;


typedef struct tftp_info {        /* << TFTP Session info >>                 */
   U8  State;                     /* TFTP Session current state              */
   U8  Retries;                   /* Number of retries                       */
   U8  Flags;                     /* State machine Flags                     */
   U16 Timer;                     /* Timeout Timer value                     */
   U8  RemIpAdr[IP_ADRLEN];       /* Remote IP address                       */
   U16 RemPort;                   /* Remote TCP port                         */
   U16 BlockNr;                   /* Block Number                            */
   void *File;                    /* File Handle pointer                     */
   U32 FPos;                      /* File Position indicator                 */
} TFTP_INFO;


typedef struct smtp_info {        /* << SMTP Session info >>                 */
   U8  State;                     /* SMTP Session current state              */
   U8  Socket;                    /* Binded TCP Socket                       */
   U8  Flags;                     /* State machine Flags                     */
   U8  Timer;                     /* Timeout Timer value                     */
   U8  SrvIpAdr[IP_ADRLEN];       /* SMTP Server IP address                  */
   U16 SrvPort;                   /* SMTP Server remote Port                 */
   U8  AuthMode;                  /* SMTP Authentication mode                */
   void (*notify)(U8 evt);        /* User callback status notify function    */
   U32 SVar;                      /* Session private var. (smtp_cbfunc)      */
} SMTP_INFO;


typedef struct smtp_resp {        /* << SMTP Response info >>                */
   U8 code[4];                    /* SMTP Response Code in ascii             */
   U8 id;                         /* Internal Server Response Code id        */
} SMTP_RESP;


typedef struct dns_info {         /* << DNS Cache Entry info >>              */
   U32 HostId;                    /* Host Id (CRC32 value of host name)      */
   U32 Ttl;                       /* Cache Entry Time To Live                */
   U8  IpAdr[IP_ADRLEN];          /* Ethernet IP Address                     */
} DNS_INFO;


typedef struct localm {           /* << Local Machine info >>                */
   U8 IpAdr[IP_ADRLEN];           /* Local IP Address                        */
   U8 DefGW[IP_ADRLEN];           /* Default GateWay                         */
   U8 NetMask[IP_ADRLEN];         /* Net Mask                                */
   U8 PriDNS[IP_ADRLEN];          /* Primary DNS Server                      */
   U8 SecDNS[IP_ADRLEN];          /* Secondary DNS Server                    */
} LOCALM;


typedef struct remotem {          /* << Remote Machine Info >>               */
   U8 IpAdr[IP_ADRLEN];           /* Remote IP address                       */
   U8 HwAdr[ETH_ADRLEN];          /* Remote Hardware Address                 */
} REMOTEM;


typedef enum {                    /* << Fatal System Error Codes >>          */
   ERR_MEM_ALLOC,
   ERR_MEM_FREE,
   ERR_MEM_CORRUPT,
   ERR_UDP_ALLOC,
   ERR_TCP_ALLOC,
   ERR_TCP_STATE
} ERROR_CODE;


/*----------------------------------------------------------------------------
 *      Functions
 *---------------------------------------------------------------------------*/

/* Net_Config.c */
extern void init_system (void);
extern void run_system (void);
extern void process_hl_igmp (OS_FRAME *frame);
extern void process_hl_udp (OS_FRAME *frame);
extern void process_hl_tcp (OS_FRAME *frame);
extern BOOL dispatch_frame (OS_FRAME *frame, U8 netif);
extern BOOL eth_chk_adr (OS_FRAME *frame);
extern U8  *eth_get_adr (U8 *ipadr);
extern void sys_error (ERROR_CODE code);

/* at_Mem.c */
extern OS_FRAME *alloc_mem (U32 byte_size);
extern void free_mem (OS_FRAME *mem_ptr);

/* at_Ethernet.c */
extern void init_eth_link (void);
extern void run_eth_link (void);
extern void put_in_queue (OS_FRAME *frame);
extern BOOL eth_send_frame (OS_FRAME *frame);

/* at_Ppp.c */
extern void init_ppp_link (void);
extern void run_ppp_link (void);
extern BOOL ppp_send_frame (OS_FRAME *frame, U16 prot);

/* at_Slip.c */
extern void init_slip_link (void);
extern void run_slip_link (void);
extern BOOL slip_send_frame (OS_FRAME *frame);

/* at_Lib.c */
extern int  mem_copy (void *dp, void *sp, int len);
extern void mem_rcopy (void *dp, void *sp, int len);
extern BOOL mem_comp (void *sp1, void *sp2, int len);
extern void mem_set (void *dp, U8 val, int len);
extern BOOL mem_test (void *sp, U8 val, int len);
extern BOOL str_scomp (U8 *sp, U8 const *cp);
extern int  str_copy (U8 *dp, U8 *sp);
extern void str_up_case (U8 *dp, U8 *sp);
extern U16  SwapB (U16 w16);
extern U16  get_u16 (U8 *p16);
extern U32  get_u32 (U8 *p32);
extern void set_u32 (U8 *p32, U32 val);

/* at_Igmp.c */
extern void init_igmp (void);
extern void run_igmp_host (void);
extern void process_igmp (OS_FRAME *frame);
extern BOOL igmp_is_member (U8 *ipadr);

/* at_Udp.c */
extern void init_udp (void);
extern void process_udp (OS_FRAME *frame);

/* at_Tcp.c */
extern void init_tcp (void);
extern void tcp_poll_sockets (void);
extern void process_tcp (OS_FRAME *frame_r);

/* at_Http.c */
extern void init_http (void);
extern void run_http_server (void);
extern void *http_fopen (U8 *name);
extern void http_fclose (void *file);
extern U16  http_fread (void *file, U8 *buf, U16 len);
extern BOOL http_fgets (void *file, U8 *buf, U16 size);
extern void cgi_process_var (U8 *qstr);
extern void cgi_process_data (U8 code, U8 *dat, U16 len);
extern U16  cgi_func (U8 *env, U8 *buf, U16 buflen, U32 *pcgi);
extern U8  *http_get_var (U8 *env, void *ansi, U16 maxlen);
extern U8  *http_get_lang (void);
extern void http_get_info (REMOTEM *info);
extern U8   http_get_session (void);

/* at_Telnet.c */
extern void init_tnet (void);
extern void run_tnet_server (void);
extern U16  tnet_cbfunc (U8 code, U8 *buf, U16 buflen);
extern U16  tnet_process_cmd (U8 *cmd, U8 *buf, U16 buflen, U32 *pvar);
extern BOOL tnet_ccmp (U8 *buf, U8 *cmd);
extern void tnet_set_delay (U16 cnt);
extern void tnet_get_info (REMOTEM *info);
extern U8   tnet_get_session (void);
extern BOOL tnet_msg_poll (U8 session);

/* at_Tftp.c */
extern void init_tftp (void);
extern void run_tftp_server (void);
extern void *tftp_fopen (U8 *fname, U8 *mode);
extern void tftp_fclose (void *file);
extern U16  tftp_fread (void *file, U32 fpos, U8 *buf);
extern U16  tftp_fwrite (void *file, U8 *buf, U16 len);

/* at_Bootp.c */
extern void init_bootp (void);
extern void bootp_client (void);

/* at_Dhcp.c */
extern void init_dhcp (void);
extern void run_dhcp_client (void);

/* at_Nbns.c */
extern void init_nbns (void);

/* at_Dns.c */
extern void init_dns (void);
extern void run_dns_client (void);
extern U8   get_host_by_name (U8 *hostn, void (*cbfunc)(U8, U8 *));

/* at_Smtp.c */
extern void init_smtp (void);
extern void run_smtp_client (void);
extern U16  smtp_cbfunc (U8 code, U8 *buf, U16 buflen, U32 *pvar);

/* Ethernet Device Driver */
extern void init_ethernet (void);
extern void send_frame (OS_FRAME *frame);
extern void poll_ethernet (void);
extern void int_enable_eth (void);
extern void int_disable_eth (void);

/* Serial Device Driver */
extern void init_serial (void);
extern int  com_getchar (void);
extern BOOL com_putchar (U8 c);
extern BOOL com_tx_active (void);

/* Modem Device Driver */
extern void init_modem (void);
extern void modem_dial (U8 *dialnum);
extern void modem_hangup (void);
extern void modem_listen (void);
extern BOOL modem_online (void);
extern BOOL modem_process (U8 ch);
extern void modem_run (void);

#ifdef __cplusplus               // EC++
}
#endif

/*----------------------------------------------------------------------------
 * end of file
 *---------------------------------------------------------------------------*/

#endif

