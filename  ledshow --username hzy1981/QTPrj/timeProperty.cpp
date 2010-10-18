#include "timeProperty.h"

//正反计时编辑
CtimeProperty::CtimeProperty(QWidget *parent):QWidget(parent)
{
    QGridLayout *gridLayout,*mainLayout;

    gridLayout = new QGridLayout(this);
    mainLayout = new QGridLayout(this);

    textGroup = new QGroupBox(tr("固定文本"), this);
    simpleTextEdit = new CsimpleTextEdit(this);

    gridLayout -> addWidget(simpleTextEdit, 0, 0);
    //gridLayout -> addWidget(editButton, 1, 0);
    textGroup -> setLayout(gridLayout);
    mainLayout->addWidget(textGroup, 0, 0);
    setLayout(mainLayout);
}

CtimeProperty::~CtimeProperty()
{

}

void CtimeProperty::getSettingsFromWidget(QString str)
{

}

void CtimeProperty::setSettingsToWidget(QString str)
{

}
