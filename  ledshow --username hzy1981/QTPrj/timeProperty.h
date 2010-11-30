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
#include "areaProperty.h"
#include "showArea.h"

//节目属性窗
class CtimeProperty:public QWidget
{
    Q_OBJECT
private:

    QGroupBox *timePropertyGroup; //属性

    QGroupBox *textGroup;
    QLabel *textLabel;  //文本
    CsimpleTextEdit *simpleTextEdit;
    CsmLineEdit *smLineEdit;
    CdateTimeEdit *dateTimeEdit;
public slots:
    void edited();
public:
    Carea *area;
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CtimeProperty(QWidget *parent=0);
    ~CtimeProperty();
};

void getTimeParaFromSettings(QString str, U_File_Para &para);
void updateTimeShowArea(CshowArea *area, QTreeWidgetItem *item);
#endif // TIMEPROPERTY_H
