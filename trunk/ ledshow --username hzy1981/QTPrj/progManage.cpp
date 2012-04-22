#include "progManage.h"
#include <QMessageBox>
#include <QDockWidget>
#include <QPainter>
#include <QSettings>
#include <QInputDialog>
#include <QMdiSubWindow>
#include <QMdiArea>
#include "showArea.h"
#include "mainwindow.h"
#include "makeProto.h"
#include <QLabel>
#include <QMessageBox>

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
int checkStrType(QString str)
{
    settings.beginGroup(str);
    int type = settings.value("type").toInt();
    int subType = settings.value("subType").toInt();
    settings.endGroup();
/*
    if(type == PROG_PROPERTY)
        return PROG_TYPE;
    else if(type == AREA_PROPERTY)
        return AREA_TYPE;
    else
        return FILE_TYPE;
        */
    if(subType > 0)
     return subType;
    else
     return type;
}

int checkItemType(QTreeWidgetItem *item)
{
    //QVariant QVar;

    QString QStr = item ->data(0,Qt::UserRole).toString();

    return checkStrType(QStr);
}

//更新item的parent使其当前的subindex为item
void updateItemSubIndex(QTreeWidgetItem *item)
{
    QString QStr;
    //QTreeWidgetItem *parent;
    int index;//parentIndex;

    //parent = item ->parent();
    //parentIndex = parent->parent()->indexOfChild(parent);
    index = item->parent()->indexOfChild(item);//在父亲中索引
    //QStr = QString::number(parentIndex + 1) + QObject::tr("分区");
    //QStr = QStr + "(" + QString::number(index + 1) + ")";
    //item->parent()->setText(0,QStr);//setText(QStr);

    QStr = (item->parent()->data(0,Qt::UserRole)).toString();
    settings.beginGroup(QStr);
    settings.setValue("subIndex", index + 1);
    settings.endGroup();

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
  treeWidget = new QTreeWidget(this);//(this);

  treeWidget->setHeaderHidden(true);//header()->setVisible(false);

  //QObject::connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem *, int)),
    //      this, SLOT(clickItem(QTreeWidgetItem *, int)));
  setWidget(treeWidget);

  setFeatures(QDockWidget::NoDockWidgetFeatures);

  //previewWin = new QMainWindow(w);
  //previewArea =  new CscreenArea;
/*
  previewWin = new QMainWindow(w);
  previewWin->setWindowModality(Qt::WindowModal);

  previewArea =  new CscreenArea;//(previewWin);
  previewArea->setWindowModality(Qt::WindowModal);
  previewArea->previewFlag = 1;

  previewWin->setCentralWidget(previewArea);
  //QDialog d(previewArea);
*/


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

    if(type == SCREEN_PROPERTY)
        Qstr = QObject::tr("屏幕");
    else if(type == PROG_PROPERTY)
        Qstr = QObject::tr("节目");
    else if(type == AREA_PROPERTY)
        Qstr = QObject::tr("分区");
    else if(type == PIC_STEXT_PROPERTY)
        Qstr = QObject::tr("字幕");
    else if(type == PIC_MTEXT_PROPERTY)
        Qstr = QObject::tr("文本");
    else if(type == PIC_TABLE_PROPERTY)
        Qstr = QObject::tr("表格");
    else if(type == PIC_FLASH_PROPERTY)
        Qstr = QObject::tr("动画");
    else if(type == PIC_IMAGE_PROPERTY)
        Qstr = QObject::tr("图片");
    else if(type == CLOCK_PROPERTY)
        Qstr = QObject::tr("表盘");
    else if(type == TIME_PROPERTY)
        Qstr = QObject::tr("时间");
    else if(type == TIMER_PROPERTY)
        Qstr = QObject::tr("计时");
    else if(type == TEMP_PROPERTY)
        Qstr = QObject::tr("温度");
    else if(type == LUN_PROPERTY)
        Qstr = QObject::tr("农历");
    else if(type == HUMIDITY_PROPERTY)
        Qstr = QObject::tr("湿度");
    else if(type == NOISE_PROPERTY)
        Qstr = QObject::tr("噪音");
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
    int count,type,subIndex,parentIndex;
    QString Qstr,str;
    QTreeWidgetItem *temp;
    QString name;

    if(parent == 0) { //顶层项
        count = treeWidget->topLevelItemCount();
    }
    else
       count = parent->childCount();

    if(parent != 0)
    {
        type = checkItemType(parent);
        if(type == SCREEN_PROPERTY || type == AREA_PROPERTY || type == PROG_PROPERTY)
        {
            str = parent->data(0, Qt::UserRole).toString();
            settings.beginGroup(str);
            subIndex = settings.value("subIndex").toInt();

            settings.beginGroup("name");
            name = settings.value("name").toString();
            if(!name.isEmpty())
              name = QString("-") + name;
            settings.endGroup();

            settings.endGroup();

#if SUB_INDEX_EN > 0
            Qstr = "(" + QString::number(subIndex) + ")";
#else
            Qstr = "";
#endif
            if(type == SCREEN_PROPERTY)//---不会进入此判断
            {
                parentIndex = treeWidget->indexOfTopLevelItem(parent);//parent->parent()->indexOfChild(parent);
                parent->setText(0, QString::number(parentIndex + 1) + tr("屏幕") + Qstr + name); //设置text
            }
            else if(type == AREA_PROPERTY)
            {
              parentIndex = parent->parent()->indexOfChild(parent);
              parent->setText(0, QString::number(parentIndex + 1) + tr("分区") + Qstr + name); //设置text
            }
            else
            {
              parentIndex = parent->parent()->indexOfChild(parent);
              parent->setText(0, QString::number(parentIndex + 1) + tr("节目") + Qstr + name); //设置text

            }
        }
    }

    for(int i=0; i < count; i ++)
    {
        if(parent == (QTreeWidgetItem *)0)
           temp = treeWidget->topLevelItem(i); //顶层项
        else
           temp = parent->child(i);

        int type = checkItemType(temp); //类型

        //QString QStr = temp ->data(0,Qt::UserRole).toString();


        Qstr = getTypeString(type); //根据类型获得对应的字符串

        str = temp->data(0, Qt::UserRole).toString();
        settings.beginGroup(str);
        subIndex = settings.value("subIndex").toInt();

        settings.beginGroup("name");
        name = settings.value("name").toString();
        if(!name.isEmpty())
          name = QString("-") + name;
        settings.endGroup();
        settings.endGroup();
#if SUB_INDEX_EN
        if(type == SCREEN_PROPERTY || type == AREA_PROPERTY || type == PROG_PROPERTY) //分区
        {
            Qstr = Qstr + "(" + QString::number(subIndex) + ")";
        }
#endif
        /*
        else
        {
            //-------------
            str = temp->data(0, Qt::UserRole).toString();
            settings.beginGroup(str);

            settings.beginGroup("name");
            name = settings.value("name").toString();
            settings.endGroup();

            settings.endGroup();
        }
        */
        //---------------
        temp->setText(0, QString::number(i + 1) + Qstr + name); //设置text
    }
}

