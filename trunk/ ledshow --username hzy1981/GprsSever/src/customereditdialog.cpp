#include "customereditdialog.h"
#include <QtGui/QMessageBox>
#include <QtSql/QSqlQuery>
#include <QtCore/QTextCodec>

CustomerEditDialog::CustomerEditDialog(QWidget *parent):QDialog(parent)
{
	setupUi(this);
	setWindowTitle(tr("添加顾客"));
	setFixedSize(size());

	dateEditAddDate->setDate(QDate::currentDate());
	dateEditBirth->setDate(QDate(1970, 1, 1));
	m_iCustomerId = -1;
}

CustomerEditDialog::CustomerEditDialog(QWidget *parent, const QSqlRecord &record):QDialog(parent)
{
	setupUi(this);
	setWindowTitle(tr("修改信息"));
	setFixedSize(size());
	m_iCustomerId = record.value("customerid").toInt();

	lineEditFullName->setText(record.value("fullname").toString());
	comboBoxGender->setCurrentIndex(record.value("gender").toInt());
	lineEditCustomerNo->setText(record.value("customerno").toString());
	dateEditAddDate->setDate(record.value("adddate").toDate());
	dateEditBirth->setDate(record.value("birth").toDate());
	lineEditEmploy->setText(record.value("employ").toString());
	lineEditCompany->setText(record.value("company").toString());
	lineEditPhone->setText(record.value("phone").toString());
	lineEditMobile->setText(record.value("mobile").toString());
	lineEditAddress->setText(record.value("address").toString());
	textEditRemark->setPlainText(record.value("remark").toString());
	m_iCustomerId = record.value("customerid").toInt();
}

CustomerEditDialog::~CustomerEditDialog()
{
}

void CustomerEditDialog::on_okButton_clicked()
{
	lineEditFullName->setText(lineEditFullName->text().trimmed());
	if (lineEditFullName->text() == "")
	{
		QMessageBox::information(this, tr("信息"), tr("姓名不能为空"), QMessageBox::Ok);
		lineEditFullName->setFocus();
		return;
	}

	lineEditCustomerNo->setText(lineEditCustomerNo->text().trimmed());
	if (lineEditCustomerNo->text() == "")
	{
		QMessageBox::information(this, tr("信息"), tr("编号不能为空"), QMessageBox::Ok);
		lineEditCustomerNo->setFocus();
		return;
	}

	lineEditEmploy->setText(lineEditEmploy->text().trimmed());
	lineEditCompany->setText(lineEditCompany->text().trimmed());
	lineEditPhone->setText(lineEditPhone->text().trimmed());
	lineEditMobile->setText(lineEditMobile->text().trimmed());
	lineEditAddress->setText(lineEditAddress->text().trimmed());
	textEditRemark->setPlainText(textEditRemark->toPlainText().trimmed());

	QSqlQuery query(QSqlDatabase::database());
	QString strSql = "SELECT customerid FROM ct_customer WHERE customerno LIKE '" + lineEditCustomerNo->text() + "' AND customerid <> " + QString::number(m_iCustomerId);
	if (query.exec(strSql) && query.size() > 0)
	{
		QMessageBox::information(this, tr("信息"), tr("编号") + lineEditCustomerNo->text() + tr("已经存在"), QMessageBox::Ok);
		lineEditCustomerNo->setFocus();
		return;
	}

	if (m_iCustomerId < 0)
	{
		m_strSqlExec = QString("INSERT INTO ct_customer(customerno, fullname, adddate, gender, phone, mobile, birth, company, employ, address, remark) VALUES('%1', '%2', '%3', %4, '%5', '%6', '%7', '%8', '%9', '%10', '%11')")
			.arg(lineEditCustomerNo->text())
			.arg(lineEditFullName->text())
			.arg(dateEditAddDate->date().toString("yyyy-MM-dd"))
			.arg(comboBoxGender->currentIndex())
			.arg(lineEditPhone->text())
			.arg(lineEditMobile->text())
			.arg(dateEditBirth->date().toString("yyyy-MM-dd"))
			.arg(lineEditCompany->text())
			.arg(lineEditEmploy->text())
			.arg(lineEditAddress->text())
			.arg(textEditRemark->toPlainText());
	}
	else
	{
		m_strSqlExec = QString("UPDATE ct_customer SET customerno = '%1', fullname = '%2', adddate = '%3', gender = %4, phone = '%5', mobile = '%6', birth = '%7', company = '%8', employ = '%9', address = '%10', remark = '%11' WHERE customerid = %12")
			.arg(lineEditCustomerNo->text())
			.arg(lineEditFullName->text())
			.arg(dateEditAddDate->date().toString("yyyy-MM-dd"))
			.arg(comboBoxGender->currentIndex())
			.arg(lineEditPhone->text())
			.arg(lineEditMobile->text())
			.arg(dateEditBirth->date().toString("yyyy-MM-dd"))
			.arg(lineEditCompany->text())
			.arg(lineEditEmploy->text())
			.arg(lineEditAddress->text())
			.arg(textEditRemark->toPlainText())
			.arg(m_iCustomerId);
	}
	
	accept();
}

QString CustomerEditDialog::strSqlExec()
{
	return m_strSqlExec;
}