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
#include "..\Stm32\usr\app\led_show.h"
#include "..\Stm32\usr\app\Pic_show.h"
#include "mainwindow.h"

extern MainWindow *w;
extern QSettings settings;

#define TIME_EDIT_WIDTH 70


//定义边框数据
const S_Border_Data Border_Data[] =
{
    {40,1,{0xFF,0xFF,0xFF,0xFF,0xFF}},
    /*--  每五个点一个单元  --*/
    /*--  宽度x高度=40x8  --*/
    {40,1,{0xE0,0x83,0x0F,0x3E,0xF8}},
    /*--  每10个点一个单元  --*/
    /*--  宽度x高度=40x8  --*/
    {40,1,{0x00,0xFC,0x0F,0xC0,0xFF}},

    {40,2,{0xFF,0xFF,0xFF,0xFF,0xFF,
           0xFF,0xFF,0xFF,0xFF,0xFF}},
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

    {40,3,{0x22,0x22,0x22,0x22,0x22,
           0x77,0x77,0x77,0x77,0x77,
           0x22,0x22,0x22,0x22,0x22}},

{40,3,{0x22,0x22,0x22,0x22,0x22,
       0xCC,0x6C,0xCC,0xCC,0xCC,
       0x22,0x22,0x22,0x22,0x22}},

{40,3,{0x08,0x08,0x08,0x08,0x08,
       0x7F,0x7F,0x7F,0x7F,0x7F,
       0x08,0x08,0x08,0x08,0x08,}},

    {40,3,{0x00,0x00,0x00,0x00,0x08,
           0xFF,0xFF,0xFF,0xFF,0x7F,
           0x00,0x00,0x00,0x00,0x08}},

    {40,3,{0xFF,0x03,0xF0,0x3F,0x00,
           0xFF,0xFF,0xFF,0xFF,0xFF,
           0xFF,0x03,0xF0,0x3F,0x00}},

{40,3,{0xFF,0xFF,0xFF,0xFF,0xFF,
       0xFF,0x03,0xF0,0x3F,0x00,
       0xFF,0x03,0xF0,0x3F,0x00}},

{40, 3,{0x09,0x24,0x90,0x40,0x02,
        0x12,0x48,0x20,0x81,0x04,
        0x09,0x24,0x90,0x40,0x02}},

{40, 3,{0x08,0x20,0x80,0x00,0x02,
        0x14,0x50,0x40,0x01,0x05,
        0x08,0x20,0x80,0x00,0x02}},

{40, 3,{0x14,0x50,0x40,0x01,0x05,
        0x08,0x20,0x80,0x00,0x02,
        0x14,0x50,0x40,0x01,0x05}},

{40, 3,{0x0C,0x30,0xC0,0x00,0x03,
        0x33,0xCC,0x30,0xC3,0x0C,
        0x0C,0x30,0xC0,0x00,0x03}},

{40, 3,{0xFF,0x07,0xF8,0x7F,0x80,
        0x01,0x06,0x18,0x60,0x80,
        0x01,0xFE,0x1F,0xE0,0xFF}},

{40, 3,{0xFF,0xFC,0xF3,0xCF,0x3F,
        0x81,0x04,0x12,0x48,0x20,
        0xFF,0xFC,0xF3,0xCF,0x3F}},

{40, 3,{0xE0,0x7F,0x00,0xFE,0x07,
        0x3F,0xC0,0xFF,0x03,0xFC,
        0xE0,0x7F,0x00,0xFE,0x07}},

{40, 4,{0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF}},

{40, 4,{0x08,0x20,0x80,0x00,0x02,
        0x14,0x50,0x40,0x01,0x05,
        0x22,0x88,0x20,0x82,0x08,
        0x41,0x04,0x11,0x44,0x10}},

{40, 4,{0x18,0x60,0x80,0x01,0x06,
        0x3C,0xF0,0xC0,0x03,0x0F,
        0x7E,0xF8,0xE1,0x87,0x1F,
        0xFF,0xFC,0xF3,0xCF,0x3F}},

{40, 4,{0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0xFF,0xFF,0xFF,0xFF,
        0xFF,0x03,0xF0,0x3F,0x00,
        0xFF,0x03,0xF0,0x3F,0x00}},

{40, 4,{0xFF,0xFF,0xFF,0xFF,0xFF,
        0x01,0x02,0x10,0x20,0x00,
        0x01,0x02,0x10,0x20,0x00,
        0xFF,0x03,0xF0,0x3F,0x00}},
};

int getBorderWidth(int index)
{
    if(index >= S_NUM(Border_Data))
        index = 0;
    return Border_Data[index].Width;
}

int getBorderHeight(int index)
{
    if(index >= S_NUM(Border_Data))
        index = 0;
    return Border_Data[index].Height;
}

