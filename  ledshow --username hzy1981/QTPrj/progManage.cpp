#include "progManage.h"
#include <QDockWidget>
#include <QPainter>
#include <QSettings>
#include "showArea.h"
#include "mainwindow.h"
#include <QLabel>

extern MainWindow *w;
extern QSettings settings;
/*
 QSettings：
 program
   |-00
   |-01
     |-area
        |-00
        |-01
           |-
 */
int checkItemType(QTreeWidgetItem *item)
{
    //QVariant QVar;

    QString QStr = item ->data(0,Qt::UserRole).toString();
/*
    if(QStr.contains("file"))
        return FILE_TYPE;
    else if(QStr.contains("area"))
        return AREA_TYPE;
    else if(QStr.contains("program"))
        return PROG_TYPE;
        */
    settings.beginGroup(QStr);
    int type = settings.value("type").toInt();
    settings.endGroup();
/*
    if(type == PROG_PROPERTY)
        return PROG_TYPE;
    else if(type == AREA_PROPERTY)
        return AREA_TYPE;
    else
        return FILE_TYPE;
        */
    return type;
}

/*
#define HTXT_AREA  0x00 //超文本
#define PIC_AREA   0x01 //图片
#define FLASH_AREA 0x02 //动画
#define CLOCK_AREA 0x03 //表盘
#define TIME_AREA  0x04 //日期时间
#define TIMER_AREA 0x05 //定时
#define TEMP_AREA  0x06 //温度
 */

void newAreaSettings(QString &groupName, int type)
{
    settings.beginGroup(groupName);
    if(type == PROG_PROPERTY)
    {
        settings.setValue("name", "new prog");//名字
        settings.setValue("timerPlay", 0); //定时播放
        settings.setValue("weekPlay", 0); //星期播放
        settings.setValue("fixTimePlay", 0);  //定长播放-固定时长
        //settings.setValue("", );
    }
    settings.endGroup();

}

//program管理
CprogManage:: CprogManage(QWidget *parent):QDockWidget(tr("节目管理"), parent)
{
  setAllowedAreas(Qt::LeftDockWidgetArea);
  treeWidget = new QTreeWidget(this);
  treeWidget->setHeaderHidden(true);//header()->setVisible(false);

  QObject::connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem *, int)),\
          this, SLOT(clickItem(QTreeWidgetItem *, int)));
  setWidget(treeWidget);

}

CprogManage::~CprogManage()
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

//根据类型获得对应的字符串，该字符串用于显示,不用于Qsettngs中
QString getTypeString(int type)
{
    QString Qstr;

    if(type == PROG_PROPERTY)
        Qstr = QObject::tr("节目");
    else if(type == AREA_PROPERTY)
        Qstr = QObject::tr("分区");
    else if(type == PIC_PROPERTY)
        Qstr = QObject::tr("图文");
    else if(type == FLASH_PROPERTY)
        Qstr = QObject::tr("动画");
    else if(type == CLOCK_PROPERTY)
        Qstr = QObject::tr("表盘");
    else if(type == TIME_PROPERTY)
        Qstr = QObject::tr("时间");
    else if(type == TIMER_PROPERTY)
        Qstr = QObject::tr("定时");
    else if(type == TEMP_PROPERTY)
        Qstr = QObject::tr("温度");
    else
    {
        //ASSERT_FAILED();
        Qstr = "";
        //return "";
    }

    return Qstr;
}

//更新parent项下所有项的标题
//parent为0时表示更新顶层项
//parent!=0表示更新parent的所有子项
void CprogManage::updateTextHead(QTreeWidgetItem *parent)
{
    int count;
    QString Qstr;
    QTreeWidgetItem *temp;

    if(parent == 0) //顶层项
       count = treeWidget->topLevelItemCount();
    else
       count = parent->childCount();

    for(int i=0; i < count; i ++)
    {
        if(parent == (QTreeWidgetItem *)0)
           temp = treeWidget->topLevelItem(i); //顶层项
        else
           temp = parent->child(i);

        int type = checkItemType(temp); //类型
        Qstr = getTypeString(type); //根据类型获得对应的字符串

        temp->setText(0, QString::number(i + 1) + Qstr); //设置text
    }
}

// program/01
void CprogManage::newProg()
{
    int i,size;
    int max = 0,tmp;

    settings.beginGroup("program"); //设置settings到program下面
    QStringList groups = settings.childGroups(); //所有节目的列表

    size = groups.size();
    qDebug("groups size = %d", size);
    for(i = 0; i < size; i ++)
    {
      tmp = groups.at(i).toInt();
      if(tmp > max)
          max=tmp;
    }
    max++;

    qDebug("new prog %d",max);

    settings.beginGroup(QString::number(max));
    settings.setValue("name", QString("new prog"));
    settings.setValue("type", PROG_PROPERTY);
    settings.endGroup();
    qDebug("progs size = %d", settings.childGroups().size());
    settings.endGroup();

    //w->setCurSettingsStr(QString("program") + "/" + QString::number(max));

    QTreeWidgetItem* item = new QTreeWidgetItem(treeWidget);//QStringList(QString::number(size + 1)+tr("节目")));
    item->setData(0, Qt::UserRole, QVariant(QString("program") + "/" + QString::number(max)));

    treeWidget->addTopLevelItem(item);
    treeWidget->setCurrentItem(item);
    saveCurItem(item); //当前点钟的
    updateTextHead(0);
    //w->property->stackedWidget->setCurrentIndex(PROG_PROPERTY);
    //w->property->setSettingsToWidget(QString("program") + "/" + QString::number(max), PROG_PROPERTY);

    w->property->updateProperty(item);
    w->screenArea->updateShowArea(item);//  progSettingsInit(QStr);
}



