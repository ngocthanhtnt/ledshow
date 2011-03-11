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

#define MOVE_LEFT_CONTINUOUS 0x02
#define MOVE_UP_CONTINUOUS   0x01
#define MOVE_NORMAL          0x00

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
    void showModeEdited();
    //void getSettings();
public:
    Carea *area;
    CnameEdit *nameEdit;
    void screenCardParaChangeProc();
    void connectSignal();
    void disconnectSignal();
    void getSettingsFromWidget(QString str);
    void setSettingsToWidget(QString str);
    QPushButton *editButton; //编辑按钮
    CpicProperty(QWidget *parent=0);
    ~CpicProperty();
};
void updatePicShowArea(CshowArea *area);
int checkSLineMoveLeftContinuous(QString str);
void getPicParaFromSettings(QString str, U_File_Para &para);
#endif // picProperty_H
