#include "..\Stm32\usr\app\Includes.h"
#include "showArea.h"
#include "mainwindow.h"
#include <QPainter>
#include <QTreeWidgetItem>



extern MainWindow *w;
extern QSettings settings;

extern int linePosi[MAX_LINE_NUM];
extern int pagePosi[MAX_LINE_NUM];

bool Get_Border_Show_En()
{
  return (Card_Para.File_En_Word >> BORDER_SHOW_BIT) & 0x01;
}

bool Get_Clock_Show_En()
{
    return (Card_Para.File_En_Word >> CLOCK_SHOW_BIT) & 0x01;
}

bool Get_Txt_Show_En()
{
    return (Card_Para.File_En_Word >> TXT_SHOW_BIT) & 0x01;
}

bool Get_Pic_Show_En()
{
    return (Card_Para.File_En_Word >> PIC_SHOW_BIT) & 0x01;
}

bool Get_Lun_Show_En()
{
    return (Card_Para.File_En_Word >> LUN_SHOW_BIT) & 0x01;
}

bool Get_Temp_Show_En()
{
    return (Card_Para.File_En_Word >> TEMP_SHOW_BIT) & 0x01;
}

bool Get_Time_Show_En()
{
    return (Card_Para.File_En_Word >> TIME_SHOW_BIT) & 0x01;
}

bool Get_Timer_Show_En()
{
    return (Card_Para.File_En_Word >> TIMER_SHOW_BIT) & 0x01;
}

bool Get_Humidity_Show_En()
{
  return (Card_Para.File_En_Word >> HUMIDITY_SHOW_BIT) & 0x01;
}

bool Get_Noise_Show_En()
{
  return (Card_Para.File_En_Word >> NOISE_SHOW_BIT) & 0x01;
}

//保存屏幕参数Screen_Para到Screen_Para_Bak
void saveScreenPara(S_Screen_Para &Screen_Para_Bak)
{
  memcpy(&Screen_Para_Bak, &Screen_Para, sizeof(Screen_Para));

}
//保存节目参数Prog_Para到Prog_Para_Bak
void saveProgPara(S_Prog_Para &Prog_Para_Bak)
{
  memcpy(&Prog_Para_Bak, &Prog_Para, sizeof(Prog_Para));
}

//保存节目参数Prog_Para到Prog_Para_Bak
void saveCardPara(S_Card_Para &Card_Para_Bak)
{
  memcpy(&Card_Para_Bak, &Card_Para, sizeof(Card_Para));
}

//从Screen_Para_Bak中恢复参数到Screen_Para
void restoreScreenPara(S_Screen_Para &Screen_Para_Bak)
{
  memcpy(&Screen_Para, &Screen_Para_Bak, sizeof(Screen_Para_Bak));
}

//从Prog_Para_Bak中恢复参数到Prog_Para
void restoreProgPara(S_Prog_Para &Prog_Para_Bak)
{
  memcpy(&Prog_Para, &Prog_Para_Bak, sizeof(Prog_Para_Bak));
}

//保存节目参数Prog_Para到Prog_Para_Bak
void restoreCardPara(S_Card_Para &Card_Para_Bak)
{
  memcpy(&Card_Para, &Card_Para_Bak, sizeof(Card_Para_Bak));
}
//背景区域构造函数
CscreenArea::CscreenArea(QWidget *parent, INT16U width, INT16U height, INT8U color):CshowArea(parent,BLUE)
{
    int i,xLen,yLen;
    QStringList str;

    for(i = 0; i < MAX_AREA_NUM; i ++)
    {
     pArea[i] = newShowArea();
     pArea[i]->setVisible(0);
     //areaUsed[i] = 0;
    }

/*
    settings.beginGroup("screen");
    str = settings.allKeys();
    if(str.isEmpty() == false)
    {
        xLen = settings.value("width").toInt();
        yLen = settings.value("height").toInt();
        color = settings.value("color").toInt();

        if(xLen*yLen > MAX_POINTS)
        {
          xLen = 256;
          yLen = 256;

          settings.setValue("width", xLen);
          settings.setValue("height", yLen);
        }

        if(color > 0x07 || color == 0)
        {
            color = 0x07;
            settings.setValue("color", 0x07);
        }
    }
    else
    {
        xLen = 256;
        yLen = 256;
        color = 0x07;

        settings.setValue("width", xLen);
        settings.setValue("height", yLen);
        settings.setValue("color", 0x07);
    }
*/
    screenPara.Base_Para.Width = xLen = width;//Screen_Para.Base_Para.Width;
    screenPara.Base_Para.Height = yLen = height;//Screen_Para.Base_Para.Height;
    screenPara.Base_Para.Color = color = color;//Screen_Para.Base_Para.Color;

    resize(xLen, yLen);

    setFixedSize(xLen, yLen);
    //settings.endGroup();
    setAreaType(0);
}

//屏幕信息初始化
void CscreenArea::screenSettingsInit(QTreeWidgetItem *item)
{
    int progNum = 0,subIndex;
    QStringList progGroups;
    QString progStr;
    QString str;

    str = item->data(0, Qt::UserRole).toString();

   settings.beginGroup(str);
   subIndex = settings.value("subIndex").toInt(); //当前子节目
   settings.endGroup();

   settings.beginGroup(str + "/program/");

   //areaGroups = str + "/area/";
   if(settings.value("type").toInt() == SCREEN_PROPERTY)
   {
     progNum = settings.childGroups().size();
     progGroups = settings.childGroups();
   }
   else
   {
       ASSERT_FAILED();
       //qDebug("progSettingsInit not Prog type");
       progNum = 0;
   }

   settings.endGroup();

   if(subIndex > progNum)
   {
       ASSERT_FAILED();
       subIndex = progNum;
   }
/*
   for(int i = 0; i < MAX_AREA_NUM; i ++)
   {
       setAreaVisible(i, 0);
   }
*/
   w->screenArea->setFocusArea((CshowArea *)0);
   w->screenArea->screenItem = item; //背景区域对应该项

   //updateProgShowArea(w->screenArea);
   for(int i = 0; i < MAX_AREA_NUM; i ++)
   {
       setAreaVisible(i, 0);
   }

   if(progNum > 0 && subIndex > 0)
     progSettingsInit(item->child(subIndex - 1)); //设为焦点分区
}

