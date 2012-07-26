#include <QTextStream>
#include "Communication.h"
#include <Qstringlist.h>
#include <QSettings>
#include <QTime>
#include <QCoreApplication>
#include <QProgressDialog>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include "mainwindow.h"
#include "makeProto.h"
#include <windows.h>
#include <dbt.h>

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

//等待通信结果,返回正确应答帧返回true,否定返回false, 返回数据域保留在pDst中
bool CcomStatus::waitComEnd(INT8U *pDst, unsigned int maxLen, int *pDstLen)
{
    char status;

    while(1)//for(int i = 0; i < 100; i ++)
    {
      Delay_ms(100);
      status = comThread->status;

      if(comThread->Rcv_Posi >= 500)
      {
          ASSERT_FAILED();
          comThread->Rcv_Posi = 0;
      }

      if(status EQ COM_FAILED || status EQ COM_OK)
      {
         if(comThread->Rcv_Posi < maxLen)
         {
           memcpy(pDst, w->comStatus->comThread->Rcv_Buf + FDATA, w->comStatus->comThread->Rcv_Posi);
           *pDstLen = comThread->Rcv_Posi - F_NDATA_LEN;
         }
         else
         {
             ASSERT_FAILED();
         }
      }

      if(status EQ COM_FAILED)
          return false;
      else if(status EQ COM_OK)
          return true;
    }

}


int CcomThread::waitComRcv(int sec)
{
    int rcvBytes,j = 0;

    Rcv_Posi = 0;
    Rcv_Flag = 0;
    memset(Rcv_Buf, 0, sizeof(Rcv_Buf));

    for(int i = 0; i < sec*10; i ++)
    {
        this->msleep(100); //延时100ms
        rcvBytes = comReceive();

        if(Rcv_Flag EQ FRAME_FLAG) //收到应答帧
            return 1;
        else if(rcvBytes > 0)//收到了数据则重新计时
        {
            i = 0;
        }

        j ++;
        if(j >= 50) //最大不超过5s
            return 0;

    }

    return 0;
}

bool CcomThread::comRun()
{
    FILE *file;
    int re;
    bool Re = true;
    INT16U len;
    int len0 = 0;
    bool flag = false;
    char frameBuf[2000];//[MAX_COM_BUF_LEN + 20];

    if(status == COM_ING) //当前在通信过程中,退出
        return false;

    status = COM_ING; //进入通信状态

    if(COM_Mode EQ UDISK_MODE) //U盘模式，直接复制文件就行，不需要通信过程
    {
        QDir dataDir;
        QFile file;


        QString fileDir = uDiskName;//getUDiskPath(); //获取U盘路径
        //uDiskName = fileDir;
        if(fileDir == "") //没有插入U盘
        {
            comReStr = tr("没有找到U盘,生成U盘数据失败！");
            emit this->comStatusChanged(comReStr);
            status = COM_FAILED; //进入通信状态
            return false;
        }

        fileDir = fileDir + "LEDDATA";
        if(dataDir.exists(fileDir) == false)
        {
            if(dataDir.mkdir(fileDir) == false)
            {
                comReStr = uDiskName + tr(",该U盘中创建目录失败，请检查U盘是否写保护");
                emit this->comStatusChanged(comReStr);
                status = COM_FAILED; //进入通信状态
                return false;
            }
        }

        fileDir = fileDir + "\\" + QString::number(this->COM_Para.Addr) + ".dat";
        if(file.exists(fileDir))
           file.remove(fileDir);

        if(file.copy(protoFileName, fileDir) == false)
        {
            comReStr = uDiskName + tr(",该U盘中复制文件失败，请检查U盘是否写保护");
            emit this->comStatusChanged(comReStr);
            status = COM_FAILED; //进入通信状态
            return false;
        }

        comReStr = tr("数据成功保存到")+uDiskName;
        status = COM_OK; //进入通信状态

        return true;

    }

    file = fopen(protoFileName.toLocal8Bit(), "rb");
    if(file EQ 0)
    {
        ASSERT_FAILED();
        comReStr = tr("找不到协议数据文件！");
        emit this->comStatusChanged(comReStr);
        status = COM_FAILED;
        return false;
    }

    fseek(file, 0, SEEK_SET);

    //dialog->show();

    if(this->connect() EQ 0)
    {
        status = COM_FAILED;
        return false;
    }

    while((re = fread(frameBuf, FLEN + 2, 1, file)) > 0 && frameBuf[0] EQ FRAME_HEAD)
    {
      len = 0;
      memcpy(&len, frameBuf + FLEN, 2);
      if(len <= sizeof(frameBuf) && len > FLEN + 2)
      {
          re = fread(frameBuf + FLEN + 2,  len - (FLEN + 2), 1, file);

          if(re > 0 && Check_Frame_Format((INT8U *)frameBuf, len))
          {
              flag = true;
              Rcv_Posi = 0;
              memset(Rcv_Buf, 0, sizeof(Rcv_Buf));
              if(sendFrame(frameBuf, len, sizeof(frameBuf)) EQ false)
              {
                Re = false;
                break;
              }

              len0 += len;
              fseek(file, len0, SEEK_SET);
           }
           else
           {
              Re = false;
              break;
           }
      }
      else
      {
           Re = false;
           break;
      }
    }

    fclose(file);

    this->disConnect();

    if(checkComMode(this->COM_Mode))
    {
        if(flag EQ false)
        {
          comReStr = tr("无数据发送");
          emit this->comStatusChanged(comReStr);
        }
        else
          emit this->comEnd(Re);
     }

    if(Re EQ true)
        status = COM_OK;
    else
        status = COM_FAILED;

    return Re;
}

