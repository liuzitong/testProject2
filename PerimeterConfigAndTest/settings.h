#ifndef LOCAL_DATA_H
#define LOCAL_DATA_H

#include <QPair>
#include <QList>
#include <QJsonArray>
#include <QMap>
#include <table_model.h>
#include <QSharedPointer>
#include <QJsonObject>
#include "models.h"


class Settings
{
public:
    Settings();
    QString m_VID,m_PID;
    QJsonObject m_rootObj;
    QList<QPair<QString,int>> m_colorToSlot,m_spotSizeToSlot;
    QList<DotInfo> m_dotInfoList,m_secondaryDotInfoList;
    LocalTableData m_localTableData;
    QString localConfig,localData;
    void Write();
};

#endif
