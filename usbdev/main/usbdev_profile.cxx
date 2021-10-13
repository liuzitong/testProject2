#ifndef USBDEV_PROFILE_CXX
#define USBDEV_PROFILE_CXX

#include <QString>
#include "usbdev_profile.hxx"
#include "usbdev/common/usbdev_pimplprivtemp.hpp"
#include <QMetaType>
#include <QStringList>

namespace UsbDev {

// ////////////////////////////////////////////////////////////////////////////
// register in Qt Meta system
// ////////////////////////////////////////////////////////////////////////////
static bool g_is_reg = false;
static void gRegInQt ( )
{
    if ( ! g_is_reg ) {
        qRegisterMetaType<UsbDev::Profile>(); g_is_reg = true;
    }
}
static bool g_is_be_order = false;

// ////////////////////////////////////////////////////////////////////////////
// private object
// ////////////////////////////////////////////////////////////////////////////
#define T_PrivPtr( o )  usbdev_objcast( ProfilePriv*, o )
class USBDEV_HIDDEN ProfilePriv : public PImplPrivTemp<ProfilePriv > {
private:
    QString  m_dev_ver; bool m_is_front_video_comb, m_is_be_order;
    uint     m_dev_maj;
    QSize    m_front_video_size;
    qintptr  m_front_video_row_pitch;
    QPair<qint32,qint32>  m_x_motor_range, m_y_motor_range, m_z_motor_range, m_focus_motor_range,
                          m_chin_motor_range, m_spectra_motor_range, m_light_motor_range, m_sample_motor_range;
    QPair<qint32,qint32>  m_vibra_mirror_x_ad_range, m_vibra_mirror_y_ad_range;
    QPair<qint32,qint32>  m_fixat_lamp_x_range, m_fixat_lamp_y_range;
    QPair<qint32,qint32>  m_global_accel_param_range;
    quint8  m_dbl_cam_code, m_intr_cam_code, m_3d_plat_code, m_phys_key_cnt;
    bool    m_has_ext_ver_info;
public :
    ProfilePriv ( );
    ProfilePriv ( const ProfilePriv & );
    virtual ~ProfilePriv( ) Q_DECL_OVERRIDE;