//根据settings对某个节目的分区进行初始化
void CscreenArea::progSettingsInit(QTreeWidgetItem *item)
{
    int areaNum = 0,subIndex;
    QStringList areaGroups;
    QString areaStr;
    QString str;
    int type;

    str = item->data(0, Qt::UserRole).toString();

   settings.beginGroup(str);
   subIndex = settings.value("subIndex").toInt(); //焦点分区
   type = settings.value("type").toInt();
   settings.endGroup();

   settings.beginGroup(str + "/area");

   //areaGroups = str + "/area/";
   if(type == PROG_PROPERTY)
   {
     areaNum = settings.childGroups().size();
     areaGroups = settings.childGroups();
   }
   else
   {
       ASSERT_FAILED();
       //qDebug("progSettingsInit not Prog type");
       areaNum = 0;
   }

   settings.endGroup();

   if(subIndex > areaNum)
   {
       ASSERT_FAILED();
       subIndex = areaNum;
   }

   for(int i = 0; i < MAX_AREA_NUM; i ++)
   {
       setAreaVisible(i, 0);
   }

   w->screenArea->setFocusArea((CshowArea *)0);
   w->screenArea->progItem = item; //背景区域对应该项

   updateProgShowArea(w->screenArea);

   for(int i = 0; i < areaNum && i<MAX_AREA_NUM; i ++)
   {
      if(i != subIndex- 1)
       areaSettingsInit(item->child(i));
    }

   if(areaNum > 0 && subIndex > 0)
     areaSettingsInit(item->child(subIndex - 1)); //设为焦点分区


}

//根据str的设置，初始化一个分区
//str 分区的settings的group
//index 对应的area索引
void CscreenArea::areaSettingsInit(QTreeWidgetItem *item)
{
    QString str;
    int index, subIndex;
    int x,y,xLen,yLen;
    QTreeWidgetItem *subItem;

    str = item->data(0, Qt::UserRole).toString();

    settings.beginGroup(str);

    if(settings.allKeys().isEmpty()==false && settings.value("type").toInt() == AREA_PROPERTY)
    {
        x = settings.value("x").toInt();
        y = settings.value("y").toInt();
        xLen = settings.value("width").toInt();
        yLen = settings.value("height").toInt();
    }
    else
    {
        ASSERT_FAILED();
        qDebug("areaSettingsInit Error");

        x = 0;//256;
        y = 0;
        xLen = DEF_SCN_WIDTH / 2;
        yLen = DEF_SCN_HEIGHT;

        settings.setValue("x", x);
        settings.setValue("y", y);
        settings.setValue("width", xLen);
        settings.setValue("height", yLen);
        //qDebug("seeOneAreaVisible Error")
        //return;
    }

    //qDebug("x=%d,y=%d,xLen=%d,yLen=%d",x,y,xLen,yLen);
    index = settings.value("index").toInt();
    subIndex= settings.value("subIndex").toInt(); //子文件索引
    settings.endGroup();

    if(index < MAX_AREA_NUM)
    {
        pArea[index] -> setVisible(1);
        pArea[index]->areaItem = item; //背景区域对应该项
        pArea[index]->fileItem = (QTreeWidgetItem *)0; //还没有绑定一个文件

        pArea[index]->filePara.Time_Para.Flag = 0;

        w->screenArea->setFocusArea(pArea[index]);
        pArea[index]->move(x, y);
        pArea[index]->resize(xLen,yLen);

        memset(pArea[index]->showData.Color_Data, 0, sizeof(pArea[index]->showData.Color_Data));
        //Clear_Area_Data(&(pArea[index]->showData), 0);
        //初始化当前子文件
        if(subIndex <= item->childCount() && subIndex> 0)
        {
            subItem = item->child(subIndex - 1);
            fileSettingsInit(subItem);
        }

    }
    else
        ASSERT_FAILED();


    return ;
}

//文件设置初始化
void CscreenArea::fileSettingsInit(QTreeWidgetItem *item)
{
    CshowArea *area;

    //当前文件类型
    /*
    QString str = item->data(0, Qt::UserRole).toString();
    settings.beginGroup(str);
    int type = settings.value("type").toInt();
    settings.endGroup();
    */
    int type = checkItemType(item);

    //索引在父路径中
    QString str = item->parent()->data(0, Qt::UserRole).toString();
    settings.beginGroup(str);
    int index = settings.value("index").toInt();
    settings.endGroup();

    if(index >= MAX_AREA_NUM)
    {
        ASSERT_FAILED();
        index = 0;
    }

    area = w->screenArea->pArea[index];
    area->fileItem = item;
    //area->areaItem = item->parent(); //父项为分区对应的item

    if(type EQ CLOCK_PROPERTY)//表盘显示更新
    {
        updateClockShowArea(area);
    }
    else if(type EQ TXT_PROPERTY)
    {
        updateTxtShowArea(area);
    }
    else if(type EQ PIC_STEXT_PROPERTY || type EQ PIC_MTEXT_PROPERTY || type EQ PIC_TABLE_PROPERTY)
    {
        updatePicShowArea(area);
    }
    else if(type EQ TIME_PROPERTY)
    {
        updateTimeShowArea(area);
    }
    else if(type EQ TIMER_PROPERTY)
    {
        updateTimerShowArea(area);
    }
    else if(type EQ LUN_PROPERTY)
    {
        updateLunShowArea(area);
    }
    else if(type EQ PIC_FLASH_PROPERTY)
    {
        updateFlashShowArea(area);
    }
    else if(type EQ PIC_IMAGE_PROPERTY)
    {
        updateImageShowArea(area);
    }
    else if(type EQ TEMP_PROPERTY)
    {
        updateTempShowArea(area);
    }
    else if(type EQ HUMIDITY_PROPERTY)
    {
        updateHumidityShowArea(area);
    }
    else if(type EQ NOISE_PROPERTY)
    {
        updateNoiseShowArea(area);
    }
}

//当前节目、分区、文件发生变化时的处理
void CscreenArea::progChangedProc(QString settingsStr)
{

}

//设置Index号分区的现实状态，flag为0隐藏，1显示
void CscreenArea::setAreaVisible(int index, bool flag)
{
    if(index < MAX_AREA_NUM)
    {
        pArea[index]->setVisible(flag);

    }
}

int CscreenArea::checkEnoughArea()
{
    int i;

    for(i = 0; i < MAX_AREA_NUM; i ++)
    {
        if(pArea[i] -> isVisible() == 0)
           return i + 1;
    }
    return 0;
}
/*
//找到一个隐藏分区，并将其设置为现实状态
//该分区对应的参数在settingsStr中定义
int CscreenArea::setOneAreaVisible(QString settingsStr)
{
    int i;
    int x,y,xLen,yLen;

    settings.beginGroup(settingsStr);
    if(settings.allKeys().isEmpty()==false && settings.value("type").toInt() == AREA_PROPERTY)
    {
        x = settings.value("x").toInt();
        y = settings.value("y").toInt();
        xLen = settings.value("width").toInt();
        yLen = settings.value("height").toInt();
    }
    else
    {
        qDebug("seeOneAreaVisible Error");

        x = 0;//256;
        y = 0;
        xLen = 256;
        yLen = 256;

        settings.setValue("x", x);
        settings.setValue("y", y);
        settings.setValue("width", xLen);
        settings.setValue("height", yLen);
        //qDebug("seeOneAreaVisible Error")
        //return;
    }
    settings.endGroup();

    for(i = 0; i < MAX_AREA_NUM; i ++)
    {
        if(pArea[i] -> isVisible() == 0)
        {
            pArea[i] -> setVisible(1);

            CshowArea *oldArea = w->screenArea->getFocusArea();
            if(oldArea != pArea[i])
            {
               w->screenArea->setFocusArea(pArea[i]);
               pArea[i]->raise();
                if(oldArea != (CshowArea *)0)
                  oldArea->update();
            }

            pArea[i]->move(x, y);
            pArea[i]->resize(xLen,yLen);

            return 1;
            //break;
        }
    }

    return 0;
}
*/
CscreenArea::~CscreenArea()
{

}

