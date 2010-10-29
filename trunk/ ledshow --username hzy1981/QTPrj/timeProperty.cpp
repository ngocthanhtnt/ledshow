#include "timeProperty.h"

//正反计时编辑
CtimeProperty::CtimeProperty(QWidget *parent):QWidget(parent)
{
    //QGridLayout *gridLayout,*mainLayout;
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;


    hLayout = new QHBoxLayout(this);
    //mainLayout = new QGridLayout(this);

    area = new Carea(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(area);
    //vLayout->addStretch();
    hLayout->addLayout(vLayout);

    smLineEdit = new CsmLineEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(smLineEdit);
    //vLayout->addStretch();
    hLayout->addLayout(vLayout);

    //textGroup = new QGroupBox(tr("固定文本"), this);
    simpleTextEdit = new CsimpleTextEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(simpleTextEdit);
    //vLayout->addStretch();
    hLayout->addLayout(vLayout);

    dateTimeEdit = new CdateTimeEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(dateTimeEdit);
    //vLayout->addStretch();
    hLayout->addLayout(vLayout);
/*
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(simpleTextEdit);

    gridLayout -> addLayout(vLayout, 0, 0);

    vLayout = new QVBoxLayout(this);
    vLayout -> addWidget(dateTimeEdit);
*/
    //hLayout ->addWidget(area);
    //hLayout ->addWidget(smLineEdit);
    //hLayout ->addWidget(simpleTextEdit);
    //hLayout ->addWidget(dateTimeEdit);
    hLayout->addStretch();
    //textGroup -> setLayout(gridLayout);
    //mainLayout->addWidget(textGroup, 0, 0);
    setLayout(hLayout);
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