    inline auto  devMajRef( )          ->uint&       { return m_dev_maj; }      // since 0.3.0
    inline auto  devVerRef( )          ->QString&    { return m_dev_ver; }
    inline auto  isFrontVideoCombRef() ->bool&       { return m_is_front_video_comb; }
    inline auto  isBeOrderRef()        ->bool&       { return m_is_be_order; }
    inline auto  frontVideoSizeRef()   ->QSize &     { return m_front_video_size; }
    inline auto  frontVideoRowPitchRef() -> qintptr& { return m_front_video_row_pitch; }
    inline auto  hasExtVerInfoRef()    -> bool &     { return m_has_ext_ver_info; }
    inline auto  dblCamCodeRef()       -> quint8 &   { return m_dbl_cam_code; }
    inline auto  intrCamCodeRef()      -> quint8 &   { return m_intr_cam_code; }
    inline auto  d3PlatCodeRef()       -> quint8 &   { return m_3d_plat_code;  }
    inline auto  physKeyCntRef()       -> quint8 &   { return m_phys_key_cnt;  } // since 0.3.0
    inline auto  xMotorRangeRef()           -> QPair<qint32,qint32>& { return m_x_motor_range; }
    inline auto  yMotorRangeRef()           -> QPair<qint32,qint32>& { return m_y_motor_range; }
    inline auto  zMotorRangeRef()           -> QPair<qint32,qint32>& { return m_z_motor_range; }
    inline auto  focusMotorRangeRef()       -> QPair<qint32,qint32>& { return m_focus_motor_range; }
    inline auto  chinMotorRangeRef()        -> QPair<qint32,qint32>& { return m_chin_motor_range; }
    inline auto  spectraMotorRangeRef()     -> QPair<qint32,qint32>& { return m_spectra_motor_range; }
    inline auto  lightMotorRangeRef()       -> QPair<qint32,qint32>& { return m_light_motor_range; }
    inline auto  sampleMotorRangeRef()      -> QPair<qint32,qint32>& { return m_sample_motor_range; }
    inline auto  vibraMirrorXadRangeRef()   -> QPair<qint32,qint32>& { return m_vibra_mirror_x_ad_range; }
    inline auto  vibraMirrorYadRangeRef()   -> QPair<qint32,qint32>& { return m_vibra_mirror_y_ad_range; }
    inline auto  fixatLampXRangeRef()       -> QPair<qint32,qint32>& { return m_fixat_lamp_x_range; }
    inline auto  fixatLampYRangeRef()       -> QPair<qint32,qint32>& { return m_fixat_lamp_y_range; }
    inline auto  globalAccelParamRangeRef() -> QPair<qint32,qint32>& { return m_global_accel_param_range; }
};

ProfilePriv :: ~ProfilePriv ( ) { }

// ============================================================================
// ctor
// ============================================================================
ProfilePriv :: ProfilePriv ( )
{
    m_is_be_order = false;
    m_is_front_video_comb = false;
    m_front_video_size = QSize(0,0);
    m_front_video_row_pitch = 0;

    QPair<qint32,qint32> tmp_range(0,0);
    m_x_motor_range    = tmp_range;  m_y_motor_range = tmp_range;
    m_z_motor_range    = tmp_range;  m_focus_motor_range = tmp_range;
    m_chin_motor_range = tmp_range;  m_spectra_motor_range = tmp_range;
    m_light_motor_range = tmp_range; m_sample_motor_range  = tmp_range;
    m_vibra_mirror_x_ad_range = tmp_range; m_vibra_mirror_y_ad_range = tmp_range;
    m_fixat_lamp_x_range = tmp_range; m_fixat_lamp_y_range = tmp_range;
    m_global_accel_param_range = tmp_range;

    m_has_ext_ver_info = false;
    m_dbl_cam_code  = 0;
    m_intr_cam_code = 0;
    m_3d_plat_code  = 0;
    m_phys_key_cnt  = 0; // since 0.3.0
    m_dev_maj       = 0; // since 0.3.0

}

// ============================================================================
// ctor( copy )
// ============================================================================
ProfilePriv :: ProfilePriv ( const ProfilePriv &o )
{
    m_dev_ver = o.m_dev_ver;
    m_is_front_video_comb = o.m_is_front_video_comb;
    m_is_be_order         = o.m_is_be_order;
    m_front_video_size    = o.m_front_video_size;
    m_front_video_row_pitch = o.m_front_video_row_pitch;

    m_x_motor_range = o.m_x_motor_range;
    m_y_motor_range = o.m_y_motor_range;
    m_z_motor_range = o.m_z_motor_range;
    m_focus_motor_range = o.m_focus_motor_range;
    m_chin_motor_range  = o.m_chin_motor_range;
    m_spectra_motor_range = o.m_spectra_motor_range;
    m_light_motor_range   = o.m_light_motor_range;
    m_sample_motor_range  = o.m_sample_motor_range;

    m_vibra_mirror_x_ad_range = o.m_vibra_mirror_x_ad_range;
    m_vibra_mirror_y_ad_range = o.m_vibra_mirror_y_ad_range;

    m_fixat_lamp_x_range = o.m_fixat_lamp_x_range;
    m_fixat_lamp_y_range = o.m_fixat_lamp_y_range;

    m_global_accel_param_range = o.m_global_accel_param_range;

    m_has_ext_ver_info = o.m_has_ext_ver_info;
    m_dbl_cam_code     = o.m_dbl_cam_code;
    m_intr_cam_code    = o.m_intr_cam_code;
    m_3d_plat_code     = o.m_3d_plat_code;
    m_phys_key_cnt      = o.m_phys_key_cnt;  // since 0.3.0
    m_dev_maj          = o.m_dev_maj;        // since 0.3.0
}

// ////////////////////////////////////////////////////////////////////////////
// help function
// ////////////////////////////////////////////////////////////////////////////
static qint32  gReadData_Le_I32( const unsigned char *buff )
{
    return  (  int( buff[0] ) & 255 ) | (( int( buff[1]) & 255 ) << 8 ) |
            (( int( buff[2] ) & 255 ) << 16 ) | (( int( buff[3]) & 255 ) << 24 );
}

static qint32  gReadData_Be_I32( const unsigned char *buff )
{
     return  (  int( buff[3] ) & 255 ) | (( int( buff[2]) & 255 ) << 8 ) |
            (( int( buff[1] ) & 255 ) << 16 ) | (( int( buff[0]) & 255 ) << 24 );
}

static qint16  gReadData_Le_I16( const unsigned char *buff )
{
    return  qint16( ( int( buff[0] ) & 255 ) | (( int( buff[1] ) & 255 ) << 8 ));
}

static qint16  gReadData_Be_I16( const unsigned char *buff )
{
    return  qint16( ( int( buff[1] ) & 255 ) | (( int( buff[0] ) & 255 ) << 8 ));
}

static qint32  gReadData_I32( const unsigned char *buff, bool is_be )
{   return ( is_be ?  gReadData_Be_I32( buff ) : gReadData_Le_I32( buff )); }

static qint32  gReadData_I16( const unsigned char *buff, bool is_be )
{   return ( is_be ?  gReadData_Be_I16( buff ) : gReadData_Le_I16( buff )); }


// ////////////////////////////////////////////////////////////////////////////
// wrap API
// ////////////////////////////////////////////////////////////////////////////
// ============================================================================
//  ctor ( empty )
// ============================================================================
Profile :: Profile ( )
{ gRegInQt(); m_obj = nullptr; }

// ============================================================================
//  ctor ( copy  )
// ============================================================================
Profile :: Profile ( const Profile &o )
{
    gRegInQt();  m_obj = nullptr;
    ProfilePriv::attach( &m_obj, const_cast<void**>( & o.m_obj));
}

// ============================================================================
//  assign
// ============================================================================
Profile &  Profile :: operator=( const Profile &o )
{
    gRegInQt();
    ProfilePriv::attach( &m_obj, const_cast<void**>( & o.m_obj));
    return *this;
}

// ============================================================================
// dtor
// ============================================================================
Profile :: ~Profile ( )
{
    if ( m_obj != nullptr ) {
        ProfilePriv::attach( &m_obj, nullptr );
    }
}

// ============================================================================
// ctor ( consturct by data )
// ============================================================================
Profile :: Profile ( const QByteArray &ba )
{
    gRegInQt(); m_obj = nullptr;
    if ( ba.size() < 512 ) { return; }

    // ------------------------------------------------------------------------
    // build data
    // ------------------------------------------------------------------------
    void *d = nullptr;
    const unsigned char *buff = reinterpret_cast<const unsigned char*>( ba.constData());
    ProfilePriv::buildIfNull( & d );
    auto *priv = T_PrivPtr( d );

    if ( buff[0] == 0xff && buff[1] == 0xff ) {
        priv->devVerRef() = QString("%1.%2").arg( uint(buff[96] )).arg( uint(buff[97]));
        priv->hasExtVerInfoRef() = true;
        priv->devMajRef() = uint( buff[96] );
    } else {
        priv->devVerRef() = QString("%1.%2").arg( uint(buff[0]) ).arg( uint( buff[1]));
        priv->hasExtVerInfoRef() = false;
        priv->devMajRef() = uint( buff[0] );
    }

    priv->isFrontVideoCombRef() = ( ( buff[2] & 1 ) != 0 );
    bool is_be = priv->isBeOrderRef() = ( ( buff[2] & 2 ) != 0 );
    g_is_be_order = is_be;

    priv->frontVideoSizeRef() = QSize(
        gReadData_I16( & buff[4], is_be ), gReadData_I16( & buff[6], is_be )
    );
    priv->frontVideoRowPitchRef() =  gReadData_I32( & buff[8], is_be );

    priv->chinMotorRangeRef() = QPair<qint32,qint32> (
        gReadData_I32( & buff[12], is_be ), gReadData_I32( & buff[16], is_be )
    );
    priv->xMotorRangeRef() = QPair<qint32,qint32> (
        gReadData_I32( & buff[20], is_be ), gReadData_I32( & buff[24], is_be )
    );
    priv->yMotorRangeRef() = QPair<qint32,qint32> (
        gReadData_I32( & buff[28], is_be ), gReadData_I32( & buff[32], is_be )
    );
    priv->zMotorRangeRef() = QPair<qint32,qint32> (
        gReadData_I32( & buff[36], is_be ), gReadData_I32( & buff[40], is_be )
    );

    priv->focusMotorRangeRef() = QPair<qint32,qint32> (
        gReadData_I32( & buff[44], is_be ), gReadData_I32( & buff[48], is_be )
    );
    priv->spectraMotorRangeRef() = QPair<qint32,qint32> (
        gReadData_I32( & buff[52], is_be ), gReadData_I32( & buff[56], is_be )
    );
    priv->lightMotorRangeRef() = QPair<qint32,qint32> (
        gReadData_I32( & buff[60], is_be ), gReadData_I32( & buff[64], is_be )
    );
    priv->sampleMotorRangeRef() = QPair<qint32,qint32> (
        gReadData_I32( & buff[68], is_be ), gReadData_I32( & buff[72], is_be )
    );

    priv->vibraMirrorXadRangeRef() = QPair<qint32,qint32> (
        gReadData_I16( & buff[76], is_be ), gReadData_I16( & buff[78], is_be )
    );
    priv->vibraMirrorYadRangeRef() = QPair<qint32,qint32> (
        gReadData_I16( & buff[80], is_be ), gReadData_I16( & buff[82], is_be )
    );

    priv->fixatLampXRangeRef() = QPair<qint32,qint32> (
        gReadData_I16( & buff[84], is_be ), gReadData_I16( & buff[86], is_be )
    );
    priv->fixatLampYRangeRef() = QPair<qint32,qint32> (
        gReadData_I16( & buff[88], is_be ), gReadData_I16( & buff[90], is_be )
    );
    priv->globalAccelParamRangeRef() = QPair<qint32,qint32>(
        gReadData_I16( & buff[92], is_be ), gReadData_I16( & buff[94], is_be )
    );

    // added since 0.2.0
    if ( priv->hasExtVerInfoRef()) {
        priv->dblCamCodeRef()  = buff[100];
        priv->intrCamCodeRef() = buff[101];
        priv->d3PlatCodeRef()  = buff[102];
    }
    if ( priv->hasExtVerInfoRef() && priv->devMajRef() >= 0x40 ) {
        priv->physKeyCntRef()   = buff[103];
    }

    m_obj = d;
}

// ============================================================================
// method access
// ============================================================================
bool       Profile :: isEmpty() const { return ( m_obj == nullptr ); }

QString    Profile :: devVersion( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->devVerRef() : QString() ); }

