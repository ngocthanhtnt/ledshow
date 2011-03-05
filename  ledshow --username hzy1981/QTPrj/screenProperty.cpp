#include <QFileDialog>
#include <QSettings>
#include <QMovie>
#include <QInputDialog>
#include <QMessageBox>
#include <QextSerialPort>
#include <QextSerialEnumerator>
#include <QList>
#include <QObject>
#include "mainwindow.h"
#include "screenProperty.h"

extern MainWindow *w;
extern QSettings settings;

//屏幕配置文件
QSettings screenSettings(SCREEN_INI_FILE,QSettings::IniFormat,0);
//控制卡配置文件
QSettings cardSettings(CARD_INI_FILE,QSettings::IniFormat,0);

#define WIDTH_0 80
/*
CipInput::CipInput(QWidget *parent):QGroupBox(parent)
{
    QHBoxLayout *hLayout;
    QLabel *pointLabel[4];

    hLayout = new QHBoxLayout(this);

    for(int i = 0; i < 4; i ++)
    {
        inputEdit[i] = new QLineEdit(this);
        inputEdit[i]->setFixedWidth(30);
        //inputEdit[i]->setmi
        //inputEdit[i]->setmax
        pointLabel[i] = new QLabel(tr("."),this);
        hLayout->addWidget(inputEdit[i]);
        hLayout->addWidget(pointLabel[i]);
    }

   setLayout(hLayout);
}

CipInput::~CipInput()
{

}

INT332U CipInput::getInputIP()
{

}
*/
/*
//screen属性窗
class CscreenProperty:public QWidget
{
    Q_OBJECT
private:
    QLabel *screenSourceLabel; //screen源标志
    QLineEdit *screenSourceEdit; //screen源编辑框
    QPushButton *openButton; //打开按钮

    QLabel *frameNumLabel; //帧数标志
    QLineEdit *frameNumEdit; //帧数编辑
    QLabel *runSpeedLabel; //运行速度标志
    QLineEdit *runSpeedCheck; //运行速度编辑
    QLabel *speedUnitLabel; //速度单位

    QLabel *totalFrameNumLabel; //总帧数


public:
    CscreenProperty(QWidget *parent=0);
    ~CscreenProperty();
};
*/
//读取屏幕参数
//返回>0表示读取到参数，==0表示没有读取到参数
INT8U getScreenParaFromSettings(QString screenStr, S_Screen_Para &screenPara)
{
    //在
  settings.beginGroup(screenStr);
  QString indexStr = settings.value("screenIndex").toString(); //获得屏幕
  settings.endGroup();

  //在屏幕参数配置文件中读取屏幕参数
  screenSettings.beginGroup(QString("screen/") + indexStr);
  if(settings.childKeys().size() EQ 0) //不存在这个屏幕??
  {
      screenSettings.endGroup();
      return 0;
  }

  screenPara.Base_Para.Addr = screenSettings.value("addr").toString().toInt();
  screenPara.Base_Para.Baud = screenSettings.value("Baud").toString().toInt();
  screenPara.Base_Para.Color = screenSettings.value("color").toString().toInt();
  screenPara.Base_Para.Width = 256;//screenSettings.value("width").toString().toInt();
  screenPara.Base_Para.Height = 256;//screenSettings.value("height").toString().toInt();
  screenPara.Base_Para.IP = screenSettings.value("ip").toString().toInt();
  screenSettings.endGroup();

  return 1;
}

//screen属性编辑
CscreenProperty::CscreenProperty(QWidget *parent):QWidget(parent)
{

    QTabWidget *tab;
    QHBoxLayout *hLayout,*mainLayout;
    QVBoxLayout *vLayout;
    //QGroupBox *lightnessGroup;
    //QGroupBox *openCloseTimeGroup;
    //QGroupBox *facParaGroup;

    //lightnessGroup = new QGroupBox(tr("亮度设置"),this);
    //openCloseTimeGroup = new QGroupBox(tr("开关机设置"),this);
    //facParaGroup = new QGroupBox(tr("安装参数"),this);

    mainLayout = new QHBoxLayout(this);

    vLayout = new QVBoxLayout(this);
    nameEdit = new CnameEdit(this);
    vLayout->addWidget(nameEdit);
    vLayout->addStretch(10);
    mainLayout->addLayout(vLayout);

    //tab = new QTabWidget(this);
     //hLayout = new QHBoxLayout(this);
    facProperty = new CfacScreenProperty(this);

    facProperty->setEditEnable(false);
    facProperty->comTest->setVisible(false);
    facProperty->endButton->setVisible(false);
    facProperty->loadButton->setVisible(false);
    facProperty->tabWidget->removeTab(facProperty->tabWidget->indexOf(facProperty->readParaGroup));
    //hLayout->addWidget(facProperty);
    //facParaGroup->setLayout(hLayout);

    //hLayout = new QHBoxLayout(this);
    lightnessProperty = new ClightnessProperty(this);
    //hLayout->addWidget(lightnessProperty);
    //lightnessGroup->setLayout(hLayout);

    //hLayout = new QHBoxLayout(this);
    openCloseProperty = new CopenCloseProperty(this);
    //hLayout->addWidget(openCloseProperty,0,Qt::AlignTop);
    //openCloseTimeGroup->setLayout(hLayout);
    //lightnessGroup->setLayout(vLayout);
    //facProperty->setEnabled(false);
    //facProperty->endButton->setEnabled(true);
    //tab->addTab(lightnessProperty, tr("亮度调节"));
    //tab->addTab(openCloseProperty, tr("定时开关机"));

   // tab->addTab(facProperty, tr("工厂参数"));
    //hLayout->addWidget(tab);
    mainLayout->addWidget(lightnessProperty);
    mainLayout->addWidget(openCloseProperty);
    mainLayout->addWidget(facProperty);
    mainLayout->addStretch(10);

    //setLayout(hLayout);
     //hLayout->addLayout(vLayout);

    //connect(nameEdit, SIGNAL(edited()), this, SIGNAL(edited()));
    //connect(openButton, SIGNAL(clicked()), this, SLOT(openscreenFile()));
}


