#include "progProperty.h"
#include "..\Includes.h"
#include <QSettings>
#include <QDate>
#include "mainwindow.h"


extern MainWindow *w;
extern QSettings settings;

//����߿�����
const S_Border_Data Border_Data[] =
{
    /*--  ÿ�����һ����Ԫ  --*/
    /*--  ����x�߶�=40x8  --*/
    {40,1,{0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x01,
    0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00,0x00,
    0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01}},
    /*--  ÿ10����һ����Ԫ  --*/
    /*--  ����x�߶�=40x8  --*/
    {40,1,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,
    0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,
    0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01}},

    /*--    --*/
    /*--  ����x�߶�=40x8  --*/
    {40,2,{0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
    0x03,0x03,0x03,0x00,0x00,0x00,0x00,0x00}},

    /*--  ������һ��ͼ���������½���ͼ��  --*/
    /*--  ����x�߶�=40x8  --*/
    {40,2,{0x01,0x01,0x01,0x01,0x01,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x01,
    0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
    0x03,0x03,0x03,0x01,0x01,0x01,0x01,0x01}},

    /*--  ������һ��ͼ���������½���ͼ��  --*/
    /*--  ����x�߶�=40x8  --*/
    {40,2,{0x02,0x02,0x02,0x02,0x02,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x02,
    0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
    0x03,0x03,0x03,0x02,0x02,0x02,0x02,0x02}}


};

QImage getBorderImage(int index, QColor color)
{

   int i,j;

   if(index >= sizeof(Border_Data)/sizeof(Border_Data[0]))
   {
       ASSERT_FAILED();
       return QImage(0,0);
   }

   QImage border(Border_Data[index].Width, Border_Data[index].Height, QImage::Format_RGB32);
   border.fill(Qt::black);
   for(i = 0; i < border.width(); i ++)
       for(j = 0; j <border.height(); j++)
       {
         if(Get_Rect_Buf_Bit((INT8U *)Border_Data[index].Data, sizeof(Border_Data[index].Data), Border_Data[index].Width, i, j) > 0)
             border.setPixel(i, j, color.rgb());
   }

   //border = border.scaled(border.width(), border.height());
   //border.save("d:\\border.png");
   return border;
}

