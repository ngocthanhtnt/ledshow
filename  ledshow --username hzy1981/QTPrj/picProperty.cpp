#include "picProperty.h"
#include "mainwindow.h"
#include <QSettings>

extern MainWindow *w;
extern QSettings settings;

//图文属性编辑
CpicProperty::CpicProperty(QWidget *parent):QWidget(parent)
{
    QGridLayout *gridLayout;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;


    hLayout = new QHBoxLayout(this);

    area = new Carea(this);
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(area);
    hLayout->addLayout(vLayout);

    //gridLayout = new QGridLayout(this);
    textGroup = new QGroupBox(tr("文本内容"), this);
    editButton = new QPushButton(tr("编辑"), this);

    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(editButton);
    textGroup -> setLayout(vLayout);

    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(textGroup);
    hLayout->addLayout(vLayout);
/*
    gridLayout = new QGridLayout(this);
    paraGroup = new QGroupBox(tr("参数修改"), this);
    showModeLabel = new QLabel(tr("显示模式"), this);
    speedLabel = new QLabel(tr("运行速度"), this);
    stayTimeLabel = new QLabel(tr("停留时间"), this);

    showModeCombo = new CshowModeCombo(this);
    speedCombo = new CshowSpeedCombo(this);
    stayTimeEdit = new QLineEdit(this);
    gridLayout -> addWidget(showModeLabel, 0, 0);
    gridLayout -> addWidget(showModeCombo, 0, 1);
    gridLayout -> addWidget(speedLabel, 1, 0);
    gridLayout -> addWidget(speedCombo, 1, 1);
    gridLayout -> addWidget(stayTimeLabel, 2, 0);
    gridLayout -> addWidget(stayTimeEdit, 2, 1);
    paraGroup -> setLayout(gridLayout);
*/
    showModeEdit = new CshowModeEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(showModeEdit);
    hLayout->addLayout(vLayout);
    hLayout->addStretch();
    setLayout(hLayout);

    edit = new TextEdit(this);
    //textEdit->show();//clear();
    edit->getEdit()->clear();
    connect(editButton, SIGNAL(clicked()), edit, SLOT(show()));
}

CpicProperty::~CpicProperty()
{

}

void CpicProperty::getSettingsFromWidget(QString str)
{
    showModeEdit->getSettingsFromWidget(str);

    settings.beginGroup(str);
    settings.setValue("text", edit->getEdit()->toPlainText());
    settings.endGroup();

}

void CpicProperty::setSettingsToWidget(QString str)
{
    //QStringList keys;
    QString text;

    showModeEdit->setSettingsToWidget(str);
    settings.beginGroup(str);
    text = settings.value("text").toString();
    if(text == "")
        text == QString(tr("图文显示"));
    //textEdit->clear();
    edit->getEdit()->setPlainText(text);
    settings.endGroup();
}
