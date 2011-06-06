#include "progProperty.h"
#include "..\Stm32\usr\app\Includes.h"
#include <QSettings>
#include <QDate>
#include "mainwindow.h"


extern MainWindow *w;
extern QSettings settings;

//定义边框数据
const S_Border_Data Border_Data[] =
{
    /*--  每五个点一个单元  --*/
    /*--  宽度x高度=40x8  --*/
    {40,1,{0xE0,0x83,0x0F,0x3E,0xF8}},
    /*--  每10个点一个单元  --*/
    /*--  宽度x高度=40x8  --*/
    {40,1,{0x00,0xFC,0x0F,0xC0,0xFF}},

    /*--    --*/
    /*--  宽度x高度=40x8  --*/
    {40,2,{0x00,0xFC,0x0F,0xC0,0xFF,
           0x00,0xFC,0x0F,0xC0,0xFF}},

    /*--  调入了一幅图像：这是您新建的图像  --*/
    /*--  宽度x高度=40x8  --*/
    {40,2,{0xFF,0xFF,0xFF,0xFF,0xFF,
           0x00,0xFC,0x0F,0xC0,0xFF}},

    /*--  调入了一幅图像：这是您新建的图像  --*/
    /*--  宽度x高度=40x8  --*/
    {40,2,{0x00,0xFC,0x0F,0xC0,0xFF,
           0xFF,0xFF,0xFF,0xFF,0xFF}},

    {40,3,{0x00,0xFC,0x0F,0xC0,0xFF,
           0xFF,0xFF,0xFF,0xFF,0xFF,
           0x00,0xFC,0x0F,0xC0,0xFF}},

    {40,3,{0xE0,0x83,0x0F,0x3E,0xF8,
           0xFF,0xFF,0xFF,0xFF,0xFF,
           0xE0,0x83,0x0F,0x3E,0xF8}},
    //箭头
    {40,3,{0x00,0x00,0x02,0x00,0x20,
           0xFF,0xFF,0xF7,0xFF,0x7F,
           0x00,0x00,0x02,0x00,0x20}},

    {40,3,{0x80,0x00,0x02,0x08,0x20,
           0xFF,0xFD,0xF7,0xDF,0x7F,
           0x80,0x00,0x02,0x08,0x20}},
};

QImage getBorderImage(int type, int index, QColor color)
{

   int i,j;
/*
   if(index >= sizeof(Border_Data)/sizeof(Border_Data[0]))
   {
       ASSERT_FAILED();
       return QImage(0,0);
   }
*/


   if(type EQ 0)
   {
       QImage border(Border_Data[index].Width, Border_Data[index].Height, QImage::Format_RGB32);
       border.fill(Qt::black);
       for(i = 0; i < border.width(); i ++)
           for(j = 0; j <border.height(); j++)
           {
             if(Get_Rect_Buf_Bit((INT8U *)Border_Data[index].Data, sizeof(Border_Data[index].Data), Border_Data[index].Width, i, j) > 0)
                 border.setPixel(i, j, color.rgb());
       }

       return border;
    }
   else
   {
       QImage border(Simple_Border_Data[index].Width, Simple_Border_Data[index].Height, QImage::Format_RGB32);
       border.fill(Qt::black);
       for(i = 0; i < border.width(); i ++)
           for(j = 0; j <border.height(); j++)
           {
             if(Get_Rect_Buf_Bit((INT8U *)Simple_Border_Data[index].Data, sizeof(Simple_Border_Data[index].Data), Simple_Border_Data[index].Width, i, j) > 0)
                 border.setPixel(i, j, color.rgb());
       }

       return border;
   }

   //border = border.scaled(border.width(), border.height());
   //border.save("d:\\border.png");

}

