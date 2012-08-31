#include "sqlquerymodelconsumebottomleft.h"
#include <QtSql/QSqlRecord>

SqlQueryModelConsumeBottomLeft::SqlQueryModelConsumeBottomLeft(QObject *parent) : QSqlQueryModel(parent)
{
	m_strSql = "SELECT consumedate, consumeprice, consumeid FROM ct_consume";
	m_iCustomerId = 0;
	m_strSqlWhere = " WHERE customerid = " + QString::number(m_iCustomerId);
}

int SqlQueryModelConsumeBottomLeft::customerId()
{
	return m_iCustomerId;
}

void SqlQueryModelConsumeBottomLeft::setCustomerId(int iCustomerId)
{
	m_iCustomerId = iCustomerId;
	setSqlWhere();
	sort(m_iSortColumn, m_iSortOrder);
}

void SqlQueryModelConsumeBottomLeft::setSqlWhere()
{
	QString strSql;
	strSql = " WHERE customerid = " + QString::number(m_iCustomerId);
	m_strSqlWhere = strSql;
}

void SqlQueryModelConsumeBottomLeft::setQuery()
{
	QSqlQueryModel::setQuery(m_strSql + m_strSqlWhere);
}

void SqlQueryModelConsumeBottomLeft::sort(int column, Qt::SortOrder order)
{
	m_iSortColumn = column;
	m_iSortOrder = order;
	QString strSql = m_strSql + m_strSqlWhere; 
	strSql += " ORDER BY ";
	switch (column)
	{
		case 0:
			strSql += "consumedate";
			break;
		case 1:
			strSql += "consumeprice";
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

QVariant SqlQueryModelConsumeBottomLeft::data(const QModelIndex & index, int role) const
{
	QVariant value = QSqlQueryModel::data(index, role);

	/*
	if (value.isValid() && role == Qt::DisplayRole && index.column() == 2)
	{
		value = (value.toInt() == 1 ? tr("男") : tr("女"));
		return value;
	}
	if (value.isValid() && role == Qt::DisplayRole && (index.column() == 2 || index.column() == 3))
	{
		value = "￥" + value.toString();
		return value;
	}

	*/
	if (role == Qt::TextAlignmentRole && index.column() == 1)
	{
		value = (Qt::AlignVCenter + Qt::AlignRight);
		return value;
	}
	/*
	if (role == Qt::TextAlignmentRole && index.column() == 3) 
	{
		value = (Qt::AlignVCenter + Qt::AlignRight);
		return value;
	}

	if (role == Qt::TextAlignmentRole && (index.column() == 2 || index.column() == 3 || index.column() == 4)) 
	{
		value = (Qt::AlignCenter);
		return value;
	}

	*/
	return value;
}

QVariant SqlQueryModelConsumeBottomLeft::headerData(int section, Qt::Orientation orientation, int role) const
{
	QVariant value = QSqlQueryModel::headerData(section, orientation, role);
	if (value.isValid() && orientation == Qt::Horizontal)
	{
		if (role == Qt::DisplayRole)
		{
			switch (section)
			{
			case 0:
				value = tr("日期");
				break;
			case 1:
				value = tr("金额");
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
			default:
			       value = Qt::AlignCenter;
			}
		}
		
	}
	return value;
}
