#ifndef USBDEV_DEVCTL_CXX
#define USBDEV_DEVCTL_CXX

#include "usbdev_devctl.hxx"
#include <QThread>
#include <QTimer>
#include <QMetaObject>
#include <QDebug>
#include <QElapsedTimer>
#include <QAtomicInt>
#include <memory>

#include "nwkusbobj2.hxx"
#include "usbdev/common/usbdev_memcntr.hxx"
#include "qxpack/indcom/sys/qxpack_ic_rmtobjcreator_priv.hxx"
#include "qxpack/indcom/common/qxpack_ic_queuetemp.hpp"
#include "qxpack/indcom/sys/qxpack_ic_rmtobjsigblocker_priv.hxx"
#include "usbdev/main/usbdev_profile.hxx"
#include "usbdev/main/usbdev_framedata.hxx"
#include "usbdev/main/usbdev_statusdata.hxx"

namespace UsbDev {

// ////////////////////////////////////////////////////////////////////////////
// helper function
// ////////////////////////////////////////////////////////////////////////////
static void  gPutInt32_Le( unsigned char *buff, qint32 v )
{
    buff[0] = quint8( v & 0x0ff );          buff[1] = quint8(( v >> 8 ) & 0x0ff );
    buff[2] = quint8(( v >> 16 ) & 0x0ff ); buff[3] = quint8(( v >> 24) & 0x0ff );
}

static void  gPutInt16_Le( unsigned char *buff, qint16 v )
{
    buff[0] = quint8( v & 0x0ff );          buff[1] = quint8(( v >> 8 ) & 0x0ff );
}

static void  gPutInt32( unsigned char *buff, qint32 v, const Profile &pf )
{
        gPutInt32_Le( buff, v );
}

static void  gPutInt16( unsigned char *buff, qint16 v, const Profile &pf )
{
        gPutInt16_Le( buff, v );
}



// ////////////////////////////////////////////////////////////////////////////
//
//                    worker ( running in a QThread )
//
// ////////////////////////////////////////////////////////////////////////////
class USBDEV_HIDDEN DevCtl_Worker : public QObject {
    Q_OBJECT
private:
    Profile m_profile;
    SciPack::NwkUsbObj2 *m_usb_dev;
    QElapsedTimer m_elapse_tmr;
    quint32 m_trg_cntr; quint32 m_vid_pid, m_cfg_id; bool m_is_video_on;
    QAtomicInt  m_trg_called;
    DevCtl::WorkStatus  m_wks;
    quint32 m_key_bmp;
protected:
    auto  cmdComm_bulkOutSync( const unsigned char *buff, int buff_sz ) -> bool;
    auto  cmdComm_strInSync  (       unsigned char *buff, int buff_sz ) -> bool;
    auto  cmdComm_bulkInSync (       unsigned char *buff, int buff_sz ) -> bool;
    auto  isDeviceWork( ) -> bool
    {
        if ( m_usb_dev == nullptr ) { return false; }
        if ( m_usb_dev->status() != SciPack::NwkUsbObj2::StatusID_S_OK ) { return false; }
        return true;
    }

public :
    explicit DevCtl_Worker( quint32 vid_pid, quint32 cfg, QObject* pa = Q_NULLPTR );
    virtual ~DevCtl_Worker( ) Q_DECL_OVERRIDE;

    Q_INVOKABLE void  init( bool req_emit = true );
    Q_SLOT      void  trigger_di( );
    Q_INVOKABLE void  forceReadProfile( void *p ) { Profile *pf = reinterpret_cast<Profile*>(p); *pf = m_profile; }
    Q_INVOKABLE int   forceReadWorkStatus( ) { return m_wks; }  // since 0.2.1  try force check workstatus
    Q_INVOKABLE bool  cmd_ReadProfile( bool req_emit = true );
    Q_INVOKABLE bool  cmd_ReadStatusData( );
    Q_INVOKABLE bool  cmd_ReadFrameData ( );
    Q_INVOKABLE bool  cmd_TurnOnVideo ( );
    Q_INVOKABLE bool  cmd_TurnOffVideo( );
    Q_INVOKABLE bool  cmd_Move5Motors  ( quint8 sps[5], qint32 value[5],DevCtl::MoveMethod method );
    Q_INVOKABLE bool  cmd_SaveMotorCfg( int mot, const QByteArray &ba );
    Q_INVOKABLE bool  cmd_ControlSampleMotor( int stage, qint32 sps, quint8 acc_flag );
    Q_INVOKABLE bool  cmd_SetLamp ( int lamp, bool );
    Q_INVOKABLE bool  cmd_SetFixatLamp( qint16, qint16, bool);

    Q_SIGNAL void  workStatusChanged( int );
    Q_SIGNAL void  newProfile   ( const UsbDev::Profile &    );
    Q_SIGNAL void  newFrameData ( const UsbDev::FrameData &  );
    Q_SIGNAL void  newStatusData( const UsbDev::StatusData & );
    Q_SIGNAL void  videoStatusChanged( bool );


