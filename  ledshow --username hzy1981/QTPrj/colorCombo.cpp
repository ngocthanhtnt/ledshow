
#include "colorCombo.h"

CcolorCombo::CcolorCombo(QWidget *parent):QComboBox(parent)
{
  setItems();
}

void CcolorCombo::setItems()
{
    QPixmap *pixmap;//(16,16);

    clear();
    if(GET_BIT(Screen_Para.Base_Para.Color, 0x00)>0 ||\
       Screen_Para.Base_Para.Color EQ 0)// || Screen_Para.Base_Para.Color > 7)
    {
        pixmap = new QPixmap(16,16);
        pixmap->fill(QColor(Qt::red));
        QIcon redicon(*pixmap);
        addItem(redicon, tr(""));
    }

    if(GET_BIT(Screen_Para.Base_Para.Color, 0x01))
    {
        pixmap = new QPixmap(16,16);
        pixmap->fill(QColor(Qt::green));
        QIcon greenicon(*pixmap);
        addItem(greenicon, tr(""));
    }

    if(Screen_Para.Base_Para.Color EQ 0x03)
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
       if(GET_BIT(Screen_Para.Base_Para.Color, 0) == 0)
         ASSERT_FAILED();

       data = (0x01 <<index);
    }
    else if(col == QColor(Qt::green))
    {
        if(GET_BIT(Screen_Para.Base_Para.Color, 0))
          index ++ ;
        if(GET_BIT(Screen_Para.Base_Para.Color, 1) == 0)
          ASSERT_FAILED();

        data = (0x01 <<index);
    }
    else if(col == QColor(Qt::yellow))
    {
        if(GET_BIT(Screen_Para.Base_Para.Color, 0))
            data = data | 0x01;
        if(GET_BIT(Screen_Para.Base_Para.Color, 1))
            data = data | 0x02;
        if(Screen_Para.Base_Para.Color != 0x03)
            ASSERT_FAILED();


    }

    //return index;
    return data;
}

QColor getQColor(INT8U colorData)
{
    QColor col;
    int index = 0;

    if(colorData >= 0x03) //»ÆÉ«
    {
      if(Screen_Para.Base_Para.Color EQ 0x03)
        col = QColor(Qt::yellow);
      else
        col = QColor(Qt::red);
    }
    else if(GET_BIT(colorData, 0x00) > 0)
    {
      if(GET_BIT(Screen_Para.Base_Para.Color, 0x00) > 0)// || Screen_Para.Base_Para.Color EQ 0 || Screen_Para.Base_Para.Color > 7)
        col = QColor(Qt::red);
      else if(GET_BIT(Screen_Para.Base_Para.Color, 0x01) > 0)
        col = QColor(Qt::green);
      else
        col = QColor(Qt::red);
    }
    else if(GET_BIT(colorData, 0x01) > 0)
    {
        if(GET_BIT(Screen_Para.Base_Para.Color, 0x00) > 0)
            index ++;

        if(GET_BIT(Screen_Para.Base_Para.Color, 0x01) > 0)
        {
            index ++;
            if(index EQ 2)
              return QColor(Qt::green);
         }

        return QColor(Qt::green);
    }

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
      if(GET_BIT(Screen_Para.Base_Para.Color, 0x00) > 0)// || Screen_Para.Base_Para.Color EQ 0 || Screen_Para.Base_Para.Color > 7)
        col = QColor(Qt::red);
      else if(GET_BIT(Screen_Para.Base_Para.Color, 0x01) > 0)
        col = QColor(Qt::green);
      else if(GET_BIT(Screen_Para.Base_Para.Color, 0x02) > 0)
        col = QColor(Qt::yellow);
      else
        col = QColor(Qt::red);
    }
    else if(currentIndex() == 1)
    {
        if(GET_BIT(Screen_Para.Base_Para.Color, 0x00) > 0)
          col = QColor(Qt::green);
        else if(GET_BIT(Screen_Para.Base_Para.Color, 0x03) > 0)
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
       if(GET_BIT(Screen_Para.Base_Para.Color, 0) == 0)
         ASSERT_FAILED();
    }
    else if(col == QColor(Qt::green))
    {
        if(GET_BIT(Screen_Para.Base_Para.Color, 0))
          index ++ ;
        if(GET_BIT(Screen_Para.Base_Para.Color, 1) == 0)
          ASSERT_FAILED();
    }
    else if(col == QColor(Qt::yellow))
    {
        if(GET_BIT(Screen_Para.Base_Para.Color, 0))
            index ++ ;
        if(GET_BIT(Screen_Para.Base_Para.Color, 1))
            index ++;

        if(Screen_Para.Base_Para.Color != 0x03)
            ASSERT_FAILED();
        //if(GET_BIT(Screen_Para.Base_Para.Color, 2) == 0)
            //ASSERT_FAILED();
    }

    //return index;
    setCurrentIndex(index);
}

CsizeCombo::CsizeCombo(QWidget *parent):QComboBox(parent)
{
  //this->setUserData();
  setItems();
}

void CsizeCombo::setItems()
{
  clear();
  addItem(tr("16"));
  if(Card_Para.Font_Num > 1)
    addItem(tr("24"));
}

CsizeCombo::~CsizeCombo()
{

}
