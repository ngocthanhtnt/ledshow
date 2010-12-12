#include "colorCombo.h"

CcolorCombo::CcolorCombo(QWidget *parent):QComboBox(parent)
{
    QPixmap *pixmap;//(16,16);

    pixmap = new QPixmap(16,16);
    pixmap->fill(QColor(Qt::red));
    QIcon redicon(*pixmap);
    addItem(redicon, tr(""));

    pixmap = new QPixmap(16,16);
    pixmap->fill(QColor(Qt::green));
    QIcon greenicon(*pixmap);
    addItem(greenicon, tr(""));

    pixmap = new QPixmap(16,16);
    pixmap->fill(QColor(Qt::yellow));
    QIcon yellowicon(*pixmap);
    addItem(yellowicon, tr(""));
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
    else if(col == QColor(Qt::yellow))
        setCurrentIndex(2);
    else
        setCurrentIndex(0);
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
