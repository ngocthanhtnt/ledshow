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
#include "simpleTextEdit.h"
#include "colorCombo.h"
#include "showArea.h"

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

    QLineEdit *pointRadiusEdit; //整点半径
    QLineEdit *point369RadiusEdit; //
    QLineEdit *hourWidthEdit;
    QLineEdit *minWidthEdit;
    QLineEdit *secWidthEdit;

    CcolorCombo *pointColorCombo;
    CcolorCombo *point369ColorCombo;
    CcolorCombo *hourColorCombo;
    CcolorCombo *minColorCombo;
    CcolorCombo *secColorCombo;

    QGroupBox *textGroup;
    CsimpleTextEdit *simpleTextEdit;
public slots:
    void propertyEdited();
public:
    void updateShowAreaa(CshowArea *area);

    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    CclockProperty(QWidget *parent);
    ~CclockProperty();
};

void getClockParaFromSettings(QString str, U_File_Para &para);
void updateClockShowArea(CshowArea *area);
#endif // CLOCKPROPERTY_H
