#ifndef AREAPROPERTY_H
#define AREAPROPERTY_H

#include <QtGui/QMainWindow>
#include <QGroupBox>
#include <QLineEdit.h>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QRect>

//∑÷«¯ Ù–‘¥∞
class Carea:public QGroupBox
{
    Q_OBJECT
private:
    QGroupBox *groupBox;
    QLabel *nameLabel;
    QLabel *xLabel,*yLabel;
    QLabel *widthLabel, *heightLabel;
    QLineEdit *nameEdit;
    QLineEdit *xEdit,*yEdit;
    QLineEdit *widthEdit,*heightEdit;
    QGridLayout *grid;

public slots:
    void xEdited();
    void yEdited();
    void xLenEdited();
    void yLenEdited();

public:


    void updateRect(QRect &rect);
    void setSettingsToWidget(QString str);
    void getSettingsFromWidget(QString str);

    Carea(QWidget *parent=0);
    ~Carea();
};

class CareaProperty:public QWidget
{
    Q_OBJECT

public:
    Carea *area;
    CareaProperty(QWidget *parent=0);
    ~CareaProperty();
};

#endif

