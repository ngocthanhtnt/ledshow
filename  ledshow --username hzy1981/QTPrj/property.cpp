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

    lunProperty = new ClunProperty(stackedWidget);
    stackedWidget->addWidget(lunProperty);
    setWidget(stackedWidget);


}

INT8U getStackedWidgetIndex(INT8U type)
{
    if(type < 10)
        return type;
    else if(type EQ PIC_MTEXT_PROPERTY ||\
            type EQ PIC_STEXT_PROPERTY)
        return 0x02;
    else if(type EQ PIC_FLASH_PROPERTY)
        return 0x03;
    else
    {
        ASSERT_FAILED();
        return 0;
    }
    /*
#define PROG_PROPERTY 0x00
#define AREA_PROPERTY 0x01
#define PIC_PROPERTY    0x02 //图片
#define CLOCK_PROPERTY  0x04 //表盘
#define TIME_PROPERTY   0x05 //日期时间
#define TIMER_PROPERTY  0x06 //定时
#define TEMP_PROPERTY   0x07 //温度
#define LUN_PROPERTY 0x08    //农历
     */
}

//根据item更新当前property的显示
void Cproperty::updateProperty(QTreeWidgetItem *item)
{
    QString str;
    int type;

    setSettingsToWidget(item);
/*
    str = item->data(0, Qt::UserRole).toString();

    settings.beginGroup(str);
    type = settings.value("type").toInt();
    settings.endGroup();
*/
    type = checkItemType(item);
    int index = getStackedWidgetIndex(type);
    stackedWidget->setCurrentIndex(index);

    if(type == PROG_PROPERTY)
    {
       area = (Carea *)0;
       ASSERT_FAILED();//progProperty->setSettingsToWidget(str);//stackedWidget->setCurrentIndex();
    }
    else if(type == AREA_PROPERTY)
        area = areaProperty->area;//->setSettingsToWidget(str);
    else if(type == PIC_MTEXT_PROPERTY)
    {
        //picProperty->setSettingsToWidget(str);
        area = picProperty->area;//->setSettingsToWidget(str);
    }
    else if(type == PIC_FLASH_PROPERTY)
    {
        //flashProperty->setSettingsToWidget(str);
        area = flashProperty->area;//->setSettingsToWidget(str);
    }
    else if(type == CLOCK_PROPERTY)
    {
        //clockProperty->setSettingsToWidget(str);
        area = clockProperty->area;//->setSettingsToWidget(pstr);
    }
    else if(type == TIME_PROPERTY)
    {
        //timeProperty->setSettingsToWidget(str);
        area = timeProperty->area;//->setSettingsToWidget(str);
    }
    else if(type == TIMER_PROPERTY)
    {
        //timerProperty->setSettingsToWidget(str);
        area = timerProperty->area;//->setSettingsToWidget(str);
    }
    else if(type == TEMP_PROPERTY)
    {
        //tempProperty->setSettingsToWidget(str);
        area = tempProperty->area;//->setSettingsToWidget(str);
    }
    else if(type == LUN_PROPERTY)
    {
        area = lunProperty->area;
    }
    else
    {
        area = (Carea *)0;
        ASSERT_FAILED();
    }

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
    QString pstr;

    str = item->data(0, Qt::UserRole).toString();
    if(item->parent()!= 0)
      pstr = item->parent()->data(0, Qt::UserRole).toString();
/*
    settings.beginGroup(str);
    type = settings.value("type").toInt();
    settings.endGroup();
*/
    type = checkItemType(item);

    if(type == PROG_PROPERTY)
        progProperty->setSettingsToWidget(str);//stackedWidget->setCurrentIndex();
    else if(type == AREA_PROPERTY)
    {
        areaProperty->setSettingsToWidget(str);
        areaProperty->area->setSettingsToWidget(str);
    }
    else if(type == PIC_MTEXT_PROPERTY)
    {
        picProperty->setSettingsToWidget(str);
        picProperty->area->setSettingsToWidget(pstr);
    }
    else if(type == PIC_FLASH_PROPERTY)
    {
        flashProperty->setSettingsToWidget(str);
        flashProperty->area->setSettingsToWidget(pstr);
    }
    else if(type == CLOCK_PROPERTY)
    {
        clockProperty->setSettingsToWidget(str);
        clockProperty->area->setSettingsToWidget(pstr);
    }
    else if(type == TIME_PROPERTY)
    {
        timeProperty->setSettingsToWidget(str);
        timeProperty->area->setSettingsToWidget(pstr);
    }
    else if(type == TIMER_PROPERTY)
    {
        timerProperty->setSettingsToWidget(str);
        timerProperty->area->setSettingsToWidget(pstr);
    }
    else if(type == TEMP_PROPERTY)
    {
        tempProperty->setSettingsToWidget(str);
        tempProperty->area->setSettingsToWidget(pstr);
    }
    else if(type == LUN_PROPERTY)
    {
        lunProperty->setSettingsToWidget(str);
        lunProperty->area->setSettingsToWidget(pstr);
    }
    else
    {
        ASSERT_FAILED();
    }
}

void Cproperty::getSettingsFromWidget(QTreeWidgetItem *item)
{
    QString str,pstr;
    int type;

    if(item == (QTreeWidgetItem *)0)
        return;

    str = item->data(0, Qt::UserRole).toString();
    if(item->parent()!= 0)
      pstr = item->parent()->data(0, Qt::UserRole).toString();
/*
    settings.beginGroup(str);
    type = settings.value("type").toInt();
    settings.endGroup();
*/
    type = checkItemType(item);

    if(type == PROG_PROPERTY)
        progProperty->getSettingsFromWidget(str);//stackedWidget->setCurrentIndex();
    else if(type == AREA_PROPERTY)
    {
        areaProperty->getSettingsFromWidget(str);
        areaProperty->area->getSettingsFromWidget(str);
    }
    else if(type == PIC_MTEXT_PROPERTY)
    {
        picProperty->getSettingsFromWidget(str);
        picProperty->area->getSettingsFromWidget(pstr);
    }
    else if(type == PIC_FLASH_PROPERTY)
    {
        flashProperty->getSettingsFromWidget(str);
        flashProperty->area->getSettingsFromWidget(pstr);
    }
    else if(type == CLOCK_PROPERTY)
    {
        clockProperty->getSettingsFromWidget(str);
        clockProperty->area->getSettingsFromWidget(pstr);
    }
    else if(type == TIME_PROPERTY)
    {
        timeProperty->getSettingsFromWidget(str);
        timeProperty->area->getSettingsFromWidget(pstr);
    }
    else if(type == TIMER_PROPERTY)
    {
        timerProperty->getSettingsFromWidget(str);
        timerProperty->area->getSettingsFromWidget(pstr);
    }
    else if(type == TEMP_PROPERTY)
    {
        tempProperty->getSettingsFromWidget(str);
        tempProperty->area->getSettingsFromWidget(pstr);
    }
    else if(type == LUN_PROPERTY)
    {
        lunProperty->getSettingsFromWidget(str);
        lunProperty->area->getSettingsFromWidget(pstr);
    }
    else
    {
        ASSERT_FAILED();
    }
}

//当前节目、分区、文件发生变化时的处理
void Cproperty::progChangedProc(QString settingsStr)
{

}
