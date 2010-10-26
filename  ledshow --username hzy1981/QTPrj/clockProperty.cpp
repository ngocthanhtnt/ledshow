#include "mainwindow.h"
#include "showArea.h"
#include "clockProperty.h"
#include "colorCombo.h"
#include <QSettings>

extern MainWindow *w;
extern QSettings settings;
//时钟属性编辑
CclockProperty::CclockProperty(QWidget *parent):QWidget(parent)
{
    QGridLayout *gridLayout;

    gridLayout = new QGridLayout(this);

    editGroup = new QGroupBox(this);
    pointRadiusLabel = new QLabel(tr("整点半径"), this);
    point369RadiusLabel = new QLabel(tr("369点半径"), this);
    hourWidthLabel = new QLabel(tr("小时宽度"), this);
    minWidthLabel = new QLabel(tr("分钟宽度"), this);
    secWidthLabel = new QLabel(tr("秒钟宽度"), this);

    pointColorLabel = new QLabel(tr("整点颜色"), this);
    point369ColorLabel = new QLabel(tr("369点颜色"), this);
    hourColorLabel = new QLabel(tr("小时颜色"), this);
    minColorLabel = new QLabel(tr("分钟颜色"), this);
    secColorLabel = new QLabel(tr("秒钟颜色"), this);

    pointRadiusEdit = new QLineEdit(this);
    point369RadiusEdit = new QLineEdit(this);
    hourWidthEdit = new QLineEdit(this);
    minWidthEdit= new QLineEdit(this);
    secWidthEdit = new QLineEdit(this);

    pointColorCombo = new CcolorCombo(this);
    point369ColorCombo = new CcolorCombo(this);
    hourColorCombo = new CcolorCombo(this);
    minColorCombo = new CcolorCombo(this);
    secColorCombo = new CcolorCombo(this);

    gridLayout -> addWidget(pointRadiusLabel, 0, 0);
    gridLayout -> addWidget(pointRadiusEdit, 0, 1);
    gridLayout -> addWidget(pointColorLabel, 0, 2);
    gridLayout -> addWidget(pointColorCombo, 0, 3);

    gridLayout -> addWidget(point369RadiusLabel, 1, 0);
    gridLayout -> addWidget(point369RadiusEdit, 1, 1);
    gridLayout -> addWidget(point369ColorLabel, 1, 2);
    gridLayout -> addWidget(point369ColorCombo, 1, 3);

    gridLayout -> addWidget(hourWidthLabel, 2, 0);
    gridLayout -> addWidget(hourWidthEdit, 2, 1);
    gridLayout -> addWidget(hourColorLabel, 2, 2);
    gridLayout -> addWidget(hourColorCombo, 2, 3);

    gridLayout -> addWidget(minWidthLabel, 3, 0);
    gridLayout -> addWidget(minWidthEdit, 3, 1);
    gridLayout -> addWidget(minColorLabel, 3, 2);
    gridLayout -> addWidget(minColorCombo, 3, 3);

    gridLayout -> addWidget(secWidthLabel, 4, 0);
    gridLayout -> addWidget(secWidthEdit, 4, 1);
    gridLayout -> addWidget(secColorLabel, 4, 2);
    gridLayout -> addWidget(secColorCombo, 4, 3);
    editGroup -> setLayout(gridLayout);


    textGroup = new QGroupBox(tr("固定文本"), this);
    simpleTextEdit = new CsimpleTextEdit(textGroup);
    gridLayout = new QGridLayout(this);
    gridLayout ->addWidget(simpleTextEdit, 0, 0);
    textGroup ->setLayout(gridLayout);

    gridLayout = new QGridLayout(this);
    gridLayout -> addWidget(editGroup, 0, 0);
    gridLayout -> addWidget(textGroup, 0, 1);
    setLayout(gridLayout);

    connect(pointRadiusEdit, SIGNAL(editingFinished()), this, SIGNAL(edited()));
    connect(point369RadiusEdit, SIGNAL(editingFinished()), this, SIGNAL(edited()));
    connect(hourWidthEdit, SIGNAL(editingFinished()), this, SIGNAL(edited()));
    connect(minWidthEdit, SIGNAL(editingFinished()), this, SIGNAL(edited()));
    connect(secWidthEdit, SIGNAL(editingFinished()), this, SIGNAL(edited()));

    connect(pointColorCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));
    connect(point369ColorCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));
    connect(hourColorCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));
    connect(minColorCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));
    connect(secColorCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));

    connect(secColorCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));

    connect(simpleTextEdit, SIGNAL(edited()), this, SIGNAL(edited()));

    connect(this, SIGNAL(edited()), this, SLOT(propertyEdited()));
}

