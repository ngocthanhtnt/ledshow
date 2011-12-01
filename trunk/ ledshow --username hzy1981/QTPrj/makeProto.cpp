#define MAKE_PROTO_C
#include "..\Stm32\usr\app\includes.h"
#include "makeProto.h"
#include <QSettings>
#include <QImage>
#include "screenProperty.h"
#include "mainwindow.h"

extern MainWindow *w;
extern QSettings settings;

extern int linePosi[MAX_LINE_NUM];
extern int pagePosi[MAX_LINE_NUM];
S_Show_Data protoShowData;

S_Screen_Para comScreenPara; //通信参数

#define PROTO_DATA_BUF_LEN (2000*1000)
/*
    if(height % 8 EQ 0)
       tmpLen = width * height/ 8;
    else
       tmpLen = width * (height / 8 + 1);
*/
//#define BLOCK_SHOW_DATA_LEN (BLOCK_DATA_LEN - 20)

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
  INT16U seq0;
  char type,cmd1 = 0;

  pDst[0] = FRAME_HEAD;//帧头

  memcpy(pDst + FADDR, &Screen_Para.COM_Para.Addr, 2); //地址

  if(seq != frameInfo.seq) //一条新的帧！
  {
      frameInfo.seq = seq;
      frameInfo.seq0 = 0;
      frameInfo.off = 0;
  }

  if(dataLen >  0 && frameInfo.off >= dataLen)//>
      return 0;

  seq0 = frameInfo.seq0;
  if(cmd EQ (C_PROG_DATA | WR_CMD)) //控制码是显示数据则可能需要分帧
  {
    if(frameInfo.seq0 EQ 0) //第一帧全部是显示参数!!
    {
        frameInfo.len = 0;
        type = data[0];
        len = Get_Show_Para_Len(type); //第一帧长度

        frameInfo.off = 0;
        if(dataLen > len)
        {
            cmd1 |= 0x01;
            frameInfo.seq0 ++;//有后续帧
        }
    }
    else
    {
        if(frameInfo.off + BLOCK_SHOW_DATA_LEN >= dataLen)
        {
          len = dataLen - frameInfo.off; //后续帧长度
          frameInfo.seq0 = 0; //没有后续帧了
        }
        else
        {
          len = BLOCK_SHOW_DATA_LEN;
          cmd1 |= 0x01;
          frameInfo.seq0 ++; // 有后续帧
        }
    }
  }
  else
      len = dataLen;

  memcpy(pDst + FDATA, data + frameInfo.off, len);

  //数据域+33
  for(int i = 0; i < len; i ++)
      pDst[FDATA + i] += 0x33;

  frameInfo.off += len;

  pDst[FSEQ] = frameInfo.seq;
  memcpy(pDst + FSEQ0, &seq0, sizeof(seq0));
  //pDst[FSEQ0] = frameInfo.seq0;
  pDst[FCMD] = cmd; //两个字节的控制码
  pDst[FCMD + 1] = cmd1;

  len += F_NDATA_LEN; //数据域 + 非数据域 = 整个帧长
  memcpy(pDst + FLEN, &len, 2);

  INT16U sum = Sum_2Bytes((INT8U *)pDst, len - 3); //后3个字节是校验和和帧尾
  memcpy((char *)pDst + len - 3, (char *)&sum, 2);
  pDst[len - 1] = FRAME_TAIL;

  return len;
}

#if 0
//发送协议数据
//pFrame和len表示帧起始和帧长
//mode表示发送的模式，0表示串口，1表示u盘，2表示以太网
INT8U sendProtoData(char *pFrame, int len)
{
    int i = 0;

    INT8U mode = comScreenPara.Com_Mode;

    if(mode EQ PREVIEW_MODE)//预览模式
    {
      Rcv_Frame_Proc(CH_SIM, (INT8U *)pFrame, (INT16U)len); //接收函数处理。在仿真情况下，将参数写入了硬盘文件。模拟写入EEROM
    }
    else if(mode EQ SIM_MODE) //仿真模式
    {
      for(i = 0; i < len; i ++)
          Com_Rcv_Byte(CH_SIM, *(pFrame + i));
/*
      QTimer t;
      t.start();
      while(t.elapsed() < 250)
      {
          QCoreApplication::processEvents();
          usleep(10000);//sleep和usleep都已经obsolete，建议使用nanosleep代替 }

      }*/
    }
    else if(mode EQ COM_MODE)//串口通信模式
    {

    }
    else if(mode EQ ETH_MODE)//以太网模式
    {

    }
    else if(mode EQ GPRS_MODE)
    {

    }
    else if(mode EQ UDISK_MODE)
    {

    }

    return 1;
}
#endif

