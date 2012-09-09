#include <QObject>
#include "mainwindow.h"
#include "progProperty.h"
#include "progManage.h"
#include "makeProto.h"
#include "..\Stm32\usr\app\Includes.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include <QApplication>
#include <QUrl>

extern MainWindow *w;

QString rsrcPath1 =  ":/images/win1";
QString rsrcPath = ":/images/win";

//节目工程文件
QSettings settings(PROG_INI_FILE,QSettings::IniFormat,0);


#define QT_MOVE_STEP_TIMER MOVE_STEP_PERIOD //仿真时定时间隔

#if QT_MOVE_STEP_TIMER > MOVE_STEP_PERIOD
#error "QT_MOVE_STEP_TIMER error"
#endif

int stepTimer = 0;

QString getItemStr(QTreeWidgetItem *item)
{
    return item->data(0,Qt::UserRole).toString();
}
/*
class MainObj:public QObject
{
  Q_OBJECT
signals:
    screenChange();
public:
    MainObj(QObject *parent = 0);
    ~MainObj();
};
*/
MainObj::MainObj(QObject *parent):QObject(parent)
{

}

void MainObj::emitScreenChangeSignal()
{
    emit this->screenChange();
}

MainObj::~MainObj()
{

}

void MainWindow::setupFileActions()
{
    //QToolBar *tb = new QToolBar(this);
    //tb->setWindowTitle(tr("File Actions"));
    //addToolBar(tb);

    QMenu *menu = new QMenu(tr("文件"), this);
    menuBar()->addMenu(menu);

    QAction *a;

    a = new QAction(tr("新建工程"), this);
    //a->setPriority(QAction::LowPriority);
    ////a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(fileNew()));
    //tb->addAction(a);
    menu->addAction(a);

    //QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
    a = new QAction(tr("打开工程"), this);
    //a->setPriority(QAction::LowPriority);
    ////a->setShortcut(QKeySequence::Open);
    connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    //tb->addAction(a);
    menu->addAction(a);
/*
    a = new QAction(tr("保存"), this);
    //a->setShortcut(QKeySequence::Save);
    connect(a, SIGNAL(triggered()), this, SLOT(fileSave()));
    //tb->addAction(a);
    menu->addAction(a);
*/
    a = new QAction(tr("工程另存为"), this);
    ////a->setShortcut(QKeySequence::Save);
    connect(a, SIGNAL(triggered()), this, SLOT(fileSaveAs()));
    //tb->addAction(a);
    menu->addAction(a);

    menu->addSeparator();

    a = new QAction(tr("退出"), this);
    //a->setPriority(QAction::LowPriority);
    connect(a, SIGNAL(triggered()), this, SLOT(close()));
    menu->addAction(a);

}

void MainWindow::setupViewActions()
{
    //QToolBar *tb = new QToolBar(this);
    //tb->setWindowTitle(tr("File Actions"));
    //addToolBar(tb);

    QMenu *menu = new QMenu(tr("视图"), this);
    menuBar()->addMenu(menu);

    QAction *a;

    //QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
    a = new QAction(tr("状态栏"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileNew()));
    //tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("控制窗口"), this);
    //a->setShortcut(QKeySequence::Open);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    //tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("属性窗口"), this);
    //a->setShortcut(QKeySequence::Save);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileSave()));
    //tb->addAction(a);
    menu->addAction(a);
}


QIcon getTypeIcon(INT8U type)
{
  QIcon icon;
  if(type EQ SCREEN_PROPERTY)
      icon = QIcon::fromTheme(QObject::tr("屏幕"), QIcon(rsrcPath1 + QObject::tr("/屏幕.png")));
  else if(type EQ PROG_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("节目"), QIcon(rsrcPath1 + QObject::tr("/节目.png")));
  else if(type EQ AREA_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("分区"), QIcon(rsrcPath1 + QObject::tr("/分区.png")));
  else if(type EQ PIC_STEXT_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("字幕"), QIcon(rsrcPath1 + QObject::tr("/字幕.png")));
  else if(type EQ PIC_MTEXT_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("文本"), QIcon(rsrcPath1 + QObject::tr("/图文.png")));
  else if(type EQ PIC_TABLE_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("表格"), QIcon(rsrcPath1 + QObject::tr("/表格.png")));
  else if(type EQ PIC_FLASH_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("动画"), QIcon(rsrcPath1 + QObject::tr("/动画.png")));
  else if(type EQ PIC_IMAGE_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("图片"), QIcon(rsrcPath1 + QObject::tr("/图片.png")));
  else if(type EQ CLOCK_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("表盘"), QIcon(rsrcPath1 + QObject::tr("/表盘.png")));
  else if(type EQ TIME_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("时间"), QIcon(rsrcPath1 + QObject::tr("/日历.png")));
  else if(type EQ TIMER_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("计时"), QIcon(rsrcPath1 + QObject::tr("/计时.png")));
  else if(type EQ LUN_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("农历"), QIcon(rsrcPath1 + QObject::tr("/农历.png")));
  else if(type EQ TEMP_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("温度"), QIcon(rsrcPath1 + QObject::tr("/温度.png")));
  else if(type EQ HUMIDITY_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("湿度"), QIcon(rsrcPath1 + QObject::tr("/湿度.png")));
  else if(type EQ NOISE_PROPERTY)
     icon = QIcon::fromTheme(QObject::tr("噪音"), QIcon(rsrcPath1 + QObject::tr("/噪音.png")));

  return icon;
}

