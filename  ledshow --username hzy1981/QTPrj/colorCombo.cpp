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
