#include <QApplication>
#include "simpleTextEdit.h"
#include <QGridLayout>
#include <QFontDatabase>
#include <QFontComboBox>
#include <QFontMetrics>
#include <QPainter>
#include <QSize>
#include <QRectF>
#include <QTextEdit>
#include <QSettings>
#include "showArea.h"
//#include "includes.h"
#include "..\led_show.h"
#include "mainwindow.h"

extern MainWindow *w;
extern QSettings settings;

#define TIME_EDIT_WIDTH 40
/*
const S_Mode_Func Mode_Func[]=
{
  {&Move_Left},
  {&Move_Right},
  {&Move_Up},
  {&Move_Down},
  {&Move_Left_Cover},
  {&Move_Right_Cover},
  {&Move_Up_Cover},
  {&Move_Down_Cover},
  {&Move_Left_Up_Cover},
  {&Move_Right_Up_Cover},
  {&Move_Left_Down_Cover},
  {&Move_Right_Down_Cover},
  {&Move_Left_Right_Open},
  {&Move_Up_Down_Open},
  {&Move_Left_Right_Close},
  {&Move_Up_Down_Close},

};
*/
CshowModeCombo::CshowModeCombo(QWidget *parent):QComboBox(parent)
{
    addItem(tr("左移"));
    addItem(tr("右移"));
    addItem(tr("上移"));
    addItem(tr("下移"));
    addItem(tr("左划"));
    addItem(tr("右划"));
    addItem(tr("上划"));
    addItem(tr("下划"));
    addItem(tr("左上划"));
    addItem(tr("右上划"));
    addItem(tr("左下划"));
    addItem(tr("右下划"));
    addItem(tr("左右开帘"));
    addItem(tr("上下开帘"));
    addItem(tr("左右合帘"));
    addItem(tr("上下合帘"));
 }

CshowModeCombo::~CshowModeCombo()
{

}

CshowSpeedCombo::CshowSpeedCombo(QWidget *parent):QComboBox(parent)
{
    addItem(tr("0"));
    addItem(tr("1"));
    addItem(tr("2"));
    addItem(tr("3"));
    addItem(tr("4"));
    addItem(tr("5"));
    addItem(tr("6"));
    addItem(tr("7"));
    addItem(tr("8"));
    addItem(tr("9"));
 }

CshowSpeedCombo::~CshowSpeedCombo()
{

}

CshowModeEdit::CshowModeEdit(QWidget *parent):QGroupBox(parent)
{
    //QGridLayout *gridLayout;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;

    //gridLayout = new QGridLayout(this);
    vLayout=new QVBoxLayout(this);

    setTitle(tr("显示特效"));
    inModeLabel = new QLabel(tr("引入"), this);
    inModeCombo = new CshowModeCombo(this);
    inTimeEdit = new QLineEdit(this);
    inTimeEdit->setFixedWidth(TIME_EDIT_WIDTH);
    inTimeLabel = new QLabel(tr("毫秒"), this);

    hLayout = new QHBoxLayout(this);
    hLayout->addWidget(inModeLabel);
    hLayout->addWidget(inModeCombo);
    hLayout->addWidget(inTimeEdit);
    hLayout->addWidget(inTimeLabel);
    hLayout->addStretch();
    vLayout->addLayout(hLayout);

    outModeLabel = new QLabel(tr("引出"), this);
    outModeCombo = new CshowModeCombo(this);
    outTimeEdit = new QLineEdit(this);
    outTimeEdit->setFixedWidth(TIME_EDIT_WIDTH);
    outTimeLabel = new QLabel(tr("毫秒"), this);

    hLayout = new QHBoxLayout(this);
    hLayout->addWidget(outModeLabel);
    hLayout->addWidget(outModeCombo);
    hLayout->addWidget(outTimeEdit);
    hLayout->addWidget(outTimeLabel);
    hLayout->addStretch();
    vLayout->addLayout(hLayout);

    stayTimeLabel = new QLabel(tr("停留"), this);
    stayTimeEdit = new QLineEdit(this);
    stayTimeEdit->setFixedWidth(TIME_EDIT_WIDTH);
    stayTimeUnitLabel = new QLabel(tr("秒"), this);


    hLayout = new QHBoxLayout(this);
    hLayout->addWidget(stayTimeLabel);
    hLayout->addWidget(stayTimeEdit);
    hLayout->addWidget(stayTimeUnitLabel);
    hLayout->addStretch();
    vLayout->addLayout(hLayout);

    //vLayout->addStretch();
    setLayout(vLayout);
/*
    int width = 80;
    showModeCombo->setFixedWidth(width);
    speedCombo->setFixedWidth(width);
    stayTimeEdit->setFixedWidth(width);
*/
    /*
    gridLayout -> addWidget(showModeLabel, 0, 0);
    gridLayout -> addWidget(showModeCombo, 0, 1);
    gridLayout -> addWidget(speedLabel, 1, 0);
    gridLayout -> addWidget(speedCombo, 1, 1);
    gridLayout -> addWidget(stayTimeLabel, 2, 0);
    gridLayout -> addWidget(stayTimeEdit, 2, 1);
    setLayout(gridLayout);
*/
}