    Q_INVOKABLE bool  cmd_readUsbEEPROM ( char *buff, int size, int eeprom_addr  ); // since 0.5
    Q_INVOKABLE bool  cmd_writeUsbEEPROM( const char *buff, int size, int eeprom_addr );
};

// ============================================================================
// ctor
// ============================================================================
DevCtl_Worker :: DevCtl_Worker ( quint32 vid_pid, quint32 cfg_id, QObject *pa ) : QObject( pa )
{
    m_usb_dev = nullptr; m_trg_cntr = 0;
    m_vid_pid = vid_pid; m_cfg_id = cfg_id; m_is_video_on = false;
    m_trg_called.store(0);
    m_key_bmp = 0;
    m_wks = DevCtl::WorkStatus_S_Disconnected;
}

// ============================================================================
// dtor
// ============================================================================
DevCtl_Worker :: ~DevCtl_Worker ( )
{
    if ( m_usb_dev != nullptr ) {
        this->cmd_TurnOffVideo();
        usbdev_delete( m_usb_dev, SciPack::NwkUsbObj2 );
        emit this->workStatusChanged( DevCtl::WorkStatus_S_Disconnected );
    }
}

// ============================================================================
// method: handle the initialize
// ============================================================================
void   DevCtl_Worker :: init( bool req_emit )
{
    if ( m_usb_dev == nullptr ) {
        m_wks = DevCtl::WorkStatus_S_ConnectToDev;
        if ( req_emit ) { emit this->workStatusChanged( DevCtl::WorkStatus_S_ConnectToDev ); }
        m_usb_dev = usbdev_new( SciPack::NwkUsbObj2, m_vid_pid, uint8_t( m_cfg_id ), 0xff000000, 0, 0 );
        if ( m_usb_dev->status() == SciPack::NwkUsbObj2::StatusID_S_OK ) {
            m_wks = DevCtl::WorkStatus_S_OK;
            if ( req_emit ) { emit this->workStatusChanged( DevCtl::WorkStatus_S_OK ); }
            this->cmd_ReadProfile( req_emit );
        } else {
            m_wks = DevCtl::WorkStatus_E_UnExpected;
            if ( req_emit ) { emit this->workStatusChanged( DevCtl::WorkStatus_E_UnExpected ); }
            usbdev_delete( m_usb_dev, SciPack::NwkUsbObj2 );
            m_usb_dev = nullptr;
            m_wks = DevCtl::WorkStatus_S_Disconnected;
            if ( req_emit ) { emit this->workStatusChanged( DevCtl::WorkStatus_S_Disconnected ); }
        }
    }
}

// ============================================================================
// method: work trigger
// ============================================================================
void   DevCtl_Worker :: trigger_di( )
{
    if ( m_trg_called.loadAcquire() > 5 ) { return; }
    m_trg_called.fetchAndAddOrdered(1);

    if ( ( ++ m_trg_cntr ) % 2 == 0 ) {
        QMetaObject::invokeMethod( this, "cmd_ReadStatusData", Qt::QueuedConnection );
    } else {
        QMetaObject::invokeMethod( this, "cmd_ReadFrameData", Qt::QueuedConnection );
    }
}

// ============================================================================
// output the buffer to usb client
// ============================================================================
bool    DevCtl_Worker :: cmdComm_bulkOutSync( const unsigned char *buff, int buff_sz )
{
    SciPack::NwkUsbObj2::DataPacket  pkg;
    pkg.dat_id = 0; pkg.dat_ptr = const_cast<unsigned char*>( buff ); pkg.dat_size = buff_sz;
    return ( m_usb_dev->bulkTransSync( SciPack::NwkUsbObj2::PipeTypeID_BlkBulkOut, & pkg ) == SCIPACK_S_OK );
}

// ============================================================================
// input the buffer from usb client
// ============================================================================
bool    DevCtl_Worker :: cmdComm_bulkInSync( unsigned char *buff, int buff_sz )
{
    SciPack::NwkUsbObj2::DataPacket pkg;
    pkg.dat_id = 0; pkg.dat_ptr = buff; pkg.dat_size = buff_sz;
    return ( m_usb_dev->bulkTransSync( SciPack::NwkUsbObj2::PipeTypeID_BlkBulkIn, & pkg ) == SCIPACK_S_OK );
}

// ============================================================================
// input the buffer from usb client
// ============================================================================
bool    DevCtl_Worker :: cmdComm_strInSync( unsigned char *buff, int buff_sz )
{
    SciPack::NwkUsbObj2::DataPacket pkg;
    pkg.dat_id = 0; pkg.dat_ptr = buff; pkg.dat_size = buff_sz;
    return ( m_usb_dev->bulkTransSync( SciPack::NwkUsbObj2::PipeTypeID_StrBulkIn, & pkg ) == SCIPACK_S_OK );
}


// ============================================================================
// cmd: read the profile from device
// ============================================================================
bool   DevCtl_Worker :: cmd_ReadProfile( bool req_emit )
{
    if ( ! this->isDeviceWork()) { return false; }

    unsigned char buff[512]; bool ret = true;
    if ( ret ) {
        buff[0] = 0x5a; buff[1] = 0xf0; buff[2] = 0x00; buff[3] = 0;
        ret = this->cmdComm_bulkOutSync( buff, sizeof( buff ) );
        if ( ! ret ) { qWarning("send read profile command failed."); }
    }
    if ( ret ) {
        ret = this->cmdComm_bulkInSync( buff, sizeof( buff ));
        if ( ! ret ) { qWarning("recv. profile data failed."); }
    }
    if ( ret ) {
        Profile profile( QByteArray::fromRawData( reinterpret_cast<const char*>(buff), sizeof(buff)));
        if ( ! profile.isEmpty()) { if ( req_emit ){ emit this->newProfile( profile );} }
        m_profile = profile;
    }

    return ret;
}

// ============================================================================
// cmd: read the status data from device
// ============================================================================
bool   DevCtl_Worker :: cmd_ReadStatusData()
{
    if ( m_trg_called.loadAcquire() > 0 ) { m_trg_called.fetchAndSubOrdered(1); }

    if ( ! this->isDeviceWork()) { return false; }

    unsigned char buff[512]; bool ret = true;
    if ( ret ) {
        buff[0] = 0x5a; buff[1] = 0xf1; buff[2] = 0x55; buff[3] = 0xaa;
        ret = this->cmdComm_bulkOutSync( buff, sizeof( buff ));
        if ( ! ret  ) { qWarning("send read status command failed."); }
    }
    if ( ret ) {
        ret = this->cmdComm_bulkInSync( buff, sizeof( buff ));
        if ( ! ret ) { qWarning("recv. stauts data failed."); }
    }
    if ( ret ) {
        StatusData sd( QByteArray::fromRawData( reinterpret_cast<const char*>(buff),sizeof(buff)));
        if ( ! sd.isEmpty()) {
            emit this->newStatusData( sd );
        }
    }
    return ret;
}

// ============================================================================
// cmd: read the front video data
// ============================================================================
bool  DevCtl_Worker :: cmd_ReadFrameData()
{
    if ( m_trg_called.loadAcquire() > 0 ) { m_trg_called.fetchAndSubOrdered(1); }

    if ( ! this->isDeviceWork() || ! m_is_video_on || m_profile.isEmpty()) { return false; }

    bool ret = true;
    QSize sz = m_profile.videoSize();
    qintptr total_bytes = sz.height()*sz.width();
    if ( total_bytes > 64 * 1024 * 1024 || total_bytes % 512 != 0 ) { return false; }

    QByteArray ba( int( total_bytes ), 0 );
    ret = this->cmdComm_strInSync( reinterpret_cast<unsigned char*>( ba.data()), ba.size());
    if ( ret ) {
        FrameData fd( ba );
        emit this->newFrameData( fd );
    }

    return ret;
}

// ============================================================================
// cmd: the video open or close control
// ============================================================================
bool  DevCtl_Worker :: cmd_TurnOnVideo()
{
    if ( ! this->isDeviceWork()) { return false; }
    if ( m_is_video_on ) { return true; }
    bool ret = true;

    if ( ret ) { // turn on EP2
        SciPack::NwkUsbObj2::SetupPacket pkg;
        pkg.m_req_type = 0x40; pkg.m_req = 0xb2; pkg.m_value = 0;
        pkg.m_index = 0x01; pkg.m_length = 0;
        if ( m_usb_dev->ctlTransSync( & pkg, nullptr, nullptr ) != SCIPACK_S_OK ) {
            qWarning("control transfer failed, can not open EP2 IN.");
            ret = false;
        }
    }
    if ( ret ) { // turn on video
        unsigned char buff[512];
        buff[0] = 0x5a; buff[1] = 0x70; buff[2] = 0x00; buff[3] = 0x01;
        ret = this->cmdComm_bulkOutSync( buff, sizeof( buff ));
        if ( ! ret ) { qWarning("send video-on cmd failed."); }
    }
    if ( ret ) {
        m_is_video_on = true; m_elapse_tmr.start();
        emit this->videoStatusChanged( true );
    }

    return ret;
}

// ============================================================================
// turn off the video
// ============================================================================
bool  DevCtl_Worker :: cmd_TurnOffVideo()
{
    if ( ! this->isDeviceWork()) { return false; }
    if ( ! m_is_video_on ) { return true; }
    bool ret = true;

    if ( ret ) { // turn off video
        unsigned char buff[512];
        buff[0] = 0x5a; buff[1] = 0x70; buff[2] = 0x00; buff[3] = 0x00;
        ret = this->cmdComm_bulkOutSync( buff, sizeof( buff ));
        if ( ! ret ) { qWarning("send video-off cmd failed."); }
    }
    if ( ret ) { // turn off EP2
        SciPack::NwkUsbObj2::SetupPacket pkg;
        pkg.m_req_type = 0x40; pkg.m_req = 0xb2; pkg.m_value = 0;
        pkg.m_index = 0x02; pkg.m_length = 0;
        if ( m_usb_dev->ctlTransSync( & pkg, nullptr, nullptr ) != SCIPACK_S_OK ) {
            qWarning("control transfer failed, can not close EP2 IN.");
            ret = false;
        }
    }
    if ( ret ) {
        m_is_video_on = false; m_elapse_tmr.invalidate();
        emit this->videoStatusChanged( false );
    }

    return ret;
}

// ============================================================================
// cmd: motor move
// ============================================================================
bool  DevCtl_Worker :: cmd_Move5Motors( quint8 sps[5], qint32 dist[5] ,DevCtl::MoveMethod method)
{
    if ( ! this->isDeviceWork()) { return false; }
    unsigned char buff[512]; bool ret = true;

    if ( ret ) {
        buff[0] = 0x5a;
        buff[1] = method  == DevCtl::MoveMethod::Relative ? 0x52 : 0x53 ;
        memcpy(&buff[3],&sps[0],sizeof (*sps));
        memcpy(&buff[8],&dist[0],sizeof (*dist));
        ret = this->cmdComm_bulkOutSync( buff, sizeof( buff ) );
        if ( ! ret ) { qWarning("send motor moving command failed."); }
    }
    return ret;
}

// ============================================================================
// cmd: save the motor configuration data
// ============================================================================
bool  DevCtl_Worker :: cmd_SaveMotorCfg( int mot, const QByteArray &ba )
{
    if ( ! this->isDeviceWork()) { return false; }
    unsigned char buff[512]; bool ret = true;
    if ( ret ) {
        buff[0] = 0x5a; buff[1] = 0x53; buff[2] = quint8( mot ); buff[3] = 0;
        std::memcpy( & buff[4], ba.constData(), size_t( ba.size() >= 500 ? 500 : ba.size()));
        ret = this->cmdComm_bulkOutSync( buff, sizeof(buff) );
        if ( ! ret ) { qWarning("send save motor config. failed."); }
    }
    return ret;
}

// ============================================================================
// cmd: sample motor control
// ============================================================================
bool  DevCtl_Worker :: cmd_ControlSampleMotor( int stage, qint32 sps, quint8 acc_flag )
{
    if ( ! this->isDeviceWork()) { return false; }
    unsigned char buff[512]; bool ret = true;
    if ( ret ) {
        buff[0] = 0x5a; buff[1] = 0x54; buff[2] = quint8( stage ); buff[3] = 0;
        gPutInt32( & buff[4], sps, m_profile );
        gPutInt32( & buff[8], 0, m_profile );
        buff[12] = acc_flag;
        ret = this->cmdComm_bulkOutSync( buff, sizeof( buff ));
        if ( ! ret ) { qWarning("send control sample motor cmd failed."); }
    }
    return ret;
}


// ============================================================================
// cmd: set the lamp ON or OFF
// ============================================================================
bool  DevCtl_Worker :: cmd_SetLamp( int lamp, bool sw )
{
    if ( ! this->isDeviceWork()) { return false; }
    if ( lamp < DevCtl::LampId_FrontIr || lamp > DevCtl::LampId_OuterFixat ) { return false; }
    unsigned char buff[512];
    buff[0] = 0x5a; buff[1] = 0x90; buff[2] = quint8( lamp ); buff[3] = ( sw ? 0x01 : 0x00 );
    bool ret = this->cmdComm_bulkOutSync( buff, sizeof( buff ));
    if ( ! ret ) { qWarning("send set lamp command failed."); }
    return ret;
}

// ============================================================================
// cmd: set the fixat lamp
// ============================================================================
bool   DevCtl_Worker :: cmd_SetFixatLamp( qint16 cx, qint16 cy, bool on_off )
{
    if ( ! this->isDeviceWork()) { return false; }
    unsigned char buff[512];
    buff[0] = 0x5a; buff[1] = 0x91; buff[2] = 0; buff[3] = ( on_off ? 0x01 : 0x00 );
    gPutInt16( & buff[4], cx, m_profile );
    gPutInt16( & buff[6], cy, m_profile );
    bool ret = this->cmdComm_bulkOutSync( buff, sizeof(buff));
    if ( ! ret ) { qWarning("send set fixat lamp cmd failed."); }
    return ret;
}

// ============================================================================
// eeprom read/write
// ============================================================================
auto     DevCtl_Worker :: cmd_readUsbEEPROM ( char *buff, int size, int eeprom_addr  ) -> bool
{
    if ( ! this->isDeviceWork()) { return false; }

    SciPack::NwkUsbObj2::SetupPacket setup_pkg;
    setup_pkg.m_req_type = 0xc0;   setup_pkg.m_req   = 0xb0;
    setup_pkg.m_index    = 0x5103; setup_pkg.m_value = uint16_t( eeprom_addr );
    setup_pkg.m_length   = uint16_t( size );

    SciPack::NwkUsbObj2::DataPacket  data_pkg;
    data_pkg.dat_ptr = buff; data_pkg.dat_size = size;
    intptr_t bytes_trans;
    auto ret = ( m_usb_dev->ctlTransSync( & setup_pkg, & data_pkg, & bytes_trans ) == SCIPACK_S_OK );
    if ( ! ret ) { qWarning("read USB EEPROM cmd failed!"); }
    if ( ret ) {
        qDebug( "readEEPROM: %d address OK", eeprom_addr );
    }
    return ret;
}

auto     DevCtl_Worker :: cmd_writeUsbEEPROM( const char *buff, int size, int eeprom_addr ) -> bool
{
    if ( ! this->isDeviceWork()) { return false; }

    SciPack::NwkUsbObj2::SetupPacket setup_pkg;
    setup_pkg.m_req_type = 0x40;   setup_pkg.m_req = 0xb0;
    setup_pkg.m_index    = 0x5183; setup_pkg.m_value = uint16_t( eeprom_addr );
    setup_pkg.m_length   = uint16_t( size );
    SciPack::NwkUsbObj2::DataPacket data_pkg;
    data_pkg.dat_ptr = const_cast<void*>( reinterpret_cast<const void*>( buff )); data_pkg.dat_size = size;
    intptr_t bytes_trans;
    auto ret = ( m_usb_dev->ctlTransSync( & setup_pkg, & data_pkg, & bytes_trans ) == SCIPACK_S_OK );
    if ( ! ret ) { qWarning("write USB EEPROM cmd failed!"); }
    if ( ret ) {
        qDebug( "writeEEPROM: %d address OK", eeprom_addr );
    }
    return ret;
}



// ////////////////////////////////////////////////////////////////////////////
//
//                       private object
//
// ////////////////////////////////////////////////////////////////////////////
typedef QxPack::IcArrayQueueTemp<UsbDev::StatusData,3>   DevCtl_StatusDataQueue;
typedef QxPack::IcArrayQueueTemp<UsbDev::FrameData,3>    DevCtl_FrameDataQueue;
#define T_PrivPtr( o )  usbdev_objcast( DevCtlPriv*, o )
class USBDEV_HIDDEN DevCtlPriv : public QObject {
    Q_OBJECT
private:
    QThread  *m_t_worker; DevCtl_Worker *m_wkr;  // worker thread and worker
    QThread  *m_t_tmr;    QTimer *m_trg_tmr;     // timer thread and timer
    Profile   m_profile;
    DevCtl_StatusDataQueue  m_status_data_queue;
    DevCtl_FrameDataQueue   m_frame_data_queue;
    quintptr  m_status_data_emit_cntr, m_frame_data_emit_cntr;
    quint32   m_vid_pid, m_cfg_id;
    DevCtl::WorkStatus m_wkr_status;
    bool   m_is_inited;
protected:
    inline void  emitNewFrameData( )
    {
       if ( m_frame_data_emit_cntr < 1 ) {
           ++ m_frame_data_emit_cntr; emit this->newFrameData();
       }
    }

