#include <QSettings>
#include "timeProperty.h"
#include "mainwindow.h"

extern MainWindow *w;
extern QSettings settings;


//正反计时编辑
CtimeProperty::CtimeProperty(QWidget *parent):QWidget(parent)
{
    //QGridLayout *gridLayout,*mainLayout;
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;


    hLayout = new QHBoxLayout(this);
    //mainLayout = new QGridLayout(this);

    area = new Carea(this);
    vLayout = new QVBoxLayout(this);
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

    dateTimeEdit = new CdateTimeEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(dateTimeEdit);
    hLayout->addLayout(vLayout);
    //vLayout->addStretch();
    showModeEdit = new CshowModeEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(showModeEdit);

    hLayout->addLayout(vLayout);
/*
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(simpleTextEdit);

    gridLayout -> addLayout(vLayout, 0, 0);

    vLayout = new QVBoxLayout(this);
    vLayout -> addWidget(dateTimeEdit);
*/
    //hLayout ->addWidget(area);
    //hLayout ->addWidget(smLineEdit);
    //hLayout ->addWidget(simpleTextEdit);
    //hLayout ->addWidget(dateTimeEdit);
    hLayout->addStretch(10);
    //textGroup -> setLayout(gridLayout);
    //mainLayout->addWidget(textGroup, 0, 0);
    setLayout(hLayout);

    connect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(dateTimeEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));
}

//属性编辑的SLOT
void CtimeProperty::edited()
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
            updateTimeShowArea(area);
        }
    }
}

//刷新显示区域
void updateTimeShowArea(CshowArea *area)
{
    //CshowArea *area;
    QString str;
    QTreeWidgetItem *item;

    if(area != (CshowArea *)0) //
    {
        item = area->fileItem;

        str = item->data(0,Qt::UserRole).toString();

        getTimeParaFromSettings(str,area->filePara);
        area->imageBk = getLineTextImage(str);

        //qDebug("file_para flag = %d", area->filePara.Temp_Para.Flag);
        area->update(); //刷新显示

    }
    else
    {
        ASSERT_FAILED();
    }

}

//从settings中获取参数
void getTimeParaFromSettings(QString str, U_File_Para &para)
{
    int tmp;
    bool checked;
    // QString str;

    para.Time_Para.Flag = SHOW_TIME;
    settings.beginGroup(str);

    settings.beginGroup("dateEdit");
    checked = settings.value("checked").toBool();
    if(checked > 0)
    {
        para.Time_Para.Date_Type = settings.value("type").toInt() + 1;
        tmp = settings.value("color").toInt();
        para.Time_Para.Date_Color = 0;
        SET_BIT(para.Time_Para.Date_Color, tmp);
        para.Time_Para.Date_Font = settings.value("size").toInt();
    }
    else
        para.Time_Para.Date_Type = 0;
    settings.endGroup();

    settings.beginGroup("weekEdit");
    checked = settings.value("checked").toBool();
    if(checked > 0)
    {
        para.Time_Para.Week_Type = settings.value("type").toInt() + 1;
        tmp = settings.value("color").toInt();
        para.Time_Para.Week_Color = 0;
        SET_BIT(para.Time_Para.Week_Color, tmp);
        para.Time_Para.Week_Font = settings.value("size").toInt();
    }
    else
        para.Time_Para.Week_Type = 0;

    settings.endGroup();

    settings.beginGroup("timeEdit");
    checked = settings.value("checked").toBool();
    if(checked > 0)
    {
        para.Time_Para.Time_Type = settings.value("type").toInt() + 1;
        tmp = settings.value("color").toInt();
        para.Time_Para.Time_Color = 0;
        SET_BIT(para.Time_Para.Time_Color, tmp);
        para.Time_Para.Time_Font = settings.value("size").toInt();
    }
    else
        para.Time_Para.Time_Type = 0;
    settings.endGroup();

    settings.beginGroup("smLine");
    para.Time_Para.SmLineFlag = settings.value("smLineCheck").toBool();
    settings.endGroup();


    settings.endGroup();
}


CtimeProperty::~CtimeProperty()
{

}

void CtimeProperty::getSettingsFromWidget(QString str)
{
    settings.beginGroup(str);
    int type = settings.value("type").toInt();
    settings.endGroup();

    if(type == TIME_PROPERTY)
    {
        simpleTextEdit->getSettingsFromWidget(str);
        smLineEdit->getSettingsFromWidget(str);
        dateTimeEdit->getSettingsFromWidget(str);
    }
    else
        ASSERT_FAILED();


}

void CtimeProperty::setSettingsToWidget(QString str)
{
    disconnect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(dateTimeEdit, SIGNAL(edited()), this, SLOT(edited()));
    disconnect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));

    settings.beginGroup(str);
    int type = settings.value("type").toInt();
    settings.endGroup();

    if(type == TIME_PROPERTY)
    {
        simpleTextEdit->setSettingsToWidget(str);
        smLineEdit->setSettingsToWidget(str);
        dateTimeEdit->setSettingsToWidget(str);
    }
    else
        ASSERT_FAILED();



    connect(simpleTextEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(dateTimeEdit, SIGNAL(edited()), this, SLOT(edited()));
    connect(smLineEdit, SIGNAL(edited()), this, SLOT(edited()));
}
