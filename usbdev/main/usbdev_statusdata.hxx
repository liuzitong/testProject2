#ifndef USBDEV_STATUSDATA_HXX
#define USBDEV_STATUSDATA_HXX

#include "usbdev/common/usbdev_def.h"
#include "usbdev/main/usbdev_devctl.hxx"
#include <QByteArray>
#include <QMetaType>
#include <QVector2D>

namespace UsbDev {

// ////////////////////////////////////////////////////////////////////////////
/*!
 * @brief the device status data
 */
// ////////////////////////////////////////////////////////////////////////////
class USBDEV_API  StatusData {
public:
   //! ctor empty object
   explicit StatusData( );

   //! ctor ( with data )
   StatusData( const QByteArray & );

   //! ctor ( construct )
   StatusData ( const StatusData & );

   //! ctor ( assign )
   StatusData &  operator = ( const StatusData & );

   //! dtor
   virtual ~StatusData( );

   //! check if it is empty
   bool      isEmpty( ) const;

   //! the serial no
   //! @note the serial NO. is changed every status data package
   int       serialNO( ) const;

   //! check if the front camera run
   bool      isFrontVideoOpened( ) const;

   //! check if the SLED over the limit Power
   bool      isSLEDPowerNormal( ) const;

   //! return the SLED Power value
   qint32    powerValueSLED( ) const;

   // =========================================================================
   // motor attribute by ID
   // =========================================================================
   //! check if the motor busy
   bool      isMotorBusy( DevCtl::MotorId ) const;

   //! check if the motor in rest position
   bool      isMotorInResetPos( DevCtl::MotorId ) const;

   //! check if the motor is in limit
   //! @return 0 means is not in limit, -1 means in negative limit, otherwise is in absolute limit
   int       motorLimitFlag( DevCtl::MotorId ) const;

   //! return the command cntr
   int       motorCmdCntr( DevCtl::MotorId ) const;

   //! current position of chinrests
   qint32    motorPosition( DevCtl::MotorId ) const;

   // =========================================================================
   // the vibra mirror
   // =========================================================================
   //! x ad
   qint32    vibraMirrorXad( ) const;

   //! y ad
   qint32    vibraMirrorYad( ) const;

   // =========================================================================
   // the lamp on/off
   // =========================================================================
   bool      isFrontIrLampOn   ( ) const;
   bool      isOuterFixatLampOn( ) const;
   bool      isFixatLampOn     ( ) const;
   QVector2D  fixatLampCoord   ( ) const;

   // =========================================================================
   // SLO ( added since 0.4 )
   // =========================================================================
   bool     isSLOPowreNormal() const;
   qint32   powerValueSLO() const;

private:
    void *m_obj;
};


}
Q_DECLARE_METATYPE(UsbDev::StatusData)
#endif