CMdiSubWindow * _newScreen(QString name, int x, int y, INT16U width, INT16U height ,INT8U color)
{

    //--------------
    CMdiSubWindow *subWin = new CMdiSubWindow;

    subWin->setWindowIcon(getTypeIcon(SCREEN_PROPERTY));

    w->screenArea =  new CscreenArea(subWin, width, height, color);

    w->screenArea->screenPara.Base_Para.Width = width;
    w->screenArea->screenPara.Base_Para.Height = height;
    w->screenArea->screenPara.Base_Para.Color = color;

    for(int i =0; i<MAX_AREA_NUM;i++)
        w->screenArea->pArea[i]->screenPara.Base_Para.Color = color;
    //w->screenArea->setGeometry(10,10,Screen_Para.Base_Para.Width+8, Screen_Para.Base_Para.Height+34);
    subWin->setWidget(w->screenArea);
    //subWin->setAttribute(Qt::WA_DeleteOnClose);
    //subWin->setWindowFlags(Qt::WindowMinimizeButtonHint);

    w->mdiArea->addSubWindow(subWin);
    subWin->setWindowTitle(name);
    //subWin->setGeometry(x,y,width,height); //resize(Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height);
    //subWin->resize(width + 8,height + 34);
    subWin->move(x,y);
    //subWin->setFixedSize(subWin->size());
    subWin->setFixedSize(subWin->sizeHint());
    subWin->setWindowFlags(subWin->windowFlags() &~ (Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint));

    //subWin->setSystemMenu(0); //此调用可以删除弹出菜单，但不知有没有副作用
    subWin->show();
    return subWin;
}

void CprogManage::newScreen()
{
    //QTreeWidgetItem *curItem;
    //QTreeWidgetItem *parentItem;
    QString QStr;
    int i,size;//,type,index;
    int max = 0,tmp;

    if(verifyPSW() EQ false)
        return;

    /*
    CinputPSWDialog *pswInput = new CinputPSWDialog(this);
    //pswInput->setOkButtonText(tr("确定"));
    pswInput->exec();
*/
    QStr = "screen";//QStr + "/" + QString(tr("area"));

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


    //初始化分区属性
    settings.beginGroup(QString::number(max));
    settings.setValue("screenIndex", 1);//value("screenIndex").toString()
    settings.setValue("checkState", true);
    settings.endGroup();
    settings.endGroup();


    //
    QTreeWidgetItem* item = new QTreeWidgetItem(treeWidget,QStringList(QString::number(size + 1)+tr("屏幕")));
    item->setData(0, Qt::UserRole, QVariant(QStr + "/" + QString::number(max)));
    item->setCheckState(0, Qt::Checked);

    QIcon icon = getTypeIcon(SCREEN_PROPERTY);
    item->setIcon(0,icon);

    treeWidget->addTopLevelItem(item);

    /*CMdiSubWindow * subWin =*/
    _newScreen(QString::number(size + 1) + tr("屏幕"), 0, 0, DEF_SCN_WIDTH, DEF_SCN_HEIGHT, DEF_SCN_COLOR);
    w->screenArea->screenItem = item;

    w->progManage->treeWidget->setCurrentItem(item);

    //---------------
    QString str = w->screenArea->getCurrentScreenStr(); //当前屏幕str
    QDialog *facParaWin = new QDialog(this);
    QHBoxLayout *hLayout = new QHBoxLayout(facParaWin);

    facParaWin->setWindowTitle(tr("新建屏幕"));
    CfacScreenProperty *facScreenProperty = new CfacScreenProperty(NEW_SCN, facParaWin);
    CcomTest *comTest = new CcomTest(facParaWin);
    //facScreenProperty->setSettingsToWidget(str);

    hLayout->addWidget(facScreenProperty);
    hLayout->addWidget(comTest);

    facParaWin->setLayout(hLayout);
    facParaWin->setAttribute(Qt::WA_DeleteOnClose);
    connect(facScreenProperty->endButton, SIGNAL(clicked()), facParaWin, SLOT(close()));
    facParaWin->exec();
    //--------------------

    //判断参数是否被加载，没有被加载则删除已经生成的窗口
    settings.beginGroup(str);
    settings.beginGroup("facPara");
    int setFlag = settings.value("setFlag").toInt(); //是否加载设置了屏幕参数?
    settings.endGroup();
    settings.endGroup();

    if(setFlag EQ 0) //没有加载参数则删除上面建的屏幕
    {
       w->progManage->_deleteItem(0); //删除上面创建的屏幕
    }

    //读取屏幕参数
    //getScreenParaFromSettings(QStr + "/" + QString::number(max), Screen_Para);
    /*
    else
    {
       //subWin->resize(width + 8, height + 34);//setGeometry(0,0, width +8, height + 34);
       subWin->setFixedSize(width + 8, height + 34);
    }*/

}

