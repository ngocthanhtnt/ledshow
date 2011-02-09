#include "mainwindow.h"
#include "progProperty.h"
#include "progManage.h"
#include <QFileDialog>
#include <QMessageBox>


extern MainWindow *w;
//节目配置文件
QSettings settings(PROG_INI_FILE,QSettings::IniFormat,0);
//屏幕配置文件
QSettings screenSettings(SCREEN_INI_FILE,QSettings::IniFormat,0);
//控制卡配置文件
QSettings cardSettings(CARD_INI_FILE,QSettings::IniFormat,0);

void MainWindow::setupFileActions()
{
    QToolBar *tb = new QToolBar(this);
    tb->setWindowTitle(tr("File Actions"));
    addToolBar(tb);

    QMenu *menu = new QMenu(tr("文件"), this);
    menuBar()->addMenu(menu);

    QAction *a;

    a = new QAction(tr("新建"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(fileNew()));
    tb->addAction(a);
    menu->addAction(a);

    //QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
    a = new QAction(tr("打开"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::Open);
    connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("保存"), this);
    a->setShortcut(QKeySequence::Save);
    connect(a, SIGNAL(triggered()), this, SLOT(fileSave()));
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("另存为"), this);
    a->setShortcut(QKeySequence::Save);
    connect(a, SIGNAL(triggered()), this, SLOT(fileSaveAs()));
    tb->addAction(a);
    menu->addAction(a);

    menu->addSeparator();

    a = new QAction(tr("退出"), this);
    a->setPriority(QAction::LowPriority);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileSaveAs()));
    menu->addAction(a);

}

void MainWindow::setupViewActions()
{
    QToolBar *tb = new QToolBar(this);
    tb->setWindowTitle(tr("File Actions"));
    addToolBar(tb);

    QMenu *menu = new QMenu(tr("视图"), this);
    menuBar()->addMenu(menu);

    QAction *a;

    //QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
    a = new QAction(tr("状态栏"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::New);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileNew()));
    tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("控制窗口"), this);
    a->setShortcut(QKeySequence::Open);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("属性窗口"), this);
    a->setShortcut(QKeySequence::Save);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileSave()));
    tb->addAction(a);
    menu->addAction(a);
}

void MainWindow::setupEditActions()
{
    QToolBar *tb = new QToolBar(this);
    tb->setWindowTitle(tr("File Actions"));
    addToolBar(tb);

    QMenu *menu = new QMenu(tr("编辑"), this);
    menuBar()->addMenu(menu);

    QAction *a;

    a = new QAction(tr("屏幕"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), progManage, SLOT(newScreen())); //新建节目
    tb->addAction(a);

    menu->addAction(a);
    menu->addSeparator();

    //QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
    a = new QAction(tr("节目"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), progManage, SLOT(newProg())); //新建节目
    tb->addAction(a);

    menu->addAction(a);
    menu->addSeparator();

    a = new QAction(tr("分区"), this);
    a->setShortcut(QKeySequence::Open);
    connect(a, SIGNAL(triggered()), progManage, SLOT(newArea())); //新建节目
    tb->addAction(a);
    menu->addAction(a);
    menu->addSeparator();

    actionSave = a = new QAction(tr("字幕"), this);
    a->setShortcut(QKeySequence::Save);
    a->setEnabled(true);//(bool)Get_Pic_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newSText())); //新建节目
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("图文"), this);
    a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Pic_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newPic())); //新建节目
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("动画"), this);
    a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Pic_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newFlash()));
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("表盘"), this);
    a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Clock_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newClock()));
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("时间"), this);
    a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Time_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newTime()));
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("计时"), this);
    a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Timer_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newTimer()));
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("温度"), this);
    a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Temp_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newTemp()));
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("农历"), this);
    a->setShortcut(QKeySequence::Save);
    a->setEnabled((bool)Get_Lun_Show_En());
    connect(a, SIGNAL(triggered()), progManage, SLOT(newLun()));
    tb->addAction(a);
    menu->addAction(a);
    menu->addSeparator();

    actionSave = a = new QAction(tr("删除"), this);
    a->setShortcut(QKeySequence::Save);
    connect(a, SIGNAL(triggered()), progManage, SLOT(deleteItem())); //删除节目
    tb->addAction(a);
    menu->addAction(a);
}

