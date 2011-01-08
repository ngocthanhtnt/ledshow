#ifndef CLOCKPROPERTY_H
#define CLOCKPROPERTY_H

#include "..\Includes.h"
#include <QtGui/QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QSpinBox>
#include "areaProperty.h"
#include "simpleTextEdit.h"
#include "colorCombo.h"
#include "showArea.h"

class CposiEdit:public QGroupBox
{
  Q_OBJECT
public:
    QComboBox *item;
    QPushButton *left;
    QPushButton *right;
    QPushButton *up;
    QPushButton *down;
    QPushButton *def;


    CposiEdit(QWidget *parent);
    ~CposiEdit();
};

class CclockProperty:public QWidget
{
    Q_OBJECT
private:
    QGroupBox *editGroup;

    QLabel *pointRadiusLabel; //整点半径
    QLabel *point369RadiusLabel; //369点半径
    QLabel *hourWidthLabel; //小时宽度
    QLabel *minWidthLabel; //分钟宽度
    QLabel *secWidthLabel; //秒钟宽度

    QLabel *pointColorLabel; //整点颜色
    QLabel *point369ColorLabel; //369点颜色
    QLabel *hourColorLabel; //小时颜色
    QLabel *minColorLabel; //分钟颜色
    QLabel *secColorLabel; //秒钟颜色

    QSpinBox *pointRadiusEdit; //整点半径
    QSpinBox *point369RadiusEdit; //
    QSpinBox *hourWidthEdit;
    QSpinBox *minWidthEdit;
    QSpinBox *secWidthEdit;

    CcolorCombo *pointColorCombo;
    CcolorCombo *point369ColorCombo;
    CcolorCombo *hourColorCombo;
    CcolorCombo *minColorCombo;
    CcolorCombo *secColorCombo;

    CtimeDiffEdit *timeDiffEdit;
    CsimpleTextEdit *simpleTextEdit;
    CposiEdit *posiEdit;

    QGroupBox *timeGroup;
    CdateEdit *dateEdit;
    CweekEdit *weekEdit;

    CshowModeEdit *showModeEdit;
signals:
    void edited();
public slots:
    void leftEdit();
    void rightEdit();
    void upEdit();
    void downEdit();
    void defEdit();
    void propertyEdited();
public:
    Carea *area;
    CnameEdit *nameEdit;
    void updateShowAreaa(CshowArea *area);

    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CclockProperty(QWidget *parent);
    ~CclockProperty();
};

void getClockParaFromSettings(QString str, U_File_Para &para);
void updateClockShowArea(CshowArea *area);
#endif // CLOCKPROPERTY_H