//获取文件参数
//width,height所在显示分区的宽度和高度
//fileStr文件的字符串
//buf目标数据缓冲区
int getFileParaFromSettings(INT8U Prog_No, INT8U Area_No, INT8U File_No, INT16U width, INT16U height, QString fileStr, char *buf, int bufLen)
{
    int type, tmpLen;
    U_File_Para filePara;
    S_Screen_Para screenParaBak;
    S_Prog_Para progParaBak;
    int len = 0;
    int borderHeight = 0;

    type = checkStrType(fileStr);

    saveScreenPara(screenParaBak);
    saveProgPara(progParaBak);

    memset(&filePara, 0, sizeof(filePara));

    //重置参数--
    resetShowPara(width, height, Screen_Para.Base_Para.Color);

    filePara.Pic_Para.Prog_No = Prog_No;
    filePara.Pic_Para.Area_No = Area_No;
    filePara.Pic_Para.File_No = File_No;


    getBorderParaFromeSettings(fileStr, filePara);

    if(filePara.Pic_Para.Border_Check > 0)
    {
        //INT8U Type = filePara.Pic_Para.Border_Type;
        borderHeight = Get_Simple_Border_Height(filePara.Pic_Para.Border_Type);//Simple_Border_Data[Type].Height;//Get_Area_Border_Height(Area_No);

        width = width - borderHeight*2;
        height = height - borderHeight*2;
    }

    //getBorderParaFromeSettings(fileStr, filePara);// 获取边框参数

    if(type EQ PIC_STEXT_PROPERTY || type EQ PIC_MTEXT_PROPERTY || type EQ PIC_TABLE_PROPERTY)
    {
      len = sizeof(S_Pic_Para) - CHK_BYTE_LEN; //真正的参数长度，不包括头尾校验

      settings.beginGroup(fileStr);
      settings.beginGroup("textEdit");
      QString picStr = settings.value("text").toString();
      settings.endGroup();

      bool smLineFlag;
      if(type EQ PIC_MTEXT_PROPERTY)
      {
          settings.beginGroup("smLine");
          smLineFlag = settings.value("smLineCheck").toBool();
          settings.endGroup();
      }
      else
          smLineFlag = false; //单行
      settings.endGroup();

      int moveFlag = checkSLineMoveLeftContinuous(fileStr);
      int lineNum,pageNum;
      QImage image;
      //整个文本的图形
      if(type EQ PIC_TABLE_PROPERTY)
      {
        image = getTableImage(width, height, picStr, &pageNum);
      }
      else
      {
          if(moveFlag != MOVE_LEFT_CONTINUOUS)
          {
              image = getTextImage(width, picStr, &lineNum, linePosi);
              //整体的行数
              pageNum = getTextPageNum(smLineFlag, moveFlag, image.height(), width, height, lineNum, linePosi, pagePosi);
          }
          else
          {
              pageNum = getSLineTextPageNum(picStr, width);
              //image = getSLineTextImage(picStr, width,height,page);
          }
      }
      getPicParaFromSettings(fileStr, filePara);
      filePara.Pic_Para.SNum = pageNum;
      memcpy(buf, (char *)&filePara.Pic_Para.Head + 1, sizeof(S_Pic_Para)); //前一个字节是头，不拷贝

      QImage imageBk;
      for(int i = 0; i < pageNum; i ++)
      {
          //获取每页的图像
          if(type EQ PIC_TABLE_PROPERTY)
          {
             imageBk = getTablePageImage(image, width, height, i);
          }
          else
          {
              if(moveFlag != MOVE_LEFT_CONTINUOUS)
                imageBk = getTextPageImage(smLineFlag, image, width, height, i, pagePosi);
              else
                imageBk = getSLineTextImage(picStr, width,height,i);
          }

          //获取的图形的宽度和高度应该和分区的宽度和高度一致
          if(imageBk.width() != width || imageBk.height() != height)
          {
              ASSERT_FAILED();
          }

           //转换图形数据到protoShowData中
          memset(protoShowData.Color_Data, 0, sizeof(protoShowData.Color_Data));
          //Set_Area_Border_Out(0);

          //Screen_Para.Base_Para.Width -=  2*borderHeight; //getTextShowData函数需要使用到屏幕宽度，高度等，因此需要重置改参数
          //Screen_Para.Base_Para.Height -= 2*borderHeight;

          resetShowPara(width, height, Screen_Para.Base_Para.Color);
          //imageBk.save("d:\\mkprotoimag.png");
          getTextShowData(imageBk, &protoShowData, 0, 0);

          //Screen_Para.Base_Para.Width +=  2*borderHeight;
          //Screen_Para.Base_Para.Height += 2*borderHeight;
/*
          if(height % 8 EQ 0)
             tmpLen = width * height/ 8;
          else
             tmpLen = width * (height / 8 + 1);
*/
          tmpLen = GET_TEXT_LEN(width, height);
          tmpLen = tmpLen * Get_Screen_Color_Num();
          if(len + tmpLen >= bufLen)
          {
              ASSERT_FAILED();
              return len;
          }

          memcpy(buf + len, protoShowData.Color_Data, tmpLen);
          len += tmpLen;
      }
    }
    else if(type EQ CLOCK_PROPERTY) //时钟
    {
        getClockParaFromSettings(fileStr, filePara);
        QImage image = getLineTextImage(fileStr);

        filePara.Clock_Para.Text_Width = image.size().width();
        filePara.Clock_Para.Text_Height = image.size().height();
        filePara.Clock_Para.SNum = 1;

        mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

        S_Point Point;
        Get_Clock_Text_Point(width, height, &filePara.Clock_Para, &Point);
        filePara.Clock_Para.Text_X = Point.X + borderHeight;
        filePara.Clock_Para.Text_Y = Point.Y + borderHeight;

        memcpy(buf, (char *)&filePara.Clock_Para.Head + 1, sizeof(S_Clock_Para)); //前一个字节是头，不拷贝
        len = sizeof(S_Clock_Para) - CHK_BYTE_LEN;

        resetShowPara(image.size().width(), image.size().height(), Screen_Para.Base_Para.Color);
        getTextShowData(image, &protoShowData, 0, 0);

        tmpLen = GET_TEXT_LEN(image.size().width(),image.size().height());
        tmpLen = tmpLen * Get_Screen_Color_Num();
        memcpy(buf + len, protoShowData.Color_Data, tmpLen);
        len +=tmpLen;
    }
    else if(type EQ LUN_PROPERTY) //农历
    {
        getLunParaFromSettings(fileStr, filePara);
        QImage image = getLineTextImage(fileStr);
        QSize size = image.size();

        filePara.Lun_Para.Text_Width = size.width();
        filePara.Lun_Para.Text_Height = size.height();
        filePara.Lun_Para.SNum = 1;

        mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

        S_Point P0;
        Get_Lun_Text_Point(0, width, height, P0);
        filePara.Lun_Para.Text_X = P0.X + borderHeight;
        filePara.Lun_Para.Text_Y = P0.Y + borderHeight;

        memcpy(buf, (char *)&filePara.Lun_Para.Head + 1, sizeof(S_Lun_Para)); //前一个字节是头，不拷贝
        len = sizeof(S_Lun_Para) - CHK_BYTE_LEN;

        resetShowPara(image.size().width(), image.size().height(), Screen_Para.Base_Para.Color);
        getTextShowData(image, &protoShowData, 0, 0);

        tmpLen = GET_TEXT_LEN(image.size().width(),image.size().height());
        tmpLen = tmpLen * Get_Screen_Color_Num();
        memcpy(buf + len, protoShowData.Color_Data, tmpLen);
        len +=tmpLen;

    }
    else if(type EQ TIME_PROPERTY) //时间
    {
        getTimeParaFromSettings(fileStr, filePara);
        QImage image = getLineTextImage(fileStr);
        QSize size = image.size();

        filePara.Time_Para.Text_Width = size.width();
        filePara.Time_Para.Text_Height = size.height();
        filePara.Time_Para.SNum = 1;

        mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

        S_Point P0;
        Get_Time_Text_Point(0, width, height, P0);
        filePara.Time_Para.Text_X = P0.X + borderHeight;
        filePara.Time_Para.Text_Y = P0.Y + borderHeight;
        memcpy(buf, (char *)&filePara.Time_Para.Head + 1, sizeof(S_Time_Para)); //前一个字节是头，不拷贝
        len = sizeof(S_Time_Para) - CHK_BYTE_LEN;

        resetShowPara(image.size().width(), image.size().height(), Screen_Para.Base_Para.Color);
        getTextShowData(image, &protoShowData, 0, 0);

        tmpLen = GET_TEXT_LEN(image.size().width(),image.size().height());
        tmpLen = tmpLen * Get_Screen_Color_Num();
        memcpy(buf + len, protoShowData.Color_Data, tmpLen);
        len +=tmpLen;
    }
    else if(type EQ TEMP_PROPERTY) //温度
    {
        getTempParaFromSettings(fileStr, filePara);
        QImage image = getLineTextImage(fileStr);
        QSize size = image.size();

        filePara.Temp_Para.Text_Width = size.width();
        filePara.Temp_Para.Text_Height = size.height();
        filePara.Temp_Para.SNum = 1;

        mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

        S_Point P0;
        Get_Temp_Text_Point(0, width, height, P0);
        filePara.Temp_Para.Text_X = P0.X + borderHeight;
        filePara.Temp_Para.Text_Y = P0.Y + borderHeight;
        memcpy(buf, (char *)&filePara.Temp_Para.Head + 1, sizeof(S_Temp_Para)); //前一个字节是头，不拷贝
        len = sizeof(S_Temp_Para) - CHK_BYTE_LEN;

        resetShowPara(image.size().width(), image.size().height(), Screen_Para.Base_Para.Color);
        getTextShowData(image, &protoShowData, 0, 0);

        tmpLen = GET_TEXT_LEN(image.size().width(),image.size().height());
        tmpLen = tmpLen * Get_Screen_Color_Num();
        memcpy(buf + len, protoShowData.Color_Data, tmpLen);
        len +=tmpLen;

    }
    else if(type EQ HUMIDITY_PROPERTY) //湿度
    {
        getHumidityParaFromSettings(fileStr, filePara);
        QImage image = getLineTextImage(fileStr);
        QSize size = image.size();

        filePara.Humidity_Para.Text_Width = size.width();
        filePara.Humidity_Para.Text_Height = size.height();
        filePara.Humidity_Para.SNum = 1;

        mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

        S_Point P0;
        Get_Humidity_Text_Point(0, width, height, P0);
        filePara.Humidity_Para.Text_X = P0.X + borderHeight;
        filePara.Humidity_Para.Text_Y = P0.Y + borderHeight;
        memcpy(buf, (char *)&filePara.Humidity_Para.Head + 1, sizeof(S_Humidity_Para)); //前一个字节是头，不拷贝
        len = sizeof(S_Humidity_Para) - CHK_BYTE_LEN;

        resetShowPara(image.size().width(), image.size().height(), Screen_Para.Base_Para.Color);
        getTextShowData(image, &protoShowData, 0, 0);

        tmpLen = GET_TEXT_LEN(image.size().width(),image.size().height());
        tmpLen = tmpLen * Get_Screen_Color_Num();
        memcpy(buf + len, protoShowData.Color_Data, tmpLen);
        len +=tmpLen;

    }
    else if(type EQ NOISE_PROPERTY) //噪音
    {
        getNoiseParaFromSettings(fileStr, filePara);
        QImage image = getLineTextImage(fileStr);
        QSize size = image.size();

        filePara.Noise_Para.Text_Width = size.width();
        filePara.Noise_Para.Text_Height = size.height();
        filePara.Noise_Para.SNum = 1;

        mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

        S_Point P0;
        Get_Noise_Text_Point(0, width, height, P0);
        filePara.Noise_Para.Text_X = P0.X + borderHeight;
        filePara.Noise_Para.Text_Y = P0.Y + borderHeight;
        memcpy(buf, (char *)&filePara.Noise_Para.Head + 1, sizeof(S_Noise_Para)); //前一个字节是头，不拷贝
        len = sizeof(S_Noise_Para) - CHK_BYTE_LEN;

        resetShowPara(image.size().width(), image.size().height(), Screen_Para.Base_Para.Color);
        getTextShowData(image, &protoShowData, 0, 0);

        tmpLen = GET_TEXT_LEN(image.size().width(),image.size().height());
        tmpLen = tmpLen * Get_Screen_Color_Num();
        memcpy(buf + len, protoShowData.Color_Data, tmpLen);
        len +=tmpLen;

    }
    else if(type EQ TIMER_PROPERTY) //计时
    {
        getTimerParaFromSettings(fileStr, filePara);
        QImage image = getLineTextImage(fileStr);
        QSize size = image.size();

        filePara.Timer_Para.Text_Width = size.width();
        filePara.Timer_Para.Text_Height = size.height();
        filePara.Timer_Para.SNum = 1;

        mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

        S_Point P0;
        Get_Timer_Text_Point(0, width, height, P0);
        filePara.Timer_Para.Text_X = P0.X + borderHeight;
        filePara.Timer_Para.Text_Y = P0.Y + borderHeight;
        memcpy(buf, (char *)&filePara.Timer_Para.Head + 1, sizeof(S_Timer_Para)); //前一个字节是头，不拷贝
        len = sizeof(S_Timer_Para) - CHK_BYTE_LEN;

        resetShowPara(image.size().width(), image.size().height(), Screen_Para.Base_Para.Color);
        getTextShowData(image, &protoShowData, 0, 0);

        tmpLen = GET_TEXT_LEN(image.size().width(),image.size().height());
        tmpLen = tmpLen * Get_Screen_Color_Num();
        memcpy(buf + len, protoShowData.Color_Data, tmpLen);
        len +=tmpLen;
    }
    else if(type EQ PIC_FLASH_PROPERTY)//动画
    {
        getFlashParaFromSettings(fileStr, filePara);
        filePara.Pic_Para.Flag = SHOW_PIC;

        int count = getFlashFrameCount(fileStr);
        //filePara.Pic_Para.SNum = count;

        memset(protoShowData.Color_Data, 0, sizeof(protoShowData.Color_Data));
        len = sizeof(S_Pic_Para) - CHK_BYTE_LEN;

        INT16U num = 0;

        if(filePara.Pic_Para.SNum > 0)
        {
            for(int i = 0; i < count; i += count / filePara.Pic_Para.SNum)
            {
            //Screen_Para.Base_Para.Width -=  2*borderHeight; //getTextShowData函数需要使用到屏幕宽度，高度等，因此需要重置改参数
            //Screen_Para.Base_Para.Height -= 2*borderHeight;

            resetShowPara(width, height, Screen_Para.Base_Para.Color);
            getFlashPageShowData(fileStr, i, &protoShowData, 0, borderHeight, borderHeight, width, height);

              //Screen_Para.Base_Para.Width +=  2*borderHeight; //getTextShowData函数需要使用到屏幕宽度，高度等，因此需要重置改参数
              //Screen_Para.Base_Para.Height += 2*borderHeight;
              tmpLen = GET_TEXT_LEN(width, height);
              tmpLen = tmpLen * Get_Screen_Color_Num();
              if(len + tmpLen >= bufLen)
              {
                  filePara.Pic_Para.SNum = num;
                  memcpy(buf, (char *)&filePara.Pic_Para.Head + 1, sizeof(S_Pic_Para) - CHK_BYTE_LEN); //前一个字节是头，不拷贝

                  ASSERT_FAILED();
                  return len;
              }
              num ++;

              memcpy(buf + len, protoShowData.Color_Data, tmpLen);
              len += tmpLen;

              if(num>=filePara.Pic_Para.SNum)
                  break;
            }
        }

        filePara.Pic_Para.SNum = num;
        memcpy(buf, (char *)&filePara.Pic_Para.Head + 1, sizeof(S_Pic_Para) - CHK_BYTE_LEN); //前一个字节是头，不拷贝

    }
  else if(type EQ PIC_IMAGE_PROPERTY) //图片
    {
      getImageParaFromSettings(fileStr, filePara);
      filePara.Pic_Para.Flag = SHOW_PIC;

      //int count = getFlashFrameCount(fileStr);
      //filePara.Pic_Para.SNum = count;

      len = sizeof(S_Pic_Para) - CHK_BYTE_LEN;

      memset(protoShowData.Color_Data, 0, sizeof(protoShowData.Color_Data));

      //Screen_Para.Base_Para.Width -=  2*borderHeight; //getTextShowData函数需要使用到屏幕宽度，高度等，因此需要重置改参数
      //Screen_Para.Base_Para.Height -= 2*borderHeight;

    resetShowPara(width, height, Screen_Para.Base_Para.Color);
    getImagePageShowData(fileStr, 0, &protoShowData, 0, 0, 0, width, height);

    //Screen_Para.Base_Para.Width +=  2*borderHeight;
    //Screen_Para.Base_Para.Height += 2*borderHeight;
    tmpLen = GET_TEXT_LEN(width, height);
    tmpLen = tmpLen * Get_Screen_Color_Num();

    memcpy(buf + len, protoShowData.Color_Data, tmpLen);
    len += tmpLen;

      filePara.Pic_Para.SNum = 1;
      memcpy(buf, (char *)&filePara.Pic_Para.Head + 1, sizeof(S_Pic_Para) - CHK_BYTE_LEN); //前一个字节是头，不拷贝

  }

    restoreScreenPara(screenParaBak);
    restoreProgPara(progParaBak);

    return len;
}