//获取处于焦点状态的显示分区
CshowArea *CscreenArea::getFocusArea()
{
    for(int i = 0; i < MAX_AREA_NUM; i ++)
    {
        if(pArea[i]->focusFlag == true)
            return pArea[i];
    }

    return (CshowArea *)0;
}

//设置某个分区为焦点分区
void CscreenArea::setFocusArea(CshowArea *area)
{
    CshowArea *oldArea = w->screenArea->getFocusArea();
    if(oldArea != area)
    {
//       w->screenArea->setFocusArea(this);
        for(int i = 0; i < MAX_AREA_NUM; i ++)
        {
            if(pArea[i] == area) {
                pArea[i]->focusFlag = true;
            }
            else
                pArea[i]->focusFlag = false;
          //focusArea = area;
        }

       //w->progManage->treeWidget->setCurrentItem(area->treeItem); //treewidget设置为当前显示项目

        if(area != (CshowArea *)0)
        {
          area->update();//重绘
          area->raise();//置于顶部
        }
        if(oldArea != (CshowArea *)0)
          oldArea->update();
    }

}

//新建一个分区,实际上是使某个分区从隐藏状态变为显示状态
CshowArea * CscreenArea::newShowArea()
{
  CshowArea *p = new CshowArea(this, 0);
  p ->setAreaType(1);
  return p;
  //p->repaint();
  //this->repaint();

}

//根据当前item刷新显示区域
//此函数更新了screenArea中的screenItem和progItem还有fileItem
void CscreenArea::updateShowArea(QTreeWidgetItem *item)
{
    int type;// index;
    QString str;

    type = checkItemType(item);

    if(type == SCREEN_PROPERTY)
    {
        //if(w->screenArea->screenItem != item)
           w->screenArea->screenSettingsInit(item);
    }
    else if(type == PROG_PROPERTY)
    {
        if(w->screenArea->screenItem != item->parent())
        {
           w->screenArea->screenSettingsInit(item->parent());
           //w->screenArea->progSettingsInit(item);
        }
        else if(w->screenArea->progItem != item)
        {
           w->screenArea->progSettingsInit(item);
        }
    }//  progSettingsInit(QStr);
    else if(type == AREA_PROPERTY)
    {
        if(w->screenArea->screenItem != item->parent()->parent())
        {
           w->screenArea->screenSettingsInit(item->parent()->parent());
           //w->screenArea->progSettingsInit(item->parent());
           //w->scrennArea->areaSettingsInit(item);
        }
        else if(w->screenArea->progItem != item->parent())
        {
           w->screenArea->progSettingsInit(item->parent());
           //w->scrennArea->areaSettingsInit(item);
        }
        else if(w->screenArea->areaItem != item)
        {
           w->screenArea->areaSettingsInit(item);
        }
    }
    else
    {
        if(w->screenArea->screenItem != item->parent()->parent()->parent())
        {
           w->screenArea->screenSettingsInit(item->parent()->parent()->parent());
           //w->screenArea->progSettingsInit(item->parent()->parent());
           //w->scrennArea->areaSettingsInit(item->parent());
        }
        else if(w->screenArea->progItem != item->parent()->parent())
        {
           w->screenArea->progSettingsInit(item->parent()->parent());
           //w->scrennArea->areaSettingsInit(item->parent());
        }
        else if(w->screenArea->areaItem != item->parent())
        {
           w->screenArea->areaSettingsInit(item->parent());
        }
    }

}

//分区的初始化函数
CshowArea::CshowArea(QWidget *parent, int colorFlag):QWidget(parent)
{
    memset(&screenPara, 0, sizeof(screenPara));
    memset(&progPara, 0, sizeof(progPara));
    memset(&filePara, 0, sizeof(filePara));

    color = Screen_Para.Base_Para.Color;

    if(color > 0x02)
        color = 0x00;

    memset(showData.Color_Data, 0, sizeof(showData.Color_Data));
/*
    if(color == 0x01) //单色屏
    {
       memset(showData.Color_Data, 0xFF, sizeof(showData.Color_Data));
    }
    else if(color == 0x03) //双色屏
    {
        for(i = 0; i < sizeof(showData.Color_Data); i ++)
        {
            if((i % 2) == 0)
                showData.Color_Data[i] = 0xFF;
        }
    }
    else if(color == 0x07) //三色屏
    {
        for(i = 0; i < sizeof(showData.Color_Data); i ++)
        {
            if((i % 3) == 0)
                showData.Color_Data[i] = 0xFF;
        }
    }
    */
    setMouseTracking(true);
    mousePressed = false;
    focusFlag = false;
    updateFlag = false;
    filePara.Temp_Para.Flag = SHOW_NULL;

    fileItem = (QTreeWidgetItem *)0;
    areaItem = (QTreeWidgetItem *)0;
    screenItem = (QTreeWidgetItem *)0;

    previewFlag = 0; //不是预览窗口

    QPalette palette(QPalette::Base,QColor(Qt::black));
    setPalette(palette);//->setPalette(palette);
    setAutoFillBackground(true);
}

void CshowArea::clrShowData()
{
  memset(showData.Color_Data, 0, sizeof(showData.Color_Data));
}

//设置分区类型,0表示
void CshowArea::setAreaType(int type)
{
    areaType = type;
}

void CshowArea::mouseDoubleClickEvent(QMouseEvent *event)
{
  //debug("double click");
    INT8U type;

    type = checkItemType(w->progManage->getCurItem());

    //文本类型
    if(type == PIC_STEXT_PROPERTY || type == PIC_MTEXT_PROPERTY || type == PIC_TABLE_PROPERTY)
    {
      w->property->picProperty->edit->showInit();
    }
}

