#ifndef SCREENPROPERTY_H
#define SCREENPROPERTY_H


#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QTimeEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QSlider>
#include <QInputDialog>
#include <QRadioButton>
#include "showArea.h"
#include "areaProperty.h"

#define NEW_SCN 0x00  //新建屏幕
#define MODI_SCN 0x01 //修改屏幕
#define SHOW_SCN 0x02 //显示屏幕木
//#define LIGHT

/*
class CipInput:public QGroupBox
{
  Q_OBJECT

  QLineEdit *inputEdit[4];
signals:
    void edited();
public:
  INT32U getInputIP();
  CipInput(QWidget *parent=0);
  ~CipInput();

};
*/

class CipInput:public QWidget
{
    Q_OBJECT
signals:
    void editSignal();
public:
    QLineEdit *edit;

    int getIP();
    void setIP(int ip);

    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);

    CipInput(QWidget *parent=0);
    ~CipInput();
};

class CcomTest:public QGroupBox
{
    Q_OBJECT
signals:
    void editSignal();
public slots:
    void editSlot();
public:
    QComboBox *comModeCombo; //通信方式
    QSpinBox *screenIDEdit; //屏幕ID，硬件地址
    QComboBox *comPortEdit; //串口号
    QComboBox *comBaudCombo; //波特率
    CipInput *ipEdit; //IP地址
    QPushButton *connectButton; //链接按钮
    QPushButton *autoTestButton; //测试按钮

    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    void setSettingsToScreePara(QString str, S_Screen_Para &screenPara);

    CcomTest(QWidget *parent=0);
    ~CcomTest();
};

//定时开关机调节
class CopenCloseProperty:public QGroupBox
{
    Q_OBJECT
    //QRadioButton *manualButton;
    //QRadioButton *timerButton;
signals:
    void TimeEditSignal();
public slots:
    void allEditSlot();
public:
    void timeCheckProc();
    QCheckBox *timeCheck[MAX_OPEN_CLOSE_TIME];
    QTimeEdit *openTimeEdit[MAX_OPEN_CLOSE_TIME];
    QTimeEdit *closeTimeEdit[MAX_OPEN_CLOSE_TIME];
    //QSlider *timerSlider[MAX_LIGHTNESS_TIME];

    //QSlider *manualSlider;
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CopenCloseProperty(QWidget *parent=0);
    ~CopenCloseProperty();
};

//亮度调节
class ClightnessProperty:public QGroupBox
{
    Q_OBJECT
    QRadioButton *manualButton;
    QRadioButton *timerButton;
    QRadioButton *autoButton;
signals:
    void adjModeEditSignal();
    void allEditSignal();
public slots:
    void adjModeEditSlot();
    void allEditSlot();
public:
    QCheckBox *timerCheck[MAX_LIGHTNESS_TIME];
    QTimeEdit *timerEdit[MAX_LIGHTNESS_TIME];
    QSlider *timerSlider[MAX_LIGHTNESS_TIME];
    QLabel *timerLabel[MAX_LIGHTNESS_TIME];

    QSlider *manualSlider;
    QLabel *manualLabel;

    QLabel *autoLabel;
    void sliderEditProc();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    ClightnessProperty(QWidget *parent=0);
    ~ClightnessProperty();
};

class ClightnessDialog:public QDialog
{
    Q_OBJECT
public slots:
    void sendPara(); //发送参数
    void udiskPara(); //生成u盘文件
public:
    ClightnessProperty *lightnessProperty;
    QPushButton *sendButton;
    QPushButton *udiskButton;
    QPushButton *cancelButton;

    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    ClightnessDialog(QWidget *parent=0);
    ~ClightnessDialog();
};

class CopenCloseDialog:public QDialog
{
    Q_OBJECT
public slots:
    void sendPara(); //发送参数
    void udiskPara(); //生成u盘文件
public:
    CopenCloseProperty *openCloseProperty;
    QPushButton *sendButton;
    QPushButton *udiskButton;
    QPushButton *cancelButton;

    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CopenCloseDialog(QWidget *parent=0);
    ~CopenCloseDialog();
};

class CadjTimeProperty:public QGroupBox
{
    Q_OBJECT
public slots:
    void adjTimeModeCheck();
public:
    //QDateTimeEdit *dateTimeEdit;
    //QPushButton *sysTimeButton;
    QRadioButton *sysTimeButton; //系统时间
    QRadioButton *selfTimeButton; //自定义事件
    QDateTimeEdit *dateTimeEdit;

    QDateTime getDateTime();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CadjTimeProperty(QWidget *parent=0);
    ~CadjTimeProperty();
};

class CadjTimeDialog:public QDialog
{
    Q_OBJECT
public slots:
    void sendData();
    void udiskData();
public:
    CadjTimeProperty *adjTimeProperty;

    QPushButton *sendButton;
    QPushButton *udiskButton;
    QPushButton *cancelButton;

    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CadjTimeDialog(QWidget *parent=0);
    ~CadjTimeDialog();
};

