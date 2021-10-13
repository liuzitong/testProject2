#ifndef USBDEV_FRAMEDATA_HXX
#define USBDEV_FRAMEDATA_HXX

#include "usbdev/common/usbdev_def.h"
#include <QByteArray>
#include <QMetaType>
#include <QImage>
#include <QSize>

namespace UsbDev {

class Profile;

// ////////////////////////////////////////////////////////////////////////////
/*!
 * @brief the front video frame data
 */
// ////////////////////////////////////////////////////////////////////////////
class USBDEV_API  FrameData {
public:
    //! ctor
    explicit FrameData ( );

    //! ctor by raw data
    //! @param ba [in] the raw data
    //! @param pf [in] the profile that spec. video width, height and format...
    //! @note this CTOR is called inside DevCtl, user should not use it.
    FrameData ( const QByteArray &ba, const Profile &pf, const qint64 &tm );

    //! ctor ( construct )
    FrameData ( const FrameData & );

    //! assign
    FrameData & operator = ( const FrameData & );

    //! dtor
    virtual   ~FrameData( );

    //! check if it is empty
    bool        isEmpty( ) const;

    //! return the time stamp of this frame data
    //! @note the empty FrameData will return 0
    qint64      timeStamp( ) const;

    //! return the raw data
    //! @return if OK, return object is not empty
    //! @note user should check return object whether if it is empty.
    //! @note the empty FrameData will return empty QByteArray()
    QByteArray  rawData( ) const;

    //! return the holde video size
    //! @note the empty FrameData will return QSize(0,0)
    QSize       rectSize( ) const;

    //! return the video row pitch in bytes
    //! @note the empty FrameData will return 0
    qintptr     rowPitch( ) const;

    //! format
    //! @note the empty FrameData will return QImage::Format_Invalid
    QImage::Format  format( ) const;

    //! check if the front video is right first
    bool   isRightFirstAtRawData( ) const;

    //! check if is right and left combined,
    //! this means right is first, and follow left video
    bool   isRightAndLeftCombined( ) const;

private:
    void *m_obj;
};

}

Q_DECLARE_METATYPE(UsbDev::FrameData)

#endif
