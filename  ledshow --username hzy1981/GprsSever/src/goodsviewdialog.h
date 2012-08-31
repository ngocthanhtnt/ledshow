/*
 * =====================================================================================
 * 
 *       Filename:  goodsviewdialog.h
 * 
 *    Description:  View thd Selected Goods Information
 * 
 *        Version:  1.0
 *        Created:  2006-6-25 10:11:53 中国标准时间
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  Bai_Jianping (XChinux), XChinux@163.com
 *        Company:  
 * 
 * =====================================================================================
 */

#ifndef GOODSVIEWDIALOG_H
#define GOODSVIEWDIALOG_H

#include <QtGui/QDialog>
#include <QtSql/QSqlRecord>
#include "ui_goodsviewdialog.h"

class GoodsViewDialog : public QDialog, public Ui::GoodsViewDialog
{
	Q_OBJECT
public:
	GoodsViewDialog(QWidget *parent, const QSqlRecord &record);
	~GoodsViewDialog();
};

#endif
