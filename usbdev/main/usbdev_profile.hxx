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

#ifndef USBDEV_PROFILE_HXX
#define USBDEV_PROFILE_HXX

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
class USBDEV_API  Profile {
public:
   //! ctor
   explicit Profile ( );

   //! construct by spec. data
   Profile ( const QByteArray & );

   //! ctor ( construct )
   Profile ( const Profile & );

   //! ctor ( assign )
   Profile & operator = ( const Profile & );

   //! dtor
   virtual ~Profile( );

   //! check if it is empty
   bool     isEmpty( ) const;

   //! the device version string
   //! @note the format is "x.y"
   QString  devVersion( ) const;

   //! check if hardware is BE or LE order
   //! @note this is not affect all values of profile or status, just a \n
   //!   hint.
   // 2019/06/19 added by nw
   bool     isBeOrder( ) const;

   //! check if the video frame is combined
   bool     isFrontVideoCombined( ) const;


   //! return video frame size ( width, height )
   //! @note if video is combined, the height is two video height
   QSize    frontVideoSize( ) const;

   //! return the video width line pitch in bytes
   qintptr  frontVideoRowPitch( ) const;

   //! return the range of the chinresets
   QPair<qint32,qint32> motorRange( DevCtl::MotorId ) const;

   //! return the AD range of the Vibration Mirror X
   QPair<qint32,qint32> vibraMirrorXadRange( ) const;

   //! return the AD range of the vibration mirror Y
   QPair<qint32,qint32> vibraMirrorYadRange( ) const;

   //! return the fixation lamp X range
   QPair<qint32,qint32> fixatLampXRange( ) const;

   //! return the fixation lamp Y range
   QPair<qint32,qint32> fixatLampYRange( ) const;

   //! global accel. param. range
   // 20190619 added by nw
   QPair<qint32,qint32> globalAccelParamRange( ) const;

   //! to json object
   QJsonObject  toJsonObject( ) const;

   //! check if has extend version information
   //! @since 0.2.0
   //! @note if this is true, xxxCode() function will be usable.
   bool    hasExtVerInfo() const;

   //! return the double camera code
   //! @since 0.2.0
   //! @note require hasExtVerInfo() return true
   quint8  dblCamCode() const;

   //! return the interference camera code
   //! @since 0.2.0
   //! @note require hasExtVerInfo() return true
   quint8  intrCamCode() const;

   //! return the 3D platform code
   //! @since 0.2.0
   //! @note require hasExtVerInfo() return true
   quint8  d3PlatCode() const;

   //! return the phsyical key number
   //! @since 0.3.0
   //! @note require hasExtVerInfo() return true and devVersion() is "40.??"
   //!       device major version is 40 ( 0x28 )
   quint8  physKeyCount() const;

   //! check if has phys key
   //! @since 0.3.0
   bool    hasPhysKey() const;

   //! check if device is x07
   //! @since 0.4
   bool    isX07Dev() const;

   //! static function used to detect if device is LE
   static bool isBeOrderStatic();
private:
    void *m_obj;
};



}

Q_DECLARE_METATYPE(UsbDev::Profile)
#endif
