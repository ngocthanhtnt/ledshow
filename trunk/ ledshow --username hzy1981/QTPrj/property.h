#ifndef PROPERTY_H
#define PROPERTY_H

#include <QtGui/QMainWindow>
#include "areaProperty.h"
#include "progProperty.h"
#include "timerProperty.h"
#include "picProperty.h"
#include "clockProperty.h"
#include "flashProperty.h"
#include "timeProperty.h"
#include "tempProperty.h"
#include "textedit.h"
#include <QDockWidget>
#include <QStackedWidget>
#include <QTreeWidgetItem>



//属性窗口
class Cproperty :public QDockWidget
{
    Q_OBJECT
private:


    CprogProperty *progProperty; //节目属性
    CtimeProperty *timeProperty; //日期时间
    CtimerProperty *timerProperty; //定时器

    CclockProperty *clockProperty; //表盘
    CflashProperty *flashProperty; //flash动画
    CtempProperty *tempProperty; //温度

public:
    Carea *area;
    CareaProperty *areaProperty; //分区属性
    CpicProperty *picProperty;  //图文

    void setSettingsToWidget(QTreeWidgetItem *item);
    void getSettingsFromWidget(QTreeWidgetItem *item);

    void updateProperty(QTreeWidgetItem *item);
    void progChangedProc(QString settingsStr);

    QStackedWidget *stackedWidget;
    Cproperty(QWidget *parent = 0);
    ~Cproperty();
};
#endif // PROPERTY_H
