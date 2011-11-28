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
#include "showArea.h"
#include "tablePropertyEdit.h"
//#include "includes.h"
#include "..\Stm32\usr\app\led_show.h"
#include "..\Stm32\usr\app\Pic_show.h"
#include "mainwindow.h"

extern MainWindow *w;
extern QSettings settings;

CtablePropertyEdit::CtablePropertyEdit(QWidget *parent)
{
  QGroupBox *sizeGroup = new QGroupBox(tr("大小"), this);
  QGroupBox *alignGroup =new  QGroupBox(tr("位置"), this);
  QGroupBox *borderMarginGroup = new QGroupBox(tr("边框"), this);

  QVBoxLayout *mainVLayout = new QVBoxLayout(this);

  QVBoxLayout *vLayout = new QVBoxLayout(borderMarginGroup);

  QHBoxLayout *hLayout = new QHBoxLayout(sizeGroup);
  QLabel *rowsLabel = new QLabel(tr("行数"), this);
  QLabel *colsLabel = new QLabel(tr("列数"), this);
  QLabel *widthLabel = new QLabel(tr("宽度"), this);
  //QLabel *pixLabel = QLabel(tr("像素"), this);

  rowsEdit = new QSpinBox(this);
  colsEdit = new QSpinBox(this);
  widthEdit = new QSpinBox(this);

  hLayout->addWidget(rowsLabel);
  hLayout->addWidget(rowsEdit);
  hLayout->addWidget(colsLabel);
  hLayout->addWidget(colsEdit);
  hLayout->addWidget(widthLabel);
  hLayout->addWidget(widthEdit);
  //hLayout->addWidget(pixLabel);
  sizeGroup->setLayout(hLayout);

  mainVLayout->addWidget(sizeGroup);

  hLayout = new QHBoxLayout(alignGroup);
  alignCombo = new QComboBox(this);
  alignCombo->addItem(tr("左边"));
  alignCombo->addItem(tr("中央"));
  alignCombo->addItem(tr("右边"));

  hLayout->addWidget(alignCombo);
  hLayout->addStretch(10);
  alignGroup->setLayout(hLayout);

  mainVLayout->addWidget(alignGroup);

  hLayout = new QHBoxLayout(borderMarginGroup);
  QLabel *borderWidthLabel = new QLabel(tr("宽度"), this);
  QLabel *borderColorLabel = new QLabel(tr("颜色"), this);
  QLabel *borderStyleLabel = new QLabel(tr("式样"), this);

  borderWidth = new QSpinBox(this);
  borderColor = new CcolorCombo(this);
  borderStyle = new QComboBox(this);

  borderStyle->addItem("None");
  borderStyle->addItem("Dotted");
  borderStyle->addItem("Dashed");
  borderStyle->addItem("Solid");
  borderStyle->addItem("Double");
  borderStyle->addItem("DotDash");
  borderStyle->addItem("DotDotDash");
  borderStyle->addItem("Groove");
  borderStyle->addItem("Ridge");
  borderStyle->addItem("Inset");
  borderStyle->addItem("Outset");

  hLayout->addWidget(borderWidthLabel);
  hLayout->addWidget(borderWidth);
  hLayout->addWidget(borderColorLabel);
  hLayout->addWidget(borderColor);
  hLayout->addWidget(borderStyleLabel);
  hLayout->addWidget(borderStyle);
  vLayout->addLayout(hLayout);

  hLayout = new QHBoxLayout(borderMarginGroup);
  QLabel *marginBetweenCellsLabel = new QLabel(tr("外边距"), this);
  QLabel *marginInCellsLabel = new QLabel(tr("内边距"), this);

  marginBetweenCells = new QSpinBox(this);
  marginInCells = new QSpinBox(this);

  hLayout->addWidget(marginBetweenCellsLabel);
  hLayout->addWidget(marginBetweenCells);
  hLayout->addWidget(marginInCellsLabel);
  hLayout->addWidget(marginInCells);
  vLayout->addLayout(hLayout);
  borderMarginGroup->setLayout(vLayout);

  mainVLayout->addWidget(borderMarginGroup);

  hLayout = new QHBoxLayout(this);
  applyButton = new QPushButton(tr("应用"),this);
  okButton = new QPushButton(tr("确定"), this);
  cancelButton = new QPushButton(tr("取消"), this);
  hLayout->addWidget(applyButton);
  hLayout->addWidget(okButton);
  hLayout->addWidget(cancelButton);
  mainVLayout->addLayout(hLayout);

  this->setLayout(mainVLayout);

  this->setWindowTitle(tr("表格属性"));

  connect(applyButton, SIGNAL(clicked()), this, SLOT(apply()));
  connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
  connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}