// program/01
void CprogManage::newProg()
{
    int i,size,type;
    int max = 0,tmp;
    QTreeWidgetItem *parentItem,*curItem;

    curItem = treeWidget->currentItem(); //当前被选中的项
    if(curItem == (QTreeWidgetItem *)0)
    {
        QMessageBox::information(w, tr("提示"),
                                 tr("请在节目管理栏选定一个屏幕"),tr("确定"));

        return;
    }
    type = checkItemType(curItem); //该项目是哪种?

    //找到该分区对应的节目的treeWidgetItem
    if(type == SCREEN_PROPERTY)
        parentItem = curItem;
    else if(type == PROG_PROPERTY)
        parentItem = curItem->parent();
    else if(type == AREA_PROPERTY)
        parentItem = curItem->parent()->parent();
    else
    {
      parentItem = (curItem ->parent())->parent()->parent();
    }

    if(parentItem EQ (QTreeWidgetItem *)0)
    {
        ASSERT_FAILED();
        QMessageBox::information(w, tr("提示"),
                                 tr("请在节目管理栏选定一个屏幕"),tr("确定"));

        return;
    }

    QString QStr = (parentItem ->data(0,Qt::UserRole)).toString();
    QStr = QStr + "/program";

    settings.beginGroup(QStr); //设置settings到program下面
    QStringList groups = settings.childGroups(); //所有节目的列表

    size = groups.size();
    if(size >= MAX_PROG_NUM)
    {
        settings.endGroup();
        QMessageBox::information(w, tr("提示"),
                                 tr("当前屏幕节目数达到上限！"),tr("确定"));

        return;
    }
    //qDebug("groups size = %d", size);
    for(i = 0; i < size; i ++)
    {
      tmp = groups.at(i).toInt();
      if(tmp > max)
          max=tmp;
    }
    max++;

    //qDebug("new prog %d",max);

    settings.beginGroup(QString::number(max));
    settings.setValue("subIndex", 0); //当前子分区
    settings.setValue("name", QString("new prog"));
    settings.setValue("type", PROG_PROPERTY);
    settings.setValue("subType", 0);
    settings.setValue("setFlag", 0); //没有设过参数
      //按日期定时
    settings.setValue("dateTimerCheck", 0);
    settings.setValue("startYear", 2010);
    settings.setValue("startMonth", 1);
    settings.setValue("startDay", 1);
    settings.setValue("endYear", 2010);
    settings.setValue("endMonth", 1);
    settings.setValue("endDay", 1);

    //按星期定时
    settings.setValue("weekTimerCheck", 0);
    settings.setValue("w0", 0);
    settings.setValue("w1", 0);
    settings.setValue("w2", 0);
    settings.setValue("w3", 0);
    settings.setValue("w4", 0);
    settings.setValue("w5", 0);
    settings.setValue("w6", 0);

    //按时间定时
    settings.setValue("timeCheck", 0);
    settings.setValue("startHour", 0);
    settings.setValue("startMin", 0);
    settings.setValue("endHour", 0);
    settings.setValue("endMin", 0);

    //定长播放
    settings.setValue("playTimeCheck", 0);
    settings.setValue("playTime", 0);

    //边框选择
    settings.setValue("borderCheck", 0);
    settings.setValue("width", 1);
    settings.setValue("speed", 1);
    settings.setValue("style", 1);
    settings.setValue("color", 1);

    settings.setValue("checkState", true);

    //qDebug("progs size = %d", settings.childGroups().size());
    settings.endGroup();
    settings.endGroup();

    QTreeWidgetItem* item = new QTreeWidgetItem(parentItem,QStringList(QString::number(size + 1)+tr("节目")));
    item->setData(0, Qt::UserRole, QStr + "/" + QString::number(max));
    item->setCheckState(0, Qt::Checked);

    QIcon icon = getTypeIcon(PROG_PROPERTY);
    item->setIcon(0,icon);
    //parentItem->addChild(item);

    //treeWidget->addTopLevelItem(item);
    //treeWidget->setCurrentItem(item);
    //saveCurItem(item); //当前点钟的

    //w->progManage->clickItem(item, 0);
    w->progManage->treeWidget->setCurrentItem(item);
/*
    updateTextHead(parentItem);
    w->property->updateProperty(item);
    w->screenArea->updateShowArea(item);//  progSettingsInit(QStr);
*/
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
    {
        QMessageBox::information(w, tr("提示"),
                                 tr("请在节目管理栏选定一个节目"),tr("确定"));

        return;
    }
/*
    settings.beginGroup("screen");
    int xLen = settings.value("width").toInt();
    int yLen = settings.value("height").toInt();
    settings.endGroup();
*/
    int xLen = Screen_Para.Base_Para.Width;
    int yLen = Screen_Para.Base_Para.Height;

    type = checkItemType(curItem); //该项目是哪种?
    if(type == SCREEN_PROPERTY)
    {
        QMessageBox::information(w, tr("提示"),
                                 tr("请在节目管理栏选定一个节目"),tr("确定"));

        return;
    }
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
    if(size >= MAX_AREA_NUM)
    {
        settings.endGroup();
        QMessageBox::information(w, tr("提示"),
                                 tr("当前节目分区数达到上限！"),tr("确定"));

        return;
    }

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
    settings.setValue("subIndex", 0); //子项索引
    settings.setValue("name", QString("new area"));
    settings.setValue("type", AREA_PROPERTY);
    settings.setValue("subType", AREA_PROPERTY);
    settings.setValue("setFlag", 0); //没有设过参数
    settings.setValue("index", index);
    settings.setValue("x", size*(xLen / 20));  //该分区的起点x
    settings.setValue("y", size*(yLen / 20));  //该分区的起点y
    settings.setValue("width", xLen / 2);  //该分区的宽度
    settings.setValue("height", yLen / 2);  //该分区的长度
    settings.setValue("checkState", true);
    settings.endGroup();
    settings.endGroup();

    QTreeWidgetItem* item = new QTreeWidgetItem(parentItem,QStringList(QString::number(size + 1)+tr("分区")));
    item->setData(0, Qt::UserRole, QVariant(QStr + "/" + QString::number(max)));
    item->setCheckState(0, Qt::Checked);
    QIcon icon = getTypeIcon(AREA_PROPERTY);
    item->setIcon(0,icon);
    //w->setCurSettingsStr(QStr + "/" + QString::number(max));


    parentItem->addChild(item);
    /*
    treeWidget->setCurrentItem(item);
    saveCurItem(item);

    updateItemSubIndex(item);
    updateTextHead(item->parent());


    //w->property->stackedWidget->setCurrentIndex(AREA_PROPERTY);
    //w->property->setSettingsToWidget(QStr + "/" + QString::number(max), AREA_PROPERTY);
    w->property->updateProperty(item);
    w->screenArea->updateShowArea(item);//w->getCurSettingsStr());//显示一个分区,该分区之前处于隐藏状态
    */

    //w->progManage->clickItem(item, 0);
    w->progManage->treeWidget->setCurrentItem(item);
}

