#include <QFileDialog>
#include <QSettings>
#include <QMovie>
#include <QInputDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "screenProperty.h"

extern MainWindow *w;
extern QSettings settings;
extern QSettings screenSettings;
extern QSettings cardSettings;

#define WIDTH_0 40
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
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;

    hLayout = new QHBoxLayout(this);

    vLayout = new QVBoxLayout(this);
    nameEdit = new CnameEdit(this);
    vLayout->addWidget(nameEdit);
    vLayout->addStretch(10);
    hLayout->addLayout(vLayout);

    tab = new QTabWidget(this);
    facProperty = new CfacScreenProperty(this);

    //QGroupBox *lightnessGroup = new QGroupBox(tr("亮度调节"),this);
    //vLayout = new QVBoxLayout(this);
    lightnessProperty = new ClightnessProperty(this);
    openCloseProperty = new CopenCloseProperty(this);
    //vLayout->addWidget(lightnessProperty);
    //lightnessGroup->setLayout(vLayout);
    //facProperty->setEnabled(false);
    //facProperty->lockParaButton->setEnabled(true);
    tab->addTab(lightnessProperty, tr("亮度调节"));
    tab->addTab(openCloseProperty, tr("定时开关机"));

    tab->addTab(facProperty, tr("工厂参数"));
    hLayout->addWidget(tab);
    hLayout->addStretch(10);

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
lightnessProperty->getSettingsFromWidget(str);
}

void CscreenProperty::setSettingsToWidget(QString str)
{
lightnessProperty->setSettingsToWidget(str);
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
ClightnessProperty::ClightnessProperty(QWidget *parent):QWidget(parent)
{
    INT8U i;

    QHBoxLayout *hLayout;
   QVBoxLayout *vLayout;
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
   vLayout = new QVBoxLayout(this);

   hLayout = new QHBoxLayout(this);
   manualSlider = new QSlider(Qt::Horizontal,this);
   hLayout->addWidget(manualSlider);
   vLayout->addLayout(hLayout);

   hLayout = new QHBoxLayout(this);
   autoLabel = new QLabel(tr("请确认已安装光照传感器"),this);
   hLayout->addWidget(autoLabel);
   vLayout->addLayout(hLayout);


   QVBoxLayout *timerVLayout = new QVBoxLayout(this);
   for(i = 0; i < MAX_LIGHTNESS_TIME; i ++)
   {
     hLayout = new QHBoxLayout(this);
     timerCheck[i] = new QCheckBox(tr("使用"),this);
     timerEdit[i] = new QTimeEdit(this);
     timerSlider[i] = new QSlider(Qt::Horizontal,this);
     hLayout->addWidget(timerCheck[i]);
     hLayout->addWidget(timerEdit[i]);
     hLayout->addWidget(timerSlider[i]);

     timerVLayout->addLayout(hLayout);
   }

   vLayout->addLayout(timerVLayout);
   groupBox->setLayout(vLayout);
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

   connect(this,SIGNAL(adjModeEditSignal()),this,SLOT(adjModeEditSlot()));
   connect(this,SIGNAL(allEditSignal()),this,SLOT(allEditSlot()));
}

void ClightnessProperty::allEditSlot()
{

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
        }

        autoLabel->setVisible(false);

        manualSlider->setVisible(true);
    }
    else if(timerButton->isChecked())
    {
      for(int i=0; i < MAX_LIGHTNESS_TIME; i ++)
      {
          timerCheck[i]->setVisible(true);
          timerEdit[i]->setVisible(true);
          timerSlider[i]->setVisible(true);
      }

      autoLabel->setVisible(false);
      manualSlider->setVisible(false);
    }
    else if(autoButton->isChecked())
    {
        for(int i=0; i < MAX_LIGHTNESS_TIME; i ++)
        {
            timerCheck[i]->setVisible(false);
            timerEdit[i]->setVisible(false);
            timerSlider[i]->setVisible(false);
        }

        autoLabel->setVisible(true);

        manualSlider->setVisible(false);
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
     settings.setValue("timerLightness" + QString::number(i), timerSlider[i]->value());
  }

  settings.setValue("manualLightness", manualSlider->value());
  settings.endGroup();
  settings.endGroup();
}

void ClightnessProperty::setSettingsToWidget(QString str)
{
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
      timerSlider[i]->setValue(settings.value("timerLightness" + QString::number(i)).toInt());
     }

    manualSlider->setValue(settings.value("manualLightness").toInt());

    settings.endGroup();
    settings.endGroup();
}

ClightnessProperty::~ClightnessProperty()
{

}