bool       Profile :: isBeOrder() const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->isBeOrderRef() : g_is_be_order ); }

bool       Profile :: isFrontVideoCombined( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->isFrontVideoCombRef() : false ); }

QSize      Profile :: frontVideoSize( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->frontVideoSizeRef() : QSize()); }

qintptr    Profile :: frontVideoRowPitch( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->frontVideoRowPitchRef() : 0 ); }

QPair<qint32,qint32>  Profile :: motorRange( DevCtl::MotorId mot_id ) const
{
    if ( m_obj == nullptr ) { return QPair<qint32,qint32>(0,0); }
    switch( mot_id ) {
    case DevCtl::MotorId_X : return T_PrivPtr( m_obj )->xMotorRangeRef();
    case DevCtl::MotorId_Y : return T_PrivPtr( m_obj )->yMotorRangeRef();
    case DevCtl::MotorId_Z : return T_PrivPtr( m_obj )->zMotorRangeRef();
    case DevCtl::MotorId_Focus : return T_PrivPtr( m_obj )->focusMotorRangeRef();
    case DevCtl::MotorId_Chinrests : return T_PrivPtr( m_obj )->chinMotorRangeRef();
    case DevCtl::MotorId_Spectra : return T_PrivPtr( m_obj )->spectraMotorRangeRef();
    case DevCtl::MotorId_Light   : return T_PrivPtr( m_obj )->lightMotorRangeRef();
    default: return T_PrivPtr( m_obj )->sampleMotorRangeRef();
    }
}

