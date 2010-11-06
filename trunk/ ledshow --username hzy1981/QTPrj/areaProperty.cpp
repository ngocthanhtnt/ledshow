#include "areaProperty.h"
#include <QSettings>
#include "mainwindow.h"

extern MainWindow *w;
extern QSettings settings;
//分区属性编辑
//////////////////////////////
Carea::Carea(QWidget *parent):QGroupBox(parent)
{
    QHBoxLayout *hBoxLayout;
    QGridLayout *gridLayout;
    int screenWidth, screenHeight;

    settings.beginGroup("screen");
    screenWidth = settings.value("xLen").toInt();//w->screenArea->width();
    screenHeight = settings.value("yLen").toInt();//w->screenArea->height();
    settings.endGroup();

    QValidator *xValidator = new QIntValidator(0,screenWidth,this);
    QValidator *yValidator = new QIntValidator(0,screenHeight,this);

    //groupBox = new QGroupBox(tr("分区属性"), this);

    nameLabel = new QLabel(tr("名字"), this);
    xLabel = new QLabel(tr("x起点"), this);
    yLabel = new QLabel(tr("y起点"), this);
    widthLabel = new QLabel(tr("宽度"), this);
    heightLabel = new QLabel(tr("高度"), this);

    int width = 50;
    nameEdit = new QLineEdit(this);
    xEdit = new QLineEdit(this);
    yEdit = new QLineEdit(this);
    widthEdit = new QLineEdit(this);
    heightEdit = new QLineEdit(this);

    nameEdit->setFixedWidth(width);
    xEdit->setFixedWidth(width);
    yEdit->setFixedWidth(width);
    widthEdit->setFixedWidth(width);
    heightEdit->setFixedWidth(width);

    connect(xEdit, SIGNAL(editingFinished()), this, SLOT(xEdited()));
    connect(yEdit, SIGNAL(editingFinished()), this, SLOT(yEdited()));
    connect(widthEdit, SIGNAL(editingFinished()), this, SLOT(xLenEdited()));
    connect(heightEdit, SIGNAL(editingFinished()), this, SLOT(yLenEdited()));

    xEdit->setValidator(xValidator);
    yEdit->setValidator(yValidator);
    widthEdit->setValidator(xValidator);
    heightEdit->setValidator(yValidator);
/*
    nameEdit->setMaxLength(4);
    xEdit->setMaxLength(4);
    yEdit->setMaxLength(4);
    widthEdit->setMaxLength(4);
    heightEdit->setMaxLength(4);
*/
    setTitle(tr("分区属性"));
    //setFixedWidth(150);
    gridLayout = new QGridLayout(this);

    gridLayout -> addWidget(nameLabel,0,0);
    gridLayout -> addWidget(nameEdit,0,1);

    gridLayout -> addWidget(xLabel, 1, 0);
    gridLayout -> addWidget(xEdit, 1, 1);
    gridLayout -> addWidget(yLabel, 2, 0);
    gridLayout -> addWidget(yEdit, 2, 1);
    gridLayout -> addWidget(widthLabel, 3, 0);
    gridLayout -> addWidget(widthEdit, 3, 1);
    gridLayout -> addWidget(heightLabel, 4, 0);
    gridLayout -> addWidget(heightEdit, 4, 1);
    //gridLayout -> setColumnStretch(1, 10);

    setLayout(gridLayout);
    //resize(200,200);

    //hBoxLayout = new QHBoxLayout(this);
    //hBoxLayout->addWidget(groupBox);

    //setLayout(hBoxLayout);

    setAttribute(Qt::WA_StaticContents);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    //resize(sizeHint().width(),sizeHint().height());
}

void Carea::updateRect(QRect &rect)
{

    xEdit->setText(QString::number(rect.x()));
    yEdit->setText(QString::number(rect.y()));
    widthEdit->setText(QString::number(rect.width()));
    heightEdit->setText(QString::number(rect.height()));


}

void Carea::xEdited()
{
    int x,xLen;
    CshowArea *area;
    QTreeWidgetItem *item;
    QString str;

    if(xEdit->text().toInt() + widthEdit->text().toInt() > w->screenArea->width())
    {
        x = w->screenArea->width() - widthEdit->text().toInt();
        xEdit->setText(QString::number(x));
    }
    else
        x = xEdit->text().toInt();

    item = w->progManage->treeWidget->currentItem();//setCurrentItem(this->treeItem);
    if(checkItemType(item) != AREA_PROPERTY)
        item = item->parent();

    str = item->data(0, Qt::UserRole).toString();

    settings.beginGroup(str);
    settings.setValue("x", x);
    settings.endGroup();

    area = w->screenArea->getFocusArea(); //当前点中的分区
    area->move(x, yEdit->text().toInt());
}

