#include "progManage.h"
#include "property.h"
#include <QSettings>
#include <QTreeWidgetItem>

extern QSettings settings;
/*
#define SCREEN_PROPERTY 0x00
#define PROG_PROPERTY 0x01
#define AREA_PROPERTY 0x02
#define PIC_PROPERTY    0x03 //图片
#define CLOCK_PROPERTY  0x05 //表盘
#define TIME_PROPERTY   0x06 //日期时间
#define TIMER_PROPERTY  0x07 //定时
#define TEMP_PROPERTY   0x08 //温度
#define LUN_PROPERTY 0x09    //农历

#define PIC_TABLE_PROPERTY  0x30
#define PIC_FLASH_PROPERTY  0x31 //动画
#define PIC_MTEXT_PROPERTY  0x32
#define PIC_STEXT_PROPERTY  0x33
 */
//属性编辑框
Cproperty::Cproperty(QWidget *parent):QDockWidget(parent)
{
    //QVBoxLayout *layout;

    docWidget = new QWidget(this);
    setAllowedAreas(Qt::BottomDockWidgetArea);
    hLayout = new QHBoxLayout(this);//docWidget);
    docWidget->setLayout(hLayout);
    setWidget(docWidget);
    setWindowTitle(tr("属性编辑"));

    setFeatures(QDockWidget::NoDockWidgetFeatures);
/*
    //0
    screenProperty = new CscreenProperty(stackedWidget);
    stackedWidget->addWidget(screenProperty);

    //1
    progProperty = new CprogProperty(stackedWidget);
    stackedWidget->addWidget(progProperty);

    //2
    areaProperty = new CareaProperty(stackedWidget);
    stackedWidget -> addWidget(areaProperty);

    //3
    picProperty = new CpicProperty(stackedWidget);
    stackedWidget->addWidget(picProperty);

    //4
    flashProperty = new CflashProperty(stackedWidget);
    stackedWidget->addWidget(flashProperty);

    //5
    imageProperty = new CimageProperty(stackedWidget);
    stackedWidget->addWidget(imageProperty);
    //6
    clockProperty = new CclockProperty(stackedWidget);
    stackedWidget->addWidget(clockProperty);

    //7
    timeProperty = new CtimeProperty(stackedWidget);
    stackedWidget->addWidget(timeProperty);

    //8
    timerProperty = new CtimerProperty(stackedWidget);
    stackedWidget->addWidget(timerProperty);

    //9
    tempProperty = new CtempProperty(stackedWidget);
    stackedWidget->addWidget(tempProperty);

    //10
    lunProperty = new ClunProperty(stackedWidget);
    stackedWidget->addWidget(lunProperty);
    setWidget(stackedWidget);

    //10
    humidityProperty = new ChumidityProperty(stackedWidget);
    stackedWidget->addWidget(humidityProperty);
    setWidget(stackedWidget);

    //11
    noiseProperty = new CnoiseProperty(stackedWidget);
    stackedWidget->addWidget(noiseProperty);
    setWidget(stackedWidget);
*/
    //setWidget(stackedWidget);
    //this->setFeatures(QDockWidget::NoDockWidgetFeatures);
}

