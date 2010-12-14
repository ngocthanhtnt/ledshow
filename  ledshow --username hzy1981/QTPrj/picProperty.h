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
#include <simpleTextEdit.h>
#include "areaProperty.h"
#include "textedit.h"
#include <showArea.h>


//节目属性窗
class CpicProperty:public QWidget
{
    Q_OBJECT
private:

    QGroupBox *picPropertyGroup; //属性

    QGroupBox *textGroup;
    QLabel *textLabel;  //文本
    QTextEdit *textEdit; //显示文本

/*
    QGroupBox *paraGroup;
    QLabel *showModeLabel; //显示模式
    QLabel *speedLabel; //运行速度
    QLabel *stayTimeLabel; //停留时间

    CshowModeCombo *showModeCombo;
    CshowSpeedCombo *speedCombo;
    QLineEdit *stayTimeEdit;
*/
    CshowModeEdit *showModeEdit;
    TextEdit *edit;
public slots:
    void propertyEdited();
public:
    Carea *area;
    CnameEdit *nameEdit;
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    QPushButton *editButton; //编辑按钮
    CpicProperty(QWidget *parent=0);
    ~CpicProperty();
};
void updatePicShowArea(CshowArea *area);
#endif // picProperty_H
