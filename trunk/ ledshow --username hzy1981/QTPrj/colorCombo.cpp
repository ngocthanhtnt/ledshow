
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

INT8U getColorData(const QColor &col)
{
    INT8U data = 0;
    INT8U index = 0;

    if(col == QColor(Qt::red))
    {
        index = 0;
       if(GET_BIT(Screen_Para.Color, 0) == 0)
         ASSERT_FAILED();
    }
    else if(col == QColor(Qt::green))
    {
        if(GET_BIT(Screen_Para.Color, 0))
          index ++ ;
        if(GET_BIT(Screen_Para.Color, 1) == 0)
          ASSERT_FAILED();
    }
    else if(col == QColor(Qt::yellow))
    {
        if(GET_BIT(Screen_Para.Color, 0))
            index ++ ;
        if(GET_BIT(Screen_Para.Color, 1))
            index ++;
        if(GET_BIT(Screen_Para.Color, 2) == 0)
            ASSERT_FAILED();
    }

    //return index;
    return (0x01 <<index);
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
    int index;
    INT8U colorData = 0;

    index = currentIndex();
    colorData = (0x01 <<index);
    return getQColor(colorData);
    /*
    QColor col;

    if(currentIndex() == 0)
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
    else if(currentIndex() == 1)
    {
        if(GET_BIT(Screen_Para.Color, 0x00) > 0)
          col = QColor(Qt::green);
        else if(GET_BIT(Screen_Para.Color, 0x03) > 0)
          col = QColor(Qt::yellow);
        else
          col = QColor(Qt::green);
    }
    else
        col = QColor(Qt::yellow);

    return col;
    */
}

CcolorCombo::~CcolorCombo()
{

}

void CcolorCombo::setColor(const QColor &col)
{
    INT8U data = 0;
    INT8U index = 0;

    if(col == QColor(Qt::red))
    {
        index = 0;
       if(GET_BIT(Screen_Para.Color, 0) != 0)
         ASSERT_FAILED();
    }
    else if(col == QColor(Qt::green))
    {
        if(GET_BIT(Screen_Para.Color, 0))
          index ++ ;
        if(GET_BIT(Screen_Para.Color, 1) == 0)
          ASSERT_FAILED();
    }
    else if(col == QColor(Qt::yellow))
    {
        if(GET_BIT(Screen_Para.Color, 0))
            index ++ ;
        if(GET_BIT(Screen_Para.Color, 1))
            index ++;
        if(GET_BIT(Screen_Para.Color, 2) == 0)
            ASSERT_FAILED();
    }

    //return index;
    setCurrentIndex(index);
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
