#include <QApplication>
#include "simpleTextEdit.h"
#include <QGridLayout>
#include <QFontDatabase>
#include <QFontComboBox>
#include <QFontMetrics>
#include <QPainter>
#include <QSize>
#include <QRectF>
#include <QTextEdit>
#include <QSettings>
#include "..\led_show.h"

extern QSettings settings;
//简单文本编辑框
CsimpleTextEdit::CsimpleTextEdit(QWidget *parent):QWidget(parent)
{
    QHBoxLayout *hLayout;
    //QVBoxLayout *vLayout;
  QGridLayout *gridLayout;
  QFontDatabase db;


  //vLayout = new QVBoxLayout(this);
  gridLayout = new QGridLayout(this);
  fontLabel = new QLabel(tr("字体"), this);
  fontSizeLabel = new QLabel(tr("大小"), this);
  colorLabel = new QLabel(tr("颜色"), this);

  fontCombo = new QFontComboBox(this);
  fontSizeCombo = new QComboBox(this);
  //fontSizeCombo->setobjectName("comboSize");
  fontSizeCombo->setEditable(true);

  foreach(int size, db.standardSizes())
    fontSizeCombo->addItem(QString::number(size));
    //connect(comboSize, SIGNAL(activated(const QString &)),
    //this, SLOT(textSize(const QString &)));
  fontSizeCombo->setCurrentIndex(fontSizeCombo->findText(QString::number(QApplication::font().pointSize())));

  colorCombo = new CcolorCombo(this);
//-------------


  //---------------
  bButton = new QPushButton(tr("粗体"),this);
  iButton = new QPushButton(tr("斜体"),this);
  uButton = new QPushButton(tr("下划"), this);
  //oButton = new QPushButton(tr("打开"),this);

  bButton->setCheckable(true);
  iButton->setCheckable(true);
  uButton->setCheckable(true);
  //oButton->setCheckable(true);

  lineEdit = new QLineEdit(this);

  hLayout = new QHBoxLayout(this);
  hLayout -> addWidget(fontLabel);
  hLayout -> addWidget(fontCombo);
  hLayout -> addWidget(fontSizeLabel);
  hLayout -> addWidget(fontSizeCombo);
  hLayout -> addWidget(colorLabel);
  hLayout -> addWidget(colorCombo);
  gridLayout->addLayout(hLayout, 0, 0);

  hLayout = new QHBoxLayout(this);
  hLayout -> addWidget(bButton);
  hLayout -> addWidget(iButton);
  hLayout -> addWidget(uButton);
  //hLayout -> addWidget(oButton);
  gridLayout->addLayout(hLayout, 1, 0);

  hLayout = new QHBoxLayout(this);
  hLayout -> addWidget(lineEdit);
  gridLayout->addLayout(hLayout, 2, 0);

  setLayout(gridLayout);

  //所有的消息统一到一个消息
  connect(fontCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
  connect(fontSizeCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
  connect(colorCombo, SIGNAL(currentIndexChanged(int)),this,SIGNAL(edited()));
  connect(bButton, SIGNAL(clicked(int)),this,SIGNAL(edited()));
  connect(iButton, SIGNAL(clicked(int)),this,SIGNAL(edited()));
  connect(uButton, SIGNAL(clicked(int)),this,SIGNAL(edited()));
  connect(lineEdit, SIGNAL(editingFinished(int)),this,SIGNAL(edited()));
}

/*
QFont font("times", 24);
QFontMetrics fm(font);
int pixelsWide = fm.width("What's the width of this text?");
int pixelsHigh = fm.height();
 */
//获取文本的像素
QImage getTextImage(QString str)
{
    QString text;
    QPainter painter;
    //QFontComboBox fontComboBox;
    //QComboBox fontSizeComboBox;

    settings.beginGroup(str);

    text = settings.value("text").toString();

    QString fontName = settings.value("fontName").toString();
    //fontComboBox.setCurrentIndex(i);
    int fontSize = settings.value("fontSize").toInt();
    //fontSizeComboBox.setCurrentIndex(i);

    //QFont font(fontComboBox.currentText(), fontSizeComboBox.currentText().toInt());

    QFont font(fontName, fontSize);

    font.setStyleStrategy(QFont::NoAntialias);//关闭抗锯齿
    QFontMetrics fm(font);
    int width = fm.width(text);
    int height = fm.height();

    QImage image(width, height, QImage::Format_RGB32);

    painter.begin(&image);
    painter.fillRect(0,0,width,height,Qt::black);

    int color = settings.value("color").toInt();
    if(color == 0x00)
        painter.setPen(QColor(Qt::red));
    else if(color == 0x01)
        painter.setPen(QColor(Qt::green));
    else
        painter.setPen(QColor(Qt::yellow));

    painter.setFont(font);

    //QString str = lineEdit->text();//edit.document()->toPlainText();//lineEdit->text();//document()->toPlainText ();
    painter.drawText(0,0,width,height,Qt::AlignLeft, text);
    painter.end();
/*
    if(image.save("c:\\a.png")== false)
    {
      qDebug("save image failed");
    }
*/
    settings.endGroup();
    return image;

}

//
QSize getTextShowData(QImage image, S_Show_Data *pDst, INT16U x, INT16U y)
{
  //QImage image;
  QSize size;
  QColor red(Qt::red);
  QColor green(Qt::green);
  QColor yellow(Qt::yellow);
  QColor black(Qt::black);
  QRgb rgb;
  int i,j;

  //image = getTextImage(str);
  for(i = 0; i < image.width(); i ++)
      for(j = 0; j < image.height(); j ++)
      {
        rgb = image.pixel(i,j);
        if(rgb == red.rgb())
            Set_Area_Point_Data(pDst, 0, x + i, y + j, 0x01);
        else if(rgb == green.rgb())
            Set_Area_Point_Data(pDst, 0, x + i, y + j, 0x02);
        else if(rgb == yellow.rgb())
            Set_Area_Point_Data(pDst, 0, x + i, y + j, 0x04);
        else if(rgb == black.rgb())
            Set_Area_Point_Data(pDst, 0, x + i, y + j, 0x00);
        else
            ASSERT_FAILED();
      }
  size.setWidth(image.width());
  size.setHeight(image.height());
  return size;
}

//从Widget上获取设置
void CsimpleTextEdit::getSettingsFromWidget(QString str)
{
   settings.beginGroup(str);
   settings.setValue("fontIndex", fontCombo->currentIndex());
   settings.setValue("fontSizeIndex", fontSizeCombo->currentIndex());
   settings.setValue("fontName", fontCombo->currentText());
   settings.setValue("fontSize", fontSizeCombo->currentText().toInt());

   settings.setValue("color", colorCombo->currentIndex());
   settings.setValue("bText", bButton->isChecked());
   settings.setValue("uText", uButton->isChecked());
   settings.setValue("iText", iButton->isChecked());
   settings.setValue("text", lineEdit->text());
   settings.endGroup();
}

void CsimpleTextEdit::setSettingsToWidget(QString str)
{
    settings.beginGroup(str);
    fontCombo->setCurrentIndex(settings.value("fontIndex").toInt());
    fontSizeCombo->setCurrentIndex(settings.value("fontSizeIndex").toInt());

    //fontCombo->setCurrentText(settings.value("font").toString());
    //fontSizeCombo->setCurrentText(settings.value("fontSize").toString());

    colorCombo->setCurrentIndex(settings.value("color").toInt());
    bButton->setChecked(settings.value("bText").toBool());
    uButton->setChecked(settings.value("uText").toBool());
    iButton->setChecked(settings.value("iText").toBool());
    lineEdit->setText(settings.value("text").toString());
    settings.endGroup();
}
/*
 bool QObject::connect ( const QObject * sender, const char * signal, const QObject * receiver, const char * method, Qt::ConnectionType type = Qt::AutoConnection )   [static]

void CsimpleTextEdit::edited()
{
  qDebug("simpleText edited!");
}
*/
CsimpleTextEdit::~CsimpleTextEdit()
{

}
