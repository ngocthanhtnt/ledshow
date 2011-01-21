#include <QSettings>
#include "timeProperty.h"
#include "mainwindow.h"

extern MainWindow *w;
extern QSettings settings;


//正反计时编辑
ClunProperty::ClunProperty(QWidget *parent):QWidget(parent)
{
    //QGridLayout *gridLayout,*mainLayout;
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;


    hLayout = new QHBoxLayout(this);
    //mainLayout = new QGridLayout(this);

    area = new Carea(this);
    nameEdit = new CnameEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(nameEdit);
    vLayout->addWidget(area);
    //vLayout->addStretch();
    hLayout->addLayout(vLayout);

    smLineEdit = new CsmLineEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(smLineEdit);
    //vLayout->addStretch();
    hLayout->addLayout(vLayout);

    //textGroup = new QGroupBox(tr("固定文本"), this);
    simpleTextEdit = new CsimpleTextEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(simpleTextEdit);
    //vLayout->addStretch();
    hLayout->addLayout(vLayout);

    lunEdit = new ClunEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(lunEdit);
    //vLayout->addStretch();
    hLayout->addLayout(vLayout);

    showModeEdit = new CshowModeEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(showModeEdit);
    hLayout->addLayout(vLayout);
/*
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(simpleTextEdit);

    gridLayout -> addLayout(vLayout, 0, 0);

    vLayout = new QVBoxLayout(this);
    vLayout -> addWidget(lunEdit);
*/
    //hLayout ->addWidget(area);
    //hLayout ->addWidget(smLineEdit);
    //hLayout ->addWidget(simpleTextEdit);
    //hLayout ->addWidget(lunEdit);
    hLayout->addStretch(10);
    //textGroup -> setLayout(gridLayout);
    //mainLayout->addWidget(textGroup, 0, 0);
    setLayout(hLayout);

    connectSignal();
}

//属性编辑的SLOT
void ClunProperty::edited()
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
            updateLunShowArea(area);
        }
    }
}

//刷新显示区域
void updateLunShowArea(CshowArea *area)
{
    //CshowArea *area;
    QString str;
    QTreeWidgetItem *item;

    if(area != (CshowArea *)0) //
    {
        item = area->fileItem;

        str = item->data(0,Qt::UserRole).toString();

        getLunParaFromSettings(str,area->filePara);
        area->imageBk = getLineTextImage(str);
        area->updateFlag = true;
        //qDebug("file_para flag = %d", area->filePara.Temp_Para.Flag);
        area->update(); //刷新显示

    }
    else
    {
        ASSERT_FAILED();
    }

}

//从settings中获取参数
void getLunParaFromSettings(QString str, U_File_Para &para)
{
    int tmp;
    bool checked;
    // QString str;

    para.Lun_Para.Flag = SHOW_LUN;
    settings.beginGroup(str);

    settings.beginGroup("lunEdit");
    para.Lun_Para.Tiangan_Type = settings.value("tianganCheck").toBool();
    if(para.Lun_Para.Tiangan_Type > 0)
    {
        tmp = settings.value("tianganColor").toInt();
        para.Lun_Para.Tiangan_Color = 0;
        SET_BIT(para.Lun_Para.Tiangan_Color, tmp);
        para.Lun_Para.Tiangan_Font = settings.value("size").toInt();
    }

    para.Lun_Para.Nongli_Type = settings.value("nongliCheck").toBool();
    if(para.Lun_Para.Tiangan_Type > 0)
    {
        tmp = settings.value("nongliColor").toInt();
        para.Lun_Para.Nongli_Color = 0;
        SET_BIT(para.Lun_Para.Nongli_Color, tmp);
        para.Lun_Para.Nongli_Font = settings.value("size").toInt();
    }

    para.Lun_Para.Jieqi_Type = settings.value("jieqiCheck").toBool();
    if(para.Lun_Para.Jieqi_Type > 0)
    {
        tmp = settings.value("jieqiColor").toInt();
        para.Lun_Para.Jieqi_Color = 0;
        SET_BIT(para.Lun_Para.Jieqi_Color, tmp);
        para.Lun_Para.Jieqi_Font = settings.value("size").toInt();
    }

    settings.endGroup();

    settings.beginGroup("smLine");
    para.Lun_Para.SmLineFlag = settings.value("smLineCheck").toBool();
    para.Lun_Para.LineSpace = (INT8U)settings.value("lineSpace").toInt();
    settings.endGroup();


    settings.endGroup();

    getShowModeParaFromSettings(str, para);

}


ClunProperty::~ClunProperty()
{

}

void ClunProperty::connectSignal()
{
    //connect(nameEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(lunEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(showModeEdit, SIGNAL(edited()), this, SLOT(edited()));
}

void ClunProperty::disconnectSignal()
{
    //connect(nameEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(lunEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(showModeEdit, SIGNAL(edited()), this, SLOT(edited()));
}

void ClunProperty::getSettingsFromWidget(QString str)
{
    settings.beginGroup(str);
    int type = settings.value("type").toInt();
    settings.endGroup();

    if(type == LUN_PROPERTY)
    {
        nameEdit->getSettingsFromWidget(str);
        simpleTextEdit->getSettingsFromWidget(str);
        smLineEdit->getSettingsFromWidget(str);
        lunEdit->getSettingsFromWidget(str);
    }
    else
        ASSERT_FAILED();


}

void ClunProperty::setSettingsToWidget(QString str)
{
    disconnectSignal();

    settings.beginGroup(str);
    int type = settings.value("type").toInt();
    settings.endGroup();

    if(type == LUN_PROPERTY)
    {
        nameEdit->setSettingsToWidget(str);
        simpleTextEdit->setSettingsToWidget(str);
        smLineEdit->setSettingsToWidget(str);
        lunEdit->setSettingsToWidget(str);
    }
    else
        ASSERT_FAILED();

    connectSignal();
}