//获取边框数据
void getBorderData(QString str, INT8U Dst[], INT16U DstLen)
{
    bool check;
    INT8U Re;
    int width,height;

    if(DstLen <  BORDER_DATA_LEN)
    {
       ASSERT_FAILED();
       return;
    }

    memset(Dst, 0x00, BORDER_DATA_LEN);
    settings.beginGroup(str);
    settings.beginGroup("borderPara");
    check = settings.value("borderCheck").toBool();

    int style = settings.value("borderStyle").toInt();
    INT8U color = settings.value("borderColor").toInt();

    settings.endGroup();
    settings.endGroup();

    if(style >= S_NUM(Border_Data))
        style = 0;

    if(check)
    {
       width = Border_Data[style].Width;
       height = Border_Data[style].Height;

       for(int i = 0; i < width; i ++)
           for(int j = 0; j < height; j++)
           {
          //Re = Get_Buf_Point_Data((INT8U *)Border_Data[index].Data, sizeof(Border_Data[index].Data), color, Border_Data[index].Width, i, j);
           Re = Get_Rect_Buf_Bit((INT8U *)Border_Data[style].Data, sizeof(Border_Data[style].Data),\
                            width, i, j);
           if(color < 2)
             Re = (Re << color);
           else
             Re = (Re << 1) + Re;
           Set_Buf_Point_Data((INT8U *)Dst, DstLen, Screen_Para.Base_Para.Color, width, i, j, Re);
        }

    }
}

QImage getBorderImage(int type, int index, QColor color)
{

   int i,j;
   S_Simple_Border_Data *p;
/*
   if(index >= sizeof(Border_Data)/sizeof(Border_Data[0]))
   {
       ASSERT_FAILED();
       return QImage(0,0);
   }
*/
   if(index >= S_NUM(Border_Data))
       index = 0;

   //if(type EQ 0)
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
   /*
   else
   {
       p = Get_Simple_Border_Info(index);

       QImage border(p->Width, p->Height, QImage::Format_RGB32);
       border.fill(Qt::black);
       for(i = 0; i < border.width(); i ++)
           for(j = 0; j <border.height(); j++)
           {
             if(Get_Rect_Buf_Bit((INT8U *)(p->Data), MAX_SBORDER_DATA_LEN, p->Width, i, j) > 0)
                 border.setPixel(i, j, color.rgb());
       }

       return border;
   }
   */

   //border = border.scaled(border.width(), border.height());
   //border.save("d:\\border.png");

}
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
CshowModeCombo::CshowModeCombo(bool flag, QWidget *parent):QComboBox(parent)
{

  type = flag;
  setItems();
  connect(this, SIGNAL(currentIndexChanged(int)), this, SIGNAL(indexChangeSignal()));
  connect(mainObj, SIGNAL(screenChange()), this, SLOT(setItems()));
  /*
    if(flag EQ 0)
    {
        addItem(tr("随机"));
        addItem(tr("立即显示"));
        addItem(tr("连续左移"));
        addItem(tr("连续上移"));
        addItem(tr("左平移"));
        addItem(tr("右平移"));
        addItem(tr("上平移"));
        addItem(tr("下平移"));
        addItem(tr("左移"));
        addItem(tr("右移"));
        addItem(tr("上移"));
        addItem(tr("下移"));
        addItem(tr("左覆盖"));
        addItem(tr("右覆盖"));
        addItem(tr("上覆盖"));
        addItem(tr("下覆盖"));
        addItem(tr("左上覆盖"));
        addItem(tr("右上覆盖"));
        addItem(tr("左下覆盖"));
        addItem(tr("右下覆盖"));
        addItem(tr("左右开帘"));
        addItem(tr("上下开帘"));
        addItem(tr("左右合帘"));
        addItem(tr("上下合帘"));
        addItem(tr("顺时针覆盖"));
        addItem(tr("逆时针覆盖"));
        addItem(tr("向上飘雪"));
        addItem(tr("向下飘雪"));
        addItem(tr("闪烁"));
        addItem(tr("左镭射"));
        addItem(tr("右镭射"));
        addItem(tr("上镭射"));
        addItem(tr("下镭射"));
        addItem(tr("左拉伸"));
        //addItem(tr("右拉伸"));
        addItem(tr("上拉伸"));
        //addItem(tr("下拉伸"));
        addItem(tr("垂直拉伸"));
        addItem(tr("水平拉伸"));
        addItem(tr("左移弹出"));
        addItem(tr("上移弹出"));
        addItem(tr("水平百叶窗"));
        addItem(tr("垂直百叶窗"));
        addItem(tr("向左压缩"));
        addItem(tr("向上压缩"));
        addItem(tr("淡入"));
    }
    else
    {
        addItem(tr("随机"));
        addItem(tr("不清屏"));
        addItem(tr("立即清屏"));
        addItem(tr("左移"));
        addItem(tr("右移"));
        addItem(tr("上移"));
        addItem(tr("下移"));
        addItem(tr("左覆盖"));
        addItem(tr("右覆盖"));
        addItem(tr("上覆盖"));
        addItem(tr("下覆盖"));
        addItem(tr("左上覆盖"));
        addItem(tr("右上覆盖"));
        addItem(tr("左下覆盖"));
        addItem(tr("右下覆盖"));
        addItem(tr("左右开帘"));
        addItem(tr("上下开帘"));
        addItem(tr("左右合帘"));
        addItem(tr("上下合帘"));
        addItem(tr("顺时针覆盖"));
        addItem(tr("逆时针覆盖"));
        addItem(tr("淡出"));

    }
    */
 }

