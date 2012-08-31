#include "sqlquerymodelcustomer.h"
#include <QtSql/QSqlRecord>

SqlQueryModelCustomer::SqlQueryModelCustomer(QObject *parent) : QSqlQueryModel(parent)
{
	m_strSql = "SELECT customerno, fullname, adddate, gender, phone, mobile, birth, company, employ, address, remark, customerid  FROM ct_customer"; 
	m_strCustomerNo = "";
	m_strCustomerName = "";
	m_strSqlWhere = "";
}

QString SqlQueryModelCustomer::customerNo()
{
	return m_strCustomerNo;
}

void SqlQueryModelCustomer::setCustomerNo(QString strCustomerNo)
{
	m_strCustomerNo = strCustomerNo;
	setSqlWhere();
	sort(m_iSortColumn, m_iSortOrder);
}

QString SqlQueryModelCustomer::customerName()
{
	return m_strCustomerName;
}

void SqlQueryModelCustomer::setCustomerName(QString strCustomerName)
{
	m_strCustomerName = strCustomerName;
	setSqlWhere();
	sort(m_iSortColumn, m_iSortOrder);
}

void SqlQueryModelCustomer::setSqlWhere()
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

void SqlQueryModelCustomer::setQuery()
{
	QSqlQueryModel::setQuery(m_strSql + m_strSqlWhere);
}

void SqlQueryModelCustomer::sort(int column, Qt::SortOrder order)
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
			strSql += "adddate";
			break;
		case 3:
			strSql += "gender";
			break;
		case 4:
			strSql += "phone";
			break;
		case 5:
			strSql += "mobile";
			break;
		case 6:
			strSql += "birth";
			break;
		case 7:
			strSql += "company";
			break;
		case 8:
			strSql += "employ";
			break;
		case 9:
			strSql += "address";
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

QVariant SqlQueryModelCustomer::data(const QModelIndex & index, int role) const
{
	QVariant value = QSqlQueryModel::data(index, role);

	if (value.isValid() && role == Qt::DisplayRole && index.column() == 3)
	{
		value = (value.toInt() == 1 ? tr("男") : tr("女"));
		return value;
	}
	/*
	if (value.isValid() && role == Qt::DisplayRole && (index.column() == 2 || index.column() == 3))
	{
		value = "￥" + value.toString();
		return value;
	}

	if (role == Qt::TextAlignmentRole && index.column() > 1 && index.column() < 5) 
	{
		value = (Qt::AlignVCenter + Qt::AlignRight);
		return value;
	}
	*/
	if (role == Qt::TextAlignmentRole && (index.column() == 2 || index.column() == 3 || index.column() == 6)) 
	{
		value = (Qt::AlignCenter);
		return value;
	}

	return value;
}

QVariant SqlQueryModelCustomer::headerData(int section, Qt::Orientation orientation, int role) const
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
				value = tr("加入");
				break;
			case 3:
				value = tr("性别");
				break;
			case 4:
				value = tr("电话");
				break;
			case 5:
				value = tr("手机");
				break;
			case 6:
				value = tr("生日");
				break;
			case 7:
				value = tr("单位");
				break;
			case 8:
				value = tr("职业");
				break;
			case 9:
				value = tr("地址");
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
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			default:
			       value = Qt::AlignCenter;
			}
		}
		
	}
	return value;
}