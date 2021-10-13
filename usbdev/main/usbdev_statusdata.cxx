#ifndef USBDEV_STATUSDATA_CXX
#define USBDEV_STATUSDATA_CXX

#include "usbdev_statusdata.hxx"
#include "usbdev/common/usbdev_pimplprivtemp.hpp"
#include "usbdev_profile.hxx"

#include <QMetaType>

namespace UsbDev {

// ////////////////////////////////////////////////////////////////////////////
// register in Qt Meta system
// ////////////////////////////////////////////////////////////////////////////
static bool g_is_reg = false;
static void gRegInQt ( )
{
    if ( ! g_is_reg ) {
        qRegisterMetaType<UsbDev::StatusData>(); g_is_reg = true;
    }
}

// ////////////////////////////////////////////////////////////////////////////
// motor item
// ////////////////////////////////////////////////////////////////////////////
class USBDEV_HIDDEN StatusData_MotorItem {
private:
    int  m_cmd_cntr, m_limit_flag; qint32 m_pos; bool m_is_busy, m_is_in_reset;
public :
    explicit StatusData_MotorItem( )
    {
        m_cmd_cntr = 0; m_limit_flag = false;
        m_pos = 0; m_is_busy = false; m_is_in_reset = false;
    }
    StatusData_MotorItem & operator = ( const StatusData_MotorItem &o )
    {
        m_cmd_cntr = o.m_cmd_cntr;  m_limit_flag = o.m_limit_flag;
        m_pos      = o.m_pos;       m_is_busy    = o.m_is_busy;
        m_is_in_reset = o.m_is_in_reset;
        return *this;
    }

    inline auto  cmdCntrRef()   -> int&    { return m_cmd_cntr; }
    inline auto  limitFlagRef() -> int&    { return m_limit_flag; }
    inline auto  positionRef()  -> qint32& { return m_pos; }
    inline auto  isBusyRef()    -> bool&   { return m_is_busy; }
    inline auto  isInResetRef() -> bool&   { return m_is_in_reset; }
};

// ////////////////////////////////////////////////////////////////////////////
// private object
// ////////////////////////////////////////////////////////////////////////////
#define T_PrivPtr( o )  usbdev_objcast( StatusDataPriv*, o  )
class USBDEV_HIDDEN StatusDataPriv : public PImplPrivTemp<StatusDataPriv> {
private:
    StatusData_MotorItem  m_x_motor, m_y_motor, m_z_motor, m_focus_motor,
            m_chin_motor, m_spectra_motor, m_light_motor, m_sample_motor;
    int  m_sn_no;
    qint32  m_sled_power, m_slo_power;
    qint32  m_vibra_mirror_x_ad, m_vibra_mirror_y_ad;
    bool m_is_front_video_opened, m_is_sled_power_normal, m_is_slo_power_normal;
    bool m_is_front_ir_lamp_on,   m_is_outer_fixat_lamp_on, m_is_fixat_lamp_on;
    QVector2D   m_is_fixat_lamp_coord;

public :
    explicit StatusDataPriv ( );
    StatusDataPriv ( const StatusDataPriv & );
    virtual ~StatusDataPriv( ) Q_DECL_OVERRIDE { }

    inline auto  snNoRef() -> int&  { return m_sn_no; }
    inline auto  isFrontVideoOpenedRef() -> bool& { return m_is_front_video_opened; }
    inline auto  isSLedPowerNormalRef()  -> bool& { return m_is_sled_power_normal; }
    inline auto  isFrontIrLampOnRef()    -> bool& { return m_is_front_ir_lamp_on;  }
    inline auto  isOuterFixatLampOnRef() -> bool& { return m_is_outer_fixat_lamp_on; }
    inline auto  isFixatLampOnRef()      -> bool& { return m_is_fixat_lamp_on; }
    inline auto  fixatLampCoordRef()     -> QVector2D& { return m_is_fixat_lamp_coord; }