void CshowModeCombo::setItems()
{
    int inModeNum,outModeNum;

      disconnect(this, SIGNAL(currentIndexChanged(int)), this, SIGNAL(indexChangeSignal()));
      inModeNum = Card_Para.InMode_Num;
      outModeNum = Card_Para.OutMode_Num;
      //setFixedWidth(50);

      clear();
      if(type EQ 0)
      {
          addItem(tr("随机"));
          for(int i = 0; i <inModeNum; i++)
              addItem(tr(In_Mode_Func[i].name));

      }
      else
      {
          addItem(tr("随机"));
          addItem(tr("不清屏"));
          for(int i = 0; i <outModeNum; i++)
              addItem(tr(Out_Mode_Func[i].name));
      }

      connect(this, SIGNAL(currentIndexChanged(int)), this, SIGNAL(indexChangeSignal()));

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
    //QHBoxLayout *hLayout;
    //QVBoxLayout *vLayout;
    //QValidator *inoutSpeedValidator = new QIntValidator(0,999,this);
    QValidator *stayTimeValidator = new QIntValidator(0,9999,this);
    QValidator *playCountsValidator = new QIntValidator(1,255,this);
    //gridLayout = new QGridLayout(this);
    //vLayout=new QVBoxLayout(this);
    QGridLayout *mainLayout = new QGridLayout(this);

    setTitle(tr("显示特效"));
    inModeLabel = new QLabel(tr("引入特效"), this);
    inModeCombo = new CshowModeCombo(0, this);
    inSpeedEdit = new QComboBox(this);
    //inSpeedEdit->setFixedWidth(TIME_EDIT_WIDTH);
    inSpeedLabel = new QLabel(tr("引入速度"), this);
    //inSpeedEdit->setValidator(inoutSpeedValidator);
    inSpeedEdit->addItem(tr("1级(最快)"));
    inSpeedEdit->addItem(tr("2级"));
    inSpeedEdit->addItem(tr("3级"));
    inSpeedEdit->addItem(tr("4级"));
    inSpeedEdit->addItem(tr("5级"));
    inSpeedEdit->addItem(tr("6级"));
    inSpeedEdit->addItem(tr("7级"));
    inSpeedEdit->addItem(tr("8级"));
    inSpeedEdit->addItem(tr("9级"));
    inSpeedEdit->addItem(tr("10级(最慢)"));

    //inModeCombo->setFixedWidth(100);
    mainLayout->addWidget(inModeLabel, 0, 0);
    mainLayout->addWidget(inModeCombo, 0, 1, 1, 2);
    mainLayout->addWidget(inSpeedLabel, 1, 0);
    mainLayout->addWidget(inSpeedEdit,  1, 1,1,2);
    //vLayout->addLayout(hLayout);

    outModeLabel = new QLabel(tr("引出特效"), this);
    outModeCombo = new CshowModeCombo(1, this);
    outSpeedEdit = new QComboBox(this);
    //outSpeedEdit->setFixedWidth(TIME_EDIT_WIDTH);
    outSpeedLabel = new QLabel(tr("引出速度"), this);

    outSpeedEdit->addItem(tr("1级(最快)"));
    outSpeedEdit->addItem(tr("2级"));
    outSpeedEdit->addItem(tr("3级"));
    outSpeedEdit->addItem(tr("4级"));
    outSpeedEdit->addItem(tr("5级"));
    outSpeedEdit->addItem(tr("6级"));
    outSpeedEdit->addItem(tr("7级"));
    outSpeedEdit->addItem(tr("8级"));
    outSpeedEdit->addItem(tr("9级"));
    outSpeedEdit->addItem(tr("10级(最慢)"));

    //outModeCombo->setFixedWidth(100);
    mainLayout->addWidget(outModeLabel, 2, 0);
    mainLayout->addWidget(outModeCombo, 2, 1, 1,2);
    mainLayout->addWidget(outSpeedLabel, 3, 0);
    mainLayout->addWidget(outSpeedEdit, 3, 1,1,2);

    //hLayout->addStretch();
    //vLayout->addLayout(hLayout);

    stayTimeLabel = new QLabel(tr("停留时间"), this);
    stayTimeEdit = new QLineEdit(this);
    stayTimeEdit->setFixedWidth(TIME_EDIT_WIDTH);
    stayTimeUnitLabel = new QLabel(tr("秒"), this);
    stayTimeEdit->setValidator(stayTimeValidator);

    //hLayout = new QHBoxLayout(this);
    mainLayout->addWidget(stayTimeLabel, 4, 0);
    mainLayout->addWidget(stayTimeEdit, 4, 1);
    mainLayout->addWidget(stayTimeUnitLabel, 4, 2);
    //mainLayout->addStretch();
    //mainLayout->addLayout(hLayout);

    playCountsLabel = new QLabel(tr("播放次数"), this);
    playCountsEdit = new QLineEdit(this);
    playCountsEdit->setFixedWidth(TIME_EDIT_WIDTH);
    playCountsUnitLabel = new QLabel(tr("次"));
    playCountsEdit->setValidator(playCountsValidator);

    mainLayout->addWidget(playCountsLabel, 5, 0);
    mainLayout->addWidget(playCountsEdit, 5, 1);
    mainLayout->addWidget(playCountsUnitLabel, 5, 2);

    setLayout(mainLayout);
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

    connectSignal();
}

