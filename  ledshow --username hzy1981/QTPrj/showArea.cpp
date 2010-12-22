#include "..\Includes.h"
#include "showArea.h"
#include "mainwindow.h"
#include <QPainter>
#include <QTreeWidgetItem>

extern MainWindow *w;
extern QSettings settings;

extern int linePosi[MAX_LINE_NUM];
extern int pagePosi[MAX_LINE_NUM];
//背景区域构造函数
CscreenArea::CscreenArea(QWidget *parent):CshowArea(parent,BLUE)
{
    int i,xLen,yLen;
    QStringList str;

    for(i = 0; i < MAX_AREA_NUM; i ++)
    {
     pArea[i] = newShowArea();
     pArea[i]->setVisible(0);
     //areaUsed[i] = 0;
    }

    settings.beginGroup("screen");
    str = settings.allKeys();
    if(str.isEmpty() == false)
    {
        xLen = settings.value("xLen").toInt();
        yLen = settings.value("yLen").toInt();
        color = settings.value("color").toInt();

        if(xLen*yLen > MAX_POINTS)
        {
          xLen = 256;
          yLen = 256;

          settings.setValue("xLen", xLen);
          settings.setValue("yLen", yLen);
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

        settings.setValue("xLen", xLen);
        settings.setValue("yLen", yLen);
        settings.setValue("color", 0x07);
    }

    resize(xLen, yLen);

    settings.endGroup();
    setAreaType(0);
}

//根据settings对某个节目的分区进行初始化
void CscreenArea::progSettingsInit(QTreeWidgetItem *item)
{
    int areaNum = 0,subIndex;
    QStringList areaGroups;
    QString areaStr;
    QString str;

    str = item->data(0, Qt::UserRole).toString();

   settings.beginGroup(str);
   subIndex = settings.value("subIndex").toInt(); //焦点分区
   settings.endGroup();

   settings.beginGroup(str + "/area/");

   //areaGroups = str + "/area/";
   if(settings.value("type").toInt() == PROG_PROPERTY)
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
   w->screenArea->treeItem = item; //背景区域对应该项
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
        xLen = settings.value("xLen").toInt();
        yLen = settings.value("yLen").toInt();
    }
    else
    {
        ASSERT_FAILED();
        qDebug("areaSettingsInit Error");

        x = 0;//256;
        y = 0;
        xLen = 256;
        yLen = 256;

        settings.setValue("x", x);
        settings.setValue("y", y);
        settings.setValue("xLen", xLen);
        settings.setValue("yLen", yLen);
        //qDebug("seeOneAreaVisible Error")
        //return;
    }

    qDebug("x=%d,y=%d,xLen=%d,yLen=%d",x,y,xLen,yLen);
    index = settings.value("index").toInt();
    subIndex= settings.value("subIndex").toInt(); //子文件索引
    settings.endGroup();

    if(index < MAX_AREA_NUM)
    {
        pArea[index] -> setVisible(1);
        pArea[index]->treeItem = item; //背景区域对应该项
        pArea[index]->fileItem = (QTreeWidgetItem *)0; //还没有绑定一个文件

        pArea[index]->filePara.Time_Para.Flag = 0;

        w->screenArea->setFocusArea(pArea[index]);
        pArea[index]->move(x, y);
        pArea[index]->resize(xLen,yLen);

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
    QString str = item->data(0, Qt::UserRole).toString();
    settings.beginGroup(str);
    int type = settings.value("type").toInt();
    settings.endGroup();

    //索引在父路径中
    str = item->parent()->data(0, Qt::UserRole).toString();
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
    //area->treeItem = item->parent(); //父项为分区对应的item

    if(type EQ CLOCK_PROPERTY)//表盘显示更新
    {
        updateClockShowArea(area);
    }
    else if(type EQ PIC_PROPERTY)
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
    else if(type EQ FLASH_PROPERTY)
    {
        updateFlashShowArea(area);
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
        xLen = settings.value("xLen").toInt();
        yLen = settings.value("yLen").toInt();
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
        settings.setValue("xLen", xLen);
        settings.setValue("yLen", yLen);
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
            if(pArea[i] == area)
                pArea[i]->focusFlag = true;
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
void CscreenArea::updateShowArea(QTreeWidgetItem *item)
{
    int type, index;
    QString str;

    type = checkItemType(item);

    if(type == PROG_PROPERTY)
        w->screenArea->progSettingsInit(item);//  progSettingsInit(QStr);
    else if(type == AREA_PROPERTY)
    {
        if(w->screenArea->treeItem != item->parent()) //与前一个节目是否是同一个节目
        {
            w->screenArea->progSettingsInit(item->parent());
            //w->screenArea->areaSettingsInit(item);
        }
        else
          w->screenArea->areaSettingsInit(item);
    }
    else
    {
        if(w->screenArea->treeItem != item->parent()->parent())//与前一个节目是否是同一个节目
        {
            w->screenArea->progSettingsInit(item->parent()->parent());
            //w->screenArea->areaSettingsInit(item->parent());
            //w->screenArea->fileSettingsInit(item);
        }
        else
        {
          w->screenArea->areaSettingsInit(item->parent());
          //w->screenArea->fileSettingsInit(item);
       }
    }

}

//分区的初始化函数
CshowArea::CshowArea(QWidget *parent, int colorFlag):QWidget(parent)
{/*
    memset(color0, 0, sizeof(color0));
    memset(color1, 0, sizeof(color1));
    memset(color2, 0, sizeof(color2));

    if(i == RED)
        memset(color0, 0xFF, sizeof(color0));
    else if(i == GREEN)
        memset(color1, 0xFF, sizeof(color0));
    else if(i == YELLOW)
        memset(color2, 0xFF, sizeof(color0));
*/
    settings.beginGroup("screen");
    color = settings.value("color").toInt();
    settings.endGroup();

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
    filePara.Temp_Para.Flag = SHOW_NULL;

    fileItem = (QTreeWidgetItem *)0;
    treeItem = (QTreeWidgetItem *)0;
    //setAttribute(Qt::WA_StaticContents);
  //resize(100,100);
  //setText("Test");
   // Painter = new QPainter(this);
}

//设置分区类型,0表示
void CshowArea::setAreaType(int type)
{
    areaType = type;
}

void CshowArea::mousePressEvent(QMouseEvent *event)
{

    int x0,y0;
    int x1,y1;

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
    if(this->treeItem != 0)
    {
        if(treeItem == w->progManage->treeWidget->currentItem())
        {
          w->progManage->clickItem(treeItem, 0);
          return;
        }
/*
        QString str;
        str = this ->treeItem->data(0, Qt::UserRole).toString();

        settings.beginGroup(str);
        int subIndex = settings.value("subIndex").toInt();
        settings.endGroup();
*/
        QTreeWidgetItem *item = this->fileItem;

        if(item != (QTreeWidgetItem *)0)
        {
            //QTreeWidgetItem *item = treeItem->child(subIndex-1);
            w->progManage->clickItem(item, 0);
        }
        //else
            //ASSERT_FAILED();
    }
/*
    CshowArea *oldArea = w->screenArea->getFocusArea();
    if(oldArea != this)
    {
       w->screenArea->setFocusArea(this);
       w->progManage->treeWidget->setCurrentItem(this->treeItem); //treewidget设置为当前显示项目

       this->update();//重绘
       this->raise();//置于顶部
       if(oldArea != (CshowArea *)0)
        oldArea->update();
    }
    */
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

        //记录下当前区域的位置等
        if(treeItem != (QTreeWidgetItem *)0)
        {
            str = treeItem->data(0, Qt::UserRole).toString();
            settings.beginGroup(str);
            settings.setValue("x", x);
            settings.setValue("y", y);
            settings.setValue("xLen", width);
            settings.setValue("yLen", height);
            settings.endGroup();
        }
    }
    //qDebug("mouseReleaseEvent");
}

void CshowArea::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point = pos();
    //int diff;
    QRect rect, rect1,rect2;

    int x0,y0;
    int x1,y1;


    if(areaType EQ 0)
        return;

    x0 = event->x();
    y0 = event->y();
    x1 = width();
    y1 = height();
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

    rect = geometry();

    if(dragFlag == DRAG_MOVE) //移动
    {
        if(event->buttons() & Qt::LeftButton)
        {
            move(framePosition + event->globalPos() - dragPosition);
        }

    }
    else if(dragFlag == DRAG_R) //右
    {
       //resize(event->x() + 4, height());
        resize(oldSize.width() + event->globalPos().x() - dragPosition.x(), oldSize.height());
    }
    else if(dragFlag == DRAG_RD)//右下拉伸
    {
        //resize(event->x() + 4, event -> y() + 4);
        resize(oldSize.width() + event->globalPos().x() - dragPosition.x(),\
               oldSize.height() + event->globalPos().y() - dragPosition.y());
    }
    else if(dragFlag == DRAG_RU) //右上
    {
        move(framePosition.x(),framePosition.y() + event->globalPos().y() - dragPosition.y());
        resize(oldSize.width() + event->globalPos().x() - dragPosition.x(),\
               oldSize.height() - event->globalPos().y() + dragPosition.y());
    }
    else if(dragFlag == DRAG_D) //垂直拉伸
    {
        //resize(width(), event ->y() + 4);
        resize(oldSize.width(), oldSize.height() + event->globalPos().y() - dragPosition.y());
    }
    else if(dragFlag == DRAG_U) //垂直拉伸
    {
        move(framePosition.x(),framePosition.y() + event->globalPos().y() - dragPosition.y());
        resize(oldSize.width(), oldSize.height() - event->globalPos().y() + dragPosition.y());
    }
    else if(dragFlag == DRAG_L) //左
    {
        move(framePosition.x()  + event->globalPos().x() - dragPosition.x(),framePosition.y());
        resize(oldSize.width() - event->globalPos().x() + dragPosition.x(), oldSize.height());
    }
    else if(dragFlag == DRAG_LD)//左下拉伸
    {
        move(framePosition.x()  + event->globalPos().x() - dragPosition.x(),\
             framePosition.y());
        resize(oldSize.width() - event->globalPos().x() + dragPosition.x(),\
               oldSize.height() + event->globalPos().y() - dragPosition.y());
    }
    else if(dragFlag == DRAG_LU) //左上
    {
        move(framePosition.x()  + event->globalPos().x() - dragPosition.x(),\
             framePosition.y()  + event->globalPos().y() - dragPosition.y());

        resize(oldSize.width() - event->globalPos().x() + dragPosition.x(),\
               oldSize.height() - event->globalPos().y() + dragPosition.y());
    }
    event->accept();

    rect1 = geometry();
    rect2 = parentWidget()->geometry();

    //qDebug("bef geometry x=%d, y=%d, width=%d, height=%d",rect1.x(),rect1.y(),rect1.width(),rect1.height());

    int setFlag = 0;
    rect = rect1;
    if(rect1.x() < 0)
    {
        rect1.setX(0);
        rect1.setY(rect.y());
        rect1.setWidth(rect.width());
        rect1.setHeight(rect.height());
        setFlag = 1;
    }
    if(rect1.y() < 0)
    {
        //rect1.setX(rect.x());
        rect1.setY(0);
        rect1.setWidth(rect.width());
        rect1.setHeight(rect.height());
        setFlag = 1;
    }
    if(rect1.x() + rect1.width()>= rect2.width())
    {
        rect1.setX(rect2.width()-rect1.width());
        //rect1.setY(rect.y());
        rect1.setWidth(rect.width());
        rect1.setHeight(rect.height());

        setFlag = 1;
    }
    if(rect1.y() + rect1.height()>= rect2.height())
    {
        //rect1.setX(rect.x());
        rect1.setY(rect2.height()-rect1.height());
        rect1.setWidth(rect.width());
        rect1.setHeight(rect.height());
        setFlag = 1;
    }
    if(rect1.width()<10)
    {
        rect1.setWidth(10);
        setFlag = 1;
    }
    if(rect1.height()<10)
    {
        rect1.setHeight(10);
        setFlag = 1;
    }

    if(setFlag == 1)
    {
         setGeometry(rect1);

     }

    w->property->area->updateRect(rect1);
    //rect1 = geometry();
    //qDebug("setFlag = %d, aft geometry x=%d, y=%d, width=%d, height=%d",setFlag, rect1.x(),rect1.y(),rect1.width(),rect1.height());
}

void CshowArea::paintEvent(QPaintEvent *)
{
    int i,j;
    int color;
    QString str;
    S_Point P0;
    INT8U Area_No = 0;
    INT16U Width,Height,Min_Width, Min_Height;
    INT16S tmp;
    //CshowArea *pArea;
    //QPainter painter;

    resetProgramPara();
    painter.begin(this);

    color =getColor();

    Width = width();
    Height = height();

    if(areaType != 0)//0表示是分区
    {

//测试画点
    /*
    for(i=0; i < 10; i ++)
    {
        Set_Area_Point_Data(&showData, 0, i, 1, 0x01);
        //Set_Area_Point_Data(&showData, 0, 5, i, 0x02);
    }*/
//测试画线
/*
    S_Point p0 = {10,0};
    S_Point P0 = {10,100};
    S_Point p2 = {20, 10};

    Draw_Line(&showData, 0, &p0, &P0, 0x01);
    Copy_Line(&showData, 0, &p0, &P0, &showData, &p2);
*/
    //测试画矩形
/*
    S_Point p0 = {10,10};
    S_Point P0 = {50,50};

    Fill_Rect(&showData, 0, &p0, 50, 50, 0x02);
    Copy_Filled_Rect(&showData, 0, &p0, 50, 50, &showData, &P0);
*/
    //画圆
/*
    S_Point p0 = {60, 60};
    Fill_Round(&showData, 0, &p0, 10, 0x02);
*/
    //画三角形
/*
    S_Point p0 = {0, 0};
    S_Point P0 = {20,80};
    S_Point p2 = {100, 20};
    S_Point p3 = {60, 80};

    Fill_Triangle(&showData, 0, &p0, &P0, &p2, 0x03);
    Copy_Filled_Triangle(&showData, 0, &p0, &P0, &p2, &showData, &p3);
*/
    //画多边形
/*
    S_Point p0 = {0, 0};
    S_Point P0 = {20,20};
    S_Point p2 = {30, 20};
    S_Point p3 = {40, 10};
    S_Point p4 = {50, 10};

    Fill_Polygon(&showData, 0, &p0,&P0, &p2, &p3, 0x02);//(&showData, 0, &p0, &P0, &p2, 0x03);
    Copy_Filled_Polygon(&showData, 0, &p0, &P0, &p2, &p3, &showData, &p4);
*/
    //画时钟的整点
    /*
    S_Point p0={60, 60};
    S_Point P0;

    //Get_Angle_Point(&p0, 45, 30, &P0); //找到圆的中心点
    //Draw_Line(&showData, 0, &p0, &P0, 0x02);
    Fill_Clock_Point(&showData, 0, &p0, 45, 30, 5, 0x01);
    Fill_Clock_Line(&showData, 0, &p0, 135, 50, 5, 0x04);
*/
   Clear_Area_Data(&Show_Data, 0);
   //if(mousePressed == false || (mousePressed == true && dragFlag != DRAG_MOVE))//鼠标在没有按下的情况下才更新数据
    {

        Clear_Area_Data(&Show_Data_Bak, 0);
        //memset(Show_Data.Color_Data, 0, sizeof(Show_Data.Color_Data));
        //memset(Show_Data_Bak.Color_Data, 0, sizeof(Show_Data_Bak.Color_Data));
        if(filePara.Temp_Para.Flag == SHOW_CLOCK) //显示表盘
        {
            Get_Cur_Time(Cur_Time.Time);

            //将背景文字放到Show_Data_Bak中

            QSize size = imageBk.size();

            filePara.Clock_Para.Text_Width = size.width();
            filePara.Clock_Para.Text_Height = size.height();

            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

            tmp = (INT16S)(Width * Prog_Status.File_Para[Area_No].Clock_Para.Text_X / 100) - (INT16S)Prog_Status.File_Para[Area_No].Clock_Para.Text_Width/2;
            if(tmp > 0)
              P0.X = (INT16U)tmp;
            else
              P0.X = 0;

            tmp = (INT16S)(Height * Prog_Status.File_Para[Area_No].Clock_Para.Text_Y / 100) - (INT16S)(Prog_Status.File_Para[Area_No].Clock_Para.Text_Height/2);
            if(tmp > 0)
              P0.Y = (INT16U)tmp;
            else
              P0.Y = 0;

            getTextShowData(imageBk, &Show_Data_Bak, P0.X, P0.Y);

            Update_Clock_Data(0);
        }
        else if(filePara.Temp_Para.Flag == SHOW_PIC) //显示图文
        {
            //imageBk = getTextEditImage(smLineFlag, w,h, picStr, page);
            int lineNum = 0;
            int pageNum = 0;
            QImage image = getTextImage(Width, picStr, &lineNum, linePosi);
            pageNum = getTextPageNum(smLineFlag, Width, Height, lineNum, linePosi, pagePosi);
            imageBk = getTextPageImage(smLineFlag, image, Width, Height, page, pagePosi);
            //getTextPageNum(area->smLineFlag, area->width(), area->height(), lineNum, linePosi, pagePosi);

            getTextShowData(imageBk, &Show_Data, 0, 0);
        }
        else if(filePara.Temp_Para.Flag == SHOW_TIME)
        {
            Get_Cur_Time(Cur_Time.Time);

            //将背景文字放到Show_Data_Bak中

            QSize size = imageBk.size();

            filePara.Time_Para.Text_Width = size.width();
            filePara.Time_Para.Text_Height = size.height();

            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

            Min_Width = Get_Time_Min_Width(Area_No);
            Min_Height = Get_Time_Min_Height(Area_No);

            if(Prog_Status.File_Para[Area_No].Time_Para.SmLineFlag == SLINE_MODE)//单行
            {
              if(Width > Min_Width)
              {
                P0.X = (Width - Min_Width) / 2;
              }
              else
              {
                P0.X = 0;
              }

              if(Height > Prog_Status.File_Para[Area_No].Time_Para.Text_Height)
                P0.Y = (Height - Prog_Status.File_Para[Area_No].Time_Para.Text_Height)/2;
              else
                P0.Y = 0;//(Height - Prog_Status.File_Para[Area_No].Time_Para.Text_Height)/2;
            }
            else
            {
                if(Height > Min_Height)
                {
                  P0.Y = (Height - Min_Height) / 2;
                }
                else
                {
                  P0.Y = 0;
                }

                if(Width > Prog_Status.File_Para[Area_No].Time_Para.Text_Width)
                  P0.X = (Width - Prog_Status.File_Para[Area_No].Time_Para.Text_Width)/2;
                else
                  P0.X = 0;//(Height - Prog_Status.File_Para[Area_No].Time_Para.Text_Height)/2;
            }

            Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Status.File_Para[Area_No].Time_Para.Text_Width, Prog_Status.File_Para[Area_No].Time_Para.Text_Height, &Show_Data, &P0);//&Point);

            getTextShowData(imageBk, &Show_Data_Bak, P0.X, P0.Y);
            Update_Time_Data(Area_No);
        }
        else if(filePara.Temp_Para.Flag == SHOW_TIMER) //计时器
        {
            Get_Cur_Time(Cur_Time.Time);

            //将背景文字放到Show_Data_Bak中

            QSize size = imageBk.size();

            filePara.Timer_Para.Text_Width = size.width();
            filePara.Timer_Para.Text_Height = size.height();

            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

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

            Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Status.File_Para[Area_No].Timer_Para.Text_Width, Prog_Status.File_Para[Area_No].Timer_Para.Text_Height, &Show_Data, &P0);//&Point);
            getTextShowData(imageBk, &Show_Data_Bak, P0.X, P0.Y);
            Update_Timer_Data(Area_No);
        }
        else if(filePara.Temp_Para.Flag == SHOW_LUN) //显示农历
        {
            Get_Cur_Time(Cur_Time.Time);

            //将背景文字放到Show_Data_Bak中

            QSize size = imageBk.size();

            filePara.Lun_Para.Text_Width = size.width();
            filePara.Lun_Para.Text_Height = size.height();

            mem_cpy((INT8U *)&Prog_Status.File_Para[0], &filePara, sizeof(filePara), (INT8U *)&Prog_Status.File_Para[0], sizeof(Prog_Status.File_Para[0]));

            Min_Width = Get_Lun_Min_Width(Area_No); //显示农历的最小宽度
            Min_Height = Get_Lun_Min_Height(Area_No); //先死农历的最小高度

            if(Prog_Status.File_Para[Area_No].Lun_Para.SmLineFlag == SLINE_MODE)//单行
            {
              if(Width > Min_Width)
              {
                P0.X = (Width - Min_Width) / 2;
              }
              else
              {
                P0.X = 0;
              }

              if(Height > Prog_Status.File_Para[Area_No].Lun_Para.Text_Height)
                P0.Y = (Height - Prog_Status.File_Para[Area_No].Lun_Para.Text_Height)/2;
              else
                P0.Y = 0;//(Height - Prog_Status.File_Para[Area_No].Lun_Para.Text_Height)/2;
            }
            else
            {
                if(Height > Min_Height)
                {
                  P0.Y = (Height - Min_Height) / 2;
                }
                else
                {
                  P0.Y = 0;
                }

                if(Width > Prog_Status.File_Para[Area_No].Lun_Para.Text_Width)
                  P0.X = (Width - Prog_Status.File_Para[Area_No].Lun_Para.Text_Width)/2;
                else
                  P0.X = 0;//(Height - Prog_Status.File_Para[Area_No].Lun_Para.Text_Height)/2;
              }

            Copy_Filled_Rect(&Show_Data_Bak, Area_No, &P0, Prog_Status.File_Para[Area_No].Lun_Para.Text_Width, Prog_Status.File_Para[Area_No].Lun_Para.Text_Height, &Show_Data, &P0);//&Point);

            getTextShowData(imageBk, &Show_Data_Bak, P0.X, P0.Y);
            Update_Lun_Data(Area_No);
        }
        else if(filePara.Temp_Para.Flag == SHOW_FLASH) //显示动画
        {
            P0.X = P0.Y = 0;
            getFlashShowData(imageBk, &Show_Data, P0.X, P0.Y);
            //Update_Lun_Data(Area_No);
        }
     }
    for(j=0; j<Height; j++)
    {
        for(i=0; i<Width; i++)
        {
            unsigned char colorData = Get_Area_Point_Data(&Show_Data, 0, i, j);

            //if(colorData != 0)
              //qDebug("point %d,%d = %d", i, j, colorData);
           painter.setPen(getQColor(colorData));
           painter.drawPoint(i,j);
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
    }
/*
    painter.setPen(QColor(Qt::green));
    for(i=0; i<w; i++)
    {
        for(j=0; j<h; j++)
        {
           if(Get_Bit(color1, w, i, j))
           {
             //painter.setPen(QColor(Qt::red));
             painter.drawPoint(i,j);
           }
       }
    }

    painter.setPen(QColor(Qt::yellow));
    for(i=0; i<w; i++)
    {
        for(j=0; j<h; j++)
        {
           if(Get_Bit(color2, w, i, j))
           {
             //painter.setPen(QColor(Qt::red));
             painter.drawPoint(i,j);
           }
       }
    }*/
}
    else //非0表示是背景
    {
        painter.setPen(QColor(Qt::darkGray));
        for(i=0; i<Width; i++)
        {
            for(j=0; j<Height; j++)
            {
               //if(Get_Bit(color2, w, i, j))
               {
                 //painter.setPen(QColor(Qt::red));
                 painter.drawPoint(i,j);
               }
           }
        }
    }


/*
    else if(Get_Bit(color1, h, i, j))
           {
             painter.setPen(QColor(Qt::green));
             painter.drawPoint(i,j);
           }
           else if(Get_Bit(color2, h, i, j))
           {
             painter.setPen(QColor(Qt::yellow));
             painter.drawPoint(i,j);
           }
           else
           {
               if(areaType == 0)
               {
                   painter.setPen(QColor(Qt::darkGray));
                   painter.drawPoint(i,j);
               }
               else if(areaType > 0)
               {
                   painter.setPen(QColor(Qt::black));
                   painter.drawPoint(i,j);
               }
           }
        }
    }
*/
    //lpArea = w->screenArea->getFocusArea();//((CscreenArea *)parentWidget)->getFocusArea(); //w->screenArea->getFocusArea();
    if(focusFlag == true) //当前分区是焦点
    {
      painter.setPen(QColor(Qt::yellow));
      painter.drawRect(0, 0, geometry().width()-1, geometry().height()-1);
    }

    //painter.setPen(QColor(Qt::yellow));
    //painter.drawRect(0, 0, geometry().width()-1, geometry().height()-1);
    painter.end();
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
void CshowArea::resetProgramPara()
{
    Screen_Para.Width = geometry().width();
    Screen_Para.Height = geometry().height();
    //Screen_Para.Color = 0x07;//getColor();

    Prog_Para.Area_Num = 1;
    Prog_Para.Area[0].X = 0;
    Prog_Para.Area[0].Y = 0;
    Prog_Para.Area[0].X_Len = geometry().width();
    Prog_Para.Area[0].Y_Len = geometry().height();

}

QString CscreenArea::getCurrentStr()
{
    CshowArea *area = getFocusArea();
    if(area == (CshowArea *)0)
        return "";

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