CscreenProperty::~CscreenProperty()
{

}

void CscreenProperty::getSettingsFromWidget(QString str)
{
    nameEdit->getSettingsFromWidget(str);
    lightnessProperty->getSettingsFromWidget(str);
    openCloseProperty->getSettingsFromWidget(str);

}

void CscreenProperty::setSettingsToWidget(QString str)
{
    nameEdit->setSettingsToWidget(str);
    lightnessProperty->setSettingsToWidget(str);
    openCloseProperty->setSettingsToWidget(str);
    facProperty->setSettingsToWidget(str);
}
/*
class ClightnessProperty:public QWidget
{
    Q_OBJECT
    QRadioButton *manualButton;
    QRadioButton *timerButton;

public:
    QCheckBox *timerCheck[MAX_LIGHTNESS_TIME];
    QTimeEdit *timerEdit[MAX_LIGHTNESS_TIME];
    QSlider *timerSlider[MAX_LIGHTNESS_TIME];

    QSlider *manualSlider;
    //void getSettingsFromWidget(QString str);
   //void setSettingsToWidget(QString str);
    ClightnessProperty(QWidget *parent=0);
    ~ClightnessProperty();
};
*/
ClightnessProperty::ClightnessProperty(QWidget *parent):QGroupBox(parent)
{
    INT8U i;

    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
   QHBoxLayout *gHLayout;
   QGroupBox *groupBox;

   QHBoxLayout *mainLayout = new QHBoxLayout(this);

   groupBox = new QGroupBox(this);
   vLayout = new QVBoxLayout(this);
   manualButton = new QRadioButton(tr("手动调亮"),this);
   timerButton = new QRadioButton(tr("定时调亮"),this);
   autoButton = new QRadioButton(tr("自动调亮"),this);

   vLayout->addWidget(manualButton);
   vLayout->addWidget(timerButton);
   vLayout->addWidget(autoButton);
   groupBox->setLayout(vLayout);

   mainLayout->addWidget(groupBox);//addLayout(hLayout);

   groupBox = new QGroupBox(this);
   gHLayout = new QHBoxLayout(this);

   hLayout = new QHBoxLayout(this);
   manualSlider = new QSlider(Qt::Horizontal,this);
   manualSlider->setRange(10,MAX_LIGHTNESS_LEVEL*10);
   manualSlider->setTickInterval(10);
   //manualSlider->setFocusPolicy(Qt::StrongFocus);
   //manualSlider->setTickPosition(QSlider::TicksAbove);
   manualLabel = new QLabel(this);
   manualLabel->setFixedWidth(15);
   hLayout->addWidget(manualSlider);
   hLayout->addWidget(manualLabel);
   gHLayout->addLayout(hLayout);

   hLayout = new QHBoxLayout(this);
   autoLabel = new QLabel(tr("请确认已安装光照传感器"),this);
   hLayout->addWidget(autoLabel);
   gHLayout->addLayout(hLayout);


   QVBoxLayout *timerVLayout = new QVBoxLayout(this);
   for(i = 0; i < MAX_LIGHTNESS_TIME; i ++)
   {
     hLayout = new QHBoxLayout(this);
     timerCheck[i] = new QCheckBox(tr("使用"),this);
     timerEdit[i] = new QTimeEdit(this);

     timerSlider[i] = new QSlider(Qt::Horizontal,this);
     timerSlider[i]->setRange(10,MAX_LIGHTNESS_LEVEL*10);
     timerSlider[i]->setTickInterval(10);
     //timerSlider[i]->setFocusPolicy(Qt::StrongFocus);
     //timerSlider[i]->setTickPosition(QSlider::TicksAbove);

     timerLabel[i] = new QLabel(this);
     timerLabel[i]->setFixedWidth(15);

     hLayout->addWidget(timerCheck[i]);
     hLayout->addWidget(timerEdit[i]);
     hLayout->addWidget(timerSlider[i]);
     hLayout->addWidget(timerLabel[i]);

     timerVLayout->addLayout(hLayout);
   }

   gHLayout->addLayout(timerVLayout);
   groupBox->setLayout(gHLayout);
   mainLayout->addWidget(groupBox);
   mainLayout->addStretch(10);

   this->setLayout(mainLayout);

   connect(manualButton, SIGNAL(clicked()),this,SIGNAL(adjModeEditSignal()));
   connect(timerButton, SIGNAL(clicked()),this,SIGNAL(adjModeEditSignal()));
   connect(autoButton, SIGNAL(clicked()),this,SIGNAL(adjModeEditSignal()));

   connect(manualButton, SIGNAL(clicked()),this,SIGNAL(allEditSignal()));
   connect(timerButton, SIGNAL(clicked()),this,SIGNAL(allEditSignal()));
   connect(autoButton, SIGNAL(clicked()),this,SIGNAL(allEditSignal()));

   for(int i =0;i < MAX_LIGHTNESS_TIME; i ++)
   {
     connect(timerCheck[i],SIGNAL(clicked()),this,SIGNAL(allEditSignal()));
     connect(timerEdit[i],SIGNAL(timeChanged(QTime)),this,SIGNAL(allEditSignal()));
     connect(timerSlider[i],SIGNAL(valueChanged(int)),this,SIGNAL(allEditSignal()));
   }
   connect(manualSlider,SIGNAL(valueChanged(int)),this,SIGNAL(allEditSignal()));

   connect(this,SIGNAL(adjModeEditSignal()),this,SLOT(adjModeEditSlot()));
   connect(this,SIGNAL(allEditSignal()),this,SLOT(allEditSlot()));
}