//节目属性编辑
CprogProperty::CprogProperty(QWidget *parent):QWidget(parent)
{
    QGridLayout *gridLayout,*timerGroupLayout;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;

    hLayout = new QHBoxLayout(this);

    //nameGroup = new QGroupBox(tr("节目名称"),this);
    //nameLabel = new QLabel(tr("名字"), this);

    //nameEdit = new QLineEdit(this);
    //nameEdit->setFixedWidth(100);
    nameEdit = new CnameEdit(this);

    vLayout = new QVBoxLayout(this);
    //vLayout->addWidget(nameLabel);
    vLayout->addWidget(nameEdit);
    vLayout->addStretch(10);
    //vLayout->addStretch();
    //nameGroup->setLayout(vLayout);

    //vLayout = new QVBoxLayout(this);
    //vLayout->addWidget(nameGroup);
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

    //QValidator *validator = new QIntValidator(1,99999,this);
    //mainLayout -> addWidget(timerGroup, 1, 0);
    //播放长度
    gridLayout = new QGridLayout(this);
    playTimeGroup = new QGroupBox(tr("播放长度"), this);
    playTimeCheck = new QCheckBox(tr("定长播放"), this);
    playTimeEdit = new QSpinBox(this);
    playTimeEdit->setMinimum(1);
    playTimeEdit->setMaximum(99999);//setValidator(validator);
    playTimeLabel = new QLabel(tr("秒"));
    playTimeEdit->setFixedWidth(50);

    //validator = new QIntValidator(1,99999,this);
    playCountCheck = new QCheckBox(tr("顺次播放"), this);
    playCountEdit = new QSpinBox(this);
    playCountEdit->setMinimum(1);
    playCountEdit->setMaximum(99999);//setValidator(validator);//playCountEdit->setValidator(validator);
    playCountLabel = new QLabel(tr("次"));
    playCountEdit->setFixedWidth(50);


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


    //魔幻边框选择
    gridLayout = new QGridLayout(this);
    borderGroup = new QGroupBox(tr("魔幻边框选择"), this);
    borderCheck = new QCheckBox(tr("启用魔幻边框"), this);
    //stepLabel = new QLabel(tr("步长"), this);
    //pointsLabel = new QLabel(tr("点数"), this);
    styleLabel = new QLabel(tr("样式"), this);
    modeLabel = new QLabel(tr("特效"), this);
    speedLabel = new QLabel(tr("速度"), this);
    usLabel = new QLabel(tr("微秒"), this);
    //stepCombo = new QComboBox(this);//new QLineEdit(this); //步长
    speedCombo = new QComboBox(this);
    colorCombo = new CcolorCombo(this);
    styleCombo = new QComboBox(this);
    modeCombo = new QComboBox(this);//CmodeCombo(this);
    gridLayout -> addWidget(borderCheck, 0, 0, 1, 2);
    //gridLayout -> addWidget(stepLabel, 1, 0);
    //gridLayout -> addWidget(stepCombo, 1, 1);
    //gridLayout -> addWidget(pointsLabel, 1, 2);
    gridLayout -> addWidget(styleLabel, 1, 0);
    gridLayout -> addWidget(styleCombo, 1, 1);
     gridLayout -> addWidget(colorCombo, 1, 2);
    gridLayout -> addWidget(modeLabel, 2, 0);
    gridLayout -> addWidget(modeCombo, 2, 1, 1, 2);
    gridLayout -> addWidget(speedLabel, 3, 0);
    gridLayout -> addWidget(speedCombo, 3, 1);
    gridLayout -> addWidget(usLabel, 3, 2);
    borderGroup -> setLayout(gridLayout);
    //mainLayout -> addWidget(borderGroup, 1, 2);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(borderGroup);
    hLayout->addLayout(vLayout);

    hLayout->addStretch(10);
    setLayout(hLayout);

  //-----------------------------------------------------
  /*
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
  */


   styleCombo->setIconSize(QSize(40,8));

   for(unsigned int i = 0; i < S_NUM(Border_Data); i ++)
    {
       QPixmap borderPixmap;
       QImage borderImage;
       borderImage = getBorderImage(0, i, QColor(Qt::red));
       borderImage = borderImage.scaled(borderImage.width()*10, borderImage.height()*20);
       borderPixmap.convertFromImage(borderImage);
       styleCombo->addItem(QIcon(borderPixmap), QString("%1").arg(Border_Data[i].Height));

   }

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
/*
   stepCombo->addItem(tr("1"));
   stepCombo->addItem(tr("2"));
   stepCombo->addItem(tr("3"));
   stepCombo->addItem(tr("4"));
   stepCombo->addItem(tr("5"));
   stepCombo->addItem(tr("6"));
   stepCombo->addItem(tr("7"));
   stepCombo->addItem(tr("8"));
*/
   speedCombo->addItem(tr("1最快"));
   speedCombo->addItem(tr("2"));
   speedCombo->addItem(tr("3"));
   speedCombo->addItem(tr("4"));
   speedCombo->addItem(tr("5"));
   speedCombo->addItem(tr("6"));
   speedCombo->addItem(tr("7"));
   speedCombo->addItem(tr("8"));
   speedCombo->addItem(tr("9"));
   speedCombo->addItem(tr("10最慢"));

   //connect(weekCheck[7], SIGNAL(stateChanged(int)),this,SLOT(allWeekDayCheckProc(int)));
   connectSignal();
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
    QComboBox *stepCombo,*speedCombo;
    QComboBox *styleCombo;
    QComboBox *modeCombo;
    CcolorCombo *colorCombo;
 */

void CprogProperty::connectSignal()
{
    connect(dateTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(dateTimerCheckProc(int)));
    connect(weekTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(weekTimerCheckProc(int)));
    connect(timeCheck, SIGNAL(stateChanged(int)),this,SLOT(timeCheckProc(int)));
    connect(playTimeCheck, SIGNAL(stateChanged(int)),this,SLOT(playTimeCheckProc(int)));
    connect(playCountCheck, SIGNAL(stateChanged(int)),this,SLOT(playCountCheckProc(int)));
    connect(borderCheck, SIGNAL(stateChanged(int)),this,SLOT(borderCheckProc(int)));

    //---
    connect(startDateEdit, SIGNAL(dateChanged(QDate)),this,SLOT(edited()));
    connect(endDateEdit, SIGNAL(dateChanged(QDate)),this,SLOT(edited()));
    connect(startTimeEdit, SIGNAL(timeChanged(QTime)),this,SLOT(edited()));
    connect(endTimeEdit, SIGNAL(timeChanged(QTime)),this,SLOT(edited()));
    connect(weekCheck[0], SIGNAL(clicked()),this,SLOT(edited()));
    connect(weekCheck[1], SIGNAL(clicked()),this,SLOT(edited()));
    connect(weekCheck[2], SIGNAL(clicked()),this,SLOT(edited()));
    connect(weekCheck[3], SIGNAL(clicked()),this,SLOT(edited()));
    connect(weekCheck[4], SIGNAL(clicked()),this,SLOT(edited()));
    connect(weekCheck[5], SIGNAL(clicked()),this,SLOT(edited()));
    connect(weekCheck[6], SIGNAL(clicked()),this,SLOT(edited()));
    connect(weekCheck[7], SIGNAL(clicked()),this,SLOT(edited()));
    //-----------------
    connect(dateTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    connect(weekTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    connect(timeCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    connect(playTimeCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    connect(playTimeEdit, SIGNAL(valueChanged(int)),this,SLOT(edited()));
    connect(playCountCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    connect(playCountEdit, SIGNAL(valueChanged(int)),this,SLOT(edited()));
    connect(borderCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));

    connect(borderCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    connect(styleCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
    connect(colorCombo,SIGNAL(indexChangeSignal()), this, SLOT(edited()));
    connect(speedCombo,SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
    connect(modeCombo,SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));

    //connect(borderEdit,SIGNAL(editSignal()),  this, SLOT(edited()));
}

void CprogProperty::disconnectSignal()
{
    disconnect(dateTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(dateTimerCheckProc(int)));
    disconnect(weekTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(weekTimerCheckProc(int)));
    disconnect(timeCheck, SIGNAL(stateChanged(int)),this,SLOT(timeCheckProc(int)));
    disconnect(playTimeCheck, SIGNAL(stateChanged(int)),this,SLOT(playTimeCheckProc(int)));
    disconnect(playCountCheck, SIGNAL(stateChanged(int)),this,SLOT(playCountCheckProc(int)));
    disconnect(borderCheck, SIGNAL(stateChanged(int)),this,SLOT(borderCheckProc(int)));

    //---
    disconnect(startDateEdit, SIGNAL(dateChanged(QDate)),this,SLOT(edited()));
    disconnect(endDateEdit, SIGNAL(dateChanged(QDate)),this,SLOT(edited()));
    disconnect(startTimeEdit, SIGNAL(timeChanged(QTime)),this,SLOT(edited()));
    disconnect(endTimeEdit, SIGNAL(timeChanged(QTime)),this,SLOT(edited()));
    disconnect(weekCheck[0], SIGNAL(clicked()),this,SLOT(edited()));
    disconnect(weekCheck[1], SIGNAL(clicked()),this,SLOT(edited()));
    disconnect(weekCheck[2], SIGNAL(clicked()),this,SLOT(edited()));
    disconnect(weekCheck[3], SIGNAL(clicked()),this,SLOT(edited()));
    disconnect(weekCheck[4], SIGNAL(clicked()),this,SLOT(edited()));
    disconnect(weekCheck[5], SIGNAL(clicked()),this,SLOT(edited()));
    disconnect(weekCheck[6], SIGNAL(clicked()),this,SLOT(edited()));
    disconnect(weekCheck[7], SIGNAL(clicked()),this,SLOT(edited()));
    //-----------------
    disconnect(dateTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    disconnect(weekTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    disconnect(timeCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    disconnect(playTimeCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    disconnect(playTimeEdit, SIGNAL(valueChanged(int)),this,SLOT(edited()));
    disconnect(playCountCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    disconnect(playCountEdit, SIGNAL(valueChanged(int)),this,SLOT(edited()));
    disconnect(borderCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));

    disconnect(borderCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    disconnect(styleCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
    disconnect(colorCombo,SIGNAL(indexChangeSignal()), this, SLOT(edited()));
    disconnect(speedCombo,SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
    disconnect(modeCombo,SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));

    //disconnect(borderEdit,SIGNAL(editSignal()),  this, SLOT(edited()));

}

//从settings设置到widget中
void CprogProperty::setSettingsToWidget(QString str)
{
    QStringList keys;
    int year,month,day,hour,min,sec,tmp;
    QDate date;
    QTime time;

    disconnectSignal();

    settings.beginGroup(str);
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag == 0)
    {
      settings.setValue("setFlag", 1);
    }

    //名字
    //nameEdit->setText(settings.value("name").toString());

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
    sec = settings.value("startSec").toInt();
    time.setHMS(hour, min, sec, 0);
    startTimeEdit->setTime(time);

    hour = settings.value("endHour").toInt();
    min = settings.value("endMin").toInt();
    sec = settings.value("endSec").toInt();
    time.setHMS(hour, min, sec, 0);
    endTimeEdit->setTime(time);

    //播放模式
    if(settings.value("playMode").toInt() EQ 0)
    {
      playCountCheck->setChecked(true);
      playTimeCheck->setChecked(false);
    }
    else
    {
        playCountCheck->setChecked(false);
        playTimeCheck->setChecked(true);
    }

    //playTimeCheck->setChecked(settings.value("playTimeCheck").toBool());
    tmp = settings.value("playTime").toInt();
    playTimeEdit->setValue(tmp);//setText(QString::number(tmp));
    //playTimeEdit->setFixedWidth(50);
    tmp = settings.value("playCount").toInt();
    playCountEdit->setValue(tmp);//setText(QString::number(tmp));
    //playCountEdit->setFixedWidth(50);
    //边框选择
    borderCheck->setChecked(settings.value("borderCheck").toBool());
    //stepCombo->setText(QString::number(settings.value("width").toInt()));
    //stepCombo->setCurrentIndex(settings.value("borderStep").toInt());

    //stepCombo->addItem(tr("2"));

    speedCombo->setCurrentIndex(settings.value("borderSpeed").toInt());


    styleCombo->setCurrentIndex(settings.value("borderStyle").toInt());
    colorCombo->setCurrentIndex(settings.value("borderColor").toInt());
    modeCombo->setCurrentIndex(settings.value("borderMode").toInt());

    settings.endGroup();

    connectSignal();

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

    nameEdit->setSettingsToWidget(str);
    //borderEdit->setSettingsToWidget(str);
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
    //settings.setValue("name",QVariant(nameEdit->text()));
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
    settings.setValue("timeCheck", QVariant(timeCheck->checkState()));

    settings.setValue("startHour", startTimeEdit->time().hour());
    settings.setValue("startMin", startTimeEdit->time().minute());
    settings.setValue("startSec", startTimeEdit->time().second());
    settings.setValue("endHour", endTimeEdit->time().hour());
    settings.setValue("endMin", endTimeEdit->time().minute());
    settings.setValue("endSec", endTimeEdit->time().second());

    //定长播放
    if(playCountCheck->isChecked())
      settings.setValue("playMode", 0);
    else
      settings.setValue("playMode", 1);

    //playTimeCheck->setChecked(settings.value("playTimeCheck").toBool());
    //settings.setValue("playTimeCheck", QVariant(playTimeCheck->checkState()));
    //playTimeEdit->setText(settings.value("playTime").toString());
    settings.setValue("playTime", QVariant(playTimeEdit->value()));
    //settings.setValue("playCountCheck", QVariant(playCountCheck->checkState()));
    settings.setValue("playCount", QVariant(playCountEdit->value()));
      //边框选择
      //borderCheck->setChecked(settings.value("boderCheck").toBool());
    settings.setValue("borderCheck", QVariant(borderCheck->checkState()));
    //stepCombo->setText(settings.value("width").toString());
    //settings.setValue("borderStep", QVariant(stepCombo->currentIndex()));
    //speedCombo->setText(settings.value(bo).toString());
    settings.setValue("borderSpeed", QVariant(speedCombo->currentIndex()));
    //styleCombo->setCurrentIndex(settings.value( m,).toInt());
    settings.setValue("borderStyle", QVariant(styleCombo->currentIndex()));
    //modeCombo->setCurrentIndex(settings.value("borderColor").toInt());
    settings.setValue("borderColor", QVariant(colorCombo->currentIndex()));
    settings.setValue("borderMode", QVariant(modeCombo->currentIndex()));
   }

    settings.endGroup();

    nameEdit->getSettingsFromWidget(str);
   // borderEdit->getSettingsFromWidget(str);

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

    //stepCombo->setEnabled(flag);
    speedCombo->setEnabled(flag);
    styleCombo->setEnabled(flag);
    modeCombo->setEnabled(flag);
    colorCombo->setEnabled(flag);
}
//属性编辑的SLOT
void CprogProperty::edited()
{
    CscreenArea *area;
    QTreeWidgetItem *item;

    //qDebug("propertyEdited");
    area = w->screenArea; //当前焦点分区

    if(area != (CscreenArea *)0) //
    {
        //当前选中的item
        item = area->progItem;//w->progManage->treeWidget->currentItem();////// //w->progManage->treeWidget->currentItem();
        if(item != (QTreeWidgetItem *)0)
        {
            QString str = item->data(0,Qt::UserRole).toString();
            getSettingsFromWidget(str);
            updateProgShowArea(area);
        }
    }
}

//刷新显示区域
void updateProgShowArea(CscreenArea *area)
{
    //CshowArea *area;
    QString str;
    //QTreeWidgetItem *item;

    if(area != (CscreenArea *)0) //
    {
        //item = area->treeItem;
        str = area->progItem->data(0,Qt::UserRole).toString();

        getProgParaFromSettings(str,area->progPara);
        //area->imageBk = getLineTextImage(str);
        area->updateFlag = true;

        //qDebug("file_para flag = %d", area->filePara.Temp_Para.Flag);
        area->update(); //刷新显示

    }
    else
    {
        ASSERT_FAILED();
    }

}
//获取某个存储项目下所有选中的项目数
QStringList getSettingsCheckedSubList(QString settingsStr)
{
    int i;
    //int counts = 0;
    QStringList subList, checkedList;


    checkedList.clear();

    settings.beginGroup(settingsStr);
    subList = settings.childGroups();

    for(i = 0; i < subList.size(); i ++)
    {
       settings.beginGroup(subList.at(i));
       if(settings.value("checkState").toBool() EQ true)
           checkedList.append(subList.at(i));
       settings.endGroup();
    }

    settings.endGroup();
    return checkedList;
}
/*
typedef struct
{
  INT8U Head;
  INT8U Prog_No; //节目号
  //INT8U Program_Cycles; //循环次数
  //INT16U Program_Stay_Sec; //停留秒数
  S_Program_Timing Timing[3]; //节目定时设置
  INT8U Area_Num; //分区数
  INT8U Main_Area_No; //主分区号
  INT8U Area_File_Num[MAX_AREA_NUM]; //每分区文件数
  S_Area Area[MAX_AREA_NUM]; //区域定义

  INT8U Border_Speed; //边框运行速度
  INT8U Border_Mode;  //边框模式
  INT8U Border_Width;   //边框宽度
  INT8U Border_Height;  //边框高度
  INT8U Temp;   //备用
  INT8U Border_Data[3*MAX_BORDER_POINTS/8]; //边框数据

  INT8U CS[CS_BYTES];

  INT8U Tail;
}S_Prog_Para;
 */
void getProgParaFromSettings(QString str, S_Prog_Para &para)
{
  int index;
  INT8U color,check;
  INT8U Re;

  memset(&para, 0, sizeof(para));
  color = Screen_Para.Base_Para.Color;//w->screenArea->screenPara.Color;

  settings.beginGroup(str);

  //按星期定时选择
  para.Timing[0].Week_Check = settings.value("weekTimerCheck").toBool();
  para.Timing[0].Week_Flag = 0;
  if(para.Timing[0].Week_Check > 0)
  {
      if(settings.value("w0").toBool())
        SET_BIT(para.Timing[0].Week_Flag, 0);
      if(settings.value("w1").toBool())
        SET_BIT(para.Timing[0].Week_Flag, 1);
      if(settings.value("w2").toBool())
        SET_BIT(para.Timing[0].Week_Flag, 2);
      if(settings.value("w3").toBool())
        SET_BIT(para.Timing[0].Week_Flag, 3);
      if(settings.value("w4").toBool())
        SET_BIT(para.Timing[0].Week_Flag, 4);
      if(settings.value("w5").toBool())
        SET_BIT(para.Timing[0].Week_Flag, 5);
      if(settings.value("w6").toBool())
        SET_BIT(para.Timing[0].Week_Flag, 6);
  }

  //按日期定时选择
  para.Timing[0].Date_Check = settings.value("dateTimerCheck").toBool();
  if(para.Timing[0].Date_Check > 0)
  {
      para.Timing[0].Start_Date[0] = (INT8U)settings.value("startYear").toInt();
      para.Timing[0].Start_Date[1] = (INT8U)settings.value("startMonth").toInt();
      para.Timing[0].Start_Date[2] = (INT8U)settings.value("startDay").toInt();

      //结束年月日
      para.Timing[0].End_Date[0] = (INT8U)settings.value("endYear").toInt();
      para.Timing[0].End_Date[1] = (INT8U)settings.value("endMonth").toInt();
      para.Timing[0].End_Date[2] = (INT8U)settings.value("endDay").toInt();
  }

  //按时间定时选择
  para.Timing[0].Time_Check = settings.value("timeCheck").toBool();
  if(para.Timing[0].Time_Check > 0)
  {
      para.Timing[0].Start_Time[0] = (INT8U)settings.value("startHour").toInt();
      para.Timing[0].Start_Time[1] = (INT8U)settings.value("startMin").toInt();

      //结束年月日
      para.Timing[0].End_Time[0] = (INT8U)settings.value("endHour").toInt();
      para.Timing[0].End_Time[1] = (INT8U)settings.value("endMin").toInt();
  }

  if(settings.value("playCountCheck").toBool())//按次数播放?
  {
    para.Mode = PROG_COUNTS_MODE;
    para.Counts = (INT16U)settings.value("playCount").toInt();
  }
  else if(settings.value("playTimeCheck").toBool())//按时间播放
  {
    para.Mode = PROG_TIME_MODE;
    para.Time = settings.value("playTime").toInt();
  }
  else
  {
    para.Mode = PROG_COUNTS_MODE;
    para.Counts = 1;//(INT16U)settings.value("playCount").toInt();
  }

  index = settings.value("borderStyle").toInt();
  color = settings.value("borderColor").toInt();
  check = settings.value("borderCheck").toBool();

  para.Border_Mode = settings.value("borderMode").toInt();
  //para.Border_Speed = settings.value("borderSpeed").toInt();
  para.Border_StayTime = (INT16U)(settings.value("borderSpeed").toInt() + 1)*MOVE_STEP_PERIOD;

  para.Border_Check = check;
  para.Border_Width = Border_Data[index].Width;
  para.Border_Height = Border_Data[index].Height;


  memset(para.Border_Data, 0, sizeof(para.Border_Data));

  if(check > 0)
  {
      for(int i = 0; i < para.Border_Width; i ++)
          for(int j = 0; j < para.Border_Height; j++)
          {
         //Re = Get_Buf_Point_Data((INT8U *)Border_Data[index].Data, sizeof(Border_Data[index].Data), color, Border_Data[index].Width, i, j);
          Re = Get_Rect_Buf_Bit((INT8U *)Border_Data[index].Data, sizeof(Border_Data[index].Data),\
                           para.Border_Width, i, j);
          Re = (Re << color);
          Set_Buf_Point_Data((INT8U *)para.Border_Data, sizeof(para.Border_Data), Screen_Para.Base_Para.Color, para.Border_Width, i, j, Re);
       }
  //memcpy(para.Border_Data, Border_Data[index].Data, sizeof(Border_Data[index].Data));
  }

  settings.endGroup();

  //settings.beginGroup(str + "/area");
  QStringList areaList =  getSettingsCheckedSubList(str + "/area");//settings.childGroups();
  int areaNum = areaList.size();
 // settings.endGroup();

  //分区数
  if(areaNum > MAX_AREA_NUM)
      para.Area_Num = MAX_AREA_NUM;
  else
      para.Area_Num = (INT8U)areaNum;

  //每个分区的位置、大小和文件数
  for(int i = 0; i < para.Area_Num; i ++)
  {
      QString areaStr = str + "/area/" + areaList.at(i) ;
      settings.beginGroup(areaStr);

      para.Area[i].X = (INT16U)settings.value("x").toInt();
      para.Area[i].Y = (INT16U)settings.value("y").toInt();
      para.Area[i].X_Len = (INT16U)settings.value("width").toInt();
      para.Area[i].Y_Len = (INT16U)settings.value("height").toInt();

      //settings.beginGroup("file");
      para.Area_File_Num[i] = getSettingsCheckedSubList("file").size();//settings.childGroups().size();//文件数
      //settings.endGroup();

      settings.endGroup();
  }

  SET_HT(para);
  SET_SUM(para);

}
