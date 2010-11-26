#include "colorCombo.h"

CcolorCombo::CcolorCombo(QWidget *parent):QComboBox(parent)
{
    addItem(tr("ºìÉ«"));
    addItem(tr("ÂÌÉ«"));
    addItem(tr("»ÆÉ«"));
}

QColor CcolorCombo::getColor()
{
    QColor col;

    if(currentIndex() == 0)
        col = QColor(Qt::red);
    else if(currentIndex() == 1)
        col = QColor(Qt::green);
    else
        col = QColor(Qt::yellow);

    return col;
}

CcolorCombo::~CcolorCombo()
{

}

void CcolorCombo::setColor(const QColor &col)
{
    if(col == QColor(Qt::red))
        setCurrentIndex(0);
    else if(col == QColor(Qt::green))
        setCurrentIndex(1);
    else
        setCurrentIndex(2);
}

CsizeCombo::CsizeCombo(QWidget *parent):QComboBox(parent)
{
    addItem(tr("16"));
    addItem(tr("24"));
    addItem(tr("32"));
}

CsizeCombo::~CsizeCombo()
{

}
