#ifndef GOODSEDITDIALOG_H
#define GOODSEDITDIALOG_H

#include <QtGui/QDialog>
#include <QtSql/QSqlRecord>
#include "ui_goodseditdialog.h"

class GoodsEditDialog : public QDialog, public Ui::GoodsEditDialog
{
	Q_OBJECT
public:
	GoodsEditDialog(QWidget *parent);
	GoodsEditDialog(QWidget *parent, const QSqlRecord &record);
	~GoodsEditDialog();
	QString strSqlExec();
public slots:
	void on_okButton_clicked();
private:
	int m_iGoodsId;
	QString m_strSqlExec;
};

#endif