void getShowModeParaFromSettings(QString str, U_File_Para &para)
{
  settings.beginGroup(str);
  para.Pic_Para.In_Mode = (INT8U)settings.value("inMode").toInt();
  para.Pic_Para.In_Time = (INT16U)settings.value("inTime").toInt();
  para.Pic_Para.Out_Mode = (INT8U)settings.value("outMode").toInt();
  para.Pic_Para.Out_Time = (INT16U)settings.value("outTime").toInt();
  para.Pic_Para.Stay_Time = (INT16U)settings.value("stayTime").toInt();
  para.Pic_Para.Stay_Time |= 0x8000; //停留时间单位为秒，因此最高位置1
  settings.endGroup();
}

void CshowModeEdit::getSettingsFromWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("showMode");
    settings.setValue("inMode", inModeCombo->currentIndex());
    settings.setValue("inTime", inTimeEdit->text().toInt());
    settings.setValue("outMode", outModeCombo->currentIndex());
    settings.setValue("outTime", outTimeEdit->text().toInt());
    settings.setValue("stayTime", stayTimeEdit->text().toInt());
    //settings.setValue("text", edit->getEdit()->toPlainText());
    settings.endGroup();
    settings.endGroup();

}

void CshowModeEdit::setSettingsToWidget(QString str)
{
    QStringList keys;
    QString text;

    settings.beginGroup(str);
    settings.beginGroup("showMode");
    int setFlag = settings.value("setFlag").toInt();
    if(setFlag == 0)
    {
      //名字
      settings.setValue("setFlag", 1);
      settings.setValue("inMode", 0);
      settings.setValue("inTime", 50);
      settings.setValue("outMode", 0);
      settings.setValue("outTime", 50);
      settings.setValue("stayTime", 5);
      settings.setValue("text", QString(tr("图文显示")));
    }

    inModeCombo->setCurrentIndex(settings.value("inMode").toInt());
    inTimeEdit->setText(QString::number(settings.value("inTime").toInt()));
    outModeCombo->setCurrentIndex(settings.value("outMode").toInt());
    outTimeEdit->setText(QString::number(settings.value("outTime").toInt()));
    stayTimeEdit->setText(QString::number(settings.value("stayTime").toInt()));
    /*
    text = settings.value("text").toString();
    if(text == "")
        text == QString(tr("图文显示"));
    //textEdit->clear();
    edit->getEdit()->setPlainText(text);*/
    settings.endGroup();
    settings.endGroup();
}

CshowModeEdit::~CshowModeEdit()
{

}


CsmLineCombo::CsmLineCombo(QWidget *parent):QComboBox(parent)
{
    QHBoxLayout *hLayout;

    //editGroup = new QGroupBox(this);
    //smLineCombo = new QComboBox(this);

    addItem(tr("单行字幕"));
    addItem(tr("多行文本"));

    //hLayout = new QHBoxLayout(this);
    //hLayout->addWidget(smLineCombo);

    //setTitle(tr("单/多行"));
    //setLayout(hLayout);

    connect(this, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
}

//从Widget上获取设置
void CsmLineCombo::getSettingsFromWidget(QString str)
{
   settings.beginGroup(str);
   settings.beginGroup("smLine");
   settings.setValue("smLineCheck", currentIndex());
   settings.endGroup();
   settings.endGroup();
}

void CsmLineCombo::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("smLine");
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag == 0)
    {
       settings.setValue("smLineCheck", 0);
       settings.setValue("setFlag", 1);
    }
    setCurrentIndex(settings.value("smLineCheck").toInt());
    settings.endGroup();
    settings.endGroup();
}

CsmLineCombo::~CsmLineCombo()
{

}

///--------//
CsmLineEdit::CsmLineEdit(QWidget *parent):QGroupBox(parent)
{
    //QHBoxLayout *hLayout;
    QGridLayout *gridLayout;
    QVBoxLayout *vLayout;
    QLabel *label;

    //editGroup = new QGroupBox(this);
    smLineCombo = new QComboBox(this);

    smLineCombo->addItem(tr("单行"));
    smLineCombo->addItem(tr("多行"));
    label = new QLabel(tr("间距"),this);
    lineSpaceEdit = new QSpinBox(this);

    lineSpaceEdit->setMinimum(0);
    lineSpaceEdit->setMaximum(255);

    gridLayout = new QGridLayout(this);
    gridLayout->addWidget(smLineCombo,0,0,1,2);
    gridLayout->addWidget(label, 1, 0);
    gridLayout->addWidget(lineSpaceEdit, 1,1);

    setTitle(tr("单/多行"));
    setLayout(gridLayout);

    connect(smLineCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(lineSpaceEdit, SIGNAL(valueChanged(int)),this,SIGNAL(edited()));
    //connect(smLineCombo, SIGNAL(currentIndexChanged(int)),this,SLOT(smLineChanged(int)));
}

//从Widget上获取设置
void CsmLineEdit::getSettingsFromWidget(QString str)
{
   settings.beginGroup(str);
   settings.beginGroup("smLine");
   settings.setValue("smLineCheck", smLineCombo->currentIndex());
   settings.setValue("lineSpace", lineSpaceEdit->value());
   settings.endGroup();
   settings.endGroup();
}

void CsmLineEdit::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("smLine");
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag == 0)
    {
       settings.setValue("smLineCheck", 0);
       settings.setValue("lineSpace", 0);
       settings.setValue("setFlag", 1);
    }
    smLineCombo->setCurrentIndex(settings.value("smLineCheck").toInt());
    lineSpaceEdit->setValue(settings.value("lineSpace").toInt());
    //smLineChanged(smLineCombo->currentIndex());
    settings.endGroup();
    settings.endGroup();
}