//-------------------------------------------------
void CtablePropertyEdit::getTableFormat()
{
        // global table settings
        if (this->alignCombo->currentIndex() == 0) tFormat.setAlignment(Qt::AlignLeft);
        if (this->alignCombo->currentIndex() == 1) tFormat.setAlignment(Qt::AlignHCenter);
        if (this->alignCombo->currentIndex() == 2) tFormat.setAlignment(Qt::AlignRight);
           tFormat.setWidth( QTextLength(QTextLength::FixedLength, this->widthEdit->value()) );
        //if (ui.CBWidth->currentIndex() == 0) tFormat.setWidth( QTextLength(QTextLength::FixedLength,	 ui.SBWidth->value()) );
        //if (ui.CBWidth->currentIndex() == 1) tFormat.setWidth( QTextLength(QTextLength::PercentageLength,ui.SBWidth->value()) );
        /*
        size = ui.SBHeight->value();
        if (ui.CBHeight->currentIndex() == 0)	tFormat.setHeight( QTextLength(QTextLength::FixedLength, size) );
        if (ui.CBHeight->currentIndex() == 1)	tFormat.setHeight( QTextLength(QTextLength::PercentageLength, size) );
        */
        //tFormat.setBackground(colorTable);

        // border and margins settings
        tFormat.setBorder(this->borderWidth->value());//ui.SBBorder->value());
        tFormat.setBorderBrush(QBrush(this->borderColor->getColor()));//QBrush(colorBorder));
        tFormat.setBorderStyle( QTextFrameFormat::BorderStyle(this->borderStyle->currentIndex())); //ui.CBBorderStyle->currentIndex()
        tFormat.setCellSpacing(this->marginBetweenCells->value());
        tFormat.setCellPadding(this->marginInCells->value());
}

void CtablePropertyEdit::accept()
{
        getTableFormat();
        if (modeNewTable)
        {
                emit createTable(this->rowsEdit->value(), this->colsEdit->value(), tFormat);
        }
        else
        {
                emit updateTable(this->rowsEdit->value(), this->colsEdit->value(), tFormat);
        }
        QWidget::hide();  //close dialog
}

//-------------------------------------------------
void CtablePropertyEdit::reject()
{
        hide();  //close dialog
}

//-------------------------------------------------
void CtablePropertyEdit::apply()
{
        getTableFormat();
        emit updateTable(this->rowsEdit->value(), this->colsEdit->value(), tFormat);
}

//-------------------------------------------------
void CtablePropertyEdit::setProperties(int rows, int colums, QTextTableFormat tableFormat, bool newTable)
{
        rowsEdit->setValue(rows);
        colsEdit->setValue(colums);
        applyButton->setVisible(!newTable);
        modeNewTable = newTable;
        if (!newTable){
                tFormat = tableFormat;

                // global table settings
                //colorTable = tFormat.background().color();
                //ui.PBTableColor->setStyleSheet("background-color: " + colorTable.name() +";");

                if (tFormat.alignment() == Qt::AlignLeft)	this->alignCombo->setCurrentIndex(0);
                if (tFormat.alignment() == Qt::AlignHCenter)	this->alignCombo->setCurrentIndex(1);
                if (tFormat.alignment() == Qt::AlignRight)	this->alignCombo->setCurrentIndex(2);

                QTextLength tl = tFormat.width();
                //if (tl.type() == QTextLength::FixedLength) 		ui.CBWidth->setCurrentIndex(0);
                //if (tl.type() == QTextLength::PercentageLength)	ui.CBWidth->setCurrentIndex(1);
                widthEdit->setValue(tl.rawValue());
                /*
                *QTextLength tl = tFormat.height();
                if (tl.type() == QTextLength::FixedLength) 		ui.CBHeight->setCurrentIndex(0);
                if (tl.type() == QTextLength::PercentageLength)	ui.CBHeight->setCurrentIndex(1);
                ui.SBHeight->setValue(tl.rawValue());*/

                // border and margins settings
                borderWidth->setValue(tFormat.border());
                colorBorder = tFormat.borderBrush().color();
                //ui.PBBorderColor->setStyleSheet("background-color: " + colorBorder.name() +";");
                this->borderColor->setColor(colorBorder);
                borderStyle->setCurrentIndex(tFormat.borderStyle());
                marginBetweenCells->setValue(tFormat.cellSpacing());
                marginInCells->setValue(tFormat.cellPadding());
        }
        else
        {
            this->alignCombo->setCurrentIndex(0);

            //QTextLength tl = tFormat.width(50);
            //if (tl.type() == QTextLength::FixedLength) 		ui.CBWidth->setCurrentIndex(0);
            //if (tl.type() == QTextLength::PercentageLength)	ui.CBWidth->setCurrentIndex(1);
            widthEdit->setValue(50);
            /*
            *QTextLength tl = tFormat.height();
            if (tl.type() == QTextLength::FixedLength) 		ui.CBHeight->setCurrentIndex(0);
            if (tl.type() == QTextLength::PercentageLength)	ui.CBHeight->setCurrentIndex(1);
            ui.SBHeight->setValue(tl.rawValue());*/

            // border and margins settings
            borderWidth->setValue(1);
            //colorBorder = tFormat.borderBrush().color();
            //ui.PBBorderColor->setStyleSheet("background-color: " + colorBorder.name() +";");
            this->borderColor->setColor(QColor(Qt::red));
            borderStyle->setCurrentIndex(1);
            marginBetweenCells->setValue(1);
            marginInCells->setValue(1);


        }
}

CtablePropertyEdit::~CtablePropertyEdit()
{

}