CclockProperty::~CclockProperty()
{

}

void CclockProperty::getSettingsFromWidget(QString str)
{
    int type;
    int tmp;

    settings.beginGroup(str);

    type = settings.value("type").toInt();
    if(type == CLOCK_PROPERTY)
    {
        tmp = pointRadiusEdit->text().toInt();
        qDebug("get pointRadius = %d", tmp);

        settings.setValue("pointRadius", pointRadiusEdit->text().toInt());   //整点半径
        settings.setValue("point369Radius", point369RadiusEdit->text().toInt()); //369点半径
        settings.setValue("hourWidth", hourWidthEdit->text().toInt());//时钟宽度
        settings.setValue("minWidth", minWidthEdit->text().toInt()); //分钟宽度
        settings.setValue("secWidth", secWidthEdit->text().toInt()); //分钟宽度

        settings.setValue("pointColor", pointColorCombo->currentIndex()); //整点颜色
        settings.setValue("point369Color", point369ColorCombo->currentIndex()); //369点颜色
        settings.setValue("hourColor", hourColorCombo->currentIndex()); //时钟颜色
        settings.setValue("minColor", minColorCombo->currentIndex()); //分钟颜色
        settings.setValue("secColor", secColorCombo->currentIndex()); //秒钟颜色
    }
    else
        ASSERT_FAILED();

    settings.endGroup();

    if(type == CLOCK_PROPERTY)
      simpleTextEdit->getSettingsFromWidget(str);
}

//刷新显示区域
void updateClockShowArea(CshowArea *area, QTreeWidgetItem *item)
{
    //CshowArea *area;
    QString str;


    if(area != (CshowArea *)0) //
    {
        str = item->data(0,Qt::UserRole).toString();

        getClockParaFromSettings(str,area->File_Para);
        area->imageBk = getTextImage(str);

        qDebug("file_para flag = %d", area->File_Para.Temp_Para.Flag);
        area->update(); //刷新显示

    }
    else
    {
        ASSERT_FAILED();
    }

}

//属性编辑的SLOT
void CclockProperty::propertyEdited()
{
    CshowArea *area;
    QTreeWidgetItem *item;

    qDebug("propertyEdited");
    area = w->screenArea->getFocusArea(); //当前焦点分区

    if(area != (CshowArea *)0) //
    {
        //当前选中的item
        item = area->fileItem;//w->progManage->treeWidget->currentItem();////// //w->progManage->treeWidget->currentItem();
        if(item != (QTreeWidgetItem *)0)
        {
            QString str = item->data(0,Qt::UserRole).toString();
            getSettingsFromWidget(str);
            updateClockShowArea(area, item);
        }
    }
}

