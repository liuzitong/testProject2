﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <usbdev/main/usbdev_devctl.hxx>
#include <usbdev/main/usbdev_statusdata.hxx>
#include <usbdev/main/usbdev_framedata.hxx>
#include <usbdev/main/usbdev_profile.hxx>
#include <usbdev/main/usbdev_config.hxx>
#include <usbdev/main/usbdev_cache.hxx>
#include <QStandardItemModel>
#include <QTimer>
#include <QJsonObject>
#include <Qpair>
#include <settings.h>
#include <table_model.h>
#include <tuple>
#include "gl_image.h"

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

private:signals:
    void updateRefreshInfo(QString str);
    void updateInfo(QString str);

private slots:
    void showDevInfo(QString);
    void showDevRefreshInfo(QString str);
    void refreshStatus();
    void refreshVideo();
    void refreshConnectionStatus(int);
    void updateProfile();

    void on_tabWidget_currentChanged(int index);

    void on_action_chooseDevice_triggered();

    void on_action_readLocalData_triggered();

    void on_action_saveLocalData_triggered();

    void on_action_saveConfig_triggered();

    void on_action_readConfigFromLocal_triggered();

    void on_action_updateConfigToLower_triggered();

    void on_action_downloadConfig_triggered();

    void on_spinBox_centerLightAndOtherDA_valueChanged(int arg1);

    void on_spinBox_bigAndSmallDiamondDA_valueChanged(int arg1);

    void on_spinBox_lightR_valueChanged(int arg1);

    void on_spinBox_lightG_valueChanged(int arg1);

    void on_spinBox_lightB_valueChanged(int arg1);

    void on_comboBox_lightSelect_1_currentIndexChanged(int index);

    void on_comboBox_lightSelect_2_currentIndexChanged(int index);

    void on_comboBox_lampIndex_currentIndexChanged(int index);

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

    void on_pushButton_light1_clicked();

    void on_pushButton_light2_clicked();

    void on_pushButton_light3_clicked();

    void on_comboBox_color_currentIndexChanged(int index);

    void on_spinBox_colorSlot_valueChanged(int arg1);

    void on_spinBox_colorMotorPos_2_valueChanged(int arg1);

    void on_comboBox_spotSize_currentIndexChanged(int);

    void on_spinBox_spotSlot_valueChanged(int arg1);

    void on_spinBox_spotMotorPos_2_valueChanged(int arg1);

    void on_spinBox_DbSetting_valueChanged(int arg1);

    void on_spinBox_DbColorPos_valueChanged(int arg1);

    void on_spinBox_DbSpotPos_valueChanged(int arg1);

    void on_lineEdit_coordX_textChanged(const QString &arg1){fillXYMotorAndFocalInfoByXYCoord();};

    void on_lineEdit_coordY_textChanged(const QString &arg1){fillXYMotorAndFocalInfoByXYCoord();};

    void on_spinBox_shutterOpenPos_valueChanged(int arg1);

    void on_pushButton_colorTest_clicked();

    void on_pushButton_spotTest_clicked();

    void on_pushButton_focalTest_clicked();

    void on_pushButton_dbTest_clicked();

    void on_pushButton_staticCastTest_clicked();

    void on_pushButton_shuterTest_clicked();

    void on_comboBox_testFucntion_currentIndexChanged(int index);

    void on_pushButton_testStart_clicked();

    void on_pushButton_readCache_clicked();

    void on_checkBox_IO_stateChanged(int arg1);

    void on_checkBox_startRefreshInfo_stateChanged(int arg1);

    void on_checkBox_RefreshIO_stateChanged(int arg1);

private:
    void initData();
    void initTable();
    void moveChinMotors(UsbDev::DevCtl::MoveMethod);
    void move5Motors(UsbDev::DevCtl::MoveMethod);
    void fillXYMotorAndFocalInfoByXYCoord();

    //获取XY电机位置还有焦距
    bool getXYMotorPosAndFocalDistFromCoord(const CoordSpacePosInfo& coordSpacePosInfo,CoordMotorPosFocalDistInfo& coordMotorPosFocalDistInfo);
    void staticCastTest(const CoordMotorPosFocalDistInfo& dot,int spotSlot ,int colorSlot,int db,int* sps,int durationTime,int shutterPos);
    void moveCastTest(const CoordSpacePosInfo& dotBegin,const CoordSpacePosInfo& dotEnd,int spotSlot ,int colorSlot,float stepLength,int db,int* sps);
    void init();
    void initDevCtl();
    void uninitDevCtl();
    void initWidget();
    int interpolation(int value[4],QPointF loc);
    int getFocusMotorPosByDist(int focalDist,int spotSlot);
    void initConfigUI();
    void refreshConfigUI();
    void refreshConfigDataByUI();
    Ui::MainWindow *ui;
    TableModel *m_colorPosTableModel;                       //颜色表
    TableModel *m_spotPosTableModel;                        //光斑表
    TableModel *m_spotDistFocalPosModel;                    //焦距参数表
    TableModel *m_dbColorSpotPosTableModel;                 //DB参数表
    TableModel *m_speedStepTimeTableModel;                  //速度与步数
    TableModel *m_diamondCenterSpotFocalPosTableModel;      //菱形中心点时测试时, 焦距电机所需走动的步数 7个光斑
    TableModel *m_xyDistTableModel;                         //xy桌标对应的距离 本机数据
    TableModel *m_dbAngleDampingTableModel;                 //DB离心度衰减参数表 本机数据
    UsbDev::DevCtl *m_devCtl=NULL;
    UsbDev::Config m_config;
    LocalTableData m_localTableData;
    UsbDev::StatusData m_statusData;
    UsbDev::FrameData m_frameData;
    UsbDev::Profile m_profile;
    QTimer* m_timer=NULL;
    Settings m_settings;
    quint8* pixData=NULL;
    int m_width,m_height;

    void readLocalData(QString filePath);
    void readLocalConfig(QString filePath);

//    QTimer* m_videoTimer=NULL;
//    int m_videoCount=0;


};

#endif // MAINWINDOW_H
