
#include <QFileDialog>
#include <QSettings>
#include <QMovie>
#include "mainwindow.h"
#include "imageProperty.h"

extern MainWindow *w;
extern QSettings settings;

#define IMAGE_MIN_VALUE 150
#define IMAGE_MAX_VALUE 250
/*
//image属性窗
class CimageProperty:public QWidget
{
    Q_OBJECT
private:
    QLabel *imageSourceLabel; //image源标志
    QLineEdit *imageSourceEdit; //image源编辑框
    QPushButton *openButton; //打开按钮

    QLabel *frameNumLabel; //帧数标志
    QLineEdit *frameNumEdit; //帧数编辑
    QLabel *runSpeedLabel; //运行速度标志
    QLineEdit *stayTimeEdit; //运行速度编辑
    QLabel *speedUnitLabel; //速度单位

    QLabel *totalFrameNumLabel; //总帧数


public:
    CimageProperty(QWidget *parent=0);
    ~CimageProperty();
};
*/
//image属性编辑
CimageProperty::CimageProperty(QWidget *parent):QWidget(parent)
{
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;
    QGridLayout *gridLayout;
    hLayout = new QHBoxLayout(this);
    vLayout = new QVBoxLayout(this);
    //QValidator *inOutTimeValidator = new QIntValidator(0,999,this);
    //QValidator *stayTimeValidator = new QIntValidator(0,999,this);

    area = new Carea(this);
    nameEdit = new CnameEdit(this);

    vLayout->addWidget(nameEdit);
    vLayout->addWidget(area);
    hLayout->addLayout(vLayout);
    //setLayout(vLayout);

    groupBox = new QGroupBox(tr("图片信息"),this);

   imageSourceLabel = new QLabel(tr("图片文件"), this);
   imageSourceEdit = new QLineEdit(this);
   openButton = new QPushButton(tr("打开"), this);
/*
   totalFrameNumLabel = new QLabel(tr("总帧数"), this);
   totalFrameNumEdit = new QLineEdit(this);

   frameNumLabel = new QLabel(tr("提取帧数"), this);
   frameNumEdit = new QSpinBox(this);

   runSpeedLabel = new QLabel(tr("每屏停留时间"), this);
   stayTimeEdit = new QLineEdit(this);
   stayTimeEdit->setFixedWidth(40);
   stayTimeEdit->setValidator(stayTimeValidator);
   speedUnitLabel = new QLabel(tr("毫秒"), this);


   //imageSourceEdit->setEnabled(false);
   imageSourceEdit->setFocusPolicy(Qt::NoFocus);
   totalFrameNumEdit->setFocusPolicy(Qt::NoFocus);

   totalFrameNumEdit->setFixedWidth(40);
   frameNumEdit->setFixedWidth(40);

   frameNumEdit->setMinimum(1);
   */
   gridLayout = new QGridLayout(this);
   gridLayout->addWidget(imageSourceLabel, 0, 0);
   gridLayout->addWidget(imageSourceEdit, 0, 1,1,5);
   gridLayout->addWidget(openButton, 0, 6);
/*
   gridLayout->addWidget(totalFrameNumLabel, 1, 0);
   gridLayout->addWidget(totalFrameNumEdit, 1, 1);
   gridLayout->addWidget(frameNumLabel, 1, 2);
   gridLayout->addWidget(frameNumEdit, 1, 3);
   gridLayout->addWidget(runSpeedLabel, 1, 4);
   gridLayout->addWidget(stayTimeEdit, 1, 5);
   gridLayout->addWidget(speedUnitLabel, 1, 6);
*/
   groupBox->setLayout(gridLayout);

   vLayout = new QVBoxLayout(this);
   vLayout->addWidget(groupBox);

   imageSize = new CimageSize(this);
   vLayout->addWidget(imageSize);

   hLayout->addLayout(vLayout);

   showModeEdit = new CshowModeEdit(this);
   hLayout->addWidget(showModeEdit);

   borderEdit = new CborderEdit(this);
   hLayout->addWidget(borderEdit);

   hLayout->addStretch(10);
   setLayout(hLayout);

   connectSignal();

}

