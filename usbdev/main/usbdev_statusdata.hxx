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

   // =========================================================================
   // motor attribute by ID
   // =========================================================================
   //! check if the motor busy
   bool      isMotorBusy( DevCtl::MotorId ) const;

   //! return the command cntr
   int       motorCmdCntr( DevCtl::MotorId ) const;

   //! current position of chinrests
   qint32    motorPosition( DevCtl::MotorId ) const;

   qint32 cacheNormalFlag() const;
   qint32 cacheMoveFlag() const;
   bool answerpadStatus() const;
   bool cameraStatus() const;
   bool envLightDA() const;
   bool castLightDA() const;
private:
    void *m_obj;
};


}
Q_DECLARE_METATYPE(UsbDev::StatusData)
#endif