    inline auto  sLedPowerRef()      -> qint32& { return m_sled_power; }
    inline auto  vibraMirrorXadRef() -> qint32& { return m_vibra_mirror_x_ad; }
    inline auto  vibraMirrorYadRef() -> qint32& { return m_vibra_mirror_y_ad; }
    inline auto  xMotorRef() -> StatusData_MotorItem& { return m_x_motor; }
    inline auto  yMotorRef() -> StatusData_MotorItem& { return m_y_motor; }
    inline auto  zMotorRef() -> StatusData_MotorItem& { return m_z_motor; }
    inline auto  focusMotorRef()   -> StatusData_MotorItem& { return m_focus_motor; }
    inline auto  chinMotorRef()    -> StatusData_MotorItem& { return m_chin_motor;  }
    inline auto  spectraMotorRef() -> StatusData_MotorItem& { return m_spectra_motor; }
    inline auto  lightMotorRef()   -> StatusData_MotorItem& { return m_light_motor; }
    inline auto  sampleMotorRef()  -> StatusData_MotorItem& { return m_sample_motor; }

    // since 0.4
    inline auto  isSLoPowerNormalRef() -> bool& { return m_is_slo_power_normal; }
    inline auto  sloPowerRef() -> qint32&       { return m_slo_power; }
};

// ============================================================================
// ctor
// ============================================================================
StatusDataPriv :: StatusDataPriv ( )
{
    m_sn_no = 0; m_is_sled_power_normal = true;  m_sled_power = 0;
    m_vibra_mirror_x_ad = m_vibra_mirror_y_ad = 0;
    m_is_front_video_opened = false;
    m_is_sled_power_normal = true;
    m_is_front_ir_lamp_on  = false; m_is_outer_fixat_lamp_on = false;
    m_is_fixat_lamp_on     = false;
    m_is_fixat_lamp_coord  = QVector2D(0,0);

    m_is_sled_power_normal = true;
    m_slo_power = 0;
}

// ============================================================================
// ctor( copy )
// ============================================================================
StatusDataPriv :: StatusDataPriv ( const StatusDataPriv &o )
{
    m_x_motor = o.m_x_motor;
    m_y_motor = o.m_y_motor;
    m_z_motor = o.m_z_motor;
    m_focus_motor = o.m_focus_motor;
    m_chin_motor  = o.m_chin_motor;
    m_spectra_motor = o.m_spectra_motor;
    m_light_motor   = o.m_light_motor;
    m_sample_motor  = o.m_sample_motor;

    m_sn_no = o.m_sn_no;
    m_is_sled_power_normal = o.m_is_sled_power_normal;
    m_sled_power= o.m_sled_power;
    m_vibra_mirror_x_ad = o.m_vibra_mirror_x_ad;
    m_vibra_mirror_y_ad = o.m_vibra_mirror_y_ad;

    m_is_front_video_opened = o.m_is_front_video_opened;
    m_is_sled_power_normal  = o.m_is_sled_power_normal;
    m_is_front_ir_lamp_on   = o.m_is_front_ir_lamp_on;
    m_is_outer_fixat_lamp_on = o.m_is_outer_fixat_lamp_on;
    m_is_fixat_lamp_on = o.m_is_fixat_lamp_on;

    m_is_fixat_lamp_coord = o.m_is_fixat_lamp_coord;

    // since 0.4
    m_is_slo_power_normal = o.m_is_slo_power_normal;
    m_slo_power = o.m_slo_power;
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
// ctor ( empty )
// ============================================================================
StatusData :: StatusData( ) { gRegInQt(); m_obj = nullptr; }

// ============================================================================
// ctor ( construct )
// ============================================================================
StatusData :: StatusData ( const StatusData &o )
{
    gRegInQt(); m_obj = nullptr;
    StatusDataPriv::attach( & m_obj, const_cast<void**>(& o.m_obj));
}

// ============================================================================
// ctor ( assign )
// ============================================================================
StatusData &  StatusData :: operator = ( const StatusData &o )
{
    gRegInQt();
    StatusDataPriv::attach( & m_obj, const_cast<void**>( & o.m_obj ));
    return *this;
}

// ============================================================================
// dtor
// ============================================================================
StatusData :: ~StatusData( )
{
    if ( m_obj != nullptr ) {
        StatusDataPriv::attach( & m_obj, nullptr );
    }
}

// ============================================================================
// load the data
// ============================================================================
StatusData :: StatusData ( const QByteArray &ba )
{
    gRegInQt(); m_obj = nullptr;
    if ( ba.size() < 512 ) { return; }

    // ------------------------------------------------------------------------
    // build data
    // ------------------------------------------------------------------------
    void *d = nullptr;
    const unsigned char *buff = reinterpret_cast<const unsigned char*>( ba.constData());
    StatusDataPriv::buildIfNull( & d );
    bool is_be = Profile::isBeOrderStatic();

    auto priv = T_PrivPtr( d );

    priv->snNoRef() = ( int( buff[0]) & 255 );
    priv->isFrontVideoOpenedRef() = ( buff[2] != 0 );
    priv->isSLedPowerNormalRef()  = ( buff[3] == 0 );
    priv->sLedPowerRef() = gReadData_Le_I32( & buff[4] );

    priv->chinMotorRef().isBusyRef()    = ( buff[8] != 0 );
    priv->xMotorRef().isBusyRef()       = ( buff[ 9] != 0 );
    priv->yMotorRef().isBusyRef()       = ( buff[10] != 0 );
    priv->zMotorRef().isBusyRef()       = ( buff[11] != 0 );
    priv->focusMotorRef().isBusyRef()   = ( buff[12] != 0 );
    priv->spectraMotorRef().isBusyRef() = ( buff[13] != 0 );
    priv->lightMotorRef().isBusyRef()   = ( buff[14] != 0 );
    priv->sampleMotorRef().isBusyRef()  = ( buff[15] != 0 );

    priv->chinMotorRef().isInResetRef() = ( buff[16] != 0 );
    priv->xMotorRef().isInResetRef()    = ( buff[17] != 0 );
    priv->yMotorRef().isInResetRef()    = ( buff[18] != 0 );
    priv->zMotorRef().isInResetRef()    = ( buff[19] != 0 );
    priv->focusMotorRef().isInResetRef()   = ( buff[20] != 0 );
    priv->spectraMotorRef().isInResetRef() = ( buff[21] != 0 );
    priv->lightMotorRef().isInResetRef()   = ( buff[22] != 0 );
    priv->sampleMotorRef().isInResetRef()  = ( buff[23] != 0 );

    priv->chinMotorRef().limitFlagRef() = int( buff[24] ) & 255;
    priv->xMotorRef().limitFlagRef()    = int( buff[25] ) & 255;
    priv->yMotorRef().limitFlagRef()    = int( buff[26] ) & 255;
    priv->zMotorRef().limitFlagRef()    = int( buff[27] ) & 255;
    priv->focusMotorRef().limitFlagRef() = int( buff[28] ) & 255;
    priv->spectraMotorRef().limitFlagRef() = int( buff[29] ) & 255;
    priv->lightMotorRef().limitFlagRef()   = int( buff[30] ) & 255;
    priv->sampleMotorRef().limitFlagRef()  = int( buff[31] ) & 255;

    priv->chinMotorRef().cmdCntrRef() = int( buff[32] ) & 255;
    priv->xMotorRef().cmdCntrRef()    = int( buff[33] ) & 255;
    priv->yMotorRef().cmdCntrRef()    = int( buff[34] ) & 255;
    priv->zMotorRef().cmdCntrRef()    = int( buff[35] ) & 255;
    priv->focusMotorRef().cmdCntrRef() = int( buff[36] ) & 255;
    priv->spectraMotorRef().cmdCntrRef()= int( buff[37] ) & 255;
    priv->lightMotorRef().cmdCntrRef() = int( buff[38] ) & 255;
    priv->sampleMotorRef().cmdCntrRef() = int( buff[39]) & 255;

    priv->chinMotorRef().positionRef() = gReadData_I32( & buff[40], is_be );
    priv->xMotorRef().positionRef()    = gReadData_I32( & buff[44], is_be );
    priv->yMotorRef().positionRef()    = gReadData_I32( & buff[48], is_be );
    priv->zMotorRef().positionRef()    = gReadData_I32( & buff[52], is_be );
    priv->focusMotorRef().positionRef()   = gReadData_I32( & buff[56], is_be );
    priv->spectraMotorRef().positionRef() = gReadData_I32( & buff[60], is_be );
    priv->lightMotorRef().positionRef()   = gReadData_I32( & buff[64], is_be );
    priv->sampleMotorRef().positionRef()  = gReadData_I32( & buff[68], is_be );

    priv->vibraMirrorXadRef() = gReadData_I16( & buff[72], is_be );
    priv->vibraMirrorYadRef() = gReadData_I16( & buff[74], is_be );

    priv->isFrontIrLampOnRef()    = ( buff[76] != 0 );
    priv->isOuterFixatLampOnRef() = ( buff[77] != 0 );
    priv->isFixatLampOnRef()      = ( buff[78] != 0 );

    priv->fixatLampCoordRef()     = QVector2D (
        gReadData_I16( & buff[80], is_be ), gReadData_I16( & buff[82], is_be )
    );

    // since 0.4
    priv->isSLoPowerNormalRef() = ( buff[88] == 0 );
    priv->sloPowerRef() = gReadData_I32( &buff[92], is_be );

    m_obj = d;
}

// ============================================================================
// method access
// ============================================================================
bool     StatusData :: isEmpty() const
{ return ( m_obj == nullptr ); }

int      StatusData :: serialNO( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->snNoRef() : 0 ); }

bool     StatusData :: isFrontVideoOpened( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->isFrontVideoOpenedRef() : false ); }

