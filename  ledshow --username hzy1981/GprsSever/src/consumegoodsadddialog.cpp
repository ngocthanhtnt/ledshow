/*
 * =====================================================================================
 * 
 *        Filename:  consumegoodsadddialog.cpp
 * 
 *     Description:  
 * 
 *         Version:  1.0
 *         Created:  2006-6-25 16:55:15 中国标准时间
 *        Revision:  none
 *        Compiler:  gcc
 * 
 *          Author:  Bai_Jianping (XChinux), XChinux@163.com
 *         Company:  
 * 
 * =====================================================================================
 */

#include "consumegoodsadddialog.h"
#include <QtGui/QMessageBox>


ConsumeGoodsAddDialog::ConsumeGoodsAddDialog(QWidget *parent, int iConsumeId, int iCustomerId):QDialog(parent)
{
	setupUi(this);
	m_iConsumeId = iConsumeId;
	m_iCustomerId = iCustomerId;
	db = QSqlDatabase::database();
	query.exec("SELECT goodsname, goodsno, isservices, inprice, sellprice, goodsnum, manufacturer, goodsid FROM ct_goods");
	while (query.next())
	{
		comboBoxGoodsName->addItem(query.value(0).toString());
	}

}

ConsumeGoodsAddDialog::~ConsumeGoodsAddDialog()
{
}

int ConsumeGoodsAddDialog::consumeId()
{
	return m_iConsumeId;
}

int ConsumeGoodsAddDialog::customerId()
{
	return m_iCustomerId;
}

void ConsumeGoodsAddDialog::on_comboBoxGoodsName_currentIndexChanged(int index)
{
	if (query.seek(index))
	{
		labelGoodsNo->setText(query.value(1).toString());
		labelIsServices->setText(query.value(2).toInt() == 1 ? tr("服务类") : tr("商品类"));
		labelInPrice->setText("￥" + QString::number(query.value(3).toDouble(), 'f', 2));
		labelSellPrice->setText("￥" + QString::number(query.value(4).toDouble(), 'f', 2));
		labelGoodsNum->setText(QString::number(query.value(5).toInt()));
		labelManufacturer->setText(query.value(6).toString());
		spinBoxConsumeGoodsNum->setMaximum(query.value(5).toInt());
		spinBoxConsumeGoodsNum->setValue(0);
		m_iGoodsId = query.value(7).toInt();
		m_fInPrice = query.value(3).toDouble();
		m_fSellPrice = query.value(4).toDouble();
	}
}

void ConsumeGoodsAddDialog::on_spinBoxConsumeGoodsNum_valueChanged(int value)
{
	doubleSpinBoxConsumeGoodsPrice->setValue(value*m_fSellPrice);
}

void ConsumeGoodsAddDialog::on_okButton_clicked()
{
	if (spinBoxConsumeGoodsNum->value() < 1)
	{
		return;
	}
	QSqlQuery queryTemp;
	queryTemp.exec(QString("SELECT COUNT(*) AS cnt FROM ct_consumedetail WHERE consumeid = %1 AND goodsid = %2").arg(m_iConsumeId).arg(m_iGoodsId));
	queryTemp.next();
	if (queryTemp.value(0).toInt() > 0)
	{
		QMessageBox::information(this, tr("信息"), tr("此商品已经存在了，请先删除此商品消费再增加"), QMessageBox::Ok);
		return;
	}

	db.exec(QString("INSERT INTO ct_consumedetail(consumeid, goodsid, goodsnum, goodsprice, remark) VALUES(%1, %2, %3, %4, '%5')").arg(m_iConsumeId).arg(m_iGoodsId).arg(spinBoxConsumeGoodsNum->value()).arg(doubleSpinBoxConsumeGoodsPrice->value()).arg(lineEditConsumeRemark->text()));
	db.exec(QString("UPDATE ct_consume SET consumeprice = consumeprice + %1 WHERE consumeid = %2").arg(doubleSpinBoxConsumeGoodsPrice->value()).arg(m_iConsumeId));
	db.exec(QString("UPDATE ct_customer SET consumeprice = consumeprice + %1 WHERE customerid = %2").arg(doubleSpinBoxConsumeGoodsPrice->value()).arg(m_iCustomerId));
	db.exec(QString("UPDATE ct_goods SET goodsnum = goodsnum - %1 WHERE goodsid = %2").arg(spinBoxConsumeGoodsNum->value()).arg(m_iGoodsId));
	accept();
}