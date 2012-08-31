#include "goodseditdialog.h"
#include <QtGui/QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtCore/QTextCodec>

GoodsEditDialog::GoodsEditDialog(QWidget *parent):QDialog(parent)
{
	setupUi(this);
	setWindowTitle(tr("添加商品"));
	setFixedSize(sizeHint());
	m_iGoodsId = -1;
}

GoodsEditDialog::GoodsEditDialog(QWidget *parent, const QSqlRecord &record):QDialog(parent)
{
	setupUi(this);
	setWindowTitle(tr("修改商品"));
	setFixedSize(sizeHint());
	m_iGoodsId = record.value("goodsid").toInt();

	comboBoxIsService->setCurrentIndex(record.value("isservices").toInt());
	lineEditGoodsNo->setText(record.value("goodsno").toString());
	lineEditGoodsName->setText(record.value("goodsname").toString());
	doubleSpinBoxSellPrice->setValue(record.value("sellprice").toDouble());
	doubleSpinBoxInPrice->setValue(record.value("inprice").toDouble());
	spinBoxGoodsNum->setValue(record.value("goodsnum").toInt());
	lineEditManufacturer->setText(record.value("manufacturer").toString());

	spinBoxGoodsNum->setEnabled(false);
}

GoodsEditDialog::~GoodsEditDialog()
{
}

void GoodsEditDialog::on_okButton_clicked()
{
	lineEditGoodsNo->setText(lineEditGoodsNo->text().trimmed());
	if (lineEditGoodsNo->text() == "")
	{
		QMessageBox::information(this, tr("信息"), tr("商品编号不能为空"), QMessageBox::Ok);
		lineEditGoodsNo->setFocus();
		return;
	}

	lineEditGoodsName->setText(lineEditGoodsName->text().trimmed());
	if (lineEditGoodsName->text() == "")
	{
		QMessageBox::information(this, tr("信息"), tr("商品名称不能为空"), QMessageBox::Ok);
		lineEditGoodsName->setFocus();
		return;
	}
	lineEditManufacturer->setText(lineEditManufacturer->text().trimmed());

	QSqlQuery query(QSqlDatabase::database());
	QString strSql = "SELECT goodsid FROM ct_goods WHERE goodsno LIKE '" + lineEditGoodsNo->text() + "' AND goodsid <> " + QString::number(m_iGoodsId);
	if (query.exec(strSql) && query.size() > 0)
	{
		QMessageBox::information(this, tr("信息"), tr("商品编号") + lineEditGoodsNo->text() + tr("已经存在"), QMessageBox::Ok);
		lineEditGoodsNo->setFocus();
		return;
	}

	if (m_iGoodsId < 0)
	{
		m_strSqlExec = QString("INSERT INTO ct_goods(goodsno, goodsname, inprice, sellprice, goodsnum, manufacturer, isservices) VALUES('%1', '%2', %3, %4, %5, '%6', %7)")
			.arg(lineEditGoodsNo->text())
			.arg(lineEditGoodsName->text())
			.arg(doubleSpinBoxInPrice->value())
			.arg(doubleSpinBoxSellPrice->value())
			.arg(spinBoxGoodsNum->value())
			.arg(lineEditManufacturer->text())
			.arg(comboBoxIsService->currentIndex());
	}
	else
	{
		m_strSqlExec = QString("UPDATE ct_goods SET goodsno = '%1', goodsname = '%2', inprice = %3, sellprice = %4, manufacturer = '%5', isservices = %6 WHERE goodsid = %7")
			.arg(lineEditGoodsNo->text())
			.arg(lineEditGoodsName->text()) 
			.arg(doubleSpinBoxInPrice->value())
			.arg(doubleSpinBoxSellPrice->value())
			.arg(lineEditManufacturer->text())
			.arg(comboBoxIsService->currentIndex())
			.arg(m_iGoodsId);
	}
	accept();
}

QString GoodsEditDialog::strSqlExec()
{
	return m_strSqlExec;
}