void CimageProperty::edited()
{/*
  QString str;
  str = w->screenArea->getCurrentFileStr();//getCurrentFileStr();
  getSettingsFromWidget(str);
  */
    CshowArea *area;
    QTreeWidgetItem *item;
    area = w->screenArea->getFocusArea(); //当前焦点分区

    if(area != (CshowArea *)0) //
    {
        //当前选中的item
        item = area->fileItem;//w->progManage->treeWidget->currentItem();////// //w->progManage->treeWidget->currentItem();
        if(item != (QTreeWidgetItem *)0)
        {
            QString str = item->data(0,Qt::UserRole).toString();
            getSettingsFromWidget(str);
            //getImageParaFromSettings(str, area->filePara);
            updateImageShowArea(area);
        }
    }
}

void CimageProperty::openImageFile()
{
    CshowArea *area;
    QTreeWidgetItem *item;

    QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件"),
                                                    "/home",
                                                    tr("Images (*.png *.bmp *.jpg *.ico)"));
    if(fileName.isEmpty() == false)
    {
        imageSourceEdit->setText(fileName);
        //QMovie *movie = new QMovie(fileName);
        //totalFrameNumEdit->setText(QString::number(movie->frameCount()));
        //frameNumEdit->setMaximum(movie->frameCount());

        area = w->screenArea->getFocusArea(); //当前焦点分区

        if(area != (CshowArea *)0) //
        {
            //当前选中的item
            item = area->fileItem;//w->progManage->treeWidget->currentItem();////// //w->progManage->treeWidget->currentItem();
            if(item != (QTreeWidgetItem *)0)
            {
                QString str = item->data(0,Qt::UserRole).toString();
                getSettingsFromWidget(str);
                //getImageParaFromSettings(str, area->filePara);
                updateImageShowArea(area);
            }
        }

  }
}

void getImageParaFromSettings(QString str, U_File_Para &para)
{
   para.Pic_Para.Flag = SHOW_IMAGE;

   getBorderParaFromeSettings(str, para);
   getShowModeParaFromSettings(str, para);
}

CimageProperty::~CimageProperty()
{

}

//刷新显示区域
void updateImageShowArea(CshowArea *area)
{
    //CshowArea *area;
    QString str;
    QTreeWidgetItem *item;

    if(area != (CshowArea *)0) //
    {
        item = area->fileItem;
        str = item->data(0,Qt::UserRole).toString();

        getImageParaFromSettings(str,area->filePara);

        settings.beginGroup(str);
        QMovie *movie = new QMovie(settings.value("fileName").toString());

        settings.beginGroup("imageProportion");
        area->xProportion = settings.value("x").toInt();
        area->yProportion = settings.value("y").toInt();
        settings.endGroup();

        settings.endGroup();
        movie->setCacheMode(QMovie::CacheAll);
        //totalFrameNumEdit->setText(QString::number(movie->frameCount()));
        if(movie->jumpToFrame(0) EQ false)
        {
            ASSERT_FAILED();
        }

        area->imageBk = movie->currentImage();
        //area->imageBk.save("d:\\image.png");
        area->updateFlag = true;
        //area->imageBk = getTextEditImage(MLINE_MODE, area->width(), area->height(), str, 0);
        getBorderData(str, area->borderData, sizeof(area->borderData));
        //qDebug("file_para flag = %d", area->File_Para.Temp_Para.Flag);
        area->update(); //刷新显示

    }
    else
    {
        ASSERT_FAILED();
    }

}

void CimageProperty::connectSignal()
{
    //connect(frameNumEdit, SIGNAL(edited()), this, SIGNAL(edited()));
    //connect(frameNumEdit, SIGNAL(valueChanged(int)), this, SLOT(edited()));
    //connect(stayTimeEdit, SIGNAL(textEdited(const QString &)),this, SLOT(edited()));
    connect(openButton, SIGNAL(clicked()), this, SLOT(openImageFile()));
    connect(borderEdit, SIGNAL(editSignal()), this, SLOT(edited()));
    connect(imageSize, SIGNAL(editSignal()), this, SLOT(edited()));
    connect(showModeEdit, SIGNAL(edited()), this, SLOT(edited()));

}

