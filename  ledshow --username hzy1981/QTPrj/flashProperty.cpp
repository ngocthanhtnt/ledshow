#include <QFileDialog>
#include <QSettings>
#include <QMovie>
#include "mainwindow.h"
#include "flashProperty.h"

extern MainWindow *w;
extern QSettings settings;

#define FLASH_MIN_VALUE 150
#define FLASH_MAX_VALUE 250
/*
//flash属性窗
class CflashProperty:public QWidget
{
    Q_OBJECT
private:
    QLabel *flashSourceLabel; //flash源标志
    QLineEdit *flashSourceEdit; //flash源编辑框
    QPushButton *openButton; //打开按钮

    QLabel *frameNumLabel; //帧数标志
    QLineEdit *frameNumEdit; //帧数编辑
    QLabel *runSpeedLabel; //运行速度标志
    QLineEdit *stayTimeEdit; //运行速度编辑
    QLabel *speedUnitLabel; //速度单位

    QLabel *totalFrameNumLabel; //总帧数


public:
    CflashProperty(QWidget *parent=0);
    ~CflashProperty();
};
*/
//flash属性编辑
CflashProperty::CflashProperty(QWidget *parent):QWidget(parent)
{
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;
    QGridLayout *gridLayout;
    hLayout = new QHBoxLayout(this);
    vLayout = new QVBoxLayout(this);
    //QValidator *inOutTimeValidator = new QIntValidator(0,999,this);
    QValidator *stayTimeValidator = new QIntValidator(0,999,this);

    area = new Carea(this);
    nameEdit = new CnameEdit(this);

    vLayout->addWidget(nameEdit);
    vLayout->addWidget(area);
    hLayout->addLayout(vLayout);
    //setLayout(vLayout);

    groupBox = new QGroupBox(tr("动画信息"),this);

   flashSourceLabel = new QLabel(tr("动画文件"), this);
   flashSourceEdit = new QLineEdit(this);
   openButton = new QPushButton(tr("打开"), this);

   totalFrameNumLabel = new QLabel(tr("总帧数"), this);
   totalFrameNumEdit = new QLineEdit(this);

   frameNumLabel = new QLabel(tr("提取帧数"), this);
   frameNumEdit = new QSpinBox(this);

   runSpeedLabel = new QLabel(tr("每屏停留时间"), this);
   stayTimeEdit = new QLineEdit(this);
   stayTimeEdit->setFixedWidth(40);
   stayTimeEdit->setValidator(stayTimeValidator);
   speedUnitLabel = new QLabel(tr("毫秒"), this);
/*
   stayTimeEdit->addItem(tr("0最快"));
   stayTimeEdit->addItem(tr("1"));
   stayTimeEdit->addItem(tr("2"));
   stayTimeEdit->addItem(tr("3"));
   stayTimeEdit->addItem(tr("4"));
   stayTimeEdit->addItem(tr("5"));
   stayTimeEdit->addItem(tr("6"));
   stayTimeEdit->addItem(tr("7"));
   stayTimeEdit->addItem(tr("8"));
   stayTimeEdit->addItem(tr("9最慢"));
*/

   //flashSourceEdit->setEnabled(false);
   flashSourceEdit->setFocusPolicy(Qt::NoFocus);
   totalFrameNumEdit->setFocusPolicy(Qt::NoFocus);

   totalFrameNumEdit->setFixedWidth(40);
   frameNumEdit->setFixedWidth(40);

   frameNumEdit->setMinimum(1);

   gridLayout = new QGridLayout(this);
   gridLayout->addWidget(flashSourceLabel, 0, 0);
   gridLayout->addWidget(flashSourceEdit, 0, 1,1,5);
   gridLayout->addWidget(openButton, 0, 6);

   gridLayout->addWidget(totalFrameNumLabel, 1, 0);
   gridLayout->addWidget(totalFrameNumEdit, 1, 1);
   gridLayout->addWidget(frameNumLabel, 1, 2);
   gridLayout->addWidget(frameNumEdit, 1, 3);
   gridLayout->addWidget(runSpeedLabel, 1, 4);
   gridLayout->addWidget(stayTimeEdit, 1, 5);
   gridLayout->addWidget(speedUnitLabel, 1, 6);
   groupBox->setLayout(gridLayout);

   vLayout = new QVBoxLayout(this);
   vLayout->addWidget(groupBox);
   hLayout->addLayout(vLayout);

   hLayout->addStretch(10);
   setLayout(hLayout);

   connectSignal();

}