//生成协议数据到fileName
INT16U _makeProtoData(QString fileName, QString screenStr, int flag, char buf[], int bufLen)
{
    FILE *file;
    INT16U counts = 0;
    S_Prog_Para progPara;
    int len;
    INT16U areaWidth, areaHeight;
    INT8U seq = 0, progNum, areaNum, fileNum;
    char frameBuf[MAX_COM_BUF_LEN + 20], *dataBuf;
    S_Screen_Para screenParaBak;
    S_Prog_Para progParaBak;
    S_Card_Para cardParaBak;

    seq = frameInfo.seq + 1;//= 0xFF;

    file = fopen(fileName.toLocal8Bit(), "wb+");
    if(file EQ (FILE *)0)
    {
        ASSERT_FAILED();
        return 0;
    }

    fseek(file, 0, SEEK_SET);

    //直接发送数据,不从配置文件中获取
    if(flag EQ 0)
    {
        counts++;
        fwrite(buf, bufLen, 1, file);

        fclose(file);

        return counts;
    }

    saveScreenPara(screenParaBak);
    saveProgPara(progParaBak);
    saveCardPara(cardParaBak);

    //读取屏幕参数和控制卡参数
    //没有读取到正确的屏幕参数则返回0
    if(getScreenCardParaFromSettings(screenStr, Screen_Para, Card_Para) EQ 0)
    {
        ASSERT_FAILED();

        restoreScreenPara(screenParaBak);
        restoreProgPara(progParaBak);
        restoreCardPara(cardParaBak);

        fclose(file);

        return counts;
    }

    Calc_Screen_Color_Num();
    dataBuf = (char *)malloc(PROTO_DATA_BUF_LEN);
    //读取屏幕参数
    //预览模式或者仿真模式需要写屏幕参数到本地文件
    //if(mode EQ PREVIEW_MODE || mode EQ SIM_MODE)
    {
        //设置屏幕参数
        if(GET_BIT(flag, C_SCREEN_PARA))
        {
            len = makeFrame((char *)&Screen_Para.Base_Para, sizeof(Screen_Para) - CHK_BYTE_LEN,\
                       C_SCREEN_PARA | WR_CMD, seq++, frameBuf);
            counts++;
            fwrite(frameBuf, len, 1, file);
        }

        //串口通信参数
        if(GET_BIT(flag, C_SCREEN_COM_PARA))
        {
            len = makeFrame((char *)&Screen_Para.COM_Para, sizeof(Screen_Para.COM_Para),\
                       C_SCREEN_COM_PARA | WR_CMD, seq++, frameBuf);
            counts++;
            fwrite(frameBuf, len, 1, file);
        }

        //设置屏幕基本参数
        if(GET_BIT(flag, C_SCREEN_BASE_PARA))
        {
            len = makeFrame((char *)&Screen_Para.Base_Para, sizeof(Screen_Para.Base_Para),\
                       C_SCREEN_BASE_PARA | WR_CMD, seq++, frameBuf);
            counts++;
            fwrite(frameBuf, len, 1, file);
        }
        //扫描参数
        if(GET_BIT(flag, C_SCAN_PARA))
        {
            len = makeFrame((char *)&Screen_Para.Scan_Para, sizeof(Screen_Para.Scan_Para),\
                       C_SCAN_PARA | WR_CMD, seq++, frameBuf);
            counts++;
            fwrite(frameBuf, len, 1, file);
       }
    }


    //定时开关机时间
    if(GET_BIT(flag, C_SCREEN_OC_TIME))
    {
        len = makeFrame((char *)&Screen_Para.OC_Time, sizeof(Screen_Para.OC_Time),\
                   C_SCREEN_OC_TIME | WR_CMD, seq++, frameBuf);
        counts++;
        fwrite(frameBuf, len, 1, file);
    }

    //亮度
    if(GET_BIT(flag, C_SCREEN_LIGNTNESS))
    {
        len = makeFrame((char *)&Screen_Para.Lightness, sizeof(Screen_Para.Lightness),\
                   C_SCREEN_LIGNTNESS | WR_CMD, seq++, frameBuf);
        counts++;
        fwrite(frameBuf, len, 1, file);
    }

    //节目数

    //settings.beginGroup(screenStr + "/program/");
    //QStringList progList = getSettingsCheckedSubList();//settings.childGroups();
    //settings.endGroup();

    QStringList progList = getSettingsCheckedSubList(screenStr + "/program/");

    progNum = progList.size();
    debug("prog num = %d", progNum);

    if(GET_BIT(flag, C_PROG_DATA))
    {
      len = makeFrame((char *)&progNum, sizeof(progNum),\
               C_PROG_NUM | WR_CMD, seq++, frameBuf);
      counts++;
      fwrite(frameBuf, len, 1, file);
    }

    //节目数据
    if(GET_BIT(flag, C_PROG_DATA))
    {
        QString progStr,areaStr, fileStr;

        for(int i = 0; i < progNum; i ++)
        {
            //节目字符串
            progStr = screenStr + "/program/" + progList.at(i);
            //获取节目参数
            getProgParaFromSettings(progStr, progPara);
            progPara.Prog_No = i;
            //节目参数帧
            len = makeFrame((char *)&progPara.Head + 1, sizeof(progPara) - CHK_BYTE_LEN,C_PROG_PARA | WR_CMD, seq++, frameBuf);
            counts++;
            fwrite(frameBuf, len, 1, file);

            //settings.beginGroup(progStr + "/area/");
            QStringList areaList = getSettingsCheckedSubList(progStr + "/area/");//settings.childGroups();
            //settings.endGroup();

            areaNum = areaList.size();
            for(int j = 0; j < areaNum; j ++)
            {
                areaStr = progStr + "/area/" + areaList.at(j);

                //分区宽度和高度
                settings.beginGroup(areaStr);
                areaWidth = settings.value("width").toInt();
                areaHeight = settings.value("height").toInt();
                settings.endGroup();

                //文件列表
                //settings.beginGroup(areaStr + "/file/");
                QStringList fileList = getSettingsCheckedSubList(areaStr + "/file/");//settings.childGroups();
                //settings.endGroup();

                fileNum = fileList.size();
                for(int k = 0; k < fileNum; k ++)
                {
                    fileStr = areaStr + "/file/" + fileList.at(k);
                    len = getFileParaFromSettings(i,j,k,areaWidth, areaHeight, fileStr, dataBuf, PROTO_DATA_BUF_LEN);

                    while(1)
                    {
                      //节目显示数据帧
                      int tmpLen = makeFrame(dataBuf, len, C_PROG_DATA | WR_CMD, seq, frameBuf);
                      if(tmpLen > 0)
                      {
                          counts++;
                          fwrite(frameBuf, tmpLen, 1, file);
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
    }

    free(dataBuf);

    fclose(file);

    restoreScreenPara(screenParaBak);
    restoreProgPara(progParaBak);
    restoreCardPara(cardParaBak);

    return counts;

}

//生成协议数据,数据源不从settings中取，而是直接从buf中获得
INT8U makeProtoBufData(QString screenStr, int mode, INT8U cmd , char buf[], int bufLen)
{
    int len, counts;
    //INT8U seq = 0;
    char frameBuf[MAX_COM_BUF_LEN + 20];


    len = makeFrame(buf, bufLen,\
               cmd, frameInfo.seq+1, frameBuf);

    if(mode EQ PREVIEW_MODE || mode EQ SIM_MODE)
    {
       counts = _makeProtoData(PREVIEW_PROTO_FILE, screenStr, 0, frameBuf, len); //生成协议数据到

       w->comStatus->setTotalFrameCounts(counts);
       w->comStatus->setComMode(mode);
       w->comStatus->sendProtoFile(PREVIEW_PROTO_FILE);
    }
    else if(mode EQ UDISK_MODE)
    {
       //直接生成到U盘中文件名为 屏幕Addr.dat
        _makeProtoData(UDISK_PROTO_FILE, screenStr, 0, frameBuf, len); //生成协议数据到
        w->comStatus->setComMode(mode);
        w->comStatus->getUDiskParaFromSettings(screenStr); //获取屏幕地址--生成文件时需要
        w->comStatus->sendProtoFile(UDISK_PROTO_FILE);
    }
    else //if(mode EQ COM_MODE) //串口方式
    {
        counts = _makeProtoData(COM_PROTO_FILE, screenStr, 0, frameBuf, len);  //生成协议数据到
        w->comStatus->setTotalFrameCounts(counts);
        w->comStatus->getCOMParaFromSettings(screenStr); //获取通信参数--具体的通信方式在通信参数中定义
        w->comStatus->sendProtoFile(COM_PROTO_FILE);
    }

    return 1;
}

//INT8U makeProtoBufData(INT8U Cmd, )
INT8U makeProtoFileData(QString screenStr, int mode, int flag)
{
    INT16U counts = 0; //总的帧数

    if(mode EQ PREVIEW_MODE)
    {
       counts = _makeProtoData(PREVIEW_PROTO_FILE, screenStr, flag, (char *)0, 0); //生成协议数据到

       w->comStatus->setTotalFrameCounts(counts);
       w->comStatus->setComMode(mode);
       w->comStatus->sendProtoFile(PREVIEW_PROTO_FILE);
    }
    else  if(mode EQ SIM_MODE)
    {
        counts = _makeProtoData(SIM_PROTO_FILE, screenStr, flag, (char *)0, 0); //生成协议数据到

        w->comStatus->setTotalFrameCounts(counts);
        w->comStatus->setComMode(mode);
        w->comStatus->sendProtoFile(SIM_PROTO_FILE);
    }
    else if(mode EQ UDISK_MODE)
    {
        //直接生成到U盘中文件名为 屏幕Addr.dat
         _makeProtoData(UDISK_PROTO_FILE, screenStr, flag, (char *)0, 0); //生成协议数据到
         w->comStatus->setComMode(mode);
         w->comStatus->getUDiskParaFromSettings(screenStr); //获取屏幕地址--生成文件时需要
         w->comStatus->sendProtoFile(UDISK_PROTO_FILE);
    }
    else //if(mode EQ COM_MODE) //串口方式
    {
        counts = _makeProtoData(COM_PROTO_FILE, screenStr, flag, (char *)0, 0);  //生成协议数据到
        w->comStatus->setTotalFrameCounts(counts);
        w->comStatus->getCOMParaFromSettings(screenStr); //获取通信参数
        w->comStatus->sendProtoFile(COM_PROTO_FILE);
    }

    return 1;

}
