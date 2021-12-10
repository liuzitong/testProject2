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
#include <local_data.h>
#include <table_model.h>


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

    void initTable();
    void updateConfig();
private slots:
//    void saveConfig();
    void showDevInfo(QString);
    void refreshStatus();
    void refreshVideo();
    void refreshConnectionStatus(int);
    void updateProfile();
//    void updateConfig();

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

    void on_action_chooseDevice_triggered();

    void on_tabWidget_currentChanged(int index);

    void on_action_readLocalMotorPosTable_triggered();

    void on_action_saveMotorPosTable_triggered();

    void on_action_saveConfig_triggered();

    void on_action_readConfigFromLoacal_triggered();

    void on_action_updateConfigToLower_triggered();

    void on_action_downloadConfig_triggered();

private:
    void moveChinMotors(UsbDev::DevCtl::MoveMethod);
    void move5Motors(UsbDev::DevCtl::MoveMethod);
    bool getXYMotorPosAndFocalDistFromCoord(DotInfo& dotInfo);
    void staticCastTest(DotInfo dotInfo,int spotSlot ,int colorSlot,int db,int sps,int durationTime,int shutterPos);
    void moveCastTest(DotInfo dotBegin,DotInfo dotEnd,int spotSlot ,int colorSlot,int stepCount,int db,int sps);
    void init();
    void uninit();
    int interpolation(int value[4],QPoint loc);
    int getFocusMotorPosByDist(int focalDist,int spotSlot);
    Ui::MainWindow *ui;
    TableModel *m_colorPosTableModel,*m_spotPosTableModel,*m_dbColorSpotPosTableModel,*m_spotDistFocalPosModel;
    UsbDev::DevCtl *m_devCtl=NULL;
    UsbDev::Config m_config;
    UsbDev::StatusData m_statusData;
    UsbDev::FrameData m_frameData;
    UsbDev::Profile m_profile;
    QTimer* m_timer=NULL;
    LocalData m_localData;
    int m_width,m_height;
};

#endif // MAINWINDOW_H
