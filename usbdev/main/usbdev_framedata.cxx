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
    qint64      m_tm_stamp;
    QByteArray  m_raw_data;
    QImage::Format  m_format;
    QSize  m_rect_sz; qintptr m_row_pitch;
    bool   m_is_combined, m_is_rigth_first;
public :
    explicit FrameDataPriv ( );
    FrameDataPriv ( const FrameDataPriv & );
    virtual ~FrameDataPriv( ) Q_DECL_OVERRIDE { }
    void      init( const QByteArray &, const Profile&, const qint64 &tm );

    inline qint64&   tmStampRef()     { return m_tm_stamp; }
    inline QByteArray &  rawDataRef() { return m_raw_data; }
    inline qintptr   rowPitch( )      { return m_row_pitch; }
    inline QImage::Format  format()   { return m_format; }
    inline QSize &   rectSizeRef()    { return m_rect_sz;  }
    inline bool      isCombined()     { return m_is_combined;    }
    inline bool      isRightFirst()   { return m_is_rigth_first; }
};

// ============================================================================
// ctor
// ============================================================================
FrameDataPriv :: FrameDataPriv ( )
{
    m_tm_stamp = 0;
    m_raw_data = QByteArray();
    m_format   = QImage::Format_Grayscale8;
    m_rect_sz  = QSize(0,0); m_row_pitch = 0;
    m_is_combined = m_is_rigth_first = false;
}

// ============================================================================
// ctor ( copy )
// ============================================================================
FrameDataPriv :: FrameDataPriv ( const FrameDataPriv &o )
{
    m_tm_stamp = o.m_tm_stamp;
    m_raw_data = o.m_raw_data; m_format = o.m_format;
    m_rect_sz  = o.m_rect_sz;  m_row_pitch = o.m_row_pitch;
    m_is_combined = o.m_is_combined; m_is_rigth_first = o.m_is_rigth_first;
}

// ============================================================================
// initialize
// ============================================================================
void  FrameDataPriv :: init( const QByteArray &ba, const Profile &pf, const qint64 &tm )
{
    if ( pf.isEmpty() ) { return; }
    m_tm_stamp = tm;

    m_is_combined = pf.isFrontVideoCombined();
    if ( m_is_combined ) { m_is_rigth_first = true; }

    m_row_pitch = pf.frontVideoRowPitch();
    m_rect_sz   = pf.frontVideoSize();

    // ------------------------------------------------------------------------
    // check if the format is 0 or other
    // ------------------------------------------------------------------------
    if ( ! ba.isEmpty() ) {
        if ( ba.size() >= m_row_pitch * m_rect_sz.height() ) {
            m_raw_data = ba;
        } else {
            m_raw_data = QByteArray();
        }
    } else {
        m_raw_data = QByteArray();
    }
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
FrameData :: FrameData ( const QByteArray &ba, const Profile &pf, const qint64 &tm )
{
    gRegInQt(); m_obj = nullptr;

    void *d = nullptr;
    FrameDataPriv::buildIfNull( & d );
    T_PrivPtr( d )->init( ba, pf, tm );

    m_obj = d;
}

// ============================================================================
// method access
// ============================================================================
bool      FrameData :: isEmpty() const
{ return ( m_obj == nullptr ); }

qint64    FrameData :: timeStamp( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->tmStampRef() : 0 ); }

QByteArray  FrameData :: rawData( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->rawDataRef() : QByteArray()); }

QSize       FrameData :: rectSize( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->rectSizeRef() : QSize(0,0)); }

qintptr     FrameData :: rowPitch( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->rowPitch() : 0 ); }

QImage::Format  FrameData :: format( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->format() : QImage::Format_Invalid ); }

bool       FrameData :: isRightFirstAtRawData( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->isRightFirst() : false ); }

bool       FrameData :: isRightAndLeftCombined( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->isCombined() : false ); }



}

#endif
