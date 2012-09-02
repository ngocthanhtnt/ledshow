#include "mainwindow.h"
#include <QtGui/QHeaderView>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlQuery>
#include <QtCore/Qt>
#include <QtGui/QMessageBox>
#include <QtGui/QSplitter>
#include "goodseditdialog.h"
#include "goodsinoutdialog.h"
#include "customereditdialog.h"
#include "goodsviewdialog.h"
#include "consumegoodsadddialog.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
        setupUi(this);
	resize(800, 600);
	connect(actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
	toolBar->addAction(actionGoods);
	toolBar->addAction(actionCustomer);
	toolBar->addAction(actionConsume);
	toolBar->addAction(actionReport);
	toolBar->addAction(actionAboutSoftware);
	toolBar->addAction(actionExit);

        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("data.db");
/*
        db.setHostName(db_hostname);
        db.setDatabaseName(db_database);
        db.setUserName(db_username);
        db.setPassword(db_password);
*/

        if (db.open() == false)
        {
                QMessageBox::critical(NULL, QObject::tr("错误"), QObject::tr("MySQL数据库链接错误, 请重新配置数据库参数"), QMessageBox::Ok, QMessageBox::NoButton);
                //return ;
        }
        QSqlQuery q(db);
 /*
                m_strSqlExec = QString("INSERT INTO ct_goods(goodsno, goodsname, inprice, sellprice, goodsnum, manufacturer, isservices) VALUES('%1', '%2', %3, %4, %5, '%6', %7)")
                        .arg(lineEditGoodsNo->text())
                        .arg(lineEditGoodsName->text())
                        .arg(doubleSpinBoxInPrice->value())
                        .arg(doubleSpinBoxSellPrice->value())
                        .arg(spinBoxGoodsNum->value())
                        .arg(lineEditManufacturer->text())
                        .arg(comboBoxIsService->currentIndex());

  */
        q.prepare("CREATE TABLE IF NOT EXISTS ct_goods ("
                          "goodsno TEXT, "
                          "goodsname TEXT, "
                          "inprice REAL, "
                          "sellprice REAL, "
                          "goodsnum INTEGER, "
                          "manufacturer TEXT, "
                          "goodsid INTEGER, "
                          "isservices INTEGER)");
        if(!q.exec()){
            QMessageBox::critical(NULL, QObject::tr("错误"), QObject::tr("新建表格失败"), QMessageBox::Ok, QMessageBox::NoButton);

        }
	//=========================================================================
	queryModelGoods.setQuery();

	tableViewGoods->setModel(&queryModelGoods);
	
	tableViewGoods->verticalHeader()->setDefaultSectionSize(20);
	tableViewGoods->verticalHeader()->hide();
	
	tableViewGoods->setColumnWidth(0, 80);
	tableViewGoods->setColumnWidth(1, 200);
	tableViewGoods->setColumnWidth(2, 60);
	tableViewGoods->setColumnWidth(3, 60);
	tableViewGoods->setColumnWidth(4, 60);
	tableViewGoods->setColumnWidth(5, 60);
	tableViewGoods->setColumnWidth(6, 200);
	tableViewGoods->hideColumn(7);

	queryModelGoods.sort(0);
	QHeaderView *headerGoods = tableViewGoods->horizontalHeader();
	headerGoods->setSortIndicator(0, Qt::AscendingOrder);
	headerGoods->setSortIndicatorShown(true);
	headerGoods->setClickable(true);
	connect(headerGoods, SIGNAL(sectionClicked(int)), tableViewGoods, SLOT(sortByColumn(int)));

	///////////////////////////////////
	// 这里创建商品表格的右键菜单
        actGoodsAdd = new QAction(tr("添加商品"), this);
        connect(actGoodsAdd, SIGNAL(triggered()), this, SLOT(on_actGoodsAdd_triggered()));
        connect(pushButtonGoodsAdd, SIGNAL(clicked()), this, SLOT(on_actGoodsAdd_triggered()));

	actGoodsInout= new QAction(tr("商品进退货"), this);
	connect(actGoodsInout, SIGNAL(triggered()), this, SLOT(on_actGoodsInout_triggered())); 
	connect(pushButtonGoodsInout, SIGNAL(clicked()), this, SLOT(on_actGoodsInout_triggered()));
	

	actGoodsEdit = new QAction(tr("修改商品"), this);
	connect(actGoodsEdit, SIGNAL(triggered()), this, SLOT(on_actGoodsEdit_triggered())); 
	connect(pushButtonGoodsEdit, SIGNAL(clicked()), this, SLOT(on_actGoodsEdit_triggered()));


	actGoodsSeparator = new QAction(this);
	actGoodsSeparator->setSeparator(true);


	actGoodsDelete = new QAction(tr("删除商品"), this);
	connect(actGoodsDelete, SIGNAL(triggered()), this, SLOT(on_actGoodsDelete_triggered())); 
	connect(pushButtonGoodsDelete, SIGNAL(clicked()), this, SLOT(on_actGoodsDelete_triggered()));


	tableViewGoods->addAction(actGoodsAdd);
	tableViewGoods->addAction(actGoodsEdit);
	tableViewGoods->addAction(actGoodsDelete);
	tableViewGoods->addAction(actGoodsSeparator);
	tableViewGoods->addAction(actGoodsInout);
	//=================================================================================
	queryModelCustomer.setQuery();

	tableViewCustomer->setModel(&queryModelCustomer);
	
	tableViewCustomer->verticalHeader()->setDefaultSectionSize(20);
	tableViewCustomer->verticalHeader()->hide();
	
	tableViewCustomer->setColumnWidth(0, 60);
	tableViewCustomer->setColumnWidth(1, 55);
	tableViewCustomer->setColumnWidth(2, 70);
	tableViewCustomer->setColumnWidth(3, 50);
	tableViewCustomer->setColumnWidth(4, 80);
	tableViewCustomer->setColumnWidth(5, 80);
	tableViewCustomer->setColumnWidth(6, 70);
	tableViewCustomer->setColumnWidth(7, 100);
	tableViewCustomer->setColumnWidth(8, 70);
	tableViewCustomer->setColumnWidth(9, 100);
	
	tableViewCustomer->hideColumn(10);
	tableViewCustomer->hideColumn(11);

	queryModelCustomer.sort(0);
	QHeaderView *headerCustomer = tableViewCustomer->horizontalHeader();
	headerCustomer->setSortIndicator(0, Qt::AscendingOrder);
	headerCustomer->setSortIndicatorShown(true);
	headerCustomer->setClickable(true);
	connect(headerCustomer, SIGNAL(sectionClicked(int)), tableViewCustomer, SLOT(sortByColumn(int)));

	///////////////////////////////////
	// 这里创建顾客表格的右键菜单

	actCustomerAdd = new QAction(tr("添加顾客"), this);
	connect(actCustomerAdd, SIGNAL(triggered()), this, SLOT(on_actCustomerAdd_triggered())); 
	connect(pushButtonCustomerAdd, SIGNAL(clicked()), this, SLOT(on_actCustomerAdd_triggered()));
	

	actCustomerEdit = new QAction(tr("修改信息"), this);
	connect(actCustomerEdit, SIGNAL(triggered()), this, SLOT(on_actCustomerEdit_triggered())); 
	connect(pushButtonCustomerEdit, SIGNAL(clicked()), this, SLOT(on_actCustomerEdit_triggered()));


	actCustomerDelete = new QAction(tr("删除顾客"), this);
	connect(actCustomerDelete, SIGNAL(triggered()), this, SLOT(on_actCustomerDelete_triggered())); 
	connect(pushButtonCustomerDelete, SIGNAL(clicked()), this, SLOT(on_actCustomerDelete_triggered()));

	tableViewCustomer->addAction(actCustomerAdd);
	tableViewCustomer->addAction(actCustomerEdit);
	tableViewCustomer->addAction(actCustomerDelete);

	//==========================================
	/*
	QVBoxLayout *consumeLayout = new QVBoxLayout(this);
	QSplitter *splitter = new QSplitter(Qt::Vertical, this);
	splitter->addWidget(frameConsumeTop);
	splitter->addWidget(frameConsumeBottom);
	consumeLayout->addWidget(splitter);
	pageConsume->setLayout(consumeLayout);	

	QVBoxLayout *consumeBottomLayout = new QVBoxLayout(this);
	QSplitter *splitter2 = new QSplitter(Qt::Horizontal, this);
	splitter2->addWidget(tableViewConsumeBottomLeft);
	splitter2->addWidget(tableViewConsumeBottomRight);
	consumeBottomLayout->addWidget(frameConsumeBottomTop);
	consumeBottomLayout->addWidget(splitter2);
	frameConsumeBottom->setLayout(consumeBottomLayout);
	*/


	//=================================================================================
	///////////////////////////////////////////////////////////////////
	queryModelConsumeTop.setQuery();

	tableViewConsumeTop->setModel(&queryModelConsumeTop);
	
	tableViewConsumeTop->verticalHeader()->setDefaultSectionSize(20);
	tableViewConsumeTop->verticalHeader()->hide();
	
	tableViewConsumeTop->setColumnWidth(0, 60);
	tableViewConsumeTop->setColumnWidth(1, 60);
	tableViewConsumeTop->setColumnWidth(2, 100);
	tableViewConsumeTop->setColumnWidth(3, 90);
	
	tableViewConsumeTop->hideColumn(4);
	tableViewConsumeTop->hideColumn(5);
	tableViewConsumeTop->hideColumn(6);
	tableViewConsumeTop->hideColumn(7);
	tableViewConsumeTop->hideColumn(8);
	tableViewConsumeTop->hideColumn(9);
	tableViewConsumeTop->hideColumn(10);
	tableViewConsumeTop->hideColumn(11);
	tableViewConsumeTop->hideColumn(12);

	queryModelConsumeTop.sort(0);
	QHeaderView *headerConsumeTop = tableViewConsumeTop->horizontalHeader();
	headerConsumeTop->setSortIndicator(0, Qt::AscendingOrder);
	headerConsumeTop->setSortIndicatorShown(true);
	headerConsumeTop->setClickable(true);
	connect(headerConsumeTop, SIGNAL(sectionClicked(int)), tableViewConsumeTop, SLOT(sortByColumn(int)));
	//===================================================================
	actConsumeViewCustomer = new QAction(tr("查看消费"), this);
	connect(actConsumeViewCustomer, SIGNAL(triggered()), this, SLOT(on_actConsumeViewCustomer_triggered())); 
	connect(pushButtonConsumeViewCustomer, SIGNAL(clicked()), this, SLOT(on_actConsumeViewCustomer_triggered()));

	tableViewConsumeTop->addAction(actConsumeViewCustomer);
	connect(tableViewConsumeTop, SIGNAL(pressed(const QModelIndex&)), this, SLOT(on_tableViewConsumeTop_activated(const QModelIndex&)));
	labelConsumeCustomerRemark->clear();
	labelConsumeCustomerAddress->clear();
	labelConsumeCustomerMobile->clear();
	labelConsumeCustomerPhone->clear();
	labelConsumeCustomerCompany->clear();
	labelConsumeCustomerEmploy->clear();
	labelConsumeCustomerBirth->clear();
	labelConsumeCustomerAddDate->clear();
	labelConsumeCustomerGender->clear();
	labelConsumeCustomerCustomerNo->clear();
	labelConsumeCustomerCustomerName->clear();
	
	//////////////////////////////////////////////////////////////////////




	//=================================================================================
	// 消费次数列表
	queryModelConsumeBottomLeft.setQuery();
	tableViewConsumeBottomLeft->setModel(&queryModelConsumeBottomLeft);
	tableViewConsumeBottomLeft->verticalHeader()->setDefaultSectionSize(20);
	tableViewConsumeBottomLeft->verticalHeader()->hide();
	
	tableViewConsumeBottomLeft->setColumnWidth(0, 120);
	tableViewConsumeBottomLeft->setColumnWidth(1, 100);
	tableViewConsumeBottomLeft->hideColumn(2);

	queryModelConsumeBottomLeft.sort(0);
	QHeaderView *headerConsumeBottomLeft = tableViewConsumeBottomLeft->horizontalHeader();
	headerConsumeBottomLeft->setSortIndicator(0, Qt::AscendingOrder);
	headerConsumeBottomLeft->setSortIndicatorShown(true);
	headerConsumeBottomLeft->setClickable(true);
	connect(headerConsumeBottomLeft, SIGNAL(sectionClicked(int)), tableViewConsumeBottomLeft, SLOT(sortByColumn(int)));
	//-----------------------------------------------
	actConsumeViewDetail = new QAction(tr("查看详细"), this);
	connect(actConsumeViewDetail, SIGNAL(triggered()), this, SLOT(on_actConsumeViewDetail_triggered())); 
	connect(pushButtonConsumeBottomViewDetail, SIGNAL(clicked()), this, SLOT(on_actConsumeViewDetail_triggered()));

	actConsumeAdd = new QAction(tr("添加消费"), this);
	connect(actConsumeAdd, SIGNAL(triggered()), this, SLOT(on_actConsumeAdd_triggered()));
	connect(pushButtonConsumeAdd, SIGNAL(clicked()), this, SLOT(on_actConsumeAdd_triggered()));

	actConsumeEdit = new QAction(tr("修改消费"), this);
	connect(actConsumeEdit, SIGNAL(triggered()), this, SLOT(on_actConsumeEdit_triggered()));
	connect(pushButtonConsumeEdit, SIGNAL(clicked()), this, SLOT(on_actConsumeEdit_triggered()));

	actConsumeDelete = new QAction(tr("删除消费"), this);
	connect(actConsumeDelete, SIGNAL(triggered()), this, SLOT(on_actConsumeDelete_triggered()));
	connect(pushButtonConsumeDelete, SIGNAL(clicked()), this, SLOT(on_actConsumeDelete_triggered()));

	actConsumeSeparator = new QAction(this);
	actConsumeSeparator->setSeparator(true);

	tableViewConsumeBottomLeft->addAction(actConsumeViewDetail);
	tableViewConsumeBottomLeft->addAction(actConsumeSeparator);
	tableViewConsumeBottomLeft->addAction(actConsumeAdd);
	tableViewConsumeBottomLeft->addAction(actConsumeEdit);
	tableViewConsumeBottomLeft->addAction(actConsumeDelete);
	connect(tableViewConsumeBottomLeft, SIGNAL(pressed(const QModelIndex&)), this, SLOT(on_tableViewConsumeBottomLeft_activated(const QModelIndex&)));
	//==================================================================================


	//=================================================================================
	// 详细消费列表
	queryModelConsumeBottomRight.setQuery();
	tableViewConsumeBottomRight->setModel(&queryModelConsumeBottomRight);
	tableViewConsumeBottomRight->verticalHeader()->setDefaultSectionSize(20);
	tableViewConsumeBottomRight->verticalHeader()->hide();
	
	tableViewConsumeBottomRight->setColumnWidth(0, 80);
	tableViewConsumeBottomRight->setColumnWidth(1, 100);
	tableViewConsumeBottomRight->setColumnWidth(2, 60);
	tableViewConsumeBottomRight->setColumnWidth(3, 60);
	tableViewConsumeBottomRight->setColumnWidth(4, 60);
	tableViewConsumeBottomRight->hideColumn(5);
	tableViewConsumeBottomRight->hideColumn(6);
	tableViewConsumeBottomRight->hideColumn(7);
	tableViewConsumeBottomRight->hideColumn(8);
	tableViewConsumeBottomRight->hideColumn(9);
	tableViewConsumeBottomRight->hideColumn(10);

	queryModelConsumeBottomRight.sort(0);
	QHeaderView *headerConsumeBottomRight = tableViewConsumeBottomRight->horizontalHeader();
	headerConsumeBottomRight->setSortIndicator(0, Qt::AscendingOrder);
	headerConsumeBottomRight->setSortIndicatorShown(true);
	headerConsumeBottomRight->setClickable(true);
	connect(headerConsumeBottomRight, SIGNAL(sectionClicked(int)), tableViewConsumeBottomRight, SLOT(sortByColumn(int)));
	//----------------------------------------------------------------------------------

	actConsumeGoodsView = new QAction(tr("查看商品"), this);
	connect(actConsumeGoodsView, SIGNAL(triggered()), this, SLOT(on_actConsumeGoodsView_triggered())); 
	connect(pushButtonConsumeGoodsView, SIGNAL(clicked()), this, SLOT(on_actConsumeGoodsView_triggered()));

	actConsumeGoodsAdd = new QAction(tr("添加产品"), this);
	connect(actConsumeGoodsAdd, SIGNAL(triggered()), this, SLOT(on_actConsumeGoodsAdd_triggered()));
	connect(pushButtonConsumeGoodsAdd, SIGNAL(clicked()), this, SLOT(on_actConsumeGoodsAdd_triggered()));

	actConsumeGoodsEdit = new QAction(tr("修改产品"), this);
	connect(actConsumeGoodsEdit, SIGNAL(triggered()), this, SLOT(on_actConsumeGoodsEdit_triggered()));
	connect(pushButtonConsumeGoodsEdit, SIGNAL(clicked()), this, SLOT(on_actConsumeGoodsEdit_triggered()));

	actConsumeGoodsDelete = new QAction(tr("删除产品"), this);
	connect(actConsumeGoodsDelete, SIGNAL(triggered()), this, SLOT(on_actConsumeGoodsDelete_triggered()));
	connect(pushButtonConsumeGoodsDelete, SIGNAL(clicked()), this, SLOT(on_actConsumeGoodsDelete_triggered()));

	actConsumeGoodsSeparator = new QAction(this);
	actConsumeGoodsSeparator->setSeparator(true);

	tableViewConsumeBottomRight->addAction(actConsumeGoodsView);
	tableViewConsumeBottomRight->addAction(actConsumeGoodsSeparator);
	tableViewConsumeBottomRight->addAction(actConsumeGoodsAdd);
	tableViewConsumeBottomRight->addAction(actConsumeGoodsEdit);
	tableViewConsumeBottomRight->addAction(actConsumeGoodsDelete);
	
	//------------------------------------------------------------------------
	//==================================================================================
	pushButtonConsumeEdit->hide();
	pushButtonConsumeGoodsEdit->hide();
	actConsumeEdit->setVisible(false);
	actConsumeGoodsEdit->setVisible(false);

	setConsumeBottomRightLabel(true);
        setConsumeBottomLeftLabel(true);
}

