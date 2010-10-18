#ifndef PICPROPERTY_H
#define PICPROPERTY_H

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
#include "textedit.h"

class CshowModeCombo:public QComboBox
{
public:
    CshowModeCombo(QWidget *parent = 0);
    ~CshowModeCombo();
};

class CshowSpeedCombo:public QComboBox
{
public:
    CshowSpeedCombo(QWidget *parent = 0);
    ~CshowSpeedCombo();
};

//节目属性窗
class CpicProperty:public QWidget
{
    Q_OBJECT
private:

    QGroupBox *picPropertyGroup; //属性

    QGroupBox *textGroup;
    QLabel *textLabel;  //文本
    QTextEdit *textEdit; //显示文本


    QGroupBox *paraGroup;
    QLabel *showModeLabel; //显示模式
    QLabel *speedLabel; //运行速度
    QLabel *stayTimeLabel; //停留时间

    CshowModeCombo *showModeCombo;
    CshowSpeedCombo *speedCombo;
    QLineEdit *stayTimeEdit;

    TextEdit *edit;
public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    QPushButton *editButton; //编辑按钮
    CpicProperty(QWidget *parent=0);
    ~CpicProperty();
};

#endif // picProperty_H