void CcomThread::run()
{
  comRun();
}

CcomThread::CcomThread(QObject * parent):QThread(parent)
{
    //QVBoxLayout *vLayout;

    port = new QextSerialPort("COM1", QextSerialPort::EventDriven);

    memset(Rcv_Buf, 0, sizeof(Rcv_Buf));
    Rcv_Posi = 0;

        //QObject::connect(port, SIGNAL(readyRead()), this, SLOT(receive()));
}

//断开通信连接
bool CcomThread::disConnect()
{

    if(COM_Mode EQ COM_MODE)
      port->close();

    return true;
}

//打开通信端口，并进行连接
bool CcomThread::connect()
{
    QStringList comPortList;
    comPortList = getComPortList();

    memset(Rcv_Buf, 0, sizeof(Rcv_Buf));
    Rcv_Posi = 0;

    if(COM_Mode EQ COM_MODE)
    {
        port->setPortName("\\\\.\\"+COM_Port);

        port->close();
        if(port->open(QIODevice::ReadWrite) EQ false)
        {

            comReStr = tr("打开串口失败！");
            emit comStatusChanged(comReStr);
            return false;
        }
        else
        {
            if(COM_Para.Baud EQ 0)
              port->setBaudRate(BAUD57600);
            else
              port->setBaudRate(BAUD9600);

            //流控关、偶校验、数据位8位、停止位1位
            port->setFlowControl(FLOW_OFF);
            port->setParity(PAR_NONE); //偶校验
            port->setDataBits(DATA_8);
            port->setStopBits(STOP_1);

          comReStr = tr("打开串口成功！");

          char comByteBuf[50];
          memset(comByteBuf, COM_BYTE, sizeof(comByteBuf));
          port->write(comByteBuf, sizeof(comByteBuf));//(comByteBuf, len, sizeof(comByteBuf); //先发送20个字节的"唤醒符"
          Delay_ms(100); //等待下位机进入通信状态

          emit comStatusChanged(comReStr);
          return true;
        }

    }
    else //其他通信方式
    {
       return true;

    }
}