void CprogManage::newSText()
{
  newFile(PIC_PROPERTY,PIC_STEXT_PROPERTY);
}

void CprogManage::newPic() //新图文
{
  newFile(PIC_PROPERTY,PIC_MTEXT_PROPERTY);
}

void CprogManage::newTable()//新表格
{
  newFile(PIC_PROPERTY,PIC_TABLE_PROPERTY);
}

void CprogManage::newFlash() //新动画
{
  newFile(PIC_PROPERTY,PIC_FLASH_PROPERTY);
}

void CprogManage::newImage() //图片
{
  newFile(PIC_PROPERTY,PIC_IMAGE_PROPERTY);
}

void CprogManage::newTime() //新日期
{
  newFile(TIME_PROPERTY,0);
}

void CprogManage::newTimer() //新计时
{
  newFile(TIMER_PROPERTY,0);
}

void CprogManage::newClock() //新表盘
{
  newFile(CLOCK_PROPERTY,0);
}

void CprogManage::newTemp() //新温度
{
  newFile(TEMP_PROPERTY,0);

}

void CprogManage::newLun() //新农历
{
  newFile(LUN_PROPERTY,0);
}

void CprogManage::newHumidity()
{
  newFile(HUMIDITY_PROPERTY, 0);
}

void CprogManage::newNoise()
{
    newFile(NOISE_PROPERTY, 0);
}

/*
CMdiSubWindow *newSubWin(QString title, int width, int height)
{
    CMdiSubWindow *subWin = new CMdiSubWindow;
    //subWin->previewFlag = 1; //用于仿真的子窗口
    previewArea =  new CscreenArea;
    //previewArea->previewFlag = 1;
    subWin->setWidget(previewArea);
    w->mdiArea->addSubWindow(subWin);
    subWin->setWindowTitle(tr("预览"));
    subWin->setGeometry(0,0,Screen_Para.Base_Para.Width + 8, Screen_Para.Base_Para.Height + 32); //resize(Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height);
    subWin->show();
}
*/