void ClightnessProperty::allEditSlot()
{
    QString str = w->screenArea->getCurrentScreenStr();//getCurrentStr
    getSettingsFromWidget(str);

    for(int i=0; i < MAX_LIGHTNESS_TIME; i++)
      timerLabel[i]->setText(QString::number(timerSlider[i]->value()/10));
    manualLabel->setText(QString::number(manualSlider->value()/10));

    sliderEditProc();
}

void ClightnessProperty::adjModeEditSlot()
{
    if(manualButton->isChecked())
    {
        for(int i=0; i < MAX_LIGHTNESS_TIME; i ++)
        {
            timerCheck[i]->setVisible(false);
            timerEdit[i]->setVisible(false);
            timerSlider[i]->setVisible(false);
            timerLabel[i]->setVisible(false);
        }

        autoLabel->setVisible(false);

        manualSlider->setVisible(true);
        manualLabel->setVisible(true);
    }
    else if(timerButton->isChecked())
    {
      for(int i=0; i < MAX_LIGHTNESS_TIME; i ++)
      {
          timerCheck[i]->setVisible(true);
          timerEdit[i]->setVisible(true);
          timerSlider[i]->setVisible(true);
          timerLabel[i]->setVisible(true);
      }

      autoLabel->setVisible(false);
      manualSlider->setVisible(false);
      manualLabel->setVisible(false);
    }
    else if(autoButton->isChecked())
    {
        for(int i=0; i < MAX_LIGHTNESS_TIME; i ++)
        {
            timerCheck[i]->setVisible(false);
            timerEdit[i]->setVisible(false);
            timerSlider[i]->setVisible(false);
            timerLabel[i]->setVisible(false);
        }

        autoLabel->setVisible(true);

        manualSlider->setVisible(false);
        manualLabel->setVisible(false);
    }

    sliderEditProc();
}

void ClightnessProperty::sliderEditProc()
{
    for(int i=0; i < MAX_LIGHTNESS_TIME; i++)
    {
      if(timerCheck[i]->isChecked())
      {
          timerEdit[i]->setEnabled(true);//setTime(time);
          timerSlider[i]->setEnabled(true);//setValue(settings.value("timerLightness" + QString::number(i)).toInt()*10);
          timerLabel[i]->setEnabled(true);//setText(QString::number(timerSlider[i]->value()/10));
      }
      else
      {
          timerEdit[i]->setEnabled(false);//setTime(time);
          timerSlider[i]->setEnabled(false);//setValue(settings.value("timerLightness" + QString::number(i)).toInt()*10);
          timerLabel[i]->setEnabled(false);//setText(QString::number(timerSlider[i]->value()/10));
      }
    }
}

void ClightnessProperty::getSettingsFromWidget(QString str)
{
    settings.beginGroup(str);
  settings.beginGroup("lightness");
  //亮度调节方式
  if(timerButton->isChecked())
      settings.setValue("adjMode", 1);
  else if(autoButton->isChecked())
      settings.setValue("adjMode", 2);
  else
      settings.setValue("adjMode", 0);

  for(int i=0; i < MAX_LIGHTNESS_TIME; i++)
  {
     settings.setValue("timeCheck" + QString::number(i), timerCheck[i]->isChecked());
     settings.setValue("startHour" + QString::number(i),timerEdit[i]->time().hour());
     settings.setValue("startMin" + QString::number(i), timerEdit[i]->time().minute());
     settings.setValue("startSec" + QString::number(i),timerEdit[i]->time().second());
     settings.setValue("timerLightness" + QString::number(i), timerSlider[i]->value()/10);
  }

  settings.setValue("manualLightness", manualSlider->value()/10);
  settings.endGroup();
  settings.endGroup();
}

void ClightnessProperty::setSettingsToWidget(QString str)
{
    disconnect(this,SIGNAL(adjModeEditSignal()),this,SLOT(adjModeEditSlot()));
    disconnect(this,SIGNAL(allEditSignal()),this,SLOT(allEditSlot()));

    settings.beginGroup(str);
    settings.beginGroup("lightness");
    //亮度调节方式
    int adjMode = settings.value("adjMode").toInt();
    if(adjMode EQ 0)
       manualButton->setChecked(1);
    else
       manualButton->setChecked(0);

    if(adjMode EQ 1)
       timerButton->setChecked(1);
    else
       timerButton->setChecked(0);

    if(adjMode EQ 2)
       autoButton->setChecked(1);
    else
       autoButton->setChecked(0);

    for(int i=0; i < MAX_LIGHTNESS_TIME; i++)
    {
      timerCheck[i]->setChecked(settings.value("timeCheck" + QString::number(i)).toBool());
      QTime time;
      time.setHMS(settings.value("startHour" + QString::number(i)).toInt(), \
                  settings.value("startMin" + QString::number(i)).toInt(),\
                  settings.value("startSec" + QString::number(i)).toInt());
      timerEdit[i]->setTime(time);
      timerSlider[i]->setValue(settings.value("timerLightness" + QString::number(i)).toInt()*10);
      timerLabel[i]->setText(QString::number(timerSlider[i]->value()/10));
    }

    manualSlider->setValue(settings.value("manualLightness").toInt()*10);
    manualLabel->setText(QString::number(manualSlider->value()/10));

    settings.endGroup();
    settings.endGroup();

    adjModeEditSlot();
    sliderEditProc();

    setTitle(tr("亮度参数"));

    connect(this,SIGNAL(adjModeEditSignal()),this,SLOT(adjModeEditSlot()));
    connect(this,SIGNAL(allEditSignal()),this,SLOT(allEditSlot()));
}

ClightnessProperty::~ClightnessProperty()
{

}

