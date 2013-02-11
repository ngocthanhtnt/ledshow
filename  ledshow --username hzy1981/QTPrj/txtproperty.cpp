#include <QApplication>
#include "txtproperty.h"
#include <QGridLayout>
#include <QFontDatabase>
#include <QComboBox>
#include <QFontMetrics>
#include <QPainter>
#include <QSize>
#include <QRectF>
#include <QTextEdit>
#include <QGroupBox>
#include <QSettings>
#include "mainwindow.h"
//----------
//------------------------
extern MainWindow *w;
extern QSettings settings;
//简单文本编辑框
CsimpleTextEdit1::CsimpleTextEdit1(QWidget *parent):QGroupBox(parent)
{
  QHBoxLayout *hLayout;
  QVBoxLayout *vLayout;
  //QVBoxLayout *vLayout;
  QGridLayout *gridLayout, *mainLayout;
  QFontDatabase db;


  vLayout = new QVBoxLayout(this);
  gridLayout = new QGridLayout(this);
  mainLayout = new QGridLayout(this);

  fontLabel = new QLabel(tr("字体"), this);
  //fontSizeLabel = new QLabel(tr("大小"), this);
  colorLabel = new QLabel(tr("颜色"), this);
/*
  fontCombo = new QFontComboBox(this);
  fontCombo->setFixedWidth(100);
*/
  fontSizeCombo = new QComboBox(this);
  //fontSizeCombo->setobjectName("comboSize");
  fontSizeCombo->addItem("16");
  fontSizeCombo->addItem("24");
  fontSizeCombo->addItem("32");
  //fontSizeCombo->setEditable(true);


  colorCombo = new CcolorCombo(this);

  QLabel *pageLabel = new QLabel(tr("第"),this);
  pageBox = new QSpinBox(this);
  pageBox->setMinimum(1);
  muLabel = new QLabel(tr("幕"),this);
//-------------

  //QLabel *textLabel = new QLabel(tr("文字"), this);
  chrNumLabel = new QLabel(tr("字符数(0/") + QString::number(MAX_CHR_NUM) + QString(")"),this);


  txtEdit = new QTextEdit(this);
  txtEdit->setFixedWidth(400);
  txtEdit->setFixedHeight(100);
  //txtEdit->setfon;

  hLayout = new QHBoxLayout(this);
  hLayout -> addWidget(fontLabel);
  //hLayout -> addWidget(fontCombo);
  //hLayout -> addWidget(fontSizeLabel);
  hLayout -> addWidget(fontSizeCombo);
  hLayout -> addWidget(colorLabel);
  hLayout -> addWidget(colorCombo);


  hLayout -> addWidget(pageLabel);
  hLayout ->addWidget(pageBox);
  hLayout->addWidget(muLabel);

  hLayout->addWidget(chrNumLabel);
  hLayout ->addStretch();
  vLayout->addLayout(hLayout);
  //gridLayout->addLayout(hLayout, 0, 0);

  hLayout = new QHBoxLayout(this);
  //hLayout -> addWidget(textLabel);
  hLayout -> addWidget(txtEdit);

  //hLayout->addStretch(10);
  //gridLayout->addLayout(hLayout, 1, 0);
  vLayout->addLayout(hLayout);
  //hLayout = new QHBoxLayout(this);
  //hLayout -> addWidget(textLabel);
  //hLayout -> addWidget(txtEdit);
  //hLayout->addStretch();
  //hLayout -> addWidget(oButton);
  //gridLayout->addLayout(hLayout, 2, 0);

  //txtEdit->setSizePolicy();
  /*
  hLayout = new QHBoxLayout(this);

  hLayout -> addWidget(txtEdit);
  hLayout->addStretch();
  gridLayout->addLayout(hLayout, 2, 0);
*/
  //textGroup = new QGroupBox(tr("固定文本"), this);
  //textGroup -> setLayout(gridLayout);
  //mainLayout->addWidget(textGroup, 0, 0);
  setTitle(tr("编辑内容"));
  setLayout(vLayout);

  //this->setCheckable(true);

  //所有的消息统一到一个消息
  //connect(fontCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
  connect(fontSizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
  connect(colorCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));

  //connect(this, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
  connect(txtEdit, SIGNAL(textChanged()),this,SIGNAL(edited()));
  connect(pageBox, SIGNAL(valueChanged(int)),this, SIGNAL(edited()));
  connect(txtEdit, SIGNAL(textChanged()),this, SLOT(calcChrNum()));
}