bool     StatusData :: isSLEDPowerNormal( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->isSLedPowerNormalRef() : true ); }

qint32   StatusData :: powerValueSLED( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->sLedPowerRef() : 0 ); }

bool     StatusData :: isMotorBusy( DevCtl::MotorId mot_id ) const
{
    if ( m_obj == nullptr ) { return false; }

    switch( mot_id ) {
    case DevCtl::MotorId_X : return T_PrivPtr( m_obj )->xMotorRef().isBusyRef();
    case DevCtl::MotorId_Y : return T_PrivPtr( m_obj )->yMotorRef().isBusyRef();
    case DevCtl::MotorId_Z : return T_PrivPtr( m_obj )->zMotorRef().isBusyRef();
    case DevCtl::MotorId_Focus : return T_PrivPtr( m_obj )->focusMotorRef().isBusyRef();
    case DevCtl::MotorId_Chinrests : return T_PrivPtr( m_obj )->chinMotorRef().isBusyRef();
    case DevCtl::MotorId_Spectra  :  return T_PrivPtr( m_obj )->spectraMotorRef().isBusyRef();
    case DevCtl::MotorId_Light : return T_PrivPtr( m_obj )->lightMotorRef().isBusyRef();
    default: return T_PrivPtr( m_obj )->sampleMotorRef().isBusyRef();
    }
}