CopenCloseProperty::CopenCloseProperty(QWidget *parent):QGroupBox(parent)
{
    INT8U i;

    QHBoxLayout *hLayout;
   QVBoxLayout *vLayout;
   QLabel *openTimeLabel, *closeTimeLabel;

   hLayout = new QHBoxLayout(this);
   QGridLayout *mainLayout = new QGridLayout(this);
   closeTimeLabel = new QLabel(tr("关闭时间"),this);
   openTimeLabel = new QLabel(tr("开启时间"),this);
   mainLayout->addWidget(closeTimeLabel,0,1,1,1,Qt::AlignVCenter|Qt::AlignHCenter);
   mainLayout->addWidget(openTimeLabel,0,3,1,1,Qt::AlignVCenter|Qt::AlignHCenter);

   for(i = 0; i < MAX_OPEN_CLOSE_TIME; i ++)
   {
     timeCheck[i] = new QCheckBox(tr("使用"),this);
     openTimeEdit[i] = new QTimeEdit(this);
     closeTimeEdit[i] = new QTimeEdit(this);

     mainLayout->addWidget(timeCheck[i], 1 + i, 0, 1, 1,Qt::AlignTop);
     mainLayout->addWidget(openTimeEdit[i], 1 + i, 1, 1, 2,Qt::AlignTop);
     mainLayout->addWidget(closeTimeEdit[i], 1 + i, 3, 1, 2,Qt::AlignTop);
   }

   hLayout->addLayout(mainLayout);
   hLayout->addStretch(10);
   setLayout(hLayout);

   for(i =0;i < MAX_LIGHTNESS_TIME; i ++)
   {
     connect(timeCheck[i], SIGNAL(clicked()),this,SIGNAL(TimeEditSignal()));
     connect(openTimeEdit[i],SIGNAL(timeChanged(QTime)),this,SIGNAL(TimeEditSignal()));
     connect(closeTimeEdit[i],SIGNAL(timeChanged(QTime)),this,SIGNAL(TimeEditSignal()));
   }

   connect(this, SIGNAL(TimeEditSignal()), this, SLOT(allEditSlot()));

   setTitle(tr("开关机参数"));
   timeCheckProc();
}

void CopenCloseProperty::timeCheckProc()
{
   for(int i = 0; i < MAX_OPEN_CLOSE_TIME; i ++)
    {
     openTimeEdit[i]->setEnabled(timeCheck[i]->isChecked());
     closeTimeEdit[i]->setEnabled(timeCheck[i]->isChecked());
   }
}

void CopenCloseProperty::allEditSlot()
{
    QString str = w->screenArea->getCurrentScreenStr();//getCurrentStr
    getSettingsFromWidget(str);

    timeCheckProc();
}

void CopenCloseProperty::getSettingsFromWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("openCloseTime");

    for(int i =0; i < MAX_OPEN_CLOSE_TIME;i ++)
    {
        settings.setValue("timeCheck"+QString::number(i), timeCheck[i]->isChecked());
        settings.setValue("openHour"+QString::number(i), openTimeEdit[i]->time().hour());
        settings.setValue("openMin"+QString::number(i),openTimeEdit[i]->time().minute());
        settings.setValue("openSec"+QString::number(i), openTimeEdit[i]->time().second());
        settings.setValue("closeHour"+QString::number(i), closeTimeEdit[i]->time().hour());
        settings.setValue("closeMin"+QString::number(i), closeTimeEdit[i]->time().minute());
        settings.setValue("closeSec"+QString::number(i), closeTimeEdit[i]->time().second());
    }

    settings.endGroup();
    settings.endGroup();
}
//开关机时段属性
void CopenCloseProperty::setSettingsToWidget(QString str)
{
    disconnect(this, SIGNAL(TimeEditSignal()), this, SLOT(allEditSlot()));

    settings.beginGroup(str);
    settings.beginGroup("openCloseTime");

    for(int i =0; i < MAX_OPEN_CLOSE_TIME;i ++)
    {
        timeCheck[i]->setChecked(settings.value("timeCheck"+QString::number(i)).toBool());
        QTime time;
        time.setHMS(settings.value("openHour" + QString::number(i)).toInt(), \
                    settings.value("openMin" + QString::number(i)).toInt(),\
                    settings.value("openSec" + QString::number(i)).toInt());
        openTimeEdit[i]->setTime(time);

        time.setHMS(settings.value("closeHour" + QString::number(i)).toInt(), \
                    settings.value("closeMin" + QString::number(i)).toInt(),\
                    settings.value("closeSec" + QString::number(i)).toInt());
        closeTimeEdit[i]->setTime(time);
    }

    settings.endGroup();
    settings.endGroup();


    timeCheckProc();
    connect(this, SIGNAL(TimeEditSignal()), this, SLOT(allEditSlot()));
}


CopenCloseProperty::~CopenCloseProperty()
{

}
/*
//screen属性窗
class CfacScreenProperty:public QWidget
{
    Q_OBJECT
 QGroupBox *cardGroup;
 QGroupBox *baseParaGroup;
 QGroupBox *advanceParaGroup;

 QComboBox *cardCombo; //选择卡类型
 QTextEdit *cardPara; //卡参数

 //基本参数
 QLineEdit *screenIDEdit; // 屏幕ID
 QComboBox *dataPolarityCombo; //数据极性
 QComboBox *oePolarityCombo; //OE极性
 QComboBox *colorCombo; //颜色
 QLineEdit *widthEdit; //屏宽
 QLineEdit *heightEdit; //屏高
 QCheckBox *138Check;     //是否有138译码器
 QComboBox *scanModeCombo; //扫描方式

 //高级设置
 QCheckBox *defParaCheck; //使用默认参数
 QComboBox *freqCombo; //扫描频率
 QSpinBox *lineHideCombo; //行消隐藏
 //------------------

 QPushButton *endButton;
 QPushButton *readParaButton;
 QPushButton *cancelButton;
 QPushButton *okButton;
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CfacScreenProperty(QWidget *parent=0);
    ~CfacScreenProperty();
};
*/

