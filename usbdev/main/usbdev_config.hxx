﻿// ////////////////////////////////////////////////////////////////////////////
/*!
 * @verbatim
 *     < author >      < date >         < memo. >
 *      nightwing      2019/06/19       fixed. by new instruction of doc.
 *      nightwing      2020/10/13       added new functions()  for 0.2.0
 *      nightwing      2020/12/15       added physical key count for 0.3.0
 * @endverbatim
 */
// ////////////////////////////////////////////////////////////////////////////

#ifndef USBDEV_CONFIG_HXX
#define USBDEV_CONFIG_HXX

#include "usbdev/common/usbdev_def.h"
#include <QString>
#include <QSize>
#include <QPair>
#include <QByteArray>
#include <QMetaType>
#include <QJsonObject>
//#include <spdlog/spdlog.h>
namespace UsbDev {

// ////////////////////////////////////////////////////////////////////////////
/*!
 * @brief describe the hardware capabilities
 */
// ////////////////////////////////////////////////////////////////////////////
class USBDEV_API  Config {
public:
   //! ctor
   explicit Config ( );

   //! construct by spec. data
   Config ( const QByteArray & );

   //! ctor ( construct )
   Config ( const Config & );

   //! ctor ( assign )
   Config & operator = ( const Config & );

   //! dtor
   virtual ~Config( );

   //! check if it is empty
   bool     isEmpty( ) const;

//   //! to json object
//   QJsonObject  toJsonObject( ) const;
    quint32& crcVeryficationRef();
    quint32& deviceIDRef();
    quint16& centerFixationLampDARef();
    quint16* bigDiamondfixationLampDAPtr();
    quint16* smallDiamondFixationLampDAPtr();
    quint16& yellowBackgroundLampDARef();
    quint16* whiteBackgroundLampDAPtr();
    quint16& centerInfraredLampDARef();
    quint16& borderInfraredLampDARef();
    quint16& eyeglassFrameLampDARef();
    quint16* environmentAlarmLightDAPtr();
    quint16* pupilGreyThresholdDAPtr();
    int* switchColorMotorPosPtr();
    int* switchLightSpotMotorPosPtr();
    qint32& focusPosForSpotAndColorChangeRef();
    qint32& shutterOpenPosRef();
    qint32& mainTableCenterXRef();
    qint32& mainTableCenterYRef();
    qint32& secondaryTableCenterXRef();
    qint32& secondaryTableCenterYRef();
    qint32& maximunProjectionLightADPresetRef();
    qint32& focalLengthMotorPosForLightCorrectionRef();
    qint32& xMotorPosForLightCorrectionRef();
    qint32& yMotorPosForLightCorrectionRef();
    int& xMotorPosForDiamondCenterTestRef();
    int& yMotorPosForDiamondCenterTestRef();
    int* focalLengthMotorPosForDiamondCenterTestPtr();
    int(*focalLengthMotorPosMappingPtr())[7];
    int(*DbPosMappingPtr())[2];
//    int* DbAngleDampingPtr();
    int* stepTimePtr();
    float& stepLengthRef();
    void* dataPtr();
    int dataLen();
    //    void* GetData();
private:
    void *m_obj=nullptr;
};



}

Q_DECLARE_METATYPE(UsbDev::Config)
#endif
