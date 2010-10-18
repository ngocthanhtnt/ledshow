#include "progManage.h"
#include "property.h"
#include <QSettings>
#include <QTreeWidgetItem>

extern QSettings settings;
/*
#define PROG_PROPERTY 0x00
#define AREA_PROPERTY 0x01
#define PIC_PROPERTY    0x02 //图片
#define FLASH_PROPERTY  0x03 //动画
#define CLOCK_PROPERTY  0x04 //表盘
#define TIME_PROPERTY   0x05 //日期时间
#define TIMER_PROPERTY  0x06 //定时
#define TEMP_PROPERTY   0x07 //温度
 */
//属性编辑框
Cproperty::Cproperty(QWidget *parent):QDockWidget(parent)
{
    //QVBoxLayout *layout;

    stackedWidget = new QStackedWidget(this);
    setAllowedAreas(Qt::BottomDockWidgetArea);

    progProperty = new CprogProperty(stackedWidget);
    stackedWidget->addWidget(progProperty);

    areaProperty = new CareaProperty(stackedWidget);
    stackedWidget -> addWidget(areaProperty);

    picProperty = new CpicProperty(stackedWidget);
    stackedWidget->addWidget(picProperty);

    flashProperty = new CflashProperty(stackedWidget);
    stackedWidget->addWidget(flashProperty);

    clockProperty = new CclockProperty(stackedWidget);
    stackedWidget->addWidget(clockProperty);

    timeProperty = new CtimeProperty(stackedWidget);
    stackedWidget->addWidget(timeProperty);

    timerProperty = new CtimerProperty(stackedWidget);
    stackedWidget->addWidget(timerProperty);

    tempProperty = new CtempProperty(stackedWidget);
    stackedWidget->addWidget(tempProperty);

    setWidget(stackedWidget);


}

//根据item更新当前property的显示
void Cproperty::updateProperty(QTreeWidgetItem *item)
{
    QString str;
    int type;

    setSettingsToWidget(item);

    str = item->data(0, Qt::UserRole).toString();

    settings.beginGroup(str);
    type = settings.value("type").toInt();
    settings.endGroup();
    stackedWidget->setCurrentIndex(type);


}

Cproperty ::~Cproperty()
{

}
/*

#define PROG_PROPERTY 0x00
#define AREA_PROPERTY 0x01
#define PIC_PROPERTY    0x02 //图片
#define FLASH_PROPERTY  0x03 //动画
#define CLOCK_PROPERTY  0x04 //表盘
#define TIME_PROPERTY   0x05 //日期时间
#define TIMER_PROPERTY  0x06 //定时
#define TEMP_PROPERTY   0x07 //温度

 */
void Cproperty::setSettingsToWidget(QTreeWidgetItem *item)
{
    QString str;
    int type;

    str = item->data(0, Qt::UserRole).toString();

    settings.beginGroup(str);
    type = settings.value("type").toInt();
    settings.endGroup();

    if(type == PROG_PROPERTY)
        progProperty->setSettingsToWidget(str);//stackedWidget->setCurrentIndex();
    else if(type == AREA_PROPERTY)
        areaProperty->setSettingsToWidget(str);
    else if(type == PIC_PROPERTY)
        picProperty->setSettingsToWidget(str);
    else if(type == FLASH_PROPERTY)
        flashProperty->setSettingsToWidget(str);
    else if(type == CLOCK_PROPERTY)
        clockProperty->setSettingsToWidget(str);
    else if(type == TIME_PROPERTY)
        timeProperty->setSettingsToWidget(str);
    else if(type == TIMER_PROPERTY)
        timerProperty->setSettingsToWidget(str);
    else if(type == TEMP_PROPERTY)
        tempProperty->setSettingsToWidget(str);
    else
    {
        //ASSERT_FAILED();
    }
}

void Cproperty::getSettingsFromWidget(QTreeWidgetItem *item)
{
    QString str;
    int type;

    if(item == (QTreeWidgetItem *)0)
        return;

    str = item->data(0, Qt::UserRole).toString();

    settings.beginGroup(str);
    type = settings.value("type").toInt();
    settings.endGroup();

    if(type == PROG_PROPERTY)
        progProperty->getSettingsFromWidget(str);//stackedWidget->setCurrentIndex();
    else if(type == AREA_PROPERTY)
        areaProperty->getSettingsFromWidget(str);
    else if(type == PIC_PROPERTY)
        picProperty->getSettingsFromWidget(str);
    else if(type == FLASH_PROPERTY)
        flashProperty->getSettingsFromWidget(str);
    else if(type == CLOCK_PROPERTY)
        clockProperty->getSettingsFromWidget(str);
    else if(type == TIME_PROPERTY)
        timeProperty->getSettingsFromWidget(str);
    else if(type == TIMER_PROPERTY)
        timerProperty->getSettingsFromWidget(str);
    else if(type == TEMP_PROPERTY)
        tempProperty->getSettingsFromWidget(str);
    else
    {
        //ASSERT_FAILED();
    }
}

//当前节目、分区、文件发生变化时的处理
void Cproperty::progChangedProc(QString settingsStr)
{

}