void getShowModeParaFromSettings(QString str, U_File_Para &para)
{
  settings.beginGroup(str);
  settings.beginGroup("showMode");

  para.Pic_Para.In_Mode = (INT8U)settings.value("inMode").toInt();
  para.Pic_Para.In_Speed = (INT16U)settings.value("inSpeed").toInt() + 1;
  //para.Pic_Para.In_Time |= 0x8000; //停留时间单位为ms，因此最高位置1
  para.Pic_Para.Out_Mode = (INT8U)settings.value("outMode").toInt();
  para.Pic_Para.Out_Speed = (INT16U)settings.value("outSpeed").toInt() + 1;
  //para.Pic_Para.Out_Time |= 0x8000; //停留时间单位为ms，因此最高位置1
  para.Pic_Para.Stay_Time = (INT16U)settings.value("stayTime").toInt();

  para.Pic_Para.Play_Counts = (INT8U)settings.value("playCounts").toInt();

  settings.endGroup();
  settings.endGroup();
}

//如果进入方式是连续左移、连续上移、左平移、右平移、上平移、下平移，则不清屏
void CshowModeEdit::inModeChanged()
{
    if(inModeCombo->currentIndex() >= 2 && inModeCombo->currentIndex() < 8)
    {
      outModeCombo->setCurrentIndex(1);
      outModeCombo->setEnabled(false);
    }
    else
    {
      //outModeCombo->setCurrentIndex(2);
      outModeCombo->setEnabled(true);
    }
/*
    if(inModeCombo->currentIndex() EQ 1)
    {
        inSpeedEdit->setCurrentIndex(0);
        inSpeedEdit->setEnabled(false);//setEditable(false);
    }
    else
    {
        inSpeedEdit->setEnabled(true);
    }
    */
}

void CshowModeEdit::outModeChanged()
{/*
    if(outModeCombo->currentIndex() EQ 2)
    {
        outSpeedEdit->setCurrentIndex(0);
        outSpeedEdit->setEnabled(false);//setEditable(false);
    }
    else
    {
        outSpeedEdit->setEnabled(true);
    }
    */
}