void MainWindow::setupEditActions()
{
    QToolBar *tb = new QToolBar(this);
    tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tb->setWindowTitle(tr("File Actions"));
    addToolBar(tb);

    QMenu *menu = new QMenu(tr("添加"), this);
    menuBar()->addMenu(menu);

    QAction *a;
/*
    QAction *actionScreen;
    QAction *actionProg;
    QAction *actionArea;
    QAction *actionSText;
    QAction *actionMText;
    QAction *actionTemp;
    QAction *actionHumidi;
    QAction *actionFlash;
    QAction *actionClock;
    QAction *actionTime;
    QAction *actionNoise;
    QAction *actionNongli;
    QAction *actionTimer;
 */
    QIcon screenIcon = getTypeIcon(SCREEN_PROPERTY);//QIcon::fromTheme(tr("屏幕"), QIcon(rsrcPath1 + tr("/屏幕.png")));
    actionScreen = a = new QAction(screenIcon, tr("屏幕"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), progManage, SLOT(newScreen())); //新建节目
    //tb->addAction(a);

    menu->addAction(a);
    menu->addSeparator();

    QIcon progIcon = getTypeIcon(PROG_PROPERTY);//QIcon::fromTheme("节目", QIcon(rsrcPath1 + tr("/节目22.png")));
    actionProg = a = new QAction(progIcon, tr("节目"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), progManage, SLOT(newProg())); //新建节目
    tb->addAction(a);

    menu->addAction(a);
    menu->addSeparator();
    tb->addSeparator();

    QIcon areaIcon = getTypeIcon(AREA_PROPERTY);//QIcon::fromTheme(tr("分区"), QIcon(rsrcPath1 + tr("/分区.png")));
    actionArea = a = new QAction(areaIcon, tr("分区"), this);
    a->setIconText(tr("分区"));
    //a->setShortcut(QKeySequence::Open);
    connect(a, SIGNAL(triggered()), progManage, SLOT(newArea())); //新建分区
    tb->addAction(a);
    menu->addAction(a);
    menu->addSeparator();
    tb->addSeparator();

    QIcon stextIcon = getTypeIcon(PIC_STEXT_PROPERTY);//QIcon::fromTheme(tr("字幕"), QIcon(rsrcPath1 + tr("/字幕.ico")));
    actionSText = a = new QAction(stextIcon, tr("字幕"), this);
    //a->setShortcut(QKeySequence::Save);
    a->setEnabled(true);//(bool)Get_Pic_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newSText())); //新建节目
    tb->addAction(a);
    menu->addAction(a);

    QIcon mtextIcon = getTypeIcon(PIC_MTEXT_PROPERTY);//QIcon::fromTheme(tr("文本"), QIcon(rsrcPath1 + tr("/图文22.png")));
    actionMText = a = new QAction(mtextIcon, tr("文本"), this);
    //a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Pic_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newPic())); //新建节目
    tb->addAction(a);
    menu->addAction(a);

    QIcon tableIcon = getTypeIcon(PIC_TABLE_PROPERTY);//QIcon::fromTheme(tr("文本"), QIcon(rsrcPath1 + tr("/图文22.png")));
    actionTable = a = new QAction(tableIcon, tr("表格"), this);
    //a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Pic_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newTable())); //新建节目
    tb->addAction(a);
    menu->addAction(a);

    QIcon flashIcon = getTypeIcon(PIC_FLASH_PROPERTY);//QIcon::fromTheme(tr("动画"), QIcon(rsrcPath1 + tr("/动画.ico")));
    actionFlash = a = new QAction(flashIcon, tr("动画"), this);
    //a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Pic_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newFlash()));
    tb->addAction(a);
    menu->addAction(a);

    QIcon imageIcon = getTypeIcon(PIC_IMAGE_PROPERTY);//QIcon::fromTheme(tr("动画"), QIcon(rsrcPath1 + tr("/动画.ico")));
    actionImage = a = new QAction(imageIcon, tr("图片"), this);
    //a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Pic_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newImage()));
    tb->addAction(a);
    menu->addAction(a);

    QIcon clockIcon = getTypeIcon(CLOCK_PROPERTY);//QIcon::fromTheme(tr("表盘"), QIcon(rsrcPath1 + tr("/表盘.ico")));
    actionClock = a = new QAction(clockIcon, tr("表盘"), this);
    //a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Clock_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newClock()));
    tb->addAction(a);
    menu->addAction(a);

    QIcon timeIcon = getTypeIcon(TIME_PROPERTY);//QIcon::fromTheme(tr("时间"), QIcon(rsrcPath1 + tr("/日历22.png")));
    actionTime = a = new QAction(timeIcon, tr("时间"), this);
    //a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Time_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newTime()));
    tb->addAction(a);
    menu->addAction(a);

    QIcon lunIcon = getTypeIcon(LUN_PROPERTY);//QIcon::fromTheme(tr("农历"), QIcon(rsrcPath1 + tr("/农历22.png")));
    actionNongli = a = new QAction(lunIcon, tr("农历"), this);
    //a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Lun_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newLun()));
    tb->addAction(a);
    menu->addAction(a);

    QIcon timerIcon = getTypeIcon(TIMER_PROPERTY);//QIcon::fromTheme(tr("计时"), QIcon(rsrcPath1 + tr("/计时.png")));
    actionTimer = a = new QAction(timerIcon, tr("计时"), this);
    //a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Timer_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newTimer()));
    tb->addAction(a);
    menu->addAction(a);

    QIcon tempIcon = getTypeIcon(TEMP_PROPERTY);//QIcon::fromTheme(tr("温度"), QIcon(rsrcPath1 + tr("/温度22.png")));
    actionTemp = a = new QAction(tempIcon, tr("温度"), this);
    //a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Temp_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newTemp()));
    tb->addAction(a);
    menu->addAction(a);

    QIcon humidityIcon = getTypeIcon(HUMIDITY_PROPERTY);//QIcon::fromTheme(tr("湿度"), QIcon(rsrcPath1 + tr("/湿度.png")));
    actionHumidi = a = new QAction(humidityIcon, tr("湿度"), this);
    //a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Humidity_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newHumidity()));
    tb->addAction(a);
    menu->addAction(a);

    QIcon noiseIcon = getTypeIcon(NOISE_PROPERTY);//QIcon::fromTheme(tr("湿度"), QIcon(rsrcPath1 + tr("/噪音.ico")));
    actionNoise = a = new QAction(noiseIcon, tr("噪音"), this);
    //a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Humidity_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newNoise()));
    tb->addAction(a);
    menu->addAction(a);
    menu->addSeparator();
    tb->addSeparator();

    QIcon delIcon = QIcon::fromTheme(tr("删除"), QIcon(rsrcPath1 + tr("/删除.png")));
    actionDel = a = new QAction(delIcon, tr("删除"), this);
    //a->setShortcut(QKeySequence::Save);
    connect(a, SIGNAL(triggered()), progManage, SLOT(deleteItem())); //删除节目
    tb->addAction(a);
    menu->addAction(a);
}

