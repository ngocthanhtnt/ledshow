#ifndef COLORCOMBO_H
#define COLORCOMBO_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QColor>
#include "..\Includes.h"

#define RED_INDEX 0
#define YEL_INDEX 1
#define GRE_INDEX 2

#define COLOR_INDEX_2_COLOR(x) (x+1)

class CsizeCombo:public QComboBox
{
    Q_OBJECT
public:
    void setItems();
    CsizeCombo(QWidget *parent = 0);
    ~CsizeCombo();

};

class CcolorCombo:public QComboBox
{
    Q_OBJECT
public:
    void setItems();
    QColor getColor();
    void setColor(const QColor &col);
    CcolorCombo(QWidget *parent = 0);
    ~CcolorCombo();
};
INT8U getColorDataFromIndex(INT8U Index);
INT8U getColorData(const QColor &col);
QColor getQColor(INT8U colorData);
#endif // COLORCOMBO_H