CipInput::CipInput(QWidget *parent):QWidget(parent)
{/*
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    for(int i = 0; i < 4; i++)
    {

      edit[i] = new QLineEdit(this);
      //edit[i]->setFixedWidth(25);


      QRegExp rx("(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-4]|[01]?\\d\\d?") ;

         //ipLabel = new QLabel(tr("IP Address:"));
        // ipLineEdit = new QLineEdit;
         //ipLabel->setBuddy(ipLineEdit);

         QValidator *validator = new QRegExpValidator(rx, this);
         edit[i]->setValidator(validator);
         edit[i]->setInputMask("000.000.000.000;");


      hLayout->addWidget(edit[i],10);
      if(i!=3)
      {
        QLabel *label = new QLabel(".",this);
        label->setFixedWidth(2);
        hLayout->addWidget(label,1);
      }
    }

    hLayout->addStretch(10);
    setLayout(hLayout);
    */

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    QRegExp rx("(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-4]|[01]?\\d\\d?") ;

    //ipLabel = new QLabel(tr("IP Address:"));
    // ipLineEdit = new QLineEdit;
    //ipLabel->setBuddy(ipLineEdit);

    edit = new QLineEdit(this);
    QValidator *validator = new QRegExpValidator(rx, this);
    edit->setValidator(validator);
    edit->setInputMask("000.000.000.000;");

    hLayout->addWidget(edit);
    setLayout(hLayout);
}

void CipInput::getSettingsFromWidget(QString str)
{

}

void CipInput::setSettingsToWidget(QString str)
{

}

void CipInput::setIP(int ip)
{

}

int CipInput::getIP()
{
  return 0xFFFFFFFF;
}

CipInput::~CipInput()
{

}

CcomTest::CcomTest(QWidget *parent):QGroupBox(parent)
{
  //QVBoxLayout *vLayout = new QVBoxLayout(this);
  QGridLayout *gridLayout = new QGridLayout(this);

  QLabel *comModeLabel = new QLabel(tr("通信方式"),this);
  comModeCombo = new QComboBox(this);
  comModeCombo->addItem(tr("串口"));
  QLabel *screenIDLabel = new QLabel(tr("硬件地址"),this);
  screenIDEdit = new QSpinBox(this);
  QLabel *comPortLabel = new QLabel(tr("串口号"),this);
  comPortEdit = new QComboBox(this);

  //QextSerialPort *comm = new QextSerialPort();
  //comm->setQueryMode(QextSerialPort::EventDriven);

  QextSerialEnumerator enumer;
  QList<QextPortInfo> ports = enumer.getPorts();
  QStringList strlist;

  strlist.clear();
  for( int i = 0; i < ports.count(); ++i)
      strlist << QObject::tr(ports.at(i).portName.toLocal8Bit());
  comPortEdit->addItems(strlist);

  QLabel *comBaudLabel = new QLabel(tr("波特率"),this);
  comBaudCombo = new QComboBox(this);
  comBaudCombo->addItem("9600");
  comBaudCombo->addItem("57600");
  QLabel *ipEditLabel = new QLabel(tr("IP地址"),this);
  ipEdit = new CipInput(this);

  connectButton = new QPushButton(tr("建立连接"),this);

  gridLayout->addWidget(comModeLabel, 0, 0,1,1);
  gridLayout->addWidget(comModeCombo,  0, 1,1,2);
  gridLayout->addWidget(screenIDLabel, 1, 0,1,1);
  gridLayout->addWidget(screenIDEdit, 1,1,1,2);
  gridLayout->addWidget(comPortLabel, 2, 0,1,1);
  gridLayout->addWidget(comPortEdit, 2, 1,1,2);
  gridLayout->addWidget(comBaudLabel, 3, 0,1,1);
  gridLayout->addWidget(comBaudCombo, 3, 1,1,2);
  gridLayout->addWidget(ipEditLabel, 4, 0,1,1);
  gridLayout->addWidget(ipEdit, 4,1,1,2);
  gridLayout->addWidget(connectButton, 5,0,1,3);

  setLayout(gridLayout);

  //------------暂时屏蔽----
  ipEditLabel->setVisible(false);
  ipEdit->setVisible(false);
}

void CcomTest::getSettingsFromWidget(QString str)
{

}

void CcomTest::setSettingsToWidget(QString str)
{

}

CcomTest::~CcomTest()
{

}