void CflashProperty::edited()
{
  QString str;
  str = w->screenArea->getCurrentFileStr();//getCurrentFileStr();
  getSettingsFromWidget(str);
}

void CflashProperty::openFlashFile()
{
    CshowArea *area;
    QTreeWidgetItem *item;

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Images (*.png *.xpm *.jpg *.gif)"));
    if(fileName.isEmpty() == false)
    {
        flashSourceEdit->setText(fileName);
        QMovie *movie = new QMovie(fileName);
        totalFrameNumEdit->setText(QString::number(movie->frameCount()));
        frameNumEdit->setMaximum(movie->frameCount());

        area = w->screenArea->getFocusArea(); //当前焦点分区

        if(area != (CshowArea *)0) //
        {
            //当前选中的item
            item = area->fileItem;//w->progManage->treeWidget->currentItem();////// //w->progManage->treeWidget->currentItem();
            if(item != (QTreeWidgetItem *)0)
            {
                QString str = item->data(0,Qt::UserRole).toString();
                getSettingsFromWidget(str);
                //getFlashParaFromSettings(str, area->filePara);
                updateFlashShowArea(area);
            }
        }

  }
}

void getFlashParaFromSettings(QString str, U_File_Para &para)
{
   para.Pic_Para.Flag = SHOW_FLASH;
   para.Pic_Para.In_Mode = 1;//(INT8U)settings.value("inMode").toInt();
   para.Pic_Para.In_Time = 1;//(INT16U)settings.value("inTime").toInt();
   para.Pic_Para.In_Time |= 0x8000; //停留时间单位为ms，因此最高位置1
   para.Pic_Para.Out_Mode = 1;//(INT8U)settings.value("outMode").toInt();
   para.Pic_Para.Out_Time = 1;//(INT16U)settings.value("outTime").toInt();
   para.Pic_Para.Out_Time |= 0x8000; //停留时间单位为ms，因此最高位置1

   settings.beginGroup(str);
   para.Pic_Para.SNum = (INT16U)settings.value("frameCount").toInt();
   para.Pic_Para.Stay_Time = (INT16U)settings.value("stayTime").toInt();
   para.Pic_Para.Stay_Time |= 0x8000;
   settings.endGroup();

}

CflashProperty::~CflashProperty()
{

}

//刷新显示区域
void updateFlashShowArea(CshowArea *area)
{
    //CshowArea *area;
    QString str;
    QTreeWidgetItem *item;

    if(area != (CshowArea *)0) //
    {
        item = area->fileItem;
        str = item->data(0,Qt::UserRole).toString();

        getFlashParaFromSettings(str,area->filePara);

        settings.beginGroup(str);
        QMovie *movie = new QMovie(settings.value("fileName").toString());
        settings.endGroup();
        movie->setCacheMode(QMovie::CacheAll);
        //totalFrameNumEdit->setText(QString::number(movie->frameCount()));
        if(movie->jumpToFrame(0) EQ false)
        {
            ASSERT_FAILED();
        }

        area->imageBk = movie->currentImage();
        //area->imageBk.save("d:\\flash.png");
        area->updateFlag = true;
        //area->imageBk = getTextEditImage(MLINE_MODE, area->width(), area->height(), str, 0);

        //qDebug("file_para flag = %d", area->File_Para.Temp_Para.Flag);
        area->update(); //刷新显示

    }
    else
    {
        ASSERT_FAILED();
    }

}

void CflashProperty::connectSignal()
{
    //connect(frameNumEdit, SIGNAL(edited()), this, SIGNAL(edited()));
    connect(frameNumEdit, SIGNAL(valueChanged(int)), this, SLOT(edited()));
    connect(stayTimeEdit, SIGNAL(textEdited(const QString &)),this, SLOT(edited()));
    connect(openButton, SIGNAL(clicked()), this, SLOT(openFlashFile()));

}

void CflashProperty::disconnectSignal()
{
    //connect(frameNumEdit, SIGNAL(edited()), this, SIGNAL(edited()));
    disconnect(frameNumEdit, SIGNAL(valueChanged(int)), this, SLOT(edited()));
    disconnect(stayTimeEdit, SIGNAL(textEdited(const QString &)),this, SLOT(edited()));
    disconnect(openButton, SIGNAL(clicked()), this, SLOT(openFlashFile()));

}

