#ifndef COLORCOMBO_H
#define COLORCOMBO_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QColor>

#define RED_INDEX 0
#define YEL_INDEX 1
#define GRE_INDEX 2

#define COLOR_INDEX_2_COLOR(x) (x+1)

class CsizeCombo:public QComboBox
{
    Q_OBJECT
public:
    CsizeCombo(QWidget *parent = 0);
    ~CsizeCombo();

};

class CcolorCombo:public QComboBox
{
    Q_OBJECT
public:
    QColor getColor();
    CcolorCombo(QWidget *parent = 0);
    ~CcolorCombo();
};

#endif // COLORCOMBO_H