//一个新的area窗口
// program/01/
void CprogManage::newArea()
{
    QTreeWidgetItem *curItem;
    QTreeWidgetItem *parentItem;
    QString QStr;
    int i,size,type,index;
    int max = 0,tmp;

    curItem = treeWidget->currentItem(); //当前被选中的项
    if(curItem == (QTreeWidgetItem *)0)
        return;

    settings.beginGroup("screen");
    int xLen = settings.value("xLen").toInt();
    int yLen = settings.value("yLen").toInt();
    settings.endGroup();

    type = checkItemType(curItem); //该项目是哪种?

    //找到该分区对应的节目的treeWidgetItem
    if(type == PROG_PROPERTY)
        parentItem = curItem;
    else if(type == AREA_PROPERTY)
        parentItem = curItem->parent();
    else
    {
      parentItem = (curItem ->parent())->parent();
    }

    QStr = (parentItem ->data(0,Qt::UserRole)).toString();
    QStr = QStr + "/" + QString(tr("area"));

    settings.beginGroup(QStr);
    QStringList groups = settings.childGroups(); //area列表

    size = groups.size();
    for(i = 0; i < size; i ++)
    {
      tmp = groups.at(i).toInt();
      if(tmp > max)
          max=tmp;
    }
    max++;

    //检查是否有足够的Area
    index = w->screenArea->checkEnoughArea();
    if(index <= 0)
        return;
    else
        index --;

    //初始化分区属性
    settings.beginGroup(QString::number(max));
    settings.setValue("name", QString("new area"));
    settings.setValue("type", AREA_PROPERTY);
    settings.setValue("index", index);
    settings.setValue("x", size*(xLen / 20));  //该分区的起点x
    settings.setValue("y", size*(yLen / 20));  //该分区的起点y
    settings.setValue("xLen", xLen / 2);  //该分区的宽度
    settings.setValue("yLen", yLen / 2);  //该分区的长度
    settings.endGroup();
    settings.endGroup();

    QTreeWidgetItem* item = new QTreeWidgetItem(parentItem,QStringList(QString::number(size + 1)+tr("分区")));
    item->setData(0, Qt::UserRole, QVariant(QStr + "/" + QString::number(max)));

    //w->setCurSettingsStr(QStr + "/" + QString::number(max));


    parentItem->addChild(item);
    treeWidget->setCurrentItem(item);
    saveCurItem(item);
    updateTextHead(item->parent());


    //w->property->stackedWidget->setCurrentIndex(AREA_PROPERTY);
    //w->property->setSettingsToWidget(QStr + "/" + QString::number(max), AREA_PROPERTY);
    w->property->updateProperty(item);
    w->screenArea->updateShowArea(item);//w->getCurSettingsStr());//显示一个分区,该分区之前处于隐藏状态
}


void CprogManage::newPic() //新图文
{
  newFile(PIC_PROPERTY);
}

void CprogManage::newFlash() //新动画
{
  newFile(FLASH_PROPERTY);
}

void CprogManage::newTime() //新日期
{
  newFile(TIME_PROPERTY);
}

void CprogManage::newTimer() //新计时
{
  newFile(TIMER_PROPERTY);
}

void CprogManage::newClock() //新表盘
{
  newFile(CLOCK_PROPERTY);
}

void CprogManage::newTemp() //新温度
{
  newFile(TEMP_PROPERTY);

}

//一个新的显示file
void CprogManage::newFile(int fileType)
{
    QTreeWidgetItem *curItem;
    QTreeWidgetItem *parentItem;
    QString QStr;
    int i,size,type;
    int max = 0,tmp;

    curItem = treeWidget->currentItem(); //当前被选中的项
    if(curItem == (QTreeWidgetItem *)0)
        return;

    type = checkItemType(curItem); //该项目是哪种?

    if(type == PROG_PROPERTY)
    {
        return;
    }
    else if(type == AREA_PROPERTY) //area型
        parentItem = curItem;
    else
    {
      parentItem = curItem ->parent();
    }

    QStr = (parentItem ->data(0,Qt::UserRole)).toString();
    QStr = QStr + "/" + QString(tr("file"));

    settings.beginGroup(QStr);
    QStringList groups = settings.childGroups(); //area列表

    size = groups.size();
    for(i = 0; i < size; i ++)
    {
      tmp = groups.at(i).toInt();
      if(tmp > max)
          max=tmp;
    }
    max++;
    settings.beginGroup(QString::number(max));
    settings.setValue("type", fileType);
    settings.endGroup();
    settings.endGroup();

    //w->setCurSettingsStr(QStr + "/" + QString::number(max));

    QTreeWidgetItem* item = new QTreeWidgetItem(parentItem,QStringList(QString::number(max)));
    item->setData(0, Qt::UserRole, QVariant(QStr + "/" + QString::number(max)));
    parentItem->addChild(item);
    treeWidget->setCurrentItem(item);
    saveCurItem(item);
    updateTextHead(item->parent());
    //w->property->stackedWidget->setCurrentIndex(fileType);
    //w->property->setSettingsToWidget(QStr + "/" + QString::number(max), fileType);
    w->property->updateProperty(item);
    w->screenArea->updateShowArea(item);//  progSettingsInit(QStr);
}