QPair<qint32,qint32>  Profile :: vibraMirrorXadRange( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->vibraMirrorXadRangeRef() : QPair<qint32,qint32>(0,0)); }

QPair<qint32,qint32>  Profile :: vibraMirrorYadRange( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->vibraMirrorYadRangeRef() : QPair<qint32,qint32>(0,0)); }

QPair<qint32,qint32>  Profile :: fixatLampXRange( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->fixatLampXRangeRef() : QPair<qint32,qint32>(0,0)); }

QPair<qint32,qint32>  Profile :: fixatLampYRange( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->fixatLampYRangeRef() : QPair<qint32,qint32>(0,0)); }

QPair<qint32,qint32>  Profile :: globalAccelParamRange( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->globalAccelParamRangeRef() : QPair<qint32,qint32>(0,0)); }

bool       Profile :: hasExtVerInfo() const
{ return ( m_obj != nullptr ? T_PrivPtr(m_obj)->hasExtVerInfoRef() : false ); }

quint8     Profile :: dblCamCode() const
{ return ( m_obj != nullptr ? T_PrivPtr(m_obj)->dblCamCodeRef() : 0xff ); }

quint8     Profile :: intrCamCode() const
{ return ( m_obj != nullptr ? T_PrivPtr(m_obj)->intrCamCodeRef() : 0xff ); }

quint8     Profile :: d3PlatCode() const
{ return ( m_obj != nullptr ? T_PrivPtr(m_obj)->d3PlatCodeRef() : 0xff ); }

quint8     Profile :: physKeyCount() const
{ return ( m_obj != nullptr ? T_PrivPtr(m_obj)->physKeyCntRef() : 0 ); }

