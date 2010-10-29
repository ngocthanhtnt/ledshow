#ifndef TEMPPROPERTY_H
#define TEMPPROPERTY_H

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
#include "areaProperty.h"

//节目属性窗
class CtempProperty:public QWidget
{
    Q_OBJECT
private:

    QGroupBox *tempPropertyGroup; //属性

    QGroupBox *textGroup;
    QLabel *textLabel;  //文本
    CsimpleTextEdit *simpleTextEdit;
    //QTextEdit *textEdit; //显示文本
    //QPushButton *editButton; //编辑按钮



public:
    Carea *area;
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CtempProperty(QWidget *parent=0);
    ~CtempProperty();
};

#endif // TEMPPROPERTY_H
