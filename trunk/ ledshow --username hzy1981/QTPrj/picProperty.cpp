#include "picProperty.h"
#include "mainwindow.h"
#include <QSettings>

extern MainWindow *w;
extern QSettings settings;

//获取参数到PicPara中
void getPicParaFromSettings(QString str, U_File_Para &para)
{
   para.Clock_Para.Flag = SHOW_PIC;
}

//刷新显示区域
void updatePicShowArea(CshowArea *area, QTreeWidgetItem *item)
{
    //CshowArea *area;
    QString str;


    if(area != (CshowArea *)0) //
    {
        str = item->data(0,Qt::UserRole).toString();

        getPicParaFromSettings(str,area->File_Para);

        settings.beginGroup(str);
        settings.beginGroup("textEdit");
        area->picStr = settings.value("text").toString();
        settings.endGroup();

        settings.beginGroup("smLine");
        area->smLineFlag = settings.value("smLineCheck").toBool();
        settings.endGroup();

        settings.endGroup();

        area->page = 0;
        //area->imageBk = getTextEditImage(MLINE_MODE, area->width(), area->height(), str, 0);

        //qDebug("file_para flag = %d", area->File_Para.Temp_Para.Flag);
        area->update(); //刷新显示

    }
    else
    {
        ASSERT_FAILED();
    }

}

//属性编辑的SLOT
void CpicProperty::propertyEdited()
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
            updatePicShowArea(area, item);
        }
    }
}

//图文属性编辑
CpicProperty::CpicProperty(QWidget *parent):QWidget(parent)
{
    QGridLayout *gridLayout;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;


    hLayout = new QHBoxLayout(this);

    area = new Carea(this);
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(area);
    hLayout->addLayout(vLayout);

    textGroup = new QGroupBox(tr("文本内容"), this);
    editButton = new QPushButton(tr("编辑"), this);

    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(editButton);
    textGroup -> setLayout(vLayout);

    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(textGroup);
    hLayout->addLayout(vLayout);

    showModeEdit = new CshowModeEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(showModeEdit);
    hLayout->addLayout(vLayout);

    hLayout->addStretch(10);
    setLayout(hLayout);

    edit = new TextEdit(this);
    //edit->getEdit()->clear();
    connect(editButton, SIGNAL(clicked()), edit, SLOT(showInit()));
    //connect(editButton, SIGNAL(clicked()), this, SLOT(propertyEdited()));
}

CpicProperty::~CpicProperty()
{

}


//获取settings到
void CpicProperty::getSettingsFromWidget(QString str)
{
    showModeEdit->getSettingsFromWidget(str);
    edit->getSettingsFromWidget(str);
}

void CpicProperty::setSettingsToWidget(QString str)
{
    showModeEdit->setSettingsToWidget(str);
    edit->setSettingsToWidget(str);
}


