#ifndef SQLQUERYMODELCONSUMEBOTTOMRIGHT_H
#define SQLQUERYMODELCONSUMEBOTTOMRIGHT_H

#include <QtSql/QSqlQueryModel>
#include <QtCore/QString>

class SqlQueryModelConsumeBottomRight: public QSqlQueryModel
{
	Q_OBJECT
public:
	SqlQueryModelConsumeBottomRight(QObject *parent=0);
public:
	void setQuery();

	int consumeId();
	void setConsumeId(int iConsumeId);

	void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
private:
	QString m_strSql;
	int m_iConsumeId;
	QString m_strSqlWhere;

	int m_iSortColumn;
	Qt::SortOrder m_iSortOrder;
private:
	void setSqlWhere();
};

#endif
