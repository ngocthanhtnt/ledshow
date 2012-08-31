#ifndef GOODSINOUTDIALOG_H
#define GOODSINOUTDIALOG_H

#include <QtGui/QDialog>
#include <QtSql/QSqlRecord>
#include "ui_goodsinoutdialog.h"

class GoodsInoutDialog : public QDialog, public Ui::GoodsInoutDialog
{
	Q_OBJECT
public:
	GoodsInoutDialog(QWidget *parent, const QSqlRecord &record);
	~GoodsInoutDialog();
	QString strSqlExec();
private slots:
	void on_radioButtonIn_toggled(bool);
	void on_radioButtonOut_toggled(bool);
	void on_okButton_clicked();
private:
	int m_iGoodsId;
	int m_iGoodsNum;
	QString m_strSqlExec;
};

#endif
