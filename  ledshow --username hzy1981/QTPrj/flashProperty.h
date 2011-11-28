#ifndef FLASHPROPERTY_H
#define FLASHPROPERTY_H

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
#include "showArea.h"
#include "areaProperty.h"


//flash属性窗
class CflashProperty:public QWidget
{
    Q_OBJECT
private:
    QGroupBox *groupBox;
    QLabel *flashSourceLabel; //flash源标志
    QLineEdit *flashSourceEdit; //flash源编辑框
    QPushButton *openButton; //打开按钮

    QLabel *totalFrameNumLabel; //总帧数
    QLineEdit *totalFrameNumEdit; //总

    QLabel *frameNumLabel; //帧数标志
    QSpinBox *frameNumEdit; //帧数编辑

    QLabel *runSpeedLabel; //运行速度标志
    //QComboBox *runSpeedCheck; //运行速度编辑
    QLineEdit *stayTimeEdit;
    QLabel *speedUnitLabel; //速度单位

    CimageSize *imageSize;
    CborderEdit *borderEdit;
public slots:
    void openFlashFile();
    void edited();
public:
    Carea *area;
    CnameEdit *nameEdit;
    void connectSignal();
    void disconnectSignal();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CflashProperty(QWidget *parent=0);
    ~CflashProperty();
};

void getFlashParaFromSettings(QString str, U_File_Para &para);
void updateFlashShowArea(CshowArea *area);
QSize getFlashShowData(QImage image, S_Show_Data *pDst, INT8U Area_No, INT16U x, INT16U y);
void getFlashPageShowData(QString str, INT8U page, S_Show_Data *pDst, INT8U Area_No, INT16U x, INT16U y, INT16U width, INT16U height);
int getFlashFrameCount(QString str);
#endif // FLASHPROPERTY_H
