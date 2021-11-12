#include "slot_step_model.h"

SlotPosModel::SlotPosModel(QObject* parent)
{
    modelData.append({0,334});
    modelData.append({1,5666});
    modelData.append({2,4332});
    header<<QStringLiteral("颜色")<<QStringLiteral("步数");

}


int SlotPosModel::rowCount(const QModelIndex &parent) const
{
    return modelData.count();
}

int SlotPosModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant SlotPosModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
           return QVariant();
       if(role == Qt::DisplayRole || role == Qt::EditRole)
       {
           //DisplayRole返回显示的文本值
           const int row = index.row();
           switch(index.column())
           {
           case 0: return modelData.at(row).Slot;
           case 1: return modelData.at(row).Pos;
           }
       }
       return QVariant();

}

bool SlotPosModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        const int row = index.row();
        switch(index.column())
        {
            case 0: {modelData[row].Slot = value.toInt(); break;}
            case 1: {modelData[row].Pos = value.toInt(); break;}
        }
        //发送信号触发刷新
        emit dataChanged(index, index, QVector<int>() << role);
        spdlog::info("回家后");
        printData();
        return true;
    }

}

QVariant SlotPosModel::headerData(int section, Qt::Orientation orientation, int role) const
{
   if(role == Qt::DisplayRole && orientation == Qt::Horizontal)
   {
        return header[section];
   }
   return QAbstractTableModel::headerData(section,orientation,role);
}

Qt::ItemFlags SlotPosModel::flags(const QModelIndex &index) const
{
    return  Qt::ItemIsEnabled | Qt::ItemIsSelectable|Qt::ItemIsEditable;
}

void SlotPosModel::printData()
{
    for(auto&v :modelData)
    {
        spdlog::info("Slot:{0},Pos:{1}",v.Slot,v.Pos);
    }
}


