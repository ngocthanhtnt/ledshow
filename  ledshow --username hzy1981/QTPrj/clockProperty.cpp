 #include "mainwindow.h"
#include "showArea.h"
#include "clockProperty.h"
#include "colorCombo.h"
#include <QSettings>

#define POSI_STEP 1
#define CLOCK_LINE_MAX_WIDTH 20

extern MainWindow *w;
extern QSettings settings;

CposiEdit::CposiEdit(QWidget *parent):QGroupBox(parent)
{
    setTitle(tr("文字位置调整"));
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;

    //vLayout = new QVBoxLayout(this);
    hLayout = new QHBoxLayout(this);

    item = new QComboBox(this);
    item->addItem(tr("固定文本"));
    item->addItem(tr("日期"));
    item->addItem(tr("星期"));

    left = new QPushButton(tr("左"));
    right = new QPushButton(tr("右"));
    up = new QPushButton(tr("上"));
    down = new QPushButton(tr("下"));
    def = new QPushButton(tr("默认"));

    int width = 30;
    left->setFixedWidth(width);
    right->setFixedWidth(width);
    up->setFixedWidth(width);
    down->setFixedWidth(width);
    def->setFixedWidth(width);

    hLayout->addWidget(item);
    hLayout->addWidget(left);
    hLayout->addWidget(right);
    hLayout->addWidget(up);
    hLayout->addWidget(down);
    hLayout->addWidget(def);
    hLayout->addStretch();
    setLayout(hLayout);
}


CposiEdit::~CposiEdit()
{

}

