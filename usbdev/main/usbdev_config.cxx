#ifndef USBDEV_PROFILE_CXX
#define USBDEV_PROFILE_CXX

#include <QString>
#include "usbdev_config.hxx"
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
        qRegisterMetaType<UsbDev::Config>(); g_is_reg = true;
    }
}

// ////////////////////////////////////////////////////////////////////////////
// private object
// ////////////////////////////////////////////////////////////////////////////
#define T_PrivPtr( o )  usbdev_objcast( ConfigPriv*, o )
class USBDEV_HIDDEN ConfigPriv : public PImplPrivTemp<ConfigPriv > {
private:
    quint32                             m_crc_veryfication,
                                        m_device_ID;
    quint16                             m_center_fixation_lamp_DA,
                                        m_big_diamond_fixation_lamp_DA,
                                        m_small_diamond_fixation_lamp_DA,
                                        m_yellow_background_lamp_DA,
                                        m_white_background_lamp_DA[3],
                                        m_center_infrared_lamp_DA,
                                        m_border_infrared_lamp_DA,
                                        m_eyeglass_frame_lamp_DA,
                                        m_environment_light_alarm_DA[2];
    qint32                              m_switch_color_motor_coord[6],
                                        m_switch_light_spot_coord[8],
                                        m_focus_coord_for_sport_and_color_change,
                                        m_main_table_center_x_correction,
                                        m_main_table_center_y_correction,
                                        m_secondary_table_center_x_correction,
                                        m_secondary_table_center_y_correction,
                                        m_maximun_projection_light_AD_preset,
                                        m_x_motor_coord_for_light_correction,
                                        m_y_motor_coord_for_light_correction,
                                        m_focal_length_motor_coord_for_light_correction,
                                        m_x_motor_coord_for_diamond_center_test,
                                        m_y_motor_coord_for_diamond_center_test,
                                        m_focal_length_motor_coord_for_diamond_center_test[7],                  //7光斑
                                        m_focal_length_motor_coord_mapping[25][7],                              //25距离,7光斑
                                        m_Db_coord_mapping[52][2];                                              //0~51DB,颜色电机,光斑电机

public :
    ConfigPriv ( );
    ConfigPriv ( const ConfigPriv & );
    virtual ~ConfigPriv( ) Q_DECL_OVERRIDE;
    inline auto crcVeryficationRef( )                               -> quint32& {return m_crc_veryfication;}
    inline auto deviceIDRef( )                                      -> quint32& {return m_device_ID;}
    inline auto centerFixationLampDARef()                           -> quint16& {return m_center_fixation_lamp_DA;}
    inline auto bigDiamondfixationLampDARef()                       -> quint16& {return m_big_diamond_fixation_lamp_DA;}
    inline auto smallDiamondFixationLampDARef()                     -> quint16& {return m_small_diamond_fixation_lamp_DA;}
    inline auto yellowBackgroundLampDARef()                         -> quint16& {return m_yellow_background_lamp_DA;}
    inline auto whiteBackgroundLampDARef()                          -> auto&    {return m_white_background_lamp_DA;}
    inline auto centerInfraredLampDARef()                           -> quint16& {return m_center_fixation_lamp_DA;}
    inline auto borderInfraredLampDARef()                           -> quint16& {return m_border_infrared_lamp_DA;}
    inline auto eyeglassFrameLampDARef()                            -> quint16& {return m_eyeglass_frame_lamp_DA;}
    inline auto environmentAlarmLightDARef()                        -> auto&    {return m_environment_light_alarm_DA;}
    inline auto switchColorMotorCoordRef()                          -> auto&    {return m_switch_color_motor_coord;}
    inline auto switchLightSpotMotorCoordRef()                      -> auto&    {return m_switch_light_spot_coord;}
    inline auto focusCoordForSpotAndColorChangeRef()                -> qint32&  {return m_focus_coord_for_sport_and_color_change;}
    inline auto mainTableCenterXCorrectionRef()                     -> qint32&  {return m_main_table_center_x_correction;}
    inline auto mainTableCenterYCorrectionRef()                     -> qint32&  {return m_main_table_center_y_correction;}
    inline auto secondaryTableCenterXCorrectionRef()                -> qint32&  {return m_secondary_table_center_x_correction;}
    inline auto secondaryTableCenterYCorrectionRef()                -> qint32&  {return m_secondary_table_center_y_correction;}
    inline auto maximunProjectionLightADPresetRef()                 -> qint32&  {return m_maximun_projection_light_AD_preset;}
    inline auto xMotorCoordForLightCorrectionRef()                  -> qint32&  {return m_x_motor_coord_for_light_correction;}
    inline auto yMotorCoordForLightCorrectionRef()                  -> qint32&  {return m_y_motor_coord_for_light_correction;}
    inline auto focalLengthMotorCoordForLightCorrectionRef()        -> qint32&  {return m_focal_length_motor_coord_for_light_correction;}
    inline auto xMotorCoordForDiamondCenterTestRef()                -> qint32&  {return m_x_motor_coord_for_diamond_center_test;}
    inline auto yMotorCoordForDiamondCenterTestRef()                -> qint32&  {return m_y_motor_coord_for_diamond_center_test;}
    inline auto focalLengthMotorCoordForDiamondCenterTestRef()      -> auto&    {return m_focal_length_motor_coord_for_diamond_center_test;}
    inline auto focalLengthMotorCoordMappingRef()                   -> auto&    {return m_focal_length_motor_coord_mapping;}
    inline auto DbCoordMappingRef()                                 -> auto&    {return m_Db_coord_mapping;}
};

