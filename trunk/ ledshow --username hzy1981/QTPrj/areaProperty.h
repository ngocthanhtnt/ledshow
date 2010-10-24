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
class CareaProperty:public QWidget
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

    CareaProperty(QWidget *parent=0);
    ~CareaProperty();
};

#endif

