#ifndef TIMEPROPERTY_H
#define TIMEPROPERTY_H

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
#include "simpleTextEdit.h"

//节目属性窗
class CtimeProperty:public QWidget
{
    Q_OBJECT
private:

    QGroupBox *timePropertyGroup; //属性

    QGroupBox *textGroup;
    QLabel *textLabel;  //文本
    CsimpleTextEdit *simpleTextEdit;
    //QTextEdit *textEdit; //显示文本
    //QPushButton *editButton; //编辑按钮



public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CtimeProperty(QWidget *parent=0);
    ~CtimeProperty();
};

#endif // TIMEPROPERTY_H
