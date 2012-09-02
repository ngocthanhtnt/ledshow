#include <QtSql/QSqlDatabase>
#include "sqlquerymodelgoods.h"

SqlQueryModelGoods::SqlQueryModelGoods(QObject *parent):QSqlQueryModel(parent)
{
        //m_strSql = "SELECT goodsno, goodsname, sellprice, inprice, goodsnum, isservices, manufacturer, goodsid FROM ct_goods ";
        m_strSql = "SELECT * FROM ct_goods";
        m_iGoodsType = -1;
	m_strGoodsNo = "";
	m_strSqlWhere = "";
}

void SqlQueryModelGoods::setSqlWhere()
{
	QString strSql;
	switch (m_iGoodsType)
	{
		case 0:
			strSql += " WHERE isservices = 0 ";	
			break;
		case 1:
			strSql += " WHERE isservices = 1 ";
			break;
		default:
			if (m_iGoodsType != -1)
			{
				m_iGoodsType = -1;
			}
			break;
	}

	if (m_strGoodsNo != "")
	{
		if (strSql.trimmed() == "")
		{
			strSql += " WHERE goodsno LIKE '" + m_strGoodsNo + "%' ";
		}
		else
		{
			strSql += " AND goodsno LIKE '" + m_strGoodsNo + "%' ";
		}	
	}
	
	m_strSqlWhere = strSql;
}

int SqlQueryModelGoods::goodsType()
{
	if (m_iGoodsType < -1 || m_iGoodsType > 1)
	{
		m_iGoodsType = -1;
	}
	return m_iGoodsType;
}

void SqlQueryModelGoods::setGoodsType(int index)
{
	if (index < -1 || index > 1)
	{
		m_iGoodsType = -1;
	}
	else 
	{
		m_iGoodsType = index;
	}
	setSqlWhere();	
	sort(m_iSortColumn, m_iSortOrder);	
}

QString SqlQueryModelGoods::goodsNo()
{
	return m_strGoodsNo;
}

void SqlQueryModelGoods::setGoodsNo(QString strGoodsNo)
{
	m_strGoodsNo = strGoodsNo;
	setSqlWhere();
	sort(m_iSortColumn, m_iSortOrder);
}

void SqlQueryModelGoods::setQuery()
{
        QSqlQueryModel::setQuery(m_strSql + m_strSqlWhere);
}

void SqlQueryModelGoods::sort(int column, Qt::SortOrder order)
{
	m_iSortColumn = column;
	m_iSortOrder = order;
	QString strSql = m_strSql + m_strSqlWhere; 
	strSql += " ORDER BY ";
	switch (column)
	{
		case 0:
			strSql += "goodsno";
			break;
		case 1:
			strSql += "goodsname";
			break;
		case 2:
			strSql += "sellprice";
			break;
		case 3:
			strSql += "inprice";
			break;
		case 4:
			strSql += "goodsnum";
			break;
		case 5:
			strSql += "isservices";
			break;
		case 6:
			strSql += "manufacturer";
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


QVariant SqlQueryModelGoods::data(const QModelIndex & index, int role) const
{
	QVariant value = QSqlQueryModel::data(index, role);
	if (value.isValid() && role == Qt::DisplayRole && index.column() == 5)
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
	if (role == Qt::TextAlignmentRole && index.column() > 1 && index.column() < 5) 
	{
		value = (Qt::AlignVCenter + Qt::AlignRight);
		return value;
	}
	if (role == Qt::TextAlignmentRole && index.column() == 5) 
	{
		value = (Qt::AlignCenter);
		return value;
	}

	return value;
}

QVariant SqlQueryModelGoods::headerData(int section, Qt::Orientation orientation, int role) const
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
				value = tr("商品名称");
				break;
			case 2:
				value = tr("售价");
				break;
			case 3:
				value = tr("进价");
				break;
			case 4:
				value = tr("数量");
				break;
			case 5:
				value = tr("类别");
				break;
			case 6:
				value = tr("进货商");
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
			default:
			       value = Qt::AlignCenter;
			}
		}
		
	}
	return value;
}