void CsmLineEdit::smLineChanged(int index)
{
  if(index == 0)
      lineSpaceEdit->setEnabled(false);
  else
      lineSpaceEdit->setEnabled(true);
}

CsmLineEdit::~CsmLineEdit()
{

}
///--------//
CdateEdit::CdateEdit(QWidget *parent):QWidget(parent)
{
    QHBoxLayout *hLayout;
    QLabel *label;

    dateCheck = new QCheckBox(tr("日期"),this);
    dateCombo = new QComboBox(this);
    dateCombo->addItem(tr("2000年12月30日"));
    dateCombo->addItem(tr("00年12月30日"));
    dateCombo->addItem(tr("12/30/2000"));
    dateCombo->addItem(tr("2000/12/30"));
    dateCombo->addItem(tr("00-12-30"));
    dateCombo->addItem(tr("00.12.30"));
    dateCombo->addItem(tr("12月30"));
    dateCombo->addItem(tr("12.30.2000"));
    dateCombo->addItem(tr("2000-12-30"));
    dateCombo->addItem(tr("2000"));
    dateCombo->addItem(tr("12"));
    dateCombo->addItem(tr("30"));

    colorCombo = new CcolorCombo(this);
    sizeCombo = new CsizeCombo(this);

    hLayout = new QHBoxLayout(this);
    hLayout->addWidget(dateCheck);
    hLayout->addWidget(dateCombo);
    //label = new QLabel(tr("颜色"), this);
    //hLayout->addWidget(label);
    hLayout->addWidget(sizeCombo);
    hLayout->addWidget(colorCombo);
    hLayout->addStretch();
    //label = new QLabel(tr("大小"), this);
    //hLayout->addWidget(label);


    setLayout(hLayout);

    connect(dateCheck, SIGNAL(stateChanged(int)),this,SIGNAL(edited()));
    connect(dateCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(colorCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(sizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
}

//从Widget上获取设置
void CdateEdit::getSettingsFromWidget(QString str)
{
   settings.beginGroup(str);
   settings.beginGroup("dateEdit");
   settings.setValue("checked", dateCheck->isChecked());
   settings.setValue("type", dateCombo->currentIndex());
   settings.setValue("color", colorCombo->currentIndex());
   settings.setValue("size", sizeCombo->currentIndex());
   settings.endGroup();
   settings.endGroup();
}

void CdateEdit::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("dateEdit");
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag EQ 0)
    {
       settings.setValue("checked", 0);
       settings.setValue("type", 0);
       settings.setValue("color", 0);
       settings.setValue("size", 0);

       settings.setValue("setFlag", 1);
    }
    dateCheck->setChecked(settings.value("checked").toBool());
    dateCombo->setCurrentIndex(settings.value("type").toInt());
    colorCombo->setCurrentIndex(settings.value("color").toInt());
    sizeCombo->setCurrentIndex(settings.value("size").toInt());
    settings.endGroup();
    settings.endGroup();
}

CdateEdit::~CdateEdit()
{

}

CweekEdit::CweekEdit(QWidget *parent):QWidget(parent)
{
    QHBoxLayout *hLayout;
    QLabel *label;

    weekCheck = new QCheckBox(tr("星期"),this);
    weekCombo = new QComboBox(this);
    weekCombo->addItem(tr("星期一"));
    weekCombo->addItem(tr("Monday"));
    weekCombo->addItem(tr("Mon"));
    weekCombo->addItem(tr("Lunedi"));
    weekCombo->addItem(tr("Montag"));
    weekCombo->addItem(tr("Lundi"));
    weekCombo->addItem(tr("げつうび"));

    colorCombo = new CcolorCombo(this);
    sizeCombo = new CsizeCombo(this);

    hLayout = new QHBoxLayout(this);
    hLayout->addWidget(weekCheck);
    hLayout->addWidget(weekCombo);
    //label = new QLabel(tr("颜色"), this);
    //hLayout->addWidget(label);
    hLayout->addWidget(sizeCombo);
    hLayout->addWidget(colorCombo);
    //label = new QLabel(tr("大小"), this);
    //hLayout->addWidget(label);
    hLayout->addStretch();

    hLayout->addStretch();
    setLayout(hLayout);

    connect(weekCheck, SIGNAL(stateChanged(int)),this,SIGNAL(edited()));
    connect(weekCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(colorCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(sizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
}

//从Widget上获取设置
void CweekEdit::getSettingsFromWidget(QString str)
{
   settings.beginGroup(str);
   settings.beginGroup("weekEdit");
   settings.setValue("checked", weekCheck->isChecked());
   settings.setValue("type", weekCombo->currentIndex());
   settings.setValue("color", colorCombo->currentIndex());
   settings.setValue("size", sizeCombo->currentIndex());
   settings.endGroup();
   settings.endGroup();
}

void CweekEdit::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("weekEdit");
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag EQ 0)
    {
       settings.setValue("checked", 0);
       settings.setValue("type", 0);
       settings.setValue("color", 0);
       settings.setValue("size", 0);

       settings.setValue("setFlag", 1);
    }
    weekCheck->setChecked(settings.value("checked").toBool());
    weekCombo->setCurrentIndex(settings.value("type").toInt());
    colorCombo->setCurrentIndex(settings.value("color").toInt());
    sizeCombo->setCurrentIndex(settings.value("size").toInt());
    settings.endGroup();
    settings.endGroup();
}

CweekEdit::~CweekEdit()
{

}

CtimeEdit::CtimeEdit(QWidget *parent):QWidget(parent)
{
    QHBoxLayout *hLayout;
    QLabel *label;

    timeCheck = new QCheckBox(tr("时间"),this);
    timeCombo = new QComboBox(this);
    timeCombo->addItem(tr("12时59分59秒"));
    timeCombo->addItem(tr("12:59:59"));
    timeCombo->addItem(tr("12时59分"));
    timeCombo->addItem(tr("12:59"));
    timeCombo->addItem(tr("12时"));
    timeCombo->addItem(tr("59分"));
    timeCombo->addItem(tr("59秒"));
    timeCombo->addItem(tr("上午 8:59"));
    timeCombo->addItem(tr("AM 8:59"));
    timeCombo->addItem(tr("8:59 上午"));
    timeCombo->addItem(tr("8:59 AM"));

    colorCombo = new CcolorCombo(this);
    sizeCombo = new CsizeCombo(this);

    hLayout = new QHBoxLayout(this);
    hLayout ->addWidget(timeCheck);
    hLayout->addWidget(timeCombo);
    //label = new QLabel(tr("颜色"), this);
    //hLayout->addWidget(label);
    hLayout->addWidget(sizeCombo);
    hLayout->addWidget(colorCombo);
    //label = new QLabel(tr("大小"), this);
    //hLayout->addWidget(label);
    hLayout->addStretch();

    setLayout(hLayout);

    connect(timeCheck, SIGNAL(stateChanged(int)),this,SIGNAL(edited()));
    connect(timeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(colorCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(sizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
}

//从Widget上获取设置
void CtimeEdit::getSettingsFromWidget(QString str)
{
   settings.beginGroup(str);
   settings.beginGroup("timeEdit");
   settings.setValue("checked", timeCheck->isChecked());
   settings.setValue("type", timeCombo->currentIndex());
   settings.setValue("color", colorCombo->currentIndex());
   settings.setValue("size", sizeCombo->currentIndex());
   settings.endGroup();
   settings.endGroup();
}

void CtimeEdit::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("timeEdit");
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag EQ 0)
    {
       settings.setValue("checked", 0);
       settings.setValue("type", 0);
       settings.setValue("color", 0);
       settings.setValue("size", 0);

       settings.setValue("setFlag", 1);
    }

    timeCheck->setChecked(settings.value("checked").toBool());
    timeCombo->setCurrentIndex(settings.value("type").toInt());
    colorCombo->setCurrentIndex(settings.value("color").toInt());
    sizeCombo->setCurrentIndex(settings.value("size").toInt());
    settings.endGroup();
    settings.endGroup();
}

CtimeEdit::~CtimeEdit()
{

}

//-----------
CtimeDiffEdit::CtimeDiffEdit(QWidget *parent):QGroupBox(parent)
{
  QHBoxLayout *hLayout;
  QLabel *label;

  hLayout =new QHBoxLayout(this);
  label = new QLabel(tr("时差"), this);
  hLayout->addWidget(label);

  diffFlag = new QComboBox(this);
  diffFlag->addItem(tr("+"));
  diffFlag->addItem(tr("-"));
  hLayout->addWidget(diffFlag);

  label = new QLabel(tr("小时"), this);
  hLayout->addWidget(label);
  hourEdit = new QSpinBox(this);
  hourEdit->setMinimum(0);
  hourEdit->setMaximum(23);
  hLayout->addWidget(hourEdit);

  label = new QLabel(tr("分钟"), this);
  hLayout->addWidget(label);
  minEdit = new QSpinBox(this);
  minEdit->setMinimum(0);
  minEdit->setMaximum(59);
  hLayout->addWidget(minEdit);

  setLayout(hLayout);
  setTitle(tr("时差调整"));

  connect(diffFlag, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
  connect(hourEdit, SIGNAL(valueChanged(int)),this,SIGNAL(edited()));
  connect(minEdit, SIGNAL(valueChanged(int)),this,SIGNAL(edited()));

}

//从Widget上获取设置
void CtimeDiffEdit::getSettingsFromWidget(QString str)
{
   settings.beginGroup(str);
   settings.beginGroup("timeDiff");
   settings.setValue("diffFlag", diffFlag->currentIndex());
   settings.setValue("hour", hourEdit->value());
   settings.setValue("min", minEdit->value());
   settings.endGroup();
   settings.endGroup();
}

void CtimeDiffEdit::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("timeDiff");
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag EQ 0)
    {
        settings.setValue("diffFlag", 0);
        settings.setValue("hour", 0);
        settings.setValue("min", 0);

       settings.setValue("setFlag", 1);
    }

    diffFlag->setCurrentIndex(settings.value("diffFlag").toInt());
    hourEdit->setValue(settings.value("hour").toInt());
    minEdit->setValue(settings.value("min").toInt());
    settings.endGroup();
    settings.endGroup();
}

CtimeDiffEdit::~CtimeDiffEdit()
{

}
//----------------
CdateTimeEdit::CdateTimeEdit(QWidget *parent):QGroupBox(parent)
{
    QVBoxLayout *vLayout;
    QGridLayout *gridLayout;

    vLayout = new QVBoxLayout(this);

    //editGroup = new QGroupBox(tr("时间"),this);
    dateEdit = new CdateEdit(this);
    weekEdit = new CweekEdit(this);
    timeEdit = new CtimeEdit(this);

    vLayout->addWidget(dateEdit);
    vLayout->addWidget(weekEdit);
    vLayout->addWidget(timeEdit);
    //editGroup->setLayout(vLayout);

    //gridLayout = new QGridLayout(this);
    //gridLayout->addWidget(editGroup, 0, 0);
    setTitle(tr("时间"));
    setLayout(vLayout);

    connect(dateEdit, SIGNAL(edited()),this,SIGNAL(edited()));
    connect(timeEdit, SIGNAL(edited()),this,SIGNAL(edited()));
    connect(weekEdit, SIGNAL(edited()),this,SIGNAL(edited()));
}

//从Widget上获取设置
void CdateTimeEdit::getSettingsFromWidget(QString str)
{
    dateEdit->getSettingsFromWidget(str);
    timeEdit->getSettingsFromWidget(str);
    weekEdit->getSettingsFromWidget(str);
}

void CdateTimeEdit::setSettingsToWidget(QString str)
{
    dateEdit->setSettingsToWidget(str);
    timeEdit->setSettingsToWidget(str);
    weekEdit->setSettingsToWidget(str);
}

CdateTimeEdit::~CdateTimeEdit()
{

}
//--------------
ClunEdit::ClunEdit(QWidget *parent):QGroupBox(parent)
{
    QGridLayout *gridLayout;

    tianganCheck = new QCheckBox(tr("天干"), this);
    nongliCheck = new QCheckBox(tr("农历"), this);
    jieqiCheck = new QCheckBox(tr("节气"), this);

    tianganColor = new CcolorCombo(this);
    nongliColor = new CcolorCombo(this);
    jieqiColor = new CcolorCombo(this);

    tianganFont = new CsizeCombo(this);
    nongliFont = new CsizeCombo(this);
    jieqiFont = new CsizeCombo(this);

    gridLayout = new QGridLayout(this);

    gridLayout ->addWidget(tianganCheck, 0, 0);
    gridLayout ->addWidget(nongliCheck, 1, 0);
    gridLayout ->addWidget(jieqiCheck, 2, 0);
    gridLayout ->addWidget(tianganFont, 0, 1);
    gridLayout ->addWidget(nongliFont, 1, 1);
    gridLayout ->addWidget(jieqiFont, 2, 1);
    gridLayout ->addWidget(tianganColor, 0, 2);
    gridLayout ->addWidget(nongliColor, 1, 2);
    gridLayout ->addWidget(jieqiColor, 2, 2);

    setLayout(gridLayout);
    setTitle(tr("显示内容"));

    connect(tianganCheck, SIGNAL(stateChanged(int)),this,SIGNAL(edited()));
    connect(nongliCheck, SIGNAL(stateChanged(int)),this,SIGNAL(edited()));
    connect(jieqiCheck, SIGNAL(stateChanged(int)),this,SIGNAL(edited()));

    connect(tianganColor, SIGNAL(currentIndexChanged (int)),this,SIGNAL(edited()));
    connect(nongliColor, SIGNAL(currentIndexChanged (int)),this,SIGNAL(edited()));
    connect(jieqiColor, SIGNAL(currentIndexChanged (int)),this,SIGNAL(edited()));

    connect(tianganFont, SIGNAL(currentIndexChanged (int)),this,SIGNAL(edited()));
    connect(nongliFont, SIGNAL(currentIndexChanged (int)),this,SIGNAL(edited()));
    connect(jieqiFont, SIGNAL(currentIndexChanged (int)),this,SIGNAL(edited()));
}

//从Widget上获取设置
void ClunEdit::getSettingsFromWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("lunEdit");
    settings.setValue("tianganCheck", tianganCheck->isChecked());
    settings.setValue("tianganSize", tianganFont->currentIndex());
    settings.setValue("tianganColor", tianganColor->currentIndex());
    settings.setValue("nongliCheck", nongliCheck->isChecked());
    settings.setValue("nongliSize", nongliFont->currentIndex());
    settings.setValue("nongliColor", nongliColor->currentIndex());
    settings.setValue("jieqiCheck", jieqiCheck->isChecked());
    settings.setValue("jieqiSize", jieqiFont->currentIndex());
    settings.setValue("jieqiColor", jieqiColor->currentIndex());
    settings.endGroup();
    settings.endGroup();

}

void ClunEdit::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("lunEdit");
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag EQ 0)
    {
      settings.setValue("tianganCheck", 1);
      settings.setValue("setFlag", 1);

    }

    tianganCheck->setChecked(settings.value("tianganCheck").toBool());
    tianganFont->setCurrentIndex(settings.value("tianganSize").toInt());
    tianganColor->setCurrentIndex(settings.value("tianganColor").toInt());

    nongliCheck->setChecked(settings.value("nongliCheck").toBool());
    nongliFont->setCurrentIndex(settings.value("nongliSize").toInt());
    nongliColor->setCurrentIndex(settings.value("nongliColor").toInt());

    jieqiCheck->setChecked(settings.value("jieqiCheck").toBool());
    jieqiFont->setCurrentIndex(settings.value("jieqiSize").toInt());
    jieqiColor->setCurrentIndex(settings.value("jieqiColor").toInt());
    settings.endGroup();
    settings.endGroup();
}