/*
class CsendProgDialog:public QDialog
{
    Q_OBJECT
public:
    QCheckBox *openCloseCheck;
    QCheckBox *lightnessCheck;
    QCheckBox *adjTimeCheck;

    CopenCloseProperty *openCloseProperty;
    ClightnessProperty *lightnessProperty;


    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CopenCloseDialog(QWidget *parent=0);
    ~CopenCloseDialog();
};
*/
class CsendDataDialog:public QDialog
{
    Q_OBJECT
public slots:
    void propertyCheckProc();
    void sendData(); //发送数据
    void uDiskData(); //生成U攀升数据
signals:
    void closeSignal();
public:
    QCheckBox *lightnessCheck; //亮度控制
    QCheckBox *openCloseCheck; //开关机时段控制
    QCheckBox *adjTimeCheck;  //校时控制

    QPushButton *sendButton; //发送
    QPushButton *udiskButton; //u盘
    QPushButton *cancelButton; //取消

    ClightnessProperty *lightnessProperty;
    CopenCloseProperty *openCloseProperty;
    CadjTimeProperty *adjTimeProperty;

    CsendDataDialog(int flag, QWidget *parent=0);
    ~CsendDataDialog();


};

//screen属性窗
class CfacScreenProperty:public QGroupBox
{
    Q_OBJECT
private:
    S_Screen_Para readScreenPara;
    bool readScreenParaFlag;

public slots:
 void defParaCheckProc();
 void cardChangeProc();
 void endProc(); //保存参数
 void loadParaProc(); //加载参数
 void readParaProc(); //回读参数
 void setTestProc(); // 自检
 public:
 QTabWidget *tabWidget;

 QWidget *cardGroup;
 QWidget *netParaGroup;
 QWidget *baseParaGroup;
 QWidget *advanceParaGroup;
 QWidget *readParaGroup;
 QWidget *scanParaGroup;

 QWidget *scanPicWidget;

 QComboBox *cardCombo; //选择卡类型
 QTextEdit *cardParaEdit; //卡参数

 //通信参数

 //QComboBox *ipModeCombo; //IP获取方式
 //QLineEdit *ipEdit; //IP地址
 CipInput *ipEdit;
 //QLineEdit *newIpEdit; //新IP地址
 CipInput *maskEdit; //子网掩码
 CipInput *gateEdit; //网关掩码
 CipInput *macEdit; //mac地址
 //基本参数
 QSpinBox *screenIDEdit; // 屏幕ID
 QComboBox *baudCombo; //波特率
 QCheckBox *redGreenRevCheck; //红绿
 QComboBox *dataPolarityCombo; //数据极性
 QComboBox *oePolarityCombo; //OE极性

 QComboBox *colorCombo; //颜色
 QSpinBox *widthEdit; //屏宽
 QSpinBox *heightEdit; //屏高
 QCheckBox *_138Check;     //是否有138译码器
 QComboBox *scanModeCombo; //扫描方式

 //高级设置
 QCheckBox *defParaCheck; //使用默认参数
 QComboBox *freqCombo; //扫描频率
 QComboBox *lineHideCombo; //行消隐藏
 QComboBox *dataMirrorCombo; //数据镜像
 QComboBox *lineOrderCombo; //行顺序
 //------------------

 //CcomTest *comTest;
 //导入参数
 QTextEdit *readParaEdit;
 QPushButton *readParaButton;
 QPushButton *importParaButton;

 QPushButton *endButton;
 QPushButton *loadButton;
 QPushButton *exportButton;
 QPushButton *selfTestButton;

 //QPushButton *defButton;
 int paraFlag; //表示新建屏幕、1表示修改屏幕，2表示显示屏幕
 int SendPara();
 void setEditEnable(bool flag);
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CfacScreenProperty(int flag, QWidget *parent=0);
    ~CfacScreenProperty();
};

//screen属性窗
class CsetFacPara:public QMainWindow
{
    Q_OBJECT
    CfacScreenProperty *facScreenProperty;
public:
    //void getSettingsFromWidget(QString str);
    //void setSettingsToWidget(QString str);
    CsetFacPara(QWidget *parent=0);
    ~CsetFacPara();
};

//screen属性窗
class CscreenProperty:public QWidget
{
    Q_OBJECT
    CnameEdit *nameEdit;
    CfacScreenProperty *facProperty;
    ClightnessProperty *lightnessProperty;
    CopenCloseProperty *openCloseProperty;
signals:
    void editSignal();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CscreenProperty(QWidget *parent=0);
    ~CscreenProperty();
};

void getComTestParaFromSettings(QString str, S_Screen_Para &screenPara);
INT8U getCardParaFromSettings(QString cardName, S_Card_Para &cardPara);
INT8U getScreenCardParaFromSettings(QString screenStr, S_Screen_Para &screenPara, S_Card_Para &cardPara);
#endif // SCREENPROPERTY_H
