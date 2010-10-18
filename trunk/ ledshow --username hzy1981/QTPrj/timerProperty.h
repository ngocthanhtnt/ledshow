#ifndef TIMERPROPERTY_H
#define TIMERPROPERTY_H

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
class CtimerProperty:public QWidget
{
    Q_OBJECT
private:

    QGroupBox *timerPropertyGroup; //属性

    QGroupBox *textGroup;
    QLabel *textLabel;  //文本
    CsimpleTextEdit *simpleTextEdit;
    //QTextEdit *textEdit; //显示文本
    //QPushButton *editButton; //编辑按钮

    QGroupBox *dstTimeGroup;
    QLabel *dstTimeLabel; //目标时间
    QLabel *styleLabel; //样式
    QLabel *colorLabel; //颜色
    QLabel *fontSizeLabel; //大小
    QDateTimeEdit *dstDateTimeEdit; //目标时间日期
    CcolorCombo *colorCombo;  //颜色
    QComboBox *styleCombo;  //样式
    QComboBox *fontSizeCombo; //字体大小

public:
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CtimerProperty(QWidget *parent=0);
    ~CtimerProperty();
};

#endif // TIMERPROPERTY_H