MainWindow::~MainWindow()
{
	db.close();
}

void MainWindow::on_actionAboutSoftware_triggered()
{
	QMessageBox::about(this, tr("关于本软件"), tr("使用Qt4做的一个简单的美容院管理系统，这是0.0.2版，Build 20060904，待逐步加强"));
}

void MainWindow::on_actionGoods_triggered()
{
	stackedWidget->setCurrentWidget(pageGoods);
}

void MainWindow::on_actionCustomer_triggered()
{
	stackedWidget->setCurrentWidget(pageCustomer);
}

void MainWindow::on_actionConsume_triggered()
{
	stackedWidget->setCurrentWidget(pageConsume);
}

void MainWindow::on_actionReport_triggered()
{
	stackedWidget->setCurrentWidget(pageReport);
}

void MainWindow::on_actGoodsAdd_triggered()
{
	if (db.isOpen())
	{
                QSqlQuery   sqlQuery(db);
		GoodsEditDialog goodsEditDialog(this);
		goodsEditDialog.exec();	
		if (goodsEditDialog.result() == QDialog::Accepted)
		{
                        if(sqlQuery.exec(goodsEditDialog.strSqlExec()) == false)
                          qDebug("insert failed");
			queryModelGoods.setQuery();
		}
	}
}

void MainWindow::on_pushButtonGoodsAdd_clicked()
{
  on_actGoodsAdd_triggered();
}