bool     StatusData :: isMotorInResetPos( DevCtl::MotorId mot_id ) const
{
    if ( m_obj == nullptr ) { return false; }

    switch( mot_id ) {
    case DevCtl::MotorId_X : return T_PrivPtr( m_obj )->xMotorRef().isInResetRef();
    case DevCtl::MotorId_Y : return T_PrivPtr( m_obj )->yMotorRef().isInResetRef();
    case DevCtl::MotorId_Z : return T_PrivPtr( m_obj )->zMotorRef().isInResetRef();
    case DevCtl::MotorId_Focus : return T_PrivPtr( m_obj )->focusMotorRef().isInResetRef();
    case DevCtl::MotorId_Chinrests : return T_PrivPtr( m_obj )->chinMotorRef().isInResetRef();
    case DevCtl::MotorId_Spectra  :  return T_PrivPtr( m_obj )->spectraMotorRef().isInResetRef();
    case DevCtl::MotorId_Light : return T_PrivPtr( m_obj )->lightMotorRef().isInResetRef();
    default: return T_PrivPtr( m_obj )->sampleMotorRef().isInResetRef();
    }
}

int     StatusData :: motorLimitFlag( DevCtl::MotorId mot_id ) const
{
    if ( m_obj == nullptr ) { return false; }

    switch( mot_id ) {
    case DevCtl::MotorId_X : return T_PrivPtr( m_obj )->xMotorRef().limitFlagRef();
    case DevCtl::MotorId_Y : return T_PrivPtr( m_obj )->yMotorRef().limitFlagRef();
    case DevCtl::MotorId_Z : return T_PrivPtr( m_obj )->zMotorRef().limitFlagRef();
    case DevCtl::MotorId_Focus : return T_PrivPtr( m_obj )->focusMotorRef().limitFlagRef();
    case DevCtl::MotorId_Chinrests : return T_PrivPtr( m_obj )->chinMotorRef().limitFlagRef();
    case DevCtl::MotorId_Spectra  :  return T_PrivPtr( m_obj )->spectraMotorRef().limitFlagRef();
    case DevCtl::MotorId_Light : return T_PrivPtr( m_obj )->lightMotorRef().limitFlagRef();
    default: return T_PrivPtr( m_obj )->sampleMotorRef().limitFlagRef();
    }
}

