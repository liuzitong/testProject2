#ifndef USBDEV_DEVCTL_HXX
#define USBDEV_DEVCTL_HXX

#include "usbdev/common/usbdev_def.h"
#include <QObject>
#include <QByteArray>
#include <spdlog/spdlog.h>
namespace UsbDev {

class Profile;
class StatusData;
class FrameData;


// ////////////////////////////////////////////////////////////////////////////
/*!
 * @brief the device controller
 * @details this class will do communication between host and usb device. \n
 *   the class inner used a thread, so NEED NOT to put it into a thread.
 */
// ////////////////////////////////////////////////////////////////////////////
class USBDEV_API  DevCtl : public QObject {
    Q_OBJECT
public:
    //! enumeric
    enum WorkStatus {
        WorkStatus_S_Disconnected = 0,     //!< device has been disconnect from device
        WorkStatus_S_ConnectToDev = 1,      //!< device has been connect to device
        WorkStatus_S_OK = 2,                //!< the device has been connected and all are OK
        WorkStatus_E_UnExpected   = 0x81,   //!< some error ocurred
    };

    //! lamp id
    enum LampId {
        LampId_FrontIr = 0,   //!< fron IR lamp,
        LampId_OuterFixat = 1 //!< the outer fixat lamp
    };

    //! the motor ID
    enum MotorId {
        MotorId_X = 1,
        MotorId_Y = 2,
        MotorId_Focus = 3,
        MotorId_Color = 4,
        MotorId_Light_Spot = 5,
        MotorId_Shutter = 6,
        MotorId_Chin_X = 7,
        MotorId_Chin_y = 8
    };

    //! sample motor control stage
    enum  SampleMotorCtl_Stage {
        SampleMotorCtl_Stage_Stop = 0,     //!< same as moveMotor( 0 )
        SampleMotorCtl_Stage_Prepare = 1,
        SampleMotorCtl_Stage_Work = 2
    };

    enum MoveMethod{
        Relative=0,
        Abosolute=1
    };


    //! dtor
    virtual ~DevCtl( ) Q_DECL_OVERRIDE;

    //! initialize, call this to do init.
    //! @note this function will drop old context and retry connect to device
    void   reinit( );

    //! return the work status
    WorkStatus  workStatus( ) const;

    /*!
     * \brief control the lamp on off
     * \param lamp   [in] the Lamp Id pre-defined
     * \param level  [in] light level, range is 0 to 255, rsvd
     * \param on_off [in] true means lamp turn on.
     */
    void  setLamp( LampId lamp, int level, bool on_off );

    /*!
     * \brief control the fixat lamp ( inner )
     * \param cx  [in] the coord. x
     * \param cy  [in] the coord. y
     * \param on_off [in] true means fixat lamp is ON
     */
    void  setFixatLamp( qint16 cx, qint16 cy, bool on_off );

    void  moveChinMotors( quint8* sps, qint32* value,MoveMethod method);

    /*!
     * \brief move spec. Motor
     * \param mot      [in]  the motor id pre-defined
     * \param sps      [in]  speed pre seconds. How many motor steps moved in 1 seconds.
     * \param dist     [in]  relative distance.
     * \param acc_flag [in]  a flag used to means use acceleration or not.
     *                       0x01 means use acceleration
     * \note  'sps' parameter can be use 0 or < 0, it will automatically use \n
     *    default speed.
     * \note  while 'acc_flag' is 0, 'sps' should be [ 0, 400 ]
     *        while 'acc_flga' is 1, 'sps' should be [ 0, 800 ]
     *
     */
    void  move5Motors( quint8 sps[5], qint32 value[5],MoveMethod method);

    /*!
     * \brief Positioning spec. Motor
     * \param mot      [in]  the motor id pre-defined
     * \param sps      [in]  speed pre seconds. How many motor steps moved in 1 seconds.
     * \param pos      [in]  absolute position
     * \param acc_flag [in]  a flag used to means use acceleration or not.
     *                       0x01 means use acceleration
     * \note  'sps' parameter can be use 0 or < 0, it will automatically use \n
     *     default speed.
     */
    void  pos5Motors( MotorId mot, qint32 sps, qint32 pos, quint8 acc_flag );

