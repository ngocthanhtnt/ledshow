#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtCore/QPoint>
#include "ui_mainwindow.h"
#include "sqlquerymodelgoods.h"
#include "sqlquerymodelcustomer.h"
#include "sqlquerymodelconsumetop.h"
#include "sqlquerymodelconsumebottomleft.h"
#include "sqlquerymodelconsumebottomright.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent=0);
	~MainWindow();
	void setConsumeBottomRightLabel(bool bReset);
	void setConsumeBottomLeftLabel(bool bReset);
private:
	QSqlDatabase db;
	SqlQueryModelGoods queryModelGoods;
	SqlQueryModelCustomer queryModelCustomer;
	SqlQueryModelConsumeTop queryModelConsumeTop;
	SqlQueryModelConsumeBottomLeft queryModelConsumeBottomLeft;
	SqlQueryModelConsumeBottomRight queryModelConsumeBottomRight;
private slots:
	void on_actionAboutSoftware_triggered();
	void on_actionGoods_triggered();
	void on_actionCustomer_triggered();
	void on_actionConsume_triggered();
	void on_actionReport_triggered();

	void on_actGoodsAdd_triggered();
	void on_actGoodsInout_triggered();
	void on_actGoodsEdit_triggered();
	void on_actGoodsDelete_triggered();

        void on_pushButtonGoodsAdd_clicked();

	void on_actCustomerAdd_triggered();
	void on_actCustomerEdit_triggered();
	void on_actCustomerDelete_triggered();

	void on_actConsumeViewCustomer_triggered();
	void on_actConsumeViewDetail_triggered();

	void on_actConsumeAdd_triggered();
	void on_actConsumeEdit_triggered();
	void on_actConsumeDelete_triggered();

	void on_actConsumeGoodsAdd_triggered();
	void on_actConsumeGoodsEdit_triggered();
	void on_actConsumeGoodsDelete_triggered();
	void on_actConsumeGoodsView_triggered();


	void on_comboBoxGoodsType_currentIndexChanged(int index);
	void on_lineEditGoodsNo_returnPressed();
	void on_lineEditCustomerNo_returnPressed();
	void on_lineEditCustomerName_returnPressed();
	void on_lineEditConsumeCustomerNo_returnPressed();
	void on_lineEditConsumeCustomerName_returnPressed();

	void on_tableViewGoods_doubleClicked(const QModelIndex &index);
	void on_tableViewCustomer_doubleClicked(const QModelIndex &index);
	void on_tableViewConsumeTop_activated(const QModelIndex &index);
	void on_tableViewConsumeBottomLeft_activated(const QModelIndex &index);
	void on_tableViewConsumeBottomRight_doubleClicked(const QModelIndex &index);

	void on_pushButtonConsumeCustomerAdd_clicked();
private:
	QAction *actGoodsAdd;
	QAction *actGoodsInout;
	QAction *actGoodsEdit;
	QAction *actGoodsDelete;	
	QAction *actGoodsSeparator;

	QAction *actCustomerAdd;
	QAction *actCustomerEdit;
	QAction *actCustomerDelete;

	QAction *actConsumeViewCustomer;
	QAction *actConsumeViewDetail;

	QAction *actConsumeAdd;
	QAction *actConsumeEdit;
	QAction *actConsumeDelete;
	QAction *actConsumeSeparator;

	QAction *actConsumeGoodsAdd;
	QAction *actConsumeGoodsEdit;
	QAction *actConsumeGoodsDelete;
	QAction *actConsumeGoodsView;
	QAction *actConsumeGoodsSeparator;
};

#endif
