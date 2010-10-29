#ifndef PROGPROPERTY_H
#define PROGPROPERTY_H

#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QTimeEdit>
#include <QCheckBox>
#include <QComboBox>
#include "colorCombo.h"


//节目属性窗
class CprogProperty:public QWidget
{
    Q_OBJECT
private:
    QGroupBox *nameGroup;
    QGroupBox *timerGroup; //定时播放

    //-----------名称-------------
    QLabel *nameLabel;  //名字
    QLineEdit *nameEdit; //名字输入框

    //--------  按日期定时---------
    QGroupBox *dateGroup;
    QCheckBox *dateTimerCheck; //按日期定时
    QLabel *startDateLabel, *endDateLabel;
    QDateEdit *startDateEdit; //起始日期
    QDateEdit *endDateEdit; //结束日期

    //----------按星期定时-----------
    QGroupBox *weekGroup;
    QCheckBox *weekTimerCheck; //按星期定时
    QCheckBox *weekCheck[7]; //星期选择

    //----------按时间定时----------
    QGroupBox *timeGroup;
    QCheckBox *timeCheck; //按时间定时
    QLabel *startTimeLabel,*endTimeLabel;
    QTimeEdit *startTimeEdit; //开始时间
    QTimeEdit *endTimeEdit; //结束时间

    //------------定长播放----------
    QGroupBox *playTimeGroup; //播放时长
    QCheckBox *playTimeCheck; //定长播放
    QLineEdit *playTimeEdit; //时长
    QLabel *playTimeLabel;

    //-------------边框选择----------
    QGroupBox *borderGroup; //边框
    QCheckBox *borderCheck;

    QLabel *widthLabel,*styleLabel,*colorLabel,*speedLabel;
    QLabel *pointsLabel,*usLabel;
    QLineEdit *widthEdit, *speedEdit;
    QComboBox *styleCombo;
    CcolorCombo *colorCombo;

    //QSrting settingsStr; //当前设置Str
public slots:
    void allWeekDayCheckProc(int state);
    void dateTimerCheckProc(int state);
    void weekTimerCheckProc(int state);
    void timeCheckProc(int state);
    void playTimeCheckProc(int state);
    void borderCheckProc(int state);

public:

    void setSettingsToWidget(QString str);
    void getSettingsFromWidget(QString str);

    CprogProperty(QWidget *parent=0);
    ~CprogProperty();
};

#endif // PROGPROPERTY_H