void MainWindow::on_actGoodsInout_triggered()
{
	QModelIndex index = tableViewGoods->currentIndex();
	if (index.isValid())
	{
		GoodsInoutDialog goodsInoutDialog(this, queryModelGoods.record(index.row()));
		goodsInoutDialog.exec();
		if (goodsInoutDialog.result() == QDialog::Accepted)
		{
			db.exec(goodsInoutDialog.strSqlExec());
			queryModelGoods.setQuery();
		}
	}
}

void MainWindow::on_actGoodsEdit_triggered()
{
	QModelIndex index = tableViewGoods->currentIndex();
	if (index.isValid())
	{
            QSqlQuery   sqlQuery(db);
		GoodsEditDialog goodsEditDialog(this, queryModelGoods.record(index.row()));
		goodsEditDialog.exec();	
		if (goodsEditDialog.result() == QDialog::Accepted)
		{
                        sqlQuery.exec(goodsEditDialog.strSqlExec());
			queryModelGoods.setQuery();
		}
	}
}

void MainWindow::on_actGoodsDelete_triggered()
{
	QModelIndex index = tableViewGoods->currentIndex();
	if (index.isValid())
	{
		db.exec(QString("DELETE FROM ct_goods WHERE goodsid = %1").arg(queryModelGoods.record(index.row()).value("goodsid").toInt()));
		queryModelGoods.setQuery();	
	}
}

