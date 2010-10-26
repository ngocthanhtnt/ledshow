#include "colorCombo.h"

CcolorCombo::CcolorCombo(QWidget *parent):QComboBox(parent)
{
    addItem(tr("ºìÉ«"));
    addItem(tr("ÂÌÉ«"));
    addItem(tr("»ÆÉ«"));
}

CcolorCombo::~CcolorCombo()
{

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
