#ifndef SCREENPROPERTY_H
#define SCREENPROPERTY_H


#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
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
#include <QRadioButton>
#include "showArea.h"
#include "areaProperty.h"

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


//定时开关机调节
class CopenCloseProperty:public QWidget
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
class ClightnessProperty:public QWidget
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
//screen属性窗
class CfacScreenProperty:public QWidget
{
    Q_OBJECT
public slots:
 void lockParaProc();
 public:
 QWidget *cardGroup;
 QWidget *comParaGroup;
 QWidget *baseParaGroup;
 QWidget *advanceParaGroup;
 QWidget *readParaGroup;

 QComboBox *cardCombo; //选择卡类型
 QTextEdit *cardParaEdit; //卡参数

 //通信参数
 QLineEdit *screenIDEdit; // 屏幕ID
 QLineEdit *newScreenIDEdit; //新设屏幕ID
 QComboBox *comModeCombo; //通信方式
 QComboBox *baudCombo; //波特率
 QComboBox *ipModeCombo; //IP获取方式
 QLineEdit *ipEdit; //IP地址
 QLineEdit *newIpEdit; //新IP地址
 QLineEdit *maskEdit; //子网掩码
 QLineEdit *gateEdit; //网关掩码
 //基本参数

 QComboBox *dataPolarityCombo; //数据极性
 QComboBox *oePolarityCombo; //OE极性
 QComboBox *colorCombo; //颜色
 QLineEdit *widthEdit; //屏宽
 QLineEdit *heightEdit; //屏高
 QCheckBox *_138Check;     //是否有138译码器
 QComboBox *scanModeCombo; //扫描方式

 //高级设置
 QCheckBox *defParaCheck; //使用默认参数
 QComboBox *freqCombo; //扫描频率
 QSpinBox *lineHideBox; //行消隐藏
 QComboBox *dataMirrorCombo; //数据镜像
 QComboBox *lineOrderCombo; //行顺序
 //------------------

 //导入参数
 QTextEdit *readParaEdit;
 QPushButton *readParaButton;
 QPushButton *importParaButton;

 QPushButton *lockParaButton;
 QPushButton *sendButton;
 QPushButton *exportButton;
 //QPushButton *defButton;

 void setEditEnable(bool flag);
    //void getSettingsFromWidget(QString str);
    //void setSettingsToWidget(QString str);
    CfacScreenProperty(QWidget *parent=0);
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
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CscreenProperty(QWidget *parent=0);
    ~CscreenProperty();
};

INT8U getScreenParaFromSettings(QString screenStr, S_Screen_Para &screenPara);
#endif // SCREENPROPERTY_H
