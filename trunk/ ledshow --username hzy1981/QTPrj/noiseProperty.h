#ifndef NOISEPROPERTY_H
#define NOISEPROPERTY_H

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

class Cnoise:public QGroupBox
{
    Q_OBJECT
private:

  QComboBox *noiseCombo;
  CcolorCombo *colorCombo;
  CsizeCombo *sizeCombo;

signals:
    void edited();

public:
    void screenCardParaChangeProc();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    Cnoise(QWidget *parent=0);
    ~Cnoise();
};

//节目属性窗
class CnoiseProperty:public QWidget
{
    Q_OBJECT
public slots:
    void edited();
private:

    QGroupBox *noisePropertyGroup; //属性


    QLabel *textLabel;  //文本
    CsimpleTextEdit *simpleTextEdit;
    Cnoise *noiseStyle;
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
    CnoiseProperty(QWidget *parent=0);
    ~CnoiseProperty();
};

void getNoiseParaFromSettings(QString str, U_File_Para &para);
void updateNoiseShowArea(CshowArea *area);
void Get_Noise_Text_Point(INT8U Area_No, INT16U Width, INT16U Height, S_Point &P0);
#endif // NOISEPROPERTY_H