void CshowArea::mousePressEvent(QMouseEvent *event)
{

    int x0,y0;
    int x1,y1;

    //debug("press click");

    if(areaType == 0)//背景屏幕不响应
        return;

    x0 = event->x();
    y0 = event->y();
    x1 = width();
    y1 = height();

    if(x0 >5 && x0 < x1 - 5 && y0 > 5 && y0 < y1 -5)
    {
       setCursor(Qt::ClosedHandCursor);
    }
    //draw_point(x0,y0,0);
    //qDebug("mousepress, x0 = %d,y0 = %d, x1 = %d, y1 = %d", x0,y0,x1,y1);
    mousePressed = true; //鼠标被按下
    //setCursor(Qt::ClosedHandCursor);
    framePosition = frameGeometry().topLeft();
    dragPosition = event->globalPos();// - frameGeometry().topLeft();
    oldSize = size();

    event->accept();
    //w->screenArea->setFocusArea(this);
    //if(w->screenArea !=)
    //更新当前的screenArea!!
    w->screenArea = (CscreenArea *)this->parent();

    if(this->areaItem != 0)
    {/*
        if(areaItem == w->progManage->treeWidget->currentItem())
        {
          //w->progManage->clickItem(treeItem, 0);
          return;
        }
        */
/*
        QString str;
        str = this ->areaItem->data(0, Qt::UserRole).toString();

        settings.beginGroup(str);
        int subIndex = settings.value("subIndex").toInt();
        settings.endGroup();
*/
        QTreeWidgetItem *fileItem = this->fileItem;
        //QTreeWidgetItem *areaItem = this->areaItem;
        if(fileItem != (QTreeWidgetItem *)0)
        {
            //QTreeWidgetItem *item = areaItem->child(subIndex-1);
            //w->progManage->clickItem(fileItem, 0);
            w->progManage->treeWidget->setCurrentItem(fileItem);
        }
        else //if(areaItem != (QTreeWidgetItem *)0)
        {
            //w->progManage->clickItem(areaItem, 0);
            w->progManage->treeWidget->setCurrentItem(areaItem);
        }
        //else
            //ASSERT_FAILED();
    }
/*
    CshowArea *oldArea = w->screenArea->getFocusArea();
    if(oldArea != this)
    {
       w->screenArea->setFocusArea(this);
       w->progManage->treeWidget->setCurrentItem(this->areaItem); //treewidget设置为当前显示项目

       this->update();//重绘
       this->raise();//置于顶部
       if(oldArea != (CshowArea *)0)
        oldArea->update();
    }
    */
    //qDebug("mousePressEvent");
}

//鼠标松开
void CshowArea::mouseReleaseEvent(QMouseEvent *event)
{

    int x,y,width,height;
    QString str;

    mousePressed = false; //鼠标松开
    setCursor(Qt::ArrowCursor);
    if(areaType == 1) //分区
    {
        x = frameGeometry().topLeft().x();
        y = frameGeometry().topLeft().y();
        width = frameGeometry().width();
        height = frameGeometry().height();

        //qDebug("release x=%d,y=%d,width=%d,height=%d",x,y,width,height);
        //记录下当前区域的位置等
        if(areaItem != (QTreeWidgetItem *)0)
        {
            str = areaItem->data(0, Qt::UserRole).toString();
            settings.beginGroup(str);
            settings.setValue("x", x);
            settings.setValue("y", y);
            settings.setValue("width", width);
            settings.setValue("height", height);
            settings.endGroup();
        }
    }
    //qDebug("mouseReleaseEvent");
}

void CshowArea::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point = pos();
    int width,height;
    QRect rect, rect1,rect2;
    int x,y;
    int x0,y0;
    int x1,y1;


    if(areaType EQ 0)
        return;

    if(this != w->screenArea->getFocusArea()) //当前不是焦点分区
    {
      mousePressed = false;
      dragFlag = 0;
      setCursor(Qt::ArrowCursor);
      return;
    }

    x0 = event->x();
    y0 = event->y();

    x1 = this->width();
    y1 = this->height();

    rect2 = parentWidget()->geometry();