bool CcomThread::sendFrame(char *data, int len, int bufLen)
{
    int i,re;
  INT8U mode = COM_Mode;

  if(mode EQ PREVIEW_MODE)//预览模式
  {
    Rcv_Frame_Proc(CH_SIM, (INT8U *)data, (INT16U)len, bufLen); //接收函数处理。在仿真情况下，将参数写入了硬盘文件。模拟写入EEROM
    return true;
  }
  else if(mode EQ SIM_MODE) //仿真模式
  {/*
    for(i = 0; i < len; i ++)
      Com_Rcv_Byte(CH_SIM, *(data + i));

    while(1)
    {
      Delay_ms(100);
      if(Screen_Status.Rcv_Flag EQ 0) //等待线程处理完该帧
          break;
    }
*/
     // Rcv_Frame_Proc(CH_SIM, (INT8U *)data, (INT16U)len, bufLen); //接收函数处理。在仿真情况下，将参数写入了硬盘文件。模拟写入EEROM
    for(i = 0; i < len; i ++)
      Com_Rcv_Byte(CH_SIM, *(data + i));

    Screen_Com_Proc();

    comReStr = tr("发送第") + QString::number(frameCounts + 1)+"/"+QString::number(totalFrameCounts)+tr("帧,等待应答...");
    emit this->comStatusChanged(comReStr);
    frameCounts++;

    if((Rcv_Buf[FCMD] & 0xC0) EQ 0x40) //肯定应答
    {
        emit comProgressChanged(100*frameCounts/totalFrameCounts);

        comReStr = tr("收到肯定应答");
        emit this->comStatusChanged(comReStr);
        return true;
     }
    else if((Rcv_Buf[FCMD] & 0xC0) EQ 0x80) //否定应答
    {
        comReStr = tr("收到否定应答");
        emit this->comStatusChanged(comReStr);
        return false;
    }
    else
    {
        comReStr = tr("收到无效应答");
        emit this->comStatusChanged(comReStr);
        return false;
    }
  }
  else if(mode EQ COM_MODE)//串口通信模式
  {
    for(i = 0; i < 2; i ++)
    {
      port->write(data, len);

      if(i EQ 0)
        comReStr = tr("发送第") + QString::number(frameCounts + 1)+"/"+QString::number(totalFrameCounts)+tr("帧,等待应答...");// + QString::number(len);
      else
        comReStr = tr("重复发送第") + QString::number(frameCounts + 1)+"/"+QString::number(totalFrameCounts)+tr("帧,等待应答...");

      emit this->comStatusChanged(comReStr);
      re = waitComRcv(2); //等待应答
      if(re > 0)
      {
          frameCounts++;
          emit comProgressChanged(100*frameCounts/totalFrameCounts);
          if((Rcv_Buf[FCMD] & 0xC0) EQ 0x40) //肯定应答
          {
              comReStr = tr("收到肯定应答");
              emit this->comStatusChanged(comReStr);
              return true;
           }
          else if((Rcv_Buf[FCMD] & 0xC0) EQ 0x80) //否定应答
          {
              comReStr = tr("收到否定应答");
              emit this->comStatusChanged(comReStr);
              return false;
          }
          else
          {
              comReStr = tr("收到无效应答");
              emit this->comStatusChanged(comReStr);
              return false;
          }
      }
    }

    comReStr = tr("等待应答超时");
    emit this->comStatusChanged(comReStr);
    return false;
  }
  else if(mode EQ ETH_MODE)//以太网模式
  {

  }
  else if(mode EQ GPRS_MODE)
  {

  }
  else if(mode EQ UDISK_MODE)
  {
      ASSERT_FAILED();
      return false;
  }

  return true;
}

//串口接收数据
int CcomThread::comReceive()
{

    int bytesRead;

    bytesRead = port->read((char *)Rcv_Buf + Rcv_Posi, sizeof(Rcv_Buf)- Rcv_Posi);//(char *)(Rcv_Buf + Rcv_Posi), sizeof(Rcv_ Buf) - Rcv_Posi);
    if(bytesRead EQ 0)
        return 0;

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

    for(unsigned int i = 0; i < Rcv_Posi; i ++)
    {
        //if(Screen_Status.Rcv_Data[i] EQ FRAME_HEAD &&
        if(Check_Frame_Format(Rcv_Buf + i, Rcv_Posi - i))
        {
           if(i != 0) //将数据复制到开始
            {
               memcpy(Rcv_Buf, Rcv_Buf + i, Rcv_Posi - i);
             Rcv_Posi = Rcv_Posi - i;
           }
           Rcv_Flag = FRAME_FLAG;
           Rcv_Ch = CH_COM;
           return bytesRead;
        }
    }

    return bytesRead;
}

