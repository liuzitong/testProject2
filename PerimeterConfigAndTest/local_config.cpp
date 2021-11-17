#include "local_config.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <iostream>

LocalConfig::LocalConfig()
{
    QFile loadFile("config.json");

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

    QJsonObject rootObj = jsonDoc.object();

    QStringList keys = rootObj.keys();
    for(int i = 0; i < keys.size(); i++)
    {
        qDebug() << "key" << i << " is:" << keys.at(i);
    }


    m_PID = rootObj.value("PID").toString();
    m_VID = rootObj.value("VID").toString();

    QJsonArray dotInfoList=rootObj.value("dotInfoList").toArray();
    QJsonArray secondaryDotInfoList=rootObj.value("secondaryDotInfoList").toArray();
    QJsonArray spotSizeToSlot=rootObj.value("spotSizeToSlot").toArray();
    QJsonArray colorToSlot=rootObj.value("colorToSlot").toArray();

    for(auto i:dotInfoList)
    {
        QJsonObject obj=i.toObject();
        m_dotInfoList.append({obj["coordx"].toInt(),obj["coordy"].toInt(),obj["focalDistance"].toInt(),obj["motorXPos"].toInt(),obj["motorYPos"].toInt()});
    }

    for(auto i:secondaryDotInfoList)
    {
        QJsonObject obj=i.toObject();
        m_secondaryDotInfoList.append({obj["coordx"].toInt(),obj["coordy"].toInt(),obj["focalDistance"].toInt(),obj["motorXPos"].toInt(),obj["motorYPos"].toInt()});
    }

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
}



void LocalConfig::Write()
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


