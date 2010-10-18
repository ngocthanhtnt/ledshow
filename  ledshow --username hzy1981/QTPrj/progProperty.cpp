#include "progProperty.h"
#include <QSettings>

extern QSettings settings;
//节目属性编辑
CprogProperty::CprogProperty(QWidget *parent):QWidget(parent)
{
    QGridLayout *gridLayout,*timerGroupLayout, *mainLayout;

    nameLabel = new QLabel(tr("名字"), this);
    nameEdit = new QLineEdit(this);

    mainLayout = new QGridLayout(this); //主布局
    mainLayout -> addWidget(nameLabel, 0, 0);
    mainLayout -> addWidget(nameEdit, 0, 1);

    timerGroupLayout = new QGridLayout(this); //定时播放布局
    gridLayout = new QGridLayout(this); //子区域布局

    timerGroup = new QGroupBox(tr("定时播放"), this);

    //按日期定时
    dateGroup = new QGroupBox(this);
    dateTimerCheck = new QCheckBox(tr("按日期定时"), this);
    startDateLabel = new QLabel(tr("开始日期"), this);
    endDateLabel = new QLabel(tr("结束日日期"), this);
    startDateEdit = new QDateEdit(this);
    endDateEdit = new QDateEdit(this);
    gridLayout -> addWidget(dateTimerCheck, 0, 0);
    gridLayout -> addWidget(startDateLabel, 1, 0);
    gridLayout -> addWidget(startDateEdit, 1, 1);
    gridLayout -> addWidget(endDateLabel, 2, 0);
    gridLayout -> addWidget(endDateEdit, 2, 1);
    dateGroup -> setLayout(gridLayout);
    timerGroupLayout -> addWidget(dateGroup, 0, 0);

    //按星期定时
    gridLayout = new QGridLayout(this);
    weekGroup = new QGroupBox( this);
    weekTimerCheck = new QCheckBox(tr("按星期定时"), this);
    weekCheck[0] = new QCheckBox(tr("星期一"), this);
    weekCheck[1] = new QCheckBox(tr("星期二"), this);
    weekCheck[2] = new QCheckBox(tr("星期三"), this);
    weekCheck[3] = new QCheckBox(tr("星期四"), this);
    weekCheck[4] = new QCheckBox(tr("星期五"), this);
    weekCheck[5] = new QCheckBox(tr("星期六"), this);
    weekCheck[6] = new QCheckBox(tr("星期日"), this);
    //weekCheck[7] = new QCheckBox(tr("全选"), this);
    gridLayout -> addWidget(weekTimerCheck, 0, 0);
    gridLayout -> addWidget(weekCheck[0], 1, 0);
    gridLayout -> addWidget(weekCheck[1], 1, 1);
    gridLayout -> addWidget(weekCheck[2], 1, 2);
    gridLayout -> addWidget(weekCheck[3], 2, 0);
    gridLayout -> addWidget(weekCheck[4], 2, 1);
    gridLayout -> addWidget(weekCheck[5], 2, 2);
    gridLayout -> addWidget(weekCheck[6], 3, 0);
    //gridLayout -> addWidget(weekCheck[7], 3, 1);
    weekGroup -> setLayout(gridLayout);
    timerGroupLayout -> addWidget(weekGroup, 0, 1);

    //按时间定时
    gridLayout = new QGridLayout(this);
    timeGroup = new QGroupBox(this);
    timeCheck = new QCheckBox(tr("按时间定时"), this);
    startTimeLabel = new QLabel(tr("开始时间"), this);
    endTimeLabel = new QLabel(tr("结束时间"), this);
    startTimeEdit = new QTimeEdit(this);
    endTimeEdit = new QTimeEdit(this);
    gridLayout -> addWidget(timeCheck, 0, 0);
    gridLayout -> addWidget(startTimeLabel, 1, 0);
    gridLayout -> addWidget(startTimeEdit, 1, 1);
    gridLayout -> addWidget(endTimeLabel, 2, 0);
    gridLayout -> addWidget(endTimeEdit, 2, 1);
    timeGroup -> setLayout(gridLayout);
    timerGroupLayout -> addWidget(timeGroup, 0, 2);
    timerGroup -> setLayout(timerGroupLayout);//addWidget(timerGroupLayout, 1, 0);
    mainLayout -> addWidget(timerGroup, 1, 0);
    //播放长度
    gridLayout = new QGridLayout(this);
    playTimeGroup = new QGroupBox(tr("播放长度"), this);
    playTimeCheck = new QCheckBox(tr("定长播放"), this);
    playTimeEdit = new QLineEdit(this);
    playTimeLabel = new QLabel(tr("秒"));
    gridLayout -> addWidget(playTimeCheck, 0, 0);
    gridLayout -> addWidget(playTimeEdit, 1, 0);
    gridLayout -> addWidget(playTimeLabel, 1, 1);
    playTimeGroup -> setLayout(gridLayout);
    mainLayout -> addWidget(playTimeGroup, 1, 1);


    //流水边框选择
    gridLayout = new QGridLayout(this);
    borderGroup = new QGroupBox(tr("流水边框选择"), this);
    borderCheck = new QCheckBox(tr("启用流水边框"), this);
    widthLabel = new QLabel(tr("宽度"), this);
    pointsLabel = new QLabel(tr("点数"), this);
    styleLabel = new QLabel(tr("样式"), this);
    colorLabel = new QLabel(tr("颜色"), this);
    speedLabel = new QLabel(tr("速度"), this);
    usLabel = new QLabel(tr("微秒"), this);
    widthEdit = new QLineEdit(this);
    speedEdit = new QLineEdit(this);
    styleCombo = new QComboBox(this);
    colorCombo = new CcolorCombo(this);
    gridLayout -> addWidget(borderCheck, 0, 0);
    gridLayout -> addWidget(widthLabel, 1, 0);
    gridLayout -> addWidget(widthEdit, 1, 1);
    gridLayout -> addWidget(pointsLabel, 1, 2);
    gridLayout -> addWidget(styleLabel, 2, 0);
    gridLayout -> addWidget(styleCombo, 2, 1);
    gridLayout -> addWidget(colorLabel, 3, 0);
    gridLayout -> addWidget(colorCombo, 3, 1);
    gridLayout -> addWidget(speedLabel, 4, 0);
    gridLayout -> addWidget(speedEdit, 4, 1);
    gridLayout -> addWidget(usLabel, 4, 2);
    borderGroup -> setLayout(gridLayout);
    mainLayout -> addWidget(borderGroup, 1, 2);


  //-----------------------------------------------------
   styleCombo->addItem(tr("1点顺时钟"));
   styleCombo->addItem(tr("2点顺时钟"));
   styleCombo->addItem(tr("3点顺时钟"));
   styleCombo->addItem(tr("4点顺时钟"));
   styleCombo->addItem(tr("5点顺时钟"));
   styleCombo->addItem(tr("6点顺时钟"));
   styleCombo->addItem(tr("7点顺时钟"));
   styleCombo->addItem(tr("8点顺时钟"));

   styleCombo->addItem(tr("1点逆时钟"));
   styleCombo->addItem(tr("2点逆时钟"));
   styleCombo->addItem(tr("3点逆时钟"));
   styleCombo->addItem(tr("4点逆时钟"));
   styleCombo->addItem(tr("5点逆时钟"));
   styleCombo->addItem(tr("6点逆时钟"));
   styleCombo->addItem(tr("7点逆时钟"));
   styleCombo->addItem(tr("8点逆时钟"));

   //colorCombo->addItem(tr("红色"));
   //colorCombo->addItem(tr("绿色"));
   //colorCombo->addItem(tr("黄色"));

   //按日期定时选择
   dateTimerCheckProc((int)dateTimerCheck->checkState());
   //按星期定时选择
   weekTimerCheckProc((int)weekTimerCheck->checkState());
   //按时间定时选择
   timeCheckProc((int)timeCheck->checkState());
   //定长播放选择
   playTimeCheckProc((int)timeCheck->checkState());
   //边框选择
   borderCheckProc((int)borderCheck->checkState());

   //connect(weekCheck[7], SIGNAL(stateChanged(int)),this,SLOT(allWeekDayCheckProc(int)));
   connect(dateTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(dateTimerCheckProc(int)));
   connect(weekTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(weekTimerCheckProc(int)));
   connect(timeCheck, SIGNAL(stateChanged(int)),this,SLOT(timeCheckProc(int)));
   connect(playTimeCheck, SIGNAL(stateChanged(int)),this,SLOT(playTimeCheckProc(int)));
   connect(borderCheck, SIGNAL(stateChanged(int)),this,SLOT(borderCheckProc(int)));
}



