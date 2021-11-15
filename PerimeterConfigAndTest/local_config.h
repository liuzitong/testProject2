#ifndef LOCAL_CONFIG_H
#define LOCAL_CONFIG_H

#include <QPair>
#include <QList>
#include <QJsonArray>

struct DotInfo
{
    DotInfo(qint32 _coordX,qint32 _coordY,qint32 _motorXPos,qint32 _motorYPos,qint32 _focalDistance)
        :coordX(_coordX),coordY(_coordY),motorXPos(_motorXPos),motorYPos(_motorYPos),focalDistance(_focalDistance){}
    qint32 coordX,coordY,motorXPos,motorYPos,focalDistance;
};

class LocalConfig
{
public:
    LocalConfig();
    QString m_VID;
    QString m_PID;
    QList<QPair<QString,int>> m_colorToSlot;
    QList<QPair<QString,int>> m_spotSizeToSlot;
    QList<DotInfo> m_dotInfoList;
    void Write();
};

#endif // LOCAL_CONFIG_H
