
#include "colorCombo.h"

CcolorCombo::CcolorCombo(QWidget *parent):QComboBox(parent)
{
    QPixmap *pixmap;//(16,16);

    if(GET_BIT(Screen_Para.Color, 0x00)>0 || Screen_Para.Color EQ 0 || Screen_Para.Color > 7)
    {
        pixmap = new QPixmap(16,16);
        pixmap->fill(QColor(Qt::red));
        QIcon redicon(*pixmap);
        addItem(redicon, tr(""));
    }

    if(GET_BIT(Screen_Para.Color, 0x01))
    {
        pixmap = new QPixmap(16,16);
        pixmap->fill(QColor(Qt::green));
        QIcon greenicon(*pixmap);
        addItem(greenicon, tr(""));
    }

    if(GET_BIT(Screen_Para.Color, 0x02))
    {
        pixmap = new QPixmap(16,16);
        pixmap->fill(QColor(Qt::yellow));
        QIcon yellowicon(*pixmap);
        addItem(yellowicon, tr(""));
    }
}

QColor getQColor(INT8U colorData)
{
    QColor col;
    int index = 0;

    if(GET_BIT(colorData, 0x00) > 0)
    {
      if(GET_BIT(Screen_Para.Color, 0x00) > 0)// || Screen_Para.Color EQ 0 || Screen_Para.Color > 7)
        col = QColor(Qt::red);
      else if(GET_BIT(Screen_Para.Color, 0x01) > 0)
        col = QColor(Qt::green);
      else if(GET_BIT(Screen_Para.Color, 0x02) > 0)
        col = QColor(Qt::yellow);
      else
        col = QColor(Qt::red);
    }
    else if(GET_BIT(colorData, 0x01) > 0)
    {
        if(GET_BIT(Screen_Para.Color, 0x00) > 0)
            index ++;

        if(GET_BIT(Screen_Para.Color, 0x01) > 0)
        {
            index ++;
            if(index EQ 2)
              return QColor(Qt::green);
         }

        if(GET_BIT(Screen_Para.Color, 0x02) > 0)
        {
             index ++;
             if(index EQ 2)
               return QColor(Qt::yellow);
         }

        return QColor(Qt::green);
    }
    else if(GET_BIT(colorData, 0x02) > 0)
        col = QColor(Qt::yellow);
    else
        col = QColor(Qt::black);
    return col;
}

QColor CcolorCombo::getColor()
{
    QColor col;

    if(currentIndex() == 0)
    {
      if(GET_BIT(Screen_Para.Color, 0x01) > 0)// || Screen_Para.Color EQ 0 || Screen_Para.Color > 7)
        col = QColor(Qt::red);
      else if(GET_BIT(Screen_Para.Color, 0x02) > 0)
        col = QColor(Qt::blue);
      else if(GET_BIT(Screen_Para.Color, 0x03) > 0)
        col = QColor(Qt::yellow);
      else
        col = QColor(Qt::red);
    }
     else if(currentIndex() == 1)
    {
     if(GET_BIT(Screen_Para.Color, 0x02) > 0)
       col = QColor(Qt::blue);
     else if(GET_BIT(Screen_Para.Color, 0x03) > 0)
       col = QColor(Qt::yellow);
     else
       col = QColor(Qt::blue);

    }
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