    inline void  emitNewStatusData( )
    {
        if ( m_status_data_emit_cntr < 1 ) {
            ++ m_status_data_emit_cntr; emit this->newStatusData();
        }
    }

           void  ensureWorker( bool );
           void  ensureTimer ( bool );
    Q_SLOT void  wkr_onWorkStatusChanged( int );
    Q_SLOT void  wkr_onNewFrameData ( const UsbDev::FrameData & );
    Q_SLOT void  wkr_onNewStatusData( const UsbDev::StatusData & );
    Q_SLOT void  wkr_onNewProfile   ( const UsbDev::Profile & );
    Q_SLOT void  wkr_onVideoStatusChanged( bool );
public:
    explicit DevCtlPriv( quint32 vid_pid, quint32 cfg );
    virtual ~DevCtlPriv( ) Q_DECL_OVERRIDE;
           auto  init( bool req_sync = false ) -> void;
    inline auto  isInited( ) const -> bool  { return m_is_inited; }
    inline auto  workStatus()   -> DevCtl::WorkStatus& { return m_wkr_status; }
    inline auto  vidPid() const -> quint32  { return m_vid_pid; }
    inline auto  cfgId () const -> quint32  { return m_cfg_id;  }
    inline auto  profile()      -> Profile& { return m_profile; }
    inline auto  wkrPtr()       -> DevCtl_Worker* { return m_wkr; }
    inline auto  takeNextPendingFrameData( UsbDev::FrameData &fd ) -> bool
    {
        if ( m_frame_data_emit_cntr > 0 ) { -- m_frame_data_emit_cntr; }
        bool ret = m_frame_data_queue.dequeue( fd );
        if ( ! m_frame_data_queue.isEmpty() ) {
           QMetaObject::invokeMethod( this, "emitNewFrameData", Qt::QueuedConnection );
           // this->emitNewFrameData();
        }
        return ret;
    }

