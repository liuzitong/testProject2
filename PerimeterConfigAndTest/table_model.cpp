#include "table_model.h"
#include <QDebug>

int TableModel::rowCount(const QModelIndex &parent) const
{
    return m_row;
}


int TableModel::columnCount(const QModelIndex &parent) const
{
    return m_column;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
           return QVariant();
       if(role == Qt::DisplayRole || role == Qt::EditRole)
       {
           return m_modelData[index.row()*m_column+index.column()];
       }
       return QVariant();

}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        m_modelData[index.row()*m_column+index.column()]=value.toInt();
        emit dataChanged(index, index, QVector<int>() << role);
        if(m_func!=nullptr)
        { QString s=m_func(index.row(),index.column());qDebug()<<s;}


        return true;
    }
    return false;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
   if(role == Qt::DisplayRole)
   {
       if( orientation == Qt::Horizontal)
           return m_hozHeader[section];
       else if(orientation==Qt::Vertical)
           return m_vertHeader[section];
   }

   return QAbstractTableModel::headerData(section,orientation,role);
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    return  Qt::ItemIsEnabled | Qt::ItemIsSelectable|Qt::ItemIsEditable;
}



