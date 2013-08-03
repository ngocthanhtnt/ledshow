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
#include "mmtimer.h"


#define CARD_INI_FILE ".\\cfg\\card.ini"     //板卡配置文件
#define SCREEN_INI_FILE ".\\cfg\\screen.ini" //屏幕配置文件
#define PROG_INI_FILE ".\\cfg\\progData.ini"     //节目配置文件

#define PROTO_DATA_FILE ".\\data\\protoData.dat"      //协议数据文件
#define UDISK_PROTO_FILE ".\\data\\uDiskData.dat"      //协议数据文件
#define PREVIEW_PROTO_FILE ".\\data\\previewData.dat" //预览数据文件
#define SIM_PROTO_FILE ".\\data\\simData.dat" //预览数据文件
#define COM_PROTO_FILE ".\\data\\comData.dat"
#define UDISK_DATA_DIR ".\\data\\"

#define MCUZK_FILE ".\\font\\mcuzk.dat" //发送到下位机的字库文件
#define MCUZK_PROTO_FILE ".\\font\\mcuzkproto.dat"

#define WORKDIR() QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation)

#define SEND_PARA_OK_STR    "数据发送成功"
#define SEND_PARA_DENIED_STR  "数据发送失败，收到否定应答！"
#define SEND_PARA_FAIL_STR  "数据发送失败，请检查通信参数和通信链路是否正常！"
#define SEND_PARA_FAIL_RECONNECT_STR  "数据发送失败，是否需要自动连接显示屏？如果您的电脑只连接了一个显示屏，建议您点“确定”按钮。否则请点“取消”按钮，并手动排查通信故障原因。"

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
    void helpFileOpen();
    void hardwareHelpFileOpen();
    void showAboutDialog();
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
    void setupLanguageActions();


    QMenu *ctrlMenu;
    QAction *actionScreen;
    QAction *actionProg;
    QAction *actionArea;
    QAction *actionTxt;
    QAction *actionSText;
    QAction *actionMText;
    QAction *actionTable;
    QAction *actionTemp;
    QAction *actionHumidi;
    QAction *actionFlash;
    QAction *actionImage;
    QAction *actionClock;
    QAction *actionTime;
    QAction *actionNoise;
    QAction *actionNongli;
    QAction *actionTimer;
    QAction *actionDel;
    QAction *actionPreview;
    QAction *actionLarge;
    QAction *actionSmall;
    QAction *actionScreenPreiew;
    QAction *actionTestCard;
    QAction *actionDownloadZK; //下载字库
    QAction *actionModiScreenPara;
    QAction *actionUpdateFirmware;
    QAction *actionUDisk;
    QAction *actionSendData;
    QAction *actionAdjTime;
    QAction *actionLightness;
    QAction *actionOpenClose;
    QAction *actionManualClose; //手动关机
    QAction *actionManualOpen; //手动开机
    QAction *atcionGetOCStatus; //获取开关机状态

public slots:
    void modifyScreenPara();
    void updateFirmware();
    void setLightness();
    void setManualClose();
    void setManualOpen();
    void adjTime();
    void sendDataProc();
    void exportUdsikProc();
    void setOpenCloseTime();
    void previewScreen();
    void previewProg();
    void previewProc();
    void largeScreen(); //放大屏幕
    void smallScreen(); //缩小屏幕
    void previewTimerProc();
    void comStatusShow();
    void testCard(); //测试控制卡
    void downloadZK();
public:
    QAction *actionComStatus;

    int MDISubWinClickFlag;
    QWidget *widget;
    CprogManage *progManage; //节目管理
    Cproperty *property; //属性编辑

    CscreenArea *screenArea; //显示区域
    QMdiArea *mdiArea;

    QMainWindow *previewWin;
    CscreenArea *previewArea;
    QTimer *timer;
    MMTimer *mmtimer;

    int timerFlag;
    INT8U previewProgNo;

    CcomStatus *comStatus; //通信状态

    void setActonsEnable();
    void actionEnProc(int type);
    void screenCardParaChangeProc();
    void setCurSettingsStr(QString str);  //获取当前的settings的str
    QString getCurSettingsStr();   //设置当前settings的str

    void closeEvent(QCloseEvent *event);

    void preview(INT8U previewMode);
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

class CinputPSWDialog:public QDialog
{
    Q_OBJECT
public slots:
    void okClickProc();
public:
    INT8U *verifyRe;
    QLineEdit *lineEdit;

    QPushButton *okButton;
    QPushButton *cancelButton;

    QLabel *reLabel;
   CinputPSWDialog(INT8U *re, QWidget *parent);
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
INT8U verifyPSW();
#endif // MAINWINDOW_H