//删除项目
void CprogManage::deleteItem()
{
    QTreeWidgetItem *curItem;
    QVariant Qvar;
    int index;

    curItem = treeWidget->currentItem(); //当前被选中的项
    if(curItem == 0)
        return;

    Qvar = curItem->data(0, Qt::UserRole);
    if(checkItemType(curItem) != PROG_PROPERTY)
    {
        if(checkItemType(curItem) == AREA_PROPERTY)
        {
            settings.beginGroup(Qvar.toString());
            int index = settings.value("index").toInt();
            if(index < MAX_AREA_NUM)
                w->screenArea->setAreaVisible(index, 0);
            settings.endGroup();
        }

        QTreeWidgetItem *parent = curItem->parent();
        curItem->parent()->removeChild(curItem);
        updateTextHead(parent);

    }
    else
    {
        index = treeWidget->indexOfTopLevelItem(curItem);
        treeWidget->takeTopLevelItem(index);
        updateTextHead(0);
    }
    settings.remove(Qvar.toString());//删除这个组
}

//点击
void CprogManage::clickItem(QTreeWidgetItem *item, int column)
{
    int type;
    QString QStr;
    QTreeWidgetItem *lastItem;

    lastItem = getCurItem();

    if(lastItem == item) //同一个项目点击
        return;

    if(lastItem != (QTreeWidgetItem *)0)
    {
       w->property->getSettingsFromWidget(lastItem);
    }

    saveCurItem(item);

    w->property->updateProperty(item);
    w->screenArea->updateShowArea(item);
}

//progManage中的treeWidget的初始化,根据settings进行初始化
void CprogManage::settingsInit()
{
    int progSize, fileSize;
    QStringList progGroups, areaGroups, fileGroups;

    treeWidget->clear();
    settings.beginGroup("program");
    progGroups = settings.childGroups(); //节目列表
    progSize = progGroups.size(); //节目个数

    for(int i = 0; i < progSize; i ++)
    {
        QTreeWidgetItem *progItem = new QTreeWidgetItem(treeWidget);
        QString progStr = QString("program") + "/" + progGroups.at(i);
        progItem->setData(0, Qt::UserRole, progStr);
        progItem->setText(0, QString::number(i + 1) + tr("节目"));
        treeWidget->addTopLevelItem(progItem);

        settings.beginGroup(progGroups.at(i) + "/area");
        areaGroups = settings.childGroups(); //列表
        //areaSize = areaGroups.size();
        //qDebug("set %d prog %s, area size = %d", i, progGroups.at(i), areaSize);

        for(int j = 0; j < areaGroups.size(); j ++)
        {
            QTreeWidgetItem *areaItem = new QTreeWidgetItem(progItem);
            QString areaStr = progStr + "/area/" + areaGroups.at(j);
            areaItem->setData(0, Qt::UserRole, areaStr);
            areaItem->setText(0, QString::number(j + 1) + tr("分区"));
            progItem->addChild(areaItem);

            settings.beginGroup(areaGroups.at(j) + "/file");
            fileGroups = settings.childGroups(); //列表
            fileSize = fileGroups.size();
            //qDebug("set %d area %s, file size = %d", j, areaGroups.at(i), fileSize);

            for(int k = 0; k < fileSize; k ++)
            {
                QTreeWidgetItem *fileItem = new QTreeWidgetItem(areaItem);
                QString fileStr = areaStr + "/file/" + fileGroups.at(k);
                fileItem->setData(0, Qt::UserRole, fileStr);

                settings.beginGroup(fileGroups.at(k));
                int type = settings.value("type").toInt();
                QString name = getTypeString(type);
                fileItem->setText(0, QString::number(k + 1) + name);
                areaItem->addChild(fileItem);

                settings.endGroup();
                //qDebug("set %d file %s", k, fileGroups.at(i));
            }
            settings.endGroup();
         }
        settings.endGroup();
    }
    settings.endGroup();

    treeWidget->setCurrentItem(treeWidget->topLevelItem(0)); //设置第一个item为当前焦点
    saveCurItem(treeWidget->topLevelItem(0));
}

//获取当前settings的str
QTreeWidgetItem * CprogManage::getCurItem()
{
    return curItem;
}

//设置当前的配置settings的str
void CprogManage::saveCurItem(QTreeWidgetItem *item)
{
    curItem = item;
}