//一个新的显示file
void CprogManage::newFile(int fileType, int subType)
{
    QTreeWidgetItem *curItem;
    QTreeWidgetItem *parentItem;
    QString QStr;
    int i,size,type;
    int max = 0,tmp;

    curItem = treeWidget->currentItem(); //当前被选中的项
    if(curItem == (QTreeWidgetItem *)0)
    {
        QMessageBox::information(w, tr("提示"),
                                 tr("请先在节目管理栏选择一个分区"),tr("确定"));
        return;
    }
    type = checkItemType(curItem); //该项目是哪种?

    if(type == PROG_PROPERTY || type == SCREEN_PROPERTY)
    {
        QMessageBox::information(w, tr("提示"),
                                 tr("请先在节目管理栏选择一个分区"),tr("确定"));
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
    if(size >= MAX_FILE_NUM)
    {
        settings.endGroup();
        QMessageBox::information(w, tr("提示"),
                                 tr("当前分区文件数达到上限！"),tr("确定"));

        return;
    }

    for(i = 0; i < size; i ++)
    {
      tmp = groups.at(i).toInt();
      if(tmp > max)
          max=tmp;
    }
    max++;
    settings.beginGroup(QString::number(max));
    settings.setValue("type", fileType);
    settings.setValue("subType", subType);
    settings.setValue("setFlag", 0); //没有设过参数
    settings.setValue("checkState", true);
    settings.endGroup();
    settings.endGroup();

    //w->setCurSettingsStr(QStr + "/" + QString::number(max));

    QTreeWidgetItem* item = new QTreeWidgetItem(parentItem,QStringList(QString::number(max)));
    item->setData(0, Qt::UserRole, QVariant(QStr + "/" + QString::number(max)));
    item->setCheckState(0, Qt::Checked);

    QIcon icon = getTypeIcon((subType > 0)?subType:fileType);
    item->setIcon(0,icon);

    parentItem->addChild(item);

    //w->progManage->clickItem(item, 0);
    w->progManage->treeWidget->setCurrentItem(item);

    //新建表格
    if(fileType EQ PIC_PROPERTY && subType EQ PIC_TABLE_PROPERTY)
    {
      //w->progManage->clickItem();
      w->property->picProperty->edit->showInit();
      //w->property->picProperty->edit->edit();
      w->property->picProperty->edit->tableNew();
    }
    /*
    updateItemSubIndex(item);
    updateTextHead(item->parent());
    treeWidget->setCurrentItem(item);
    saveCurItem(item);


    //w->property->stackedWidget->setCurrentIndex(fileType);
    //w->property->setSettingsToWidget(QStr + "/" + QString::number(max), fileType);


    w->property->updateProperty(item);
    w->screenArea->updateShowArea(item);//  progSettingsInit(QStr);
    */
}

void CprogManage::deleteItem()
{
    int Re =  QMessageBox::warning(w, tr("警告"),
                             tr("确定要删除该项?"),tr("确定"),tr("取消"));
  if(0 == Re)
    _deleteItem(1);
}

//删除项目
//flag == 0表示强制删除
//flag == 1表示密码删除
void CprogManage::_deleteItem(int flag)
{
    QTreeWidgetItem *curItem;
    int type;
    QTreeWidgetItem *parent;
    QString str;
    int index;

    curItem = treeWidget->currentItem(); //当前被选中的项
    if(curItem == 0)
        return;

    str = curItem->data(0, Qt::UserRole).toString();
    type = checkItemType(curItem);

    if(type EQ SCREEN_PROPERTY)//---是屏幕的不能删除
    {
        if(flag)
        {
            if(verifyPSW() EQ false)
                return;
        }

        index = treeWidget->indexOfTopLevelItem(curItem);
        treeWidget->takeTopLevelItem(index);
        updateTextHead(0);

        curItem = treeWidget->currentItem(); //当前被选中的项

        QList<QMdiSubWindow *>subWinList = w->mdiArea->subWindowList();
        QMdiSubWindow *subWin = subWinList.at(index);
        w->mdiArea->removeSubWindow(subWin);

        for(int i = 0; i < subWinList.count(); i ++)
        {
            subWinList.at(i)->setWindowTitle(QString::number(i+1)+tr("屏幕"));
        }
        //删除所有配置项
        settings.beginGroup(str);
        //qDebug("remove str:%s",(const char *)str.toLocal8Bit());
        settings.remove("");
        settings.endGroup();
    }
    else
    {
        if(type != PROG_PROPERTY) //分区和文件类型
        {
            if(type == AREA_PROPERTY)
            {
                settings.beginGroup(str);

                int index = settings.value("index").toInt();
                if(index < MAX_AREA_NUM)
                    w->screenArea->setAreaVisible(index, 0);
                else
                    ASSERT_FAILED();

                settings.endGroup();
            }

            parent = curItem->parent();
            curItem->parent()->removeChild(curItem);
            //updateItemSubIndex(curItem);
            updateTextHead(parent);

            if(type != AREA_PROPERTY)//当前删除的是文件播放类型
            {
              if(parent->childCount() EQ 0) //改分区下没有其他文件播放类型了
                {
                    w->screenArea->updateShowArea(parent); //更新改分区的显示部分.---已经没有文件了，清除该分区的显示
              }
            }

        }
        else
        {/*
            index = treeWidget->indexOfTopLevelItem(curItem);
            treeWidget->takeTopLevelItem(index);
            updateTextHead(0);
            */
            parent = curItem->parent();
            curItem->parent()->removeChild(curItem);
            //updateItemSubIndex(curItem);
            updateTextHead(parent);
            for(int i = 0; i < MAX_AREA_NUM; i ++)
                w->screenArea->setAreaVisible(i, 0);
        }


        settings.beginGroup(str);
        //qDebug("remove str:%s",(const char *)str.toLocal8Bit());
        settings.remove("");
        settings.endGroup();

        //settings.remove(str);//删除这个组

        if(parent->childCount() == 0)//子项都删除则将父项的子索引清0
        {
            str = parent->data(0, Qt::UserRole).toString();//.toString();
            settings.beginGroup(str);
            settings.setValue("subIndex", 0);
            settings.endGroup();
        }
        //qDebug("remove : %s", (const char *)(Qvar.toString().toLocal8Bit()));
        curItem = treeWidget->currentItem(); //当前被选中的项
        if(curItem == 0)
        {
            for(int i = 0; i < MAX_AREA_NUM; i ++)
                w->screenArea->setAreaVisible(i, 0);
            //return;
        }
    }

    saveCurItem((QTreeWidgetItem *)0xFFFFFFFF); //删除后当前没有点中项
    //w->progManage->clickItem(curItem, 0);
    w->progManage->treeWidget->setCurrentItem(curItem);

}

//点击
void CprogManage::clickItem(QTreeWidgetItem *item, int column)
{
    int type;
    QString QStr;
    QTreeWidgetItem *lastItem,*screenItem;
    QMdiSubWindow *subWin;
    int index;

    lastItem = getCurItem();
/*
    qDebug("lastItem str:%s,\r\ncurItem str:%s", \
           (lastItem == 0)?"null":(const char *)lastItem->data(0, Qt::UserRole).toString().toLocal8Bit(),\
           (const char *)item->data(0, Qt::UserRole).toString().toLocal8Bit());
*/

    if(lastItem == item) //同一个项目点击
    {
        if(item != (QTreeWidgetItem *)0)
        {
          index = treeWidget->indexOfTopLevelItem(w->screenArea->screenItem);
          subWin= getSubWinByIndex(w->mdiArea, index);
          if(subWin != (QMdiSubWindow *)0)
            subWin->show();
        }
        return;
    }

    if(lastItem != (QTreeWidgetItem *)0)
    {
       //w->property->getSettingsFromWidget(lastItem);
    }

    if(item EQ (QTreeWidgetItem *)0)
    {
        qDebug("no item left");
        w->actionEnProc(NULL_PROPERTY);
        return;
    }

    saveCurItem(item);

    type = checkItemType(item);

    w->actionEnProc(type);
    //更新当前屏幕
    if(type EQ SCREEN_PROPERTY)
    {
        screenItem = item;
    }
    else if(type EQ PROG_PROPERTY)
    {
        screenItem = item->parent();
    }
    else if(type EQ AREA_PROPERTY)
    {
        screenItem = item->parent()->parent();
    }
    else
    {
       screenItem = item->parent()->parent()->parent();
    }

    index = treeWidget->indexOfTopLevelItem(screenItem);
    if(index >= 0)
    {
        subWin= getSubWinByIndex(w->mdiArea, index);

        QTreeWidgetItem *oldScreenItem = w->screenArea->screenItem;
        if((CscreenArea *)subWin->widget() != w->screenArea)
        {
           w->screenArea = (CscreenArea *)subWin->widget();
           //w->screenArea->screenSettingsInit(screenItem);
        }

        if(subWin->isHidden())
          subWin->show();

        QObject::disconnect(w->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),
                w, SLOT(updateTreeWidget(QMdiSubWindow*)));
        if(w->mdiArea->activeSubWindow()!=subWin)
          w->mdiArea->setActiveSubWindow(subWin);
        QObject::connect(w->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),
                w, SLOT(updateTreeWidget(QMdiSubWindow*)));

        w->MDISubWinClickFlag = 0;
        //更新当前显示屏参数
        QString screenStr = screenItem->data(0, Qt::UserRole).toString();
        getScreenCardParaFromSettings(screenStr, Screen_Para, Card_Para);

        if(oldScreenItem != w->screenArea->screenItem)
        {
            mainObj->emitScreenChangeSignal();
          //w->screenCardParaChangeProc();
        }

    }
    else
        ASSERT_FAILED();

    if(type != SCREEN_PROPERTY)//PROG_PROPERTY) //&& type != AREA_PROPERTY) //既不是节目也不是分区
    {
        //int index =
        //QString str = item->parent()->data(0, Qt::UserRole).toString();
        updateItemSubIndex(item);
        updateTextHead(item->parent());

        if(type != PROG_PROPERTY) //分区或者文件类型则更新父目录
        {
            updateItemSubIndex(item->parent());        //updateItemSubIndex(item);
            updateTextHead(item->parent()->parent());
        }

        if(type!= PROG_PROPERTY && type!= AREA_PROPERTY) //节目文件
        {
          updateItemSubIndex(item->parent()->parent());        //updateItemSubIndex(item);
          updateTextHead(item->parent()->parent()->parent());
        }
    }
    else
    {
        //updateItemSubIndex(item);
        updateTextHead(item);

    }

    //treeWidget->setCurrentItem(item);//setCurrentItem()
    w->property->updateProperty(item);
    w->screenArea->updateShowArea(item);
    //treeWidget->setCurrentItem(item);//setCurrentItem()---这句话要放到最后！否则前面的两个函数触发槽，槽函数还是引用之前的curitem
}
/*
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

    if(treeWidget->topLevelItemCount()>0)
    {
        treeWidget->setCurrentItem(treeWidget->topLevelItem(0)); //设置第一个item为当前焦点

        for(int i = 0; i <treeWidget->topLevelItemCount(); i ++)
        {
            QTreeWidgetItem *progItem;

            progItem = treeWidget->topLevelItem(i);
            updateTextHead(progItem);
            for(int j = 0; j<progItem->childCount(); j ++)
            {
                QTreeWidgetItem *areaItem;

                areaItem =progItem->child(j);
                updateTextHead(areaItem);
            }
        }

        saveCurItem(0);
        //clickItem(treeWidget->topLevelItem(0), 0);
   }
}
*/
void CprogManage::currentItemChangedProc(QTreeWidgetItem * current, QTreeWidgetItem * previous )
{
  clickItem(current, 0);

}

