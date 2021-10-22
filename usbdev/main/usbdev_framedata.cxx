#ifndef USBDEV_FRAMEDATA_CXX
#define USBDEV_FRAMEDATA_CXX

#include "usbdev/common/usbdev_def.h"
#include "usbdev/common/usbdev_pimplprivtemp.hpp"
#include "usbdev_framedata.hxx"
#include "usbdev_profile.hxx"

namespace UsbDev {

// ////////////////////////////////////////////////////////////////////////////
// register in Qt Meta system
// ////////////////////////////////////////////////////////////////////////////
static bool g_is_reg = false;
static void gRegInQt ( )
{
    if ( ! g_is_reg ) {
        qRegisterMetaType<UsbDev::FrameData>(); g_is_reg = true;
    }
}

// ////////////////////////////////////////////////////////////////////////////
// private object
// ////////////////////////////////////////////////////////////////////////////
#define T_PrivPtr( o )  usbdev_objcast( FrameDataPriv *, o )
class USBDEV_HIDDEN  FrameDataPriv : public PImplPrivTemp< FrameDataPriv >{
private:
    quint32     m_crc_veryfication,
                m_time_stamp;
    bool        m_shutter_status;
    quint16     m_stimulate_dot_serial_number;
    qint32      m_x_motor_coordinate,
                m_y_motor_coordinate;
    QByteArray  m_raw_data;
public :
    explicit FrameDataPriv ();
    explicit FrameDataPriv (const Profile& );
    FrameDataPriv ( const FrameDataPriv & );
    virtual ~FrameDataPriv( ) Q_DECL_OVERRIDE { }
//    void      init( const QByteArray &);

    inline auto crcVeryficationRef()            -> quint32&     { return m_crc_veryfication; }
    inline auto timeStampRef()                  -> quint32&     { return m_time_stamp; }
    inline auto shutterStatusRef()              -> bool&        { return m_shutter_status;}
    inline auto stimulateDotSerialNumberRef()   -> quint16&     { return m_stimulate_dot_serial_number;}
    inline auto xMotorCoordinateRef()           -> qint32&      { return m_x_motor_coordinate;}
    inline auto yMotorCoordinateRef()           -> qint32&      { return m_y_motor_coordinate;}
    inline auto rawDataRef()                    -> QByteArray&  { return m_raw_data; }
};

// ============================================================================
// ctor
// ============================================================================
FrameDataPriv :: FrameDataPriv ( )
{
    m_crc_veryfication=0;
    m_time_stamp = 0;
    m_shutter_status=false;
    m_stimulate_dot_serial_number=0;
    m_x_motor_coordinate=0;
    m_y_motor_coordinate=0;
    m_raw_data = QByteArray();
}

// ============================================================================
// ctor
// ============================================================================
FrameDataPriv :: FrameDataPriv (const Profile& profile )
{
    m_crc_veryfication=0;
    m_time_stamp = 0;
    m_shutter_status=false;
    m_stimulate_dot_serial_number=0;
    m_x_motor_coordinate=0;
    m_y_motor_coordinate=0;
    m_raw_data = QByteArray();
    int size=profile.videoSize().width()*profile.videoSize().height();
    m_raw_data.resize(size);
}

// ============================================================================
// ctor ( copy )
// ============================================================================
FrameDataPriv :: FrameDataPriv ( const FrameDataPriv &o )
{
    m_crc_veryfication=o.m_crc_veryfication;
    m_time_stamp = o.m_time_stamp;
    m_shutter_status=o.m_shutter_status;
    m_stimulate_dot_serial_number=o.m_stimulate_dot_serial_number;
    m_x_motor_coordinate=o.m_x_motor_coordinate;
    m_y_motor_coordinate=o.m_y_motor_coordinate;
    m_raw_data = o.m_raw_data;
}

// ////////////////////////////////////////////////////////////////////////////
// help function
// ////////////////////////////////////////////////////////////////////////////
static qint32  gReadData_Le_I32( const unsigned char *buff )
{
    return  (  int( buff[0] ) & 255 ) | (( int( buff[1]) & 255 ) << 8 ) |
            (( int( buff[2] ) & 255 ) << 16 ) | (( int( buff[3]) & 255 ) << 24 );
}


static qint16  gReadData_Le_I16( const unsigned char *buff )
{
    return  qint16( ( int( buff[0] ) & 255 ) | (( int( buff[1] ) & 255 ) << 8 ));
}


// ////////////////////////////////////////////////////////////////////////////
// wrap API
// ////////////////////////////////////////////////////////////////////////////
// ============================================================================
// ctor
// ============================================================================
FrameData :: FrameData ( )
{ gRegInQt(); m_obj = nullptr; }

// =============================================================================
// ctor ( copy )
// =============================================================================
FrameData :: FrameData ( const FrameData &o )
{
    gRegInQt(); m_obj = nullptr;
    FrameDataPriv::attach( &m_obj, const_cast<void**>( & o.m_obj ));
}

// =============================================================================
// assign
// =============================================================================
FrameData &  FrameData :: operator = ( const FrameData &o )
{
    gRegInQt();
    FrameDataPriv::attach( & m_obj, const_cast<void**>( & o.m_obj ));
    return *this;
}

// ============================================================================
// dtor
// ============================================================================
FrameData :: ~FrameData( )
{
    if ( m_obj != nullptr ) {
        FrameDataPriv::attach( & m_obj, nullptr );
    }
}

// ============================================================================
// ctor (build )
// ============================================================================
FrameData :: FrameData ( const QByteArray &ba)
{
    gRegInQt(); m_obj = nullptr;
    void *d = nullptr;
    FrameDataPriv::buildIfNull( & d );
    auto* priv=T_PrivPtr( d );
    const unsigned char *buff = reinterpret_cast<const unsigned char*>( ba.constData());
    priv->crcVeryficationRef()=gReadData_Le_I32(&buff[0]);
    priv->timeStampRef()=gReadData_Le_I32(&buff[4]);
    priv->shutterStatusRef()=buff[8];
    priv->xMotorCoordinateRef()=gReadData_Le_I32(&buff[12]);
    priv->yMotorCoordinateRef()=gReadData_Le_I32(&buff[16]);
    quint8* data=(quint8*)priv->rawDataRef().data();
    size_t size=priv->rawDataRef().size();
    memcpy(data,&buff[20],20);
    memcpy(&data[20],&buff[20],size-20);
    m_obj = d;
}


// ============================================================================
// method access
// ============================================================================
bool      FrameData :: isEmpty() const
{ return ( m_obj == nullptr ); }

quint32    FrameData :: timeStamp( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->timeStampRef() : 0 ); }

quint16   FrameData::shutterStatus() const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->shutterStatusRef() : 0 ); }

quint16   FrameData::stimulateDotSerialNumber() const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->stimulateDotSerialNumberRef() : 0 ); }

qint32   FrameData::xMotorCoordinate() const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->xMotorCoordinateRef() : 0 ); }

qint32   FrameData::yMotorCoordinate() const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->yMotorCoordinateRef() : 0 ); }

QByteArray  FrameData :: rawData( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->rawDataRef() : QByteArray()); }


}

#endif