void CimageProperty::disconnectSignal()
{
    //connect(frameNumEdit, SIGNAL(edited()), this, SIGNAL(edited()));
    //disconnect(frameNumEdit, SIGNAL(valueChanged(int)), this, SLOT(edited()));
    //disconnect(stayTimeEdit, SIGNAL(textEdited(const QString &)),this, SLOT(edited()));
    disconnect(openButton, SIGNAL(clicked()), this, SLOT(openImageFile()));
    disconnect(borderEdit, SIGNAL(editSignal()), this, SLOT(edited()));
    disconnect(imageSize, SIGNAL(editSignal()), this, SLOT(edited()));
    disconnect(showModeEdit, SIGNAL(edited()), this, SLOT(edited()));
}

void CimageProperty::getSettingsFromWidget(QString str)
{
  settings.beginGroup(str);
  settings.setValue("fileName", imageSourceEdit->text());
  //settings.setValue("frameCount", frameNumEdit->value());
  //settings.setValue("stayTime", stayTimeEdit->text().toInt());
  settings.endGroup();

  nameEdit->getSettingsFromWidget(str);
  borderEdit->getSettingsFromWidget(str);
  imageSize->getSettingsFromWidget(str);
  showModeEdit->getSettingsFromWidget(str);
}

void CimageProperty::setSettingsToWidget(QString str)
{
    disconnectSignal();

    settings.beginGroup(str);
    imageSourceEdit->setText(settings.value("fileName").toString());
    //stayTimeEdit->setText(QString::number(settings.value("stayTime").toInt()));//setCurrentIndex(settings.value("speed").toInt());
    //frameNumEdit->setValue(settings.value("frameCount").toInt());
    settings.endGroup();

    if(imageSourceEdit->text().isEmpty() == false)
    {
        //QMovie *movie = new QMovie(imageSourceEdit->text());
        QMovie movie;
        movie.setFileName(imageSourceEdit->text());
        //totalFrameNumEdit->setText(QString::number(movie.frameCount()));
        //frameNumEdit->setMaximum(movie.frameCount());
    }

    nameEdit->setSettingsToWidget(str);
    borderEdit->setSettingsToWidget(str);
    imageSize->setSettingsToWidget(str);
    showModeEdit->setSettingsToWidget(str);

    connectSignal();
}

QSize getImageShowData(QImage image, S_Show_Data *pDst, INT8U Area_No, INT16U x, INT16U y)
{
    INT8U colorData=0;
    QSize size;
    QRgb rgb,r,g,b;//ye;
    int h,s,v,a;
    int i,j;

    //image.save("d:\\image.png");
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
          else if(h >= 90 && h< 180)// && r < IMAGE_VALUE && b <IMAGE_VALUE)
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

void getImagePageShowData(QString str, INT8U page, S_Show_Data *pDst, INT8U Area_No, INT16U x, INT16U y, INT16U width, INT16U height)
{
    QMovie movie;
    int x0,y0;

    settings.beginGroup(str);
    movie.setFileName(settings.value("fileName").toString());
    settings.beginGroup("imageProportion");
    x0 = settings.value("x").toInt();
    y0 = settings.value("y").toInt();
    settings.endGroup();
    settings.endGroup();
    movie.setCacheMode(QMovie::CacheAll);
    //totalFrameNumEdit->setText(QString::number(movie->frameCount()));
    movie.jumpToFrame(0);

    QImage image = movie.currentImage().scaled(width*x0/100,height*y0/100);
    getImageShowData(image, pDst,Area_No, x + (width - image.width()) / 2, y + (height - image.height())/ 2);
}

int getImageFrameCount(QString str)
{
    settings.beginGroup(str);
    QMovie *movie = new QMovie(settings.value("fileName").toString());
    settings.endGroup();
    //totalFrameNumEdit->setText(QString::number(movie->frameCount()));
    return movie->frameCount();
}
