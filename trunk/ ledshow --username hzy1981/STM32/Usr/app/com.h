#ifndef COM_H
#define COM_H

#include "Pub.h"
#include "LED_Cfg.h"

#undef EXT
#ifdef COM_C
#define EXT
#else
#define EXT extern
#endif

#define FRAME_HEAD 0x5A
#define FRAME_TAIL 0xAA
#define COM_BYTE 0x68

#define RD_CMD  0x00
#define WR_CMD  0x20

#define COM_STANDBY_SEC 3

//控制码高2位用来表达应答帧是肯定应答还是否定应答,0x40表示肯定应答,0x80表示否定应答
//第5位表示读还是写,1表示写,0表示读
//第0-5位表示控制码

//控制码定义
//#define C_SCREEN_WH   0x01 //屏幕宽高
//#define C_SCREEN_ADDR 0x02 //屏幕地址
//#define C_SCREEN_IP   0x03 //IP地址
//#define C_SCREEN_BAUD 0x04 //通信速率
#define C_SCREEN_BASE_PARA 0x00 //基本参数
#define C_SCREEN_COM_PARA 0x01 //串口通信参数
#define C_SCREEN_ETH_PARA 0x02 //以太网参数
#define C_SCREEN_GPRS_PARA 0x03 //GPRS参数
#define C_SCREEN_PARA    0x04 //整体屏幕参数
#define C_SCAN_PARA      0x05 //扫描参数
#define C_SCREEN_OC_TIME 0x06 //定时开关机时间
#define C_SCREEN_OC    0x07 //开关机
#define C_SCREEN_LIGNTNESS 0x08 //亮度
#define C_SCREEN_TIME 0x09 //时间
#define C_PROG_NUM    0x0A //节目数
#define C_PROG_PARA  0x0B //节目属性
#define C_PROG_DATA  0x0C //显示数据
#define C_SOFT_VERSION 0x0D //屏幕信息
#define C_SELF_TEST 0x0E //自动监测
#define C_UPDATE      0x0F //固件升级

#define CLOSE_FLAG 0x5A
#define OPEN_FLAG  0xA5

/*
0	0x5A	帧头
1	Len0	帧长度低字节(从帧头到帧尾)
2	Len1	帧长度高字节
3	Addr0	地址低字节
4       Addr1   地址高字节
5	Seq	帧序号, 0-255 循环计数,重发的数据序号不变
6       Seq00   帧内序号低字节
7       Seq01   帧内序号高字节
8	Cmd0	命令码低字节
9	Cmd1	命令码高字节
A	…	帧数据域内容
        …
        CS0	校验码低字节,从帧头到CS0前一个字节的和
        CS1	校验码高字节
        0xAA	帧尾
*/
#define FHEAD  0x00 //帧头,1
#define FLEN   0x01 //帧长度,2
#define FADDR  0x03 //帧地址,2
#define FSEQ   0x05 //帧序号,1
#define FSEQ0  0x06 //帧内序号,2
#define FCMD   0x08 //命令码,2
#define FDATA  0x0A //数据域名
//#define FTAIL  //帧尾巴

#define F_NDATA_LEN 13 //一条帧内非数据域的长度

#define SOFT_VERSION_LEN 30

#define FRAME_FLAG  0xAF

#define CH_COM  0x00
#define CH_GPRS  0x01
#define CH_NET 0x02
#define CH_UDISK  0x03 //UDisk不需要单独的Buf，可以使用 COM_BUF，就是串口通信的Buf
#define CH_SIM 0x04 //仿真
//#define RCV_BUF_NUM 1

#define READ_FLAG 0x00
#define SET_FLAG  0x01

#define COM_ERR_PARA_INVALID 0x01 //参数不合法
#define COM_ERR_PARA_LEN_ERR 0x02 //参数长度错误

#define RCV_DATA_BUF Screen_Status.Rcv_Data
/*
//通信接收数据的缓冲区
typedef struct
{
  INT8U Head;
  INT8U Flag; //是否收到一帧标志
  INT16U Posi; //当前存储位置
  INT8U Data[BLOCK_DATA_LEN];
  INT8U Tail;
}S_Rcv_Buf;

EXT S_Rcv_Buf Rcv_Buf;
*/
EXT void Send_Frame_Proc(INT8U Ch, INT8U Frame[], INT16U FrameLen);
EXT INT32U Get_Com_Baud(void);
EXT void Com_Rcv_Byte(INT8U Ch, INT8U Byte);
EXT INT8U Check_Frame_Format(INT8U Frame[], INT16U Frame_Len);
EXT INT8U Save_Prog_Para_Frame_Proc(INT8U Frame[],INT16U FrameLen);
EXT INT8U Save_Prog_Data_Frame_Proc(INT8U Frame[],INT16U FrameLen);
EXT INT8U Save_Screen_Para_Frame_Proc(INT16U Ctrl_Code, INT8U Data[], INT16U Len);
EXT void Clr_Rcv_Flag(void);
EXT INT16U Rcv_Frame_Proc(INT8U Ch, INT8U Frame[], INT16U FrameLen, INT16U Frame_Buf_Len);
EXT INT16U Make_Frame(INT8U *pData, INT16U Len, INT8U Addr[], INT8U Cmd, INT8U Cmd0, INT8U Seq, INT16U Seq0, char *pDst);
EXT void Screen_Com_Proc(void);
#endif