void CprogManage::itemCheckStateChangedProc(QTreeWidgetItem *item, int column)
{
    bool checkState;
    QString str = item->data(0, Qt::UserRole).toString();

    debug("item str %s", (const char *)str.toLocal8Bit());

    if(item->checkState(0) EQ Qt::Checked)
        checkState = true;
    else
        checkState = false;

    settings.beginGroup(str);
    settings.setValue("checkState", checkState);
    settings.endGroup();
}

/*
#define NULL_PROPERTY   0xFF
#define SCREEN_PROPERTY 0x00
#define PROG_PROPERTY   0x01
#define AREA_PROPERTY   0x02
#define PIC_PROPERTY    0x03 //图片
#define CLOCK_PROPERTY  0x05 //表盘
#define TIME_PROPERTY   0x06 //日期时间
#define TIMER_PROPERTY  0x07 //定时
#define TEMP_PROPERTY   0x08 //温度
#define LUN_PROPERTY    0x09    //农历
#define HUMIDITY_PROPERTY 0x0A //湿度
#define NOISE_PROPERTY 0x0B //噪音

#define PIC_TABLE_PROPERTY  0x30
#define PIC_FLASH_PROPERTY  0x31 //动画
#define PIC_MTEXT_PROPERTY  0x32
#define PIC_STEXT_PROPERTY  0x33
 */

