#include "mainwindow.h"
#include "progProperty.h"

QSettings settings("test", "test");
void MainWindow::setupFileActions()
{
    QToolBar *tb = new QToolBar(this);
    tb->setWindowTitle(tr("File Actions"));
    addToolBar(tb);

    QMenu *menu = new QMenu(tr("新建"), this);
    menuBar()->addMenu(menu);

    QAction *a;

    //QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
    a = new QAction(tr("打开"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(settingsInit()));
    tb->addAction(a);
    menu->addAction(a);

    a = new QAction(tr("保存"), this);
    a->setShortcut(QKeySequence::Open);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("另存为"), this);
    a->setShortcut(QKeySequence::Save);
    //connect(a, SIGNAL(triggered()), this, SLOT(fileSave()));
    //a->setEnabled(false);
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

    actionSave = a = new QAction(tr("图文"), this);
    a->setShortcut(QKeySequence::Save);
    connect(a, SIGNAL(triggered()), progManage, SLOT(newPic())); //新建节目
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("动画"), this);
    a->setShortcut(QKeySequence::Save);
    connect(a, SIGNAL(triggered()), progManage, SLOT(newFlash()));
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("表盘"), this);
    a->setShortcut(QKeySequence::Save);
    connect(a, SIGNAL(triggered()), progManage, SLOT(newClock()));
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("日期时间"), this);
    a->setShortcut(QKeySequence::Save);
    connect(a, SIGNAL(triggered()), progManage, SLOT(newTime()));
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("计时"), this);
    a->setShortcut(QKeySequence::Save);
    connect(a, SIGNAL(triggered()), progManage, SLOT(newTimer()));
    tb->addAction(a);
    menu->addAction(a);

    actionSave = a = new QAction(tr("温度"), this);
    a->setShortcut(QKeySequence::Save);
    connect(a, SIGNAL(triggered()), progManage, SLOT(newTemp()));
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
    //connect(a, SIGNAL(triggered()), this, SLOT(fileNew()));
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

void MainWindow::settingsInit()
{
    QStringList str;

    settings.beginGroup("screen");
    str = settings.allKeys();
    //if(str.isEmpty() == true)
    {
        int xLen = 256;
        int yLen = 256;
        int color = 0x02;

        settings.setValue("xLen", xLen);
        settings.setValue("yLen", yLen);
        settings.setValue("color", color);
    }
    settings.endGroup();
    //color =
   //progManage->settingsInit();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //property->progProperty->getSettingsFromWidget();
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    settingsInit();
    //QGridLayout *gridLayout;
    setToolButtonStyle(Qt::ToolButtonFollowStyle);

    //gridLayout = new QGridLayout(this);
    progManage = new CprogManage(this);
    property = new Cproperty(this);

    widget = new QWidget(this);
    widget->setAutoFillBackground(true);
    QPalette *palette;
    palette = new QPalette();
    palette->setColor(QPalette::Background, QColor(Qt::white));
    widget->setPalette(*palette);

    screenArea =  new CscreenArea(widget);//CshowArea(this, 1);

    //CshowArea *p = new CshowArea(screenArea,2);
    //p->update();
    //p = new CshowArea(screenArea,1);

    //settings = new QSettings();

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
    setCentralWidget(widget);
//screenArea->newShowArea();
    //setLayout(gridLayout);

}

MainWindow::~MainWindow()
{

}