void Carea::yEdited()
{
    int y,yLen;
    CshowArea *area;
    QTreeWidgetItem *item;
    QString str;

    if(yEdit->text().toInt() + heightEdit->text().toInt() > w->screenArea->height())
    {
        y = w->screenArea->height() - heightEdit->text().toInt();
        yEdit->setText(QString::number(y));
    }
    else
        y = yEdit->text().toInt();

    item = w->progManage->treeWidget->currentItem();//setCurrentItem(this->treeItem);
    if(checkItemType(item) != AREA_PROPERTY)
        item = item->parent();

    str = item->data(0, Qt::UserRole).toString();

    settings.beginGroup(str);
    settings.setValue("y", y);
    settings.endGroup();

    area = w->screenArea->getFocusArea(); //当前点中的分区
    area->move(xEdit->text().toInt(), y);
}

void Carea::xLenEdited()
{
    int x,width;
    CshowArea *area;
    QTreeWidgetItem *item;
    QString str;

    if(xEdit->text().toInt() + widthEdit->text().toInt() > w->screenArea->width())
    {
        width = w->screenArea->width() - xEdit->text().toInt();
        widthEdit->setText(QString::number(width));
    }
    else
        width = widthEdit->text().toInt();

    item = w->progManage->treeWidget->currentItem();//setCurrentItem(this->treeItem);
    if(checkItemType(item) != AREA_PROPERTY)
        item = item->parent();

    str = item->data(0, Qt::UserRole).toString();

    settings.beginGroup(str);
    settings.setValue("xLen", width);
    settings.endGroup();

    area = w->screenArea->getFocusArea(); //当前点中的分区
    //area->move(xEdit, yEdit->text().toInt());
    area->resize(width, heightEdit->text().toInt());
}

void Carea::yLenEdited()
{
    int y,height;
    CshowArea *area;
    QTreeWidgetItem *item;
    QString str;

    if(yEdit->text().toInt() + heightEdit->text().toInt() > w->screenArea->height())
    {
        height = w->screenArea->height() - yEdit->text().toInt();
        heightEdit->setText(QString::number(height));
    }
    else
        height = heightEdit->text().toInt();

    item = w->progManage->treeWidget->currentItem();//setCurrentItem(this->treeItem);
    if(checkItemType(item) != AREA_PROPERTY)
        item = item->parent();

    str = item->data(0, Qt::UserRole).toString();

    settings.beginGroup(str);
    settings.setValue("yLen", height);
    settings.endGroup();

    area = w->screenArea->getFocusArea(); //当前点中的分区
    area->resize(widthEdit->text().toInt(), height);
}

Carea::~Carea()
{


}

void Carea::getSettingsFromWidget(QString str)
{
    return;
    settings.beginGroup(str);
    settings.setValue("name", nameEdit->text().toInt());
    settings.setValue("x", xEdit->text().toInt());
    settings.setValue("y", yEdit->text().toInt());
    settings.setValue("xLen", widthEdit->text().toInt());
    settings.setValue("yLen", heightEdit->text().toInt());
    settings.endGroup();
}

void Carea::setSettingsToWidget(QString str)
{
    QStringList keys;

    //设置前端开信号
    disconnect(xEdit, SIGNAL(editingFinished()), this, SLOT(xEdited()));
    disconnect(yEdit, SIGNAL(editingFinished()), this, SLOT(yEdited()));
    disconnect(widthEdit, SIGNAL(editingFinished()), this, SLOT(xLenEdited()));
    disconnect(heightEdit, SIGNAL(editingFinished()), this, SLOT(yLenEdited()));

    settings.beginGroup(str);
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag EQ 0)
    {

       settings.setValue("setFlag", 1);
    }

    //名字
    nameEdit->setText(settings.value("name").toString());
    xEdit->setText(QString::number(settings.value("x").toInt()));
    yEdit->setText(QString::number(settings.value("y").toInt()));
    widthEdit->setText(QString::number(settings.value("xLen").toInt()));
    heightEdit->setText(QString::number(settings.value("yLen").toInt()));


    settings.endGroup();

    //重新连接信号
    connect(xEdit, SIGNAL(editingFinished()), this, SLOT(xEdited()));
    connect(yEdit, SIGNAL(editingFinished()), this, SLOT(yEdited()));
    connect(widthEdit, SIGNAL(editingFinished()), this, SLOT(xLenEdited()));
    connect(heightEdit, SIGNAL(editingFinished()), this, SLOT(yLenEdited()));
}

CareaProperty::CareaProperty(QWidget *parent):QWidget(parent)
{
    QHBoxLayout *hLayout;

    hLayout = new QHBoxLayout(this);
    area = new Carea(this);
    hLayout->addWidget(area);
    hLayout->addStretch();
    setLayout(hLayout);
}


CareaProperty::~CareaProperty()
{

}
