#define MAKE_PROTO_C
#include "makeProto.h"
#include "..\Includes.h"

#define PROTO_SHOW_DATA_LEN (BLOCK_DATA_LEN - 20)
/*
#define FLEN   0x01
#define FADDR  0x03
#define FSEQ   0x05
#define FSEQ0  0x06
#define FCTRL  0x07
#define FDATA  0x09

1	0x5A	帧头低字节
2	Len0	帧长度低字节(从帧头到帧尾)
3	Len1	帧长度高字节
4	Addr0	地址低字节,
5	Addr1	地址高字节
6	Seq	帧序号, 0-255 循环计数,重发的数据序号不变
7	Seq0	帧内序号,0-255 循环计数
8	Cmd0	命令码低字节
9	Cmd1	命令码高字节
10	…	帧数据域内容
        …
        CS0	校验码低字节,从帧头到CS0前一个字节的和
        CS1	校验码高字节
        0xAA	帧尾

      Cmd0定义:
0x01 屏长宽与颜色，可读可写
0x02 屏地址，可读可写
0x03 屏IP参数，可读可写
0x04 通信速率，可读可写
0x05 定时开关机，可读可写
0x06 当前时间，可读可写
0x07 亮度设置，可读可写
0x08 节目数设置，可读可写
0x09 节目属性设置，可读可写
0x0A 分区属性设置，可读可写
0x0B 屏信息(只读)
0x0C 固件升级

  Cmd1定义:
Bit0->Bit7 代表最低位到最高位
Bit2: 0 表示主站发出的命令帧，1表示从站发出的应答帧
Bit1: 0 表示正常应答帧，1表示异常应答帧
Bit0:0 表示无后续帧，1表示有后续帧
Bit3->Bit7 备用

 */
//生成一条帧
//data为数据域,dataLen数据域长度
//cmd控制码
//seq序列号
//pDst为目标缓冲区
int makeFrame(char *data, int dataLen, char cmd, char seq, char *pDst)
{
  int len;
  char type,cmd1 = 0;

  pDst[0] = FRAME_HEAD;//帧头

  memcpy(pDst + FADDR, &Screen_Para.Addr, 2); //地址

  if(seq != frameInfo.seq) //一条新的帧！
  {
      frameInfo.seq = seq;
      frameInfo.seq0 = 0;
      frameInfo.off = 0;
  }

  if(frameInfo.off >= dataLen)
      return 0;

  if(cmd EQ C_PROG_DATA) //控制码是显示数据则可能需要分帧
  {
    if(frameInfo.seq0 EQ 0) //第一帧全部是显示参数!!
    {
        frameInfo.len = 0;
        type = data[0];
        len = Get_Show_Para_Len(type); //第一帧长度
        frameInfo.seq0 ++;
        frameInfo.off = 0;
        if(dataLen > len)
            cmd1 |= 0x01;
    }
    else
    {
        if(frameInfo.off + PROTO_SHOW_DATA_LEN >= dataLen)
          len = dataLen - frameInfo.off; //后续帧长度
        else
        {
          len = PROTO_SHOW_DATA_LEN;
          cmd1 |= 0x01;
        }
    }
  }
  else
      len = dataLen;

  frameInfo.off += len;

  memcpy(pDst + FDATA, data + frameInfo.off, len);

  pDst[FSEQ] = frameInfo.seq;
  pDst[FSEQ0] = frameInfo.seq0;
  pDst[FCTRL] = cmd; //两个字节的控制码
  pDst[FCTRL + 1] = cmd1;

  len += F_NDATA_LEN; //数据域 + 非数据域 = 整个帧长
  memcpy(pDst + FLEN, &len, 2);

  INT16U sum = Sum_2Bytes((INT8U *)pDst, len - 3); //后3个字节是校验和和帧尾
  memcpy((char *)pDst + FLEN, (char *)&sum, 2);
  pDst[len - 1] = FRAME_TAIL;

  return len;
}

//生成协议数据
void makeProtoData()
{

}
