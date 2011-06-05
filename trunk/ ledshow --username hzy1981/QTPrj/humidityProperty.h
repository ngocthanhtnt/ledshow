#ifndef HUMIDITYPROPERTY_H
#define HUMIDITYPROPERTY_H

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

class Chumidity:public QGroupBox
{
    Q_OBJECT
private:

  QComboBox *humidityCombo;
  CcolorCombo *colorCombo;
  CsizeCombo *sizeCombo;

signals:
    void edited();

public:
    void screenCardParaChangeProc();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    Chumidity(QWidget *parent=0);
    ~Chumidity();
};

//节目属性窗
class ChumidityProperty:public QWidget
{
    Q_OBJECT
public slots:
    void edited();
private:

    QGroupBox *humidityPropertyGroup; //属性


    QLabel *textLabel;  //文本
    CsimpleTextEdit *simpleTextEdit;
    Chumidity *humidityStyle;
    CshowModeEdit *showModeEdit;
    //QTextEdit *textEdit; //显示文本
    //QPushButton *editButton; //编辑按钮

    CborderEdit *borderEdit;


public:
    CnameEdit *nameEdit;
    Carea *area;
    void connectSignal();
    void disconnectSignal();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    ChumidityProperty(QWidget *parent=0);
    ~ChumidityProperty();
};

void getHumidityParaFromSettings(QString str, U_File_Para &para);
void updateHumidityShowArea(CshowArea *area);
void Get_Humidity_Text_Point(INT8U Area_No, INT16U Width, INT16U Height, S_Point &P0);
#endif // HUMIDITYPROPERTY_H
