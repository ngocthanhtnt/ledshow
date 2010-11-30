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
    //vLayout->addStretch();
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
            updateTimeShowArea(area, item);
        }
    }
}

//刷新显示区域
void updateTimeShowArea(CshowArea *area, QTreeWidgetItem *item)
{
    //CshowArea *area;
    QString str;


    if(area != (CshowArea *)0) //
    {
        str = item->data(0,Qt::UserRole).toString();

        getTimeParaFromSettings(str,area->File_Para);
        area->imageBk = getLineTextImage(str);

        //qDebug("file_para flag = %d", area->File_Para.Temp_Para.Flag);
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
   // QString str;

    para.Clock_Para.Flag = SHOW_TIME;
    settings.beginGroup(str);


    settings.endGroup();
}


CtimeProperty::~CtimeProperty()
{

}

void CtimeProperty::getSettingsFromWidget(QString str)
{
    settings.beginGroup(str);

    int type = settings.value("type").toInt();
    if(type == TIME_PROPERTY)
    {
        simpleTextEdit->getSettingsFromWidget(str);
        smLineEdit->getSettingsFromWidget(str);
        dateTimeEdit->getSettingsFromWidget(str);
    }
    else
        ASSERT_FAILED();

    settings.endGroup();
}

void CtimeProperty::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);

    int type = settings.value("type").toInt();
    if(type == TIME_PROPERTY)
    {
        simpleTextEdit->setSettingsToWidget(str);
        smLineEdit->setSettingsToWidget(str);
        dateTimeEdit->setSettingsToWidget(str);
    }
    else
        ASSERT_FAILED();

    settings.endGroup();
}
