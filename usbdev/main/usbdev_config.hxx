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
    quint32& crcVeryficationRef();

    quint32& deviceIDRef();
    quint16& centerFixationLampDARef();
    quint16& bigDiamondfixationLampDARef();
    quint16& smallDiamondFixationLampDARef();
    quint16& yellowBackgroundLampDARef();
    quint16* whiteBackgroundLampDAPtr();
    quint16& centerInfraredLampDARef();
    quint16& borderInfraredLampDARef();
    quint16& eyeglassFrameLampDARef();
    quint16* environmentAlarmLightDAPtr();
    int* switchColorMotorCoordPtr();
    int* switchLightSpotMotorCoordPtr();
    qint32& focusCoordForSpotAndColorChangeRef();
    qint32& shutterOpenPosRef();
    qint32& mainTableCenterXCorrectionRef();
    qint32& mainTableCenterYCorrectionRef();
    qint32& secondaryTableCenterXCorrectionRef();
    qint32& secondaryTableCenterYCorrectionRef();
    qint32& maximunProjectionLightADPresetRef();
    qint32& xMotorCoordForLightCorrectionRef();
    qint32& yMotorCoordForLightCorrectionRef();
    int* focalLengthMotorCoordForDiamondCenterTestPtr();
    int(*focalLengthMotorCoordMappingPtr())[7];
    int(*DbCoordMappingPtr())[2];
    int* stepTimePtr();
    float& stepLengthRef();
private:
    void *m_obj;
};



}

Q_DECLARE_METATYPE(UsbDev::Config)
#endif
