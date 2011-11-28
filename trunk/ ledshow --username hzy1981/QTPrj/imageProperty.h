#ifndef IMAGEPROPERTY_H
#define IMAGEPROPERTY_H

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


//image属性窗
class CimageProperty:public QWidget
{
    Q_OBJECT
private:
    QGroupBox *groupBox;
    QLabel *imageSourceLabel; //image源标志
    QLineEdit *imageSourceEdit; //image源编辑框
    QPushButton *openButton; //打开按钮

    //QLabel *totalFrameNumLabel; //总帧数
    //QLineEdit *totalFrameNumEdit; //总

    //QLabel *frameNumLabel; //帧数标志
    //QSpinBox *frameNumEdit; //帧数编辑

    //QLabel *runSpeedLabel; //运行速度标志
    //QComboBox *runSpeedCheck; //运行速度编辑
    //QLineEdit *stayTimeEdit;
    //QLabel *speedUnitLabel; //速度单位
    CimageSize *imageSize;
    CborderEdit *borderEdit;
    CshowModeEdit *showModeEdit;
public slots:
    void openImageFile();
    void edited();
public:
    Carea *area;
    CnameEdit *nameEdit;
    void connectSignal();
    void disconnectSignal();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CimageProperty(QWidget *parent=0);
    ~CimageProperty();
};

void getImageParaFromSettings(QString str, U_File_Para &para);
void updateImageShowArea(CshowArea *area);
QSize getImageShowData(QImage image, S_Show_Data *pDst, INT8U Area_No, INT16U x, INT16U y);
void getImagePageShowData(QString str, INT8U page, S_Show_Data *pDst, INT8U Area_No, INT16U x, INT16U y, INT16U width, INT16U height);
int getImageFrameCount(QString str);

#endif // IMAGEPROPERTY_H
