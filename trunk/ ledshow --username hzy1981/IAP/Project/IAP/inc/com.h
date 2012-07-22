#ifndef COM_H
#define COM_H

#include "stm32f10x.h"

#undef EXT
#ifdef COM_C
#define EXT
#else
#define EXT extern
#endif

#define FRAME_HEAD 0x5A
#define FRAME_TAIL 0xAA
#define COM_BYTE 0x68

#define FHEAD  0x00 //帧头,1
#define FLEN   0x01 //帧长度,2
#define FADDR  0x03 //帧地址,2
#define FSEQ   0x05 //帧序号,1
#define FSEQ0  0x06 //帧内序号,2
#define FCMD   0x08 //命令码,2
#define FDATA  0x0A //数据域名

#define ASSERT_FAILED()

typedef struct
{
  uint8_t Head;

 uint8_t buf[5000];
 uint32_t posi;

  uint8_t Tail;
}S_Rcv_Buf;

EXT S_Rcv_Buf rcvBuf;

#endif
