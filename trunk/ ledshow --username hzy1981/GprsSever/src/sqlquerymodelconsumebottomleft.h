#ifndef SQLQUERYMODELCONSUMEBOTTOMLEFT_H
#define SQLQUERYMODELCONSUMEBOTTOMLEFT_H

#include <QtSql/QSqlQueryModel>
#include <QtCore/QString>

class SqlQueryModelConsumeBottomLeft: public QSqlQueryModel
{
	Q_OBJECT
public:
	SqlQueryModelConsumeBottomLeft(QObject *parent=0);
public:
	void setQuery();

	void InsertConsume();
	int customerId();
	void setCustomerId(int iCustomerId);

	void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
private:
	QString m_strSql;
	int m_iCustomerId;
	QString m_strSqlWhere;

	int m_iSortColumn;
	Qt::SortOrder m_iSortOrder;
private:
	void setSqlWhere();
};

#endif