void CflashProperty::getSettingsFromWidget(QString str)
{
  settings.beginGroup(str);
  settings.setValue("fileName", flashSourceEdit->text());
  settings.setValue("frameCount", frameNumEdit->value());
  settings.setValue("stayTime", stayTimeEdit->text().toInt());
  settings.endGroup();

  nameEdit->getSettingsFromWidget(str);
}

void CflashProperty::setSettingsToWidget(QString str)
{
    disconnectSignal();

    settings.beginGroup(str);
    flashSourceEdit->setText(settings.value("fileName").toString());
    stayTimeEdit->setText(QString::number(settings.value("stayTime").toInt()));//setCurrentIndex(settings.value("speed").toInt());
    frameNumEdit->setValue(settings.value("frameCount").toInt());
    settings.endGroup();

    if(flashSourceEdit->text().isEmpty() == false)
    {
        //QMovie *movie = new QMovie(flashSourceEdit->text());
        QMovie movie;
        movie.setFileName(flashSourceEdit->text());
        totalFrameNumEdit->setText(QString::number(movie.frameCount()));
        frameNumEdit->setMaximum(movie.frameCount());
    }

    nameEdit->setSettingsToWidget(str);

    connectSignal();
}

QSize getFlashShowData(QImage image, S_Show_Data *pDst, INT8U Area_No, INT16U x, INT16U y)
{
    INT8U colorData=0;
    QSize size;
    QRgb rgb,r,g,b,ye;
    int h,s,v,a;
    int i,j;

    //image.save("d:\\flash.png");
    for(i = 0; i < image.width(); i ++)
        for(j = 0; j < image.height(); j ++)
        {
          rgb = image.pixel(i,j);
          r = qRed(rgb);
          g = qGreen(rgb);
          b = qBlue(rgb);
          QColor color(r,g,b);

          color.getHsv(&h,&s,&v,&a);
        //  qDebug("%d,%d, h = %d, s = %d, v = %d, ",i,j,h,s,v);
          if(v < 80 || s < 20)
            colorData = 0;
          //ye = QColor(rgb).yellow();
          else if(h >=300 || h < 30)
          {
              colorData = getColorData(QColor(Qt::red));
              //Set_Area_Point_Data(pDst, 0, x + i, y + j, colorData);
              //qDebug("yellow");
          }
          else if(h > 30 && h < 90)
          {
              colorData = getColorData(QColor(Qt::yellow));
              //Set_Area_Point_Data(pDst, 0, x + i, y + j, 0x01);
              //qDebug("red");
          }
          else if(h >= 90 && h< 180)// && r < FLASH_VALUE && b <FLASH_VALUE)
          {
              colorData = getColorData(QColor(Qt::green));
              //Set_Area_Point_Data(pDst, 0, x + i, y + j, 0x02);
              //qDebug("green");
          }
          else //if((r == 0 && g == 0 && b == 0) || rgb == 0xFF7F9DB9)
          {
              //Set_Area_Point_Data(pDst, 0, x + i, y + j, 0x00);
              //qDebug("black");
          }
          Set_Area_Point_Data(pDst, Area_No, x + i, y + j, colorData);
        }
    size.setWidth(image.width());
    size.setHeight(image.height());
    return size;
}

void getFlashPageShowData(QString str, INT8U page, S_Show_Data *pDst, INT8U Area_No, INT16U x, INT16U y, INT16U width, INT16U height)
{
    QMovie movie;

    settings.beginGroup(str);
    movie.setFileName(settings.value("fileName").toString());
    settings.endGroup();
    movie.setCacheMode(QMovie::CacheAll);
    //totalFrameNumEdit->setText(QString::number(movie->frameCount()));
    movie.jumpToFrame(page);

    QImage image = movie.currentImage().scaled(width,height);
    getFlashShowData(image, pDst,Area_No, x, y);
}

int getFlashFrameCount(QString str)
{
    settings.beginGroup(str);
    QMovie *movie = new QMovie(settings.value("fileName").toString());
    settings.endGroup();
    //totalFrameNumEdit->setText(QString::number(movie->frameCount()));
    return movie->frameCount();
}
