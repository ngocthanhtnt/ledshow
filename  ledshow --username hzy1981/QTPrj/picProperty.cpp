#include "picProperty.h"
#include "mainwindow.h"
#include <QSettings>

extern MainWindow *w;
extern QSettings settings;

//获取参数到PicPara中
void getPicParaFromSettings(QString str, U_File_Para &para)
{
   para.Clock_Para.Flag = SHOW_PIC;

   getBorderParaFromeSettings(str, para);
   getShowModeParaFromSettings(str, para);
}

//刷新显示区域
void updatePicShowArea(CshowArea *area)
{
    //CshowArea *area;
    QString str;
    QTreeWidgetItem *item;

    if(area != (CshowArea *)0) //
    {
        item = area->fileItem;
        str = item->data(0,Qt::UserRole).toString();

        getPicParaFromSettings(str,area->filePara);

        settings.beginGroup(str);
        settings.beginGroup("textEdit");
        area->picStr = settings.value("text").toString();
        area->page = settings.value("page").toInt();
        area->page = area->page > 0? (area->page - 1):0;
        settings.endGroup();

        settings.beginGroup("smLine");
        area->smLineFlag = settings.value("smLineCheck").toBool();
        settings.endGroup();


        area->editMode = (settings.value("subType").toInt() EQ PIC_TABLE_PROPERTY)?1:0;
/*
        settings.beginGroup("showMode"); //是否是连续左移模式?
        area->moveFlag = (settings.value("inMode").toInt() EQ MOVE_LEFT_CONTINUOUS_INDEX)?true:false;
        settings.endGroup();
*/
        settings.endGroup();

        //是否连续左移
        area->moveFlag = checkSLineMoveLeftContinuous(str);
        area->updateFlag = true;
        //area->imageBk = getTextEditImage(MLINE_MODE, area->width(), area->height(), str, 0);

        getBorderData(str, area->borderData, sizeof(area->borderData));
        //qDebug("file_para flag = %d", area->File_Para.Temp_Para.Flag);
        area->update(); //刷新显示

        //getSLineTextImage(area->picStr, area->width(), area->height(), 1);

    }
    else
    {
        ASSERT_FAILED();
    }

}

void CpicProperty::editSlot()
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
            updatePicShowArea(area);

        }
    }
}

//属性编辑的SLOT
void CpicProperty::showModeEdited()
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
            showModeEdit->getSettingsFromWidget(str);

            int flag = checkSLineMoveLeftContinuous(str);
            if(flag != area->moveFlag)
            {
              area->moveFlag = flag;
              area->updateFlag = true;
              area->update();
            }
            //getSettingsFromWidget(str);
            //updatePicShowArea(area);
        }
    }
}

//图文属性编辑
CpicProperty::CpicProperty(QWidget *parent):QWidget(parent)
{
    //QGridLayout *gridLayout;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;


    hLayout = new QHBoxLayout(this);

    area = new Carea(this);
    nameEdit = new CnameEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(nameEdit);
    vLayout ->addWidget(area);
    hLayout->addLayout(vLayout);

    textGroup = new QGroupBox(tr("文本内容"), this);
    editButton = new QPushButton(tr("编辑内容"), this);
    pageBox = new QSpinBox(this);
    pageBox->setMinimum(1);
    vLayout = new QVBoxLayout(this);
    vLayout->addStretch(0);
    vLayout ->addWidget(editButton);
    vLayout->addStretch(0);
    QLabel *page = new QLabel(tr("第"),this);
    QHBoxLayout *pageHLayout = new QHBoxLayout(this);
    pageHLayout->addWidget(page);
    pageHLayout->addWidget(pageBox);
    muLabel = new QLabel(tr("幕"),this);
    pageHLayout->addWidget(muLabel);
    vLayout->addLayout(pageHLayout);
    vLayout->addStretch(0);
    textGroup -> setLayout(vLayout);

    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(textGroup);
    hLayout->addLayout(vLayout);

    showModeEdit = new CshowModeEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(showModeEdit);
    hLayout->addLayout(vLayout);

    borderEdit = new CborderEdit(this);
    hLayout->addWidget(borderEdit);
    hLayout->addStretch(10);
    setLayout(hLayout);

    edit = new TextEdit(this, 1);
    //edit->getEdit()->clear();
    connectSignal();
    //connect(editButton, SIGNAL(clicked()), this, SLOT(propertyEdited()));
    //pageBox->setEnabled(false);
    connect(edit->spinPage, SIGNAL(valueChanged(int)), pageBox, SLOT(setValue(int)));
    connect(pageBox, SIGNAL(valueChanged(int)), edit->spinPage, SLOT(setValue(int)));
}

CpicProperty::~CpicProperty()
{

}

void CpicProperty::connectSignal()
{
    connect(editButton, SIGNAL(clicked()), edit, SLOT(showInit()));
    connect(showModeEdit, SIGNAL(edited()), this, SLOT(showModeEdited()));
    connect(borderEdit, SIGNAL(editSignal()), this, SLOT(editSlot()));
}

void CpicProperty::disconnectSignal()
{
    disconnect(editButton, SIGNAL(clicked()), edit, SLOT(showInit()));
    disconnect(showModeEdit, SIGNAL(edited()), this, SLOT(showModeEdited()));
    disconnect(borderEdit, SIGNAL(editSignal()), this, SLOT(editSlot()));
}

void CpicProperty::screenCardParaChangeProc()
{
  edit->screenCardParaChangeProc();
}

//获取settings到
void CpicProperty::getSettingsFromWidget(QString str)
{
    nameEdit->getSettingsFromWidget(str);
    showModeEdit->getSettingsFromWidget(str);
    borderEdit->getSettingsFromWidget(str);
    edit->getSettingsFromWidget(str);
}

void CpicProperty::setSettingsToWidget(QString str)
{
    disconnectSignal();

    nameEdit->setSettingsToWidget(str);
    showModeEdit->setSettingsToWidget(str);
    borderEdit->setSettingsToWidget(str);
    edit->setSettingsToWidget(str);

    //pageBox->setValue(edit->spinPage->value());
    connectSignal();

    pageBox->setMaximum(999);

    pageBox->setValue(edit->spinPage->value());

    //edit->edit();
}

int checkSLineMoveLeftContinuous(QString str)//Check_SLine_Move_Left_Continuous(QString str)
{
    int inMode;
    bool smLineFlag;

    settings.beginGroup(str);
    settings.beginGroup("showMode"); //是否是连续左移模式?
    inMode = settings.value("inMode").toInt();// EQ MOVE_LEFT_CONTINUOUS_INDEX)?true:false;
    settings.endGroup();

    settings.beginGroup("smLine");
    smLineFlag = settings.value("smLineCheck").toBool();
    settings.endGroup();
    settings.endGroup();

    if(inMode EQ MOVE_LEFT_CONTINUOUS_INDEX && smLineFlag EQ 0)
        return MOVE_LEFT_CONTINUOUS;
    else if(inMode EQ MOVE_UP_CONTINUOUS_INDEX)
        return MOVE_UP_CONTINUOUS;
    else
        return MOVE_NORMAL;
}