    inline auto  takeNextPendingStatusData( UsbDev::StatusData &sd ) -> bool
    {
        if ( m_status_data_emit_cntr > 0 ) { -- m_status_data_emit_cntr; }
        bool ret = m_status_data_queue.dequeue( sd );
        if ( ! m_status_data_queue.isEmpty()) {
            QMetaObject::invokeMethod( this, "emitNewStatusData", Qt::QueuedConnection );
            //this->emitNewStatusData();
        }
        return ret;
    }

    Q_SIGNAL void  workStatusChanged( int );
    Q_SIGNAL void  newStatusData( );
    Q_SIGNAL void  newFrameData( );
    Q_SIGNAL void  newProfile( );
    Q_SIGNAL void  physKeyPressed ( quint32 ); // since 0.3.0
    Q_SIGNAL void  physKeyReleased( quint32 ); // since 0.3.0
    Q_SIGNAL void  physKeyClicked ( quint32 ); // since 0.3.0
};

// ============================================================================
// ctor
// ============================================================================
DevCtlPriv :: DevCtlPriv ( quint32 vid_pid, quint32 cfg )
{
    // init. all variables
    m_vid_pid = vid_pid; m_cfg_id = cfg;
    m_trg_tmr = Q_NULLPTR; m_wkr = Q_NULLPTR;
    m_status_data_emit_cntr = m_frame_data_emit_cntr = 0;
    m_wkr_status = DevCtl::WorkStatus_S_Disconnected;
    m_is_inited  = false;

    // create the timer thread and work thread
    m_t_tmr = usbdev_new_qobj( QThread );
    QObject::connect( m_t_tmr, SIGNAL(finished()), m_t_tmr, SLOT(deleteLater()));
    m_t_tmr->start();
    m_t_worker = usbdev_new_qobj( QThread );
    QObject::connect( m_t_worker, SIGNAL(finished()), m_t_worker, SLOT(deleteLater()));
    m_t_worker->start();    
}

// ============================================================================
// dtor
// ============================================================================
DevCtlPriv :: ~DevCtlPriv ()
{
    // drop old object that running in thread, quit() will trigger deleteLater()
    this->ensureTimer ( false );
    this->ensureWorker( false );
    m_t_tmr->quit();
    m_t_worker->quit();
}

// ============================================================================
// ensure the trigger timer
// ============================================================================
void  DevCtlPriv :: ensureTimer( bool sw )
{
    if ( sw ) {  // create timer in timer thread
        this->ensureTimer( false );
        m_trg_tmr = qobject_cast<QTimer*>(
            QxPack::IcRmtObjCreator::createObjInThread (
                m_t_tmr, []( void *)->QObject*{
                    QTimer *tmr = usbdev_new_qobj( QTimer );
                    tmr->setInterval( 23 );
                    tmr->setSingleShot( false );
                    return tmr;
                },this
            )
        );
        QMetaObject::invokeMethod( m_trg_tmr, "start" );

    } else {   // delete timer in timer thread
        if ( m_trg_tmr != Q_NULLPTR ) {
            QxPack::IcRmtObjSigBlocker::blockSignals ( m_t_tmr, true );
            m_trg_tmr->deleteLater();
            m_trg_tmr = Q_NULLPTR;
        }
    }
}

// ============================================================================
// create the worker by spec. VID PID
// ============================================================================
void  DevCtlPriv :: ensureWorker( bool sw )
{
    if ( sw  ) {  // create worker in work thread
        this->ensureWorker( false );
        m_wkr = qobject_cast<DevCtl_Worker*>(
            QxPack::IcRmtObjCreator::createObjInThread (
                m_t_worker, [](void *ctxt )->QObject*{
                    DevCtlPriv *t_this = reinterpret_cast<DevCtlPriv*>(ctxt);
                    return usbdev_new_qobj( DevCtl_Worker, t_this->m_vid_pid, t_this->m_cfg_id );
                }, this
            )
        );
        QObject::connect( m_wkr, SIGNAL(workStatusChanged(int)), this, SLOT(wkr_onWorkStatusChanged(int)));
        QObject::connect( m_wkr, SIGNAL(newProfile( const UsbDev::Profile&)), this, SLOT(wkr_onNewProfile(const UsbDev::Profile&)));
        QObject::connect( m_wkr, SIGNAL(newStatusData( const UsbDev::StatusData&)), this, SLOT(wkr_onNewStatusData(const UsbDev::StatusData&)));
        QObject::connect( m_wkr, SIGNAL(newFrameData (const UsbDev::FrameData&)), this, SLOT(wkr_onNewFrameData(const UsbDev::FrameData&)));
        QObject::connect( m_wkr, SIGNAL(videoStatusChanged(bool)), this, SLOT(wkr_onVideoStatusChanged(bool)));
        QObject::connect( m_wkr, SIGNAL(physKeyPressed (quint32)),  this, SIGNAL(physKeyPressed (quint32)));
        QObject::connect( m_wkr, SIGNAL(physKeyReleased(quint32)),  this, SIGNAL(physKeyReleased(quint32)));
        QObject::connect( m_wkr, SIGNAL(physKeyClicked (quint32)),  this, SIGNAL(physKeyClicked (quint32)));

        if ( m_trg_tmr != Q_NULLPTR ) { // connect the trigger function
           QObject::connect( m_trg_tmr, SIGNAL(timeout()), m_wkr, SLOT(trigger_di()), Qt::DirectConnection );
        }

    } else {    // delete the worker
        if ( m_wkr != Q_NULLPTR ) {
            QxPack::IcRmtObjSigBlocker::blockSignals( m_wkr, true );
            m_wkr->deleteLater();
            m_wkr = Q_NULLPTR;
        }
    }
}

// ============================================================================
// initialize
// ============================================================================
void  DevCtlPriv :: init( bool req_sync )
{
    this->ensureTimer ( true );
    this->ensureWorker( true );
    if ( m_wkr != Q_NULLPTR ) {
        QMetaObject::invokeMethod(
            m_wkr, "init", ( req_sync ? Qt::BlockingQueuedConnection : Qt::QueuedConnection ),
            Q_ARG( bool, req_sync ? false : true  ) // req_sync(true) means need not to emit signal about workstatus and profile.
        );
        if ( req_sync ) { // added since 0.3.1
            QMetaObject::invokeMethod(
                m_wkr, "forceReadProfile", Qt::BlockingQueuedConnection,
                Q_ARG( void*, reinterpret_cast<void*>(& m_profile ))
            );
        }
    }

    m_is_inited = true;
}

// ============================================================================
// slot: handle the work status changed
// ============================================================================
void  DevCtlPriv :: wkr_onWorkStatusChanged( int s )
{
    if ( m_wkr_status != s ) {
        m_wkr_status = static_cast<DevCtl::WorkStatus>( s );
        emit this->workStatusChanged( s );
    }
}

// ============================================================================
// slot: handle the video status changed
// ============================================================================
void  DevCtlPriv :: wkr_onVideoStatusChanged( bool curr_st )
{
    if ( ! curr_st ) {
        m_frame_data_emit_cntr = 0;
        m_frame_data_queue.clear();
    }
}

// ============================================================================
// slot: handle the new status data
// ============================================================================
void  DevCtlPriv :: wkr_onNewStatusData( const UsbDev::StatusData &sd )
{
    m_status_data_queue.forceEnqueue( sd );
    this->emitNewStatusData();
}

// ============================================================================
// slot: handle the new frame data
// ============================================================================
void  DevCtlPriv :: wkr_onNewFrameData( const UsbDev::FrameData &fd )
{
    m_frame_data_queue.forceEnqueue( fd );
    this->emitNewFrameData();
}

// ============================================================================
// slot: handle the new profile
// ============================================================================
void  DevCtlPriv :: wkr_onNewProfile( const UsbDev::Profile &pf )
{
    m_profile = pf;
    emit this->newProfile();
}

// ////////////////////////////////////////////////////////////////////////////
// wrap API
// ////////////////////////////////////////////////////////////////////////////
// ============================================================================
// [ static ] create private object
// ============================================================================
static DevCtlPriv *  gCreateDevCtlPriv( DevCtl *dev, quint32 vid_pid, quint32 cfg_id )
{
    DevCtlPriv *priv = usbdev_new( DevCtlPriv, vid_pid, cfg_id );

    // ------------------------------------------------------------------------
    // here need not to use queued connection due to the worker is in another
    // thread.
    // ------------------------------------------------------------------------
    QObject::connect( priv, SIGNAL(newFrameData()),  dev, SIGNAL(newFrameData())  );
    QObject::connect( priv, SIGNAL(newProfile()),    dev, SIGNAL(newProfile())    );
    QObject::connect( priv, SIGNAL(newStatusData()), dev, SIGNAL(newStatusData()) );
    QObject::connect( priv, SIGNAL(workStatusChanged(int)), dev, SIGNAL(workStatusChanged(int)));

    // since 0.3.0
    QObject::connect( priv, SIGNAL(physKeyPressed (quint32)), dev, SIGNAL(physKeyPressed (quint32)));
    QObject::connect( priv, SIGNAL(physKeyReleased(quint32)), dev, SIGNAL(physKeyReleased(quint32)));

    return priv;
}

// ============================================================================
// ctor
// ============================================================================
DevCtl :: DevCtl( quint32 vid_pid, quint32 cfg_id )
{
    m_obj = gCreateDevCtlPriv( this, vid_pid, cfg_id );
    T_PrivPtr( m_obj )->init( false );
}

// ============================================================================
// ctor( with wait )
// ============================================================================
DevCtl :: DevCtl( quint32 vid_pid, quint32 cfg_id, bool )
{
    m_obj = gCreateDevCtlPriv( this, vid_pid, cfg_id );
    T_PrivPtr( m_obj )->init( true ); // block until the device conntected and read profile

    int wks = 0;
    QMetaObject::invokeMethod(
        T_PrivPtr(m_obj)->wkrPtr(), "forceReadWorkStatus", Qt::BlockingQueuedConnection,
        Q_RETURN_ARG( int, wks )
    );
    T_PrivPtr( m_obj )->workStatus() = static_cast<DevCtl::WorkStatus>( wks );
}

// ============================================================================
// dtor
// ============================================================================
DevCtl :: ~DevCtl( )
{
    this->blockSignals(true);
    T_PrivPtr( m_obj )->blockSignals(true);
    usbdev_delete( m_obj, DevCtlPriv );
}

// ============================================================================
// return current work status
// ============================================================================
DevCtl::WorkStatus  DevCtl :: workStatus() const
{ return T_PrivPtr( m_obj )->workStatus(); }

// ============================================================================
// init the device
// ============================================================================
void  DevCtl :: init ( )
{
    if ( T_PrivPtr( m_obj )->isInited()) {
        quint32 vid_pid = T_PrivPtr( m_obj )->vidPid();
        quint32 cfg_id  = T_PrivPtr( m_obj )->cfgId();
        T_PrivPtr( m_obj )->blockSignals(true);
        usbdev_delete( m_obj, DevCtlPriv );
        m_obj = gCreateDevCtlPriv( this, vid_pid, cfg_id );
    }
    T_PrivPtr( m_obj )->init( false );
}

// ============================================================================
// return the profile data
// ============================================================================
UsbDev::Profile  DevCtl :: profile() const
{   return T_PrivPtr( m_obj )->profile(); }

// ============================================================================
// take the pending status data
// ============================================================================
UsbDev::StatusData   DevCtl :: takeNextPendingStatusData()
{
    UsbDev::StatusData sd;
    bool ret = T_PrivPtr( m_obj )->takeNextPendingStatusData( sd );
    return ( ret ? sd : UsbDev::StatusData());
}

// ============================================================================
// take the pending frame data
// ============================================================================
UsbDev::FrameData    DevCtl :: takeNextPendingFrameData()
{
    UsbDev::FrameData fd;
    bool ret = T_PrivPtr( m_obj )->takeNextPendingFrameData( fd );
    return ( ret ? fd : UsbDev::FrameData());
}

// ============================================================================
// convert the motor id to hardware id
// ============================================================================
//static int  gHwMotId ( DevCtl::MotorId m_id )
//{
//    int mot_id = 0;
//    switch( m_id ) {
//    case DevCtl::MotorId_Chinrests : mot_id = 0x01; break;
//    case DevCtl::MotorId_X : mot_id = 0x02;         break;
//    case DevCtl::MotorId_Y : mot_id = 0x03;         break;
//    case DevCtl::MotorId_Z : mot_id = 0x04;         break;
//    case DevCtl::MotorId_Focus : mot_id = 0x05;     break;
//    case DevCtl::MotorId_Spectra : mot_id = 0x06;   break;
//    case DevCtl::MotorId_Light   : mot_id = 0x07;   break;
//    case DevCtl::MotorId_Sample  : mot_id = 0x08;   break;
//    }
//    return mot_id;
//}

// ============================================================================
// move the motor
// ============================================================================
void   DevCtl :: move5Motors( quint8 sps[5], qint32 dist[5],MoveMethod method)
{
    QMetaObject::invokeMethod(
        T_PrivPtr( m_obj )->wkrPtr(), "cmd_move5Motors", Qt::QueuedConnection,
        Q_ARG( quint8, sps[5] ), Q_ARG( qint32, dist[5] ), Q_ARG( MoveMethod, method )
    );
}


// ============================================================================
// reset the motor
// ============================================================================
void   DevCtl :: resetMotor( MotorId mot, qint32 sps, qint32 pos, quint8 acc_flag )
{
    int mot_id = int( mot );
    if ( mot_id > 0 && mot_id < 9 ) {
        if ( sps <= 0 ) { sps = 400; }
        QMetaObject::invokeMethod(
            T_PrivPtr( m_obj )->wkrPtr(), "cmd_MoveMotor", Qt::QueuedConnection,
            Q_ARG( int, mot_id ), Q_ARG( qint32, qint32(sps) ), Q_ARG( qint32, pos ),
            Q_ARG( quint8, acc_flag ), Q_ARG( int, 2 )
        );
    }
}

void   DevCtl :: resetMotor( MotorId mot, qreal sps, qint32 pos, quint8 acc_flag)
{ resetMotor( mot, qint32(sps), pos, acc_flag ); }


// ============================================================================
// save the motor config
// ============================================================================
void   DevCtl :: saveMotorCfg( MotorId mot, const QByteArray &cfg )
{
    int mot_id = int( mot );
    if ( mot_id > 0 && mot_id < 9 ) {
        QMetaObject::invokeMethod(
            T_PrivPtr( m_obj )->wkrPtr(), "cmd_SaveMotorCfg", Qt::QueuedConnection,
            Q_ARG( int, mot_id ), Q_ARG( QByteArray, cfg )
        );
    }
}

// ============================================================================
// sample motor control
// ============================================================================
void   DevCtl :: sampleMotorCtl( SampleMotorCtl_Stage stage, qint32 sps, quint8 acc_flag )
{
    QMetaObject::invokeMethod(
        T_PrivPtr( m_obj )->wkrPtr(), "cmd_ControlSampleMotor", Qt::QueuedConnection,
        Q_ARG( int, stage ), Q_ARG( qint32, sps ), Q_ARG( quint8, acc_flag )
    );
}

// ============================================================================
// open the front video
// ============================================================================
void   DevCtl :: setFrontVideo( bool on_off )
{
    QMetaObject::invokeMethod(
        T_PrivPtr( m_obj )->wkrPtr(), ( on_off ? "cmd_TurnOnVideo" : "cmd_TurnOffVideo" ),
        Qt::QueuedConnection
    );
}

// ============================================================================
// set the lamp
// ============================================================================
void   DevCtl :: setLamp( LampId lamp, int, bool on_off )
{
    QMetaObject::invokeMethod(
        T_PrivPtr( m_obj )->wkrPtr(), "cmd_SetLamp", Qt::QueuedConnection,
        Q_ARG( int, lamp ), Q_ARG( bool, on_off )
    );
}

// ============================================================================
// set the fixat lamp
// ============================================================================
void   DevCtl :: setFixatLamp(qint16 cx, qint16 cy, bool on_off)
{
    QMetaObject::invokeMethod(
        T_PrivPtr( m_obj )->wkrPtr(), "cmd_SetFixatLamp", Qt::QueuedConnection,
        Q_ARG( qint16, cx ), Q_ARG( qint16, cy ), Q_ARG( bool, on_off )
    );
}




// ============================================================================
// EEPRom read/write
// ============================================================================
auto     DevCtl :: readUsbEEPROM (  char *buff_ptr, int size, int eeprom_addr ) -> bool
{
    auto priv = T_PrivPtr(m_obj);
    if ( priv->workStatus() != WorkStatus_S_OK ) { return false; }
    if ( size < 1 ) { return false; }

    bool c_ret = false;
    auto ret = QMetaObject::invokeMethod(
        priv->wkrPtr(), "cmd_readUsbEEPROM", Qt::BlockingQueuedConnection,
        Q_RETURN_ARG( bool,c_ret ), Q_ARG( char*, buff_ptr ),
        Q_ARG( int, size ), Q_ARG( int, eeprom_addr )
    );
    return ( ret && c_ret );
}

auto     DevCtl :: writeUsbEEPROM( const char *buff_ptr, int size, int eeprom_addr ) -> bool
{
    auto priv = T_PrivPtr(m_obj);
    if ( priv->workStatus() != WorkStatus_S_OK ) { return false; }
    if ( size < 1 ) { return false; }

    bool c_ret = false;
    auto ret = QMetaObject::invokeMethod(
        priv->wkrPtr(), "cmd_writeUsbEEPROM", Qt::BlockingQueuedConnection,
        Q_RETURN_ARG( bool,c_ret ), Q_ARG( const char*, buff_ptr ),
        Q_ARG( int, size ), Q_ARG( int, eeprom_addr )
    );
    return ( ret && c_ret );
}



// ////////////////////////////////////////////////////////////////////////////
// static functions
// ////////////////////////////////////////////////////////////////////////////
// ============================================================================
// create the device
// ============================================================================
UsbDev::DevCtl* DevCtl :: createInstance( quint32 vid_pid, quint32 cfg_id )
{
    return usbdev_new_qobj( UsbDev::DevCtl, vid_pid, cfg_id );
}

// ============================================================================
// since 0.2.1, create the device in sync, ensure device is created OK!
// ============================================================================
UsbDev::DevCtl*   DevCtl :: createInstanceSync( quint32 vid_pid, quint32 cfg_id )
{  return usbdev_new_qobj( UsbDev::DevCtl, vid_pid, cfg_id, true ); }

}

#include "usbdev_devctl.moc"
#endif
