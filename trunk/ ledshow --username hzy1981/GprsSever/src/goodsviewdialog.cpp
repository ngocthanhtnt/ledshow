/*
 * =====================================================================================
 * 
 *        Filename:  goodsviewdialog.cpp
 * 
 *     Description:  View the Goods Information
 * 
 *         Version:  1.0
 *         Created:  2006-6-25 10:16:17 中国标准时间
 *        Revision:  none
 *        Compiler:  gcc
 * 
 *          Author:  Bai_Jianping (XChinux), XChinux@163.com
 *         Company:  
 * 
 * =====================================================================================
 */

#include "goodsviewdialog.h"

GoodsViewDialog::GoodsViewDialog(QWidget *parent, const QSqlRecord &record):QDialog(parent)
{
	setupUi(this);
	setFixedSize(sizeHint());
	labelIsServices->setText(record.value("isservices").toInt() == 1 ? tr("服务类") : tr("产品类"));
	labelGoodsNo->setText(record.value("goodsno").toString());
	labelGoodsName->setText(record.value("goodsname").toString());
	labelSellPrice->setText("￥" + QString::number(record.value("sellprice").toDouble(), 'f', 2));
	labelInPrice->setText("￥" + QString::number(record.value("inprice").toDouble(), 'f', 2));
	labelGoodsNum->setText(QString::number(record.value("totalgoodsnum").toInt()));
	labelManufacturer->setText(record.value("manufacturer").toString());
}

GoodsViewDialog::~GoodsViewDialog()
{
}