    /*!
     * \brief reset Motor, the motor moved to reset position
     * \param mot      [in]  the motor id pre-defined
     * \param sps      [in]  speed pre seconds. How many motor steps moved in 1 seconds.
     * \param pos      [in]  absolute position
     * \param acc_flag [in]  a flag used to means use acceleration or not.
     *                       0x01 means use acceleration
     * \note  'sps' parameter can be use 0 or < 0, it will automatically use \n
     *    default speed.
     */
    void  resetMotor( MotorId mot, qreal sps, qint32 pos, quint8 acc_flag );
    void  resetMotor( MotorId mot, qint32 sps, qint32 pos, quint8 acc_flag );

    /*!
     * \brief save the motor configuration data
     * \param mot [in] the motor id pre-defined
     * \param cfg [in] the configruation data, user defined.
     * \note  the cfg data is a raw binary stream, but the usb board maybe do not \n
     *   save all data. Maximum data size is 500 bytes.
     */
    void  saveMotorCfg( MotorId mot, const QByteArray &cfg );

    /*!
     * \brief contol the sample motor
     * \param stage [in] the sample motor moving stage.
     * \param sps   [in] steps per seconds
     * \param acc_flag [in] 0x01 means use acceleration
     * \note  the 'stage' has 3 value \n
     *    'Stop'    -- this is same as call motorMove() with distance 0
     *    'Prepare' -- make the sample motor moving to prepare position. while it moving \n
     *                 the busy flag in StatusData will be set to 1.
     *    'work'    -- make the sample motor working. while it moving, the busy flag is true
     */
    void  sampleMotorCtl( SampleMotorCtl_Stage stage, qint32 sps, quint8 acc_flag );


    /*!
     * \brief setFrontVideo
     * \param on_off [in] true means on, false means off
     * \note  while turn on the front video, the old framedata will \n
     *   be cleared automatically. front video is a double video that owned \n
     *   2 images.
     */
    void  setFrontVideo( bool on_off );

    /*!
     * @brief get the current profile of the device
     * @note while device workstatus is OK, user can take it
     */
    Profile  profile( ) const;

    /*!
     * \brief take the pending status data
     * \return non empty object returned if succ.
     */
    StatusData  takeNextPendingStatusData( );

    /*!
     * \brief take the pending frame data
     * \return non empty object returned if succ.
     */
    FrameData   takeNextPendingFrameData( );

    /*!
     * @brief this signal emited while work status changed.
     */
    Q_SIGNAL  void  workStatusChanged( int );

    /*!
     * @brief while a new status data generated, this signals emited
     * @note user should call takeNextPendingStatus() to get status data
     */
    Q_SIGNAL  void  newStatusData( );

    /*!
     * @brief while a new frame data generated, this signals emited
     * @note user should call takeNextPendingFrameData() to get frame data
     */
    Q_SIGNAL  void  newFrameData( );

    /*!
     * @brief while the DevCtl loaded profile from hardware, it will be emited.
     */
    Q_SIGNAL  void  newProfile( );


    static DevCtl*  createInstance( quint32 vid_pid = 0xffffa60e, quint32 cfg_id = 1 );

    //! @brief create the instance ( wait version )
    //!
    //! @since 0.2.1
    //! @param vid_pid [in] the specified vid pid.
    //! @param cfg_id  [in] optional configuration id. current is 0x01
    //! @note  the default VID_PID is pre-defined by user, current is \n
    //!    0xffffa60e
    static  DevCtl*  createInstanceSync( quint32 vid_pid = 0xffffa60e, quint32 cfg_id = 1 );



     //! \since 0.5
    //! \param buff_ptr    [in] the data want to write
    //! \param eeprom_addr [in] eeprom address
    //! \param fk [in] factory key, should be ''
    bool   readUsbEEPROM (       char *buff_ptr, int size, int eeprom_addr );

    //! \since 0.5
    bool   writeUsbEEPROM( const char *buff_ptr, int size, int eeprom_addr );



protected:
    //! ctor
    explicit DevCtl( quint32 vid_pid, quint32 cfg_id );

    DevCtl( quint32 vid_pid, quint32 cfg_id, bool );

private:
    void *m_obj;
    Q_DISABLE_COPY( DevCtl )
    friend class DevCtlPriv;

};
}
#endif