/*
    qDebug("gloabal pos x = %d, y = %d, frame toleft x= %d, y = %d",
           event->globalPos().x(),event->globalPos().y(),
           frameGeometry().topLeft().x(), frameGeometry().topLeft().y());
*/
  //((CscreenArea *)parent())->setFocusArea(this);

    if(mousePressed == false)
    {
        if(x0 > x1 -5 && y0 > y1 - 5) //鼠标在右下角度
        {
            setCursor(Qt::SizeFDiagCursor);
            dragFlag = DRAG_RD;
        }
        else if(x0 > x1 -5 && y0 < 5) //鼠标右上角度
        {
            setCursor(Qt::SizeBDiagCursor);
            dragFlag = DRAG_RU;
        }
        else if(x0 < 5 && y0 > y1 -5) //左下角
        {
            setCursor(Qt::SizeBDiagCursor);
            dragFlag = DRAG_LD;
        }
        else if(x0 < 5 && y0 < 5) //左上角读
        {
            setCursor(Qt::SizeFDiagCursor);
            dragFlag = DRAG_LU;
        }
        else if(x0 > x1 - 5) //鼠标在右边线附近
        {
            setCursor(Qt::SizeHorCursor);
            dragFlag = DRAG_R;

        }
        else if(x0 < 5) //左边
        {
            setCursor(Qt::SizeHorCursor);
            dragFlag = DRAG_L;
        }
        else if(y0 > y1 - 5)//鼠标在下边线附近
        {
            setCursor(Qt::SizeVerCursor);
            dragFlag = DRAG_D;
        }
        else if(y0 < 5) //上边线
        {
            setCursor(Qt::SizeVerCursor);
            dragFlag = DRAG_U;
        }
        else
        {

            //if(mousePressed == true)
            {
                dragFlag = DRAG_MOVE;
            }
            //else
            {
              setCursor(Qt::ArrowCursor);
            }
        }
    }


    if(mousePressed == false)
        return;

    //qDebug("enter!!!");

    rect = geometry();

    if(dragFlag == DRAG_MOVE) //移动
    {
        if(event->buttons() & Qt::LeftButton)
        {
            QPoint posi;
            posi = framePosition + event->globalPos() - dragPosition;
            //move(framePosition + event->globalPos() - dragPosition);
            if(posi.x() < 0)
                posi.setX(0);
            if(posi.y() < 0)
                posi.setY(0);
            if(posi.x() + this->width() > rect2.width())
               posi.setX(rect2.width() - this->width());
            if(posi.y() + this->height() > rect2.height())
                posi.setY(rect2.height() - this->height());

            move(posi);

        }

    }
    else if(dragFlag == DRAG_R) //右
    {
       //resize(event->x() + 4, height());
        //使其不越右边界
        if(frameGeometry().topLeft().x() + oldSize.width() + event->globalPos().x() - dragPosition.x() > rect2.width())
            width = rect2.width() - frameGeometry().topLeft().x();// oldSize.height();//resize(rect2.width() - frameGeometry().topLeft().x(), oldSize.height());
        else
            width = oldSize.width() + event->globalPos().x() - dragPosition.x();

        updateFlag = true;
        if(width < MIN_AREA)
            width = MIN_AREA;
        resize(width, oldSize.height());
    }
    else if(dragFlag == DRAG_RD)//右下拉伸
    {

        if(frameGeometry().topLeft().x() + oldSize.width() + event->globalPos().x() - dragPosition.x() > rect2.width())
            width = rect2.width() - frameGeometry().topLeft().x(); //oldSize.height();//resize(rect2.width() - frameGeometry().topLeft().x(), oldSize.height());
        else
            width = oldSize.width() + event->globalPos().x() - dragPosition.x();

        if(frameGeometry().topLeft().y() + oldSize.height() + event->globalPos().y() - dragPosition.y() > rect2.height())
            height = rect2.height() - frameGeometry().topLeft().y();// oldSize.height();//resize(rect2.width() - frameGeometry().topLeft().x(), oldSize.height());
        else
            height = oldSize.height() + event->globalPos().y() - dragPosition.y();

        if(width < MIN_AREA)
            width = MIN_AREA;

        if(height < MIN_AREA)
            height = MIN_AREA;

        updateFlag = true;
        resize(width,height);
    }
    else if(dragFlag == DRAG_RU) //右上
    {
        if(framePosition.y() + event->globalPos().y() - dragPosition.y() < 0)
        {
           y = 0;
           height = framePosition.y() + oldSize.height();
        }
        else if(event->globalPos().y() - dragPosition.y() > oldSize.height() - MIN_AREA)
        {
           y = framePosition.y() +oldSize.height() - MIN_AREA;
           height = MIN_AREA;
        }
        else
        {
           y = framePosition.y() + event->globalPos().y() - dragPosition.y();
           height = oldSize.height() - event->globalPos().y() + dragPosition.y();
        }
        //move(framePosition.x(),y);//framePosition.y() + event->globalPos().y() - dragPosition.y());

        if(frameGeometry().topLeft().x() + oldSize.width() + event->globalPos().x() - dragPosition.x() > rect2.width())
            width = rect2.width() - frameGeometry().topLeft().x(); //oldSize.height();//resize(rect2.width() - frameGeometry().topLeft().x(), oldSize.height());
        else
            width = oldSize.width() + event->globalPos().x() - dragPosition.x();

        updateFlag = true;

        if(width < MIN_AREA)
            width = MIN_AREA;

        if(height < MIN_AREA)
            height = MIN_AREA;

        move(framePosition.x(),y);
        resize(width, height);
    }
    else if(dragFlag == DRAG_D) //垂直向下拉伸
    {
        //resize(width(), event ->y() + 4);
        if(framePosition.y() + oldSize.height() + event->globalPos().y() - dragPosition.y() < rect2.height())
          height = oldSize.height() + event->globalPos().y() - dragPosition.y();
        else
          height = rect2.height() - framePosition.y();

        updateFlag = true;
        if(height < MIN_AREA)
            height = MIN_AREA;
        resize(oldSize.width(), height);
    }
    else if(dragFlag == DRAG_U) //垂直向上拉伸
    {
        if(framePosition.y() + event->globalPos().y() - dragPosition.y() < 0)
        {
           y = 0;
           height = framePosition.y() + oldSize.height();
        }
        else
        {
           y = framePosition.y() + event->globalPos().y() - dragPosition.y();
           height = oldSize.height() - event->globalPos().y() + dragPosition.y();
        }

        updateFlag = true;
        if(height < MIN_AREA)
            height = MIN_AREA;
        move(framePosition.x(),y);
        resize(oldSize.width(), height);
    }
    else if(dragFlag == DRAG_L) //左
    {
        if(framePosition.x() + event->globalPos().x() - dragPosition.x() < 0)
        {
           x = 0;
           width = framePosition.x() + oldSize.width();
        }
        else if(event->globalPos().x() - dragPosition.x() > oldSize.width() - MIN_AREA)
        {
           x = framePosition.x() + oldSize.width()-MIN_AREA;
           width = MIN_AREA;
        }
        else
        {
           x = framePosition.x() + event->globalPos().x() - dragPosition.x();
           width = oldSize.width() - event->globalPos().x() + dragPosition.x();
       }

        updateFlag = true;
        //if(width < MIN_AREA)
            //width = MIN_AREA;

        //setGeometry(x,framePosition.y(),width,oldSize.height());
        move(x,framePosition.y());
        resize(width, oldSize.height());

        //qDebug("old x = %d, width = %d, new x = %d, width = %d",framePosition.x(), oldSize.width(), x, width);

    }
    else if(dragFlag == DRAG_LD)//左下拉伸
    {
        if(framePosition.x() + event->globalPos().x() - dragPosition.x() < 0)
        {
           x = 0;
           width = framePosition.x() + oldSize.width();
        }
        else if(event->globalPos().x() - dragPosition.x() > oldSize.width() - MIN_AREA)
        {
           x = framePosition.x() + oldSize.width()-MIN_AREA;
           width = MIN_AREA;
        }
        else
        {
           x = framePosition.x() + event->globalPos().x() - dragPosition.x();
           width = oldSize.width() - event->globalPos().x() + dragPosition.x();
        }

        if(framePosition.y() + oldSize.height() + event->globalPos().y() - dragPosition.y() < rect2.height())
          height = oldSize.height() + event->globalPos().y() - dragPosition.y();
        else
          height = rect2.height() - framePosition.y();

        updateFlag = true;
        if(width < MIN_AREA)
            width = MIN_AREA;

        if(height < MIN_AREA)
            height = MIN_AREA;
        move(x, framePosition.y());
        resize(width,height);
    }
    else if(dragFlag == DRAG_LU) //左上
    {

        if(framePosition.x() + event->globalPos().x() - dragPosition.x() < 0)
        {
           x = 0;
           width = framePosition.x() + oldSize.width();
        }
        else if(event->globalPos().x() - dragPosition.x() > oldSize.width() - MIN_AREA)
        {
           x = framePosition.x() + oldSize.width()-MIN_AREA;
           width = MIN_AREA;
        }
        else
        {
           x = framePosition.x() + event->globalPos().x() - dragPosition.x();
           width = oldSize.width() - event->globalPos().x() + dragPosition.x();
        }

        if(framePosition.y() + event->globalPos().y() - dragPosition.y() < 0)
        {
           y = 0;
           height = framePosition.y() + oldSize.height();
        }
        else if(event->globalPos().y() - dragPosition.y() > oldSize.height() - MIN_AREA)
        {
           y = framePosition.y() +oldSize.height() - MIN_AREA;
           height = MIN_AREA;
        }
        else
        {
           y = framePosition.y() + event->globalPos().y() - dragPosition.y();
           height = oldSize.height() - event->globalPos().y() + dragPosition.y();
        }

        updateFlag = true;
        if(width < MIN_AREA)
            width = MIN_AREA;

        if(height < MIN_AREA)
            height = MIN_AREA;
        move(x,y);
        resize(width,height);
    }
    event->accept();

    rect1 = geometry();
    //qDebug("get x = %d, width = %d",rect1.x(), rect1.width());

    //更新当前显示的property的分区大小数据
    if(w->property->area != (Carea *)0) {
        w->property->area->updateRect(rect1);
    }

    //rect1 = geometry();
    //qDebug("setFlag = %d, aft geometry x=%d, y=%d, width=%d, height=%d",setFlag, rect1.x(),rect1.y(),rect1.width(),rect1.height());
}