CopenCloseProperty::CopenCloseProperty(QWidget *parent):QWidget(parent)
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
 QSpinBox *lineHideBox; //行消隐藏
 //------------------

 QPushButton *lockParaButton;
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
//工厂参数编辑
CfacScreenProperty::CfacScreenProperty(QWidget *parent):QWidget(parent)
{
    QTabWidget *tabWidget;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    QGridLayout *gridLayout;

    QHBoxLayout *mainLayout;

    mainLayout = new QHBoxLayout(this);
    hLayout = new QHBoxLayout(this);

    tabWidget= new QTabWidget(this);
    //setFixedWidth(400);

    //控制组件group
    cardGroup = new QWidget(this);//QGroupBox(tr("控制组件"), this);//CnameEdit(this);
    vLayout = new QVBoxLayout(this);
    cardCombo = new QComboBox(this);
    cardCombo->setFixedWidth(100);
    cardParaEdit = new QTextEdit(this);
    //cardParaEdit->setFixedWidth(150);
    cardParaEdit->setFixedHeight(60);


    vLayout->addWidget(cardCombo);
    vLayout->addWidget(cardParaEdit);
    cardGroup->setLayout(vLayout);
    tabWidget-> addTab(cardGroup, tr("控制组件"));

    comParaGroup = new QWidget(this);//QGroupBox(tr("通信参数"),this);
    gridLayout = new QGridLayout(this);
    screenIDEdit = new QLineEdit(this);
    screenIDEdit->setFixedWidth(40);
    newScreenIDEdit = new QLineEdit(this);
    newScreenIDEdit->setFixedWidth(40);
    comModeCombo = new QComboBox(this);
    baudCombo = new QComboBox(this);
    ipModeCombo = new QComboBox(this);
    ipEdit = new QLineEdit(this);
    newIpEdit = new QLineEdit(this);
    maskEdit = new QLineEdit(this);
    gateEdit = new QLineEdit(this);
    //QRegExp rx("(2[0-5]{2}|2[0-4][0-9]|1?[0-9]{1,2})");
    //QRegExpValidator validatorIP(QRegExp("[0-9]{1,3}(.[0-9]{1,3}){3,3}"), this);
    //ipEdit->setValidator(&validatorIP);

    QLabel *screenIDLabel  = new QLabel(tr("当前屏号"),this);
    QLabel *newScreenIDLabel = new QLabel(tr("新屏号"),this);
    QLabel *screenIDInfoLabel = new QLabel(tr("(多屏幕组网时每个屏号应该唯一)"),this);
    QLabel *comModeLabel = new QLabel(tr("通信方式"),this);
    QLabel *baudComboLabel = new QLabel(tr("波特率"),this);
    QLabel *ipModeComboLabel = new QLabel(tr("IP方式"));
    QLabel *ipEditLabel = new QLabel(tr("当前IP"),this);
    QLabel *newIpEditLabel = new QLabel(tr("新IP"),this);
    QLabel *maskEditLabel = new QLabel(tr("子网掩码"),this);
    QLabel *gateEditLabel = new QLabel(tr("网关"),this);

    //QLabel *ipPortLabel = new QLabel(tr("端口: 7788"));

    gridLayout->addWidget(screenIDLabel, 0, 0);
    gridLayout->addWidget(screenIDEdit, 0, 1);
    gridLayout->addWidget(newScreenIDLabel, 0, 2);
    gridLayout->addWidget(newScreenIDEdit, 0, 3);
    gridLayout->addWidget(screenIDInfoLabel,0, 4, 1, 3);

    gridLayout->addWidget(comModeLabel, 1, 0);
    gridLayout->addWidget(comModeCombo, 1, 1);
    gridLayout->addWidget(baudComboLabel, 1, 2);
    gridLayout->addWidget(baudCombo, 1, 3);
    gridLayout->addWidget(ipModeComboLabel, 1, 4);
    gridLayout->addWidget(ipModeCombo, 1, 5);

    gridLayout->addWidget(ipEditLabel, 2, 0);
    gridLayout->addWidget(ipEdit, 2, 1, 1, 3);
    gridLayout->addWidget(newIpEditLabel, 2, 4);
    gridLayout->addWidget(newIpEdit, 2, 5,1,3);
    gridLayout->addWidget(maskEditLabel, 3, 0);
    gridLayout->addWidget(maskEdit, 3, 1,1,3);
    gridLayout->addWidget(gateEditLabel, 3, 4);
    gridLayout->addWidget(gateEdit, 3, 5, 1, 3);

    //gridLayout->addWidget(ipEditLabel, 3, 0);
    //gridLayout->addWidget(ipEdit, 5, 0, 1, 2);
    //gridLayout->addWidget(ipPortLabel, 6, 0);

    comParaGroup->setLayout(gridLayout);
    tabWidget->addTab(comParaGroup, tr("通信参数"));

    //-------------
    baseParaGroup = new QWidget(this);//QGroupBox(tr("基本参数"),this);
    //sscreenIDEdit= new QLineEdit(this);
    //screenIDEdit->setFixedWidth(WIDTH_0 * 2);

    dataPolarityCombo = new QComboBox(this);
    //dataPolarityCombo->setFixedWidth(WIDTH_0);

    oePolarityCombo = new QComboBox(this);
    //oePolarityCombo->setFixedWidth(WIDTH_0);

    colorCombo = new QComboBox(this);
    //colorCombo->setFixedWidth(WIDTH_0);

    widthEdit = new QLineEdit(this);
    //widthEdit->setFixedWidth(WIDTH_0);

    heightEdit = new QLineEdit(this);
    //heightEdit->setFixedWidth(WIDTH_0);

    _138Check = new QCheckBox(tr("使用138译码器"),this);
    scanModeCombo = new QComboBox(this);


   QLabel *dataPolarityLabel = new QLabel(tr("数据极性"),this);
   QLabel *oePolarityLabel = new QLabel(tr("OE极性"),this);
   QLabel *colorLabel = new QLabel(tr("颜色"),this);
   QLabel *widthLabel = new QLabel(tr("屏宽"),this);
   QLabel *heightLabel = new QLabel(tr("屏高"),this);
   QLabel *scanModeLabel = new QLabel(tr("扫描方式"),this);

   gridLayout = new QGridLayout(this);
   //gridLayout->addWidget(screenIDLabel, 0, 0);
   //gridLayout->addWidget(screenIDEdit, 0, 1, 1, 2);

   gridLayout->addWidget(dataPolarityLabel, 0, 0);
   gridLayout->addWidget(dataPolarityCombo, 0, 1);
   gridLayout->addWidget(oePolarityLabel, 0, 2);
   gridLayout->addWidget(oePolarityCombo, 0, 3);

   gridLayout->addWidget(_138Check, 1, 0, 1, 2);
   gridLayout->addWidget(colorLabel, 1, 2);
   gridLayout->addWidget(colorCombo, 1, 3);

   gridLayout->addWidget(widthLabel, 2, 0);
   gridLayout->addWidget(widthEdit, 2, 1);
   gridLayout->addWidget(heightLabel, 2, 2);
   gridLayout->addWidget(heightEdit, 2, 3);



   gridLayout->addWidget(scanModeLabel, 3, 0);
   gridLayout->addWidget(scanModeCombo, 3, 1, 1, 3);

   baseParaGroup->setLayout(gridLayout);
   tabWidget->addTab(baseParaGroup, tr("基本参数"));

   advanceParaGroup = new QWidget(this);//QGroupBox(tr("高级配置"),this);
   defParaCheck = new QCheckBox(tr("使用默认设置"),this);
   freqCombo = new QComboBox(this);
   lineHideBox = new QSpinBox(this);
   dataMirrorCombo = new QComboBox(this);
   lineOrderCombo = new QComboBox(this);

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
   gridLayout->addWidget(lineHideBox,1,3);

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

   vLayout = new QVBoxLayout(this);
   lockParaButton = new QPushButton(tr("编辑解锁"), this);
   sendButton = new QPushButton(tr("发送参数"), this);
   exportButton = new QPushButton(tr("导出配置文件"), this);
  // saveButton = new QPushButton(tr("保存参数"), this);
   //defButton = new QPushButton(tr("恢复默认"), this);
   vLayout->addWidget(lockParaButton);
   vLayout->addWidget(sendButton);
   vLayout->addWidget(exportButton);
   //vLayout->addStretch(10);
   //vLayout->addWidget(cancelButton);
   //hLayout->addStretch(10);

   mainLayout->addWidget(tabWidget);
   //mainLayout->addWidget(lockParaButton);
   mainLayout->addLayout(vLayout);
   //mainLayout->addStretch(10);
   setLayout(mainLayout);

  setEditEnable(false);
   //this->setEnabled(false);
   //this->setc

   connect(lockParaButton, SIGNAL(clicked()), this, SLOT(lockParaProc()));
    //connect(openButton, SIGNAL(clicked()), this, SLOT(openscreenFile()));
}

