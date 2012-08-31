#include "goodsinoutdialog.h"

GoodsInoutDialog::GoodsInoutDialog(QWidget *parent, const QSqlRecord &record):QDialog(parent)
{
	setupUi(this);
	setFixedSize(sizeHint());

	labelIsServices->setText(QString("<font color=blue>%1</font>").arg(record.value("isservices").toInt() == 1 ? "服务类" : "产品类"));
	labelGoodsNo->setText(QString("<font color=blue>%1</font>").arg(record.value("goodsno").toString()));
	labelGoodsName->setText(QString("<font color=blue>%1</font>").arg(record.value("goodsname").toString()));
	labelSellPrice->setText(QString("<font color=blue>￥%1</font>").arg(record.value("sellprice").toDouble(), 0, 'f', 2));
	labelInPrice->setText(QString("<font color=blue>￥%1</font>").arg(record.value("inprice").toDouble(), 0, 'f', 2));
	labelGoodsNum->setText(QString("<font color=blue>%1</font>").arg(record.value("goodsnum").toInt()));
	labelManufacturer->setText(QString("<font color=blue>%1</font>").arg(record.value("manufacturer").toString()));

	m_iGoodsId = record.value("goodsid").toInt();
	m_iGoodsNum = record.value("goodsnum").toInt();
}

GoodsInoutDialog::~GoodsInoutDialog()
{
}

QString GoodsInoutDialog::strSqlExec()
{
	return m_strSqlExec;
}

void GoodsInoutDialog::on_radioButtonOut_toggled(bool checked)
{
	labelGoodsInout->setText(checked ? "商品退货" : "商品进货");
	spinBoxGoodsNum->setMaximum(m_iGoodsNum);
}

void GoodsInoutDialog::on_radioButtonIn_toggled(bool checked)
{
	labelGoodsInout->setText(checked ? "商品进货" : "商品退货");
	spinBoxGoodsNum->setMaximum(99999);
}

void GoodsInoutDialog::on_okButton_clicked()
{
	if (radioButtonIn->isChecked())
	{
		m_strSqlExec = QString("UPDATE ct_goods SET goodsnum = goodsnum + %1 WHERE goodsid = %2").arg(spinBoxGoodsNum->value()).arg(m_iGoodsId);
	}
	else
	{
		m_strSqlExec = QString("UPDATE ct_goods SET goodsnum = goodsnum - %1 WHERE goodsid = %2").arg(spinBoxGoodsNum->value()).arg(m_iGoodsId);
	}
	accept();
}
