#include "timerProperty.h"
#include "mainwindow.h"
#include <QSettings>

extern MainWindow *w;
extern QSettings settings;

//正反计时编辑
CtimerProperty::CtimerProperty(QWidget *parent):QWidget(parent)
{

    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;
    QGridLayout *gridLayout;

    hLayout = new QHBoxLayout(this);
    //mainLayout = new QGridLayout(this);

    area = new Carea(this);
    nameEdit = new CnameEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(nameEdit);
    vLayout->addWidget(area);
    hLayout->addLayout(vLayout);

    smLineEdit = new CsmLineEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(smLineEdit);
    hLayout->addLayout(vLayout);

    simpleTextEdit = new CsimpleTextEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(simpleTextEdit);
    hLayout->addLayout(vLayout);

    //--------------------
    dstTimeGroup = new QGroupBox(tr("目标时间编辑"), this);
    dstTimeLabel = new QLabel(tr("目标时间"), this);
    styleLabel = new QLabel(tr("样式"), this);
    colorLabel = new QLabel(tr("颜色"), this);
    fontSizeLabel = new QLabel(tr("大小"), this);
    dstDateTimeEdit = new QDateTimeEdit(this);
    colorCombo = new CcolorCombo(this);
    styleCombo = new QComboBox(this);
    fontSizeCombo = new CsizeCombo(this);

    styleCombo->addItem(tr("0000天00时00分00秒"));
    styleCombo->addItem(tr("000天00时00分00秒"));
    styleCombo->addItem(tr("00天00时00分00秒"));
    styleCombo->addItem(tr("0000天00时00分"));
    styleCombo->addItem(tr("000天00时00分"));
    styleCombo->addItem(tr("00天00时00分"));
    styleCombo->addItem(tr("0000天00时"));
    styleCombo->addItem(tr("000天00时"));
    styleCombo->addItem(tr("00天00时"));
    styleCombo->addItem(tr("0000天"));
    styleCombo->addItem(tr("000天"));
    styleCombo->addItem(tr("00天"));
    styleCombo->addItem(tr("00时00分00秒"));
    styleCombo->addItem(tr("00时00分"));
    styleCombo->addItem(tr("00时"));
    styleCombo->addItem(tr("00分00秒"));
    styleCombo->addItem(tr("00分"));
    styleCombo->addItem(tr("00秒"));

    gridLayout = new QGridLayout(this);
    gridLayout -> addWidget(dstTimeLabel, 0, 0);
    gridLayout -> addWidget(dstDateTimeEdit, 0, 1);
    gridLayout -> addWidget(colorLabel, 0, 2);
    gridLayout -> addWidget(colorCombo, 0, 3);
    gridLayout -> addWidget(styleLabel, 1, 0);
    gridLayout -> addWidget(styleCombo, 1, 1);
    gridLayout -> addWidget(fontSizeLabel, 1, 2);
    gridLayout -> addWidget(fontSizeCombo, 1, 3);
    dstTimeGroup -> setLayout(gridLayout);

    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(dstTimeGroup);
    hLayout->addLayout(vLayout);

    showModeEdit = new CshowModeEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(showModeEdit);
    hLayout->addLayout(vLayout);

    hLayout->addStretch(10);
    setLayout(hLayout);

    connect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(dstDateTimeEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));

    connect(dstDateTimeEdit, SIGNAL(dateTimeChanged(const QDateTime &)), this, SLOT(edited()));
    connect(colorCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
    connect(styleCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
    connect(fontSizeCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
}

//属性编辑的SLOT
void CtimerProperty::edited()
{
    CshowArea *area;
    QTreeWidgetItem *item;

    //qDebug("propertyEdited");
    area = w->screenArea->getFocusArea(); //当前焦点分区

    if(area != (CshowArea *)0) //
    {
        //当前选中的item
        item = area->fileItem;//w->progManage->treeWidget->currentItem();////// //w->progManage->treeWidget->currentItem();
        if(item != (QTreeWidgetItem *)0)
        {
            QString str = item->data(0,Qt::UserRole).toString();
            getSettingsFromWidget(str);
            updateTimerShowArea(area);
        }
    }
}

//刷新显示区域
void updateTimerShowArea(CshowArea *area)
{
    //CshowArea *area;
    QString str;
    QTreeWidgetItem *item;

    if(area != (CshowArea *)0) //
    {
        item = area->fileItem;

        str = item->data(0,Qt::UserRole).toString();

        getTimerParaFromSettings(str,area->filePara);
        area->imageBk = getLineTextImage(str);

        //qDebug("file_para flag = %d", area->filePara.Temp_Para.Flag);
        area->update(); //刷新显示

    }
    else
    {
        ASSERT_FAILED();
    }

}
/*
  INT8U Dst_Year; //目标年
  INT8U Dst_Month; //目标月
  INT8U Dst_Date; //目标日
  INT8U Dst_Hour; //目标时
  INT8U Dst_Min; //目标分
  INT8U Dst_Sec; //目标秒

  INT8U Show_Mode;  //显示方式
  INT8U Show_Color; //显示颜色
  INT8U Show_Font; //显示字号
  INT8U Show_Posi; //显示位置

  INT8U Temp; //备用

  INT8U Text_Color; //背景颜色
  INT16U Text_X; //背景X
  INT16U Text_Y; //背景Y
  INT16U Text_Width; //背景宽度
  INT16U Text_Height; //背景高度
 */
//从settings中获取参数
void getTimerParaFromSettings(QString str, U_File_Para &para)
{
    int tmp;
    bool checked;
    // QString str;

    para.Timer_Para.Flag = SHOW_TIMER;
    settings.beginGroup(str);

    if(settings.value("dstYear").toInt() > 2000)
      para.Timer_Para.Dst_Year = (INT8U)(settings.value("dstYear").toInt() - 2000);
    else
      para.Timer_Para.Dst_Year = 0;

    para.Timer_Para.Dst_Month = (INT8U)settings.value("dstMon").toInt();
    para.Timer_Para.Dst_Date = (INT8U)settings.value("dstDay").toInt();
    para.Timer_Para.Dst_Hour = (INT8U)settings.value("dstHour").toInt();
    para.Timer_Para.Dst_Min = (INT8U)settings.value("dstMin").toInt();
    para.Timer_Para.Dst_Sec = (INT8U)settings.value("dstSec").toInt();

    tmp = (INT8U)settings.value("color").toInt();
    para.Timer_Para.Timer_Color = 0;
    SET_BIT(para.Timer_Para.Timer_Color, tmp);

    para.Timer_Para.Timer_Font = (INT8U)settings.value("size").toInt();
    para.Timer_Para.Timer_Type = (INT8U)settings.value("style").toInt();

    settings.beginGroup("smLine");
    para.Timer_Para.SmLineFlag = settings.value("smLineCheck").toBool();
    settings.endGroup();

    settings.endGroup();
}

CtimerProperty::~CtimerProperty()
{

}

void CtimerProperty::getSettingsFromWidget(QString str)
{
  settings.beginGroup(str);
  int type = settings.value("type").toInt();
  if(type EQ TIMER_PROPERTY)
  {
      settings.setValue("dstYear", dstDateTimeEdit->date().year());
      settings.setValue("dstMon", dstDateTimeEdit->date().month());
      settings.setValue("dstDay", dstDateTimeEdit->date().day());
      settings.setValue("dstHour", dstDateTimeEdit->time().hour());
      settings.setValue("dstMin", dstDateTimeEdit->time().minute());
      settings.setValue("dstSec", dstDateTimeEdit->time().second());

      settings.setValue("color",   colorCombo->currentIndex());
      settings.setValue("style", styleCombo->currentIndex());
      settings.setValue("size", fontSizeCombo->currentIndex());
  }
  else
      ASSERT_FAILED();
  settings.endGroup();

  if(type EQ TIMER_PROPERTY)
  {
      simpleTextEdit->getSettingsFromWidget(str);
      smLineEdit->getSettingsFromWidget(str);
  }
}

void CtimerProperty::setSettingsToWidget(QString str)
{
    int year,month,day,hour,min,sec;
    QDate date;
    QTime time;

    disconnect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    //disconnect(dstDateTimeEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));

    disconnect(dstDateTimeEdit, SIGNAL(dateTimeChanged(const QDateTime &)), this, SLOT(edited()));
    disconnect(colorCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
    disconnect(styleCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
    disconnect(fontSizeCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));

    settings.beginGroup(str);
    int type = settings.value("type").toInt();
    if(type EQ TIMER_PROPERTY)
    {
        year = settings.value("dstYear").toInt();
        month = settings.value("dstMon").toInt();
        day = settings.value("dstDay").toInt();
        date.setDate(year, month, day);
        dstDateTimeEdit->setDate(date);

        hour = settings.value("dstHour").toInt();
        min = settings.value("dstMin").toInt();
        sec = settings.value("dstSec").toInt();
        time.setHMS(hour, min, sec, 0);
        dstDateTimeEdit->setTime(time);

        colorCombo->setCurrentIndex(settings.value("color").toInt());
        styleCombo->setCurrentIndex(settings.value("style").toInt());
        fontSizeCombo->setCurrentIndex(settings.value("size").toInt());
    }
    else
        ASSERT_FAILED();
    settings.endGroup();

    if(type EQ TIMER_PROPERTY)
    {
        simpleTextEdit->setSettingsToWidget(str);
        smLineEdit->setSettingsToWidget(str);
    }
    else
        ASSERT_FAILED();

    connect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    //connect(dstDateTimeEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));

    connect(dstDateTimeEdit, SIGNAL(dateTimeChanged(const QDateTime &)), this, SLOT(edited()));
    connect(colorCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
    connect(styleCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
    connect(fontSizeCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));

}
