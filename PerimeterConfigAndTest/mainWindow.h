#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <usbdev/main/usbdev_devctl.hxx>
#include <usbdev/main/usbdev_statusdata.hxx>
#include <usbdev/main/usbdev_framedata.hxx>
#include <usbdev/main/usbdev_profile.hxx>
#include <usbdev/main/usbdev_config.hxx>
#include <QStandardItemModel>
#include <QTimer>
#include <QJsonObject>
#include <Qpair>
#include <local_config.h>
#include <slot_step_model.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString PID,VID;

private slots:
    void showDevInfo(QString);
    void refreshStatus();
    void refreshVideo();
    void refreshConnectionStatus(int);
    void on_actionchooseDevice_triggered();

    void on_pushButton_relativeMoveChin_clicked();

    void on_pushButton_absoluteMoveChin_clicked();

    void on_pushButton_relativeMove5Motors_clicked();

    void on_pushButton_absoluteMove5Motors_clicked();

    void on_pushButton_resetCheckedMotors_clicked();

    void on_pushButton_cameraSwitch_clicked();

    void on_pushButton_chinMoveUp_pressed();

    void on_pushButton_chinMoveUp_released();

    void on_pushButton_chinMoveDown_pressed();

    void on_pushButton_chinMoveDown_released();

    void on_pushButton_chinMoveLeft_pressed();

    void on_pushButton_chinMoveLeft_released();

    void on_pushButton_chinMoveRight_pressed();

    void on_pushButton_chinMoveRight_released();

    void on_pushButton_lightSwitch_clicked();

    void on_comboBox_lightSelect_currentIndexChanged(int index);

    void on_pushButton_testStart_clicked();

    void on_comboBox_spotSize_currentIndexChanged(int);

    void on_spinBox_spotSlot_valueChanged(int arg1);

    void on_comboBox_color_currentIndexChanged(int index);

    void on_spinBox_colorSlot_valueChanged(int arg1);

    void on_pushButton_shuterMotor_clicked();

    void on_checkBox_autoCalcFocalDist_stateChanged(int arg1);

    void on_checkBox_useConfigPos_stateChanged(int arg1);

    void on_comboBox_testFucntion_currentIndexChanged(int index);


private:
    void moveChinMotors(UsbDev::DevCtl::MoveMethod);
    void move5Motors(UsbDev::DevCtl::MoveMethod);
    bool getXYMotorPosAndFocalDistFromCoord(DotInfo& dotInfo);
    void staticCastTest(int motorXPost,int motorYPos,int focalDist,int spotSlot ,int colorSlot,int db,int sps,int durationTime,int shutterPos);
    void moveCastTest();
    void init();
    void uninit();
    int interpolation(int value[4],QPoint loc);
    int getFocusMotorPosByDist(int focalDist,int spotSlot);
    Ui::MainWindow *ui;
    UsbDev::DevCtl *m_devCtl=NULL;
    UsbDev::Config m_config;
    UsbDev::StatusData m_statusData;
    UsbDev::FrameData m_frameData;
    UsbDev::Profile m_profile;
    QTimer* m_timer=NULL;
    LocalConfig m_localConfig;
    SlotPosModel* m_slotPosModel=NULL;

};

#endif // MAINWINDOW_H
