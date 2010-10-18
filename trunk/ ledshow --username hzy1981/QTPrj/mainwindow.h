#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "..\LED_Cfg.h"
#include <QtGui/QMainWindow>
#include <QLineEdit.h>
#include <QListView>
#include <QDockWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QStackedWidget>
#include <QDialog>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QSettings>
#include "showArea.h"
#include "areaProperty.h"
#include "progManage.h"
#include "property.h"
#include "timerProperty.h"



//主窗口
class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void settingsInit();
private:
    int color;

    QString curSettingsStr; //当前的节目、分区或文件的settings的STR

    void setupFileActions();
    void setupViewActions();
    void setupEditActions();
    void setupCtrlActions();
    void setupToolActions();
    void setupHelpActions();
    //void settingsInit();

    QAction *actionSave;
public:
    QWidget *widget;
    CprogManage *progManage; //节目管理
    Cproperty *property; //属性编辑

    CscreenArea *screenArea; //显示区域

    //QWidget *widget;

    //QLabel *Label;
//protected:
    //void paintEvent(QPaintEvent *);
public:
    void setCurSettingsStr(QString str);  //获取当前的settings的str
    QString getCurSettingsStr();   //设置当前settings的str

    //int getColor();
    void closeEvent(QCloseEvent *event);
    //void createProgTreeArea();
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
