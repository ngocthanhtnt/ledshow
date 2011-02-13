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
    CtimeDiffEdit *timeDiffEdit;
    CsimpleTextEdit *simpleTextEdit;
    CsmLineEdit *smLineEdit;
    CdateTimeEdit *dateTimeEdit;
    CshowModeEdit *showModeEdit;
public slots:
    void edited();
public:
    CnameEdit *nameEdit;
    Carea *area;

    void screenCardParaChangeProc();
    void connectSignal();
    void disconnectSignal();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CtimeProperty(QWidget *parent=0);
    ~CtimeProperty();
};

void getTimeParaFromSettings(QString str, U_File_Para &para);
void updateTimeShowArea(CshowArea *area);
void Get_Time_Text_Point(INT8U Area_No, INT16U Width, INT16U Height, S_Point &P0);
#endif // TIMEPROPERTY_H