void MainWindow::on_comboBoxGoodsType_currentIndexChanged(int index)
{
	queryModelGoods.setGoodsType(index-1);
}

void MainWindow::on_lineEditGoodsNo_returnPressed()
{
	QString strGoodsNo = lineEditGoodsNo->text().trimmed();
	queryModelGoods.setGoodsNo(strGoodsNo);
}

void MainWindow::on_tableViewGoods_doubleClicked(const QModelIndex &index)
{
	if (index.isValid())
	{
		GoodsEditDialog goodsEditDialog(this, queryModelGoods.record(index.row()));
		goodsEditDialog.exec();
		if (goodsEditDialog.result() == QDialog::Accepted)
		{
			db.exec(goodsEditDialog.strSqlExec());
			queryModelGoods.setQuery();
		}
	}
}

void MainWindow::on_tableViewCustomer_doubleClicked(const QModelIndex &index)
{
	if (index.isValid())
	{
		CustomerEditDialog customerEditDialog(this, queryModelCustomer.record(index.row()));
		customerEditDialog.exec();
		if (customerEditDialog.result() == QDialog::Accepted)
		{
			db.exec(customerEditDialog.strSqlExec());
			queryModelCustomer.setQuery();
		}
	}
}

void MainWindow::on_actCustomerAdd_triggered()
{
	if (db.isOpen())
	{
		CustomerEditDialog customerEditDialog(this);
		customerEditDialog.exec();	
		if (customerEditDialog.result() == QDialog::Accepted)
		{
			db.exec(customerEditDialog.strSqlExec());
			queryModelCustomer.setQuery();
		}
	}
}
void MainWindow::on_actCustomerEdit_triggered()
{
	QModelIndex index = tableViewCustomer->currentIndex();
	if (index.isValid())
	{
		CustomerEditDialog customerEditDialog(this, queryModelCustomer.record(index.row()));
		customerEditDialog.exec();	
		if (customerEditDialog.result() == QDialog::Accepted)
		{
			db.exec(customerEditDialog.strSqlExec());
			queryModelCustomer.setQuery();
		}
	}
}
void MainWindow::on_actCustomerDelete_triggered()
{
	QModelIndex index = tableViewCustomer->currentIndex();
	if (index.isValid())
	{
		db.exec(QString("DELETE FROM ct_customer WHERE customerid = %1").arg(queryModelCustomer.record(index.row()).value("customerid").toInt()));
		queryModelCustomer.setQuery();	
	}
}