//从settings中获取参数
void getClockParaFromSettings(QString str, U_File_Para &para)
{
    int tmp;
   // QString str;

    para.Clock_Para.Flag = SHOW_CLOCK;
    settings.beginGroup(str);

    tmp = settings.value("pointRadius").toInt(); //整点半径
    para.Clock_Para.Hour_Point_Radius = (unsigned char)tmp;

    tmp = settings.value("point369Radius").toInt(); //369点半径
    para.Clock_Para.Hour369_Point_Radius = (unsigned char)tmp;

    tmp = settings.value("hourWidth").toInt(); //时钟宽度
    para.Clock_Para.Hour_Line_Width = (unsigned char)tmp;

    tmp = settings.value("minWidth").toInt(); //分钟宽度
    para.Clock_Para.Min_Line_Width = (unsigned char)tmp;

    tmp = settings.value("secWidth").toInt(); //秒钟宽度
    para.Clock_Para.Sec_Line_Width = (unsigned char)tmp;

    tmp = settings.value("point369Color").toInt(); //369点颜色
    para.Clock_Para.Hour369_Point_Color = 0;
    SET_BIT(para.Clock_Para.Hour369_Point_Color, tmp);
    qDebug("point369color = %d", para.Clock_Para.Hour369_Point_Color);

    tmp = settings.value("pointColor").toInt(); //整点颜色
    para.Clock_Para.Hour_Point_Color = 0;
    SET_BIT(para.Clock_Para.Hour_Point_Color, tmp);
    qDebug("pointColor = %d", para.Clock_Para.Hour_Point_Color);

    tmp = settings.value("hourColor").toInt(); //小时颜色
    para.Clock_Para.Hour_Line_Color = 0;
    SET_BIT(para.Clock_Para.Hour_Line_Color, tmp);
    qDebug("hourColor = %d", para.Clock_Para.Hour_Line_Color);

    tmp = settings.value("minColor").toInt(); //分钟颜色
    para.Clock_Para.Min_Line_Color = 0;
    SET_BIT(para.Clock_Para.Min_Line_Color, tmp);
    qDebug("minColor = %d", para.Clock_Para.Min_Line_Color);

    tmp = settings.value("secColor").toInt(); //秒钟颜色
    para.Clock_Para.Sec_Line_Color = 0;
    SET_BIT(para.Clock_Para.Sec_Line_Color, tmp);
    qDebug("secColor = %d", para.Clock_Para.Sec_Line_Color);
/*
    settings.setValue("fontIndex", fontCombo->currentIndex());
    settings.setValue("fontSizeIndex", fontSizeCombo->currentIndex());
    settings.setValue("fontName", fontCombo->currentText());
    settings.setValue("fontSize", fontSizeCombo->currentText().toInt());

    settings.setValue("color", colorCombo->currentIndex());
    settings.setValue("bText", bButton->isChecked());
    settings.setValue("uText", uButton->isChecked());
    settings.setValue("iText", iButton->isChecked());
    settings.setValue("text", lineEdit->text());

    para.Clock_Para.Bk_Color = settings.value("color").toInt();
    para.Clock_Para.Bk_Color = settings.value("color").toInt();

    tmp = settings.value("fontSizeIndex").toInt();
    tmp = settings.value("fontName").toString();
    */
    settings.endGroup();
}

/*
    QLineEdit *pointRadiusEdit; //整点半径
    QLineEdit *point369RadiusEdit; //
    QLineEdit *hourWidthEdit;
    QLineEdit *minWidthEdit;

    CcolorCombo *pointColorCombo;
    CcolorCombo *point369ColorCombo;
    CcolorCombo *hourColorCombo;
    CcolorCombo *minColorCombo;
    CcolorCombo *secColorCombo;

    QGroupBox *textGroup;
    CsimpleTextEdit *simpleTextEdit;
 */
//void CclockProperty::
void CclockProperty::setSettingsToWidget(QString str)
{
    QStringList keys;
    QString text;

    disconnect(this, SIGNAL(edited()), this, SLOT(propertyEdited()));
    settings.beginGroup(str);
    keys = settings.allKeys();
    if(keys.size() <10)
    {
      settings.setValue("pointRadius", 3);   //整点半径
      settings.setValue("point369Radius", 3); //369点半径
      settings.setValue("hourWidth", 8);//时钟宽度
      settings.setValue("minWidth", 5); //分钟宽度
      settings.setValue("secWidth", 3); //秒钟宽度

      settings.setValue("pointColor", RED_INDEX); //整点颜色
      settings.setValue("point369Color", RED_INDEX); //369点颜色
      settings.setValue("hourColor", RED_INDEX); //时钟颜色
      settings.setValue("minColor", RED_INDEX); //分钟颜色
      settings.setValue("secColor", RED_INDEX); //秒钟颜色
    }

    pointRadiusEdit->setText(QString::number(settings.value("pointRadius").toInt()));
    point369RadiusEdit->setText(QString::number(settings.value("point369Radius").toInt()));
    hourWidthEdit->setText(QString::number(settings.value("hourWidth").toInt()));
    minWidthEdit->setText(QString::number(settings.value("minWidth").toInt()));
    secWidthEdit->setText(QString::number(settings.value("secWidth").toInt()));

    pointColorCombo->setCurrentIndex(settings.value("pointColor").toInt());
    point369ColorCombo->setCurrentIndex(settings.value("point369Color").toInt());
    hourColorCombo->setCurrentIndex(settings.value("hourColor").toInt());
    minColorCombo->setCurrentIndex(settings.value("minColor").toInt());
    secColorCombo->setCurrentIndex(settings.value("secColor").toInt());

    settings.endGroup();

    simpleTextEdit->setSettingsToWidget(str);

    connect(this, SIGNAL(edited()), this, SLOT(propertyEdited()));
}
