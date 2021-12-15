#include "local_data.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <iostream>
#include <QFile>

LocalData::LocalData()
{
    QFile loadFile(R"(data/config.json)");

    if(!loadFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "could't open projects json";
        return;
    }

    QByteArray allData = loadFile.readAll();
    loadFile.close();

    QJsonParseError jsonError;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData, &jsonError));

    if(jsonError.error != QJsonParseError::NoError)
    {
        qDebug() << "json error!" << jsonError.errorString();
        return;
    }

    m_rootObj = jsonDoc.object();

    QStringList keys = m_rootObj.keys();
    for(int i = 0; i < keys.size(); i++)
    {
        qDebug() << "key" << i << " is:" << keys.at(i);
    }


    m_PID = m_rootObj.value("PID").toString();
    m_VID = m_rootObj.value("VID").toString();

    QJsonArray dotInfoList=m_rootObj.value("dotInfoList").toArray();
    QJsonArray secondaryDotInfoList=m_rootObj.value("secondaryDotInfoList").toArray();
    QJsonArray spotSizeToSlot=m_rootObj.value("spotSizeToSlot").toArray();
    QJsonArray colorToSlot=m_rootObj.value("colorToSlot").toArray();


//    for(auto i:dotInfoList)
//    {
//        QJsonObject obj=i.toObject();
//        m_dotInfoList.append({obj["coordx"].toInt(),obj["coordy"].toInt(),obj["focalDistance"].toInt(),obj["motorXPos"].toInt(),obj["motorYPos"].toInt()});
//    }

//    for(auto i:secondaryDotInfoList)
//    {
//        QJsonObject obj=i.toObject();
//        m_secondaryDotInfoList.append({obj["coordx"].toInt(),obj["coordy"].toInt(),obj["focalDistance"].toInt(),obj["motorXPos"].toInt(),obj["motorYPos"].toInt()});
//    }

    for(auto i:spotSizeToSlot)
    {
        QJsonObject obj=i.toObject();
        QString spotSize=obj["spotSize"].toString();
        int slot=obj["Slot"].toInt();
        m_spotSizeToSlot.append({spotSize,slot});
    }

    for(auto i:colorToSlot)
    {
        QJsonObject obj=i.toObject();
        QString color=obj["Color"].toString();
        int slot=obj["Slot"].toInt();
        m_colorToSlot.append({color,slot});
    }
//    LoadTableModel();
}





//void LocalData::LoadTableModel()
//{
//    m_colorPosTableModel = QSharedPointer<TableModel>(new TableModel());
//    QJsonObject colorPosModel=m_rootObj.value("colorPosModel").toObject();
////    QJsonObject info=colorPosModel["info"].toObject();
////    int row=info["rowCount"].toInt();
////    int column=info["columnCount"].toInt();
////    m_colorPosTableModel.data()->m_row=row;
////    m_colorPosTableModel.data()->m_column=column;
//    QJsonArray headers=colorPosModel["headers"].toArray();
//    for(auto i:headers)
//    {
//        m_colorPosTableModel.data()->m_hozHeader<<i.toString();
//        qDebug()<<i.toString();
//    }

//    QJsonArray data=colorPosModel["data"].toArray();
//    int rowCount=data.count();
//    int columnCount=data[0].toObject()["row"].toArray().count();
//    qDebug()<<rowCount<<" "<<columnCount;
//    m_colorPosTableModel.data()->m_modelData=QSharedPointer<QVariant>(new QVariant[rowCount*columnCount],[](QVariant* ptr){delete []ptr;});
//    m_colorPosTableModel.data()->m_row=rowCount;
//    m_colorPosTableModel.data()->m_column=columnCount;
//    for(int row=0;row<rowCount;row++)
//    {
//        QJsonObject obj=data[row].toObject();
//        auto jsArr=obj["row"].toArray();
//        for(int column=0;column<columnCount;column++)
//        {
//            auto v=jsArr[column];
//            if(v.toVariant().type()==QVariant::Type::String)
//            {
//                qDebug()<<v.toVariant().toString();
//            }
//            else
//            {
//                qDebug()<<QString::number(v.toVariant().toInt());
//            }
//            qDebug()<<row*columnCount+column;
//            m_colorPosTableModel.data()->m_modelData.data()[row*columnCount+column]=jsArr[column].toVariant();
//        }
//    }
//}



void LocalData::Write()
{
    QJsonObject obj;
    obj.insert("VID",m_VID);
    obj.insert("PID",m_PID);

    QJsonArray array,array2;
    for(auto&v:m_spotSizeToSlot){
        QJsonObject spotSlot;
        spotSlot.insert("spotSize",v.first);
        spotSlot.insert("Slot",v.second);
        array2.append(spotSlot);
    }

    for(auto&v:m_dotInfoList){
        QJsonObject dotInfo;
        dotInfo.insert("coordx",v.coordX);
        dotInfo.insert("coordy",v.coordY);
        dotInfo.insert("motorXPos",v.motorXPos);
        dotInfo.insert("motorYPos",v.motorYPos);
        dotInfo.insert("focalDistance",v.focalDistance);
        array.append(dotInfo);
    }
    obj.insert("dotInfoList",array);
    obj.insert("spotSizeToSlot",array2);
    qDebug()<<obj;
    QJsonDocument qjDoc(obj);
    auto ba= qjDoc.toJson();
    QFile file("config.json");
    file.open(QIODevice::WriteOnly);
    file.write(ba);

    file.close();
}



LocalTableData::LocalTableData()
{
    m_data=new int[400*400]{0};
    m_mainPosTableData=singleTableData(31*3,31,m_data);
    m_secondaryPosTableData=singleTableData(31*3,31,m_data+31*3*31);
    m_dbAngleDampingTableData=singleTableData(46,1,m_data+31*3*31*2);
    m_xyDistTableData=singleTableData(25,2,m_data+31*3*31*2+46);
}
