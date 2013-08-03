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

class CipInput:public QLineEdit
{
    Q_OBJECT
signals:
    void editSignal();
public:
    //QLineEdit *edit;
    INT32U getIP();
    void setIP(INT32U ip);

    //QString ipToStr(INT8U ip);
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
    void autoConnect();
    void manualConnect();
    void cardChangedProc(QString cardName);
    void comModeChangedProc();
public:
    QComboBox *comModeCombo; //通信方式
    QSpinBox *screenIDEdit; //屏幕ID，硬件地址
    QLabel *comPortLabel;
    QComboBox *comPortEdit; //串口号
    QComboBox *comBaudCombo; //波特率
    QLabel *comBaudLabel;
    CipInput *ipEdit; //IP地址
    QLabel *ipEditLabel;
    QPushButton *manualConnectButton; //链接按钮
    QPushButton *autoConnectButton; //测试按钮
    QLabel *comPortInfoLabel;

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

class CudiskListDialog:public QDialog
{
    Q_OBJECT
public slots:
    void okButtonSlot();
signals:
    void closeSignal();
public:
    QPushButton *okButton;
    QComboBox *udiskCombo;
    QStringList udiskList;
    QString udiskName;

    void updateUdiskList();
    CudiskListDialog(QWidget *parent=0);
    ~CudiskListDialog();
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
 void importParaProc(); //导入参数
 void readParaProc(); //回读参数
 void setTestProc(); // 自检
 void comLoadParaProc(); //通信加载参数
 void udiskLoadParaProc(); //U盘加载参数
 void readCardType();
 public:
 QTabWidget *tabWidget;
 CcomTest *comTest;

 QWidget *cardGroup;
 QWidget *netParaGroup;
 QWidget *baseParaGroup;
 QWidget *advanceParaGroup;
 QWidget *readParaGroup;
 QWidget *scanParaGroup;

 QWidget *scanPicWidget;

 QComboBox *cardCombo; //选择卡类型
 QPushButton *readCardTypeButton;
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
 QComboBox *scanModeCombo; //扫描方式

 //高级设置
 QLabel *freqLabel;// = new QLabel(tr("时钟频率"),this);
 QLabel *lineHideLabel;// = new QLabel(tr("行消隐"),this);
 QLabel *dataMirrorLabel;// = new QLabel(tr("数据镜像"),this);
 QLabel *lineOrderLabel;// = new QLabel(tr("行顺序"),this);
 QLabel *_138Label;

 QCheckBox *defParaCheck; //使用默认参数
 QComboBox *freqCombo; //扫描频率
 QComboBox *lineHideCombo; //行消隐藏
 QComboBox *dataMirrorCombo; //数据镜像
 QComboBox *lineOrderCombo; //行顺序
 QComboBox *_138Combo;     //是否有138译码器
 //------------------

 //CcomTest *comTest;
 //导入参数
 QTextEdit *readParaEdit;
 QPushButton *readParaButton;
 QPushButton *importParaButton;

 QPushButton *endButton;
 QPushButton *comLoadButton;
 QPushButton *udiskLoadButton;
 QPushButton *exportButton;
 QPushButton *selfTestButton;

 //QPushButton *defButton;
 int paraFlag; //表示新建屏幕、1表示修改屏幕，2表示显示屏幕
 int SendPara();
 void setEditEnable(bool flag);
  void loadParaProc(INT8U Mode); //加载参数
 void getScreenCardParaFromWidget(S_Screen_Para &screenPara, S_Card_Para &cardPara);
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CfacScreenProperty(int flag, CcomTest *comTest, QWidget *parent=0);
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
    //ClightnessProperty *lightnessProperty;
    //CopenCloseProperty *openCloseProperty;
signals:
    void editSignal();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CscreenProperty(QWidget *parent=0);
    ~CscreenProperty();
};

class CupdateFirmwareDialog:public QDialog
{
    Q_OBJECT

public slots:
    void updateFirmware(); //升级版本号
    bool readVersion(); //读取版本号
    void openFirmwareFile(); //打开固件程序
    void makeFirmwareFile(); //从bin文件生成固件文件
    //void uDiskData(); //生成U攀升数据
//signals:
    //void closeSignal();
private:
    INT8U makeFlag; //生成固件文件标志
    INT16U newFirmFrameCounts; //升级固件的帧个数
public:
    QLineEdit *oldVersionEdit; //老的程序版本
    QLineEdit *newVersionEdit; //新升级的程序版本

    QLineEdit *newFirmPath; //新固件路径
    QPushButton *openButton; //打开固件文件命令
    QPushButton *updateButton; //固件升级命令
    QPushButton *readVersionButton; //读取版本号命令

    QPushButton *makeButton; //生成程序的按钮

    char binFileData[500000];
    char fwbFileData[500000];

    CupdateFirmwareDialog(INT8U flag, QWidget *parent=0);
    ~CupdateFirmwareDialog();

};

class CInvalidDateDialog:public QDialog
{
  Q_OBJECT
private:
   QGroupBox *invalidDateGroup;
   QDateEdit *invalidDateEdit;  //无效日期
   QPushButton *sendButton; //发送按钮
   QPushButton *udiskButton; //导出按钮
public slots:
    void sendPara(); //发送
    void udiskPara(); //导出
    void editSlot();
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CInvalidDateDialog(QWidget *parent =0);
    ~CInvalidDateDialog();
};

void comFailedProc();
void getComTestParaFromSettings(QString str, S_Screen_Para &screenPara);
INT8U getCardParaFromSettings(QString cardName, S_Card_Para &cardPara);
INT8U getScreenCardParaFromSettings(QString screenStr, S_Screen_Para &screenPara, S_Card_Para &cardPara);
#endif // SCREENPROPERTY_H