void MainWindow::on_lineEditCustomerNo_returnPressed()
{
	QString strCustomerNo = lineEditCustomerNo->text().trimmed();
	queryModelCustomer.setCustomerNo(strCustomerNo);
}

void MainWindow::on_lineEditCustomerName_returnPressed()
{
	QString strCustomerName = lineEditCustomerName->text().trimmed();
	queryModelCustomer.setCustomerName(strCustomerName);
}

void MainWindow::on_lineEditConsumeCustomerNo_returnPressed()
{
	QString strCustomerNo = lineEditConsumeCustomerNo->text().trimmed();
	queryModelConsumeTop.setCustomerNo(strCustomerNo);
}

void MainWindow::on_lineEditConsumeCustomerName_returnPressed()
{
	QString strCustomerName = lineEditConsumeCustomerName->text().trimmed();
	queryModelConsumeTop.setCustomerName(strCustomerName);
}

void MainWindow::on_tableViewConsumeTop_activated(const QModelIndex &index)
{
	if (index.isValid())
	{
		// 在这里处理赋值事宜
		labelConsumeCustomerRemark->setText(queryModelConsumeTop.record(index.row()).value("remark").toString());
		labelConsumeCustomerAddress->setText(queryModelConsumeTop.record(index.row()).value("address").toString());
		labelConsumeCustomerMobile->setText(queryModelConsumeTop.record(index.row()).value("mobile").toString());
		labelConsumeCustomerPhone->setText(queryModelConsumeTop.record(index.row()).value("phone").toString());
		labelConsumeCustomerCompany->setText(queryModelConsumeTop.record(index.row()).value("company").toString());
		labelConsumeCustomerEmploy->setText(queryModelConsumeTop.record(index.row()).value("employ").toString());
		labelConsumeCustomerBirth->setText(queryModelConsumeTop.record(index.row()).value("birth").toString());
		labelConsumeCustomerAddDate->setText(queryModelConsumeTop.record(index.row()).value("adddate").toString());
		labelConsumeCustomerGender->setText(queryModelConsumeTop.record(index.row()).value("gender").toInt() == 1 ? tr("男") : tr("女"));
		labelConsumeCustomerCustomerNo->setText(queryModelConsumeTop.record(index.row()).value("customerno").toString());
		labelConsumeCustomerCustomerName->setText(queryModelConsumeTop.record(index.row()).value("fullname").toString());
		queryModelConsumeBottomLeft.setCustomerId(queryModelConsumeTop.record(index.row()).value("customerid").toInt());
		setConsumeBottomLeftLabel(false);

		queryModelConsumeBottomRight.setConsumeId(0);
		setConsumeBottomRightLabel(true);
	}
}