CcomStatus::CcomStatus(QWidget * parent):QDockWidget(tr("通信状态"), parent)
{
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;
    QWidget *widget;
    QLabel *progressLabel;
    QLabel *paraLabel, *statusLabel;
    QLabel *nameLabel;

    widget = new QWidget(this);
    vLayout = new QVBoxLayout(widget);
    hLayout = new QHBoxLayout(widget);

    nameLabel = new QLabel(tr("通信屏幕:"));
    screenNameEdit = new QLineEdit(widget);
    screenNameEdit->setFocusPolicy(Qt::NoFocus);

    //udiskListDialog = new CudiskListDialog(this);

    hLayout->addWidget(nameLabel);
    hLayout->addWidget(screenNameEdit);
    vLayout->addLayout(hLayout);

    paraLabel = new QLabel(tr("通信参数:"),widget);
    paraEdit = new QTextEdit(widget);
    paraEdit->setFixedHeight(50);
    paraEdit->setFocusPolicy(Qt::NoFocus);

    statusLabel = new QLabel(tr("通信状态:"),widget);

    statusEdit = new QTextEdit(widget);
    statusEdit->setFixedHeight(150); //通信状态
    statusEdit->setFocusPolicy(Qt::NoFocus);

    progressLabel = new QLabel(tr("进度"),widget);
    progressBar = new QProgressBar(widget);//QProgressDialog()
    progressBar->setMaximum(100);
    progressBar->setValue(0);

    hLayout = new QHBoxLayout(widget);
    hLayout->addWidget(progressLabel);
    hLayout->addWidget(progressBar);

    progressList = new QListView(widget);
    //progressList->setFixedSize(100,100);
    progressList->setFixedHeight(100);
    comThread = new CcomThread(this);

    vLayout->addWidget(paraLabel);
    vLayout->addWidget(paraEdit);
    vLayout->addWidget(statusLabel);
    vLayout->addWidget(statusEdit);
    vLayout->addWidget(progressList);
    vLayout->addLayout(hLayout);
    //vLayout->addWidget(statusEdit);
    //vLayout->addWidget(progressBar);

    clrButton = new QPushButton(tr("清空"), widget);
    hideButton = new QPushButton(tr("隐藏"), widget);
    hLayout = new QHBoxLayout(widget);
    //hLayout ->addStretch(10);
    hLayout ->addWidget(clrButton);
    hLayout ->addWidget(hideButton);
    vLayout->addLayout(hLayout);

    vLayout->addStretch(10);
    widget->setLayout(vLayout);

    widget->setFixedWidth(200);
    setWidget(widget);
    connect(this->comThread, SIGNAL(comProgressChanged(int)), this, SLOT(progressChange(int)));
    connect(this->comThread, SIGNAL(comStatusChanged(QString)), this, SLOT(statusChange(QString)));
    connect(this->comThread, SIGNAL(comEnd(bool)), this, SLOT(comEnd(bool)));
    connect(this->clrButton, SIGNAL(clicked()), this->statusEdit, SLOT(clear()));
    connect(this->clrButton, SIGNAL(clicked()), this->paraEdit, SLOT(clear()));
    connect(this->clrButton, SIGNAL(clicked()), this->screenNameEdit, SLOT(clear()));
    connect(this->clrButton, SIGNAL(clicked()), this->progressBar, SLOT(reset()));

    connect(this->hideButton, SIGNAL(clicked()), this, SLOT(hideSlot()));
    //connect(this, SIGNAL(comStart()), this->comth)
    //connect(this, SIGNAL(Start()), this, SLOT(comStart()));
    //QObject::connect(port, SIGNAL(readyRead()), this, SLOT(receive()));
    progressList->setVisible(false);
}

void CcomStatus::hideSlot()
{
  hide();
   // w->actionComStatus->setChecked(false);
}

bool checkComMode(INT8U COM_Mode)
{
    if(COM_Mode EQ COM_MODE ||\
       COM_Mode EQ GPRS_MODE ||\
       COM_Mode EQ ETH_MODE)
        return true;
    else
        return false;
}

void CcomStatus::closeEvent(QCloseEvent *e)
{
    w->actionComStatus->setChecked(false);
    //e->ignore();
}

void CcomStatus::showEvent(QShowEvent *e)
{
    w->actionComStatus->setChecked(true);
}

void CcomStatus::hideEvent(QHideEvent * e)
{
  w->actionComStatus->setChecked(false);
}