bool       Profile :: hasPhysKey() const
{ return ( m_obj != nullptr ? T_PrivPtr(m_obj)->hasExtVerInfoRef() && T_PrivPtr(m_obj)->devMajRef() >= 0x40 : false ); }

auto     Profile :: isX07Dev() const  -> bool
{ return ( m_obj != nullptr ? T_PrivPtr(m_obj)->devMajRef() >= 0x30 : false ); }


// ============================================================================
// make all profile as json object
// ============================================================================
QJsonObject  Profile :: toJsonObject( ) const
{
    QJsonObject jo;
    if ( isEmpty() ) { return jo; }

    jo.insert( QStringLiteral("devVerStr"), T_PrivPtr( m_obj )->devVerRef() );
    jo.insert( QStringLiteral("isFrontVideoCombined"), T_PrivPtr( m_obj )->isFrontVideoCombRef() );

    { // front video width and height
        QJsonObject jo2; QSize sz = T_PrivPtr( m_obj )->frontVideoSizeRef();
        jo2.insert( QStringLiteral("width"),  sz.width() );
        jo2.insert( QStringLiteral("height"), sz.height());
        jo.insert( QStringLiteral("frontVideoSize"), jo2 );
    }

    jo.insert( QStringLiteral("frontVideoRowPitch"), int( T_PrivPtr( m_obj )->frontVideoRowPitchRef() ));

    { // make all motor range value
        QStringList mot_list; ProfilePriv *pp = T_PrivPtr( m_obj );
        mot_list << "xMotorRange"    << "yMotorRange" << "zMotorRange" << "focusMotorRange"
                 << "chinMotorRange" << "spectraMotorRange" << "ligthMotorRange" << "sampleMotorRange";
        QList<QPair<qint32,qint32>> rg_list;
        rg_list << pp->xMotorRangeRef() << pp->yMotorRangeRef() << pp->zMotorRangeRef() << pp->focusMotorRangeRef()
                << pp->chinMotorRangeRef() << pp->spectraMotorRangeRef() << pp->lightMotorRangeRef() << pp->sampleMotorRangeRef();
        int sz = mot_list.size();
        for ( int i = 0; i < sz; i ++ ) {
            QJsonObject jo2;
            jo2.insert( QStringLiteral("min"), rg_list.at(i).first  );
            jo2.insert( QStringLiteral("max"), rg_list.at(i).second );
            jo.insert( mot_list.at(i), jo2 );
        }
    }

    {  // vibra mirror x ad
        QJsonObject jo2;
        jo2.insert( QStringLiteral("min"), T_PrivPtr( m_obj )->vibraMirrorXadRangeRef().first  );
        jo2.insert( QStringLiteral("max"), T_PrivPtr( m_obj )->vibraMirrorXadRangeRef().second );
        jo.insert( QStringLiteral("vibraMirrorXadRange"), jo2 );
    }
    {  // vibra mirror y ad
        QJsonObject jo2;
        jo2.insert( QStringLiteral("min"), T_PrivPtr( m_obj )->vibraMirrorYadRangeRef().first  );
        jo2.insert( QStringLiteral("max"), T_PrivPtr( m_obj )->vibraMirrorYadRangeRef().second );
        jo.insert( QStringLiteral("vibraMirrorYadRange"), jo2 );
    }
    {  // global accel param range
        QJsonObject jo2;
        jo2.insert( QStringLiteral("min"), T_PrivPtr( m_obj )->globalAccelParamRangeRef().first );
        jo2.insert( QStringLiteral("max"), T_PrivPtr( m_obj )->globalAccelParamRangeRef().second);
        jo.insert( QStringLiteral("globalAccelParamRange"), jo2 );
    }

    { // extend version information
        jo.insert( QStringLiteral("hasExtVerInfo"), T_PrivPtr(m_obj)->hasExtVerInfoRef());
        jo.insert( QStringLiteral("dblCamCode"),    T_PrivPtr(m_obj)->dblCamCodeRef());
        jo.insert( QStringLiteral("intrCamCode"), T_PrivPtr(m_obj)->intrCamCodeRef());
        jo.insert( QStringLiteral("d3PlatCode"),  T_PrivPtr(m_obj)->d3PlatCodeRef());
        jo.insert( QStringLiteral("physKeyCnt"),  T_PrivPtr(m_obj)->physKeyCntRef());
        jo.insert( QStringLiteral("hasPhysKey"),  hasPhysKey() );
    }

    return jo;
}

// ============================================================================
// [ static ] check it is be order
// ============================================================================
bool  Profile :: isBeOrderStatic() { return g_is_be_order; }

}

#endif