void CshowModeEdit::connectSignal()
{
    connect(inModeCombo, SIGNAL(currentIndexChanged(int)),this, SLOT(inModeChanged()));
    connect(outModeCombo, SIGNAL(currentIndexChanged(int)),this,SLOT(outModeChanged()));
    connect(inModeCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
    connect(outModeCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
    connect(inSpeedEdit, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(outSpeedEdit, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(stayTimeEdit, SIGNAL(textEdited(const QString &)),this,SIGNAL(edited()));
    connect(playCountsEdit, SIGNAL(textEdited(const QString &)),this,SIGNAL(edited()));

}

void CshowModeEdit::disconnectSignal()
{
    disconnect(inModeCombo, SIGNAL(currentIndexChanged(int)),this, SLOT(inModeChanged()));
    disconnect(inModeCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
    disconnect(outModeCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
    disconnect(inSpeedEdit, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    disconnect(outSpeedEdit, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    disconnect(stayTimeEdit, SIGNAL(textEdited(const QString &)),this,SIGNAL(edited()));
    disconnect(playCountsEdit, SIGNAL(textEdited(const QString &)),this,SIGNAL(edited()));

}

void CshowModeEdit::getSettingsFromWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("showMode");
    settings.setValue("inMode", inModeCombo->currentIndex());
    settings.setValue("inSpeed", inSpeedEdit->currentIndex());
    settings.setValue("outMode", outModeCombo->currentIndex());
    settings.setValue("outSpeed", outSpeedEdit->currentIndex());
    settings.setValue("stayTime", stayTimeEdit->text().toInt());
    settings.setValue("playCounts", playCountsEdit->text().toInt());
    settings.endGroup();
    settings.endGroup();

}

void CshowModeEdit::setSettingsToWidget(QString str)
{
    QStringList keys;
    QString text;


    disconnectSignal();

    settings.beginGroup(str);
    settings.beginGroup("showMode");
    int setFlag = settings.value("setFlag").toInt();
    if(setFlag == 0)
    {
      //名字
      settings.setValue("setFlag", 1);
      settings.setValue("inMode", 0);
      settings.setValue("inSpeed", 0);
      settings.setValue("outMode", 0);
      settings.setValue("outSpeed", 0);
      settings.setValue("stayTime", 5);
      settings.setValue("playCounts", 1);
      settings.setValue("text", QString(tr("图文显示")));
    }

    inModeCombo->setCurrentIndex(settings.value("inMode").toInt());
    inSpeedEdit->setCurrentIndex(settings.value("inSpeed").toInt());
    outModeCombo->setCurrentIndex(settings.value("outMode").toInt());
    outSpeedEdit->setCurrentIndex(settings.value("outSpeed").toInt());
    stayTimeEdit->setText(QString::number(settings.value("stayTime").toInt()));
    playCountsEdit->setText(QString::number(settings.value("playCounts").toInt()));

    /*
    text = settings.value("text").toString();
    if(text == "")
        text == QString(tr("图文显示"));
    //textEdit->clear();
    edit->getEdit()->setPlainText(text);*/
    settings.endGroup();
    settings.endGroup();

    connectSignal();

    inModeChanged();
}

CshowModeEdit::~CshowModeEdit()
{

}


CsmLineCombo::CsmLineCombo(QWidget *parent):QComboBox(parent)
{
    //QHBoxLayout *hLayout;

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
    //QVBoxLayout *vLayout;
    QLabel *label;

    //editGroup = new QGroupBox(this);
    smLineCombo = new QComboBox(this);

    smLineCombo->addItem(tr("单行显示"));
    smLineCombo->addItem(tr("多行显示"));
    label = new QLabel(tr("间距"),this);
    lineSpaceEdit = new QSpinBox(this);

    lineSpaceEdit->setMinimum(0);
    lineSpaceEdit->setMaximum(255);

    gridLayout = new QGridLayout(this);
    gridLayout->addWidget(smLineCombo,0,0,1,2);
    gridLayout->addWidget(label, 0, 2);
    gridLayout->addWidget(lineSpaceEdit, 0,3);

    setTitle(tr("单/多行显示"));
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
CdateEdit::CdateEdit(QWidget *parent):QGroupBox(parent)
{
    QHBoxLayout *hLayout;
    //QLabel *label;

    //dateCheck = new QCheckBox(tr("日期"),this);
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

    dateCombo->setFixedWidth(120);

    colorCombo = new CcolorCombo(this);
    sizeCombo = new CsizeCombo(this);

    hLayout = new QHBoxLayout(this);
    //hLayout->addWidget(dateCheck);
    hLayout->addWidget(dateCombo);
    //label = new QLabel(tr("颜色"), this);
    //hLayout->addWidget(label);
    hLayout->addWidget(sizeCombo);
    hLayout->addWidget(colorCombo);
    //hLayout->addStretch();
    //label = new QLabel(tr("大小"), this);
    this->setCheckable(true);
    this->setTitle(tr("显示日期"));

    setLayout(hLayout);

    connect(this, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    connect(dateCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(colorCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
    connect(sizeCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
}

void CdateEdit::screenCardParaChangeProc()
{
  colorCombo->setItems();
  sizeCombo->setItems();
}

//从Widget上获取设置
void CdateEdit::getSettingsFromWidget(QString str)
{
   settings.beginGroup(str);
   settings.beginGroup("dateEdit");
   settings.setValue("checked", this->isChecked());
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
       settings.setValue("checked", 1);
       settings.setValue("type", 0);
       settings.setValue("color", 0);
       settings.setValue("size", 0);

       settings.setValue("setFlag", 1);
    }
    this->setChecked(settings.value("checked").toBool());
    dateCombo->setCurrentIndex(settings.value("type").toInt());
    colorCombo->setCurrentIndex(settings.value("color").toInt());
    sizeCombo->setCurrentIndex(settings.value("size").toInt());
    settings.endGroup();
    settings.endGroup();
}

CdateEdit::~CdateEdit()
{

}

CweekEdit::CweekEdit(QWidget *parent):QGroupBox(parent)
{
    QHBoxLayout *hLayout;
    //QLabel *label;

    //weekCheck = new QCheckBox(tr("星期"),this);
    weekCombo = new QComboBox(this);
    weekCombo->addItem(tr("星期一"));
    weekCombo->addItem(tr("Monday"));
    weekCombo->addItem(tr("Mon"));
    weekCombo->addItem(tr("Lunedi"));
    weekCombo->addItem(tr("Montag"));
    weekCombo->addItem(tr("Lundi"));
    weekCombo->addItem(tr("げつうび"));

    weekCombo->setFixedWidth(120);

    colorCombo = new CcolorCombo(this);
    sizeCombo = new CsizeCombo(this);

    hLayout = new QHBoxLayout(this);
    //hLayout->addWidget(weekCheck);
    hLayout->addWidget(weekCombo);
    //label = new QLabel(tr("颜色"), this);
    //hLayout->addWidget(label);
    hLayout->addWidget(sizeCombo);
    hLayout->addWidget(colorCombo);
    //label = new QLabel(tr("大小"), this);
    this->setCheckable(true);
    this->setTitle(tr("显示星期"));
    //this->setAlignment(Qt::AlignHCenter);
    //hLayout->addStretch();

    //hLayout->addStretch();
    setLayout(hLayout);

    connect(this, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    connect(weekCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(colorCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
    connect(sizeCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
}

void CweekEdit::screenCardParaChangeProc()
{
  colorCombo->setItems();
  sizeCombo->setItems();
}

//从Widget上获取设置
void CweekEdit::getSettingsFromWidget(QString str)
{
   settings.beginGroup(str);
   settings.beginGroup("weekEdit");
   settings.setValue("checked", this->isChecked());
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
    this->setChecked(settings.value("checked").toBool());
    weekCombo->setCurrentIndex(settings.value("type").toInt());
    colorCombo->setCurrentIndex(settings.value("color").toInt());
    sizeCombo->setCurrentIndex(settings.value("size").toInt());
    settings.endGroup();
    settings.endGroup();
}

CweekEdit::~CweekEdit()
{

}

CtimeEdit::CtimeEdit(QWidget *parent):QGroupBox(parent)
{
    QHBoxLayout *hLayout;
    //QLabel *label;

    //timeCheck = new QCheckBox(tr("时间"),this);
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
    //hLayout ->addWidget(timeCheck);
    hLayout->addWidget(timeCombo);
    //label = new QLabel(tr("颜色"), this);
    //hLayout->addWidget(label);
    hLayout->addWidget(sizeCombo);
    hLayout->addWidget(colorCombo);
    //label = new QLabel(tr("大小"), this);
    //hLayout->addWidget(label);
    //hLayout->addStretch();

    setLayout(hLayout);
    this->setCheckable(true);
    this->setTitle(tr("显示时间"));

    connect(this, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    connect(timeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(colorCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
    connect(sizeCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
}

void CtimeEdit::screenCardParaChangeProc()
{
  colorCombo->setItems();
  sizeCombo->setItems();
}

//从Widget上获取设置
void CtimeEdit::getSettingsFromWidget(QString str)
{
   settings.beginGroup(str);
   settings.beginGroup("timeEdit");
   settings.setValue("checked", this->isChecked());
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

    this->setChecked(settings.value("checked").toBool());
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
  //hLayout->addStretch();
  setLayout(hLayout);
  //setTitle(tr("时差调整"));

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
    //QGridLayout *gridLayout;

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

void CdateTimeEdit::screenCardParaChangeProc()
{
  dateEdit->screenCardParaChangeProc();
  weekEdit->screenCardParaChangeProc();
  timeEdit->screenCardParaChangeProc();
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

    connect(tianganColor, SIGNAL(indexChangeSignal ()),this,SIGNAL(edited()));
    connect(nongliColor, SIGNAL(indexChangeSignal ()),this,SIGNAL(edited()));
    connect(jieqiColor, SIGNAL(indexChangeSignal ()),this,SIGNAL(edited()));

    connect(tianganFont, SIGNAL(indexChangeSignal ()),this,SIGNAL(edited()));
    connect(nongliFont, SIGNAL(indexChangeSignal ()),this,SIGNAL(edited()));
    connect(jieqiFont, SIGNAL(indexChangeSignal ()),this,SIGNAL(edited()));
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
void ClunEdit::screenCardParaChangeProc()
{
    tianganColor->setItems();
    nongliColor->setItems();
    jieqiColor->setItems();

    tianganFont->setItems();
    nongliFont->setItems();
    jieqiFont->setItems();
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
    //CshowArea *area;
    QTreeWidgetItem *item;

    //area = w->screenArea->getFocusArea(); //当前焦点分区

    //if(area != (CshowArea *)0) //
    {
        //当前选中的item
        item = w->progManage->treeWidget->currentItem();////// //w->progManage->treeWidget->currentItem();
        if(item != (QTreeWidgetItem *)0)
        {
            QString str = item->data(0,Qt::UserRole).toString();
            getSettingsFromWidget(str);

            if(checkStrType(str)!=SCREEN_PROPERTY)
              w->progManage->updateTextHead(item->parent());
            else
              w->progManage->updateTextHead(item);
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
  QIcon icon;
  bButton = new QPushButton(this);
  icon = QIcon::fromTheme(tr("粗体"), QIcon(rsrcPath + "/textbold.png"));
  bButton->setIcon(icon);
  iButton = new QPushButton(this);
  icon = QIcon::fromTheme(tr("斜体"), QIcon(rsrcPath + "/textitalic.png"));
  iButton->setIcon(icon);
  uButton = new QPushButton(this);
  icon = QIcon::fromTheme(tr("下划"), QIcon(rsrcPath + "/textunder.png"));
  uButton->setIcon(icon);

  //editCheck = new QCheckBox(tr("启用背景文字"), this);

  //oButton = new QPushButton(tr("打开"),this);
  int width = 20;
  bButton->setFixedWidth(width);
  iButton->setFixedWidth(width);
  uButton->setFixedWidth(width);

  bButton->setCheckable(true);
  iButton->setCheckable(true);
  uButton->setCheckable(true);
  //oButton->setCheckable(true);

  QLabel *textLabel = new QLabel(tr("文字"), this);
  lineEdit = new QLineEdit(this);
  lineEdit->setFixedWidth(115);

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
  hLayout -> addWidget(textLabel);
  hLayout -> addWidget(lineEdit);
  hLayout -> addWidget(bButton);
  hLayout -> addWidget(iButton);
  hLayout -> addWidget(uButton);
  //hLayout -> addWidget(editCheck);
  hLayout->addStretch(10);
  gridLayout->addLayout(hLayout, 1, 0);

  //hLayout = new QHBoxLayout(this);
  //hLayout -> addWidget(textLabel);
  //hLayout -> addWidget(lineEdit);
  //hLayout->addStretch();
  //hLayout -> addWidget(oButton);
  //gridLayout->addLayout(hLayout, 2, 0);

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
  setTitle(tr("显示背景文字"));
  setLayout(gridLayout);

  this->setCheckable(true);

  //所有的消息统一到一个消息
  connect(fontCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
  connect(fontSizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
  connect(colorCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
  connect(bButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
  connect(iButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
  connect(uButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
  connect(this, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
  connect(lineEdit, SIGNAL(textEdited(const QString &)),this,SIGNAL(edited()));
}

void CsimpleTextEdit::screenCardParaChangeProc()
{
    colorCombo->setItems();
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
  QRgb rgb,r,g,b;//ye;
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
   settings.setValue("editCheck", this->isChecked());//->checkState());
   settings.setValue("text", lineEdit->text());
   settings.endGroup();
   settings.endGroup();
}

void CsimpleTextEdit::setSettingsToWidget(QString str)
{
    disconnect(fontCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    disconnect(fontSizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    disconnect(colorCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
    disconnect(bButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    disconnect(iButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    disconnect(uButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    disconnect(this, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
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
    this->setChecked(settings.value("editCheck").toBool());
    lineEdit->setText(settings.value("text").toString());
    settings.endGroup();
    settings.endGroup();

    connect(fontCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(fontSizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(colorCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
    connect(bButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    connect(iButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    connect(uButton, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    connect(this, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
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

CborderEdit::CborderEdit(QWidget *parent):QGroupBox(parent)
{
    QGridLayout *gridLayout;

    //魔幻边框选择
    gridLayout = new QGridLayout(this);
    //borderGroup = new QGroupBox(tr("魔幻边框选择"), this);
    //borderCheck = new QCheckBox(tr("启用魔幻边框"), this);
    //stepLabel = new QLabel(tr("步长"), this);
    //pointsLabel = new QLabel(tr("点数"), this);
    styleLabel = new QLabel(tr("样式"), this);
    colorLabel = new QLabel(tr("颜色"), this);
    modeLabel = new QLabel(tr("特效"), this);
    speedLabel = new QLabel(tr("速度"), this);
    //usLabel = new QLabel(tr("微秒"), this);
    //stepCombo = new QComboBox(this);//new QLineEdit(this); //步长
    speedCombo = new QComboBox(this);
    colorCombo = new CcolorCombo(this);
    styleCombo = new QComboBox(this);
    modeCombo = new QComboBox(this);//CmodeCombo(this);
    //gridLayout -> addWidget(borderCheck, 0, 0, 1, 2);
    //gridLayout -> addWidget(stepLabel, 1, 0);
    //gridLayout -> addWidget(stepCombo, 1, 1);
    //gridLayout -> addWidget(pointsLabel, 1, 2);
    gridLayout -> addWidget(styleLabel, 0, 0);
    gridLayout -> addWidget(styleCombo, 0, 1);
    gridLayout -> addWidget(colorLabel, 1, 0);
    gridLayout -> addWidget(colorCombo, 1, 1);
    gridLayout -> addWidget(modeLabel, 2, 0);
    gridLayout -> addWidget(modeCombo, 2, 1, 1, 2);
    gridLayout -> addWidget(speedLabel, 3, 0);
    gridLayout -> addWidget(speedCombo, 3, 1);
    //gridLayout -> addWidget(usLabel, 3, 2);
    this -> setLayout(gridLayout);
    this->setCheckable(true);
    this->setTitle(tr("魔幻边框"));

    styleCombo->setIconSize(QSize(55,11));

    for(unsigned int i = 0; i < S_NUM(Border_Data); i ++)
     {
        QPixmap borderPixmap;
        QImage borderImage;
        borderImage = getBorderImage(0, i, QColor(Qt::red));
        borderImage = borderImage.scaled(borderImage.width()*20, borderImage.height()*40);
        borderPixmap.convertFromImage(borderImage);
        styleCombo->addItem(QIcon(borderPixmap), QString("%1").arg(Border_Data[i].Height));

    }

    modeCombo->addItem(tr("静态"));
    modeCombo->addItem(tr("闪烁"));
    modeCombo->addItem(tr("顺时钟移动"));
    modeCombo->addItem(tr("逆时钟移动"));
    modeCombo->addItem(tr("顺时钟闪烁移动"));
    modeCombo->addItem(tr("逆时钟闪烁移动"));
    modeCombo->setFixedWidth(95);

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


    connect(this, SIGNAL(clicked(bool)),this,SIGNAL(editSignal()));
    connect(styleCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(editSignal()));
    connect(colorCombo,SIGNAL(indexChangeSignal()), this, SIGNAL(editSignal()));
    connect(speedCombo,SIGNAL(currentIndexChanged(int)), this, SIGNAL(editSignal()));
    connect(modeCombo,SIGNAL(currentIndexChanged(int)), this, SIGNAL(editSignal()));
}

CborderEdit::~CborderEdit()
{

}

void CborderEdit::getSettingsFromWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("borderPara");
    settings.setValue("borderCheck", QVariant(this->isChecked()));
    //stepCombo->setText(settings.value("width").toString());
    //settings.setValue("borderStep", QVariant(stepCombo->currentIndex()));
    //speedCombo->setText(settings.value(bo).toString());
    settings.setValue("borderSpeed", QVariant(speedCombo->currentIndex()));
    //styleCombo->setCurrentIndex(settings.value( m,).toInt());
    settings.setValue("borderStyle", QVariant(styleCombo->currentIndex()));
    //modeCombo->setCurrentIndex(settings.value("borderColor").toInt());
    settings.setValue("borderColor", QVariant(colorCombo->currentIndex()));
    settings.setValue("borderMode", QVariant(modeCombo->currentIndex()));
    settings.endGroup();
    settings.endGroup();
}

void CborderEdit::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("borderPara");
    this->setChecked(settings.value("borderCheck").toBool());
    //stepCombo->setText(QString::number(settings.value("width").toInt()));
    //stepCombo->setCurrentIndex(settings.value("borderStep").toInt());

    //stepCombo->addItem(tr("2"));

    speedCombo->setCurrentIndex(settings.value("borderSpeed").toInt());


    styleCombo->setCurrentIndex(settings.value("borderStyle").toInt());
    colorCombo->setCurrentIndex(settings.value("borderColor").toInt());
    modeCombo->setCurrentIndex(settings.value("borderMode").toInt());
    settings.endGroup();
    settings.endGroup();
}

void getBorderParaFromeSettings(QString str, U_File_Para &para)
{
    settings.beginGroup(str);
    settings.beginGroup("borderPara");

    int index = settings.value("borderStyle").toInt();
    int color = settings.value("borderColor").toInt();
    bool check = settings.value("borderCheck").toBool();

    para.Pic_Para.Border_Mode = settings.value("borderMode").toInt();
    //para.Border_Speed = settings.value("borderSpeed").toInt();
    para.Pic_Para.Border_Speed = (INT8U)settings.value("borderSpeed").toInt();// + 1)*MOVE_STEP_PERIOD;

    para.Pic_Para.Border_Check = check;
    para.Pic_Para.Border_Color = color;//getColorDataFromIndex(color);
    para.Pic_Para.Border_Type = index;

    para.Pic_Para.Border_Width = getBorderWidth(index);//settings.value("")
    para.Pic_Para.Border_Height = getBorderHeight(index);
    //para.Pic_Para.Border_Width = Simple_Border_Data[index].Width;
    //para.Pic_Para.Border_Height = Simple_Border_Data[index].Height;

    settings.endGroup();
    settings.endGroup();
}


CimageSize::CimageSize(QWidget *parent):QGroupBox(parent)
{
    QLabel *widthLabel,*heighLabel;
    QLabel *widthLabel0, *heighLabel0;
    QHBoxLayout *hLayout;

    hLayout = new QHBoxLayout(this);
    widthLabel = new QLabel(tr("横向比例"),this);
    heighLabel = new QLabel(tr("纵向比例"),this);
    widthLabel0 = new QLabel("%",this);
    heighLabel0 = new QLabel("%", this);

   widthEdit = new QSpinBox(this);
   widthEdit->setMinimum(10);
   widthEdit->setMaximum(100);
   heighEdit = new QSpinBox(this);
   heighEdit->setMinimum(10);
   heighEdit->setMaximum(100);

   hLayout->addWidget(widthLabel);
   hLayout->addWidget(widthEdit);
   hLayout->addWidget(widthLabel0);

   hLayout->addWidget(heighLabel);
   hLayout->addWidget(heighEdit);
   hLayout->addWidget(heighLabel0);

   connect(widthEdit, SIGNAL(valueChanged(int)),this, SIGNAL(editSignal()));
   connect(heighEdit, SIGNAL(valueChanged(int)), this, SIGNAL(editSignal()));

   setLayout(hLayout);
   setTitle(tr("显示比例"));

}

void CimageSize::getSettingsFromWidget(QString str)
{
  settings.beginGroup(str);
  settings.beginGroup("imageProportion");
  settings.setValue("x", widthEdit->value());
  settings.setValue("y", heighEdit->value());
  settings.endGroup();
  settings.endGroup();
}

void CimageSize::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("imageProportion");
    int setFlag = settings.value("setFlag").toInt();
    if(setFlag == 0)
    {
      //名字
      settings.setValue("setFlag", 1);
      settings.setValue("x", 100);
      settings.setValue("y", 100);
    }

    widthEdit->setValue(settings.value("x").toInt());
    heighEdit->setValue(settings.value("y").toInt());
    //settings.setValue("y", heighEdit->value());
    settings.endGroup();
    settings.endGroup();
}

CimageSize::~CimageSize()
{

}