void MainWindow::setupCtrlActions()
{
    QToolBar *tb = new QToolBar(this);
    tb->setWindowTitle(tr("File Actions"));
    addToolBar(tb);

    QMenu *menu = new QMenu(tr("控制"), this);
    menuBar()->addMenu(menu);

    QAction *a;

    //QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
    a = new QAction(tr("预览"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), progManage, SLOT(preview()));
    tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("校时"), this);
    a->setShortcut(QKeySequence::Open);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("数据发送"), this);
    a->setShortcut(QKeySequence::Open);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("生成U盘文件"), this);
    a->setShortcut(QKeySequence::Open);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    tb->addAction(a);
    menu->addAction(a);
}

void MainWindow::setupToolActions()
{
    QToolBar *tb = new QToolBar(this);
    tb->setWindowTitle(tr("File Actions"));
    addToolBar(tb);

    QMenu *menu = new QMenu(tr("工具"), this);
    menuBar()->addMenu(menu);

    QAction *a;

    //QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
    a = new QAction(tr("画图板"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::New);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileNew()));
    tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("计算器"), this);
    a->setShortcut(QKeySequence::Open);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("记事本"), this);
    a->setShortcut(QKeySequence::Open);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    tb->addAction(a);
    menu->addAction(a);
}

void MainWindow::setupHelpActions()
{
    QToolBar *tb = new QToolBar(this);
    tb->setWindowTitle(tr("File Actions"));
    addToolBar(tb);

    QMenu *menu = new QMenu(tr("帮助"), this);
    menuBar()->addMenu(menu);

    QAction *a;

    //QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
    a = new QAction(tr("关于"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::New);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileNew()));
    tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("帮助"), this);
    a->setShortcut(QKeySequence::Open);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    tb->addAction(a);
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
    fileName = settings.value("cfgFile").toString(); //配置文件名
    settings.endGroup();

    QFile::copy(PROG_INI_FILE, fileName); //保存老的文件
}

//文件另存为
void MainWindow::fileSaveAs()
{

    //QString fileName;
    QString newFileName;

    newFileName = QFileDialog::getSaveFileName(this, tr("保存配置文件"), ".", tr("配置文件(.ini)"));
    if(newFileName.length()==0)
        return;

    if(QFile::copy(PROG_INI_FILE, newFileName) == true) //保存老的文件
    {
      settings.beginGroup("file");
      settings.setValue("cfgFile", newFileName); //配置文件名
      settings.endGroup();
   }

}

//新建文件
void MainWindow::fileNew()
{
    QString newFileName;

    newFileName = QFileDialog::getSaveFileName(this, tr("新建配置文件"), ".", tr("配置文件(.ini)"));
    if(newFileName.length()==0)
        return;

    fileSave(); //保存老文件

    settings.remove("program");//clear(); //清除

    settings.beginGroup("file");
    settings.setValue("cfgFile", newFileName);
    settings.endGroup();

    w->progManage->settingsInit();
    w->progManage->newProg();
    w->progManage->newArea();
}

//打开文件
void MainWindow::fileOpen()
{
    QString newFileName;
    QString oldFileName;

    newFileName = QFileDialog::getOpenFileName(this, tr("打开配置文件"), ".", tr("配置文件(.ini)"));
    if(newFileName.length()==0)
    {
        return;
    }

    settings.beginGroup("file");
    oldFileName = settings.value("cfgFile").toString(); //配置文件名
    settings.endGroup();

    QFile::remove(oldFileName);
    if(QFile::copy(PROG_INI_FILE, oldFileName)==false) //保存老的文件
    {
        ASSERT_FAILED();
        //qDebug("file open copy oldFileName error");
    }

    QFile::remove(PROG_INI_FILE);
    if(QFile::copy(newFileName, PROG_INI_FILE)==false)
    {
        ASSERT_FAILED();
        //qDebug("file open copy PROG_INI_FILE error");
    }

    settings.beginGroup("file");
    settings.setValue("cfgFile", newFileName);
    settings.endGroup();

    w->progManage->settingsInit();
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
  QList<QMdiSubWindow *> subWinList;

  subWinList = mdiArea->subWindowList(); //子窗口指针列表
  int num = subWinList.size(); //子窗口个数
  for(int i = 0; i < num; i ++)
  {
    if(subWin EQ subWinList.at(i))
    {
       if(w->progManage->treeWidget->topLevelItemCount() > i)
       {
          w->progManage->clickItem(w->progManage->treeWidget->topLevelItem(i),0);
       }
    }
  }
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

    setupFileActions();
    setupViewActions();
    setupEditActions();
    setupCtrlActions();
    setupToolActions();
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
    //w->progManage->settingsInit();

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