//工厂参数编辑
CfacScreenProperty::CfacScreenProperty(QWidget *parent):QGroupBox(parent)
{

    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    QGridLayout *gridLayout;

    QHBoxLayout *mainLayout;
    QVBoxLayout *mainVLayout;

    mainVLayout = new QVBoxLayout(this);
    mainLayout = new QHBoxLayout(this);
    hLayout = new QHBoxLayout(this);

    tabWidget= new QTabWidget(this);
    //setFixedWidth(400);

    //控制组件group
    cardGroup = new QWidget(this);//QGroupBox(tr("控制组件"), this);//CnameEdit(this);
    vLayout = new QVBoxLayout(this);
    cardCombo = new QComboBox(this);
    cardCombo->setFixedWidth(100);

    //获取所有卡的列表
    cardSettings.beginGroup("");
    QStringList cardList = cardSettings.childGroups();
    cardSettings.endGroup();

    cardCombo->addItems(cardList);

    cardParaEdit = new QTextEdit(this);
    //cardParaEdit->setFixedWidth(150);
    cardParaEdit->setFixedHeight(60);


    vLayout->addWidget(cardCombo);
    vLayout->addWidget(cardParaEdit);
    cardGroup->setLayout(vLayout);
    tabWidget-> addTab(cardGroup, tr("控制组件"));



    //-------------
    baseParaGroup = new QWidget(this);//QGroupBox(tr("基本参数"),this);
    screenIDEdit = new QSpinBox(this);
    screenIDEdit->setFixedWidth(WIDTH_0);

    baudCombo = new QComboBox(this);
    baudCombo->addItem("9600");
    baudCombo->addItem("57600");
    baudCombo->setFixedWidth(WIDTH_0);

    redGreenRevCheck = new QCheckBox(tr("红绿取反"),this);

    dataPolarityCombo = new QComboBox(this);
    dataPolarityCombo->addItem(tr("负极性"));
    dataPolarityCombo->addItem(tr("正极性"));
    dataPolarityCombo->setFixedWidth(WIDTH_0);

    oePolarityCombo = new QComboBox(this);
    oePolarityCombo->addItem(tr("低有效"));
    oePolarityCombo->addItem(tr("高有效"));
    oePolarityCombo->setFixedWidth(WIDTH_0);

    colorCombo = new QComboBox(this);
    colorCombo->addItem(tr("单色"));
    colorCombo->addItem(tr("双色"));
    colorCombo->addItem(tr("全彩"));

    colorCombo->setFixedWidth(WIDTH_0);

    widthEdit = new QSpinBox(this);
    widthEdit->setFixedWidth(WIDTH_0);
    widthEdit->setSingleStep(8);
    widthEdit->setMinimum(8);
    widthEdit->setMaximum(4096);
    widthEdit->setFocusPolicy(Qt::NoFocus); //禁止键盘输入

    heightEdit = new QSpinBox(this);
    heightEdit->setFixedWidth(WIDTH_0);
    heightEdit->setSingleStep(8);
    heightEdit->setMinimum(8);
    heightEdit->setMaximum(4096);
    heightEdit->setFocusPolicy(Qt::NoFocus); //禁止键盘输入


    _138Check = new QCheckBox(tr("使用138译码器"),this);
    scanModeCombo = new QComboBox(this);

    QLabel *screenIDLabel  = new QLabel(tr("硬件地址"),this);
    //QLabel *screenIDInfoLabel = new QLabel(tr("(多屏幕组网时每个屏号应该唯一)"),this);
    QLabel *baudComboLabel = new QLabel(tr("波特率"),this);
   QLabel *dataPolarityLabel = new QLabel(tr("数据极性"),this);
   QLabel *oePolarityLabel = new QLabel(tr("OE极性"),this);
   QLabel *colorLabel = new QLabel(tr("颜色"),this);
   QLabel *widthLabel = new QLabel(tr("屏宽"),this);
   QLabel *heightLabel = new QLabel(tr("屏高"),this);
   QLabel *scanModeLabel = new QLabel(tr("扫描方式"),this);

   gridLayout = new QGridLayout(this);

   gridLayout->addWidget(screenIDLabel, 0, 0);
   gridLayout->addWidget(screenIDEdit, 0, 1);
   gridLayout->addWidget(baudComboLabel, 0, 2);
   gridLayout->addWidget(baudCombo, 0, 3);
   gridLayout->addWidget(redGreenRevCheck,0,4,1,2);

   gridLayout->addWidget(dataPolarityLabel, 1, 0);
   gridLayout->addWidget(dataPolarityCombo, 1, 1);
   gridLayout->addWidget(oePolarityLabel, 1, 2);
   gridLayout->addWidget(oePolarityCombo, 1, 3);
   gridLayout->addWidget(_138Check, 1, 4, 1, 2);

   gridLayout->addWidget(widthLabel, 2, 0);
   gridLayout->addWidget(widthEdit, 2, 1);
   gridLayout->addWidget(heightLabel, 2, 2);
   gridLayout->addWidget(heightEdit, 2, 3);

   gridLayout->addWidget(colorLabel, 2, 4);
   gridLayout->addWidget(colorCombo, 2, 5);

   gridLayout->addWidget(scanModeLabel, 3, 0);
   gridLayout->addWidget(scanModeCombo, 3, 1, 1, 5);

   baseParaGroup->setLayout(gridLayout);
   tabWidget->addTab(baseParaGroup, tr("基本参数"));

   //---------------网络参数-------------
   netParaGroup = new QWidget(this);
   gridLayout = new QGridLayout(this);
   //newScreenIDEdit = new QLineEdit(this);
   //newScreenIDEdit->setFixedWidth(40);
   //comModeCombo = new QComboBox(this);

   //ipModeCombo = new QComboBox(this);
   ipEdit = new CipInput(this);
   //newIpEdit = new QLineEdit(this);
   maskEdit = new CipInput(this);
   gateEdit = new CipInput(this);
   macEdit = new CipInput(this);
   //QRegExp rx("(2[0-5]{2}|2[0-4][0-9]|1?[0-9]{1,2})");
   //QRegExpValidator validatorIP(QRegExp("[0-9]{1,3}(.[0-9]{1,3}){3,3}"), this);
   //ipEdit->setValidator(&validatorIP);


   //QLabel *ipModeComboLabel = new QLabel(tr("IP方式"));
   QLabel *ipEditLabel = new QLabel(tr("屏幕IP"),this);
   //QLabel *newIpEditLabel = new QLabel(tr("新IP"),this);
   QLabel *maskEditLabel = new QLabel(tr("子网掩码"),this);
   QLabel *gateEditLabel = new QLabel(tr("网关"),this);
   QLabel *macEditLabel = new QLabel(tr("MAC地址"));


   //QLabel *ipPortLabel = new QLabel(tr("端口: 7788"));



   //gridLayout->addWidget(ipModeComboLabel, 0, 0);
   //gridLayout->addWidget(ipModeCombo, 0, 1);

   gridLayout->addWidget(ipEditLabel, 1, 0);
   gridLayout->addWidget(ipEdit, 1, 1, 1, 3);
   gridLayout->addWidget(maskEditLabel, 1, 4);
   gridLayout->addWidget(maskEdit, 1, 5,1,3);

   gridLayout->addWidget(gateEditLabel, 2, 0);
   gridLayout->addWidget(gateEdit, 2, 1, 1, 3);
   gridLayout->addWidget(macEditLabel, 2, 4);
   gridLayout->addWidget(macEdit, 2, 5, 1, 3);
   //gridLayout->addWidget(ipEditLabel, 3, 0);
   //gridLayout->addWidget(ipEdit, 5, 0, 1, 2);
   //gridLayout->addWidget(ipPortLabel, 6, 0);

   netParaGroup->setLayout(gridLayout);
   tabWidget->addTab(netParaGroup, tr("网络参数"));

   //tabWidget->setTabEnabled(0,false);
   //netParaGroup->setVisible(false);
   //-----------------------------------


   advanceParaGroup = new QWidget(this);//QGroupBox(tr("高级配置"),this);
   defParaCheck = new QCheckBox(tr("使用默认设置"),this);
   freqCombo = new QComboBox(this);

   freqCombo ->addItem(tr("1最快"));
   freqCombo ->addItem(tr("2"));
   freqCombo ->addItem(tr("3"));
   freqCombo ->addItem(tr("4"));
   freqCombo ->addItem(tr("5最慢"));

   lineHideCombo = new QComboBox(this);

   lineHideCombo->addItem(tr("1最短"));
   lineHideCombo->addItem(tr("2"));
   lineHideCombo->addItem(tr("3"));
   lineHideCombo->addItem(tr("4"));
   lineHideCombo->addItem(tr("5"));
   lineHideCombo->addItem(tr("6"));
   lineHideCombo->addItem(tr("7"));
   lineHideCombo->addItem(tr("8"));
   lineHideCombo->addItem(tr("9"));
   lineHideCombo->addItem(tr("10最长"));

   dataMirrorCombo = new QComboBox(this);
   dataMirrorCombo->addItem(tr("正常"));
   dataMirrorCombo->addItem(tr("镜像"));

   lineOrderCombo = new QComboBox(this);

   lineOrderCombo->addItem(tr("正常"));
   lineOrderCombo->addItem(("+1"));
   lineOrderCombo->addItem(("-1"));

   vLayout = new QVBoxLayout(this);

   gridLayout = new QGridLayout(this);
   QLabel *freqLabel = new QLabel(tr("时钟频率"),this);
   QLabel *lineHideLabel = new QLabel(tr("行消隐"),this);
   QLabel *dataMirrorLabel = new QLabel(tr("数据镜像"),this);
   QLabel *lineOrderLabel = new QLabel(tr("行顺序"),this);

   gridLayout->addWidget(defParaCheck,0,0,1,2);

   gridLayout->addWidget(freqLabel, 1, 0);
   gridLayout->addWidget(freqCombo, 1, 1);

   gridLayout->addWidget(lineHideLabel, 1, 2);
   gridLayout->addWidget(lineHideCombo,1,3);

   gridLayout->addWidget(dataMirrorLabel, 2, 0);
   gridLayout->addWidget(dataMirrorCombo, 2, 1);

   gridLayout->addWidget(lineOrderLabel, 2, 2);
   gridLayout->addWidget(lineOrderCombo,2,3);

   advanceParaGroup->setLayout(gridLayout);
   tabWidget->addTab(advanceParaGroup, tr("高级参数"));

   //参数回读
   vLayout = new QVBoxLayout(this);
   hLayout = new QHBoxLayout(this);
   readParaGroup = new QWidget(this);//QGroupBox(tr("参数回传"),this);
   readParaEdit = new QTextEdit(tr("--显示读回参数--"),this);
   //readParaEdit->setFixedWidth(150);
   readParaEdit->setFixedHeight(60);
   readParaButton = new QPushButton(tr("回读参数"),this);
   importParaButton = new QPushButton(tr("导入参数"),this);
   vLayout->addWidget(readParaEdit);
   //hLayout->addStretch();
   hLayout->addWidget(readParaButton);
   hLayout->addWidget(importParaButton);
   vLayout->addLayout(hLayout);
   readParaGroup->setLayout(vLayout);
   tabWidget->addTab(readParaGroup, tr("回读参数"));

   hLayout = new QHBoxLayout(this);
   endButton = new QPushButton(tr("关闭"), this);
   loadButton = new QPushButton(tr("加载参数"), this);
   //exportButton = new QPushButton(tr("导出配置文件"), this);
  // saveButton = new QPushButton(tr("保存参数"), this);
   //defButton = new QPushButton(tr("恢复默认"), this);

   hLayout->addStretch();
   hLayout->addWidget(loadButton);
   hLayout->addStretch();
   hLayout->addWidget(endButton);
   hLayout->addStretch();
   //vLayout->addWidget(exportButton);
   //vLayout->addStretch(10);
   //vLayout->addWidget(cancelButton);
   //hLayout->addStretch(10);
   //hLayout = new QHBoxLayout(this);
   //QGroupBox *comTestGroup = new QGroupBox(this);
   comTest = new CcomTest(this);
   //hLayout->addWidget(comTest);
   //comTestGroup->setLayout(hLayout);

   mainLayout->addWidget(tabWidget);
   //mainLayout->addWidget(endButton);
   mainLayout->addWidget(comTest);
   //mainLayout->addLayout(vLayout);
   mainVLayout->addLayout(mainLayout);
   mainVLayout->addLayout(hLayout);

   //endButton->setVisible(false);
   //loadButton->setVisible(false);

   //mainLayout->addStretch(10);
   setLayout(mainVLayout);


   //this->setEnabled(false);
   //this->setc

  setTitle(tr("安装参数"));
   connect(loadButton, SIGNAL(clicked()), this, SLOT(loadParaProc()));
   connect(endButton, SIGNAL(clicked()), this, SLOT(endProc()));

  //----暂时将网络参数删除！
   tabWidget->removeTab(tabWidget->indexOf(netParaGroup));
}

