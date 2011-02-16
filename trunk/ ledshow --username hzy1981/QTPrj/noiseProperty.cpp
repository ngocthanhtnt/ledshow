#include <QHBoxLayout>
#include <QSettings>
#include "noiseProperty.h"
#include "simpleTextEdit.h"
#include "showArea.h"
#include "mainwindow.h"


extern MainWindow *w;

extern QSettings settings;
Cnoise::Cnoise(QWidget *parent):QGroupBox(parent)
{
    QHBoxLayout *hLayout;
    QLabel *label;

    noiseCombo = new QComboBox(this);
    colorCombo = new CcolorCombo(this);
    sizeCombo = new CsizeCombo(this);
    label = new QLabel(tr("格式"),this);
    /*
    {"噪音 %2d.%d℃", 11},
    {"噪音 %2d℃", 9},
    {" %2d.%d℃", 7},
    {" %2d℃",5}
    */
    //noiseCombo->addItem(tr("噪音 25.0℃"));
    noiseCombo->addItem(tr("噪音 60dB"));
    //noiseCombo->addItem(tr("噪音60dB"));
    noiseCombo->addItem(tr("60dB"));
    //noiseCombo->addItem(tr("60dB"));

    hLayout = new QHBoxLayout(this);
    hLayout ->addWidget(label);
    hLayout->addWidget(noiseCombo);

    hLayout->addWidget(sizeCombo);
    hLayout->addWidget(colorCombo);

    setLayout(hLayout);
    setTitle(tr("噪音属性"));

    connect(noiseCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(colorCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(sizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
}

void Cnoise::screenCardParaChangeProc()
{
  colorCombo->setItems();
  sizeCombo->setItems();
}

void Cnoise::getSettingsFromWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("noiseStyle");
    settings.setValue("noiseCombo", noiseCombo->currentIndex());
    settings.setValue("color", colorCombo->currentIndex());
    settings.setValue("size", sizeCombo->currentIndex());
    settings.endGroup();
    settings.endGroup();

    //colorCombo->getSettingsFromWidget(str);
    //sizeCombo->getSettingsFromWidget(str);

}

void Cnoise::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("noiseStyle");
    //settings.setValue("noiseCombo", noiseCombo->currentIndex());
    noiseCombo->setCurrentIndex(settings.value("noiseCombo").toInt());
    colorCombo->setCurrentIndex(settings.value("color").toInt());
    sizeCombo->setCurrentIndex(settings.value("size").toInt());
    settings.endGroup();
    settings.endGroup();

    //colorCombo->setSettingsTomWidget(str);
    //sizeCombo->setSettingsToWidget(str);
}


Cnoise::~Cnoise()
{

}
//正反计时编辑
CnoiseProperty::CnoiseProperty(QWidget *parent):QWidget(parent)
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
    simpleTextEdit = new CsimpleTextEdit(this);
    noiseStyle = new Cnoise(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(noiseStyle,1);
    vLayout->addWidget(simpleTextEdit,3);

    hLayout->addLayout(vLayout);

    showModeEdit = new CshowModeEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(showModeEdit);

    hLayout->addLayout(vLayout);
    hLayout->addStretch(10);
    setLayout(hLayout);

    connectSignal();

}

CnoiseProperty::~CnoiseProperty()
{

}

//从settings中获取参数
void getNoiseParaFromSettings(QString str, U_File_Para &para)
{
    int tmp;

    para.Noise_Para.Flag = SHOW_NOISE;
    settings.beginGroup(str);
    settings.beginGroup("noiseStyle");

    para.Noise_Para.Noise_Type = settings.value("noiseCombo").toInt();
    tmp = settings.value("color").toInt();
    para.Noise_Para.Noise_Color = getColorDataFromIndex(tmp);
    //SET_BIT(para.Noise_Para.Noise_Color, tmp);
    para.Noise_Para.Noise_Font = settings.value("size").toInt();

    settings.endGroup();
    settings.endGroup();

    getShowModeParaFromSettings(str, para);

}
//刷新显示区域
void updateNoiseShowArea(CshowArea *area)
{
    //CshowArea *area;
    QString str;
    QTreeWidgetItem *item;

    if(area != (CshowArea *)0) //
    {
        item = area->fileItem;

        str = item->data(0,Qt::UserRole).toString();

        getNoiseParaFromSettings(str,area->filePara);
        area->imageBk = getLineTextImage(str);
        area->updateFlag = true;
        //qDebug("file_para flag = %d", area->filePara.Noise_Para.Flag);
        area->update(); //刷新显示

    }
    else
    {
        ASSERT_FAILED();
    }

}


//属性编辑的SLOT
void CnoiseProperty::edited()
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
            updateNoiseShowArea(area);
        }
    }
}

void CnoiseProperty::connectSignal()
{
    //connect(timeDiffEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(noiseStyle, SIGNAL(edited()), this, SLOT(edited()));
    connect(showModeEdit, SIGNAL(edited()), this, SLOT(edited()));
    //connect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));
}

void CnoiseProperty::disconnectSignal()
{
    //connect(timeDiffEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(noiseStyle, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(showModeEdit, SIGNAL(edited()), this, SLOT(edited()));
    //connect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));
}

void CnoiseProperty::getSettingsFromWidget(QString str)
{
  simpleTextEdit->getSettingsFromWidget(str);
  noiseStyle->getSettingsFromWidget(str);
  nameEdit->getSettingsFromWidget(str);
  showModeEdit->getSettingsFromWidget(str);

}

void CnoiseProperty::setSettingsToWidget(QString str)
{
    disconnectSignal();
    simpleTextEdit->setSettingsToWidget(str);
    noiseStyle->setSettingsToWidget(str);
    nameEdit->setSettingsToWidget(str);
    showModeEdit->setSettingsToWidget(str);
    connectSignal();
}

void Get_Noise_Text_Point(INT8U Area_No, INT16U Width, INT16U Height, S_Point &P0)
{
    INT16U Min_Width,Min_Height;

    Min_Width = Get_Noise_Min_Width(Area_No);
    //Min_Height = Get_Noise_Min_Height(Area_No);

    if(Width > Min_Width)
      P0.X = (Width - Min_Width) / 2;
    else
      P0.X = 0;

    if(Height > Prog_Status.File_Para[Area_No].Noise_Para.Text_Height)
      P0.Y = (Height - Prog_Status.File_Para[Area_No].Noise_Para.Text_Height)/2;
    else
      P0.Y = 0;

}

