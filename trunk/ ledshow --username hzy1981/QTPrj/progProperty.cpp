#include "progProperty.h"
#include <QSettings>
#include <QDate>

extern QSettings settings;
//节目属性编辑
CprogProperty::CprogProperty(QWidget *parent):QWidget(parent)
{
    QGridLayout *gridLayout,*timerGroupLayout;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;

    hLayout = new QHBoxLayout(this);

    nameGroup = new QGroupBox(tr("节目名称"),this);
    //nameLabel = new QLabel(tr("名字"), this);

    nameEdit = new QLineEdit(this);
    nameEdit->setFixedWidth(100);

    vLayout = new QVBoxLayout(this);
    //vLayout->addWidget(nameLabel);
    vLayout->addWidget(nameEdit);
    //vLayout->addStretch();
    nameGroup->setLayout(vLayout);

    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(nameGroup);
    hLayout->addLayout(vLayout);

    //mainLayout = new QGridLayout(this); //主布局
    //mainLayout -> addWidget(nameLabel, 0, 0);
    //mainLayout -> addWidget(nameEdit, 0, 1);

    timerGroupLayout = new QGridLayout(this); //定时播放布局
    gridLayout = new QGridLayout(this); //子区域布局

    timerGroup = new QGroupBox(tr("定时播放"), this);

    //按日期定时
    dateGroup = new QGroupBox(this);
    dateTimerCheck = new QCheckBox(tr("按日期定时"), this);
    startDateLabel = new QLabel(tr("开始日期"), this);
    endDateLabel = new QLabel(tr("结束日期"), this);
    startDateEdit = new QDateEdit(this);
    endDateEdit = new QDateEdit(this);
    //startDateEdit->resize(startDateEdit->sizeHint());

    gridLayout -> addWidget(dateTimerCheck, 0, 0, 1, 2);
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
    gridLayout -> addWidget(weekTimerCheck, 0, 0, 1, 2);
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
    gridLayout -> addWidget(timeCheck, 0, 0, 1, 2);
    gridLayout -> addWidget(startTimeLabel, 1, 0);
    gridLayout -> addWidget(startTimeEdit, 1, 1);
    gridLayout -> addWidget(endTimeLabel, 2, 0);
    gridLayout -> addWidget(endTimeEdit, 2, 1);
    timeGroup -> setLayout(gridLayout);
    timerGroupLayout -> addWidget(timeGroup, 0, 2);
    timerGroup -> setLayout(timerGroupLayout);//addWidget(timerGroupLayout, 1, 0);

    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(timerGroup);
    hLayout->addLayout(vLayout);

    //mainLayout -> addWidget(timerGroup, 1, 0);
    //播放长度
    gridLayout = new QGridLayout(this);
    playTimeGroup = new QGroupBox(tr("播放长度"), this);
    playTimeCheck = new QCheckBox(tr("定长播放"), this);
    playTimeEdit = new QLineEdit(this);
    playTimeLabel = new QLabel(tr("秒"));

    playCountCheck = new QCheckBox(tr("顺次播放"), this);
    playCountEdit = new QLineEdit(this);
    playCountLabel = new QLabel(tr("次"));

    gridLayout -> addWidget(playCountCheck, 0, 0, 1, 2);
    gridLayout -> addWidget(playCountEdit, 1, 0);
    gridLayout -> addWidget(playCountLabel, 1, 1);

    gridLayout -> addWidget(playTimeCheck, 2, 0, 1, 2);
    gridLayout -> addWidget(playTimeEdit, 3, 0);
    gridLayout -> addWidget(playTimeLabel, 3, 1);
    playTimeGroup -> setLayout(gridLayout);

    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(playTimeGroup);
    hLayout->addLayout(vLayout);
    //mainLayout -> addWidget(playTimeGroup, 1, 1);


    //流水边框选择
    gridLayout = new QGridLayout(this);
    borderGroup = new QGroupBox(tr("流水边框选择"), this);
    borderCheck = new QCheckBox(tr("启用流水边框"), this);
    stepLabel = new QLabel(tr("步长"), this);
    pointsLabel = new QLabel(tr("点数"), this);
    styleLabel = new QLabel(tr("样式"), this);
    modeLabel = new QLabel(tr("特效"), this);
    speedLabel = new QLabel(tr("速度"), this);
    usLabel = new QLabel(tr("微秒"), this);
    stepEdit = new QLineEdit(this);
    speedEdit = new QLineEdit(this);
    colorCombo = new CcolorCombo(this);
    styleCombo = new QComboBox(this);
    modeCombo = new QComboBox(this);//CmodeCombo(this);
    gridLayout -> addWidget(borderCheck, 0, 0, 1, 2);
    gridLayout -> addWidget(stepLabel, 1, 0);
    gridLayout -> addWidget(stepEdit, 1, 1);
    gridLayout -> addWidget(pointsLabel, 1, 2);
    gridLayout -> addWidget(styleLabel, 2, 0);
    gridLayout -> addWidget(styleCombo, 2, 1);
     gridLayout -> addWidget(colorCombo, 2, 2);
    gridLayout -> addWidget(modeLabel, 3, 0);
    gridLayout -> addWidget(modeCombo, 3, 1);
    gridLayout -> addWidget(speedLabel, 4, 0);
    gridLayout -> addWidget(speedEdit, 4, 1);
    gridLayout -> addWidget(usLabel, 4, 2);
    borderGroup -> setLayout(gridLayout);
    //mainLayout -> addWidget(borderGroup, 1, 2);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(borderGroup);
    hLayout->addLayout(vLayout);

    hLayout->addStretch(10);
    setLayout(hLayout);

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

   modeCombo->addItem(tr("静态"));
   modeCombo->addItem(tr("闪烁"));
   modeCombo->addItem(tr("顺时钟移动"));
   modeCombo->addItem(tr("逆时钟移动"));
   modeCombo->addItem(tr("顺时钟闪烁移动"));
   modeCombo->addItem(tr("逆时钟闪烁移动"));

   //modeCombo->addItem(tr("红色"));
   //modeCombo->addItem(tr("绿色"));
   //modeCombo->addItem(tr("黄色"));

   //按日期定时选择
   dateTimerCheckProc((int)dateTimerCheck->checkState());
   //按星期定时选择
   weekTimerCheckProc((int)weekTimerCheck->checkState());
   //按时间定时选择
   timeCheckProc((int)timeCheck->checkState());
   //定长播放选择
   playTimeCheckProc((int)playTimeCheck->checkState());
   playCountCheckProc((int)playCountCheck->checkState());
   //边框选择
   borderCheckProc((int)borderCheck->checkState());

   //connect(weekCheck[7], SIGNAL(stateChanged(int)),this,SLOT(allWeekDayCheckProc(int)));
   connect(dateTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(dateTimerCheckProc(int)));
   connect(weekTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(weekTimerCheckProc(int)));
   connect(timeCheck, SIGNAL(stateChanged(int)),this,SLOT(timeCheckProc(int)));
   connect(playTimeCheck, SIGNAL(stateChanged(int)),this,SLOT(playTimeCheckProc(int)));
   connect(playCountCheck, SIGNAL(stateChanged(int)),this,SLOT(playCountCheckProc(int)));
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

    QLabel *stepLabel,*styleLabel,*modeLabel,*speedLabel;
    QLabel *pointsLabel,*usLabel;
    QLineEdit *stepEdit, *speedEdit;
    QComboBox *styleCombo, *modeCombo;
 */
//从settings设置到widget中
void CprogProperty::setSettingsToWidget(QString str)
{
    QStringList keys;
    int year,month,day,hour,min;
    QDate date;
    QTime time;

    disconnect(dateTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(dateTimerCheckProc(int)));
    disconnect(weekTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(weekTimerCheckProc(int)));
    disconnect(timeCheck, SIGNAL(stateChanged(int)),this,SLOT(timeCheckProc(int)));
    disconnect(playTimeCheck, SIGNAL(stateChanged(int)),this,SLOT(playTimeCheckProc(int)));
    disconnect(playCountCheck, SIGNAL(stateChanged(int)),this,SLOT(playCountCheckProc(int)));
    disconnect(borderCheck, SIGNAL(stateChanged(int)),this,SLOT(borderCheckProc(int)));

    settings.beginGroup(str);
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag == 0)
    {
      settings.setValue("setFlag", 1);
    }

    //名字
    nameEdit->setText(settings.value("name").toString());

    //按日期定时
    dateTimerCheck->setChecked(settings.value("dateTimerCheck").toBool());
    //startDateEdit->setDate(QDate::fromString(settings.value("startDate").toString(),"yyyyMd"));
    //endDateEdit->setDate(QDate::fromString(settings.value("endDate").toString(),"yyyyMd"));
    //开始年月日
    year = settings.value("startYear").toInt();
    month = settings.value("startMonth").toInt();
    day = settings.value("startDay").toInt();
    date.setDate(year, month, day);
    startDateEdit->setDate(date);
    //结束年月日
    year = settings.value("endYear").toInt();
    month = settings.value("endMonth").toInt();
    day = settings.value("endDay").toInt();
    date.setDate(year, month, day);
    endDateEdit->setDate(date);

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
    //startTimeEdit->setTime(QTime::fromString(settings.value("startTime").toString(),"m.s"));
    //endTimeEdit->setTime(QTime::fromString(settings.value("endTime").toString(),"m.s"));
    hour = settings.value("startHour").toInt();
    min = settings.value("startMin").toInt();
    time.setHMS(hour, min, 0, 0);
    startTimeEdit->setTime(time);

    hour = settings.value("endHour").toInt();
    min = settings.value("endMin").toInt();
    time.setHMS(hour, min, 0, 0);
    endTimeEdit->setTime(time);

    //定长播放
    playTimeCheck->setChecked(settings.value("playTimeCheck").toBool());
    playTimeEdit->setText(QString::number(settings.value("playTime").toInt()));
    playTimeEdit->setFixedWidth(50);
    playCountCheck->setChecked(settings.value("playCountCheck").toBool());
    playCountEdit->setText(QString::number(settings.value("playCount").toInt()));
    playCountEdit->setFixedWidth(50);
    //边框选择
    borderCheck->setChecked(settings.value("borderCheck").toBool());
    stepEdit->setText(QString::number(settings.value("width").toInt()));
    speedEdit->setText(QString::number(settings.value("speed").toInt()));
    styleCombo->setCurrentIndex(settings.value("style").toInt());
    colorCombo->setCurrentIndex(settings.value("color").toInt());
    modeCombo->setCurrentIndex(settings.value("mode").toInt());

    settings.endGroup();

    connect(dateTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(dateTimerCheckProc(int)));
    connect(weekTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(weekTimerCheckProc(int)));
    connect(timeCheck, SIGNAL(stateChanged(int)),this,SLOT(timeCheckProc(int)));
    connect(playTimeCheck, SIGNAL(stateChanged(int)),this,SLOT(playTimeCheckProc(int)));
    connect(playCountCheck, SIGNAL(stateChanged(int)),this,SLOT(playCountCheckProc(int)));
    connect(borderCheck, SIGNAL(stateChanged(int)),this,SLOT(borderCheckProc(int)));

    //按日期定时选择
    dateTimerCheckProc((int)dateTimerCheck->checkState());
    //按星期定时选择
    weekTimerCheckProc((int)weekTimerCheck->checkState());
    //按时间定时选择
    timeCheckProc((int)timeCheck->checkState());
    //定长播放选择
    playTimeCheckProc((int)playTimeCheck->checkState());
    playCountCheckProc((int)playCountCheck->checkState());
    //边框选择
    borderCheckProc((int)borderCheck->checkState());
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
    //settings.setValue("startDate", QVariant(startDateEdit->date().toString()));
    //endDateEdit->setDate(QDate::fromString(settings.value("endDate").toString(),"yyyyMd"));
    //settings.setValue("endDate", QVariant(endDateEdit->date().toString()));

    settings.setValue("startYear", startDateEdit->date().year());
    settings.setValue("startMonth", startDateEdit->date().month());
    settings.setValue("startDay", startDateEdit->date().day());

    settings.setValue("endYear", endDateEdit->date().year());
    settings.setValue("endMonth", endDateEdit->date().month());
    settings.setValue("endDay", endDateEdit->date().day());

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
    //settings.setValue("startTime", QVariant(startTimeEdit->time().toString()));
    //endTimeEdit->setTime(QTime::fromString(settings.value("endTime").toString(),"m.s"));
    //settings.setValue("endTime", QVariant(endTimeEdit->time().toString()));
    settings.setValue("startHour", startTimeEdit->time().hour());
    settings.setValue("startMin", startTimeEdit->time().minute());
    settings.setValue("endHour", endTimeEdit->time().hour());
    settings.setValue("endMin", endTimeEdit->time().minute());

    //定长播放
      //playTimeCheck->setChecked(settings.value("playTimeCheck").toBool());
    settings.setValue("playTimeCheck", QVariant(playTimeCheck->checkState()));
    //playTimeEdit->setText(settings.value("playTime").toString());
    settings.setValue("playTime", QVariant(playTimeEdit->text().toInt()));
    settings.setValue("playCountCheck", QVariant(playCountCheck->checkState()));
    settings.setValue("playCount", QVariant(playCountEdit->text().toInt()));
      //边框选择
      //borderCheck->setChecked(settings.value("boderCheck").toBool());
    settings.setValue("borderCheck", QVariant(borderCheck->checkState()));
    //stepEdit->setText(settings.value("width").toString());
    settings.setValue("width", QVariant(stepEdit->text().toInt()));
    //speedEdit->setText(settings.value("speed").toString());
    settings.setValue("speed", QVariant(speedEdit->text().toInt()));
    //styleCombo->setCurrentIndex(settings.value("style").toInt());
    settings.setValue("style", QVariant(styleCombo->currentIndex()));
    //modeCombo->setCurrentIndex(settings.value("color").toInt());
    settings.setValue("color", QVariant(colorCombo->currentIndex()));
    settings.setValue("mode", QVariant(modeCombo->currentIndex()));
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
    //weekCheck[7]->setEnabled(flag);

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
    if(flag == true)
      playCountCheck->setChecked(false);
}

void CprogProperty::playCountCheckProc(int state)
{
    bool flag;

    flag = (state==Qt::Unchecked)?false:true;
    playCountEdit->setEnabled(flag);
    if(flag == true)
      playTimeCheck->setChecked(false);
}

void CprogProperty::borderCheckProc(int state)
{
    bool flag;

    flag = (state==Qt::Unchecked)?false:true;

    stepEdit->setEnabled(flag);
    speedEdit->setEnabled(flag);
    styleCombo->setEnabled(flag);
    modeCombo->setEnabled(flag);
    colorCombo->setEnabled(flag);
}


