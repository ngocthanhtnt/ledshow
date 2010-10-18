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


//flash属性窗
class CflashProperty:public QWidget
{
    Q_OBJECT
private:
    QGroupBox *groupBox;
    QLabel *flashSourceLabel; //flash源标志
    QLineEdit *flashSourceEdit; //flash源编辑框
    QPushButton *openButton; //打开按钮

    QLabel *frameNumLabel; //帧数标志
    QLineEdit *frameNumEdit; //帧数编辑
    QLabel *runSpeedLabel; //运行速度标志
    QLineEdit *runSpeedEdit; //运行速度编辑
    QLabel *speedUnitLabel; //速度单位

    QLabel *totalFrameNumLabel; //总帧数


public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CflashProperty(QWidget *parent=0);
    ~CflashProperty();
};

#endif // FLASHPROPERTY_H
