#include "sqlquerymodelconsumetop.h"
#include <QtSql/QSqlRecord>

SqlQueryModelConsumeTop::SqlQueryModelConsumeTop(QObject *parent) : QSqlQueryModel(parent)
{
	m_strSql = "SELECT customerno, fullname, employ, consumeprice, gender, birth, adddate, phone, mobile, company, address, remark, customerid  FROM ct_customer"; 
	m_strCustomerNo = "";
	m_strCustomerName = "";
	m_strSqlWhere = "";
}

QString SqlQueryModelConsumeTop::customerNo()
{
	return m_strCustomerNo;
}

void SqlQueryModelConsumeTop::setCustomerNo(QString strCustomerNo)
{
	m_strCustomerNo = strCustomerNo;
	setSqlWhere();
	sort(m_iSortColumn, m_iSortOrder);
}

QString SqlQueryModelConsumeTop::customerName()
{
	return m_strCustomerName;
}

void SqlQueryModelConsumeTop::setCustomerName(QString strCustomerName)
{
	m_strCustomerName = strCustomerName;
	setSqlWhere();
	sort(m_iSortColumn, m_iSortOrder);
}

void SqlQueryModelConsumeTop::setSqlWhere()
{
	QString strSql;

	if (m_strCustomerNo != "")
	{
		strSql += " WHERE customerno LIKE '" + m_strCustomerNo + "%' ";
	}

	if (m_strCustomerName != "")
	{
		if (strSql.trimmed() == "")
		{
			strSql += " WHERE fullname LIKE '%" + m_strCustomerName + "%' ";
		}
		else
		{
			strSql += " AND fullname LIKE '%" + m_strCustomerName + "%' ";
		}	
	}

	m_strSqlWhere = strSql;
}

void SqlQueryModelConsumeTop::setQuery()
{
	QSqlQueryModel::setQuery(m_strSql + m_strSqlWhere);
}

void SqlQueryModelConsumeTop::sort(int column, Qt::SortOrder order)
{
	m_iSortColumn = column;
	m_iSortOrder = order;
	QString strSql = m_strSql + m_strSqlWhere; 
	strSql += " ORDER BY ";
	switch (column)
	{
		case 0:
			strSql += "customerno";
			break;
		case 1:
			strSql += "fullname";
			break;
		case 2:
			strSql += "employ";
			break;
		case 3:
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

QVariant SqlQueryModelConsumeTop::data(const QModelIndex & index, int role) const
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
	if (role == Qt::TextAlignmentRole && index.column() == 3) 
	{
		value = (Qt::AlignVCenter + Qt::AlignRight);
		return value;
	}

	/*
	if (role == Qt::TextAlignmentRole && (index.column() == 2 || index.column() == 3 || index.column() == 4)) 
	{
		value = (Qt::AlignCenter);
		return value;
	}

	*/
	return value;
}

QVariant SqlQueryModelConsumeTop::headerData(int section, Qt::Orientation orientation, int role) const
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
				value = tr("姓名");
				break;
			case 2:
				value = tr("职业");
				break;
			case 3:
				value = tr("消费额");
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
			default:
			       value = Qt::AlignCenter;
			}
		}
		
	}
	return value;
}
