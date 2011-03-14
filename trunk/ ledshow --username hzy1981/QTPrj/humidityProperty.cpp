#include <QHBoxLayout>
#include <QSettings>
#include "humidityProperty.h"
#include "simpleTextEdit.h"
#include "showArea.h"
#include "mainwindow.h"


extern MainWindow *w;

extern QSettings settings;
Chumidity::Chumidity(QWidget *parent):QGroupBox(parent)
{
    QHBoxLayout *hLayout;
    QLabel *label;

    humidityCombo = new QComboBox(this);
    colorCombo = new CcolorCombo(this);
    sizeCombo = new CsizeCombo(this);
    label = new QLabel(tr("格式"),this);
    /*
    {"湿度 %2d.%d℃", 11},
    {"湿度 %2d℃", 9},
    {" %2d.%d℃", 7},
    {" %2d℃",5}
    */
    humidityCombo->addItem(tr("湿度 25%RH"));
    //humidityCombo->addItem(tr("湿度25%RH"));
    humidityCombo->addItem(tr("25%RH"));

    hLayout = new QHBoxLayout(this);
    hLayout ->addWidget(label);
    hLayout->addWidget(humidityCombo);

    hLayout->addWidget(sizeCombo);
    hLayout->addWidget(colorCombo);

    setLayout(hLayout);
    setTitle(tr("湿度属性"));

    connect(humidityCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(colorCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
    connect(sizeCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
}

void Chumidity::screenCardParaChangeProc()
{
  colorCombo->setItems();
  sizeCombo->setItems();
}

void Chumidity::getSettingsFromWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("humidityStyle");
    settings.setValue("humidityCombo", humidityCombo->currentIndex());
    settings.setValue("color", colorCombo->currentIndex());
    settings.setValue("size", sizeCombo->currentIndex());
    settings.endGroup();
    settings.endGroup();

    //colorCombo->getSettingsFromWidget(str);
    //sizeCombo->getSettingsFromWidget(str);

}

void Chumidity::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("humidityStyle");
    //settings.setValue("humidityCombo", humidityCombo->currentIndex());
    humidityCombo->setCurrentIndex(settings.value("humidityCombo").toInt());
    colorCombo->setCurrentIndex(settings.value("color").toInt());
    sizeCombo->setCurrentIndex(settings.value("size").toInt());
    settings.endGroup();
    settings.endGroup();

    //colorCombo->setSettingsTomWidget(str);
    //sizeCombo->setSettingsToWidget(str);
}


Chumidity::~Chumidity()
{

}
//正反计时编辑
ChumidityProperty::ChumidityProperty(QWidget *parent):QWidget(parent)
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
    humidityStyle = new Chumidity(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(humidityStyle,1);
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

ChumidityProperty::~ChumidityProperty()
{

}

//从settings中获取参数
void getHumidityParaFromSettings(QString str, U_File_Para &para)
{
    int tmp;

    para.Humidity_Para.Flag = SHOW_HUMIDITY;
    settings.beginGroup(str);
    settings.beginGroup("humidityStyle");

    para.Humidity_Para.Humidity_Type = settings.value("humidityCombo").toInt();
    tmp = settings.value("color").toInt();
    para.Humidity_Para.Humidity_Color = getColorDataFromIndex(tmp);
    //SET_BIT(para.Humidity_Para.Humidity_Color, tmp);
    para.Humidity_Para.Humidity_Font = settings.value("size").toInt();

    settings.endGroup();
    settings.endGroup();

    getShowModeParaFromSettings(str, para);

}
//刷新显示区域
void updateHumidityShowArea(CshowArea *area)
{
    //CshowArea *area;
    QString str;
    QTreeWidgetItem *item;

    if(area != (CshowArea *)0) //
    {
        item = area->fileItem;

        str = item->data(0,Qt::UserRole).toString();

        getHumidityParaFromSettings(str,area->filePara);
        area->imageBk = getLineTextImage(str);
        area->updateFlag = true;
        //qDebug("file_para flag = %d", area->filePara.Humidity_Para.Flag);
        area->update(); //刷新显示

    }
    else
    {
        ASSERT_FAILED();
    }

}


//属性编辑的SLOT
void ChumidityProperty::edited()
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
            updateHumidityShowArea(area);
        }
    }
}

void ChumidityProperty::connectSignal()
{
    //connect(timeDiffEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(humidityStyle, SIGNAL(edited()), this, SLOT(edited()));
    connect(showModeEdit, SIGNAL(edited()), this, SLOT(edited()));
    //connect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));
}

void ChumidityProperty::disconnectSignal()
{
    //connect(timeDiffEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(humidityStyle, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(showModeEdit, SIGNAL(edited()), this, SLOT(edited()));
    //connect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));
}

void ChumidityProperty::getSettingsFromWidget(QString str)
{
  simpleTextEdit->getSettingsFromWidget(str);
  humidityStyle->getSettingsFromWidget(str);
  nameEdit->getSettingsFromWidget(str);
  showModeEdit->getSettingsFromWidget(str);

}

void ChumidityProperty::setSettingsToWidget(QString str)
{
    disconnectSignal();
    simpleTextEdit->setSettingsToWidget(str);
    humidityStyle->setSettingsToWidget(str);
    nameEdit->setSettingsToWidget(str);
    showModeEdit->setSettingsToWidget(str);
    connectSignal();
}

void Get_Humidity_Text_Point(INT8U Area_No, INT16U Width, INT16U Height, S_Point &P0)
{
    INT16U Min_Width,Min_Height;

    Min_Width = Get_Humidity_Min_Width(Area_No);
    //Min_Height = Get_Humidity_Min_Height(Area_No);

    if(Width > Min_Width)
      P0.X = (Width - Min_Width) / 2;
    else
      P0.X = 0;

    if(Height > Prog_Status.File_Para[Area_No].Humidity_Para.Text_Height)
      P0.Y = (Height - Prog_Status.File_Para[Area_No].Humidity_Para.Text_Height)/2;
    else
      P0.Y = 0;

}

