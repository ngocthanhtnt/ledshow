#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "..\Stm32\usr\app\LED_Cfg.h"
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
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QList>
#include <QObjectList>
#include "showArea.h"
#include "areaProperty.h"
#include "progManage.h"
#include "property.h"
#include "timerProperty.h"
#include "Communication.h"


#define CARD_INI_FILE ".\\cfg\\card.ini"
#define SCREEN_INI_FILE ".\\cfg\\screen.ini"
#define PROG_INI_FILE ".\\cfg\\temp.ini"

#define PROTO_DATA_FILE ".\\data\\protoData.dat"
#define PREVIEW_PROTO_FILE ".\\data\\previewData.dat"
#define COM_PROTO_FILE ".\\data\\comData.dat"

class MainObj:public QObject
{
  Q_OBJECT
private:
signals:
    void screenChange();
public:
    void emitScreenChangeSignal();
    MainObj(QObject *parent = 0);
    ~MainObj();
};

//主窗口
class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void fileSaveAs();
    void fileSave();
    void fileNew();
    void fileOpen();
    void settingsInit();
    void updateTreeWidget(QMdiSubWindow*);
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

    QMenu *ctrlMenu;
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
    QAction *actionDel;
    QAction *actionPreview;
    QAction *actionModiScreenPara;
    QAction *actionUDisk;
    QAction *actionSendData;
    QAction *actionAdjTime;
    QAction *actionLightness;
    QAction *actionOpenClose;
    QAction *actionComStatus;
public slots:
    void modifyScreenPara();
    void setLightness();
    void adjTime();
    void sendDataProc();
    void exportUdsikProc();
    void setOpenCloseTime();
    void preview();
    void previewProc();
    void comStatusShow();
public:
    int MDISubWinClickFlag;
    QWidget *widget;
    CprogManage *progManage; //节目管理
    Cproperty *property; //属性编辑

    CscreenArea *screenArea; //显示区域
    QMdiArea *mdiArea;

    QMainWindow *previewWin;
    CscreenArea *previewArea;
    QTimer *timer;
    int timerFlag;
    INT8U previewProgNo;

    CcomStatus *comStatus; //通信状态

    void actionEnProc(int type);
    void screenCardParaChangeProc();
    void setCurSettingsStr(QString str);  //获取当前的settings的str
    QString getCurSettingsStr();   //设置当前settings的str

    //int getColor();
    void closeEvent(QCloseEvent *event);
    //void createProgTreeArea();
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

class CinputPSWDialog:public QDialog
{
    Q_OBJECT
public slots:
    void okClickProc();
public:
    bool *verifyRe;
    QLineEdit *lineEdit;

    QPushButton *okButton;
    QPushButton *cancelButton;

    QLabel *reLabel;
   CinputPSWDialog(bool *re, QWidget *parent);
   ~CinputPSWDialog();
};

extern MainWindow *w;
extern MainObj *mainObj;
extern QString rsrcPath1;//  ":/images/win1"
extern QString rsrcPath;// ":/images/win"

QMdiSubWindow *getSubWinByIndex(QMdiArea *parentArea, int index);
int getIndexBySubWin(QMdiArea *parentArea, QMdiSubWindow *subWin);
QIcon getTypeIcon(INT8U type);
void traversalControl(const QObjectList& q);
bool verifyPSW();
#endif // MAINWINDOW_H
