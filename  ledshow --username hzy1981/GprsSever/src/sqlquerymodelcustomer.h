#ifndef SQLQUERYMODELCUSTOMER_H
#define SQLQUERYMODELCUSTOMER_H

#include <QtSql/QSqlQueryModel>
#include <QtCore/QString>

class SqlQueryModelCustomer : public QSqlQueryModel
{
	Q_OBJECT
public:
	SqlQueryModelCustomer(QObject *parent=0);
public:
	void setQuery();

	QString customerNo();
	void setCustomerNo(QString strCustomerNo);
	QString customerName();
	void setCustomerName(QString strCustomerName);

	void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
private:
	QString m_strSql;
	QString m_strCustomerNo;
	QString m_strCustomerName;
	QString m_strSqlWhere;

	int m_iSortColumn;
	Qt::SortOrder m_iSortOrder;
private:
	void setSqlWhere();
};

#endif
