#include "local_config.h"
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

LocalConfig::LocalConfig()
{
    VID="adbd";PID="ggg";
    QPair<int,int> a(3,6);
    spotSizeToSlot.append(QPair<int,int>(3,6));
    spotSizeToSlot.append(QPair<int,int>(5,8));
    dotInfoList.append(DotInfo(2,3,5,6,7));
    dotInfoList.append(DotInfo(5,3,56,5,7));


}

void LocalConfig::ShowAndWrite()
{
    QJsonObject obj;
    obj.insert("VID",VID);
    obj.insert("PID",PID);

    QJsonArray array,array2;
    for(auto&v:spotSizeToSlot){
        QJsonObject spotSlot;
        spotSlot.insert("spotSize",v.first);
        spotSlot.insert("Slot",v.second);
        array2.append(spotSlot);
    }

    for(auto&v:dotInfoList){
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