int      StatusData :: motorCmdCntr( DevCtl::MotorId  mot_id ) const
{
    if ( m_obj == nullptr ) { return false; }

    switch( mot_id ) {
    case DevCtl::MotorId_X : return T_PrivPtr( m_obj )->xMotorRef().cmdCntrRef();
    case DevCtl::MotorId_Y : return T_PrivPtr( m_obj )->yMotorRef().cmdCntrRef();
    case DevCtl::MotorId_Z : return T_PrivPtr( m_obj )->zMotorRef().cmdCntrRef();
    case DevCtl::MotorId_Focus : return T_PrivPtr( m_obj )->focusMotorRef().cmdCntrRef();
    case DevCtl::MotorId_Chinrests : return T_PrivPtr( m_obj )->chinMotorRef().cmdCntrRef();
    case DevCtl::MotorId_Spectra  :  return T_PrivPtr( m_obj )->spectraMotorRef().cmdCntrRef();
    case DevCtl::MotorId_Light : return T_PrivPtr( m_obj )->lightMotorRef().cmdCntrRef();
    default: return T_PrivPtr( m_obj )->sampleMotorRef().cmdCntrRef();
    }
}

qint32   StatusData :: motorPosition( DevCtl::MotorId mot_id ) const
{
    if ( m_obj == nullptr ) { return false; }

    switch( mot_id ) {
    case DevCtl::MotorId_X : return T_PrivPtr( m_obj )->xMotorRef().positionRef();
    case DevCtl::MotorId_Y : return T_PrivPtr( m_obj )->yMotorRef().positionRef();
    case DevCtl::MotorId_Z : return T_PrivPtr( m_obj )->zMotorRef().positionRef();
    case DevCtl::MotorId_Focus : return T_PrivPtr( m_obj )->focusMotorRef().positionRef();
    case DevCtl::MotorId_Chinrests : return T_PrivPtr( m_obj )->chinMotorRef().positionRef();
    case DevCtl::MotorId_Spectra  :  return T_PrivPtr( m_obj )->spectraMotorRef().positionRef();
    case DevCtl::MotorId_Light : return T_PrivPtr( m_obj )->lightMotorRef().positionRef();
    default: return T_PrivPtr( m_obj )->sampleMotorRef().positionRef();
    }
}

qint32   StatusData :: vibraMirrorXad( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->vibraMirrorXadRef() : 0); }

qint32   StatusData :: vibraMirrorYad( ) const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->vibraMirrorYadRef() : 0 ); }

bool     StatusData :: isFrontIrLampOn() const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->isFrontIrLampOnRef() : false );}

bool     StatusData :: isOuterFixatLampOn() const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->isOuterFixatLampOnRef() : false ); }

bool     StatusData :: isFixatLampOn() const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->isFixatLampOnRef() : false ); }

QVector2D  StatusData :: fixatLampCoord() const
{ return ( m_obj != nullptr ? T_PrivPtr( m_obj )->fixatLampCoordRef() : QVector2D(0,0)); }

// since 0.4
auto     StatusData :: isSLOPowreNormal() const -> bool
{ return ( m_obj != nullptr ? T_PrivPtr(m_obj)->isSLoPowerNormalRef() : false ); }

// since 0.4
auto     StatusData :: powerValueSLO() const -> qint32
{ return ( m_obj != nullptr ? T_PrivPtr(m_obj)->sloPowerRef() : 0 ); }

}

#endif