CprogProperty::~CprogProperty()
{

}

/*
    //-----------名称-------------
    QLabel *nameLabel;  //名字
    QLineEdit *nameEdit; //名字输入框

    //--------  按日期定时---------
    QGroupBox *dateGroup;
    QCheckBox *dateTimerCheck; //按日期定时
    QLabel *startDateLabel, *endDateLabel;
    QDateEdit *startDateEdit; //起始日期
    QDateEdit *endDateEdit; //结束日期

    //----------按星期定时-----------
    QGroupBox *weekGroup;
    QCheckBox *weekTimerCheck; //按星期定时
    QCheckBox *weekCheck[8]; //星期选择

    //----------按时间定时----------
    QGroupBox *timeGroup;
    QCheckBox *timeCheck; //按时间定时
    QLabel *startTimeLabel,*endTimeLabel;
    QTimeEdit *startTimeEdit; //开始时间
    QTimeEdit *endTimeEdit; //结束时间

    //------------定长播放----------
    QGroupBox *playTimeGroup; //播放时长
    QCheckBox *playTimeCheck; //定长播放
    QLineEdit *playTimeEdit; //时长
    QLabel *playTimeLabel;

    //-------------边框选择----------
    QGroupBox *borderGroup; //边框
    QCheckBox *borderCheck;

    QLabel *widthLabel,*styleLabel,*colorLabel,*speedLabel;
    QLabel *pointsLabel,*usLabel;
    QLineEdit *widthEdit, *speedEdit;
    QComboBox *styleCombo, *colorCombo;
 */