/*
 //QComboBox *ipModeCombo; //IP获取方式
 //QLineEdit *ipEdit; //IP地址
 CipInput *ipEdit;
 //QLineEdit *newIpEdit; //新IP地址
 CipInput *maskEdit; //子网掩码
 CipInput *gateEdit; //网关掩码
 CipInput *macEdit; //mac地址
 //基本参数
 QSpinBox *screenIDEdit; // 屏幕ID
 QComboBox *baudCombo; //波特率
 QCheckBox *redGreenRevCheck; //红绿
 QComboBox *dataPolarityCombo; //数据极性
 QComboBox *oePolarityCombo; //OE极性

 QComboBox *colorCombo; //颜色
 QSpinBox *widthEdit; //屏宽
 QSpinBox *heightEdit; //屏高
 QCheckBox *_138Check;     //是否有138译码器
 QComboBox *scanModeCombo; //扫描方式

 //高级设置
 QCheckBox *defParaCheck; //使用默认参数
 QComboBox *freqCombo; //扫描频率
 QSpinBox *lineHideCombo; //行消隐藏
 QComboBox *dataMirrorCombo; //数据镜像
 QComboBox *lineOrderCombo; //行顺序
 //------------------

 CcomTest *comTest;
 */

void CfacScreenProperty::getSettingsFromWidget(QString str)
{
  settings.beginGroup(str);
  settings.beginGroup("facPara");

  ipEdit->getSettingsFromWidget(str);
  maskEdit->getSettingsFromWidget(str);
  gateEdit->getSettingsFromWidget(str);
  macEdit->getSettingsFromWidget(str);

  settings.setValue("screenID", screenIDEdit->value()); //硬件地址
  settings.setValue("baud", baudCombo->currentIndex());
  settings.setValue("redGreenRev", redGreenRevCheck->isChecked());
  settings.setValue("dataPolarity", dataPolarityCombo->currentIndex());
  settings.setValue("oePolarity", oePolarityCombo->currentIndex());
  settings.setValue("color", colorCombo->currentIndex());
  settings.setValue("width", widthEdit->value());
  settings.setValue("height", heightEdit->value());
  settings.setValue("_138Check", _138Check->isChecked());
  settings.setValue("scanMode", scanModeCombo->currentIndex());

  settings.setValue("advDefPara", defParaCheck->isChecked());
  settings.setValue("freq", freqCombo->currentIndex());
  settings.setValue("lineHide", lineHideCombo->currentIndex());
  settings.setValue("dataMirror", dataMirrorCombo->currentIndex());
  settings.setValue("lineOrder", lineOrderCombo->currentIndex());

  settings.endGroup();
  settings.endGroup();


}

