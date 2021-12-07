#ifndef LOCAL_CONFIG_H
#define LOCAL_CONFIG_H

#include <QPair>
#include <QList>
#include <QJsonArray>
#include <QMap>
#include <table_model.h>
#include <QSharedPointer>
#include <QJsonObject>


struct DotInfo
{
//    DotInfo()=default;
//    DotInfo(qint32 _coordX,qint32 _coordY,qint32 _motorXPos,qint32 _motorYPos,qint32 _focalDistance)
//        :coordX(_coordX),coordY(_coordY),motorXPos(_motorXPos),motorYPos(_motorYPos),focalDistance(_focalDistance){}
    qint32 coordX,coordY,motorXPos,motorYPos,focalDistance;
};



class LocalData
{

public:
    LocalData();
    QString m_VID,m_PID;
    QJsonObject m_rootObj;
    QList<QPair<QString,int>> m_colorToSlot,m_spotSizeToSlot;
    QList<DotInfo> m_dotInfoList,m_secondaryDotInfoList;

//    struct mainMotorPosTable
//    {
//        DotInfo dotinfo[];
//    };




    void Write();
};

#endif // LOCAL_CONFIG_H