//时钟属性编辑
CclockProperty::CclockProperty(QWidget *parent):QWidget(parent)
{
    QGridLayout *gridLayout;
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;


    hLayout = new QHBoxLayout(this);
    vLayout = new QVBoxLayout(this);

    area = new Carea(this);
    nameEdit = new CnameEdit(this);

    vLayout->addWidget(nameEdit);
    vLayout ->addWidget(area);
    hLayout->addLayout(vLayout);

    editGroup = new QGroupBox(tr("外形属性"),this);
    pointRadiusLabel = new QLabel(tr("整点"), this);
    point369RadiusLabel = new QLabel(tr("369点"), this);
    pointMinRadiusLabel = new QLabel(tr("分点"), this);

    hourWidthLabel = new QLabel(tr("小时"), this);
    minWidthLabel = new QLabel(tr("分钟"), this);
    secWidthLabel = new QLabel(tr("秒钟"), this);
/*
    pointColorLabel = new QLabel(tr("整点颜色"), this);
    point369ColorLabel = new QLabel(tr("369点颜色"), this);
    hourColorLabel = new QLabel(tr("小时颜色"), this);
    minColorLabel = new QLabel(tr("分钟颜色"), this);
    secColorLabel = new QLabel(tr("秒钟颜色"), this);
*/
    int width = 40;
    pointRadiusEdit = new QSpinBox(this);
    pointRadiusEdit->setFixedWidth(width);
    point369RadiusEdit = new QSpinBox(this);
    point369RadiusEdit->setFixedWidth(width);
    pointMinRadiusEdit = new QSpinBox(this);
    pointMinRadiusEdit->setFixedWidth(width);

    hourWidthEdit = new QSpinBox(this);
    hourWidthEdit->setFixedWidth(width);
    minWidthEdit= new QSpinBox(this);
    minWidthEdit->setFixedWidth(width);
    secWidthEdit = new QSpinBox(this);
    secWidthEdit->setFixedWidth(width);

    pointRadiusEdit->setMaximum(CLOCK_LINE_MAX_WIDTH);
    point369RadiusEdit->setMaximum(CLOCK_LINE_MAX_WIDTH);
    pointMinRadiusEdit->setMaximum(CLOCK_LINE_MAX_WIDTH);
    hourWidthEdit->setMaximum(CLOCK_LINE_MAX_WIDTH);
    minWidthEdit->setMaximum(CLOCK_LINE_MAX_WIDTH);
    secWidthEdit->setMaximum(CLOCK_LINE_MAX_WIDTH);

    pointColorCombo = new CcolorCombo(this);
    point369ColorCombo = new CcolorCombo(this);
    pointMinColorCombo = new CcolorCombo(this);

    hourColorCombo = new CcolorCombo(this);
    minColorCombo = new CcolorCombo(this);
    secColorCombo = new CcolorCombo(this);

    pointStyle = new QComboBox(this);
    point369Style = new QComboBox(this);
    pointMinStyle = new QComboBox(this);

    pointStyle->addItem(tr("圆形"));
    pointStyle->addItem(tr("方形"));
    pointStyle->addItem(tr("线形"));
    pointStyle->addItem(tr("数字"));

    point369Style->addItem(tr("圆形"));
    point369Style->addItem(tr("方形"));
    point369Style->addItem(tr("线形"));
    point369Style->addItem(tr("数字"));

    pointMinStyle->addItem(tr("圆形"));
    pointMinStyle->addItem(tr("方形"));
    pointMinStyle->addItem(tr("线形"));
    //pointMinStyle->addItem(tr("数字"));

    gridLayout = new QGridLayout(this);
    gridLayout -> addWidget(pointRadiusLabel, 0, 0);
    gridLayout -> addWidget(pointStyle, 0, 1);
    gridLayout -> addWidget(pointRadiusEdit, 0, 2);
    gridLayout -> addWidget(pointColorCombo, 0, 3);

    gridLayout -> addWidget(point369RadiusLabel, 1, 0);
    gridLayout -> addWidget(point369Style, 1, 1);
    gridLayout -> addWidget(point369RadiusEdit, 1, 2);
    gridLayout -> addWidget(point369ColorCombo, 1, 3);

    gridLayout -> addWidget(pointMinRadiusLabel, 2, 0);
    gridLayout -> addWidget(pointMinStyle, 2, 1);
    gridLayout -> addWidget(pointMinRadiusEdit, 2, 2);
    gridLayout -> addWidget(pointMinColorCombo, 2, 3);

    gridLayout -> addWidget(hourWidthLabel, 0, 4);
    gridLayout -> addWidget(hourWidthEdit, 0, 5);
    gridLayout -> addWidget(hourColorCombo, 0, 6);

    gridLayout -> addWidget(minWidthLabel, 1, 4);
    gridLayout -> addWidget(minWidthEdit, 1, 5);
    gridLayout -> addWidget(minColorCombo, 1, 6);

    gridLayout -> addWidget(secWidthLabel, 2, 4);
    gridLayout -> addWidget(secWidthEdit, 2, 5);
    gridLayout -> addWidget(secColorCombo, 2, 6);
    editGroup -> setLayout(gridLayout);

    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(editGroup);
    hLayout->addLayout(vLayout);

    timeDiffEdit = new CtimeDiffEdit(this);
    simpleTextEdit = new CsimpleTextEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(timeDiffEdit);
    vLayout ->addWidget(simpleTextEdit);
    //vLayout->addStretch();
    hLayout->addLayout(vLayout);



    //vLayout = new QVBoxLayout(this);
    //vLayout ->addWidget(timeGroup);
    //hLayout->addLayout(vLayout);
    timeGroup = new QGroupBox(tr("日期星期"),this);
    dateEdit = new CdateEdit(this);
    weekEdit = new CweekEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(dateEdit);
    vLayout->addWidget(weekEdit);
    vLayout->addStretch();
    timeGroup->setLayout(vLayout);

    posiEdit = new CposiEdit(this);
    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(timeGroup);
    vLayout ->addWidget(posiEdit);
    hLayout->addLayout(vLayout);
    //vLayout->addStretch();

    showModeEdit = new CshowModeEdit(this);

    vLayout = new QVBoxLayout(this);
    vLayout ->addWidget(showModeEdit);
    //vLayout->addStretch();
    hLayout->addLayout(vLayout);

    hLayout ->addStretch(10);
    setLayout(hLayout);

    connect(pointRadiusEdit, SIGNAL(valueChanged(int)), this, SIGNAL(edited()));
    connect(point369RadiusEdit, SIGNAL(valueChanged(int)), this, SIGNAL(edited()));
    connect(pointMinRadiusEdit, SIGNAL(valueChanged(int)), this, SIGNAL(edited()));

    connect(hourWidthEdit, SIGNAL(valueChanged(int)), this, SIGNAL(edited()));
    connect(minWidthEdit, SIGNAL(valueChanged(int)), this, SIGNAL(edited()));
    connect(secWidthEdit, SIGNAL(valueChanged(int)), this, SIGNAL(edited()));

    connect(pointColorCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));
    connect(point369ColorCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));
    connect(pointMinColorCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));

    connect(hourColorCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));
    connect(minColorCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));
    connect(secColorCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));

    //connect(secColorCombo, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));

    //connect(nameEdit, SIGNAL(edited()), this, SIGNAL(edited()));
    connect(timeDiffEdit, SIGNAL(edited()), this, SIGNAL(edited()));
    connect(simpleTextEdit, SIGNAL(edited()), this, SIGNAL(edited()));
    connect(dateEdit, SIGNAL(edited()), this, SIGNAL(edited()));
    connect(weekEdit, SIGNAL(edited()), this, SIGNAL(edited()));

    connect(pointStyle, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));
    connect(point369Style, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));
    connect(pointMinStyle, SIGNAL(currentIndexChanged(int)), this, SIGNAL(edited()));

    connect(this, SIGNAL(edited()), this, SLOT(propertyEdited()));

    connect(posiEdit->left, SIGNAL(clicked()), this, SLOT(leftEdit()));
    connect(posiEdit->right, SIGNAL(clicked()), this, SLOT(rightEdit()));
    connect(posiEdit->up, SIGNAL(clicked()), this, SLOT(upEdit()));
    connect(posiEdit->down, SIGNAL(clicked()), this, SLOT(downEdit()));
    connect(posiEdit->def, SIGNAL(clicked()), this, SLOT(defEdit()));
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
        tmp = pointRadiusEdit->value();
        //qDebug("get pointRadius = %d", tmp);

        settings.setValue("pointRadius", pointRadiusEdit->value());   //整点半径
        settings.setValue("point369Radius", point369RadiusEdit->value()); //369点半径
        settings.setValue("pointMinRadius", pointMinRadiusEdit->value()); //369点半径

        settings.setValue("hourWidth", hourWidthEdit->value());//时钟宽度
        settings.setValue("minWidth", minWidthEdit->value()); //分钟宽度
        settings.setValue("secWidth", secWidthEdit->value()); //分钟宽度

        settings.setValue("pointColor", pointColorCombo->currentIndex()); //整点颜色
        settings.setValue("point369Color", point369ColorCombo->currentIndex()); //369点颜色
        settings.setValue("pointMinColor", pointMinColorCombo->currentIndex()); //369点颜色

        settings.setValue("pointStyle", pointStyle->currentIndex()); //整点颜色
        settings.setValue("point369Style", point369Style->currentIndex()); //369点颜色
        settings.setValue("pointMinStyle", pointMinStyle->currentIndex()); //369点颜色

        settings.setValue("hourColor", hourColorCombo->currentIndex()); //时钟颜色
        settings.setValue("minColor", minColorCombo->currentIndex()); //分钟颜色
        settings.setValue("secColor", secColorCombo->currentIndex()); //秒钟颜色
    }
    else
        ASSERT_FAILED();

    settings.endGroup();

    if(type == CLOCK_PROPERTY)
    {
      nameEdit->getSettingsFromWidget(str);
      timeDiffEdit->getSettingsFromWidget(str);
      simpleTextEdit->getSettingsFromWidget(str);
      dateEdit->getSettingsFromWidget(str);
      weekEdit->getSettingsFromWidget(str);
    }
}

