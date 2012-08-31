/*
 * =====================================================================================
 * 
 *       Filename:  consumegoodsadddialog.h
 * 
 *    Description:  
 * 
 *        Version:  1.0
 *        Created:  2006-6-25 16:52:59 中国标准时间
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  Bai_Jianping (XChinux), XChinux@163.com
 *        Company:  
 * 
 * =====================================================================================
 */

#ifndef CONSUMEGOODSADDDIALOG_H
#define CONSUMEGOODSADDDIALOG_H
#include <QtGui/QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "ui_consumegoodsadddialog.h"

class ConsumeGoodsAddDialog: public QDialog, public Ui::ConsumeGoodsAddDialog
{
	Q_OBJECT
public:
	ConsumeGoodsAddDialog(QWidget *parent, int iConsumeId, int iCustomerId);
	~ConsumeGoodsAddDialog();
	int consumeId();
	int customerId();
private slots:
	void on_comboBoxGoodsName_currentIndexChanged(int index);
	void on_spinBoxConsumeGoodsNum_valueChanged(int value);
	void on_okButton_clicked();
private:
	QSqlDatabase db;
	QSqlQuery query;
	int	m_iConsumeId;
	int m_iGoodsId;
	int m_iCustomerId;
	double m_fInPrice;
	double m_fSellPrice;
};

#endif