void CshowArea::paintEvent(QPaintEvent *)
{
    int i,j;
    int color;
    unsigned char colorData;
    QString str;
    S_Point P0;
    INT8U Area_No = 0;
    INT16U Width,Height;//,Min_Width, Min_Height;
    //INT16S tmp;
    S_Screen_Para Screen_Para_Bak;
    S_Prog_Para Prog_Para_Bak;
    int borderHeight = 0;

    //return;

    saveScreenPara(Screen_Para_Bak);
    saveProgPara(Prog_Para_Bak);

    //screenPara.Base_Para.Color = Screen_Para.Base_Para.Color;//分区的颜色应该和屏幕颜色保持一致.修改屏幕参数时不会刷新分区颜色

    resetShowPara(geometry().width(), geometry().height(), screenPara.Base_Para.Color);
    Calc_Screen_Color_Num();
    painter.begin(this);

    color =getColor();

    Width = width();
    Height = height();

    if(areaType != 0)//0表示是分区
    {
        if(filePara.Pic_Para.Border_Check > 0)
        {
            borderHeight = filePara.Pic_Para.Border_Height;//Get_Simple_Border_Height(filePara.Pic_Para.Border_Type);

            Width = Width - borderHeight*2;
            Height = Height - borderHeight*2;
        }

    if(updateFlag == true)//鼠标在没有按下的情况下才更新数据
    {
       updateFlag = 0;
       Clear_Area_Data(&Show_Data, 0);
       Clear_Area_Data(&Show_Data_Bak, 0);
        //memset(Show_Data.Color_Data, 0, sizeof(Show_Data.Color_Data));
        //memset(Show_Data_Bak.Color_Data, 0, sizeof(Show_Data_Bak.Color_Data));
        if(filePara.Temp_Para.Flag == SHOW_CLOCK) //显示表盘
        {
            Get_Cur_Time();
            //Cur_Time.Time[T_SEC] = 0x00;
            //将背景文字放到Show_Data_Bak中

            QSize size = imageBk.size();

            filePara.Clock_Para.Text_Width = size.width();
            filePara.Clock_Para.Text_Height = size.height();

            Get_Clock_Text_Point(Width, Height, &filePara.Clock_Para, &P0);
            //此处不可对filePara.Clock_Para.Text_X、filePara.Clock_Para.Text_Y直接复制，否则会导致移位
            //filePara.Clock_Para.Text_X = P0.X;
            //filePara.Clock_Para.Text_Y = P0.Y;

            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

            getTextShowData(imageBk, &Show_Data_Bak, P0.X + borderHeight, P0.Y + borderHeight);

            Set_Area_Border_Out(Area_No);
            Update_Clock_Point(&Show_Data_Bak, 0);
            Update_Clock_Data(&Show_Data_Bak, 0);
            Set_Area_Border_In(Area_No);
            memcpy(&Show_Data, &Show_Data_Bak, sizeof(Show_Data_Bak));
        }
        else if(filePara.Temp_Para.Flag == SHOW_PIC) //显示图文
        {
            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));
            int lineNum = 0;
            int pageNum = 0;

            QImage image;

            if(editMode EQ 0)
            {
                if(moveFlag != MOVE_LEFT_CONTINUOUS)
                {
                    image = getTextImage(Width, picStr, &lineNum, linePosi);
                    pageNum = getTextPageNum(smLineFlag, moveFlag, image.height(), Width, Height, lineNum, linePosi, pagePosi);
                    if(page >= pageNum)
                      page = pageNum - 1;
                    imageBk = getTextPageImage(smLineFlag, image, Width, Height, page, pagePosi);
                }
                else
                {
                    pageNum = getSLineTextPageNum(picStr, Width);
                    if(page >= pageNum)
                      page = pageNum - 1;
                    imageBk = getSLineTextImage(picStr, Width,Height,page);
                }
            }
            else //表格编辑方式
            {
               image = getTableImage(Width, Height, picStr, &pageNum);
               if(page >= pageNum)
                 page = pageNum - 1;
               imageBk = getTablePageImage(image, Width, Height, page);
            }
            //getTextPageNum(area->smLineFlag, area->width(), area->height(), lineNum, linePosi, pagePosi);

            getTextShowData(imageBk, &Show_Data, borderHeight, borderHeight);

            if(w->property->picProperty)
            {
                w->property->picProperty->pageBox->setMaximum(pageNum > 0?pageNum:1);
                w->property->picProperty->muLabel->setText(QString("/") + QString::number(w->property->picProperty->pageBox->maximum()) + tr("幕"));
            }
        }
        else if(filePara.Txt_Para.Flag == SHOW_TXT)
        {
            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

            //INT16U Read_Txt_Show_Data(S_Show_Data *pDst, INT8U Area_No, U_File_Para *pPara, INT8U Data[], INT16U Data_Len, INT8U SCN_No)
            //Set_Area_Border_Out(Area_No);
            Read_Txt_Show_Data(&Show_Data, Area_No, (S_Txt_Para *)&Prog_Status.File_Para[0].Txt_Para, this->txtData, strlen((char *)(this->txtData)), this->page, RD_TXT_NORMAL_FLAG, 0, 0);
            //Set_Area_Border_In(Area_No);
            if(w->property->txtProperty)
            {
              w->property->txtProperty->simpleTextEdit->pageBox->setMaximum(Prog_Status.File_Para[0].Txt_Para.SNum == 0 ? 1:Prog_Status.File_Para[0].Txt_Para.SNum);
              w->property->txtProperty->simpleTextEdit->muLabel->setText(QString("/") + QString::number(w->property->txtProperty->simpleTextEdit->pageBox->maximum()) + tr("幕"));
          }
        }
        else if(filePara.Temp_Para.Flag == SHOW_TIME)
        {
            Get_Cur_Time();

            //将背景文字放到Show_Data_Bak中

            QSize size = imageBk.size();

            filePara.Time_Para.Text_Width = size.width();
            filePara.Time_Para.Text_Height = size.height();

            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

            Get_Time_Text_Point(Area_No, Width, Height, P0);
            //Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Status.File_Para[Area_No].Time_Para.Text_Width, Prog_Status.File_Para[Area_No].Time_Para.Text_Height, &Show_Data, &P0);//&Point);

            getTextShowData(imageBk, &Show_Data_Bak, P0.X + borderHeight, P0.Y + borderHeight);
            Set_Area_Border_Out(Area_No);
            Update_Time_Data(&Show_Data_Bak, Area_No);
            Set_Area_Border_In(Area_No);
            memcpy(&Show_Data, &Show_Data_Bak, sizeof(Show_Data_Bak));
        }
        else if(filePara.Temp_Para.Flag == SHOW_TIMER) //计时器
        {
            Get_Cur_Time();

            //将背景文字放到Show_Data_Bak中

            QSize size = imageBk.size();

            filePara.Timer_Para.Text_Width = size.width();
            filePara.Timer_Para.Text_Height = size.height();

            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));