void MainWindow::actionEnProc(int Type)
{
  if(Type EQ NULL_PROPERTY)
  {
    property->setEnabled(false);
    ctrlMenu->setEnabled(false);
    actionPreview->setEnabled(false);
    actionModiScreenPara->setEnabled(false);
    actionUpdateFirmware->setEnabled(false);
    actionUDisk->setEnabled(false);
    actionSendData->setEnabled(false);
    actionAdjTime->setEnabled(false);
    actionLightness->setEnabled(false);
    actionOpenClose->setEnabled(false);
    actionPreview->setEnabled(false);
    actionScreenPreiew->setEnabled(false);

    actionScreen->setEnabled(true);
    actionProg->setEnabled(false);
    actionArea->setEnabled(false);
    actionSText->setEnabled(false);
    actionMText->setEnabled(false);
    actionTable->setEnabled(false);
    actionTemp->setEnabled(false);
    actionHumidi->setEnabled(false);
    actionFlash->setEnabled(false);
    actionImage->setEnabled(false);
    actionClock->setEnabled(false);
    actionTime->setEnabled(false);
    actionNoise->setEnabled(false);
    actionNongli->setEnabled(false);
    actionTimer->setEnabled(false);
    actionDel->setEnabled(false);


  }
  else if(Type EQ SCREEN_PROPERTY)
  {
      property->setEnabled(true);
      ctrlMenu->setEnabled(true);
      actionPreview->setEnabled(false);
      actionModiScreenPara->setEnabled(true);
      actionUpdateFirmware->setEnabled(true);
      actionUDisk->setEnabled(true);
      actionSendData->setEnabled(true);
      actionAdjTime->setEnabled(true);
      actionLightness->setEnabled(true);
      actionOpenClose->setEnabled(true);
      actionPreview->setEnabled(false);
      actionScreenPreiew->setEnabled(true);

      actionScreen->setEnabled(true);
      actionProg->setEnabled(true);
      actionArea->setEnabled(false);
      actionSText->setEnabled(false);
      actionMText->setEnabled(false);
      actionTable->setEnabled(false);
      actionTemp->setEnabled(false);
      actionHumidi->setEnabled(false);
      actionFlash->setEnabled(false);
      actionImage->setEnabled(false);
      actionClock->setEnabled(false);
      actionTime->setEnabled(false);
      actionNoise->setEnabled(false);
      actionNongli->setEnabled(false);
      actionTimer->setEnabled(false);
      actionDel->setEnabled(true);
  }
  else if(Type EQ PROG_PROPERTY)
  {
      property->setEnabled(true);
      ctrlMenu->setEnabled(true);
      actionPreview->setEnabled(true);
      actionModiScreenPara->setEnabled(true);
      actionUpdateFirmware->setEnabled(true);
      actionUDisk->setEnabled(true);
      actionSendData->setEnabled(true);
      actionAdjTime->setEnabled(true);
      actionLightness->setEnabled(true);
      actionOpenClose->setEnabled(true);
      actionPreview->setEnabled(true);
      actionScreenPreiew->setEnabled(true);

      actionScreen->setEnabled(true);
      actionProg->setEnabled(true);
      actionArea->setEnabled(true);
      actionSText->setEnabled(false);
      actionMText->setEnabled(false);
      actionTable->setEnabled(false);
      actionTemp->setEnabled(false);
      actionHumidi->setEnabled(false);
      actionFlash->setEnabled(false);
      actionImage->setEnabled(false);
      actionClock->setEnabled(false);
      actionTime->setEnabled(false);
      actionNoise->setEnabled(false);
      actionNongli->setEnabled(false);
      actionTimer->setEnabled(false);
      actionDel->setEnabled(true);
  }
  else if(Type EQ AREA_PROPERTY)
  {
      property->setEnabled(true);
      ctrlMenu->setEnabled(true);
      actionPreview->setEnabled(true);
      actionModiScreenPara->setEnabled(true);
      actionUpdateFirmware->setEnabled(true);
      actionUDisk->setEnabled(true);
      actionSendData->setEnabled(true);
      actionAdjTime->setEnabled(true);
      actionLightness->setEnabled(true);
      actionOpenClose->setEnabled(true);
      actionPreview->setEnabled(true);
      actionScreenPreiew->setEnabled(true);

      actionScreen->setEnabled(true);
      actionProg->setEnabled(true);
      actionArea->setEnabled(true);
      actionSText->setEnabled(true);
      actionMText->setEnabled(true);
      actionTable->setEnabled(true);
      actionTemp->setEnabled(true);
      actionHumidi->setEnabled(true);
      actionFlash->setEnabled(true);
      actionImage->setEnabled(true);
      actionClock->setEnabled(true);
      actionTime->setEnabled(true);
      actionNoise->setEnabled(true);
      actionNongli->setEnabled(true);
      actionTimer->setEnabled(true);
      actionDel->setEnabled(true);
  }
  else
  {
      property->setEnabled(true);
      ctrlMenu->setEnabled(true);
      actionPreview->setEnabled(true);
      actionModiScreenPara->setEnabled(true);
      actionUpdateFirmware->setEnabled(true);
      actionUDisk->setEnabled(true);
      actionSendData->setEnabled(true);
      actionAdjTime->setEnabled(true);
      actionLightness->setEnabled(true);
      actionOpenClose->setEnabled(true);
      actionPreview->setEnabled(true);
      actionScreenPreiew->setEnabled(true);

      actionScreen->setEnabled(true);
      actionProg->setEnabled(true);
      actionArea->setEnabled(true);
      actionSText->setEnabled(true);
      actionMText->setEnabled(true);
      actionTable->setEnabled(true);
      actionTemp->setEnabled(true);
      actionHumidi->setEnabled(true);
      actionFlash->setEnabled(true);
      actionImage->setEnabled(true);
      actionClock->setEnabled(true);
      actionTime->setEnabled(true);
      actionNoise->setEnabled(true);
      actionNongli->setEnabled(true);
      actionTimer->setEnabled(true);
      actionDel->setEnabled(true);
  }
}