//从settings设置到widget中
void CprogProperty::setSettingsToWidget(QString str)
{
    QStringList keys;

    settings.beginGroup(str);
    keys = settings.allKeys();
    if(keys.isEmpty() == false)
    {
      //名字
      nameEdit->setText(settings.value("name").toString());

      //按日期定时
      dateTimerCheck->setChecked(settings.value("dateTimerCheck").toBool());
      startDateEdit->setDate(QDate::fromString(settings.value("startDate").toString(),"yyyyMd"));
      endDateEdit->setDate(QDate::fromString(settings.value("endDate").toString(),"yyyyMd"));

      //按星期定时
      weekTimerCheck->setChecked(settings.value("weekTimerCheck").toBool());
      weekCheck[0]->setChecked(settings.value("w0").toBool());
      weekCheck[1]->setChecked(settings.value("w1").toBool());
      weekCheck[2]->setChecked(settings.value("w2").toBool());
      weekCheck[3]->setChecked(settings.value("w3").toBool());
      weekCheck[4]->setChecked(settings.value("w4").toBool());
      weekCheck[5]->setChecked(settings.value("w5").toBool());
      weekCheck[6]->setChecked(settings.value("w6").toBool());
      //weekCheck[7]->setChecked(settings.value("w7").toBool());

      //按时间定时
      timeCheck->setChecked(settings.value("timeCheck").toBool());
      startTimeEdit->setTime(QTime::fromString(settings.value("startTime").toString(),"m.s"));
      endTimeEdit->setTime(QTime::fromString(settings.value("endTime").toString(),"m.s"));

      //定长播放
      playTimeCheck->setChecked(settings.value("playTimeCheck").toBool());
      playTimeEdit->setText(settings.value("playTime").toString());

      //边框选择
      borderCheck->setChecked(settings.value("borderCheck").toBool());
      widthEdit->setText(settings.value("width").toString());
      speedEdit->setText(settings.value("speed").toString());
      styleCombo->setCurrentIndex(settings.value("style").toInt());
      colorCombo->setCurrentIndex(settings.value("color").toInt());
    }

    settings.endGroup();
}

