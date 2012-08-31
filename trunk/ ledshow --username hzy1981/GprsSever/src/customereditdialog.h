#ifndef CUSTOMEREDITDIALOG_H
#define CUSTOMEREDITDIALOG_H

#include <QtGui/QDialog>
#include <QtSql/QSqlRecord>
#include "ui_customereditdialog.h"

class CustomerEditDialog : public QDialog, public Ui::CustomerEditDialog
{
	Q_OBJECT
public:
	CustomerEditDialog(QWidget *parent);
	CustomerEditDialog(QWidget *parent, const QSqlRecord &record);
	~CustomerEditDialog();
	QString strSqlExec();
public slots:
	void on_okButton_clicked();
private:
	int m_iCustomerId;
	QString m_strSqlExec;
};

#endif
