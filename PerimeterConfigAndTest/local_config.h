#ifndef LOCAL_CONFIG_H
#define LOCAL_CONFIG_H

#include <QPair>
#include <QList>

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
    void ShowAndWrite();
    QString VID;
    QString PID;

    QList<QPair<QString,int>> spotSizeToSlot;
    QList<QPair<QString,int>> colorToSlot;
    QList<DotInfo> dotInfoList;
};

#endif // LOCAL_CONFIG_H