ConfigPriv :: ~ConfigPriv ( ) { }

// ============================================================================
// ctor
// ============================================================================
ConfigPriv :: ConfigPriv ( )
{
    m_crc_veryfication                                            = 0xffffffff;
    m_device_ID                                                   = 0xffffffff;
    m_center_fixation_lamp_DA                                     = 0;
    m_big_diamond_fixation_lamp_DA                                = 0;
    m_small_diamond_fixation_lamp_DA                              = 0;
    m_yellow_background_lamp_DA                                   = 0;
    memset(m_white_background_lamp_DA,0,sizeof (m_white_background_lamp_DA));
    m_center_infrared_lamp_DA                                     = 0;
    m_border_infrared_lamp_DA                                     = 0;
    m_eyeglass_frame_lamp_DA                                      = 0;
    memset(m_environment_light_alarm_DA,0,sizeof (m_environment_light_alarm_DA));
    memset(m_switch_color_motor_coord,0,sizeof (m_switch_color_motor_coord));
    memset(m_switch_light_spot_coord,0,sizeof (m_switch_light_spot_coord));
    m_focus_coord_for_sport_and_color_change                      = 0;
    m_main_table_center_x_correction                              = 0;
    m_main_table_center_y_correction                              = 0;
    m_secondary_table_center_x_correction                         = 0;
    m_secondary_table_center_y_correction                         = 0;
    m_maximun_projection_light_AD_preset                          = 0;
    m_x_motor_coord_for_light_correction                          = 0;
    m_y_motor_coord_for_light_correction                          = 0;
    m_focal_length_motor_coord_for_light_correction               = 0;
    m_x_motor_coord_for_diamond_center_test                       = 0;
    m_y_motor_coord_for_diamond_center_test                       = 0;
    memset(m_white_background_lamp_DA,0,sizeof (m_focal_length_motor_coord_for_diamond_center_test));
    memset(m_white_background_lamp_DA,0,sizeof (m_focal_length_motor_coord_mapping));
    memset(m_white_background_lamp_DA,0,sizeof (m_Db_coord_mapping));
}