//从Widget获取配置到settings中,str为Settings的group
void CprogProperty::getSettingsFromWidget(QString str)
{
    QStringList keys;

    settings.beginGroup(str);
    //keys = settings.allKeys();
    //if(keys.isEmpty() == false)
    {
      //名字
      //nameEdit->setText(settings.value("name").toString());
    settings.setValue("name",QVariant(nameEdit->text()));
      //按日期定时
    settings.setValue("dateTimerCheck", QVariant((bool)(dateTimerCheck->checkState())));
    settings.setValue("startDate", QVariant(startDateEdit->date().toString()));
    //endDateEdit->setDate(QDate::fromString(settings.value("endDate").toString(),"yyyyMd"));
    settings.setValue("endDate", QVariant(endDateEdit->date().toString()));

      //按星期定时
     // weekTimerCheck->setChecked(settings.value("weekTimerCheck").toBool());
    settings.setValue("weekTimerCheck", QVariant(weekTimerCheck->checkState()));
    //weekCheck[0]->setChecked(settings.value("w0").toBool());
    settings.setValue("w0", QVariant(weekCheck[0]->checkState()));
    settings.setValue("w1", QVariant(weekCheck[1]->checkState()));
    settings.setValue("w2", QVariant(weekCheck[2]->checkState()));
    settings.setValue("w3", QVariant(weekCheck[3]->checkState()));
    settings.setValue("w4", QVariant(weekCheck[4]->checkState()));
    settings.setValue("w5", QVariant(weekCheck[5]->checkState()));
    settings.setValue("w6", QVariant(weekCheck[6]->checkState()));
    //settings.setValue("w7", QVariant(weekCheck[7]->checkState()));

      //按时间定时
    //timeCheck->setChecked(settings.value("timeCheck").toBool());
    settings.setValue("timeCheck", QVariant(timeCheck->checkState()));
    //startTimeEdit->setTime(QTime::fromString(settings.value("startTime").toString(),"m.s"));
    settings.setValue("startTime", QVariant(startTimeEdit->time().toString()));
    //endTimeEdit->setTime(QTime::fromString(settings.value("endTime").toString(),"m.s"));
    settings.setValue("endTime", QVariant(endTimeEdit->time().toString()));
      //定长播放
      //playTimeCheck->setChecked(settings.value("playTimeCheck").toBool());
    settings.setValue("playTimeCheck", QVariant(playTimeCheck->checkState()));
    //playTimeEdit->setText(settings.value("playTime").toString());
    settings.setValue("playTime", QVariant(playTimeEdit->text()));
      //边框选择
      //borderCheck->setChecked(settings.value("boderCheck").toBool());
    settings.setValue("borderCheck", QVariant(borderCheck->checkState()));
    //widthEdit->setText(settings.value("width").toString());
    settings.setValue("width", QVariant(widthEdit->text()));
    //speedEdit->setText(settings.value("speed").toString());
    settings.setValue("speed", QVariant(speedEdit->text()));
    //styleCombo->setCurrentIndex(settings.value("style").toInt());
    settings.setValue("style", QVariant(styleCombo->currentIndex()));
    //colorCombo->setCurrentIndex(settings.value("color").toInt());
    settings.setValue("color", QVariant(colorCombo->currentIndex()));
   }

    settings.endGroup();

}

void CprogProperty::allWeekDayCheckProc(int state)
{
    bool flag;

    flag = (state==Qt::Checked)?true:false;
    if(flag == true)
    {
        for(int i = 0; i < 7; i ++)
        weekCheck[i]->setChecked(flag);
    }
}

void CprogProperty::dateTimerCheckProc(int state)
{
    bool flag;

    flag = (state==Qt::Unchecked)?false:true;

    startDateEdit->setEnabled(flag);
    endDateEdit->setEnabled(flag);
 }

void CprogProperty::weekTimerCheckProc(int state)
{
    bool flag;

    flag = (state==Qt::Unchecked)?false:true;

    weekCheck[0]->setEnabled(flag);
    weekCheck[1]->setEnabled(flag);
    weekCheck[2]->setEnabled(flag);
    weekCheck[3]->setEnabled(flag);
    weekCheck[4]->setEnabled(flag);
    weekCheck[5]->setEnabled(flag);
    weekCheck[6]->setEnabled(flag);
    weekCheck[7]->setEnabled(flag);

}

void CprogProperty::timeCheckProc(int state)
{
    bool flag;

    flag = (state==Qt::Unchecked)?false:true;

    startTimeEdit->setEnabled(flag);
    endTimeEdit->setEnabled(flag);
}

void CprogProperty::playTimeCheckProc(int state)
{
    bool flag;

    flag = (state==Qt::Unchecked)?false:true;
    playTimeEdit->setEnabled(flag);
}

void CprogProperty::borderCheckProc(int state)
{
    bool flag;

    flag = (state==Qt::Unchecked)?false:true;

    widthEdit->setEnabled(flag);
    speedEdit->setEnabled(flag);
    styleCombo->setEnabled(flag);
    colorCombo->setEnabled(flag);
}


