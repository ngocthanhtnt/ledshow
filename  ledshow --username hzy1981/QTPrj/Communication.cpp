#include <QTextStream>
#include "Communication.h"
#include <Qstringlist.h>
#include <QSettings>
#include <QTime>
#include <QCoreApplication>
#include <QProgressDialog>
#include <QVBoxLayout>
#include "mainwindow.h"
#include "makeProto.h"

extern QSettings settings;
extern MainWindow *w;
/*
==============
<CONSTRUCTORS>
==============
*/
QStringList getComPortList()
{
    QextSerialEnumerator enumer;
    QList<QextPortInfo> ports = enumer.getPorts();
    QStringList strlist;

    strlist.clear();
    for( int i = 0; i < ports.count(); ++i)
        strlist << QObject::tr(ports.at(i).portName.toLocal8Bit());
    //comPortEdit->addItems(strlist);
    return strlist;
}

void comSleep(int ms)
{
    QTime dieTime = QTime::currentTime().addMSecs(ms);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

int CcomStatus::waitComRcv(int sec)
{
  for(int i = 0; i < sec*10; i ++)
  {
    comSleep(100); //延时100ms
    comReceive();
    if(Rcv_Flag EQ FRAME_FLAG) //收到应答帧
        return 1;
  }

  return 0;
}

CcomStatus::CcomStatus(QWidget * parent):QWidget(parent)
{
    QVBoxLayout *vLayout;

    vLayout = new QVBoxLayout(this);
    port = new QextSerialPort("COM1", QextSerialPort::EventDriven);
    progressDialog = new QProgressDialog(w);//QProgressDialog()
    vLayout->addWidget(progressDialog);
    setLayout(vLayout);

    memset(Rcv_Buf, 0, sizeof(Rcv_Buf));
    Rcv_Posi = 0;

        //QObject::connect(port, SIGNAL(readyRead()), this, SLOT(receive()));
}

//断开通信连接
int CcomStatus::disConnect()
{
    memset(Rcv_Buf, 0, sizeof(Rcv_Buf));
    Rcv_Posi = 0;

    if(COM_Mode EQ COM_MODE)
      port->close();
}

//打开通信端口，并进行连接
int CcomStatus::connect(QString str)
{
    QStringList comPortList;
    comPortList = getComPortList();

    getCOMParaFromSettings(str);//获取通信参数

    if(COM_Mode EQ COM_MODE)
    {
        if(COM_Para.Baud EQ 0)
          port->setBaudRate(BAUD9600);
        else
          port->setBaudRate(BAUD57600);

        //流控关、偶校验、数据位8位、停止位1位
        port->setFlowControl(FLOW_OFF);
        port->setParity(PAR_EVEN); //偶校验
        port->setDataBits(DATA_8);
        port->setStopBits(STOP_1);

        if(port->open(QIODevice::ReadWrite) EQ false)
        {

            comReStr = tr("打开串口失败！请检查该串口是否已被占用");
            emit comStatusChanged(comReStr);
            return 0;
        }
        else
        {
          comReStr = tr("打开串口成功");
          emit comStatusChanged(comReStr);
          return 1;
        }

    }
    else //其他通信方式
    {
       return 0;

    }
}

void CcomStatus::setComMode(int mode)
{
    COM_Mode = mode;

}

int CcomStatus::sendFrame(char *data, int len)
{
  INT8U mode = COM_Mode;

  if(mode EQ PREVIEW_MODE)//预览模式
  {
    Rcv_Frame_Proc(CH_SIM, (INT8U *)data, (INT16U)len); //接收函数处理。在仿真情况下，将参数写入了硬盘文件。模拟写入EEROM
  }
  else if(mode EQ SIM_MODE) //仿真模式
  {
    for(int i = 0; i < len; i ++)
        Com_Rcv_Byte(CH_SIM, *(data + i));
  }
  else if(mode EQ COM_MODE)//串口通信模式
  {
      port->write(data, len);
      waitComRcv(3); //等待应答
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

//发送一个文件的协议数据到目标，可以以线程的形式发送
int CcomStatus::sendProtoFile(QString fileName)
{
    FILE *file;
    int re,Re = 1;
    INT16U len, len0 = 0;
    char frameBuf[BLOCK_DATA_LEN + 20];

    file = fopen(fileName.toLocal8Bit(), "rb");
    if(file EQ 0)
    {
        ASSERT_FAILED();
        return 0;
    }

    fseek(file, 0, SEEK_SET);

    while((re = fread(frameBuf, FLEN + 2, 1, file)) > 0)
    {
      memcpy(&len, frameBuf + FLEN, 2);
      if(len <= sizeof(frameBuf) && len > FLEN + 2)
      {
          re = fread(frameBuf + FLEN + 2,  len - (FLEN + 2), 1, file);

          if(re > 0 && Check_Frame_Format((INT8U *)frameBuf, len))
          {
            if(sendFrame(frameBuf, len) EQ 0)
              {
                Re = 0;
                break;
            }

            len0 += len;
          }
          else
          {
            Re = 0;
            break;
          }
      }
      else
      {
          Re = 0;
          break;
      }
    }

    fclose(file);

    return Re;
}

//获取通信参数,str为屏幕的settings str
void CcomStatus::getCOMParaFromSettings(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("comTest");

    COM_Mode = settings.value("comMode").toInt();
    COM_Port = settings.value("comPort").toInt();

    COM_Para.Addr = settings.value("screenID").toInt();
    COM_Para.Baud = settings.value("comBaud").toInt();

    ETH_Para.IP = settings.value("ip").toInt();

    settings.endGroup();
    settings.endGroup();

    //SET_SUM(screenPara);
}

//串口接收数据
void CcomStatus::comReceive()
{

    int bytesRead;

    bytesRead = port->read((char *)Rcv_Buf + Rcv_Posi, sizeof(Rcv_Buf)- Rcv_Posi);//(char *)(Rcv_Buf + Rcv_Posi), sizeof(Rcv_ Buf) - Rcv_Posi);
    if(bytesRead EQ 0)
        return;

    if(sizeof(Rcv_Buf) >= Rcv_Posi + bytesRead)
    {
        Rcv_Posi += bytesRead;
        Rcv_Buf[Rcv_Posi] = '\0';
    }
    else
    {
        ASSERT_FAILED();
        Rcv_Posi = 0;
    }

    for(int i = 0; i < Rcv_Posi; i ++)
    {
        //if(Screen_Status.Rcv_Data[i] EQ FRAME_HEAD && \
        if(Check_Frame_Format(Rcv_Buf + i, Rcv_Posi - i))
        {
           if(i != 0) //将数据复制到开始
               memcpy(Rcv_Buf, Rcv_Buf + i, Rcv_Posi - i);
           Rcv_Flag = FRAME_FLAG;
           Rcv_Ch = CH_COM;
           return;
        }
    }
}
/*
==============
<DESTRUCTOR>
==============
*/


/*
==============
<STATIC>
==============
*/


/*
==============
<SLOTS>
==============
*/