//��Ŀ���Ա༭
CprogProperty::CprogProperty(QWidget *parent):QWidget(parent)
{
    QGridLayout *gridLayout,*timerGroupLayout;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;

    hLayout = new QHBoxLayout(this);

    //nameGroup = new QGroupBox(tr("��Ŀ����"),this);
    //nameLabel = new QLabel(tr("����"), this);

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

    //mainLayout = new QGridLayout(this); //������
    //mainLayout -> addWidget(nameLabel, 0, 0);
    //mainLayout -> addWidget(nameEdit, 0, 1);

    timerGroupLayout = new QGridLayout(this); //��ʱ���Ų���
    gridLayout = new QGridLayout(this); //�����򲼾�

    timerGroup = new QGroupBox(tr("��ʱ����"), this);

    //�����ڶ�ʱ
    dateGroup = new QGroupBox(this);
    dateTimerCheck = new QCheckBox(tr("�����ڶ�ʱ"), this);
    startDateLabel = new QLabel(tr("��ʼ����"), this);
    endDateLabel = new QLabel(tr("��������"), this);
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

    //�����ڶ�ʱ
    gridLayout = new QGridLayout(this);
    weekGroup = new QGroupBox( this);
    weekTimerCheck = new QCheckBox(tr("�����ڶ�ʱ"), this);
    weekCheck[0] = new QCheckBox(tr("����һ"), this);
    weekCheck[1] = new QCheckBox(tr("���ڶ�"), this);
    weekCheck[2] = new QCheckBox(tr("������"), this);
    weekCheck[3] = new QCheckBox(tr("������"), this);
    weekCheck[4] = new QCheckBox(tr("������"), this);
    weekCheck[5] = new QCheckBox(tr("������"), this);
    weekCheck[6] = new QCheckBox(tr("������"), this);
    //weekCheck[7] = new QCheckBox(tr("ȫѡ"), this);
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

    //��ʱ�䶨ʱ
    gridLayout = new QGridLayout(this);
    timeGroup = new QGroupBox(this);
    timeCheck = new QCheckBox(tr("��ʱ�䶨ʱ"), this);
    startTimeLabel = new QLabel(tr("��ʼʱ��"), this);
    endTimeLabel = new QLabel(tr("����ʱ��"), this);
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
    //���ų���
    gridLayout = new QGridLayout(this);
    playTimeGroup = new QGroupBox(tr("���ų���"), this);
    playTimeCheck = new QCheckBox(tr("��������"), this);
    playTimeEdit = new QLineEdit(this);
    playTimeLabel = new QLabel(tr("��"));

    playCountCheck = new QCheckBox(tr("˳�β���"), this);
    playCountEdit = new QLineEdit(this);
    playCountLabel = new QLabel(tr("��"));

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


    //��ˮ�߿�ѡ��
    gridLayout = new QGridLayout(this);
    borderGroup = new QGroupBox(tr("��ˮ�߿�ѡ��"), this);
    borderCheck = new QCheckBox(tr("������ˮ�߿�"), this);
    stepLabel = new QLabel(tr("����"), this);
    pointsLabel = new QLabel(tr("����"), this);
    styleLabel = new QLabel(tr("��ʽ"), this);
    modeLabel = new QLabel(tr("��Ч"), this);
    speedLabel = new QLabel(tr("�ٶ�"), this);
    usLabel = new QLabel(tr("΢��"), this);
    stepCombo = new QComboBox(this);//new QLineEdit(this); //����
    speedCombo = new QComboBox(this);
    colorCombo = new CcolorCombo(this);
    styleCombo = new QComboBox(this);
    modeCombo = new QComboBox(this);//CmodeCombo(this);
    gridLayout -> addWidget(borderCheck, 0, 0, 1, 2);
    gridLayout -> addWidget(stepLabel, 1, 0);
    gridLayout -> addWidget(stepCombo, 1, 1);
    gridLayout -> addWidget(pointsLabel, 1, 2);
    gridLayout -> addWidget(styleLabel, 2, 0);
    gridLayout -> addWidget(styleCombo, 2, 1);
     gridLayout -> addWidget(colorCombo, 2, 2);
    gridLayout -> addWidget(modeLabel, 3, 0);
    gridLayout -> addWidget(modeCombo, 3, 1);
    gridLayout -> addWidget(speedLabel, 4, 0);
    gridLayout -> addWidget(speedCombo, 4, 1);
    gridLayout -> addWidget(usLabel, 4, 2);
    borderGroup -> setLayout(gridLayout);
    //mainLayout -> addWidget(borderGroup, 1, 2);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(borderGroup);
    hLayout->addLayout(vLayout);

    hLayout->addStretch(10);
    setLayout(hLayout);

  //-----------------------------------------------------
  /*
   styleCombo->addItem(tr("1��˳ʱ��"));
   styleCombo->addItem(tr("2��˳ʱ��"));
   styleCombo->addItem(tr("3��˳ʱ��"));
   styleCombo->addItem(tr("4��˳ʱ��"));
   styleCombo->addItem(tr("5��˳ʱ��"));
   styleCombo->addItem(tr("6��˳ʱ��"));
   styleCombo->addItem(tr("7��˳ʱ��"));
   styleCombo->addItem(tr("8��˳ʱ��"));

   styleCombo->addItem(tr("1����ʱ��"));
   styleCombo->addItem(tr("2����ʱ��"));
   styleCombo->addItem(tr("3����ʱ��"));
   styleCombo->addItem(tr("4����ʱ��"));
   styleCombo->addItem(tr("5����ʱ��"));
   styleCombo->addItem(tr("6����ʱ��"));
   styleCombo->addItem(tr("7����ʱ��"));
   styleCombo->addItem(tr("8����ʱ��"));
  */


   styleCombo->setIconSize(QSize(40,8));

   for(int i = 0; i < S_NUM(Border_Data); i ++)
    {
       QPixmap borderPixmap;
       QImage borderImage;
       borderImage = getBorderImage(i, QColor(Qt::red));
       borderImage = borderImage.scaled(borderImage.width()*10, borderImage.height()*20);
       borderPixmap.convertFromImage(borderImage);
       styleCombo->addItem(QIcon(borderPixmap), QString("%1").arg(Border_Data[i].Height));

   }

   modeCombo->addItem(tr("��̬"));
   modeCombo->addItem(tr("��˸"));
   modeCombo->addItem(tr("˳ʱ���ƶ�"));
   modeCombo->addItem(tr("��ʱ���ƶ�"));
   modeCombo->addItem(tr("˳ʱ����˸�ƶ�"));
   modeCombo->addItem(tr("��ʱ����˸�ƶ�"));

   //modeCombo->addItem(tr("��ɫ"));
   //modeCombo->addItem(tr("��ɫ"));
   //modeCombo->addItem(tr("��ɫ"));

   //�����ڶ�ʱѡ��
   dateTimerCheckProc((int)dateTimerCheck->checkState());
   //�����ڶ�ʱѡ��
   weekTimerCheckProc((int)weekTimerCheck->checkState());
   //��ʱ�䶨ʱѡ��
   timeCheckProc((int)timeCheck->checkState());
   //��������ѡ��
   playTimeCheckProc((int)playTimeCheck->checkState());
   playCountCheckProc((int)playCountCheck->checkState());
   //�߿�ѡ��
   borderCheckProc((int)borderCheck->checkState());

   stepCombo->addItem(tr("1"));
   stepCombo->addItem(tr("2"));
   stepCombo->addItem(tr("3"));
   stepCombo->addItem(tr("4"));
   stepCombo->addItem(tr("5"));
   stepCombo->addItem(tr("6"));
   stepCombo->addItem(tr("7"));
   stepCombo->addItem(tr("8"));

   speedCombo->addItem(tr("1���"));
   speedCombo->addItem(tr("2"));
   speedCombo->addItem(tr("3"));
   speedCombo->addItem(tr("4"));
   speedCombo->addItem(tr("5"));
   speedCombo->addItem(tr("6"));
   speedCombo->addItem(tr("7"));
   speedCombo->addItem(tr("8"));
   speedCombo->addItem(tr("9"));
   speedCombo->addItem(tr("10����"));

   //connect(weekCheck[7], SIGNAL(stateChanged(int)),this,SLOT(allWeekDayCheckProc(int)));
   connect(dateTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(dateTimerCheckProc(int)));
   connect(weekTimerCheck, SIGNAL(stateChanged(int)),this,SLOT(weekTimerCheckProc(int)));
   connect(timeCheck, SIGNAL(stateChanged(int)),this,SLOT(timeCheckProc(int)));
   connect(playTimeCheck, SIGNAL(stateChanged(int)),this,SLOT(playTimeCheckProc(int)));
   connect(playCountCheck, SIGNAL(stateChanged(int)),this,SLOT(playCountCheckProc(int)));
   connect(borderCheck, SIGNAL(stateChanged(int)),this,SLOT(borderCheckProc(int)));

   //-----------------
   connect(borderCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
   connect(styleCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
   connect(colorCombo,SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
}



CprogProperty::~CprogProperty()
{

}

/*
    //-----------����-------------
    QLabel *nameLabel;  //����
    QLineEdit *nameEdit; //���������

    //--------  �����ڶ�ʱ---------
    QGroupBox *dateGroup;
    QCheckBox *dateTimerCheck; //�����ڶ�ʱ
    QLabel *startDateLabel, *endDateLabel;
    QDateEdit *startDateEdit; //��ʼ����
    QDateEdit *endDateEdit; //��������

    //----------�����ڶ�ʱ-----------
    QGroupBox *weekGroup;
    QCheckBox *weekTimerCheck; //�����ڶ�ʱ
    QCheckBox *weekCheck[8]; //����ѡ��

    //----------��ʱ�䶨ʱ----------
    QGroupBox *timeGroup;
    QCheckBox *timeCheck; //��ʱ�䶨ʱ
    QLabel *startTimeLabel,*endTimeLabel;
    QTimeEdit *startTimeEdit; //��ʼʱ��
    QTimeEdit *endTimeEdit; //����ʱ��

    //------------��������----------
    QGroupBox *playTimeGroup; //����ʱ��
    QCheckBox *playTimeCheck; //��������
    QLineEdit *playTimeEdit; //ʱ��
    QLabel *playTimeLabel;

    //-------------�߿�ѡ��----------
    QGroupBox *borderGroup; //�߿�
    QCheckBox *borderCheck;

    QLabel *stepLabel,*styleLabel,*modeLabel,*speedLabel;
    QLabel *pointsLabel,*usLabel;
    QLineEdit *stepCombo, *speedCombo;
    QComboBox *styleCombo, *modeCombo;
 */
//��settings���õ�widget��
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

    disconnect(borderCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    disconnect(styleCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
    disconnect(colorCombo,SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));

    settings.beginGroup(str);
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag == 0)
    {
      settings.setValue("setFlag", 1);
    }

    //����
    //nameEdit->setText(settings.value("name").toString());

    //�����ڶ�ʱ
    dateTimerCheck->setChecked(settings.value("dateTimerCheck").toBool());
    //startDateEdit->setDate(QDate::fromString(settings.value("startDate").toString(),"yyyyMd"));
    //endDateEdit->setDate(QDate::fromString(settings.value("endDate").toString(),"yyyyMd"));
    //��ʼ������
    year = settings.value("startYear").toInt();
    month = settings.value("startMonth").toInt();
    day = settings.value("startDay").toInt();
    date.setDate(year, month, day);
    startDateEdit->setDate(date);
    //����������
    year = settings.value("endYear").toInt();
    month = settings.value("endMonth").toInt();
    day = settings.value("endDay").toInt();
    date.setDate(year, month, day);
    endDateEdit->setDate(date);

    //�����ڶ�ʱ
    weekTimerCheck->setChecked(settings.value("weekTimerCheck").toBool());
    weekCheck[0]->setChecked(settings.value("w0").toBool());
    weekCheck[1]->setChecked(settings.value("w1").toBool());
    weekCheck[2]->setChecked(settings.value("w2").toBool());
    weekCheck[3]->setChecked(settings.value("w3").toBool());
    weekCheck[4]->setChecked(settings.value("w4").toBool());
    weekCheck[5]->setChecked(settings.value("w5").toBool());
    weekCheck[6]->setChecked(settings.value("w6").toBool());
    //weekCheck[7]->setChecked(settings.value("w7").toBool());

    //��ʱ�䶨ʱ
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

    //��������
    playTimeCheck->setChecked(settings.value("playTimeCheck").toBool());
    playTimeEdit->setText(QString::number(settings.value("playTime").toInt()));
    playTimeEdit->setFixedWidth(50);
    playCountCheck->setChecked(settings.value("playCountCheck").toBool());
    playCountEdit->setText(QString::number(settings.value("playCount").toInt()));
    playCountEdit->setFixedWidth(50);
    //�߿�ѡ��
    borderCheck->setChecked(settings.value("borderCheck").toBool());
    //stepCombo->setText(QString::number(settings.value("width").toInt()));
    stepCombo->setCurrentIndex(settings.value("step").toInt());

    //stepCombo->addItem(tr("2"));

    speedCombo->setCurrentIndex(settings.value("speed").toInt());


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

    connect(borderCheck, SIGNAL(stateChanged(int)),this,SLOT(edited()));
    connect(styleCombo, SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));
    connect(colorCombo,SIGNAL(currentIndexChanged(int)), this, SLOT(edited()));

    //�����ڶ�ʱѡ��
    dateTimerCheckProc((int)dateTimerCheck->checkState());
    //�����ڶ�ʱѡ��
    weekTimerCheckProc((int)weekTimerCheck->checkState());
    //��ʱ�䶨ʱѡ��
    timeCheckProc((int)timeCheck->checkState());
    //��������ѡ��
    playTimeCheckProc((int)playTimeCheck->checkState());
    playCountCheckProc((int)playCountCheck->checkState());
    //�߿�ѡ��
    borderCheckProc((int)borderCheck->checkState());

    nameEdit->setSettingsToWidget(str);
}

//��Widget��ȡ���õ�settings��,strΪSettings��group
void CprogProperty::getSettingsFromWidget(QString str)
{
    QStringList keys;

    settings.beginGroup(str);
    //keys = settings.allKeys();
    //if(keys.isEmpty() == false)
    {
      //����
      //nameEdit->setText(settings.value("name").toString());
    //settings.setValue("name",QVariant(nameEdit->text()));
      //�����ڶ�ʱ
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

    //�����ڶ�ʱ
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

      //��ʱ�䶨ʱ
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

    //��������
      //playTimeCheck->setChecked(settings.value("playTimeCheck").toBool());
    settings.setValue("playTimeCheck", QVariant(playTimeCheck->checkState()));
    //playTimeEdit->setText(settings.value("playTime").toString());
    settings.setValue("playTime", QVariant(playTimeEdit->text().toInt()));
    settings.setValue("playCountCheck", QVariant(playCountCheck->checkState()));
    settings.setValue("playCount", QVariant(playCountEdit->text().toInt()));
      //�߿�ѡ��
      //borderCheck->setChecked(settings.value("boderCheck").toBool());
    settings.setValue("borderCheck", QVariant(borderCheck->checkState()));
    //stepCombo->setText(settings.value("width").toString());
    settings.setValue("step", QVariant(stepCombo->currentIndex()));
    //speedCombo->setText(settings.value("speed").toString());
    settings.setValue("speed", QVariant(speedCombo->currentIndex()));
    //styleCombo->setCurrentIndex(settings.value("style").toInt());
    settings.setValue("style", QVariant(styleCombo->currentIndex()));
    //modeCombo->setCurrentIndex(settings.value("color").toInt());
    settings.setValue("color", QVariant(colorCombo->currentIndex()));
    settings.setValue("mode", QVariant(modeCombo->currentIndex()));
   }

    settings.endGroup();

    nameEdit->getSettingsFromWidget(str);

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

    stepCombo->setEnabled(flag);
    speedCombo->setEnabled(flag);
    styleCombo->setEnabled(flag);
    modeCombo->setEnabled(flag);
    colorCombo->setEnabled(flag);
}
//���Ա༭��SLOT
void CprogProperty::edited()
{
    CscreenArea *area;
    QTreeWidgetItem *item;

    //qDebug("propertyEdited");
    area = w->screenArea; //��ǰ�������

    if(area != (CscreenArea *)0) //
    {
        //��ǰѡ�е�item
        item = area->progItem;//w->progManage->treeWidget->currentItem();////// //w->progManage->treeWidget->currentItem();
        if(item != (QTreeWidgetItem *)0)
        {
            QString str = item->data(0,Qt::UserRole).toString();
            getSettingsFromWidget(str);
            updateProgShowArea(area);
        }
    }
}

//ˢ����ʾ����
void updateProgShowArea(CscreenArea *area)
{
    //CshowArea *area;
    QString str;
    QTreeWidgetItem *item;

    if(area != (CscreenArea *)0) //
    {
        //item = area->treeItem;
        str = area->progItem->data(0,Qt::UserRole).toString();

        getProgParaFromSettings(str,area->progPara);
        //area->imageBk = getLineTextImage(str);
        area->updateFlag = true;

        //qDebug("file_para flag = %d", area->filePara.Temp_Para.Flag);
        area->update(); //ˢ����ʾ

    }
    else
    {
        ASSERT_FAILED();
    }

}
/*
typedef struct
{
  INT8U Head;
  INT8U Prog_No; //��Ŀ��
  //INT8U Program_Cycles; //ѭ������
  //INT16U Program_Stay_Sec; //ͣ������
  S_Program_Timing Timing[3]; //��Ŀ��ʱ����
  INT8U Area_Num; //������
  INT8U Main_Area_No; //��������
  INT8U Area_File_Num[MAX_AREA_NUM]; //ÿ�����ļ���
  S_Area Area[MAX_AREA_NUM]; //������

  INT8U Border_Speed; //�߿������ٶ�
  INT8U Border_Mode;  //�߿�ģʽ
  INT8U Border_Width;   //�߿����
  INT8U Border_Height;  //�߿�߶�
  INT8U Temp;   //����
  INT8U Border_Data[3*MAX_BORDER_POINTS/8]; //�߿�����

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

  //�����ڶ�ʱѡ��
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

  //�����ڶ�ʱѡ��
  para.Timing[0].Date_Check = settings.value("dateTimerCheck").toBool();
  if(para.Timing[0].Date_Check > 0)
  {
      para.Timing[0].Start_Date[0] = (INT8U)settings.value("startYear").toInt();
      para.Timing[0].Start_Date[1] = (INT8U)settings.value("startMonth").toInt();
      para.Timing[0].Start_Date[2] = (INT8U)settings.value("startDay").toInt();

      //����������
      para.Timing[0].End_Date[0] = (INT8U)settings.value("endYear").toInt();
      para.Timing[0].End_Date[1] = (INT8U)settings.value("endMonth").toInt();
      para.Timing[0].End_Date[2] = (INT8U)settings.value("endDay").toInt();
  }

  //��ʱ�䶨ʱѡ��
  para.Timing[0].Time_Check = settings.value("timeCheck").toBool();
  if(para.Timing[0].Time_Check > 0)
  {
      para.Timing[0].Start_Time[0] = (INT8U)settings.value("startHour").toInt();
      para.Timing[0].Start_Time[1] = (INT8U)settings.value("startMin").toInt();

      //����������
      para.Timing[0].End_Time[0] = (INT8U)settings.value("endHour").toInt();
      para.Timing[0].End_Time[1] = (INT8U)settings.value("endMin").toInt();
  }

  if(settings.value("playCountCheck").toBool())//����������?
  {
    para.Mode = PROG_COUNTS_MODE;
    para.Counts = (INT16U)settings.value("playCount").toInt();
  }
  else if(settings.value("playTimeCheck").toBool())//��ʱ�䲥��
  {
    para.Mode = PROG_TIME_MODE;
    para.Time = settings.value("playTime").toInt();
  }
  else
  {
    para.Mode = PROG_COUNTS_MODE;
    para.Counts = 1;//(INT16U)settings.value("playCount").toInt();
  }

  index = settings.value("style").toInt();
  color = settings.value("color").toInt();
  check = settings.value("borderCheck").toBool();

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

  settings.beginGroup(str + "/area");
  QStringList areaList = settings.childGroups();
  int areaNum = areaList.size();
  settings.endGroup();

  //������
  if(areaNum > MAX_AREA_NUM)
      para.Area_Num = MAX_AREA_NUM;
  else
      para.Area_Num = (INT8U)areaNum;

  //ÿ��������λ�á���С���ļ���
  for(int i = 0; i < para.Area_Num; i ++)
  {
      QString areaStr = str + "/area/" + areaList.at(i) ;
      settings.beginGroup(areaStr);

      para.Area[i].X = (INT16U)settings.value("x").toInt();
      para.Area[i].Y = (INT16U)settings.value("y").toInt();
      para.Area[i].X_Len = (INT16U)settings.value("width").toInt();
      para.Area[i].Y_Len = (INT16U)settings.value("height").toInt();

      settings.beginGroup("file");
      para.Area_File_Num[i] =settings.childGroups().size();//�ļ���
      settings.endGroup();

      settings.endGroup();
  }

  SET_HT(para);
  SET_SUM(para);

}