//刷新显示区域
void updateClockShowArea(CshowArea *area)
{
    //CshowArea *area;
    QString str;
    QTreeWidgetItem *item;

    if(area != (CshowArea *)0) //
    {
        item = area->fileItem;
        str = item->data(0,Qt::UserRole).toString();

        getClockParaFromSettings(str,area->filePara);
        area->imageBk = getLineTextImage(str);
        area->updateFlag = true;
        //qDebug("file_para flag = %d", area->filePara.Temp_Para.Flag);
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

    //qDebug("propertyEdited");
    area = w->screenArea->getFocusArea(); //当前焦点分区

    if(area != (CshowArea *)0) //
    {
        //当前选中的item
        item = area->fileItem;//w->progManage->treeWidget->currentItem();////// //w->progManage->treeWidget->currentItem();
        if(item != (QTreeWidgetItem *)0)
        {
            QString str = item->data(0,Qt::UserRole).toString();
            getSettingsFromWidget(str);
            updateClockShowArea(area);

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

    tmp = settings.value("pointMinRadius").toInt(); //分点半径
    para.Clock_Para.Min_Point_Radius = (unsigned char)tmp;
//
    tmp = settings.value("pointStyle").toInt(); //整点式样
    para.Clock_Para.Hour_Point_Style = (unsigned char)tmp;

    tmp = settings.value("point369Style").toInt(); //369点式样
    para.Clock_Para.Hour369_Point_Style = (unsigned char)tmp;

    tmp = settings.value("pointMinStyle").toInt(); //分点式样
    para.Clock_Para.Min_Point_Style = (unsigned char)tmp;
  //
    tmp = settings.value("hourWidth").toInt(); //时钟宽度
    para.Clock_Para.Hour_Line_Width = (unsigned char)tmp;

    tmp = settings.value("minWidth").toInt(); //分钟宽度
    para.Clock_Para.Min_Line_Width = (unsigned char)tmp;

    tmp = settings.value("secWidth").toInt(); //秒钟宽度
    para.Clock_Para.Sec_Line_Width = (unsigned char)tmp;

    tmp = settings.value("point369Color").toInt(); //369点颜色
    para.Clock_Para.Hour369_Point_Color = 0;
    SET_BIT(para.Clock_Para.Hour369_Point_Color, tmp);
    //qDebug("point369color = %d", para.Clock_Para.Hour369_Point_Color);

    tmp = settings.value("pointColor").toInt(); //整点颜色
    para.Clock_Para.Hour_Point_Color = 0;
    SET_BIT(para.Clock_Para.Hour_Point_Color, tmp);
    //qDebug("pointColor = %d", para.Clock_Para.Hour_Point_Color);

    tmp = settings.value("pointMinColor").toInt(); //分点颜色
    para.Clock_Para.Min_Point_Color = 0;
    SET_BIT(para.Clock_Para.Min_Point_Color, tmp);
    //qDebug("pointMinColor = %d", para.Clock_Para.Min_Point_Color);

    tmp = settings.value("hourColor").toInt(); //小时颜色
    para.Clock_Para.Hour_Line_Color = 0;
    SET_BIT(para.Clock_Para.Hour_Line_Color, tmp);
    //qDebug("hourColor = %d", para.Clock_Para.Hour_Line_Color);

    tmp = settings.value("minColor").toInt(); //分钟颜色
    para.Clock_Para.Min_Line_Color = 0;
    SET_BIT(para.Clock_Para.Min_Line_Color, tmp);
    //qDebug("minColor = %d", para.Clock_Para.Min_Line_Color);

    tmp = settings.value("secColor").toInt(); //秒钟颜色
    para.Clock_Para.Sec_Line_Color = 0;
    SET_BIT(para.Clock_Para.Sec_Line_Color, tmp);
    //qDebug("secColor = %d", para.Clock_Para.Sec_Line_Color);

    settings.beginGroup("dateEdit");
    tmp = settings.value("checked").toBool();
    if(tmp EQ 0)
        para.Clock_Para.Date_Type = 0;
    else
    {
        tmp = settings.value("type").toInt();
        para.Clock_Para.Date_Type = tmp + 1;
    }

    tmp = settings.value("size").toInt();
    para.Clock_Para.Date_Font = tmp;
    tmp = settings.value("color").toInt();
    para.Clock_Para.Date_Color = 0;
    SET_BIT(para.Clock_Para.Date_Color, tmp);
    settings.endGroup();

    settings.beginGroup("weekEdit");
    tmp = settings.value("checked").toBool();
    if(tmp EQ 0)
        para.Clock_Para.Week_Type = 0;
    else
    {
        tmp = settings.value("type").toInt();
        para.Clock_Para.Week_Type = tmp + 1;
    }
    tmp = settings.value("size").toInt();
    para.Clock_Para.Week_Font = tmp;
    tmp = settings.value("color").toInt();
    para.Clock_Para.Week_Color = 0;
    SET_BIT(para.Clock_Para.Week_Color, tmp);
    settings.endGroup();

    tmp = settings.value("textX").toInt();
    para.Clock_Para.Text_X = tmp;

    tmp = settings.value("textY").toInt();
    para.Clock_Para.Text_Y = tmp;

    tmp = settings.value("dateX").toInt();
    para.Clock_Para.Date_X = tmp;

    tmp = settings.value("dateY").toInt();
    para.Clock_Para.Date_Y = tmp;

    tmp = settings.value("weekX").toInt();
    para.Clock_Para.Week_X = tmp;

    tmp = settings.value("weekY").toInt();
    para.Clock_Para.Week_Y = tmp;

/*
    settings.setValue("fontIndex", fontCombo->currentIndex());
    settings.setValue("fontSizeIndex", fontSizeCombo->currentIndex());
    settings.setValue("fontName", fontCombo->currentText());
    settings.setValue("fontSize", fontSizeCombo->currentvalue());

    settings.setValue("color", colorCombo->currentIndex());
    settings.setValue("bText", bButton->isChecked());
    settings.setValue("uText", uButton->isChecked());
    settings.setValue("iText", iButton->isChecked());
    settings.setValue("text", lineEdit->text());

    para.Clock_Para.Text_Color = settings.value("color").toInt();
    para.Clock_Para.Text_Color = settings.value("color").toInt();

    tmp = settings.value("fontSizeIndex").toInt();
    tmp = settings.value("fontName").toString();
    */
    //settings.beginGroup(str);
    settings.beginGroup("timeDiff");
    para.Clock_Para.Diff_Flag = settings.value("diffFlag").toInt();
    para.Clock_Para.Hour_Diff = settings.value("hour").toInt();
    para.Clock_Para.Min_Diff = settings.value("min").toInt();
    settings.endGroup();
    settings.endGroup();

    getShowModeParaFromSettings(str, para);
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
    int setFlag = settings.value("setFlag").toBool();
    if(setFlag EQ 0)
    {
      settings.setValue("pointRadius", 3);   //整点半径
      settings.setValue("point369Radius", 3); //369点半径
      settings.setValue("pointMinRadius", 3); //369点半径

      settings.setValue("hourWidth", 8);//时钟宽度
      settings.setValue("minWidth", 5); //分钟宽度
      settings.setValue("secWidth", 3); //秒钟宽度

      settings.setValue("pointColor", RED_INDEX); //整点颜色
      settings.setValue("point369Color", RED_INDEX); //369点颜色
      settings.setValue("pointMinColor", RED_INDEX); //369点颜色

      settings.setValue("hourColor", RED_INDEX); //时钟颜色
      settings.setValue("minColor", RED_INDEX); //分钟颜色
      settings.setValue("secColor", RED_INDEX); //秒钟颜色

      settings.setValue("textX", 50); //固定文本中心在X上的位置
      settings.setValue("textY", 30); //固定文本中心在Y上的位置
      settings.setValue("dateX", 50);
      settings.setValue("dateY", 70);
      settings.setValue("weekX", 50);
      settings.setValue("weekY", 85);

      settings.setValue("setFlag", 1);
   }

    pointRadiusEdit->setValue((settings.value("pointRadius").toInt()));
    point369RadiusEdit->setValue((settings.value("point369Radius").toInt()));
    pointMinRadiusEdit->setValue((settings.value("pointMinRadius").toInt()));


    hourWidthEdit->setValue((settings.value("hourWidth").toInt()));
    minWidthEdit->setValue((settings.value("minWidth").toInt()));
    secWidthEdit->setValue((settings.value("secWidth").toInt()));

    pointColorCombo->setCurrentIndex(settings.value("pointColor").toInt());
    point369ColorCombo->setCurrentIndex(settings.value("point369Color").toInt());
    pointMinColorCombo->setCurrentIndex(settings.value("pointMinColor").toInt());

    pointStyle->setCurrentIndex(settings.value("pointStyle").toInt());
    point369Style->setCurrentIndex(settings.value("point369Style").toInt());
    pointMinStyle->setCurrentIndex(settings.value("pointMinStyle").toInt());

    hourColorCombo->setCurrentIndex(settings.value("hourColor").toInt());
    minColorCombo->setCurrentIndex(settings.value("minColor").toInt());
    secColorCombo->setCurrentIndex(settings.value("secColor").toInt());

    settings.endGroup();

    nameEdit->setSettingsToWidget(str);
    timeDiffEdit->setSettingsToWidget(str);
    simpleTextEdit->setSettingsToWidget(str);
    dateEdit->setSettingsToWidget(str);
    weekEdit->setSettingsToWidget(str);

    connect(this, SIGNAL(edited()), this, SLOT(propertyEdited()));
}

void CclockProperty::leftEdit()
{
    QString str,str1;
    int index,posi;

    index = posiEdit->item->currentIndex();
    if(index EQ 0) //固定文本左移
      str = QString("textX");//left = settings.value("textX").toInt();
    else if(index EQ 1)
      str = QString("dateX");//left = settings.value("dateX").toInt();
    else
      str = QString("weekX");
      //

    QTreeWidgetItem *item = w->progManage->treeWidget->currentItem();
    if(item != (QTreeWidgetItem *)0)
    {
        str1 = item->data(0,Qt::UserRole).toString();
        //qDebug("left : %s", (const char *)str1.toLocal8Bit());
        settings.beginGroup(str1);

        posi = settings.value(str).toInt();
        if(posi >= POSI_STEP)
            posi = posi - POSI_STEP;
        else
            posi = 0;

        settings.setValue(str,posi);
        settings.endGroup();

        propertyEdited();
   }
}

void CclockProperty::rightEdit()
{
    QString str,str1;
    int index,posi;

    index = posiEdit->item->currentIndex();
    if(index EQ 0) //固定文本左移
      str = QString("textX");//left = settings.value("textX").toInt();
    else if(index EQ 1)
      str = QString("dateX");//left = settings.value("dateX").toInt();
    else
      str = QString("weekX");
      //

    QTreeWidgetItem *item = w->progManage->treeWidget->currentItem();
    if(item != (QTreeWidgetItem *)0)
    {
        str1 = item->data(0,Qt::UserRole).toString();
        //qDebug("left : %s", (const char *)str1.toLocal8Bit());
        settings.beginGroup(str1);

        posi = settings.value(str).toInt();
        if(posi  + POSI_STEP <= 100)
            posi = posi + POSI_STEP;
        else
            posi = 100;

        settings.setValue(str,posi);
        settings.endGroup();

        propertyEdited();
   }
}

void CclockProperty::upEdit()
{
    QString str,str1;
    int index,posi;

    index = posiEdit->item->currentIndex();
    if(index EQ 0) //固定文本左移
      str = QString("textY");//left = settings.value("textX").toInt();
    else if(index EQ 1)
      str = QString("dateY");//left = settings.value("dateX").toInt();
    else
      str = QString("weekY");
      //

    QTreeWidgetItem *item = w->progManage->treeWidget->currentItem();
    if(item != (QTreeWidgetItem *)0)
    {
        str1 = item->data(0,Qt::UserRole).toString();
        //qDebug("left : %s", (const char *)str1.toLocal8Bit());
        settings.beginGroup(str1);

        posi = settings.value(str).toInt();
        if(posi >= POSI_STEP)
            posi = posi - POSI_STEP;
        else
            posi = 0;

        settings.setValue(str,posi);
        settings.endGroup();

        propertyEdited();
   }
}

void CclockProperty::downEdit()
{
    QString str,str1;
    int index,posi;

    index = posiEdit->item->currentIndex();
    if(index EQ 0) //固定文本左移
      str = QString("textY");//left = settings.value("textX").toInt();
    else if(index EQ 1)
      str = QString("dateY");//left = settings.value("dateX").toInt();
    else
      str = QString("weekY");
      //

    QTreeWidgetItem *item = w->progManage->treeWidget->currentItem();
    if(item != (QTreeWidgetItem *)0)
    {
        str1 = item->data(0,Qt::UserRole).toString();
        //qDebug("left : %s", (const char *)str1.toLocal8Bit());
        settings.beginGroup(str1);

        posi = settings.value(str).toInt();
        if(posi  + POSI_STEP <= 100)
            posi = posi + POSI_STEP;
        else
            posi = 100;

        settings.setValue(str,posi);
        settings.endGroup();

        propertyEdited();
   }
}

void CclockProperty::defEdit()
{
    QTreeWidgetItem *item = w->progManage->treeWidget->currentItem();
    if(item != (QTreeWidgetItem *)0)
    {
        QString str = item->data(0,Qt::UserRole).toString();
        //qDebug("left : %s", (const char *)str1.toLocal8Bit());
        settings.beginGroup(str);
        settings.setValue("textX", 50); //固定文本中心在X上的位置
        settings.setValue("textY", 30); //固定文本中心在Y上的位置
        settings.setValue("dateX", 50);
        settings.setValue("dateY", 70);
        settings.setValue("weekX", 50);
        settings.setValue("weekY", 85);
        settings.endGroup();

        propertyEdited();
    }
}
