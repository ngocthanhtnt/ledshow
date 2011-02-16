#ifndef LUNPROPERTY_H
#define LUNPROPERTY_H

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
class ClunProperty:public QWidget
{
    Q_OBJECT
private:

    QGroupBox *timePropertyGroup; //属性

    QGroupBox *textGroup;
    QLabel *textLabel;  //文本
    CsimpleTextEdit *simpleTextEdit;
    CsmLineEdit *smLineEdit;
    ClunEdit *lunEdit;
    CshowModeEdit *showModeEdit;
public slots:
    void edited();
public:
    CnameEdit *nameEdit;
    Carea *area;
    void connectSignal();
    void disconnectSignal();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    ClunProperty(QWidget *parent=0);
    ~ClunProperty();
};

void getLunParaFromSettings(QString str, U_File_Para &para);
void updateLunShowArea(CshowArea *area);
void Get_Lun_Text_Point(INT8U Area_No, INT16U Width, INT16U Height, S_Point &P0);
#endif // TIMEPROPERTY_H