ClunEdit::~ClunEdit()
{

}
//---------
CnameEdit::CnameEdit(QWidget *parent):QGroupBox(parent)
{
    QHBoxLayout *hLayout;

    hLayout = new QHBoxLayout(this);

    setTitle(tr("名字"));
    nameEdit = new QLineEdit(this);
    nameEdit->setFixedWidth(100);
    nameEdit->setMaxLength(16);
    hLayout->addWidget(nameEdit);
    setLayout(hLayout);

    connect(nameEdit, SIGNAL(editingFinished()),this,SLOT(edited()));
}

void CnameEdit::edited()
{
    CshowArea *area;
    QTreeWidgetItem *item;

    area = w->screenArea->getFocusArea(); //当前焦点分区

    //if(area != (CshowArea *)0) //
    {
        //当前选中的item
        item = w->progManage->treeWidget->currentItem();////// //w->progManage->treeWidget->currentItem();
        if(item != (QTreeWidgetItem *)0)
        {
            QString str = item->data(0,Qt::UserRole).toString();
            getSettingsFromWidget(str);
            w->progManage->updateTextHead(item->parent());
         }
    }
}

//从Widget上获取设置
void CnameEdit::getSettingsFromWidget(QString str)
{


    settings.beginGroup(str);
    settings.beginGroup("name");
    settings.setValue("name", nameEdit->text());
    settings.endGroup();
    settings.endGroup();


}