void MainWindow::on_actConsumeViewCustomer_triggered()
{
	QModelIndex index = tableViewConsumeTop->currentIndex();
	if (index.isValid())
	{
		on_tableViewConsumeTop_activated(index);
	}
}

void MainWindow::on_tableViewConsumeBottomLeft_activated(const QModelIndex &index)
{
	if (index.isValid())
	{
		// 在这里处理赋值事宜
		queryModelConsumeBottomRight.setConsumeId(queryModelConsumeBottomLeft.record(index.row()).value("consumeid").toInt());
		setConsumeBottomRightLabel(false);

	}
}

void MainWindow::on_actConsumeViewDetail_triggered()
{
	QModelIndex index = tableViewConsumeBottomLeft->currentIndex();
	if (index.isValid())
	{
		on_tableViewConsumeBottomLeft_activated(index);
	}
}


void MainWindow::setConsumeBottomRightLabel(bool bReset)
{
		int iTotalNum = 0;
		double fTotalPrice = 0;

		if (bReset == false)
		{
			for (int i = 0; i < queryModelConsumeBottomRight.rowCount(); i++)
			{	
				iTotalNum += queryModelConsumeBottomRight.record(i).value("goodsnum").toInt();
				fTotalPrice += queryModelConsumeBottomRight.record(i).value("goodsprice").toDouble();
			}
		}
		
		labelBottomRightTotalNum->setText(tr("<font color=blue>%1件</font>").arg(iTotalNum));
		labelBottomRightTotalPrice->setText(tr("<font color=blue>%1元</font>").arg(fTotalPrice, 0, 'f', 2));
}