/*
            Min_Width = Get_Timer_Min_Width(Area_No);
            Min_Height = Get_Timer_Min_Height(Area_No);

            if(Prog_Status.File_Para[Area_No].Timer_Para.SmLineFlag == SLINE_MODE)//单行
            {
              if(Width > Min_Width)
                P0.X = (Width - Min_Width) / 2;
              else
                P0.X = 0;

              if(Height > Prog_Status.File_Para[Area_No].Timer_Para.Text_Height)
                P0.Y = (Height - Prog_Status.File_Para[Area_No].Timer_Para.Text_Height)/2;
              else
                P0.Y = 0;//(Height - Prog_Status.File_Para[Area_No].Timer_Para.Text_Height)/2;
            }
            else
            {
                if(Height > Min_Height)
                  P0.Y = (Height - Min_Height) / 2;
                else
                  P0.Y = 0;

                if(Width > Prog_Status.File_Para[Area_No].Timer_Para.Text_Width)
                  P0.X = (Width - Prog_Status.File_Para[Area_No].Timer_Para.Text_Width)/2;
                else
                  P0.X = 0;//(Height - Prog_Status.File_Para[Area_No].Timer_Para.Text_Height)/2;
            }
*/
            Get_Timer_Text_Point(Area_No, Width, Height, P0);

            //Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Status.File_Para[Area_No].Timer_Para.Text_Width, Prog_Status.File_Para[Area_No].Timer_Para.Text_Height, &Show_Data, &P0);//&Point);
            getTextShowData(imageBk, &Show_Data_Bak, P0.X + borderHeight, P0.Y + borderHeight);
            Set_Area_Border_Out(Area_No);
            Update_Timer_Data(&Show_Data_Bak, Area_No);
            Set_Area_Border_In(Area_No);
            memcpy(&Show_Data, &Show_Data_Bak, sizeof(Show_Data_Bak));
        }
        else if(filePara.Temp_Para.Flag == SHOW_LUN) //显示农历
        {
            Get_Cur_Time();

            //将背景文字放到Show_Data_Bak中

            QSize size = imageBk.size();

            filePara.Lun_Para.Text_Width = size.width();
            filePara.Lun_Para.Text_Height = size.height();

            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

            //Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Status.File_Para[Area_No].Lun_Para.Text_Width, Prog_Status.File_Para[Area_No].Lun_Para.Text_Height, &Show_Data, &P0);//&Point);
            Get_Lun_Text_Point(Area_No, Width, Height, P0);

            getTextShowData(imageBk, &Show_Data_Bak, P0.X + borderHeight, P0.Y + borderHeight);
            Set_Area_Border_Out(Area_No);
            Update_Lun_Data(&Show_Data_Bak, Area_No);
            Set_Area_Border_In(Area_No);
            memcpy(&Show_Data, &Show_Data_Bak, sizeof(Show_Data_Bak));
        }
        else if(filePara.Temp_Para.Flag == SHOW_FLASH) //显示动画
        {
            P0.X = P0.Y = 0;
            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));
            QImage image = imageBk.scaled(Width*xProportion/100,Height*yProportion/100);//size());            
            getFlashShowData(image, &Show_Data, Area_No, \
                             P0.X + borderHeight + (Width - image.width()) / 2,\
                             P0.Y + borderHeight + (Height - image.height()) / 2);
            //Update_Lun_Data(Area_No);
        }
        else if(filePara.Temp_Para.Flag == SHOW_IMAGE) //显示图片
        {
            P0.X = P0.Y = 0;
            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));
            QImage image = imageBk.scaled(Width*xProportion/100,Height*yProportion/100);//size());
            getImageShowData(image, &Show_Data, Area_No, \
                             P0.X + borderHeight + (Width - image.width()) / 2,\
                             P0.Y + borderHeight + (Height - image.height()) / 2);
        }
        else if(filePara.Temp_Para.Flag == SHOW_TEMP) //显示温度
        {
            QSize size = imageBk.size();

            filePara.Temp_Para.Text_Width = size.width();
            filePara.Temp_Para.Text_Height = size.height();

            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

            Get_Temp_Text_Point(Area_No, Width, Height, P0);

            getTextShowData(imageBk, &Show_Data_Bak, P0.X + borderHeight, P0.Y + borderHeight);
            Set_Area_Border_Out(Area_No);
            Update_Temp_Data(&Show_Data_Bak, Area_No);
            Set_Area_Border_In(Area_No);
            memcpy(&Show_Data, &Show_Data_Bak, sizeof(Show_Data_Bak));
        }
        else if(filePara.Temp_Para.Flag == SHOW_HUMIDITY) //显示温度
        {
            QSize size = imageBk.size();

            filePara.Humidity_Para.Text_Width = size.width();
            filePara.Humidity_Para.Text_Height = size.height();

            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

            Get_Humidity_Text_Point(Area_No, Width, Height, P0);

            getTextShowData(imageBk, &Show_Data_Bak, P0.X + borderHeight, P0.Y + borderHeight);
            Set_Area_Border_Out(Area_No);
            Update_Humidity_Data(&Show_Data_Bak, Area_No);
            Set_Area_Border_In(Area_No);
            memcpy(&Show_Data, &Show_Data_Bak, sizeof(Show_Data_Bak));
        }
        else if(filePara.Temp_Para.Flag == SHOW_NOISE) //显示温度
        {
            QSize size = imageBk.size();

            filePara.Noise_Para.Text_Width = size.width();
            filePara.Noise_Para.Text_Height = size.height();

            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

            Get_Noise_Text_Point(Area_No, Width, Height, P0);

            getTextShowData(imageBk, &Show_Data_Bak, P0.X + borderHeight, P0.Y + borderHeight);
            Set_Area_Border_Out(Area_No);
            Update_Noise_Data(&Show_Data_Bak, Area_No);
            Set_Area_Border_In(Area_No);
            memcpy(&Show_Data, &Show_Data_Bak, sizeof(Show_Data_Bak));
        }

        if(filePara.Pic_Para.Border_Check > 0)
        {
            //filePara.Pic_Para.Border_Mode = 0; //静态
            //INT8U Border_Mode = 0;//filePara.Pic_Para.Border_Mode;
            //INT8U Type = Prog_Status.File_Para[Area_No].Pic_Para.Border_Type;

            //S_Simple_Border_Data *p = Get_Simple_Border_Info(Prog_Status.File_Para[Area_No].Pic_Para.Border_Type);
            //INT16U Border_Width = this->filePara.Pic_Para.Border_Width;//p->Width;//Get_Area_Border_Width(Area_No);
            //INT16U Border_Height = this->filePara.Pic_Para.Border_Height;//Get_Area_Border_Height(Area_No);
            //INT8U *pBorder_Data = ;//(INT8U *)(p->Data);

            Draw_Border(&Show_Data, 0, this->borderData,0,1);
        }

        memcpy(showData.Color_Data, Show_Data.Color_Data, sizeof(Show_Data.Color_Data));
    }

   Width = Width + borderHeight*2;
   Height = Height + borderHeight*2;

    for(j=0; j<Height; j++)
    {
        for(i=0; i<Width; i++)
        {
           //colorData = Get_Area_Point_Data(&Show_Data, 0, i, j);
           colorData = Get_Area_Point_Data(&showData, 0, i, j);
            //if(colorData != 0)
              //qDebug("point %d,%d = %d", i, j, colorData);
           if(colorData > 0)
           {
             painter.setPen(getQColor(colorData));
             painter.drawPoint(i,j);
           }
           else
           {

           }
           /*
           if(colorData & 0x01)
           {
               painter.setPen(QColor(Qt::red));
               painter.drawPoint(i,j);
           }
           else if(colorData & 0x02)
           {
               painter.setPen(QColor(Qt::green));
               painter.drawPoint(i,j);
           }
           else if(colorData & 0x04)
           {
               painter.setPen(QColor(Qt::yellow));
               painter.drawPoint(i,j);

           }
           else
           {
               painter.setPen(QColor(Qt::black));
               painter.drawPoint(i,j);
           }
           */
       }
       //if(filePara.Pic_Para.Border_Check EQ 0)
        {
            if(focusFlag == true) //当前分区是焦点
            {
                QPen pen;
                pen.setColor(QColor(Qt::white));
                pen.setStyle(Qt::DotLine);
                painter.setPen(pen);
              painter.drawRect(0, 0, geometry().width() - 1, geometry().height() - 1);
            }
            else
            {
                QPen pen;
                pen.setColor(QColor(Qt::darkGray));
                pen.setStyle(Qt::DotLine);
                painter.setPen(pen);
                //painter.setPen(QColor(Qt::darkGray));
                painter.drawRect(0, 0, geometry().width()-1, geometry().height()-1);
            }
        }

      }
    }
    else //非0表示是背景
    {
        if(updateFlag == true)//鼠标在没有按下的情况下才更新数据
         {
            Clear_Area_Data(&Show_Data, 0);
            updateFlag = 0;
            memcpy(&Prog_Para, &progPara, sizeof(progPara));

            if(Prog_Para.Border_Check)
            {
               Draw_Border(&Show_Data, MAX_AREA_NUM, borderData, 0,1);
            }
            memcpy(showData.Color_Data, Show_Data.Color_Data, sizeof(Show_Data.Color_Data));

        }

        //unsigned char colorData;
        for(i=0; i<Width; i++)
        {
            for(j=0; j<Height; j++)
            {
                //colorData = Get_Area_Point_Data(&Show_Data, MAX_AREA_NUM, i, j);
                colorData = Get_Area_Point_Data(&showData, MAX_AREA_NUM, i, j);

                if(colorData > 0)
                {
                    painter.setPen(getQColor(colorData));
                    painter.drawPoint(i,j);
                }
                else
                {
                    //painter.setPen(QColor(Qt::black));
                    //painter.drawPoint(i,j);
                }
              }
           }
        }



    //lpArea = w->screenArea->getFocusArea();//((CscreenArea *)parentWidget)->getFocusArea(); //w->screenArea->getFocusArea();



    //painter.setPen(QColor(Qt::yellow));
    //painter.drawRect(0, 0, geometry().width()-1, geometry().height()-1);
    painter.end();

    restoreScreenPara(Screen_Para_Bak);
    restoreProgPara(Prog_Para_Bak);
}