//计算字符串个数
void CsimpleTextEdit1::calcChrNum()
{
  int num;
  QString txt;

  num = this->txtEdit->toPlainText().toLocal8Bit().size();
  txt = tr("字符数(") + QString::number(num) + QString("/") + QString::number(MAX_CHR_NUM) + QString(")");

  if(num > MAX_CHR_NUM)
  {
    txt = txt + QString(tr("超,超过部分将不能显示!"));
    chrNumLabel->setStyleSheet("color:red");
  }
  else
    chrNumLabel->setStyleSheet("color:black");

  chrNumLabel->setText(txt);
}

//从Widget上获取设置
void CsimpleTextEdit1::getSettingsFromWidget(QString str)
{
   settings.beginGroup(str);
   settings.beginGroup("simpleTextEdit1");
   //settings.setValue("fontIndex", fontCombo->currentIndex());
   settings.setValue("fontSizeIndex", fontSizeCombo->currentIndex());
   //settings.setValue("fontName", fontCombo->currentText());
   //settings.setValue("fontSize", fontSizeCombo->currentText().toInt());
   settings.setValue("page", pageBox->value());
   settings.setValue("color", colorCombo->currentIndex());
   settings.setValue("text", txtEdit->toPlainText());
   settings.endGroup();
   settings.endGroup();
}

void CsimpleTextEdit1::setSettingsToWidget(QString str)
{
    //disconnect(fontCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    disconnect(fontSizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    disconnect(colorCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
    //disconnect(this, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    disconnect(txtEdit, SIGNAL(textEdited(const QString &)),this,SIGNAL(edited()));

    settings.beginGroup(str);
    settings.beginGroup("simpleTextEdit1");
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag EQ 0)
    {
       //settings.setValue("fontIndex", 0);
       settings.setValue("fontSizeIndex", 0);
       settings.setValue("color", 0);
       settings.setValue("text", QString(""));
       settings.setValue("page", 1);
       settings.setValue("setFlag", 1);
    }

    //fontCombo->setCurrentIndex(settings.value("fontIndex").toInt());
    fontSizeCombo->setCurrentIndex(settings.value("fontSizeIndex").toInt());
    pageBox->setValue(settings.value("page").toInt());
    colorCombo->setCurrentIndex(settings.value("color").toInt());

    //this->setChecked(settings.value("editCheck").toBool());
    txtEdit->setPlainText(settings.value("text").toString());
    settings.endGroup();
    settings.endGroup();

    //connect(fontCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(fontSizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(colorCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));

    //connect(this, SIGNAL(clicked(bool)),this,SIGNAL(edited()));
    connect(txtEdit, SIGNAL(textEdited(const QString &)),this,SIGNAL(edited()));

}

void CsimpleTextEdit1::screenCardParaChangeProc()
{
    colorCombo->setItems();
}

CsimpleTextEdit1::~CsimpleTextEdit1()
{

}

//正反计时编辑
CtxtProperty::CtxtProperty(QWidget *parent):QWidget(parent)
{
    //QGridLayout *gridLayout,*mainLayout;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;

    hLayout = new QHBoxLayout(this);
    vLayout = new QVBoxLayout(this);

    nameEdit = new CnameEdit(this);
    area = new Carea(this);
    vLayout->addWidget(nameEdit);
    vLayout->addWidget(area);
    hLayout->addLayout(vLayout);
    //textGroup = new QGroupBox(tr("固定文本"), this);
    simpleTextEdit = new CsimpleTextEdit1(this);
    //tempStyle = new Ctemp(this);
    vLayout = new QVBoxLayout(this);
    //vLayout->addWidget(tempStyle,1);
    vLayout->addWidget(simpleTextEdit,3);

    hLayout->addLayout(vLayout);

    showModeEdit = new CshowModeEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(showModeEdit);

    hLayout->addLayout(vLayout);

    borderEdit = new CborderEdit(this);
    hLayout->addWidget(borderEdit);
    hLayout->addStretch(10);
    setLayout(hLayout);

    connectSignal();

}

CtxtProperty::~CtxtProperty()
{

}