//发送一个文件的协议数据到目标，可以以线程的形式发送
void CcomStatus::sendProtoFile(QString fileName)
{

    //char temp[10];
    //getUDiskPath();

   this->comThread->protoFileName = fileName;

   //串口、GPRS、以太网方式采用线程形式,其他采用一般函数形式，否则可能导致预览失真
   if(checkComMode(this->comThread->COM_Mode))
   {
     this->show();
     this->comThread->start();
   }
   else //预览或者仿真模式或者U盘模式
   {
      if(this->comThread->COM_Mode EQ SIM_MODE)
          this->show();
      else if(this->comThread->COM_Mode EQ UDISK_MODE)
      {
        CudiskListDialog *udiskListDialog = new CudiskListDialog(w);

        udiskListDialog->updateUdiskList();

        int count = udiskListDialog->udiskCombo->count();
        comThread->uDiskName = "";
        if(count >= 2) //当超过2个以上的U盘时需要用户选择
        {

          udiskListDialog->setFixedWidth(180);
          udiskListDialog->exec();

          comThread->uDiskName = udiskListDialog->udiskName;
        }
        else if(count EQ 1) //只有1个U盘
        {
          comThread->uDiskName = udiskListDialog->udiskList.at(0).toLocal8Bit().constData();
        }
        else
          comThread->uDiskName = "";

      }
     this->comThread->comRun();
   }
   //emit this->start();
  // this->exec();
}

void CcomStatus::getUDiskParaFromSettings(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("comTest");

    comThread->COM_Para.Addr = settings.value("screenID").toInt(); //获取板卡地址


    settings.endGroup();
    settings.endGroup();
}

//获取通信参数,str为屏幕的settings str
void CcomStatus::getCOMParaFromSettings(QString str)
{
    QString str1;
    //int flag;
    QStringList screenGroups;
    //int screenSize;

    settings.beginGroup(str);
    settings.beginGroup("comTest");

    //flag = settings.value("flag");

    comThread->COM_Mode = settings.value("comMode").toInt();
    comThread->COM_Port = settings.value("comPort").toString();
    if(comThread->COM_Port EQ "")
    {
        if(getComPortList().count() > 0)
          comThread->COM_Port = getComPortList().at(0);
        //settings.setValue("comPort", comThread->COM_Port);
    }

    comThread->COM_Para.Addr = settings.value("screenID").toInt();
    comThread->COM_Para.Baud = settings.value("baud").toInt();

    comThread->ETH_Para.IP = settings.value("ip").toInt();

    settings.endGroup();
    settings.endGroup();

    screenNameEdit->clear();
    paraEdit->clear();
    statusEdit->clear();
    progressBar->setValue(0);

    //------查找是第几号屏幕
    int index = getScreenIndex(str);
    screenNameEdit->setText(QString::number(index) + tr("号屏幕"));
    //-------------
    if(comThread->COM_Mode EQ COM_MODE)
    {
      str1 = tr("串口通信方式, ");
      str1 += comThread->COM_Port + tr(" 波特率:");
      if(comThread->COM_Para.Baud EQ 0)
          str1 += tr("57600");
      else
          str1 += tr("9600");

      paraEdit->append(str1);
    }
}

//返回通信结果字符串
QString CcomStatus::getComReStr()
{
    return comThread->comReStr;
}

//获取当前通信状态
char CcomStatus::getComStatus()
{
  return comThread->status;
}

//设置通信模式
void CcomStatus::setComMode(int mode)
{
    comThread->COM_Mode = mode;

}

void CcomStatus::comShow()
{
    this ->show();
}

void CcomStatus::setTotalFrameCounts(int counts)
{
  comThread->frameCounts = 0;
  comThread->totalFrameCounts = counts;
}

//进度改变
void CcomStatus::progressChange(int progress)
{
    progressBar->setValue(progress);
}

//通信状态改变
void CcomStatus::statusChange(QString str)
{
    statusEdit->append(str);
}

//通信结束
void CcomStatus::comEnd(bool flag)
{
    if(flag EQ false)
        statusEdit->append(tr("发送数据失败!"));
    else
        statusEdit->append(tr("发送数据成功!"));
}

void CcomStatus::comStart()
{
    show();
    comThread->start();
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



