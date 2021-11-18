// ////////////////////////////////////////////////////////////////////////////
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
#include "usbdev/main/usbdev_devctl.hxx"
#include <QString>
#include <QSize>
#include <QPair>
#include <QByteArray>
#include <QMetaType>
#include <QJsonObject>

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
    quint32 crcVeryfication();

    quint32 deviceID();
    quint16 centerFixationLampDA();
    quint16 bigDiamondfixationLampDA();
    quint16 smallDiamondFixationLampDA();
    quint16 yellowBackgroundLampDA();
    quint16* whiteBackgroundLampDA();
    quint16 centerInfraredLampDA();
    quint16 borderInfraredLampDA();
    quint16 eyeglassFrameLampDA();
    quint16* environmentAlarmLightDA();
    int* switchColorMotorCoord();
    int* switchLightSpotMotorCoord();
    qint32 focusCoordForSpotAndColorChange();
    qint32 shutterOpenPos();
    qint32 mainTableCenterXCorrection();
    qint32 mainTableCenterYCorrection();
    qint32 secondaryTableCenterXCorrection();
    qint32 secondaryTableCenterYCorrection();
    qint32 maximunProjectionLightADPreset();
    qint32 xMotorCoordForLightCorrection();
    qint32 yMotorCoordForLightCorrection();
    int* focalLengthMotorCoordForDiamondCenterTest();
    int(*focalLengthMotorCoordMapping())[7];
    int(*DbCoordMapping())[2];
private:
    void *m_obj;
};



}

Q_DECLARE_METATYPE(UsbDev::Config)
#endif
