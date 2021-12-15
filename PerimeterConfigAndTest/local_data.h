#ifndef LOCAL_DATA_H
#define LOCAL_DATA_H

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

struct singleTableData
{
    singleTableData()=default;
    singleTableData(int row,int column,int* data):m_row(row),m_column(column),m_data(data){};
    ~singleTableData()=default;
    int m_row;
    int m_column;
    int* m_data;
};

class LocalTableData
{
public:
    LocalTableData();
//    ~LocalTableData(){
//        delete[] m_data;
//    }
public:
    singleTableData m_mainPosTableData;
    singleTableData m_secondaryPosTableData;
    singleTableData m_dbAngleDampingTableData;
    singleTableData m_xyDistTableData;
    int* m_data;
    const int dataLen=31*31*3*2+46+52*2;
};




class LocalData
{
public:
    LocalData();
    QString m_VID,m_PID;
    QJsonObject m_rootObj;
    QList<QPair<QString,int>> m_colorToSlot,m_spotSizeToSlot;
    QList<DotInfo> m_dotInfoList,m_secondaryDotInfoList;
    LocalTableData m_localTableData;
    void Write();
};

#endif
