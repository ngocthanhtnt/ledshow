#include "sqlquerymodelconsumebottomright.h"
#include <QtSql/QSqlRecord>

SqlQueryModelConsumeBottomRight::SqlQueryModelConsumeBottomRight(QObject *parent) : QSqlQueryModel(parent)
{
	m_strSql = "SELECT b.goodsno, b.goodsname, b.isservices, a.goodsnum, a.goodsprice, a.goodsid, a.remark, b.sellprice, b.inprice, b.manufacturer, b.goodsnum AS totalgoodsnum FROM ct_consumedetail a, ct_goods as b WHERE a.goodsid = b.goodsid";
	m_iConsumeId = 0;
	m_strSqlWhere = " AND a.consumeid = " + QString::number(m_iConsumeId);
}

int SqlQueryModelConsumeBottomRight::consumeId()
{
	return m_iConsumeId;
}

void SqlQueryModelConsumeBottomRight::setConsumeId(int iConsumeId)
{
	m_iConsumeId = iConsumeId;
	setSqlWhere();
	sort(m_iSortColumn, m_iSortOrder);
}

void SqlQueryModelConsumeBottomRight::setSqlWhere()
{
	QString strSql;
	strSql = " AND a.consumeid = " + QString::number(m_iConsumeId);
	m_strSqlWhere = strSql;
}

void SqlQueryModelConsumeBottomRight::setQuery()
{
	QSqlQueryModel::setQuery(m_strSql + m_strSqlWhere);
}

void SqlQueryModelConsumeBottomRight::sort(int column, Qt::SortOrder order)
{
	m_iSortColumn = column;
	m_iSortOrder = order;
	QString strSql = m_strSql + m_strSqlWhere; 
	strSql += " ORDER BY ";
	switch (column)
	{
		case 0:
			strSql += "b.goodsno";
			break;
		case 1:
			strSql += "b.goodsname";
			break;
		case 2:
			strSql += "b.isservices";
			break;
		case 3:
			strSql += "a.goodsnum";
			break;
		case 4:
			strSql += "a.goodsprice";
			break;
		default:
			return;
	}
	if (order == Qt::DescendingOrder)
	{
		strSql += " DESC";
	}
	QSqlQueryModel::setQuery(strSql);
}

QVariant SqlQueryModelConsumeBottomRight::data(const QModelIndex & index, int role) const
{
	QVariant value = QSqlQueryModel::data(index, role);

	if (value.isValid() && role == Qt::DisplayRole && index.column() == 2)
	{
		value = (value.toInt() == 1 ? tr("服务类") : tr("产品类"));
		return value;
	}
	/*
	if (value.isValid() && role == Qt::DisplayRole && (index.column() == 2 || index.column() == 3))
	{
		value = "￥" + value.toString();
		return value;
	}

	*/
	if (role == Qt::TextAlignmentRole && (index.column() == 3 || index.column() == 4))
	{
		value = (Qt::AlignVCenter + Qt::AlignRight);
		return value;
	}

	if (role == Qt::TextAlignmentRole && index.column() == 2) 
	{
		value = (Qt::AlignCenter);
		return value;
	}

	return value;
}

QVariant SqlQueryModelConsumeBottomRight::headerData(int section, Qt::Orientation orientation, int role) const
{
	QVariant value = QSqlQueryModel::headerData(section, orientation, role);
	if (value.isValid() && orientation == Qt::Horizontal)
	{
		if (role == Qt::DisplayRole)
		{
			switch (section)
			{
			case 0:
				value = tr("编号");
				break;
			case 1:
				value = tr("名称");
				break;
			case 2:
				value = tr("类型");
				break;
			case 3:
				value = tr("数量");
				break;
			case 4:
				value = tr("价格");
				break;
			default:;
			}
		}
		else if (role == Qt::TextAlignmentRole)
		{
			switch (section)
			{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			default:
			       value = Qt::AlignCenter;
			}
		}
		
	}
	return value;
}