void CfacScreenProperty::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("facPara");

    ipEdit->setSettingsToWidget(str);
    maskEdit->setSettingsToWidget(str);
    gateEdit->setSettingsToWidget(str);
    macEdit->setSettingsToWidget(str);

    screenIDEdit->setValue(settings.value("screenID").toInt());
    baudCombo->setCurrentIndex(settings.value("baud").toInt());
    redGreenRevCheck->setChecked(settings.value("redGreenRev").toBool());
    dataPolarityCombo->setCurrentIndex(settings.value("dataPolarity").toInt());
    oePolarityCombo->setCurrentIndex(settings.value("oePolarity").toInt());
    colorCombo->setCurrentIndex(settings.value("color").toInt());
    widthEdit->setValue(settings.value("width").toInt());
    heightEdit->setValue(settings.value("height").toInt());
    _138Check->setChecked(settings.value("_138Check").toBool());
    scanModeCombo->setCurrentIndex(settings.value("scanMode").toInt());

    defParaCheck->setChecked(settings.value("advDefPara").toBool());
    freqCombo->setCurrentIndex(settings.value("freq").toInt());
    lineHideCombo->setCurrentIndex(settings.value("lineHide").toInt());
    dataMirrorCombo->setCurrentIndex(settings.value("dataMirror").toInt());
    lineOrderCombo->setCurrentIndex(settings.value("lineOrder").toInt());

    settings.endGroup();
    settings.endGroup();

}

CfacScreenProperty::~CfacScreenProperty()
{

}

void CfacScreenProperty::setEditEnable(bool flag)
{
    if(flag EQ false)
    {
        cardGroup->setEnabled(false);
        netParaGroup->setEnabled(false);
        baseParaGroup->setEnabled(false);
        advanceParaGroup->setEnabled(false);
        readParaGroup->setEnabled(false);
        loadButton->setEnabled(false);
        //exportButton->setEnabled(false);
        //comTest->setEnabled(false);
    }
    else
    {
        cardGroup->setEnabled(true);
        netParaGroup->setEnabled(true);
        baseParaGroup->setEnabled(true);
        advanceParaGroup->setEnabled(true);
        readParaGroup->setEnabled(true);
        loadButton->setEnabled(true);
        //exportButton->setEnabled(true);
        //comTest->setEnabled(true);
    }
}

//加载参数
void CfacScreenProperty::loadParaProc()
{
    QString str;

    str = w->screenArea->getCurrentScreenStr(); //当前屏幕str
    qDebug("loadpara:%s",(const char *)str.toLocal8Bit());
    getSettingsFromWidget(str);
}

void CfacScreenProperty::endProc()
{

}

CsetFacPara::CsetFacPara(QWidget *parent):QMainWindow(parent)
{
    facScreenProperty = new CfacScreenProperty(this);
    this->setCentralWidget(facScreenProperty);
    this->setWindowTitle(tr("设置屏幕参数"));

}

CsetFacPara::~CsetFacPara()
{

}