INT8U getStackedWidgetIndex(INT8U type)
{
    if(type < 13)
        return type;
    else if(type EQ PIC_MTEXT_PROPERTY ||\
            type EQ PIC_STEXT_PROPERTY ||\
            type EQ PIC_TABLE_PROPERTY)
        return 0x03;
    else if(type EQ PIC_FLASH_PROPERTY)
        return 0x04;
    else if(type EQ PIC_IMAGE_PROPERTY)
        return 0x05;
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
void Cproperty::deleteProperty()
{

    if(screenProperty != 0)
    {
        QList<CscreenProperty*> items = findChildren<CscreenProperty*>(QString());
         foreach(CscreenProperty*item, items)
         {
             delete item;
         }

        //hLayout->removeItem(hLayout->itemAt(0));
        screenProperty = 0;
    }

    if(progProperty != 0)
    {
        QList<CprogProperty*> items = findChildren<CprogProperty*>(QString());
         foreach(CprogProperty*item, items)
         {
             delete item;
         }
      //delete progProperty;
      progProperty = 0;
    }

    if(areaProperty != 0)
    {
        QList<CareaProperty*> items = findChildren<CareaProperty*>(QString());
         foreach(CareaProperty*item, items)
         {
             delete item;
         }
      areaProperty = 0;
    }

    if(txtProperty != 0)
    {
        QList<CtxtProperty*> items = findChildren<CtxtProperty*>(QString());
         foreach(CtxtProperty*item, items)
         {
             delete item;
         }
      txtProperty = 0;
    }


    if(picProperty != 0)
    {
        QList<CpicProperty*> items = findChildren<CpicProperty*>(QString());
         foreach(CpicProperty*item, items)
         {
             delete item;
         }
      picProperty = 0;
    }

    if(flashProperty != 0)
    {
        QList<CflashProperty*> items = findChildren<CflashProperty*>(QString());
         foreach(CflashProperty*item, items)
         {
             delete item;
         }
      flashProperty = 0;
    }

    if(imageProperty != 0)
    {
        QList<CimageProperty*> items = findChildren<CimageProperty*>(QString());
         foreach(CimageProperty*item, items)
         {
             delete item;
         }
      imageProperty = 0;
    }

    if(clockProperty != 0)
    {
        QList<CclockProperty*> items = findChildren<CclockProperty*>(QString());
         foreach(CclockProperty*item, items)
         {
             delete item;
         }
      clockProperty = 0;
    }

    if(timeProperty != 0)
    {
        QList<CtimeProperty*> items = findChildren<CtimeProperty*>(QString());
         foreach(CtimeProperty*item, items)
         {
             delete item;
         }
      timeProperty = 0;
    }

    if(timerProperty != 0)
    {
        QList<CtimerProperty*> items = findChildren<CtimerProperty*>(QString());
         foreach(CtimerProperty*item, items)
         {
             delete item;
         }
      timerProperty = 0;
    }

    if(tempProperty != 0)
    {
        QList<CtempProperty*> items = findChildren<CtempProperty*>(QString());
         foreach(CtempProperty*item, items)
         {
             delete item;
         }
      tempProperty = 0;
    }

    if(lunProperty != 0)
    {
        QList<ClunProperty*> items = findChildren<ClunProperty*>(QString());
         foreach(ClunProperty*item, items)
         {
             delete item;
         }
      lunProperty = 0;
    }

    if(humidityProperty != 0)
    {
        QList<ChumidityProperty*> items = findChildren<ChumidityProperty*>(QString());
         foreach(ChumidityProperty*item, items)
         {
             delete item;
         }
      humidityProperty = 0;
    }

    if(noiseProperty != 0)
    {
        QList<CnoiseProperty*> items = findChildren<CnoiseProperty*>(QString());
         foreach(CnoiseProperty*item, items)
         {
             delete item;
         }
      noiseProperty = 0;
    }
}

void Cproperty::createProperty(INT8U type)
{
    //int type;

    //setSettingsToWidget(item);
/*
    str = item->data(0, Qt::UserRole).toString();

    settings.beginGroup(str);
    type = settings.value("type").toInt();
    settings.endGroup();
*/
    //type = checkItemType(item);
    //int index = getStackedWidgetIndex(type);
    //stackedWidget->setCurrentIndex(index);

    if(type  == SCREEN_PROPERTY)
    {
        screenProperty = new CscreenProperty(this);
        hLayout->addWidget(screenProperty);
    }
    else if(type == PROG_PROPERTY)
    {
        progProperty = new CprogProperty(this);
        hLayout->addWidget(progProperty);
    }
    else if(type == AREA_PROPERTY)
    {
        areaProperty = new CareaProperty(this);
        hLayout -> addWidget(areaProperty);
    }
    else if(type == TXT_PROPERTY)
    {
        txtProperty= new CtxtProperty(this);
        hLayout -> addWidget(txtProperty);
    }
    else if(type == PIC_STEXT_PROPERTY || type == PIC_MTEXT_PROPERTY || type == PIC_TABLE_PROPERTY)
    {
        picProperty = new CpicProperty(this);
        hLayout->addWidget(picProperty);
    }
    else if(type == PIC_FLASH_PROPERTY)
    {
        flashProperty = new CflashProperty(this);
        hLayout->addWidget(flashProperty);
    }
    else if(type == PIC_IMAGE_PROPERTY)
    {
        imageProperty = new CimageProperty(this);
        hLayout->addWidget(imageProperty);
    }
    else if(type == CLOCK_PROPERTY)
    {
        clockProperty = new CclockProperty(this);
        hLayout->addWidget(clockProperty);
    }
    else if(type == TIME_PROPERTY)
    {
        timeProperty = new CtimeProperty(this);
        hLayout->addWidget(timeProperty);
    }
    else if(type == TIMER_PROPERTY)
    {
        timerProperty = new CtimerProperty(this);
        hLayout->addWidget(timerProperty);
    }
    else if(type == TEMP_PROPERTY)
    {
        tempProperty = new CtempProperty(this);
        hLayout->addWidget(tempProperty);
    }
    else if(type == LUN_PROPERTY)
    {
        lunProperty = new ClunProperty(this);
        hLayout->addWidget(lunProperty);
    }
    else if(type == HUMIDITY_PROPERTY)
    {
        humidityProperty = new ChumidityProperty(this);
        hLayout->addWidget(humidityProperty);
    }
    else if(type == NOISE_PROPERTY)
    {
        noiseProperty = new CnoiseProperty(this);
        hLayout->addWidget(noiseProperty);
    }
    else
    {
        //
        ASSERT_FAILED();
    }
}

//根据item更新当前property的显示
void Cproperty::updateProperty(QTreeWidgetItem *item)
{
    QString str;
    int type;


/*
    type = checkItemType(item);
    int index = getStackedWidgetIndex(type);
    stackedWidget->setCurrentIndex(index);
*/

    deleteProperty();

    type = checkItemType(item);
    createProperty(type);
    setSettingsToWidget(item);

    if(type  == SCREEN_PROPERTY)
    {
        area= (Carea *)0;
        //ASSERT_FAILED();
    }
    else if(type == PROG_PROPERTY)
    {
       area = (Carea *)0;
       //ASSERT_FAILED();//progProperty->setSettingsToWidget(str);//stackedWidget->setCurrentIndex();
    }
    else if(type == AREA_PROPERTY)
        area = areaProperty->area;//->setSettingsToWidget(str);
    else if(type == TXT_PROPERTY)
        area = txtProperty->area;
    else if(type == PIC_STEXT_PROPERTY || type == PIC_MTEXT_PROPERTY || type == PIC_TABLE_PROPERTY)
    {
        //picProperty->setSettingsToWidget(str);
        area = picProperty->area;//->setSettingsToWidget(str);
    }
    else if(type == PIC_FLASH_PROPERTY)
    {
        //flashProperty->setSettingsToWidget(str);
        area = flashProperty->area;//->setSettingsToWidget(str);
    }
    else if(type == PIC_IMAGE_PROPERTY)
    {
        area = imageProperty->area;
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
    else if(type == HUMIDITY_PROPERTY)
    {
        area = humidityProperty->area;
    }
    else if(type == NOISE_PROPERTY)
    {
        area = noiseProperty->area;
    }
    else
    {
        area = (Carea *)0;
        ASSERT_FAILED();
    }

    if(area != 0)
    {
      area->setEditMax();
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

void Cproperty::screenCardParaChangeProc()
{
    if(txtProperty)
      txtProperty->screenCardParaChangeProc();
    if(clockProperty)
      clockProperty->screenCardParaChangeProc();
    if(timeProperty)
      timeProperty->screenCardParaChangeProc();
    if(timerProperty)
      timerProperty->screenCardParaChangeProc();
    if(picProperty)
      picProperty->screenCardParaChangeProc();
}

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

    if(type == SCREEN_PROPERTY)
    {
        qDebug("set screen para to widget:%s",(const char *)str.toLocal8Bit());
        screenProperty->setSettingsToWidget(str);; //屏幕
    }
    else if(type == PROG_PROPERTY)
        progProperty->setSettingsToWidget(str);//stackedWidget->setCurrentIndex();
    else if(type == AREA_PROPERTY)
    {
        areaProperty->setSettingsToWidget(str);
        areaProperty->area->setSettingsToWidget(str);
    }
    else if(type == TXT_PROPERTY)
    {
        txtProperty->setSettingsToWidget(str);
        txtProperty->area->setSettingsToWidget(pstr);
    }
    else if(type == PIC_STEXT_PROPERTY || type == PIC_MTEXT_PROPERTY || type == PIC_TABLE_PROPERTY)
    {
        picProperty->setSettingsToWidget(str);
        picProperty->area->setSettingsToWidget(pstr);
    }
    else if(type == PIC_FLASH_PROPERTY)
    {
        flashProperty->setSettingsToWidget(str);
        flashProperty->area->setSettingsToWidget(pstr);
    }
    else if(type == PIC_IMAGE_PROPERTY)
    {
        imageProperty->setSettingsToWidget(str);
        imageProperty->area->setSettingsToWidget(pstr);
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
    else if(type == HUMIDITY_PROPERTY)
    {
        humidityProperty->setSettingsToWidget(str);
        humidityProperty->area->setSettingsToWidget(pstr);
    }
    else if(type == NOISE_PROPERTY)
    {
        noiseProperty->setSettingsToWidget(str);
        noiseProperty->area->setSettingsToWidget(pstr);
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

    if(type == SCREEN_PROPERTY)
    {
        screenProperty->getSettingsFromWidget(str);//屏幕
    }
    else if(type == PROG_PROPERTY)
        progProperty->getSettingsFromWidget(str);//stackedWidget->setCurrentIndex();
    else if(type == AREA_PROPERTY)
    {
        areaProperty->getSettingsFromWidget(str);
        areaProperty->area->getSettingsFromWidget(str);
    }
    else if(type == TXT_PROPERTY)
    {
        txtProperty->getSettingsFromWidget(str);
        txtProperty->area->getSettingsFromWidget(str);
    }
    else if(type == PIC_STEXT_PROPERTY)
    {
        picProperty->getSettingsFromWidget(str);
        picProperty->area->getSettingsFromWidget(pstr);
    }
    else if(type == PIC_STEXT_PROPERTY || type == PIC_MTEXT_PROPERTY || type == PIC_TABLE_PROPERTY)
    {
        picProperty->getSettingsFromWidget(str);
        picProperty->area->getSettingsFromWidget(pstr);
    }
    else if(type == PIC_FLASH_PROPERTY)
    {
        flashProperty->getSettingsFromWidget(str);
        flashProperty->area->getSettingsFromWidget(pstr);
    }
    else if(type == PIC_IMAGE_PROPERTY)
    {
        imageProperty->getSettingsFromWidget(str);
        imageProperty->area->getSettingsFromWidget(pstr);
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
    else if(type == HUMIDITY_PROPERTY)
    {
        humidityProperty->getSettingsFromWidget(str);
        humidityProperty->area->getSettingsFromWidget(pstr);
    }
    else if(type == NOISE_PROPERTY)
    {
        noiseProperty->getSettingsFromWidget(str);
        noiseProperty->area->getSettingsFromWidget(pstr);
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