CfacScreenProperty::~CfacScreenProperty()
{

}

void CfacScreenProperty::setEditEnable(bool flag)
{
    if(flag EQ false)
    {
        cardGroup->setEnabled(false);
        comParaGroup->setEnabled(false);
        baseParaGroup->setEnabled(false);
        advanceParaGroup->setEnabled(false);
        readParaGroup->setEnabled(false);
        sendButton->setEnabled(false);
        exportButton->setEnabled(false);
    }
    else
    {
        cardGroup->setEnabled(true);
        comParaGroup->setEnabled(true);
        baseParaGroup->setEnabled(true);
        advanceParaGroup->setEnabled(true);
        readParaGroup->setEnabled(true);
        sendButton->setEnabled(true);
        exportButton->setEnabled(true);
    }
}

void CfacScreenProperty::lockParaProc()
{
    if(lockParaButton->text() EQ tr("编辑解锁"))
    {
        bool ok;
        QString text = QInputDialog::getText(this, tr("请输入密码"),
                                             tr("密码"), QLineEdit::Password,
                                             tr(""), &ok);
        if (ok && text EQ "168")
        {
            lockParaButton->setText(tr("保存并锁定"));
            setEditEnable(true);
            //w->property->setWindowModality(Qt::WindowModal);
            //w->property->show();
            //this->show();
       }
       else if(ok)
        {
           QMessageBox::information(0, tr(APP_NAME),
                                    tr("密码错误!"),tr("确定"));

       }
    }
    else
    {
        lockParaButton->setText(tr("编辑解锁"));
        setEditEnable(false);
    }

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
