#ifndef SQLQUERYMODELGOODS_H
#define SQLQUERYMODELGOODS_H

#include <QtSql/QSqlQueryModel>
#include <QtCore/QString>

class SqlQueryModelGoods : public QSqlQueryModel
{
	Q_OBJECT
public:
	SqlQueryModelGoods(QObject *parent=0);
public:
	int goodsType();
	void setGoodsType(int index);
	QString goodsNo();
	void setGoodsNo(QString strGoodsNo);
	void setQuery();
	void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
private:
	QString m_strSql;
	int m_iGoodsType;
	QString m_strGoodsNo;

	int m_iSortColumn;
	Qt::SortOrder m_iSortOrder;

	QString m_strSqlWhere;
private:
	void setSqlWhere();
};

#endif 