//progManage中的treeWidget的初始化,根据settings进行初始化
void CprogManage::settingsInit()
{
    int screenSize, progSize, fileSize;
    QStringList screenGroups, progGroups, areaGroups, fileGroups;
    S_Screen_Para screenPara;
    bool checkState;

    treeWidget->clear();
    //settings.clear();
    settings.beginGroup("screen");

    screenGroups = settings.childGroups(); //屏幕列表
    screenSize = screenGroups.size();
    settings.endGroup();

    //对每一个显示屏进行初始化
    for(int m = 0; m < screenSize; m ++)
    {
        settings.beginGroup("screen");

        QTreeWidgetItem *screenItem = new QTreeWidgetItem(treeWidget);
        QIcon icon = getTypeIcon(SCREEN_PROPERTY);
        screenItem->setIcon(0, icon);
        treeWidget->addTopLevelItem(screenItem);
        QString screenStr = "screen/" + screenGroups.at(m);

        settings.beginGroup(screenGroups.at(m));
        checkState = settings.value("checkState").toBool();
        settings.beginGroup("facPara");
        screenPara.Base_Para.Width = settings.value("width").toInt();
        screenPara.Base_Para.Height = settings.value("height").toInt();
        screenPara.Base_Para.Color = 0;

        int color = settings.value("color").toInt();
        if(color EQ 0)
          screenPara.Base_Para.Color = 0x01;
        else if(color EQ 1)
          screenPara.Base_Para.Color = 0x03;
        else
          screenPara.Base_Para.Color = 0x07;

        settings.endGroup();
        settings.endGroup();
        //获取当前屏幕参数
        //getScreenParaFromSettings(screenStr, Screen_Para);

        //---

        //w->screenArea->screenItem = screenItem;//在updateShowArea中更新screenItem等
/*
        QMdiSubWindow * subWin = w->mdiArea->addSubWindow(w->screenArea);
        subWin->setWindowTitle(QString::number(m + 1) + tr("显示屏"));
        //w->screenArea->parentWidget()->resize(w->screenArea->width(), w->screenArea->height());
        //w->screenArea->show();
        subWin->setGeometry(0,0,Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height); //resize(Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height);

        Qt::WindowFlags flags = Qt::Window|Qt::WindowMinimizeButtonHint;
                                //| Qt::WindowShadeButtonHint;
        //flags |= Qt::WindowMinimizeButtonHint;
        //flags |= Qt::WindowCloseButtonHint;
        //flags |= Qt::WindowMaximizeButtonHint;
        subWin->setWindowFlags(flags); // 设置禁止最大化
*/
        //subWin->setFixedSize(subWin->size());
        //subWin->show();
        //------
/*
        CMdiSubWindow *subWin = new CMdiSubWindow;
        w->screenArea =  new CscreenArea(subWin);
        subWin->setWidget(w->screenArea);
        subWin->setAttribute(Qt::WA_DeleteOnClose);
        w->mdiArea->addSubWindow(subWin);
        subWin->setWindowTitle(QString::number(m + 1) + tr("屏幕"));
        subWin->setGeometry(10,10,Screen_Para.Base_Para.Width+8, Screen_Para.Base_Para.Height+34); //resize(Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height);
        //w->screenArea->setGeometry(10,10,Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height); //resize(Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height);


        subWin->setFixedSize(subWin->size());
*/
        /*CMdiSubWindow * subWin = */    
        settings.endGroup();
        //screenItem->setData(0, Qt::UserRole, screenStr);
        _newScreen(QString::number(m + 1) + tr("屏幕"), m*50, m*50, screenPara.Base_Para.Width, screenPara.Base_Para.Height, screenPara.Base_Para.Color);


        w->screenArea->screenItem = screenItem;
        screenItem->setData(0, Qt::UserRole, screenStr);
        screenItem->setCheckState(0, (checkState == true)?(Qt::Checked):(Qt::Unchecked));
        screenItem->setText(0, QString::number(m + 1) + tr("显示屏"));

        settings.beginGroup("screen");
        settings.beginGroup(screenGroups.at(m) + "/program");
        progGroups = settings.childGroups(); //节目列表
        progSize = progGroups.size(); //节目个数

        for(int i = 0; i < progSize; i ++)
        {
            QTreeWidgetItem *progItem = new QTreeWidgetItem(screenItem);
            QString progStr = screenStr + "/program/" + progGroups.at(i);

            settings.beginGroup(progGroups.at(i));
            checkState = settings.value("checkState").toBool();
            settings.endGroup();

            QIcon icon = getTypeIcon(PROG_PROPERTY);
            progItem->setIcon(0, icon);

            progItem->setData(0, Qt::UserRole, progStr);
            progItem->setCheckState(0, (checkState == true)?(Qt::Checked):(Qt::Unchecked));
            progItem->setText(0, QString::number(i + 1) + tr("节目"));
            //treeWidget->addTopLevelItem(progItem);
            screenItem->addChild(progItem);

            settings.beginGroup(progGroups.at(i) + "/area");
            areaGroups = settings.childGroups(); //列表
            //areaSize = areaGroups.size();
            //qDebug("set %d prog %s, area size = %d", i, progGroups.at(i), areaSize);

            for(int j = 0; j < areaGroups.size(); j ++)
            {
                QTreeWidgetItem *areaItem = new QTreeWidgetItem(progItem);
                QString areaStr = progStr + "/area/" + areaGroups.at(j);

                settings.beginGroup(areaGroups.at(j));
                checkState = settings.value("checkState").toBool();
                settings.endGroup();

                QIcon icon = getTypeIcon(AREA_PROPERTY);
                areaItem->setIcon(0, icon);

                areaItem->setData(0, Qt::UserRole, areaStr);
                areaItem->setCheckState(0, (checkState == true)?(Qt::Checked):(Qt::Unchecked));
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

                    settings.beginGroup(fileGroups.at(k));
                    checkState = settings.value("checkState").toBool();
                    int type = settings.value("type").toInt();
                    int subType = settings.value("subType").toInt();
                    if(subType > 0)
                        type =subType;
                    settings.endGroup();

                    fileItem->setData(0, Qt::UserRole, fileStr);
                    fileItem->setCheckState(0, (checkState == true)?(Qt::Checked):(Qt::Unchecked));

                    //int type = checkItemType(fileItem);//checkStrType(fileStr);
                    QIcon icon = getTypeIcon(type);
                    fileItem->setIcon(0, icon);

                    QString name = getTypeString(type);
                    fileItem->setText(0, QString::number(k + 1) + name);
                    areaItem->addChild(fileItem);
                    //qDebug("set %d file %s", k, fileGroups.at(i));
                }
                settings.endGroup();
             }
            settings.endGroup();
        }
        settings.endGroup();
        settings.endGroup();
    }
    //settings.endGroup();

    if(treeWidget->topLevelItemCount()>0)
    {
        treeWidget->setCurrentItem(treeWidget->topLevelItem(0)); //设置第一个item为当前焦点

        for(int i = 0; i <treeWidget->topLevelItemCount(); i ++)
        {
            QTreeWidgetItem *screenItem;
            screenItem = treeWidget->topLevelItem(i);
            updateTextHead(screenItem);

            for(int k = 0; k<screenItem->childCount(); k ++)
            {
                QTreeWidgetItem *progItem;

                progItem = screenItem->child(k);
                updateTextHead(progItem);
                for(int j = 0; j<progItem->childCount(); j ++)
                {
                    QTreeWidgetItem *areaItem;

                    areaItem =progItem->child(j);
                    updateTextHead(areaItem);
                }
            }
        }
   }

    saveCurItem((QTreeWidgetItem *)0xFFFFFFFF);
    clickItem(treeWidget->topLevelItem(0), 0);
    mainObj->emitScreenChangeSignal();
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

//获取屏幕编号，从1开始，0表示不存在该屏幕
//screenStr表示屏幕的settings str
int getScreenIndex(QString screenStr)
{
    QStringList screenGroups;
    int screenSize;

    settings.beginGroup("screen");
    screenGroups = settings.childGroups(); //屏幕列表
    screenSize = screenGroups.size();
    settings.endGroup();

    for(int i = 0; i < screenSize; i ++)
    {
        if(QString("screen/") + screenGroups.at(i) EQ screenStr)
        {
            return i + 1;
        }
    }

    return 0;
}