void CshowArea::draw_point(int x,int y, int value)
{
    QPainter *painter;

    painter = new QPainter(this);
    painter->begin(this); // impossible - paint device cannot be 0
    painter->setPen(QColor(Qt::red));
    painter->drawPoint(x,y);
    painter->end();
}

//重置节目和屏幕参数，为了显示用
void resetShowPara(int width, int height, int color)
{
    Screen_Para.Base_Para.Width = width;//geometry().width();
    Screen_Para.Base_Para.Height = height;//geometry().height();
    Screen_Para.Base_Para.Color = color;//0x07;//getColor();---yanse bu bianhua

    Prog_Para.Area_Num = 1;
    Prog_Para.Area[0].X = 0;
    Prog_Para.Area[0].Y = 0;
    Prog_Para.Area[0].X_Len = width;//geometry().width();
    Prog_Para.Area[0].Y_Len = height;//geometry().height();

}

QString CscreenArea::getCurrentScreenStr()
{
    QTreeWidgetItem *item = screenItem;//area->fileItem;
    if(item == (QTreeWidgetItem *)0)
    {
        ASSERT_FAILED();
        return "";
    }

    return item->data(0, Qt::UserRole).toString();
}

QString CscreenArea::getCurrentFileStr()
{
    CshowArea *area = getFocusArea();
    if(area == (CshowArea *)0)
    {
        ASSERT_FAILED();
        return "";
    }

    QTreeWidgetItem *item = area->fileItem;
    if(item == (QTreeWidgetItem *)0)
        return "";

    return item->data(0, Qt::UserRole).toString();
}

int CshowArea::getColor()
{
    return color;
}


CshowArea::~CshowArea()
{
}

void CMdiSubWindow::closeEvent(QCloseEvent *closeEvent)
{
   if(previewFlag == 0)
   {
       //this->hide();
       this->showMinimized();
       //将当前项目设置为0，因为在clickItem函数判定中，如果和前次项一致
       //则不做操作，这样导致screen不会显示，因此将当前项目设置为0！！！
       //下次点击同样项时，会显示当前显示屏
       w->progManage->saveCurItem((QTreeWidgetItem *)0xFFFFFFFF);
       closeEvent->ignore();
   }
   else
   {
       Mem_Close();

       w->timer->stop();
       w->mmtimer->stop();
       //disconnect(w->progManage->timer,SIGNAL(timeout()),w->progManage,SLOT(previewProc()));
       closeEvent->accept();

   }
}

CMdiSubWindow::CMdiSubWindow(QWidget *parent):QMdiSubWindow(parent,0)
{
    Qt::WindowFlags flags = Qt::Window|Qt::WindowMinimizeButtonHint;

    previewFlag = 0;
    setWindowFlags(flags); // 设置禁止最大化
}

CMdiSubWindow::~CMdiSubWindow()
{

}

void CpreviewWin::closeEvent(QCloseEvent *closeEvent)
{/*
   if(previewFlag == 0)
   {
       this->hide();

       //将当前项目设置为0，因为在clickItem函数判定中，如果和前次项一致
       //则不做操作，这样导致screen不会显示，因此将当前项目设置为0！！！
       //下次点击同样项时，会显示当前显示屏
       w->progManage->saveCurItem(0);
       closeEvent->ignore();
   }
   else*/
   {
       Mem_Close();

       w->timer->stop();
       w->mmtimer->stop();
       //disconnect(w->progManage->timer,SIGNAL(timeout()),w->progManage,SLOT(previewProc()));
       closeEvent->accept();

   }
}

CpreviewWin::CpreviewWin(QWidget *parent):QMainWindow(parent)
{
    Qt::WindowFlags flags = Qt::Window|Qt::WindowMinimizeButtonHint;

    //previewFlag = 0;
    setWindowFlags(flags); // 设置禁止最大化
}

CpreviewWin::~CpreviewWin()
{

}
