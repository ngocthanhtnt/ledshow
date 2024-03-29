#include <QHBoxLayout>
#include <QSettings>
#include "tempProperty.h"
#include "simpleTextEdit.h"
#include "showArea.h"
#include "mainwindow.h"


extern MainWindow *w;

extern QSettings settings;
Ctemp::Ctemp(QWidget *parent):QGroupBox(parent)
{
    QHBoxLayout *hLayout;
    QLabel *label;

    tempCombo = new QComboBox(this);
    colorCombo = new CcolorCombo(this);
    sizeCombo = new CsizeCombo(this);
    label = new QLabel(tr("格式"),this);
    /*
    {"温度 %2d.%d℃", 11},
    {"温度 %2d℃", 9},
    {" %2d.%d℃", 7},
    {" %2d℃",5}
    */
    tempCombo->addItem(tr("温度 25.0℃"));
    tempCombo->addItem(tr("温度 25℃"));
    tempCombo->addItem(tr(" 25.0℃"));
    tempCombo->addItem(tr(" 25℃"));

    hLayout = new QHBoxLayout(this);
    hLayout ->addWidget(label);
    hLayout->addWidget(tempCombo);

    hLayout->addWidget(sizeCombo);
    hLayout->addWidget(colorCombo);

    setLayout(hLayout);
    setTitle(tr("温度属性"));

    connect(tempCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
    connect(colorCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
    connect(sizeCombo, SIGNAL(indexChangeSignal()),this,SIGNAL(edited()));
}

void Ctemp::screenCardParaChangeProc()
{
  colorCombo->setItems();
  sizeCombo->setItems();
}

void Ctemp::getSettingsFromWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("tempStyle");
    settings.setValue("tempCombo", tempCombo->currentIndex());
    settings.setValue("color", colorCombo->currentIndex());
    settings.setValue("size", sizeCombo->currentIndex());
    settings.endGroup();
    settings.endGroup();

    //colorCombo->getSettingsFromWidget(str);
    //sizeCombo->getSettingsFromWidget(str);

}

void Ctemp::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    settings.beginGroup("tempStyle");
    //settings.setValue("tempCombo", tempCombo->currentIndex());
    tempCombo->setCurrentIndex(settings.value("tempCombo").toInt());
    colorCombo->setCurrentIndex(settings.value("color").toInt());
    sizeCombo->setCurrentIndex(settings.value("size").toInt());
    settings.endGroup();
    settings.endGroup();

    //colorCombo->setSettingsTomWidget(str);
    //sizeCombo->setSettingsToWidget(str);
}


Ctemp::~Ctemp()
{

}
//正反计时编辑
CtempProperty::CtempProperty(QWidget *parent):QWidget(parent)
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
    tempStyle = new Ctemp(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(tempStyle,1);
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

CtempProperty::~CtempProperty()
{

}

//从settings中获取参数
void getTempParaFromSettings(QString str, U_File_Para &para)
{
    int tmp;
    getBorderParaFromeSettings(str, para);
    para.Temp_Para.Flag = SHOW_TEMP;
    settings.beginGroup(str);
    settings.beginGroup("tempStyle");

    para.Temp_Para.Temp_Type = settings.value("tempCombo").toInt();
    tmp = settings.value("color").toInt();
    para.Temp_Para.Temp_Color = getColorDataFromIndex(tmp);
    //SET_BIT(para.Temp_Para.Temp_Color, tmp);
    para.Temp_Para.Temp_Font = settings.value("size").toInt();

    settings.endGroup();
    settings.endGroup();

    getShowModeParaFromSettings(str, para);

}
//刷新显示区域
void updateTempShowArea(CshowArea *area)
{
    //CshowArea *area;
    QString str;
    QTreeWidgetItem *item;

    if(area != (CshowArea *)0) //
    {
        item = area->fileItem;

        str = item->data(0,Qt::UserRole).toString();

        getTempParaFromSettings(str,area->filePara);
        area->imageBk = getLineTextImage(str);
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
void CtempProperty::edited()
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
            updateTempShowArea(area);
        }
    }
}

void CtempProperty::connectSignal()
{
    //connect(timeDiffEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(tempStyle, SIGNAL(edited()), this, SLOT(edited()));
    connect(showModeEdit, SIGNAL(edited()), this, SLOT(edited()));
    //connect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(borderEdit, SIGNAL(editSignal()), this, SLOT(edited()));
}

void CtempProperty::disconnectSignal()
{
    //connect(timeDiffEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(tempStyle, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(showModeEdit, SIGNAL(edited()), this, SLOT(edited()));
    //connect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(borderEdit, SIGNAL(editSignal()), this, SLOT(edited()));
}

void CtempProperty::getSettingsFromWidget(QString str)
{
  simpleTextEdit->getSettingsFromWidget(str);
  tempStyle->getSettingsFromWidget(str);
  nameEdit->getSettingsFromWidget(str);
  showModeEdit->getSettingsFromWidget(str);
  borderEdit->getSettingsFromWidget(str);

}

void CtempProperty::setSettingsToWidget(QString str)
{
    disconnectSignal();
    simpleTextEdit->setSettingsToWidget(str);
    tempStyle->setSettingsToWidget(str);
    nameEdit->setSettingsToWidget(str);
    showModeEdit->setSettingsToWidget(str);
    borderEdit->setSettingsToWidget(str);
    connectSignal();
}

void Get_Temp_Text_Point(INT8U Area_No, INT16U Width, INT16U Height, S_Point &P0)
{
    INT16U Min_Width;//,Min_Height;

    Min_Width = Get_Temp_Min_Width(Area_No);
    //Min_Height = Get_Temp_Min_Height(Area_No);

    if(Width > Min_Width)
      P0.X = (Width - Min_Width) / 2;
    else
      P0.X = 0;

    if(Height > Prog_Status.File_Para[Area_No].Temp_Para.Text_Height)
      P0.Y = (Height - Prog_Status.File_Para[Area_No].Temp_Para.Text_Height)/2;
    else
      P0.Y = 0;

}