void CnameEdit::setSettingsToWidget(QString str)
{
    disconnect(nameEdit, SIGNAL(textEdited(const QString &)),this,SLOT(edited()));

    settings.beginGroup(str);
    settings.beginGroup("name");
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag EQ 0)
    {
      settings.setValue("name", QString(""));
      settings.setValue("setFlag", 1);

    }

    nameEdit->setText(settings.value("name").toString());
    settings.endGroup();
    settings.endGroup();

    connect(nameEdit, SIGNAL(textEdited(const QString &)),this,SLOT(edited()));
}


CnameEdit::~CnameEdit()
{

}
//----------
//------------------------
//简单文本编辑框
CsimpleTextEdit::CsimpleTextEdit(QWidget *parent):QGroupBox(parent)
{
    QHBoxLayout *hLayout;
    //QVBoxLayout *vLayout;
  QGridLayout *gridLayout, *mainLayout;
  QFontDatabase db;


  //vLayout = new QVBoxLayout(this);
  gridLayout = new QGridLayout(this);
  mainLayout = new QGridLayout(this);

  fontLabel = new QLabel(tr("字体"), this);
  //fontSizeLabel = new QLabel(tr("大小"), this);
  //colorLabel = new QLabel(tr("颜色"), this);

  fontCombo = new QFontComboBox(this);
  fontCombo->setFixedWidth(100);

  fontSizeCombo = new QComboBox(this);
  //fontSizeCombo->setobjectName("comboSize");
  fontSizeCombo->setEditable(true);

  foreach(int size, db.standardSizes())
    fontSizeCombo->addItem(QString::number(size));
    //connect(comboSize, SIGNAL(activated(const QString &)),
    //this, SLOT(textSize(const QString &)));
  fontSizeCombo->setCurrentIndex(fontSizeCombo->findText(QString::number(QApplication::font().pointSize())));

  colorCombo = new CcolorCombo(this);
//-------------


  //---------------
  bButton = new QPushButton(tr("粗体"),this);
  iButton = new QPushButton(tr("斜体"),this);
  uButton = new QPushButton(tr("下划"), this);
  editCheck = new QCheckBox(tr("固定文本"), this);

  //oButton = new QPushButton(tr("打开"),this);
  int width = 30;
  bButton->setFixedWidth(width);
  iButton->setFixedWidth(width);
  uButton->setFixedWidth(width);

  bButton->setCheckable(true);
  iButton->setCheckable(true);
  uButton->setCheckable(true);
  //oButton->setCheckable(true);

  QLabel *textLabel = new QLabel(tr("文字"), this);
  lineEdit = new QLineEdit(this);

  hLayout = new QHBoxLayout(this);
  hLayout -> addWidget(fontLabel);
  hLayout -> addWidget(fontCombo);
  //hLayout -> addWidget(fontSizeLabel);
  hLayout -> addWidget(fontSizeCombo);
  //hLayout -> addWidget(colorLabel);
  hLayout -> addWidget(colorCombo);
  hLayout ->addStretch();
  gridLayout->addLayout(hLayout, 0, 0);

  hLayout = new QHBoxLayout(this);
  hLayout -> addWidget(bButton);
  hLayout -> addWidget(iButton);
  hLayout -> addWidget(uButton);
  hLayout -> addWidget(editCheck);
  hLayout->addStretch();
  gridLayout->addLayout(hLayout, 1, 0);

  hLayout = new QHBoxLayout(this);
  hLayout -> addWidget(textLabel);
  hLayout -> addWidget(lineEdit);
  hLayout->addStretch();
  //hLayout -> addWidget(oButton);
  gridLayout->addLayout(hLayout, 2, 0);

  //lineEdit->setSizePolicy();
  /*
  hLayout = new QHBoxLayout(this);

  hLayout -> addWidget(lineEdit);
  hLayout->addStretch();
  gridLayout->addLayout(hLayout, 2, 0);
*/
  //textGroup = new QGroupBox(tr("固定文本"), this);
  //textGroup -> setLayout(gridLayout);
  //mainLayout->addWidget(textGroup, 0, 0);
  setTitle(tr("固定文本"));
  setLayout(gridLayout);

  //所有的消息统一到一个消息
  connect(fontCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
  connect(fontSizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
  connect(colorCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
  connect(bButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
  connect(iButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
  connect(uButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
  connect(editCheck, SIGNAL(stateChanged(int)),this,SIGNAL(edited()));
  connect(lineEdit, SIGNAL(textEdited(const QString &)),this,SIGNAL(edited()));
}

/*
QFont font("times", 24);
QFontMetrics fm(font);
int pixelsWide = fm.width("What's the width of this text?");
int pixelsHigh = fm.height();
 */
//获取文本的像素
QImage getLineTextImage(QString str)
{
    bool uText, bText, iText;
    bool editCheck;
    QString text;
    QPainter painter;
    //QFontComboBox fontComboBox;
    //QComboBox fontSizeComboBox;

    settings.beginGroup(str);
    settings.beginGroup("simpleTextEdit");
    text = settings.value("text").toString();
    uText = settings.value("uText").toBool();
    bText = settings.value("bText").toBool();
    iText = settings.value("iText").toBool();
    editCheck = settings.value("editCheck").toBool();
    if(editCheck == false)
    {
        settings.endGroup();
        settings.endGroup();
        return QImage(0,0, QImage::Format_RGB32);
    }

    QString fontName = settings.value("fontName").toString();
    //fontComboBox.setCurrentIndex(i);
    int fontSize = settings.value("fontSize").toInt();
    //fontSizeComboBox.setCurrentIndex(i);
    int color = settings.value("color").toInt();
    //QFont font(fontComboBox.currentText(), fontSizeComboBox.currentText().toInt());
    settings.endGroup();
    settings.endGroup();

    QFont font(fontName, fontSize);

    font.setStyleStrategy(QFont::NoAntialias);//关闭抗锯齿

    font.setUnderline(uText);
    font.setBold(bText);
    font.setItalic(iText);

    QFontMetrics fm(font);
    int width = fm.width(text);
    int height = fm.height();

    QImage image(width, height, QImage::Format_RGB32);

    painter.begin(&image);
    painter.fillRect(0,0,width,height,Qt::black);

/*
    if(color == 0x00)
        painter.setPen(QColor(Qt::red));
    else if(color == 0x01)
        painter.setPen(QColor(Qt::green));
    else
        painter.setPen(QColor(Qt::yellow));
*/

    painter.setPen(getQColor((0x01 <<color)));
    painter.setFont(font);

    //QString str = lineEdit->text();//edit.document()->toPlainText();//lineEdit->text();//document()->toPlainText ();
    painter.drawText(0,0,width,height,Qt::AlignCenter, text);
    painter.end();
/*
    if(image.save("d:\\line.png")== false)
    {
      qDebug("save image failed");
    }
*/

    return image;

}

void print_color(QRgb c)
{
  qDebug("red = %x", qRed(c));
  qDebug("green = %x", qGreen(c));
  qDebug("blue = %x", qBlue(c));
  qDebug("alpha = %x", qAlpha(c));
}
/*
//image转化为buf形显示数据
QSize imageToShowData(QImage image, char buf[], INT16U width, INT16U x, INT16U y)
{
    QSize size;
    QRgb rgb,r,g,b,ye;
    int i,j;

    for(i = 0; i < image.width(); i ++)
        for(j = 0; j < image.height(); j ++)
        {
          rgb = image.pixel(i,j);
          r = qRed(rgb);
          g = qGreen(rgb);
          b = qBlue(rgb);

          if(r > ANTIALIAS_VALUE && g == 0 && b == 0)// == red.rgb())
          {
              Set_Area_Point_Data(pDst, 0, x + i, y + j, 0x01);
              //qDebug("red");
          }
          else if(g > ANTIALIAS_VALUE && r == 0 && b == 0)// || rgb == 0xFF7F9Db9)
          {
              Set_Area_Point_Data(pDst, 0, x + i, y + j, 0x02);
              //qDebug("green");
          }
          else if(r > ANTIALIAS_VALUE && g>ANTIALIAS_VALUE && b == 0)
          {
              Set_Area_Point_Data(pDst, 0, x + i, y + j, 0x04);
              //qDebug("yellow");
          }
          else //if((r == 0 && g == 0 && b == 0) || rgb == 0xFF7F9DB9)
          {
              Set_Area_Point_Data(pDst, 0, x + i, y + j, 0x00);
              //qDebug("black");
          }

        }
    size.setWidth(image.width());
    size.setHeight(image.height());
    return size;

}
*/
//
QSize getTextShowData(QImage image, S_Show_Data *pDst, INT16U x, INT16U y)
{
  //QImage image;
  QSize size;
  //QColor red(Qt::red);
  //QColor green(Qt::green);
  //QColor yellow(Qt::yellow);
  //QColor black(Qt::black);
  QRgb rgb,r,g,b,ye;
  int i,j;
  INT8U colorData;

  //image = getTextImage(str);
  for(i = 0; i < image.width(); i ++)
      for(j = 0; j < image.height(); j ++)
      {
        rgb = image.pixel(i,j);
        r = qRed(rgb);
        g = qGreen(rgb);
        b = qBlue(rgb);
        //ye = QColor(rgb).yellow();

        if(r > ANTIALIAS_VALUE && g == 0 && b == 0)// == red.rgb())
        {
            colorData = getColorData(QColor(Qt::red));
            Set_Area_Point_Data(pDst, 0, x + i, y + j, colorData);
            //qDebug("red");
        }
        else if(g > ANTIALIAS_VALUE && r == 0 && b == 0)// || rgb == 0xFF7F9Db9)
        {
            colorData = getColorData(QColor(Qt::green));
            Set_Area_Point_Data(pDst, 0, x + i, y + j, colorData);
            //qDebug("green");
        }
        else if(r > ANTIALIAS_VALUE && g>ANTIALIAS_VALUE && b == 0)
        {
            colorData = getColorData(QColor(Qt::yellow));
            Set_Area_Point_Data(pDst, 0, x + i, y + j, colorData);
            //qDebug("yellow");
        }
        else //if((r == 0 && g == 0 && b == 0) || rgb == 0xFF7F9DB9)
        {
            //colorData = getColorData(QColor(Qt::red));
            Set_Area_Point_Data(pDst, 0, x + i, y + j, 0);
            //qDebug("black");
        }/*
        else
        {
            print_color(rgb);
            //qDebug("other", rgb);
            //ASSERT_FAILED();
        }*/

      }
  size.setWidth(image.width());
  size.setHeight(image.height());
  return size;
}

//从Widget上获取设置
void CsimpleTextEdit::getSettingsFromWidget(QString str)
{
   settings.beginGroup(str);
   settings.beginGroup("simpleTextEdit");
   settings.setValue("fontIndex", fontCombo->currentIndex());
   settings.setValue("fontSizeIndex", fontSizeCombo->currentIndex());
   settings.setValue("fontName", fontCombo->currentText());
   settings.setValue("fontSize", fontSizeCombo->currentText().toInt());

   settings.setValue("color", colorCombo->currentIndex());
   settings.setValue("bText", bButton->isChecked());
   settings.setValue("uText", uButton->isChecked());
   settings.setValue("iText", iButton->isChecked());
   settings.setValue("editCheck", editCheck->isChecked());//->checkState());
   settings.setValue("text", lineEdit->text());
   settings.endGroup();
   settings.endGroup();
}

void CsimpleTextEdit::setSettingsToWidget(QString str)
{
    disconnect(fontCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    disconnect(fontSizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    disconnect(colorCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    disconnect(bButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    disconnect(iButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    disconnect(uButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    disconnect(editCheck, SIGNAL(stateChanged(int)),this,SIGNAL(edited()));
    disconnect(lineEdit, SIGNAL(textEdited(const QString &)),this,SIGNAL(edited()));

    settings.beginGroup(str);
    settings.beginGroup("simpleTextEdit");
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag EQ 0)
    {
       settings.setValue("fontIndex", 0);
       settings.setValue("fontSizeIndex", 0);
       settings.setValue("color", 0);
       settings.setValue("bText", 0);
       settings.setValue("uText", 0);
       settings.setValue("iText", 0);
       settings.setValue("editCheck", 0);
       settings.setValue("text", QString(""));

       settings.setValue("setFlag", 1);
    }

    fontCombo->setCurrentIndex(settings.value("fontIndex").toInt());
    fontSizeCombo->setCurrentIndex(settings.value("fontSizeIndex").toInt());

    colorCombo->setCurrentIndex(settings.value("color").toInt());
    bButton->setChecked(settings.value("bText").toBool());
    uButton->setChecked(settings.value("uText").toBool());
    iButton->setChecked(settings.value("iText").toBool());
    editCheck->setChecked(settings.value("editCheck").toBool());
    lineEdit->setText(settings.value("text").toString());
    settings.endGroup();
    settings.endGroup();

    connect(fontCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(fontSizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(colorCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(bButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    connect(iButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    connect(uButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    connect(editCheck, SIGNAL(stateChanged(int)),this,SIGNAL(edited()));
    connect(lineEdit, SIGNAL(textEdited(const QString &)),this,SIGNAL(edited()));

}
/*
 bool QObject::connect ( const QObject * sender, const char * signal, const QObject * receiver, const char * method, Qt::ConnectionType type = Qt::AutoConnection )   [static]

void CsimpleTextEdit::edited()
{
  qDebug("simpleText edited!");
}
*/
CsimpleTextEdit::~CsimpleTextEdit()
{

}