void MainWindow::setConsumeBottomLeftLabel(bool bReset)
{
		int iTotalNum = 0;
		double fTotalPrice = 0;

		if (bReset == false)
		{
			iTotalNum = queryModelConsumeBottomLeft.rowCount();
			
			for (int i = 0; i < iTotalNum; i++)
			{
				fTotalPrice += queryModelConsumeBottomLeft.record(i).value("consumeprice").toDouble();
			}
		}

		labelBottomLeftTotalNum->setText(tr("<font color=blue>%1次</font>").arg(iTotalNum));
		labelBottomLeftTotalPrice->setText(tr("<font color=blue>%1元</font>").arg(fTotalPrice, 0, 'f', 2));
}

void MainWindow::on_actConsumeAdd_triggered()
{
	QModelIndex index = tableViewConsumeTop->currentIndex();
	if (index.isValid())
	{
		db.exec(QString("INSERT INTO ct_consume(customerid, consumedate, consumeprice, remark) VALUES(%1, '%2', 0.00, '')").arg(queryModelConsumeTop.record(index.row()).value("customerid").toInt()).arg(QDate::currentDate().toString("yyyy-MM-dd")));
		queryModelConsumeBottomLeft.setQuery();	
	}
}

void MainWindow::on_actConsumeEdit_triggered()
{
}