//从settings中获取参数
void getTxtParaFromSettings(QString str, U_File_Para &para)
{
    //int tmp;
    getBorderParaFromeSettings(str, para);
    para.Txt_Para.Flag = SHOW_TXT;

    settings.beginGroup(str);
    settings.beginGroup("simpleTextEdit1");

    para.Txt_Para.Font_Size = (INT8U)settings.value("fontSizeIndex").toInt();
    INT8U Color = (INT8U)settings.value("color").toInt();
    para.Txt_Para.Color = getColorDataFromIndex(Color);
    para.Txt_Para.Len = (INT8U)settings.value("text").toString().length();//长度
    para.Txt_Para.SNum = 1; //下位机第一次读取数据时会计算

    settings.endGroup();
    settings.endGroup();
    /*
    settings.beginGroup(str);
    settings.beginGroup("tempStyle");

    para.Temp_Para.Temp_Type = settings.value("tempCombo").toInt();
    tmp = settings.value("color").toInt();
    para.Temp_Para.Temp_Color = getColorDataFromIndex(tmp);
    //SET_BIT(para.Temp_Para.Temp_Color, tmp);
    para.Temp_Para.Temp_Font = settings.value("size").toInt();

    settings.endGroup();
    settings.endGroup();
    */
    getShowModeParaFromSettings(str, para);

}
//刷新显示区域
void updateTxtShowArea(CshowArea *area)
{
    //CshowArea *area;
    QString str;
    QTreeWidgetItem *item;

    if(area != (CshowArea *)0) //
    {
        item = area->fileItem;

        str = item->data(0,Qt::UserRole).toString();

        getTxtParaFromSettings(str,area->filePara);
        getTxtData(str, area->txtData, sizeof(area->txtData));

        settings.beginGroup(str);
        settings.beginGroup("simpleTextEdit1");

        area->page = settings.value("page").toInt();
        area->page = area->page > 0? (area->page - 1):0;
        settings.endGroup();
        settings.endGroup();

        area->updateFlag = true;

        //qDebug("file_para flag = %d", area->filePara.Temp_Para.Flag);
        getBorderData(str, area->borderData, sizeof(area->borderData));
        area->update(); //刷新显示

    }
    else
    {
        ASSERT_FAILED();
    }

}

//属性编辑的SLOT
void CtxtProperty::edited()
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
            updateTxtShowArea(area);

            this->simpleTextEdit->pageBox->setMaximum(Prog_Status.File_Para[0].Txt_Para.SNum == 0 ? 1:Prog_Status.File_Para[0].Txt_Para.SNum);
            this->simpleTextEdit->muLabel->setText(QString("/") + QString::number(this->simpleTextEdit->pageBox->maximum()) + tr("幕"));
        }
    }
}

void CtxtProperty::connectSignal()
{
    //connect(timeDiffEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    //connect(tempStyle, SIGNAL(edited()), this, SLOT(edited()));
    connect(showModeEdit, SIGNAL(edited()), this, SLOT(edited()));
    //connect(smtxtEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(borderEdit, SIGNAL(editSignal()), this, SLOT(edited()));
}

void CtxtProperty::disconnectSignal()
{
    //connect(timeDiffEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    //disconnect(tempStyle, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(showModeEdit, SIGNAL(edited()), this, SLOT(edited()));
    //connect(smtxtEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(borderEdit, SIGNAL(editSignal()), this, SLOT(edited()));
}

void CtxtProperty::getSettingsFromWidget(QString str)
{
  simpleTextEdit->getSettingsFromWidget(str);
  //tempStyle->getSettingsFromWidget(str);
  nameEdit->getSettingsFromWidget(str);
  showModeEdit->getSettingsFromWidget(str);
  borderEdit->getSettingsFromWidget(str);

}

void CtxtProperty::setSettingsToWidget(QString str)
{
    disconnectSignal();
    simpleTextEdit->setSettingsToWidget(str);
    //tempStyle->setSettingsToWidget(str);
    nameEdit->setSettingsToWidget(str);
    showModeEdit->setSettingsToWidget(str);
    borderEdit->setSettingsToWidget(str);
    connectSignal();
}

void CtxtProperty::screenCardParaChangeProc()
{

}

INT16U getTxtData(QString str, INT8U *pDst, INT32U dstLen)
{
    INT16U len;
    QByteArray byteArray;

    settings.beginGroup(str);
    settings.beginGroup("simpleTextEdit1");

    byteArray = settings.value("text").toString().toLocal8Bit();
    len = byteArray.size();
    if(len >= dstLen)
    {
        ASSERT_FAILED();
        len = dstLen - 1;
    }

    if(len > MAX_CHR_NUM)
    {
        ASSERT_FAILED();
        len = MAX_CHR_NUM;

    }

    memcpy(pDst, byteArray.data(), len);
    pDst[len] = 0;
    //para.Txt_Para.Font_Size = (INT8U)settings.value("fontSizeIndex").toInt();
    //para.Txt_Para.Color = (INT8U)settings.value("color").toInt();
    //para.Txt_Para.Len = (INT8U)settings.value("text").toString().length();//长度

    settings.endGroup();
    settings.endGroup();

    return len + 1;
}
