#include "picProperty.h"
#include "mainwindow.h"
#include <QSettings>

extern MainWindow *w;
extern QSettings settings;
/*
const S_Mode_Func Mode_Func[]=
{
  {&Move_Left},
  {&Move_Right},
  {&Move_Up},
  {&Move_Down},
  {&Move_Left_Cover},
  {&Move_Right_Cover},
  {&Move_Up_Cover},
  {&Move_Down_Cover},
  {&Move_Left_Up_Cover},
  {&Move_Right_Up_Cover},
  {&Move_Left_Down_Cover},
  {&Move_Right_Down_Cover},
  {&Move_Left_Right_Open},
  {&Move_Up_Down_Open},
  {&Move_Left_Right_Close},
  {&Move_Up_Down_Close},

};
*/
CshowModeCombo::CshowModeCombo(QWidget *parent):QComboBox(parent)
{
    addItem(tr("左移"));
    addItem(tr("右移"));
    addItem(tr("上移"));
    addItem(tr("下移"));
    addItem(tr("左划"));
    addItem(tr("右划"));
    addItem(tr("上划"));
    addItem(tr("下划"));
    addItem(tr("左上划"));
    addItem(tr("右上划"));
    addItem(tr("左下划"));
    addItem(tr("右下划"));
    addItem(tr("左右开帘"));
    addItem(tr("上下开帘"));
    addItem(tr("左右合帘"));
    addItem(tr("上下合帘"));
 }

CshowModeCombo::~CshowModeCombo()
{

}

CshowSpeedCombo::CshowSpeedCombo(QWidget *parent):QComboBox(parent)
{
    addItem(tr("0"));
    addItem(tr("1"));
    addItem(tr("2"));
    addItem(tr("3"));
    addItem(tr("4"));
    addItem(tr("5"));
    addItem(tr("6"));
    addItem(tr("7"));
    addItem(tr("8"));
    addItem(tr("9"));
 }

CshowSpeedCombo::~CshowSpeedCombo()
{

}

//图文属性编辑
CpicProperty::CpicProperty(QWidget *parent):QWidget(parent)
{
    QGridLayout *gridLayout,*mainLayout;

    gridLayout = new QGridLayout(this);
    mainLayout = new QGridLayout(this);

    textGroup = new QGroupBox(tr("文本内容"), this);
    //textLabel = new QLabel(tr("文本"), this);
    //textEdit = new QTextEdit(this);
    editButton = new QPushButton(tr("编辑"), this);
    //gridLayout -> addWidget(textEdit, 0, 0);
    gridLayout -> addWidget(editButton, 0, 0);
    textGroup -> setLayout(gridLayout);

    mainLayout -> addWidget(textGroup, 0, 0);

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

    mainLayout -> addWidget(paraGroup, 0, 1);
    setLayout(mainLayout);

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
    settings.beginGroup(str);

    settings.setValue("showMode", showModeCombo->currentIndex());
    settings.setValue("speed", speedCombo->currentIndex());
    settings.setValue("stayTime", stayTimeEdit->text().toInt());
    settings.setValue("text", edit->getEdit()->toPlainText());

    settings.endGroup();

}

void CpicProperty::setSettingsToWidget(QString str)
{
    QStringList keys;
    QString text;

    settings.beginGroup(str);
    keys = settings.allKeys();
    if(keys.isEmpty() == true)
    {
      //名字
      settings.setValue("type", PIC_PROPERTY);
      settings.setValue("showMode", 0);
      settings.setValue("speed", 1);
      settings.setValue("stayTime", 5);
      settings.setValue("text", QString(tr("图文显示")));
    }

    showModeCombo->setCurrentIndex(settings.value("showMode").toInt());
    speedCombo->setCurrentIndex(settings.value("speed").toInt());
    stayTimeEdit->setText(QString::number(settings.value("stayTime").toInt()));
    text = settings.value("text").toString();
    if(text == "")
        text == QString(tr("图文显示"));
    //textEdit->clear();
    edit->getEdit()->setPlainText(text);
    settings.endGroup();
}