void MainWindow::on_actConsumeDelete_triggered()
{
	QModelIndex index = tableViewConsumeBottomLeft->currentIndex();
	if (index.isValid())
	{
		if (queryModelConsumeBottomLeft.record(index.row()).value("consumeprice").toString() == "0.00")
		{
			db.exec(QString("DELETE FROM ct_consume WHERE consumeid = %1").arg(queryModelConsumeBottomLeft.record(index.row()).value("consumeid").toInt()));
			queryModelConsumeBottomLeft.setQuery();
			return;
		}
		int bRet = QMessageBox::question(this, tr("是否还原商品"), tr("是否要将商品以及用户消费额还原？"), tr("是"), tr("否"), tr("取消"), 0, 2);
		if (bRet == 0)
		{
			QSqlQuery queryTemp;
			queryTemp.exec(QString("SELECT goodsid, goodsnum FROM ct_consumedetail WHERE consumeid = %1").arg(queryModelConsumeBottomLeft.record(index.row()).value("consumeid").toInt()));
			while (queryTemp.next())
			{
				db.exec(QString("UPDATE ct_goods SET goodsnum = goodsnum + %1 WHERE goodsid = %2").arg(queryTemp.value(1).toInt()).arg(queryTemp.value(0).toInt()));
			}

			db.exec(QString("UPDATE ct_customer SET consumeprice = consumeprice - %1 WHERE customerid = %2").arg(queryModelConsumeBottomLeft.record(index.row()).value("consumeprice").toDouble()).arg(queryModelConsumeBottomLeft.customerId()));
			db.exec(QString("DELETE FROM ct_consumedetail WHERE consumeid = %1").arg(queryModelConsumeBottomLeft.record(index.row()).value("consumeid").toInt()));
			db.exec(QString("DELETE FROM ct_consume WHERE consumeid = %1").arg(queryModelConsumeBottomLeft.record(index.row()).value("consumeid").toInt()));
			queryModelConsumeBottomLeft.setQuery();
			queryModelConsumeBottomRight.setQuery();
		}
		else if (bRet == 1)
		{
			db.exec(QString("DELETE FROM ct_consumedetail WHERE consumeid = %1").arg(queryModelConsumeBottomLeft.record(index.row()).value("consumeid").toInt()));
			db.exec(QString("DELETE FROM ct_consume WHERE consumeid = %1").arg(queryModelConsumeBottomLeft.record(index.row()).value("consumeid").toInt()));
			queryModelConsumeBottomLeft.setQuery();
			queryModelConsumeBottomRight.setQuery();
		}
	}
}

void MainWindow::on_actConsumeGoodsAdd_triggered()
{
	QModelIndex index = tableViewConsumeBottomLeft->currentIndex();
	if (index.isValid())
	{
		ConsumeGoodsAddDialog consumeGoodsAddDialog(this, queryModelConsumeBottomLeft.record(index.row()).value("consumeid").toInt(), queryModelConsumeBottomLeft.customerId());
		consumeGoodsAddDialog.exec();
		if (consumeGoodsAddDialog.result() == QDialog::Accepted)
			{
				queryModelConsumeTop.setQuery();
				queryModelConsumeBottomLeft.setQuery();
				queryModelConsumeBottomRight.setQuery();
			}
	}
}

void MainWindow::on_actConsumeGoodsEdit_triggered()
{
}

void MainWindow::on_actConsumeGoodsDelete_triggered()
{
	QModelIndex index = tableViewConsumeBottomRight->currentIndex();
	if (index.isValid())
	{
		db.exec(QString("UPDATE ct_customer SET consumeprice = consumeprice - %1 WHERE customerid = %2").arg(queryModelConsumeBottomRight.record(index.row()).value("goodsprice").toDouble()).arg(queryModelConsumeBottomLeft.customerId()));
		db.exec(QString("UPDATE ct_consume SET consumeprice = consumeprice - %1 WHERE consumeid = %2").arg(queryModelConsumeBottomRight.record(index.row()).value("goodsprice").toDouble()).arg(queryModelConsumeBottomRight.consumeId()));
		db.exec(QString("UPDATE ct_goods SET goodsnum = goodsnum + %1 WHERE goodsid = %2").arg(queryModelConsumeBottomRight.record(index.row()).value("goodsnum").toInt()).arg(queryModelConsumeBottomRight.record(index.row()).value("goodsid").toInt()));
		db.exec(QString("DELETE FROM ct_consumedetail WHERE consumeid = %1 AND goodsid = %2").arg(queryModelConsumeBottomRight.consumeId()).arg(queryModelConsumeBottomRight.record(index.row()).value("goodsid").toInt()));
		queryModelConsumeTop.setQuery();
		queryModelConsumeBottomLeft.setQuery();
		queryModelConsumeBottomRight.setQuery();
	}
}

void MainWindow::on_actConsumeGoodsView_triggered()
{
	QModelIndex index = tableViewConsumeBottomRight->currentIndex();
	if (index.isValid())
	{
		GoodsViewDialog goodsViewDialog(this, queryModelConsumeBottomRight.record(index.row()));
		goodsViewDialog.exec();
	}
}

void MainWindow::on_tableViewConsumeBottomRight_doubleClicked(const QModelIndex &index)
{
	if (index.isValid())
	{
		GoodsViewDialog goodsViewDialog(this, queryModelConsumeBottomRight.record(index.row()));
		goodsViewDialog.exec();
	}
}

void MainWindow::on_pushButtonConsumeCustomerAdd_clicked()
{
	on_actionCustomer_triggered();
	on_actCustomerAdd_triggered();
}
