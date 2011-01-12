#define MAKE_PROTO_C
#include "makeProto.h"
#include "..\Includes.h"
#include <QSettings>
#include "screenProperty.h"
#include "mainwindow.h"

extern MainWindow *w;
extern QSettings settings;

#define PROTO_DATA_BUF_LEN (2000*1000)
#define PROTO_SHOW_DATA_LEN (BLOCK_DATA_LEN - 20)
/*
#define FLEN   0x01
#define FADDR  0x03
#define FSEQ   0x05
#define FSEQ0  0x06
#define FCMD  0x07
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

  memcpy(pDst + FADDR, &Screen_Para.Base_Para.Addr, 2); //地址

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
  pDst[FCMD] = cmd; //两个字节的控制码
  pDst[FCMD + 1] = cmd1;

  len += F_NDATA_LEN; //数据域 + 非数据域 = 整个帧长
  memcpy(pDst + FLEN, &len, 2);

  INT16U sum = Sum_2Bytes((INT8U *)pDst, len - 3); //后3个字节是校验和和帧尾
  memcpy((char *)pDst + FLEN, (char *)&sum, 2);
  pDst[len - 1] = FRAME_TAIL;

  return len;
}

//发送协议数据
//pFrame和len表示帧起始和帧长
//mode表示发送的模式，0表示串口，1表示u盘，2表示以太网
INT8U sendProtoData(char *pFrame, int len, int mode)
{
  return 1;
}

//获取文件参数
INT16U getFileParaFromSettings(QString fileStr, char *buf)
{
  return 1;
}

//生成协议数据
//screenStr屏幕参数的str,例如"screen/1/"表示第一个屏幕
//mode表示生成数据的方式：0表示串口传输，1表示生成u盘文件
INT8U makeProtoData(QString screenStr, int mode)
{
    S_Screen_Para screenPara;
    S_Prog_Para progPara;
    int len;
    INT8U seq = 0, progNum, areaNum, fileNum;
    char frameBuf[500], *dataBuf;

    //没有读取到正确的屏幕参数则返回0
    if(getScreenParaFromSettings(screenStr, screenPara) EQ 0)
        return 0;

    dataBuf = (char *)malloc(PROTO_DATA_BUF_LEN);

    //读取屏幕参数

    //设置屏幕基本参数
    len = makeFrame((char *)&screenPara.Base_Para, sizeof(screenPara.Base_Para),\
               C_SCREEN_BASE_PARA, seq++, frameBuf);
    sendProtoData(frameBuf, len, mode);

    //定时开关机时间
    len = makeFrame((char *)&screenPara.OC_Time, sizeof(screenPara.OC_Time),\
               C_SCREEN_OC_TIME, seq++, frameBuf);
    sendProtoData(frameBuf, len, mode);

    //亮度
    len = makeFrame((char *)&screenPara.Lightness, sizeof(screenPara.Lightness),\
               C_SCREEN_LIGNTNESS, seq++, frameBuf);
    sendProtoData(frameBuf, len, mode);

    //节目数
    settings.beginGroup(screenStr + "/program/");
    QStringList progList = settings.childGroups();
    settings.endGroup();
    progNum = progList.size();

    len = makeFrame((char *)&progNum, sizeof(progNum),\
               C_SCREEN_LIGNTNESS, seq++, frameBuf);
    sendProtoData(frameBuf, len, mode);

    QString progStr,areaStr, fileStr;

    for(int i = 0; i < progNum; i ++)
    {
        progStr = screenStr + "/program/" + progList.at(i);
        getProgParaFromSettings(progStr, progPara);

        //节目参数帧
        len = makeFrame((char *)&progPara.Head + 1, sizeof(progPara) - CHK_BYTE_LEN,C_PROG_PARA, seq++, frameBuf);
        sendProtoData(frameBuf, len, mode);

        settings.beginGroup(progStr + "/area/");
        QStringList areaList = settings.childGroups();
        settings.endGroup();

        areaNum = areaList.size();
        for(int j = 0; j < areaNum; j ++)
        {
            areaStr = progStr + "/area/" + areaList.at(j);

            settings.beginGroup(areaStr + "/file/");
            QStringList fileList = settings.childGroups();
            settings.endGroup();

            fileNum = fileList.size();
            for(int k = 0; k < fileNum; k ++)
            {
                fileStr = areaStr + "/file/" + fileList.at(k);
                len = getFileParaFromSettings(fileStr, dataBuf);

                while(1)
                {
                  len = makeFrame(dataBuf, len, C_PROG_DATA, seq, frameBuf);
                  if(len > 0)
                  {
                      sendProtoData(frameBuf, len, mode);
                  }
                  else
                  {
                      seq ++;
                      break;
                  }
                }
            }
        }
    }


    free(dataBuf);
}