void MainWindow::setupCtrlActions()
{
    QToolBar *tb = new QToolBar(this);
    tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tb->setWindowTitle(tr("File Actions"));
    addToolBar(tb);

    QMenu *menu = new QMenu(tr("操作"), this);
    ctrlMenu = menu;//控制菜单
    menuBar()->addMenu(menu);
    menu->setEnabled(false);

    QAction *a;

    actionModiScreenPara = a = new QAction(tr("修改屏幕参数"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(modifyScreenPara()));
    //tb->addAction(a);
    menu->addAction(a);
    menu->addSeparator();

    actionUpdateFirmware = a = new QAction(tr("固件升级"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(updateFirmware()));
    //tb->addAction(a);
    menu->addAction(a);
    menu->addSeparator();

    //QAction *actionManualClose; //手动关机
    //QAction *actionManualOpen; //手动开机
    //QAction *atcionGetOCStatus; //获取开关机状态
    actionManualClose = a = new QAction(tr("手动关机"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(setManualClose()));
    //tb->addAction(a);
    menu->addAction(a);

    actionManualOpen = a = new QAction(tr("手动开机"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(setManualOpen()));
    //tb->addAction(a);
    menu->addAction(a);

    actionOpenClose = a = new QAction(tr("定时开关机"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(setOpenCloseTime()));
    //tb->addAction(a);
    menu->addAction(a);

    actionLightness = a = new QAction(tr("调节亮度"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(setLightness()));
    //tb->addAction(a);
    menu->addAction(a);


    QIcon adjTimeIcon = QIcon::fromTheme(tr("校时"), QIcon(rsrcPath1 + tr("/校时.png")));
    actionAdjTime = a = new QAction(adjTimeIcon, tr("校时"), this);
    //a->setShortcut(QKeySequence::Open);
    connect(a, SIGNAL(triggered()), this, SLOT(adjTime()));
    tb->addAction(a);
    menu->addAction(a);
    menu->addSeparator();
    tb->addSeparator();

    QIcon sendIcon = QIcon::fromTheme(tr("发送数据"), QIcon(rsrcPath1 + tr("/发送.png")));
    actionSendData = a = new QAction(sendIcon, tr("发送数据"), this);
    //a->setShortcut(QKeySequence::Open);
    connect(a, SIGNAL(triggered()), this, SLOT(sendDataProc()));
    tb->addAction(a);
    menu->addAction(a);

    QIcon udiskIcon = QIcon::fromTheme(tr("导出U盘"), QIcon(rsrcPath1 + tr("/导U盘.png")));
    actionUDisk = a = new QAction(udiskIcon, tr("导出U盘文件"), this);
    //a->setShortcut(QKeySequence::Open);
    connect(a, SIGNAL(triggered()), this, SLOT(exportUdsikProc()));
    tb->addAction(a);
    menu->addAction(a);
    menu->addSeparator();
    tb->addSeparator();

    //QIcon udiskIcon = QIcon::fromTheme(tr("显示通信状态"), QIcon(rsrcPath1 + tr("/导U盘22.png")));
    actionComStatus = a = new QAction(tr("显示通信状态"), this);
    a->setCheckable(true);
    connect(a, SIGNAL(triggered()), this, SLOT(comStatusShow()));
    //tb->addAction(a);
    menu->addAction(a);
    menu->addSeparator();

    QIcon previewIcon = QIcon::fromTheme("节目预览", QIcon(rsrcPath1 + tr("/预览.png")));
    actionPreview = a = new QAction(previewIcon, tr("节目预览"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(previewProg()));
    tb->addAction(a);
    menu->addAction(a);

    //QIcon previewIcon = QIcon::fromTheme("预览", QIcon(rsrcPath1 + tr("/预览2222.png")));
    actionScreenPreiew = a = new QAction(tr("屏幕预览"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(previewScreen()));
    menu->addAction(a);

    actionTestCard = a = new QAction(tr("生产检测"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(testCard()));
    tb->addAction(a);
}

void MainWindow::setupToolActions()
{
    //QToolBar *tb = new QToolBar(this);
    //tb->setWindowTitle(tr("File Actions"));
    //addToolBar(tb);

    QMenu *menu = new QMenu(tr("工具"), this);
    menuBar()->addMenu(menu);

    QAction *a;

    //QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
    a = new QAction(tr("画图板"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileNew()));
    //tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("计算器"), this);
    //a->setShortcut(QKeySequence::Open);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    //tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("记事本"), this);
    //a->setShortcut(QKeySequence::Open);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    //tb->addAction(a);
    menu->addAction(a);
}

void MainWindow::setupLanguageActions()
{
    //QToolBar *tb = new QToolBar(this);
    //tb->setWindowTitle(tr("File Actions"));
    //addToolBar(tb);

    QMenu *menu = new QMenu(tr("语言"), this);
    menuBar()->addMenu(menu);

    QAction *a;

    //QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
    a = new QAction(tr("简体中文"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileNew()));
    //tb->addAction(a);
    menu->addAction(a);

}

void MainWindow::setupHelpActions()
{
    //QToolBar *tb = new QToolBar(this);
    //tb->setWindowTitle(tr("File Actions"));
    //addToolBar(tb);

    QMenu *menu = new QMenu(tr("帮助"), this);
    menuBar()->addMenu(menu);

    QAction *a;

    //QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
    a = new QAction(tr("关于"), this);
    a->setPriority(QAction::LowPriority);
    //a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(showAboutDialog()));
    //tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("帮助"), this);
    //a->setShortcut(QKeySequence::Open);
    connect(a, SIGNAL(triggered()), this, SLOT(helpFileOpen()));
    //tb->addAction(a);
    menu->addAction(a);
}
/*
void MainWindow::createProgTreeArea()
{
    QDockWidget *dock0 = new QDockWidget(tr("prog"),this);
    //QDockWidget *dock1 = new QDockWidget(tr("area"),this);

    dock0->setAllowedAreas(Qt::LeftDockWidgetArea);
    //dock1->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    treeView = new QTreeView(dock0);
    //listView = new QListView(dock1);

    dock0->setWidget(treeView);
    //dock1->setWidget(listView);
}
*/
//设置当前的全局节目、分区、文件setting str
void MainWindow::setCurSettingsStr(QString str)
{
    curSettingsStr = str;
}

//获取当前的全局节目、分区、文件setting str
QString MainWindow::getCurSettingsStr()
{
    return curSettingsStr;
}

//文件保存
void MainWindow::fileSave()
{
    QString fileName;

    settings.beginGroup("");
    fileName = settings.value("cfgFile").toString(); //工程文件名
    settings.endGroup();

    QFile::copy(PROG_INI_FILE, fileName); //保存老的文件
}

//文件另存为
void MainWindow::fileSaveAs()
{

    //QString fileName;
    QString newFileName;

    newFileName = QFileDialog::getSaveFileName(this, tr("保存工程文件"), ".", tr("工程文件(*.ini)"));
    if(newFileName.length()==0)
        return;

    if(QFile::exists(newFileName)) //文件存在
    {
      if(QFile::remove(newFileName) == false) //删除失败
        {
          QMessageBox::warning(w, tr("提示"),
                                   tr("文件替换失败，请确认该文件是否被其他程序占用") + newFileName, tr("确定"));
          return;
      }

    }

    if(QFile::copy(PROG_INI_FILE, newFileName) == false) //保存老的文件
    {
        QMessageBox::warning(w, tr("提示"),
                                 tr("工程文件保存失败"), tr("确定"));
   }

}

//新建文件
void MainWindow::fileNew()
{
    if(progManage->treeWidget->topLevelItemCount() > 0)
    {
        int Re =  QMessageBox::warning(w, tr("提示"),
                                 tr("当前编辑内容将会被清除重建！"), tr("保存当前内容再新建"),tr("不保存直接新建"),tr("取消"));

        if(Re EQ 0)
        {
            fileSaveAs();
            //return;
        }
        else if(Re EQ 2)
        {
            return;
        }
    }

    int count = progManage->treeWidget->topLevelItemCount();
    for(int i = 0; i < count; i ++)
    {
        QTreeWidgetItem *item = progManage->treeWidget->topLevelItem(0);
        progManage->treeWidget->setCurrentItem(item);
        progManage->_deleteItem(0);

    }

    settings.clear();//clear(); //清除

    //settings.beginGroup("file");
    //settings.setValue("cfgFile", newFileName);
    //settings.endGroup();

    //screenArea->screenSettingsInit();
    progManage->settingsInit();
    //progManage->newScreen();
    //progManage->newProg();
    //progManage->newArea();
    QMessageBox::warning(w, tr("提示"), tr("工程新建成功，请点击菜单\"添加-屏幕\"新建一个屏幕！"), tr("确定"));


}

void MainWindow::showAboutDialog()
{
    QMessageBox::information(w, tr("关于"), tr("LED设计师 2012\r\n\r\n\r\n编译时间  ")+QString(__TIME__) + QString(" ") + QString(__DATE__), tr("确定"));

}

void MainWindow::helpFileOpen() //打开帮助文件
{
    QString strUrl=QApplication::applicationDirPath () ;
    strUrl=QString("file:///%1/mainhelp.chm").arg (strUrl);
    QUrl qqq(strUrl);
    QDesktopServices::openUrl(qqq);


  //QDesktopServices::openUrl(QUrl("file:///C:/Documents and Settings/All Users/Desktop", QUrl::TolerantMode));
}

//打开文件
void MainWindow::fileOpen()
{
    QString newFileName;
    QString oldFileName;

    if(progManage->treeWidget->topLevelItemCount() > 0)
    {
        int Re =  QMessageBox::warning(w, tr("提示"),
                                 tr("当前编辑内容将会被清除！"), tr("保存当前内容再打开"),tr("不保存直接打开"),tr("取消"));

        if(Re EQ 0)
        {
            fileSaveAs();
            //return;
        }
        else if(Re EQ 2)
        {
            return;
        }
    }
/*
    settings.beginGroup("file");
    oldFileName = settings.value("cfgFile").toString(); //工程文件名
    settings.endGroup();
    QFile::remove(oldFileName);
    if(QFile::copy(PROG_INI_FILE, oldFileName)==false) //保存老的文件
    {
        ASSERT_FAILED();
    }
*/
    int count = progManage->treeWidget->topLevelItemCount();
    for(int i = 0; i < count; i ++)
    {
        QTreeWidgetItem *item = progManage->treeWidget->topLevelItem(0);
        progManage->treeWidget->setCurrentItem(item);
        progManage->_deleteItem(0);

    }

    settings.clear();//clear(); //清除

    newFileName = QFileDialog::getOpenFileName(this, tr("打开工程文件"), ".", tr("工程文件(*.ini)"));
    if(newFileName.length()==0)
    {
        return;
    }


    QSettings tempSettings(newFileName,QSettings::IniFormat,0);
    QStringList list = tempSettings.allKeys();
    int num = list.size();

    for(int i = 0; i < num; i ++)
    {
        settings.setValue(list.at(i), tempSettings.value(list.at(i)));
    }


    settings.beginGroup("file");
    settings.setValue("cfgFile", newFileName);
    settings.endGroup();

    //settings.setPath(QSettings::IniFormat, QSettings::UserScope, PROG_INI_FILE);

    progManage->settingsInit();
}

void MainWindow::settingsInit()
{/*
    QStringList str;

    settings.beginGroup("screen");
    str = settings.allKeys();
    //if(str.isEmpty() == true)
    {
        int xLen = 256;
        int yLen = 256;
        int color = 0x02;

        settings.setValue("width", xLen);
        settings.setValue("height", yLen);
        settings.setValue("color", color);
    }
    settings.endGroup();
    //color =
   //progManage->settingsInit();
*/
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //property->progProperty->getSettingsFromWidget();
}

void MainWindow::updateTreeWidget(QMdiSubWindow *subWin)
{

    //subWin->childAt()
  QList<QMdiSubWindow *> subWinList;

  subWinList = mdiArea->subWindowList(); //子窗口指针列表
  int num = subWinList.size(); //子窗口个数
  for(int i = 0; i < num; i ++)
  {
    if(subWin EQ subWinList.at(i))
    {
       if(progManage->treeWidget->topLevelItemCount() > i)
       {
          qDebug("update screen %d",i);
          MDISubWinClickFlag = 1;
          //progManage->clickItem(progManage->treeWidget->topLevelItem(i),0);
          if(w->screenArea->screenItem != progManage->treeWidget->topLevelItem(i))
            progManage->treeWidget->setCurrentItem(progManage->treeWidget->topLevelItem(i));
       }
    }
  }


//progManage->clickItem(((CscreenArea *)(subWin->widget()))->screenItem,0);

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    settingsInit();
    //QGridLayout *gridLayout;
    setToolButtonStyle(Qt::ToolButtonFollowStyle);

    mdiArea = new QMdiArea(this);
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


    property = new Cproperty(this);
    progManage = new CprogManage(this);
    comStatus = new CcomStatus(this);

    comStatus->hide(); //启动是隐藏
    /*
    widget = new QWidget(this);
    widget->setAutoFillBackground(true);
    QPalette *palette;
    palette = new QPalette();
    palette->setColor(QPalette::Background, QColor(Qt::white));
    widget->setPalette(*palette);
*/
    //screenArea =  new CscreenArea;//CshowArea(this, 1);

    addDockWidget(Qt::LeftDockWidgetArea, progManage);
    addDockWidget(Qt::BottomDockWidgetArea, property);
    addDockWidget(Qt::RightDockWidgetArea, comStatus);

    setupFileActions();
    //setupViewActions();
    setupEditActions();
    setupCtrlActions();
    setupLanguageActions();
    setupHelpActions();



    /*
    gridLayout ->addWidget(progMange, 0, 0);//,0,0,2,2);
    gridLayout ->addWidget(showArea, 0, 1);
    gridLayout ->addWidget(property, 1, 0);
    //area = new CareaProperty(this);
    //gridLayout ->addWidget(area, 1, 0);//,0,0,2,2);

    //sArea = new showArea(this);
    //gridLayout ->addWidget(sArea, 0, 1);
    */
    //setCentralWidget(widget);
//screenArea->newShowArea();
    //setLayout(gridLayout);
   setCentralWidget(mdiArea);
   MDISubWinClickFlag = 0;

   previewWin = new CpreviewWin(this);//new QMainWindow(w);
   previewArea =  new CscreenArea(previewWin);
   previewWin->setCentralWidget(previewArea);

   //QHBoxLayout *hLayout = new QHBoxLayout(previewWin);
   //hLayout->addWidget(previewArea);
   //hLayout->setSizeConstraint(QLayout::SetFixedSize);
   //previewWin->setLayout(hLayout);

   //initComStatus(); //通信状态初始化

   timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(previewProc()));

   mmtimer = new MMTimer(QT_MOVE_STEP_TIMER, this);
   connect(mmtimer, SIGNAL(timeout()), this, SLOT(previewProc()));

   setWindowTitle(tr(APP_NAME));
}

void MainWindow::screenCardParaChangeProc()
{
  this->property->screenCardParaChangeProc();
}

MainWindow::~MainWindow()
{

}

QMdiSubWindow *getSubWinByIndex(QMdiArea *parentArea, int index)
{
  QList<QMdiSubWindow *> subWinList;

  subWinList = parentArea->subWindowList();
  if(subWinList.size() > index)
  {
    return subWinList.at(index);
  }
  else
  {
    ASSERT_FAILED();
    return (QMdiSubWindow *)0;
  }
}

//返回-1表示没有这个子项
int getIndexBySubWin(QMdiArea *parentArea, QMdiSubWindow *subWin)
{
    QList<QMdiSubWindow *> subWinList;

    subWinList = parentArea->subWindowList();
    for(int i = 0; i < subWinList.size();i ++)
    {
        if(subWinList.at(i) == subWin)
         return i;
    }

    ASSERT_FAILED();
    return -1;

}

//修改当前屏幕参数
void MainWindow::modifyScreenPara()
{
  QString str;
  INT8U Re;

  Re = verifyPSW();
  if(Re EQ 0)
      return;

  str = w->screenArea->getCurrentScreenStr(); //当前屏幕str

  if(Re EQ 1 || Re EQ 2)
  {
      QDialog *facParaWin = new QDialog(this);
      QHBoxLayout *hLayout = new QHBoxLayout(facParaWin);

      facParaWin->setWindowTitle(tr("修改屏幕参数"));
      CfacScreenProperty *facScreenProperty = new CfacScreenProperty(MODI_SCN, facParaWin);
      CcomTest *comTest = new CcomTest(facParaWin);

      facScreenProperty->setSettingsToWidget(str);
      comTest->setSettingsToWidget(str);

      hLayout->addWidget(facScreenProperty);
      hLayout->addWidget(comTest);

      facParaWin->setLayout(hLayout);
      facParaWin->setAttribute(Qt::WA_DeleteOnClose);
      connect(facScreenProperty->endButton, SIGNAL(clicked()), facParaWin, SLOT(close()));
      facParaWin->exec();
  }
  else if(Re EQ 3)
  {
    CInvalidDateDialog *invalidDateDialog = new CInvalidDateDialog(this);
    invalidDateDialog->exec();
  }

}

//固件升级
void MainWindow::updateFirmware()
{
  INT8U re, flag;

  re = verifyPSW();
  if(re EQ 0)
    return;

  if(re EQ 4) //密码在4级才能显示生成文件的按钮,内部使用
      flag = 1;
  else
      flag = 0;

  CupdateFirmwareDialog *updateFirmwareDialog = new CupdateFirmwareDialog(flag, this);
  updateFirmwareDialog->exec();
}

//设置亮度
void MainWindow::setLightness()
{
  ClightnessDialog *lightnessDialog = new ClightnessDialog(this);
  QString str = w->screenArea->getCurrentScreenStr();
  lightnessDialog->setSettingsToWidget(str);

  lightnessDialog->exec();
}

//校准时间
void MainWindow::adjTime()
{
  CadjTimeDialog *adjTimeDialog = new CadjTimeDialog(this);
  adjTimeDialog->exec();
}

//设置开关机时段
void MainWindow::setOpenCloseTime()
{
    CopenCloseDialog *openCloseDialog = new CopenCloseDialog(this);
    QString str = w->screenArea->getCurrentScreenStr();
    openCloseDialog->setSettingsToWidget(str);

    openCloseDialog->exec();
}

//手动关机
void MainWindow::setManualClose()
{
    char Flag;
    INT8U Temp[100];
    int len;

    if(w->comStatus->comThread->isRunning())//当前线程还在运行
        return;

    QString screenStr = w->screenArea->getCurrentScreenStr();

    Flag = CLOSE_FLAG;
#if QT_SIM_EN
    makeProtoBufData(screenStr, SIM_MODE, C_SCREEN_OC | WR_CMD, &Flag, 1);
#else
    makeProtoBufData(screenStr, COM_MODE, C_SCREEN_OC | WR_CMD, &Flag, 1);
#endif

    bool re = w->comStatus->waitComEnd(Temp, sizeof(Temp), &len);
    if(re EQ true)
    {
        QMessageBox::information(w,QObject::tr("提示"),
                               QObject::tr(SEND_PARA_OK_STR),QObject::tr("确定"));
        //close(); //校时成功则关闭

    }
    else
    {
        QMessageBox::warning(w, QObject::tr("提示"),
                               QObject::tr(SEND_PARA_FAIL_STR),QObject::tr("确定"));
    }
}

//手动开机
void MainWindow::setManualOpen()
{
    char Flag;
    INT8U Temp[100];
    int len;

    if(w->comStatus->comThread->isRunning())//当前线程还在运行
        return;

    QString screenStr = w->screenArea->getCurrentScreenStr();

    Flag = 0;
#if QT_SIM_EN
    makeProtoBufData(screenStr, SIM_MODE, C_SCREEN_OC | WR_CMD, &Flag, 1);
#else
    makeProtoBufData(screenStr, COM_MODE, C_SCREEN_OC | WR_CMD, &Flag, 1);
#endif

    bool re = w->comStatus->waitComEnd(Temp, sizeof(Temp), &len);
    if(re EQ true)
    {
        QMessageBox::information(w,QObject::tr("提示"),
                               QObject::tr(SEND_PARA_OK_STR),QObject::tr("确定"));
        //close(); //校时成功则关闭

    }
    else
    {
        QMessageBox::warning(w, QObject::tr("提示"),
                               QObject::tr(SEND_PARA_FAIL_STR),QObject::tr("确定"));
    }
}

void MainWindow::sendDataProc()
{
   CsendDataDialog *sendDataDialog = new CsendDataDialog(0, this);
   sendDataDialog->exec();
}

void MainWindow::exportUdsikProc()
{
    CsendDataDialog *sendDataDialog = new CsendDataDialog(1, this);
    sendDataDialog->exec();
}

//预览当前节目
void MainWindow::previewProg()
{
  preview(PREVIEW_PROG);
}

//预览当前屏幕下的所有节目
void MainWindow::previewScreen()
{
  preview(PREVIEW_SCREEN);
}

//预览统一处理
void MainWindow::preview(INT8U previewMode)
{
  QString screenStr;//progStr;
  INT8U Screen_No,re;


  if(w->comStatus->comThread->isRunning())//当前线程还在运行
      return;

  //生成仿真文件
  Mem_Open();

  screenStr = getItemStr(screenArea->screenItem);

  Screen_No = progManage->treeWidget->indexOfTopLevelItem(screenArea->screenItem);
  if(screenArea->screenItem->childCount() EQ 0)
  {
      if(previewMode EQ PREVIEW_PROG)
          QMessageBox::information(w, tr("提示"),
                               tr("请先选择一个预览的节目"),tr("确定"));
      else
          QMessageBox::warning(w, tr("提示"),
                                   tr("该屏幕下没有节目!"),tr("确定"));
      return;
  }

  Ram_Init();

#if QT_SIM_EN
  re = makeProtoFileData(screenStr, SIM_MODE, 0xFFFFFFFF);
#else
  re = makeProtoFileData(screenStr, PREVIEW_MODE, 0xFFFFFFFF);
#endif

  if(re EQ 0)
      return;

  Preview_Prog_No = screenArea->screenItem->indexOfChild(screenArea->progItem);
  Preview_Mode = previewMode;
  //setCentralWidget(mdiArea);
  //CMdiSubWindow *subWin = new CMdiSubWindow;
  //subWin->previewFlag = 1; //用于仿真的子窗口
  timerFlag = 0;
  stepTimer = 0;

  //previewWin = new CpreviewWin(w);//new QMainWindow(w);
 if(QT_SIM_EN EQ 0)
   previewWin->setWindowModality(Qt::WindowModal);

/*
  previewArea =  new CscreenArea(previewWin);
  previewArea->setWindowModality(Qt::WindowModal);
  */

  //previewArea->setGeometry(0,0,Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height); //resize(Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height);
  //previewArea->setFixedSize(previewArea->size());
  previewArea->setFixedSize(Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height);
  //previewWin->resize(Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height);
  previewWin->setFixedSize(previewWin->sizeHint());
  //previewArea->setFixedSize(Screen_Para.Base_Para.Width, Screen_Para.Base_Para.Height);
  //previewWin->setFixedSize(previewWin->sizeHint());

  previewArea->previewFlag = 1;
  //previewArea->updateFlag = true;

  //previewWin->setAttribute(Qt::WA_DeleteOnClose);

  QString title = tr("预览-")+QString::number(Screen_No + 1) + tr("屏幕");
  if(Preview_Mode EQ PREVIEW_PROG)
      title = title + QString("-") + QString::number(Preview_Prog_No + 1) + tr("节目");
  previewWin->move((width() - previewArea->width())/2, (height() - previewArea->height())/2);

  previewWin->setWindowTitle(title);

  Para_Init(); //显示初始化。

  memcpy(&previewArea->screenPara, &Screen_Para, sizeof(Screen_Para));
  previewWin->show();
  //previewWin->setFixedSize(previewWin->size());


  timer->stop();
  timer->start(QT_MOVE_STEP_TIMER);

  //mmtimer->start();
}

void MainWindow::comStatusShow()
{
  if(actionComStatus->isChecked()==true)
      comStatus->show();
  else
      comStatus->hide();
}

void MainWindow::previewTimerProc()
{
    Show_Timer_Proc();

    previewArea->previewFlag = 1;//预览窗口
    //previewArea->updateFlag = 1;
    memcpy(previewArea->showData.Color_Data, Show_Data.Color_Data, sizeof(Show_Data.Color_Data));
    TRACE();
    previewArea->update(); //刷新显示区域
    TRACE();
}

void MainWindow::previewProc()
{
  static INT32U msCounts = 0;

  //mmtimer->stop();

  msCounts += QT_MOVE_STEP_TIMER;
  stepTimer += QT_MOVE_STEP_TIMER;

  Get_Cur_Time();
  Pub_Timer.Ms = msCounts;
  Pub_Timer.Ms100 = msCounts / 100;
  Pub_Timer.Sec = Cur_Time.Time[T_SEC]; //定时器更新

  Calc_Screen_Color_Num(); //重新计算屏幕颜色，可能在其他地方有修改

  Show_Main_Proc();
  Show_Main_Proc();
  Show_Main_Proc();

  if(stepTimer >= MOVE_STEP_PERIOD)
  {
      stepTimer = 0;
      previewTimerProc();
  }

  //mmtimer->start();
}

void MainWindow::testCard()
{
  INT8U dataBuf[10];
  INT8U Temp[20];
  int len;

  loop:
  QDateTime dateTime = QDateTime::currentDateTime(); //当前时间s

  dataBuf[T_YEAR] = dateTime.date().year() - 2000;
  dataBuf[T_MONTH] = dateTime.date().month();
  dataBuf[T_DATE] = dateTime.date().day();
  dataBuf[T_WEEK] = dateTime.date().dayOfWeek();
  if(dataBuf[T_WEEK] EQ 7)
      dataBuf[T_WEEK] = 0;
  dataBuf[T_HOUR] = dateTime.time().hour();
  dataBuf[T_MIN] = dateTime.time().minute();
  dataBuf[T_SEC] = dateTime.time().second();

  QString screenStr = w->screenArea->getCurrentScreenStr();

  //发送系统校时命令
  makeProtoBufData(screenStr, COM_MODE, C_SCREEN_TIME | WR_CMD, (char *)dataBuf, 7);

  bool re = w->comStatus->waitComEnd(Temp, sizeof(Temp), &len);
  if(re EQ false)
  {
      QMessageBox::critical(w, tr("提示"),
                             tr("控制卡自检失败:设置系统时间失败"),tr("确定"));
      return;

  }

  //发送硬件自检命令
    dataBuf[0] = 0x03; //进入硬件自检

    makeProtoBufData(screenStr, COM_MODE, C_SELF_TEST | WR_CMD, (char *)dataBuf, 1);

    re = w->comStatus->waitComEnd(Temp, sizeof(Temp), &len);
    if(re EQ false)
    {
        QMessageBox::critical(w, tr("提示"),
                             tr("控制卡自检失败:没有收到硬件自检命令应答!"),tr("确定"));
        return;
    }
    else if(len > 0 && Temp[FDATA] > 0)
    {
        QString reStr ="";

        if(GET_BIT(Temp[0], 0))
            reStr += tr(",数据存储器自检失败");

        if(GET_BIT(Temp[0], 1))
            reStr += tr(",时钟自检失败");

        if(GET_BIT(Temp[0], 2))
            reStr += tr(",加密数据自检失败");

        QMessageBox::critical(w, tr("提示"),
                             tr("控制卡自检失败:") + reStr,tr("确定"));
        return;
    }

    //发送加密命令
      dataBuf[0] = 0x05; //加密

      makeProtoBufData(screenStr, COM_MODE, C_SELF_TEST | WR_CMD, (char *)dataBuf, 1);

      re = w->comStatus->waitComEnd(Temp, sizeof(Temp), &len);
      if(re EQ false)
      {
          QMessageBox::critical(w, tr("提示"),
                                 tr("控制卡自检失败:加密命令发送失败!"),tr("确定"));
          return;

      }

    Delay_ms(500); //延时等控制器复位
    //发送接口自检命令
    dataBuf[0] = 0x04; //进入扫描接口自检

    makeProtoBufData(screenStr, COM_MODE, C_SELF_TEST | WR_CMD, (char *)dataBuf, 1);

    re = w->comStatus->waitComEnd(Temp, sizeof(Temp), &len);
    if(re EQ false)
    {
      QMessageBox::critical(w, tr("提示"),
                             tr("控制卡自检失败:发送接口自检命令失败"),tr("确定"));
      return;

    }
    else
    {
       re = QMessageBox::information(w, tr("提示"),
                               tr("请逐个接口接入显示屏幕，观察屏幕显示是否正确，如显示正确，则控制卡自检成功!"),tr("进入下一个检测"), tr("退出检测流程"));

       if(re EQ 0)
           goto loop;
       else
       {
           //发送复位命令
             dataBuf[0] = 0x01; //复位

             makeProtoBufData(screenStr, COM_MODE, C_SELF_TEST | WR_CMD, (char *)dataBuf, 1);

         }
   }
}

void traversalControl(const QObjectList& q)
{
   for(int i=0;i<q.length();i++)
    {
        if(!q.at(i)->children().empty())
        {
           traversalControl(q.at(i)->children());
        }
        else
        {

            QObject* o = q.at(i);
            if(o->inherits("QComboBox"))
            {
              QComboBox* b = qobject_cast<QComboBox *>(o);
              b->clear();//setText("<>");
            }
        }
    }
}

CinputPSWDialog::CinputPSWDialog(INT8U *re, QWidget *parent):QDialog(parent)
{
    QVBoxLayout *vLayout = new QVBoxLayout(this);
    QHBoxLayout *hLayout = new QHBoxLayout(this);

    verifyRe = re;
    *verifyRe = false;

    QLabel *pswLabel = new QLabel(tr("请输入密码"), this);
    lineEdit = new QLineEdit(this);
    lineEdit->setEchoMode(QLineEdit::Password);
    hLayout->addWidget(pswLabel);
    hLayout->addWidget(lineEdit);
    vLayout->addLayout(hLayout);

    reLabel = new QLabel(" ", this);
    vLayout->addWidget(reLabel);

    hLayout = new QHBoxLayout(this);
    okButton = new QPushButton(tr("确定"), this);
    cancelButton = new QPushButton(tr("取消"), this);
    hLayout->addStretch(1);
    hLayout->addWidget(okButton);
    hLayout->addWidget(cancelButton);

    vLayout->addLayout(hLayout);
    setLayout(vLayout);

    this->setWindowTitle(tr("密码验证"));
    setAttribute(Qt::WA_DeleteOnClose);

    connect(okButton, SIGNAL(clicked()), this, SLOT(okClickProc()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(close()));
}

void CinputPSWDialog::okClickProc()
{
   if(lineEdit->text() == "888")//1级密码
    {
       *verifyRe = 1;
      close();
   }
   else if(lineEdit->text() == "168")//2级密码
   {
       *verifyRe = 2;
       close();
   }
   else if(lineEdit->text() == "112233")
   {
       *verifyRe = 3;
       close();
   }
   else if(lineEdit->text() =="445566") //最高级密码
   {
       *verifyRe = 4;
       close();
   }
   else
   {
       reLabel->setText(tr("密码错误!"));
       *verifyRe = 0;
   }
}

CinputPSWDialog::~CinputPSWDialog()
{

}


INT8U verifyPSW()
{/*

    bool ok;
    QString text = CinputPSWDialog::getText(0, QObject::tr("密码验证"),
                                            QObject::tr("请输入密码:"), QLineEdit::Password,
                                            QObject::tr("haha"), &ok);

    if(ok)
    {
       if(text != "168")
       {
          QMessageBox::information(w, QObject::tr("提示"),
                                 QObject::tr("输入密码错误"),QObject::tr("确定"));
          return false;
       }
       else
          return true;
     }
     else
        return false;
  */

    INT8U re;

    CinputPSWDialog *pswDialog= new CinputPSWDialog(&re, w);
    pswDialog->exec();

    return re;
}