// ============================================================================
// ctor( copy )
// ============================================================================
ConfigPriv :: ConfigPriv ( const ConfigPriv &o )
{
    m_crc_veryfication                                            =o.m_crc_veryfication                      ;
    m_device_ID                                                   =o.m_device_ID                             ;
    m_center_fixation_lamp_DA                                     =o.m_center_fixation_lamp_DA               ;
    m_big_diamond_fixation_lamp_DA                                =o.m_big_diamond_fixation_lamp_DA          ;
    m_small_diamond_fixation_lamp_DA                              =o.m_small_diamond_fixation_lamp_DA        ;
    m_yellow_background_lamp_DA                                   =o.m_yellow_background_lamp_DA             ;
    memcpy(m_white_background_lamp_DA,o.m_white_background_lamp_DA,sizeof (m_white_background_lamp_DA));
    m_center_infrared_lamp_DA                                     =o.m_center_infrared_lamp_DA               ;
    m_border_infrared_lamp_DA                                     =o.m_border_infrared_lamp_DA               ;
    m_eyeglass_frame_lamp_DA                                      =o.m_eyeglass_frame_lamp_DA                ;
    memcpy(m_environment_light_alarm_DA,o.m_environment_light_alarm_DA,sizeof (m_environment_light_alarm_DA));
    memcpy(m_switch_color_motor_coord,o.m_switch_color_motor_coord,sizeof (m_switch_color_motor_coord));
    memcpy(m_switch_light_spot_coord,o.m_switch_light_spot_coord,sizeof (m_switch_light_spot_coord));
    m_focus_coord_for_sport_and_color_change                      =o.m_focus_coord_for_sport_and_color_change;
    m_main_table_center_x_correction                              =o.m_main_table_center_x_correction        ;
    m_main_table_center_y_correction                              =o.m_main_table_center_y_correction        ;
    m_secondary_table_center_x_correction                         =o.m_secondary_table_center_x_correction   ;
    m_secondary_table_center_y_correction                         =o.m_secondary_table_center_y_correction   ;
    m_maximun_projection_light_AD_preset                          =o.m_maximun_projection_light_AD_preset    ;
    m_x_motor_coord_for_light_correction                          =o.m_x_motor_coord_for_light_correction    ;
    m_y_motor_coord_for_light_correction                          =o.m_y_motor_coord_for_light_correction    ;
    m_focal_length_motor_coord_for_light_correction               =o.m_focal_length_motor_coord_for_light_correction;
    m_x_motor_coord_for_diamond_center_test                       =o.m_x_motor_coord_for_diamond_center_test ;
    m_y_motor_coord_for_diamond_center_test                       =o.m_y_motor_coord_for_diamond_center_test ;
    memcpy(m_focal_length_motor_coord_for_diamond_center_test,o.m_focal_length_motor_coord_for_diamond_center_test,sizeof (m_focal_length_motor_coord_for_diamond_center_test));
    memcpy(m_focal_length_motor_coord_mapping,o.m_focal_length_motor_coord_mapping,sizeof (m_focal_length_motor_coord_mapping));
    memcpy(m_Db_coord_mapping,o.m_Db_coord_mapping,sizeof (m_Db_coord_mapping));
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
//  ctor ( empty )
// ============================================================================
Config :: Config ( )
{ gRegInQt(); m_obj = nullptr; }

// ============================================================================
//  ctor ( copy  )
// ============================================================================
Config :: Config ( const Config &o )
{
    gRegInQt();  m_obj = nullptr;
    ConfigPriv::attach( &m_obj, const_cast<void**>( & o.m_obj));
}

// ============================================================================
//  assign
// ============================================================================
Config &  Config :: operator=( const Config &o )
{
    gRegInQt();
    ConfigPriv::attach( &m_obj, const_cast<void**>( & o.m_obj));
    return *this;
}

// ============================================================================
// dtor
// ============================================================================
Config :: ~Config ( )
{
    if ( m_obj != nullptr ) {
        ConfigPriv::attach( &m_obj, nullptr );
    }
}

// ============================================================================
// ctor ( consturct by data )
// ============================================================================
Config :: Config ( const QByteArray &ba )
{
    gRegInQt(); m_obj = nullptr;
    if ( ba.size() < 512 ) { return; }

    // ------------------------------------------------------------------------
    // build data
    // ------------------------------------------------------------------------
    void *d = nullptr;
    const unsigned char *buff = reinterpret_cast<const unsigned char*>( ba.constData());
    ConfigPriv::buildIfNull( & d );
    auto *priv = T_PrivPtr( d );
    priv->crcVeryficationRef()=gReadData_Le_I32(&buff[0]);
    priv->deviceIDRef()=gReadData_Le_I32(&buff[4]);
    priv->centerFixationLampDARef()=gReadData_Le_I16(&buff[8]);
    priv->bigDiamondfixationLampDARef()=gReadData_Le_I16(&buff[10]);
    priv->smallDiamondFixationLampDARef()=gReadData_Le_I16(&buff[12]);
    priv->yellowBackgroundLampDARef()=gReadData_Le_I16(&buff[14]);
    memcpy(priv->whiteBackgroundLampDARef(),&buff[16],sizeof (priv->whiteBackgroundLampDARef()));
    priv->centerInfraredLampDARef()=gReadData_Le_I16(&buff[22]);
    priv->borderInfraredLampDARef()=gReadData_Le_I16(&buff[24]);
    priv->eyeglassFrameLampDARef()=gReadData_Le_I16(&buff[26]);
    memcpy(priv->environmentAlarmLightDARef(),&buff[28],sizeof(priv->environmentAlarmLightDARef()));
    memcpy(priv->switchColorMotorCoordRef(),&buff[32],sizeof(priv->switchColorMotorCoordRef()));
    memcpy(priv->switchLightSpotMotorCoordRef(),&buff[56],sizeof(priv->switchLightSpotMotorCoordRef()));
    priv->focusCoordForSpotAndColorChangeRef()=gReadData_Le_I32(&buff[88]);
    priv->mainTableCenterXCorrectionRef()=gReadData_Le_I32(&buff[92]);
    priv->mainTableCenterYCorrectionRef()=gReadData_Le_I32(&buff[96]);
    priv->secondaryTableCenterXCorrectionRef()=gReadData_Le_I32(&buff[100]);
    priv->secondaryTableCenterYCorrectionRef()=gReadData_Le_I32(&buff[104]);
    priv->maximunProjectionLightADPresetRef()=gReadData_Le_I32(&buff[108]);
    priv->xMotorCoordForLightCorrectionRef()=gReadData_Le_I32(&buff[112]);
    priv->yMotorCoordForLightCorrectionRef()=gReadData_Le_I32(&buff[116]);
    priv->focalLengthMotorCoordForLightCorrectionRef()=gReadData_Le_I32(&buff[120]);
    priv->xMotorCoordForDiamondCenterTestRef()=gReadData_Le_I32(&buff[124]);
    priv->yMotorCoordForDiamondCenterTestRef()=gReadData_Le_I32(&buff[128]);
    memcpy( priv->focalLengthMotorCoordForDiamondCenterTestRef(),&buff[132],sizeof(priv->focalLengthMotorCoordForDiamondCenterTestRef()));
    memcpy( priv->focalLengthMotorCoordMappingRef(),&buff[160],sizeof(priv->focalLengthMotorCoordMappingRef()));
    memcpy (priv->DbCoordMappingRef(),&buff[860],sizeof (priv->DbCoordMappingRef()));

    m_obj = d;
}

// ============================================================================
// method access
// ============================================================================

bool       Config :: isEmpty() const { return ( m_obj == nullptr ); }

quint32&       Config :: crcVeryficationRef()
{ return T_PrivPtr( m_obj )->crcVeryficationRef(); }

quint32&       Config :: deviceIDRef()
{ return T_PrivPtr( m_obj )->deviceIDRef(); }

quint16&       Config :: centerFixationLampDARef()
{ return  T_PrivPtr( m_obj )->centerFixationLampDARef(); }

quint16&       Config :: bigDiamondfixationLampDARef()
{ return T_PrivPtr( m_obj )->bigDiamondfixationLampDARef(); }

quint16&       Config :: smallDiamondFixationLampDARef()
{ return T_PrivPtr( m_obj )->smallDiamondFixationLampDARef() ; }

quint16&       Config :: yellowBackgroundLampDARef()
{ return  T_PrivPtr( m_obj )->yellowBackgroundLampDARef() ; }

auto&          Config :: whiteBackgroundLampDARef()
{ return  T_PrivPtr( m_obj )->whiteBackgroundLampDARef() ; }

quint16&       Config :: centerInfraredLampDARef()
{ return  T_PrivPtr( m_obj )->centerInfraredLampDARef(); }

quint16&       Config :: borderInfraredLampDARef()
{ return T_PrivPtr( m_obj )->borderInfraredLampDARef(); }

quint16&       Config :: eyeglassFrameLampDARef()
{ return  T_PrivPtr( m_obj )->eyeglassFrameLampDARef(); }

auto&          Config :: environmentAlarmLightDARef()
{ return T_PrivPtr( m_obj )->environmentAlarmLightDARef(); }

auto&          Config :: switchColorMotorCoordRef()
{ return  T_PrivPtr( m_obj )->switchColorMotorCoordRef(); }

auto&          Config :: switchLightSpotMotorCoordRef()
{ return  T_PrivPtr( m_obj )->switchLightSpotMotorCoordRef(); }

qint32&       Config :: focusCoordForSpotAndColorChangeRef()
{ return T_PrivPtr( m_obj )->focusCoordForSpotAndColorChangeRef(); }

qint32&       Config :: mainTableCenterXCorrection()
{ return T_PrivPtr( m_obj )->mainTableCenterXCorrectionRef(); }

qint32&       Config :: mainTableCenterYCorrection()
{ return T_PrivPtr( m_obj )->mainTableCenterYCorrectionRef(); }

qint32&       Config :: secondaryTableCenterXCorrection()
{ return T_PrivPtr( m_obj )->secondaryTableCenterXCorrectionRef() ; }

qint32&       Config :: secondaryTableCenterYCorrection()
{ return T_PrivPtr( m_obj )->secondaryTableCenterYCorrectionRef(); }

qint32&       Config :: maximunProjectionLightADPresetRef()
{ return T_PrivPtr( m_obj )->maximunProjectionLightADPresetRef(); }

qint32&       Config :: xMotorCoordForLightCorrectionRef()
{ return T_PrivPtr( m_obj )->xMotorCoordForLightCorrectionRef(); }

qint32&       Config :: yMotorCoordForLightCorrectionRef()
{ return T_PrivPtr( m_obj )->yMotorCoordForLightCorrectionRef(); }

auto&       Config :: focalLengthMotorCoordForDiamondCenterTestRef()
{ return T_PrivPtr( m_obj )->focalLengthMotorCoordForDiamondCenterTestRef(); }

auto&       Config :: focalLengthMotorCoordMappingRef()
{ return T_PrivPtr( m_obj )->focalLengthMotorCoordMappingRef(); }

auto&       Config :: DbCoordMappingRef()
{ return T_PrivPtr( m_obj )->DbCoordMappingRef(); }
// ============================================================================
// make all profile as json object
// ============================================================================
//QJsonObject  Config :: toJsonObject( ) const
//{
//    QJsonObject jo;
//    if ( isEmpty() ) { return jo; }

//    jo.insert( QStringLiteral("devVerStr"), T_PrivPtr( m_obj )->devVerRef() );
//    jo.insert( QStringLiteral("isFrontVideoCombined"), T_PrivPtr( m_obj )->isFrontVideoCombRef() );

//    { // front video width and height
//        QJsonObject jo2; QSize sz = T_PrivPtr( m_obj )->frontVideoSizeRef();
//        jo2.insert( QStringLiteral("width"),  sz.width() );
//        jo2.insert( QStringLiteral("height"), sz.height());
//        jo.insert( QStringLiteral("frontVideoSize"), jo2 );
//    }

//    jo.insert( QStringLiteral("frontVideoRowPitch"), int( T_PrivPtr( m_obj )->frontVideoRowPitchRef() ));

//    { // make all motor range value
//        QStringList mot_list; ConfigPriv *pp = T_PrivPtr( m_obj );
//        mot_list << "xMotorRange"    << "yMotorRange" << "zMotorRange" << "focusMotorRange"
//                 << "chinMotorRange" << "spectraMotorRange" << "ligthMotorRange" << "sampleMotorRange";
//        QList<QPair<qint32,qint32>> rg_list;
//        rg_list << pp->xMotorRangeRef() << pp->yMotorRangeRef() << pp->zMotorRangeRef() << pp->focusMotorRangeRef()
//                << pp->chinMotorRangeRef() << pp->spectraMotorRangeRef() << pp->lightMotorRangeRef() << pp->sampleMotorRangeRef();
//        int sz = mot_list.size();
//        for ( int i = 0; i < sz; i ++ ) {
//            QJsonObject jo2;
//            jo2.insert( QStringLiteral("min"), rg_list.at(i).first  );
//            jo2.insert( QStringLiteral("max"), rg_list.at(i).second );
//            jo.insert( mot_list.at(i), jo2 );
//        }
//    }

//    {  // vibra mirror x ad
//        QJsonObject jo2;
//        jo2.insert( QStringLiteral("min"), T_PrivPtr( m_obj )->vibraMirrorXadRangeRef().first  );
//        jo2.insert( QStringLiteral("max"), T_PrivPtr( m_obj )->vibraMirrorXadRangeRef().second );
//        jo.insert( QStringLiteral("vibraMirrorXadRange"), jo2 );
//    }
//    {  // vibra mirror y ad
//        QJsonObject jo2;
//        jo2.insert( QStringLiteral("min"), T_PrivPtr( m_obj )->vibraMirrorYadRangeRef().first  );
//        jo2.insert( QStringLiteral("max"), T_PrivPtr( m_obj )->vibraMirrorYadRangeRef().second );
//        jo.insert( QStringLiteral("vibraMirrorYadRange"), jo2 );
//    }
//    {  // global accel param range
//        QJsonObject jo2;
//        jo2.insert( QStringLiteral("min"), T_PrivPtr( m_obj )->globalAccelParamRangeRef().first );
//        jo2.insert( QStringLiteral("max"), T_PrivPtr( m_obj )->globalAccelParamRangeRef().second);
//        jo.insert( QStringLiteral("globalAccelParamRange"), jo2 );
//    }

//    { // extend version information
//        jo.insert( QStringLiteral("hasExtVerInfo"), T_PrivPtr(m_obj)->hasExtVerInfoRef());
//        jo.insert( QStringLiteral("dblCamCode"),    T_PrivPtr(m_obj)->dblCamCodeRef());
//        jo.insert( QStringLiteral("intrCamCode"), T_PrivPtr(m_obj)->intrCamCodeRef());
//        jo.insert( QStringLiteral("d3PlatCode"),  T_PrivPtr(m_obj)->d3PlatCodeRef());
//        jo.insert( QStringLiteral("physKeyCnt"),  T_PrivPtr(m_obj)->physKeyCntRef());
//        jo.insert( QStringLiteral("hasPhysKey"),  hasPhysKey() );
//    }

//    return jo;
//}


}

#endif
