#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UsbViewer/UsbViewerQt.h"
#include <QDebug>
#include <QSettings>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <usbdev/main/usbdev_statusdata.hxx>
#include <QImage>
#include <QPainter>
#include <math.h>
#include <QTime>
#include <thread>
#include <future>
#include <QFuture>
#include <QtConcurrent>
#include <array>
#include <QSharedPointer>
#include <QStylePainter>
#include "RbTableHeaderView.h"
#include <QDesktopWidget>
#include <QtGui>
#include <QFileDialog>
#include "windows.h"
#include <QDir>


#pragma execution_character_set("utf-8")
// 不能删
static std::shared_ptr<spdlog::logger> logger=spdlog::get("logger");
static QString buffToQStr(const char* buff,size_t length)
{
    QString str;
    QByteArray byteArray= QByteArray::fromRawData(buff,length);
    for(int i = 0; i< byteArray.length(); i++){
       QString str1 = QString("%1").arg(i,2,10, QLatin1Char('0'));


       uchar temp=static_cast<uchar>(byteArray[i]);
       QString str2 = QString("%1").arg(temp,2,16, QLatin1Char('0'));
       str.append(QString("%1:%2 ").arg(str1).arg(str2));
    }
    return qPrintable(str);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(logger!=NULL) logger = spdlog::rotating_logger_mt("logger", "logs/perimeterConfig.txt", 1024*1024, 30);
//    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);                    // 禁止最大化按钮
    setWindowFlag(Qt::WindowMaximizeButtonHint,false);
    m_width=width();m_height=height();
    setFixedSize(m_width,m_height);                                  // 禁止拖动窗口大小
//    QSettings *configIni = new QSettings("para.ini", QSettings::IniFormat);
    VID=m_settings.m_VID;
    PID=m_settings.m_PID;
    m_timer=new QTimer();
    connect(m_timer,&QTimer::timeout,[&](){ui->label_connectionStatus->setText("连接断开");});
    init();
}


void MainWindow::init()
{
    initData();
    initTable();
    quint32 vid_pid=VID.toInt(nullptr,16)<<16|PID.toInt(nullptr,16);
    m_devCtl=UsbDev::DevCtl::createInstance(vid_pid);
    ui->label_VID->setText(VID);
    ui->label_PID->setText(PID);
    connect(m_devCtl,&UsbDev::DevCtl::workStatusChanged,this,&MainWindow::refreshConnectionStatus);
    connect(m_devCtl,&UsbDev::DevCtl::updateInfo,this,&MainWindow::showDevInfo);
    connect(m_devCtl,&UsbDev::DevCtl::newStatusData,this,&MainWindow::refreshStatus);
    connect(m_devCtl,&UsbDev::DevCtl::newFrameData,this,&MainWindow::refreshVideo);
    connect(m_devCtl,&UsbDev::DevCtl::newProfile,this,&MainWindow::updateProfile);
    connect(m_devCtl,&UsbDev::DevCtl::newConfig,this,&MainWindow::updateConfig);

    on_comboBox_color_currentIndexChanged(1);
    on_comboBox_spotSize_currentIndexChanged(1);

}

void MainWindow::initData()
{
    QString configPath=m_settings.localConfig;
    QString dataPath=m_settings.localData;
    readLocalConfig(configPath);
    readLocalData(dataPath);
}



void MainWindow::initTable()
{
    m_colorPosTableModel=new TableModel();
    m_colorPosTableModel->m_column=1;
    m_colorPosTableModel->m_row=6;
    m_colorPosTableModel->m_hozHeader<<"步数";
    m_colorPosTableModel->m_vertHeader<<"全透";
    m_colorPosTableModel->m_modelData=m_config.switchColorMotorPosPtr();
    ui->tableView_colorSlotPos->setModel(m_colorPosTableModel);
    ui->tableView_colorSlotPos->setCornerName("颜色");
    ui->tableView_colorSlotPos->verticalHeader()->setVisible(true);


    m_spotPosTableModel=new TableModel();
    m_spotPosTableModel->m_column=1;
    m_spotPosTableModel->m_row=8;
    m_spotPosTableModel->m_hozHeader<<"步数";
    m_spotPosTableModel->m_vertHeader<<"全透";
    m_spotPosTableModel->m_modelData=m_config.switchLightSpotMotorPosPtr();
    ui->tableView_spotSlotPos->setModel(m_spotPosTableModel);
    ui->tableView_spotSlotPos->setCornerName("光斑");
    ui->tableView_spotSlotPos->verticalHeader()->setVisible(true);

    auto tableData=m_settings.m_localTableData.m_xyDistTableData;
    m_xyDistTableModel=new TableModel();
    m_xyDistTableModel->m_column=tableData.m_column;
    m_xyDistTableModel->m_row=tableData.m_row;
    m_xyDistTableModel->m_hozHeader<<"X"<<"Y";
    m_xyDistTableModel->m_modelData=tableData.m_data;
    ui->tableView_XYDistTable->setModel(m_xyDistTableModel);
    ui->tableView_XYDistTable->verticalHeader()->setVisible(false);

    m_spotDistFocalPosModel=new TableModel();
    m_spotDistFocalPosModel->m_column=7;
    m_spotDistFocalPosModel->m_row=25;
    m_spotDistFocalPosModel->m_hozHeader<<"光斑1"<<"光斑2"<<"光斑3"<<"光斑4"<<"光斑5"<<"光斑6"<<"光斑7";
    for(int i=80;i<=320;i+=10){m_spotDistFocalPosModel->m_vertHeader<<QString::number(i);}
    m_spotDistFocalPosModel->m_modelData=(int*)m_config.focalLengthMotorPosMappingPtr();
    ui->tableView_focalPosTable->setModel(m_spotDistFocalPosModel);
    ui->tableView_focalPosTable->setCornerName("距离");
    ui->tableView_focalPosTable->verticalHeader()->setVisible(true);

    m_dbColorSpotPosTableModel=new TableModel();
    m_dbColorSpotPosTableModel->m_column=2;
    m_dbColorSpotPosTableModel->m_row=52;
    m_dbColorSpotPosTableModel->m_hozHeader<<"颜色步"<<"尺寸步";
    for(int i=0;i<=51;i++){m_dbColorSpotPosTableModel->m_vertHeader<<QString::number(i);}
    m_dbColorSpotPosTableModel->m_modelData=(int*)m_config.DbPosMappingPtr();
    ui->tableView_dbColorSpotPosTable->setModel(m_dbColorSpotPosTableModel);
    ui->tableView_dbColorSpotPosTable->setCornerName("DB");
    ui->tableView_dbColorSpotPosTable->verticalHeader()->setVisible(true);

    m_diamondCenterSpotFocalPosTableModel=new TableModel();
    m_diamondCenterSpotFocalPosTableModel->m_column=1;
    m_diamondCenterSpotFocalPosTableModel->m_row=7;
    m_diamondCenterSpotFocalPosTableModel->m_hozHeader<<"焦距步";
    for(int i=1;i<=7;i++){m_diamondCenterSpotFocalPosTableModel->m_vertHeader<<QString::number(i);}
    m_diamondCenterSpotFocalPosTableModel->m_modelData=m_config.focalLengthMotorPosForDiamondCenterTestPtr();
    ui->tableView_diamondFocalPosTable->setModel(m_diamondCenterSpotFocalPosTableModel);
    ui->tableView_diamondFocalPosTable->setCornerName("光斑");
    ui->tableView_diamondFocalPosTable->verticalHeader()->setVisible(true);

    m_speedStepTimeTableModel=new TableModel();
    m_speedStepTimeTableModel->m_column=1;
    m_speedStepTimeTableModel->m_row=7;
    m_speedStepTimeTableModel->m_hozHeader<<"时间";
    for(int i=1;i<=7;i++){m_speedStepTimeTableModel->m_vertHeader<<QString::number(i);}
    m_speedStepTimeTableModel->m_modelData=m_config.stepTimePtr();
//    m_speedStepTimeTableModel->m_modelData=m_config.switchColorMotorPosPtr();
    ui->tableView_speedStepTimeTable->setModel(m_speedStepTimeTableModel);
    ui->tableView_speedStepTimeTable->setCornerName("速度");
    ui->tableView_speedStepTimeTable->verticalHeader()->setVisible(true);

    tableData=m_settings.m_localTableData.m_dbAngleDampingTableData;
    m_dbAngleDampingTableModel=new TableModel();
    m_dbAngleDampingTableModel->m_column=tableData.m_column;
    m_dbAngleDampingTableModel->m_row=tableData.m_row;
    m_dbAngleDampingTableModel->m_hozHeader<<"DB衰减";
    for(int i=0;i<=90;i+=2){m_dbAngleDampingTableModel->m_vertHeader<<QString::number(i);}
    m_dbAngleDampingTableModel->m_modelData=tableData.m_data;
    ui->tableView_dbAngleDampingTable->setModel(m_dbAngleDampingTableModel);
    ui->tableView_dbAngleDampingTable->setCornerName("离心度");
    ui->tableView_dbAngleDampingTable->verticalHeader()->setVisible(true);

    ui->tableView_mainMotorPosTable->setData(m_settings.m_localTableData.m_mainPosTableData.m_data);
    ui->tableView_secondaryPosTable->setData(m_settings.m_localTableData.m_secondaryPosTableData.m_data);
}




void MainWindow::uninit()
{
    m_timer->stop();
    ui->label_connectionStatus->setText("未连接");
    disconnect(m_devCtl,&UsbDev::DevCtl::workStatusChanged,this,&MainWindow::refreshConnectionStatus);
    disconnect(m_devCtl,&UsbDev::DevCtl::updateInfo,this,&MainWindow::showDevInfo);
    disconnect(m_devCtl,&UsbDev::DevCtl::newStatusData,this,&MainWindow::refreshStatus);
    disconnect(m_devCtl,&UsbDev::DevCtl::newFrameData,this,&MainWindow::refreshVideo);
    delete m_devCtl;
}

int MainWindow::interpolation(int value[], QPoint loc)
{
    int secondVal[2];
    secondVal[0]=value[0]+(value[1]-value[0])*(loc.x()/6.0);
    secondVal[1]=value[2]+(value[3]-value[2])*(loc.x()/6.0);
    int ret=secondVal[0]+(secondVal[1]-secondVal[0])*(loc.y()/6.0);
    return ret;
}


int MainWindow::getFocusMotorPosByDist(int focalDist,int spotSlot)
{
    if(m_config.isEmpty()) {return 0;}
    auto map = m_config.focalLengthMotorPosMappingPtr();
    int indexDist= floor(focalDist/10)-8;
    int pos1=map[indexDist][spotSlot];
    int pos2=map[indexDist+1][spotSlot];
    int focalMotorPos=pos1+(pos2-pos1)*(focalDist%10)/10;
    return focalMotorPos;
    return 0;
}

void MainWindow::refreshConfigUI()
{
    bool ok;
    ui->lineEdit_deviceSerialNo->setText(QString::number(m_config.deviceIDRef()));
    ui->lineEdit_centralLightDA->setText(QString::number(m_config.centerFixationLampDARef()));
    ui->lineEdit_bigDiamond1DA->setText(QString::number(m_config.bigDiamondfixationLampDAPtr()[0]));
    ui->lineEdit_bigDiamond2DA->setText(QString::number(m_config.bigDiamondfixationLampDAPtr()[1]));
    ui->lineEdit_bigDiamond3DA->setText(QString::number(m_config.bigDiamondfixationLampDAPtr()[2]));
    ui->lineEdit_bigDiamond4DA->setText(QString::number(m_config.bigDiamondfixationLampDAPtr()[3]));
    ui->lineEdit_smallDiamond1DA->setText(QString::number(m_config.smallDiamondFixationLampDAPtr()[0]));
    ui->lineEdit_smallDiamond2DA->setText(QString::number(m_config.smallDiamondFixationLampDAPtr()[1]));
    ui->lineEdit_smallDiamond3DA->setText(QString::number(m_config.smallDiamondFixationLampDAPtr()[2]));
    ui->lineEdit_smallDiamond4DA->setText(QString::number(m_config.smallDiamondFixationLampDAPtr()[3]));
    ui->lineEdit_yellowBackGroundLampDa->setText(QString::number(m_config.yellowBackgroundLampDARef()));
    ui->lineEdit_whiteBackGroundLampR->setText(QString::number(m_config.whiteBackgroundLampDAPtr()[0]));
    ui->lineEdit_whiteBackGroundLampG->setText(QString::number(m_config.whiteBackgroundLampDAPtr()[1]));
    ui->lineEdit_whiteBackGroundLampB->setText(QString::number(m_config.whiteBackgroundLampDAPtr()[2]));
    ui->lineEdit_centerInfraredLampDA->setText(QString::number(m_config.centerInfraredLampDARef()));
    ui->lineEdit_borderLampDA->setText(QString::number(m_config.borderInfraredLampDARef()));
    ui->lineEdit_eyeGlassLampDa->setText(QString::number(m_config.eyeglassFrameLampDARef()));
    ui->lineEdit_whiteLampEnvLightAlarm->setText(QString::number(m_config.environmentAlarmLightDAPtr()[0]));
    ui->lineEdit_yellowLampEnvLightAlarm->setText(QString::number(m_config.environmentAlarmLightDAPtr()[1]));
    ui->lineEdit_whiteLampPupilGray->setText(QString::number(m_config.pupilGreyThresholdDAPtr()[0]));
    ui->lineEdit_yellowLampPupilGray->setText(QString::number(m_config.pupilGreyThresholdDAPtr()[1]));
    ui->lineEdit_focusUnite->setText(QString::number(m_config.focusPosForSpotAndColorChangeRef()));
    ui->lineEdit_shutterOpen->setText(QString::number(m_config.shutterOpenPosRef()));
    ui->lineEdit_centerX->setText(QString::number(m_config.mainTableCenterXRef()));
    ui->lineEdit_centerY->setText(QString::number(m_config.mainTableCenterYRef()));
    ui->lineEdit_secondaryCenterX->setText(QString::number(m_config.secondaryTableCenterXRef()));
    ui->lineEdit_secondaryCenterY->setText(QString::number(m_config.secondaryTableCenterYRef()));
    ui->lineEdit_castLightDA->setText(QString::number(m_config.maximunProjectionLightADPresetRef()));
    ui->lineEdit_lightCorrectionFocus->setText(QString::number(m_config.focalLengthMotorPosForLightCorrectionRef()));
    ui->lineEdit_lightCorrectionX->setText(QString::number(m_config.xMotorPosForLightCorrectionRef()));
    ui->lineEdit_lightCorrectionY->setText(QString::number(m_config.yMotorPosForLightCorrectionRef()));
    ui->lineEdit_diamondCenterX->setText(QString::number(m_config.xMotorPosForDiamondCenterTestRef()));
    qDebug()<<m_config.xMotorPosForDiamondCenterTestRef();
    ui->lineEdit_diamondCenterY->setText(QString::number(m_config.yMotorPosForDiamondCenterTestRef()));
    qDebug()<<m_config.yMotorPosForDiamondCenterTestRef();
    ui->lineEdit_stepLength->setText(QString::number(m_config.stepLengthRef(),'f',2));
    qDebug()<<m_config.stepLengthRef();

//    ui->tableView_dbColorSpotPosTable->viewport()->update();
//    ui->tableView_speedStepTimeTable->viewport()->update();
}

void MainWindow::refreshConfigDataByUI()
{
    bool ok;
    m_config.deviceIDRef()=ui->lineEdit_deviceSerialNo->text().toInt(&ok);                              //if(!ok) return;
    m_config.centerFixationLampDARef()=ui->lineEdit_centralLightDA->text().toInt(&ok);                  //if(!ok) return;
    m_config.bigDiamondfixationLampDAPtr()[0]=ui->lineEdit_bigDiamond1DA->text().toInt(&ok);            //if(!ok) return;
    m_config.bigDiamondfixationLampDAPtr()[1]=ui->lineEdit_bigDiamond2DA->text().toInt(&ok);            //if(!ok) return;
    m_config.bigDiamondfixationLampDAPtr()[2]=ui->lineEdit_bigDiamond3DA->text().toInt(&ok);            //if(!ok) return;
    m_config.bigDiamondfixationLampDAPtr()[3]=ui->lineEdit_bigDiamond4DA->text().toInt(&ok);            //if(!ok) return;
    m_config.smallDiamondFixationLampDAPtr()[0]=ui->lineEdit_smallDiamond1DA->text().toInt(&ok);        //if(!ok) return;
    m_config.smallDiamondFixationLampDAPtr()[1]=ui->lineEdit_smallDiamond2DA->text().toInt(&ok);        //if(!ok) return;
    m_config.smallDiamondFixationLampDAPtr()[2]=ui->lineEdit_smallDiamond3DA->text().toInt(&ok);        //if(!ok) return;
    m_config.smallDiamondFixationLampDAPtr()[3]=ui->lineEdit_smallDiamond4DA->text().toInt(&ok);        //if(!ok) return;
    m_config.yellowBackgroundLampDARef()=ui->lineEdit_yellowBackGroundLampDa->text().toInt(&ok);        //if(!ok) return;
    m_config.whiteBackgroundLampDAPtr()[0]=ui->lineEdit_whiteBackGroundLampR->text().toInt(&ok);        //if(!ok) return;
    m_config.whiteBackgroundLampDAPtr()[1]=ui->lineEdit_whiteBackGroundLampG->text().toInt(&ok);        //if(!ok) return;
    m_config.whiteBackgroundLampDAPtr()[2]=ui->lineEdit_whiteBackGroundLampB->text().toInt(&ok);        //if(!ok) return;
    m_config.centerInfraredLampDARef()=ui->lineEdit_centerInfraredLampDA->text().toInt(&ok);            //if(!ok) return;
    m_config.borderInfraredLampDARef()=ui->lineEdit_borderLampDA->text().toInt(&ok);                    //if(!ok) return;
    m_config.eyeglassFrameLampDARef()=ui->lineEdit_eyeGlassLampDa->text().toInt(&ok);                   //if(!ok) return;
    m_config.environmentAlarmLightDAPtr()[0]=ui->lineEdit_whiteLampEnvLightAlarm->text().toInt(&ok);
    m_config.environmentAlarmLightDAPtr()[1]=ui->lineEdit_yellowLampEnvLightAlarm->text().toInt(&ok);
    m_config.pupilGreyThresholdDAPtr()[0]=ui->lineEdit_whiteLampPupilGray->text().toInt(&ok);
    m_config.pupilGreyThresholdDAPtr()[1]=ui->lineEdit_yellowLampPupilGray->text().toInt(&ok);
    m_config.focusPosForSpotAndColorChangeRef()=ui->lineEdit_focusUnite->text().toInt(&ok);
    m_config.shutterOpenPosRef()=ui->lineEdit_shutterOpen->text().toInt(&ok);
    m_config.mainTableCenterXRef()=ui->lineEdit_centerX->text().toInt(&ok);
    m_config.mainTableCenterYRef()=ui->lineEdit_centerY->text().toInt(&ok);
    m_config.secondaryTableCenterXRef()=ui->lineEdit_secondaryCenterX->text().toInt(&ok);
    m_config.secondaryTableCenterYRef()=ui->lineEdit_secondaryCenterY->text().toInt(&ok);
    m_config.maximunProjectionLightADPresetRef()=ui->lineEdit_castLightDA->text().toInt(&ok);
    m_config.focalLengthMotorPosForLightCorrectionRef()=ui->lineEdit_lightCorrectionFocus->text().toInt(&ok);
    m_config.xMotorPosForLightCorrectionRef()=ui->lineEdit_lightCorrectionX->text().toInt(&ok);
    m_config.yMotorPosForLightCorrectionRef()=ui->lineEdit_lightCorrectionY->text().toInt(&ok);
    m_config.xMotorPosForDiamondCenterTestRef()=ui->lineEdit_diamondCenterX->text().toInt(&ok);
    qDebug()<<ui->lineEdit_diamondCenterX->text().toInt(&ok);
    m_config.yMotorPosForDiamondCenterTestRef()=ui->lineEdit_diamondCenterY->text().toInt(&ok);
    qDebug()<<ui->lineEdit_diamondCenterY->text().toInt(&ok);
    m_config.stepLengthRef()=ui->lineEdit_stepLength->text().toFloat(&ok);
    qDebug()<<ui->lineEdit_stepLength->text().toFloat(&ok);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::refreshStatus()
{
    spdlog::info("refreshStatus");
    m_timer->start(1000);
    ui->label_connectionStatus->setText("保持连接");
    m_statusData=m_devCtl->takeNextPendingStatusData();
    ui->label_stateX->setText(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId::MotorId_X)?"忙":"闲");
    ui->label_stateY->setText(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId::MotorId_Y)?"忙":"闲");
    ui->label_stateFocus->setText(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId::MotorId_Focus)?"忙":"闲");
    ui->label_stateColor->setText(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId::MotorId_Color)?"忙":"闲");
    ui->label_stateSpot->setText(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId::MotorId_Light_Spot)?"忙":"闲");
    ui->label_stateShutter->setText(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId::MotorId_Shutter)?"忙":"闲");
    ui->label_stateChinHoz->setText(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId::MotorId_Chin_Hoz)?"忙":"闲");
    ui->label_stateChinVert->setText(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId::MotorId_Chin_Vert)?"忙":"闲");
    ui->label_answerState->setText(m_statusData.answerpadStatus()?"按下":"松开");
    ui->label_eyeglassStatus->setText(m_statusData.eyeglassStatus()?"升起":"放下");
    ui->label_castLightDA->setText(QString(m_statusData.castLightDA()));
    ui->label_environmentDA->setText(QString(m_statusData.envLightDA()));
}


void MainWindow::refreshVideo()
{
    spdlog::info("refreshVideo");
    m_frameData=m_devCtl->takeNextPendingFrameData();
    uchar* data=(uchar*)m_frameData.rawData().data();
    QSize size=m_profile.videoSize();
    QImage image(data,size.width(),size.height(),QImage::Format::Format_Grayscale8);
    QPainter painter(ui->openGLWidget);
    QPixmap pix;
    pix.convertFromImage(image);
    painter.begin(ui->openGLWidget);
    painter.drawPixmap(0,0,pix.width(), pix.height(),pix);
    painter.end();
    auto str=("frame time stamp:"+buffToQStr((const char*)(data)+4,4)).toStdString().c_str();
    spdlog::info(str);
}

void MainWindow::refreshConnectionStatus(int status)
{
    switch (status)
    {
    case UsbDev::DevCtl::WorkStatus::WorkStatus_E_UnExpected:ui->label_connectionStatus->setText("连接异常");break;
    case UsbDev::DevCtl::WorkStatus::WorkStatus_S_ConnectToDev:ui->label_connectionStatus->setText("正在连接");break;
    case UsbDev::DevCtl::WorkStatus::WorkStatus_S_Disconnected:ui->label_connectionStatus->setText("连接断开");break;
    case UsbDev::DevCtl::WorkStatus::WorkStatus_S_OK:ui->label_connectionStatus->setText("连接正常");break;
    }
    m_timer->start(1000);
}

//TODO
void MainWindow::updateProfile()
{
    using x=UsbDev::DevCtl;
    showDevInfo("Profile Got.");
    auto profile=m_devCtl->profile();
    ui->label_xMotorRange->setText(QString("%d-%d").arg(profile.motorRange(x::MotorId_X).first).arg(profile.motorRange(x::MotorId_X).second));
    ui->label_yMotorRange->setText(QString("%d-%d").arg(profile.motorRange(x::MotorId_Y).first).arg(profile.motorRange(x::MotorId_Y).second));
    ui->label_spotMotorRange->setText(QString("%d-%d").arg(profile.motorRange(x::MotorId_Light_Spot).first).arg(profile.motorRange(x::MotorId_Light_Spot).second));
    ui->label_shutterMotorRange->setText(QString("%d-%d").arg(profile.motorRange(x::MotorId_Shutter).first).arg(profile.motorRange(x::MotorId_Shutter).second));
    ui->label_focalMotorRange->setText(QString("%d-%d").arg(profile.motorRange(x::MotorId_Focus).first).arg(profile.motorRange(x::MotorId_Focus).second));
    ui->label_colorMotorRange->setText(QString("%d-%d").arg(profile.motorRange(x::MotorId_Color).first).arg(profile.motorRange(x::MotorId_Color).second));
    ui->label_chinHozMotorRange->setText(QString("%d-%d").arg(profile.motorRange(x::MotorId_Chin_Hoz).first).arg(profile.motorRange(x::MotorId_Chin_Hoz).second));
    ui->label_chinVertMotorRange->setText(QString("%d-%d").arg(profile.motorRange(x::MotorId_Chin_Vert).first).arg(profile.motorRange(x::MotorId_Chin_Vert).second));
}

void MainWindow::updateConfig()
{
    showDevInfo("Config Got.");
}

void MainWindow::on_pushButton_cameraSwitch_clicked()
{
    if(!m_statusData.isEmpty())
        m_devCtl->setFrontVideo(!m_statusData.cameraStatus());
    else
        showDevInfo("empty status");
}

void MainWindow::on_pushButton_chinMoveUp_pressed()
{
    if(m_profile.isEmpty()){showDevInfo("empty profile");return;}
    qint32 value[2]={0};quint8 speed[2]={0};
    speed[1]=ui->spinBox_speedChinMove->text().toInt();
    value[1]=m_profile.motorRange(UsbDev::DevCtl::MotorId::MotorId_Y).first;
    m_devCtl->moveChinMotors(speed,value,UsbDev::DevCtl::MoveMethod::Abosolute);
}

void MainWindow::on_pushButton_chinMoveUp_released()
{
    qint32 value[2]={0};quint8 speed[2]={0};
    m_devCtl->moveChinMotors(speed,value,UsbDev::DevCtl::MoveMethod::Abosolute);
}

void MainWindow::on_pushButton_chinMoveDown_pressed()
{
    if(m_profile.isEmpty()){showDevInfo("empty profile");return;}
    qint32 value[2]={0};quint8 speed[2]={0};
    speed[1]=ui->spinBox_speedChinMove->text().toInt();
    value[1]=m_profile.motorRange(UsbDev::DevCtl::MotorId::MotorId_Y).second;
    m_devCtl->moveChinMotors(speed,value,UsbDev::DevCtl::MoveMethod::Abosolute);
}

void MainWindow::on_pushButton_chinMoveDown_released()
{
    qint32 value[2]={0};quint8 speed[2]={0};
    m_devCtl->moveChinMotors(speed,value,UsbDev::DevCtl::MoveMethod::Abosolute);
}

void MainWindow::on_pushButton_chinMoveLeft_pressed()
{
    if(m_profile.isEmpty()){showDevInfo("empty profile");return;}
    qint32 value[2]={0};quint8 speed[2]={0};
    speed[0]=ui->spinBox_speedChinMove->text().toInt();
    value[0]=m_profile.motorRange(UsbDev::DevCtl::MotorId::MotorId_X).first;
    m_devCtl->moveChinMotors(speed,value,UsbDev::DevCtl::MoveMethod::Abosolute);
}

void MainWindow::on_pushButton_chinMoveLeft_released()
{
    qint32 value[2]={0};quint8 speed[2]={0};
    m_devCtl->moveChinMotors(speed,value,UsbDev::DevCtl::MoveMethod::Abosolute);
}

void MainWindow::on_pushButton_chinMoveRight_pressed()
{
    if(m_profile.isEmpty()){showDevInfo("empty profile");return;}
    qint32 value[2]={0};quint8 speed[2]={0};
    speed[0]=ui->spinBox_speedChinMove->text().toInt();
    value[0]=m_profile.motorRange(UsbDev::DevCtl::MotorId::MotorId_X).second;
    m_devCtl->moveChinMotors(speed,value,UsbDev::DevCtl::MoveMethod::Abosolute);
}

void MainWindow::on_pushButton_chinMoveRight_released()
{
    qint32 value[2]={0};quint8 speed[2]={0};
    m_devCtl->moveChinMotors(speed,value,UsbDev::DevCtl::MoveMethod::Abosolute);
}

void MainWindow::on_pushButton_lightSwitch_clicked()
{
    UsbDev::DevCtl::LampId lampId=(UsbDev::DevCtl::LampId)ui->comboBox_lightSelect->currentIndex();
    if(lampId!=UsbDev::DevCtl::LampId::LampId_whiteBackground)
    {
        m_devCtl->setLamp(lampId,ui->comboBox_lampNumber->currentIndex(),ui->lineEdit_lightDAR->text().toInt());
    }
    else
    {
        int r=ui->lineEdit_lightDAR->text().toInt(nullptr,16);
        int g=ui->lineEdit_lightDAG->text().toInt(nullptr,16);
        int b=ui->lineEdit_lightDAB->text().toInt(nullptr,16);
        m_devCtl->setWhiteLamp(r,g,b);
    }
}

void MainWindow::on_comboBox_lightSelect_currentIndexChanged(int index)
{
    ui->comboBox_lampNumber->setEnabled(index==1||index==2);
    index==7?ui->label_da_RGB->setText("RGB:"):ui->label_da_RGB->setText("DA:");
    ui->lineEdit_lightDAG->setEnabled(index==7);
    ui->lineEdit_lightDAB->setEnabled(index==7);
}

void MainWindow::on_pushButton_testStart_clicked()
{
    switch (ui->comboBox_testFucntion->currentIndex())
    {
        case 0:
        {
            quint8 db=ui->spinBox_settingDb->text().toInt();
            quint16 durationTime=ui->lineEdit_durationTime->text().toInt();
            quint32 shutterPos=ui->lineEdit_shutterPos->text().toInt();
            int spotSlot=ui->spinBox_spotSlot->value();
            int colorSlot=ui->spinBox_colorSlot->value();
            float coordX=ui->lineEdit_coordX->text().toFloat();
            float coordY=ui->lineEdit_coordY->text().toFloat();
            int sps=ui->spinBox_speedLightDot->text().toInt();
            DotInfo dot;dot.coordX=coordX;dot.coordY=coordY;
            if(!getXYMotorPosAndFocalDistFromCoord(dot)) return;
            if(!ui->checkBox_autoCalcFocalDist->isChecked())
            {
                dot.focalDistance=ui->lineEdit_settingFocal->text().toInt();
            }
            else{
//                ui->lineEdit_settingFocal->setText(QString(dot.focalDistance));
            }
            staticCastTest(dot,spotSlot,colorSlot,db,sps,durationTime,shutterPos);
            break;
        }
        case 1:
        {
            DotInfo dotBegin,dotEnd;
            dotBegin.coordX=ui->lineEdit_beginCoordX->text().toInt();
            dotBegin.coordY=ui->lineEdit_beginCoordY->text().toInt();
            dotEnd.coordX=ui->lineEdit_endCoordX->text().toInt();
            dotEnd.coordY=ui->lineEdit_endCoordY->text().toInt();
            getXYMotorPosAndFocalDistFromCoord(dotBegin);
            getXYMotorPosAndFocalDistFromCoord(dotEnd);
            quint8 db=ui->spinBox_settingDb->text().toInt();
            int sps=ui->spinBox_speedLightMove->text().toInt();
            int stepCount=ui->lineEdit_stepCount->text().toInt();
            int spotSlot=ui->spinBox_spotSlot->value();
            int colorSlot=ui->spinBox_colorSlot->value();
            moveCastTest(dotBegin,dotEnd,spotSlot,colorSlot,stepCount,db,sps);
            break;
        }
    }
}

void MainWindow::on_comboBox_spotSize_currentIndexChanged(int)
{
   spdlog::info("comboBox called");
   QString text=ui->comboBox_spotSize->currentText();
   for(auto &v:m_settings.m_spotSizeToSlot)
   {
       qDebug()<<v.first;
       qDebug()<<v.second;
       if(v.first==text) ui->spinBox_spotSlot->setValue(v.second);
   }

}

void MainWindow::on_spinBox_spotSlot_valueChanged(int arg1)
{
    spdlog::info("spinBox called");
    for(auto &v:m_settings.m_spotSizeToSlot)
    {

        qDebug()<<v.first;
        qDebug()<<v.second;
        if(v.second==arg1)
        {
         ui->comboBox_spotSize->setCurrentText(v.first);return;
        }
    }
    ui->comboBox_spotSize->setCurrentText("--");
}

void MainWindow::on_comboBox_color_currentIndexChanged(int)
{
    spdlog::info("comboBox called");
    QString text=ui->comboBox_color->currentText();
    spdlog::info(text.toStdString());
    for(auto &v:m_settings.m_colorToSlot)
    {
        spdlog::info(v.first.toStdString());
        if(v.first==text)
        {
            spdlog::info(v.second);
            ui->spinBox_colorSlot->setValue(v.second);
        }
    }
}

void MainWindow::on_spinBox_colorSlot_valueChanged(int arg1)
{
    spdlog::info("spinBox called");
    for(auto &v:m_settings.m_colorToSlot)
    {
         if(v.second==arg1)
         {
             ui->comboBox_color->setCurrentText(v.first);return;
         }
    }
    ui->comboBox_color->setCurrentText("--");
}

void MainWindow::on_pushButton_shuterMotor_clicked()
{
    quint16 time = ui->lineEdit_shutterMotorTime->text().toInt();
    quint32 pos = ui->lineEdit_shutterMotorPos->text().toInt();
    m_devCtl->openShutter(time,pos);
}

void MainWindow::on_checkBox_autoCalcFocalDist_stateChanged(int arg1)
{
    ui->lineEdit_settingFocal->setEnabled(!(arg1==Qt::CheckState::Checked));
}

void MainWindow::on_checkBox_useConfigPos_stateChanged(int arg1)
{
    if(m_config.isEmpty()) return;
    ui->lineEdit_shutterPos->setEnabled(!(arg1==Qt::CheckState::Checked));
    if(arg1==Qt::CheckState::Checked)
        ui->lineEdit_shutterPos->setText(QString::number(m_config.shutterOpenPosRef()));
}

void MainWindow::on_comboBox_testFucntion_currentIndexChanged(int index)
{

    ui->groupBox_staticCastPos->setEnabled(index==0);
    ui->lineEdit_durationTime->setEnabled(index==0);
    ui->groupBox_moveCastPos->setEnabled(index==1);
    ui->checkBox_autoCalcFocalDist->setEnabled(index==0);
    if(index==1)
    {
        ui->checkBox_autoCalcFocalDist->setChecked(true);
    }
}


void MainWindow::on_action_chooseDevice_triggered()
{

    auto* dialog=new UsbViewerQt(this);
    dialog->setModal(true);
    if(dialog->exec()==QDialog::Accepted)
    {
        VID=dialog->VID;
        PID=dialog->PID;
    }
    if(m_devCtl!=NULL)
    {
        uninit();
    }
    init();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    QDesktopWidget *desktop = QApplication::desktop();

    if(index==2||index==3)
    {
        int width = GetSystemMetrics(SM_CXFULLSCREEN);
        int height = GetSystemMetrics(SM_CYFULLSCREEN);
        setMinimumSize(0, 0);
        setMaximumSize(width,height);
//       this->showMaximized();
    }
    else{
        showNormal();
        setFixedSize(m_width,m_height);
    }
}

void MainWindow::on_action_readLocalData_triggered()
{

    QString filePath=QFileDialog::getOpenFileName(this,"打开文件",QDir::currentPath()+R"(/data/)",tr("(*.dat)"));
    qDebug()<<filePath;
    readLocalData(filePath);
}

void MainWindow::readLocalData(QString filePath)
{
    QFile file(filePath);
    if(file.exists())
    {
        if(file.open(QIODevice::ReadOnly))
        {
            char* destPtr=(char*)m_settings.m_localTableData.m_data;
            int dateLen=m_settings.m_localTableData.dataLen;
            QByteArray data=file.readAll();
            if(data.length()!=(int)(dateLen*sizeof(int)))
            {
                qDebug()<<"length wrong:"<<data.length();
                return;
            }
            memcpy(destPtr,data.data(),data.length());
        }
        file.flush();
        file.close();
    }
}

void MainWindow::on_action_saveLocalData_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this,"打开文件",QDir::currentPath()+R"(/data/)",tr("(*.dat)"));
    qDebug()<<filePath;
    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly))
    {
//        int* dataPtr=new int[MotorPosTable::columnCount*MotorPosTable::rowCount*3*2];
//        int* mainTableData=ui->tableView_mainMotorPosTable->m_tableModel->m_modelData;
//        int* secondaryTableData=ui->tableView_secondaryPosTable->m_tableModel->m_modelData;
//        memcpy(dataPtr,mainTableData,MotorPosTable::columnCount*MotorPosTable::rowCount*3*sizeof(int));
//        memcpy(dataPtr+MotorPosTable::columnCount*MotorPosTable::rowCount*3,secondaryTableData,MotorPosTable::columnCount*MotorPosTable::rowCount*3*sizeof(int));
        char* destPtr=(char*)m_settings.m_localTableData.m_data;
        int dateLen=m_settings.m_localTableData.dataLen;
        file.write(destPtr,dateLen*sizeof(int));
        file.flush();
        file.close();
    }
}


void MainWindow::on_action_saveConfig_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this,"打开文件",QDir::currentPath()+R"(/data/)",tr("(*.dat)"));
    QFile file(filePath);
    qDebug()<<m_config.dataLen();
    if(file.open(QIODevice::WriteOnly))
    {
        refreshConfigDataByUI();
        file.write((char*)m_config.dataPtr(),m_config.dataLen());
    }
}


void MainWindow::on_action_readConfigFromLocal_triggered()
{
    QString filePath=QFileDialog::getOpenFileName(this,"打开文件",QDir::currentPath()+R"(/data/)",tr("(*.dat)"));
    qDebug()<<filePath;
    readLocalConfig(filePath);
}

void MainWindow::readLocalConfig(QString filePath)
{
    QFile file(filePath);
    if(file.exists())
    {
        if(file.open(QIODevice::ReadOnly))
        {
            QByteArray data=file.readAll();
            if(data.length()!=m_config.dataLen())
            {
                qDebug()<<"length wrong:"<<data.length();
                return;
            }
            memcpy(m_config.dataPtr(),data,m_config.dataLen());

        }
        file.flush();
        file.close();
    }
    refreshConfigUI();
}

void MainWindow::on_action_updateConfigToLower_triggered()
{

}

void MainWindow::on_action_downloadConfig_triggered()
{

}

//void MainWindow::on_action_SaveDBAngelDamping_triggered()
//{
//    QString filePath = QFileDialog::getSaveFileName(this,"打开文件",QDir::currentPath()+R"(/data/)",tr("(*.dat)"));
//    QFile file(filePath);
//    if(m_dbAngleDampingTableModel->m_modelData)
//    {
//        if(file.open(QIODevice::WriteOnly))
//        {
//            file.write((char*)m_dbAngleDampingTableModel->m_modelData,m_dbAngleDampingTableModel->m_column*m_dbAngleDampingTableModel->m_row*sizeof(int));
//        }
//    }
//}

//void MainWindow::on_action_loadDBAngleDamping_triggered()
//{
//    QString filePath=QFileDialog::getOpenFileName(this,"打开文件",QDir::currentPath()+R"(/data/)",tr("(*.dat)"));
//    qDebug()<<filePath;
//    QFile file(filePath);
//    if(file.exists())
//    {
//        if(file.open(QIODevice::ReadOnly))
//        {
//            QByteArray data=file.readAll();
//            int length=m_dbAngleDampingTableModel->m_column*m_dbAngleDampingTableModel->m_row*sizeof(int);
//            if(data.length()!=length)
//            {
//                qDebug()<<"length wrong:"<<data.length();
//                return;
//            }
//            memcpy(m_dbAngleDampingTableModel->m_modelData,data,length);
//        }
//        file.flush();
//        file.close();
//    }
//}



void MainWindow::on_pushButton_relativeMoveChin_clicked()
{ moveChinMotors(UsbDev::DevCtl::MoveMethod::Relative); }

void MainWindow::on_pushButton_absoluteMoveChin_clicked()
{ moveChinMotors(UsbDev::DevCtl::MoveMethod::Abosolute); }


void MainWindow::showDevInfo(QString str)
{ ui->textBrowser_infoText->append(str);}

void MainWindow::on_pushButton_relativeMove5Motors_clicked()
{move5Motors(UsbDev::DevCtl::MoveMethod::Relative);}

void MainWindow::on_pushButton_absoluteMove5Motors_clicked()
{move5Motors(UsbDev::DevCtl::MoveMethod::Abosolute);}

void MainWindow::on_pushButton_resetCheckedMotors_clicked()
{
    UsbDev::DevCtl::MotorId motorid;
    if(ui->radioButton_xMotor->isChecked()) motorid = UsbDev::DevCtl::MotorId::MotorId_X;
    if(ui->radioButton_yMotor->isChecked()) motorid = UsbDev::DevCtl::MotorId::MotorId_Y;
    if(ui->radioButton_colorMotor->isChecked()) motorid = UsbDev::DevCtl::MotorId::MotorId_Color;
    if(ui->radioButton_focusMotor->isChecked()) motorid = UsbDev::DevCtl::MotorId::MotorId_Focus;
    if(ui->radioButton_spotMotor->isChecked()) motorid = UsbDev::DevCtl::MotorId::MotorId_Light_Spot;
    if(ui->radioButton_shutterMotor->isChecked()) motorid = UsbDev::DevCtl::MotorId::MotorId_Shutter;
    if(ui->radioButton_chinHozMotor->isChecked()) motorid = UsbDev::DevCtl::MotorId::MotorId_Chin_Hoz;
    if(ui->radioButton_chinVertMotor->isChecked()) motorid = UsbDev::DevCtl::MotorId::MotorId_Chin_Vert;
    m_devCtl->resetMotor(motorid,ui->lineEdit_resetSpeed->text().toInt());
}

void MainWindow::moveChinMotors(UsbDev::DevCtl::MoveMethod method)
{
    qint32 value[2]={0};
    quint8 speed[2]={0};
    if(ui->checkBox_testChinHoz->isChecked())
    {
        value[0] = ui->lineEdit_posChinHoz->text().toInt();
        speed[0] = ui->lineEdit_speedChinHoz->text().toInt();
    }
    if(ui->checkBox_testChinVert->isChecked())
    {
        value[1] = ui->lineEdit_posChinVert->text().toInt();
        speed[1] = ui->lineEdit_speedChinVert->text().toInt();
    }
    m_devCtl->moveChinMotors(speed,value,method);
}

void MainWindow::move5Motors(UsbDev::DevCtl::MoveMethod method)
{
    qint32 value[5]={0};
    quint8 speed[5]={0};
    if(ui->checkBox_testX->isChecked())
    {
        value[0]=ui->lineEdit_posX->text().toInt();
        speed[0]=ui->lineEdit_speedX->text().toInt();
    }
    if(ui->checkBox_testY->isChecked())
    {
        value[1]=ui->lineEdit_posY->text().toInt();
        speed[1]=ui->lineEdit_speedY->text().toInt();
    }
    if(ui->checkBox_testFocus->isChecked())
    {
        value[2]=ui->lineEdit_posFocus->text().toInt();
        speed[2]=ui->lineEdit_speedFocus->text().toInt();
    }
    if(ui->checkBox_testColor->isChecked())
    {
        value[3]=ui->lineEdit_posColor->text().toInt();
        speed[3]=ui->lineEdit_speedColor->text().toInt();
    }
    if(ui->checkBox_testSpot->isChecked())
    {
        value[4]=ui->lineEdit_posSpot->text().toInt();
        speed[4]=ui->lineEdit_speedSpot->text().toInt();
    }
    m_devCtl->move5Motors(speed,value,method);
}

bool MainWindow::getXYMotorPosAndFocalDistFromCoord(DotInfo& dotInfo)
{
    static bool isMainDotInfoTable=true;
    int x1=floor(dotInfo.coordX/6.0f)*6;int x2=ceil(dotInfo.coordX/6.0f)*6;
    int y1=floor(dotInfo.coordY/6.0f)*6;int y2=ceil(dotInfo.coordY/6.0f)*6;
    DotInfo fourDots[4];
    int count = 0;
    for(auto& v:(isMainDotInfoTable?m_settings.m_dotInfoList:m_settings.m_secondaryDotInfoList))
    {
        if((v.coordX==x1)&&(v.coordY==y1)) {fourDots[0]=v;count++;}
        if((v.coordX==x2)&&(v.coordY==y1)) {fourDots[0]=v;count++;}
        if((v.coordX==x1)&&(v.coordY==y2)) {fourDots[0]=v;count++;}
        if((v.coordX==x2)&&(v.coordY==y2)) {fourDots[0]=v;count++;}
    }
    if(count != 4)          //找不到就切换到表
    {
        count=0;
        for(auto& v:(isMainDotInfoTable?m_settings.m_secondaryDotInfoList:m_settings.m_dotInfoList))
        {
            if((v.coordX==x1)&&(v.coordY==y1)) {fourDots[0]=v;count++;}
            if((v.coordX==x2)&&(v.coordY==y1)) {fourDots[0]=v;count++;}
            if((v.coordX==x1)&&(v.coordY==y2)) {fourDots[0]=v;count++;}
            if((v.coordX==x2)&&(v.coordY==y2)) {fourDots[0]=v;count++;}
        }
        if(count==4)
        {
             isMainDotInfoTable=!isMainDotInfoTable;    //记录当前表
        }
        else
        {
            showDevInfo("point is out of range!");
            return false;
        }
    }

    QPoint loc(dotInfo.coordX-fourDots[0].coordX,dotInfo.coordY-fourDots[0].coordY);
    int arr[4];
    for(unsigned int i=0;i<sizeof(arr)/sizeof(int);i++) {arr[i]=fourDots[i].motorXPos;}
    dotInfo.motorXPos=interpolation(arr,loc);
    for(unsigned int i=0;i<sizeof(arr)/sizeof(int);i++) {arr[i]=fourDots[i].motorYPos;}
    dotInfo.motorYPos=interpolation(arr,loc);
    for(unsigned int i=0;i<sizeof(arr)/sizeof(int);i++) {arr[i]=fourDots[i].focalDistance;}
    dotInfo.focalDistance=interpolation(arr,loc);
    return true;
}

void MainWindow::staticCastTest(DotInfo dot,int spotSlot ,int colorSlot,int db,int sps,int durationTime,int shutterPos)
{
    if(m_config.isEmpty()) {showDevInfo("empty config"); return;}
    while(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_X)||m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Y)||
          m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Focus)||m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Color)||
          m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Light_Spot)||m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Shutter))
    {QCoreApplication::processEvents();}

    //移动焦距电机到调节位置
    quint8 spsArr[5]={0};
    qint32 posArr[5]={0};
    if(!m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Focus))
    {
        spsArr[2]=sps;
        posArr[2]=m_config.focusPosForSpotAndColorChangeRef();
        m_devCtl->move5Motors(spsArr,posArr);
    }

    //调整颜色和光斑
    QTime time;
    time.start();
    memset(spsArr,0,sizeof(spsArr));
    memset(posArr,0,sizeof(posArr));
    spsArr[3]=sps;spsArr[4]=sps;
    posArr[3]=m_config.switchColorMotorPosPtr()[colorSlot];
    posArr[4]=m_config.switchColorMotorPosPtr()[spotSlot];

    while(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Focus)||(time.elapsed()<10))
    {QCoreApplication::processEvents();}

    m_devCtl->move5Motors(spsArr,posArr);

    //调整焦距
    time.restart();
    memset(spsArr,0,sizeof(spsArr));
    memset(posArr,0,sizeof(posArr));
    spsArr[2]=sps;
    posArr[2]=getFocusMotorPosByDist(dot.focalDistance,spotSlot);
    while(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Color)||m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Light_Spot)||(time.elapsed()<10))
    {QCoreApplication::processEvents();}
    m_devCtl->move5Motors(spsArr,posArr);

    //调整DB同时移动到指定位置
    time.restart();
    memset(spsArr,0,sizeof(spsArr));
    memset(posArr,0,sizeof(posArr));
    spsArr[0]=spsArr[1]=spsArr[3]=spsArr[4]=sps;
    posArr[0]=dot.motorXPos;
    posArr[1]=dot.motorYPos;
    posArr[3]=m_config.DbPosMappingPtr()[db][0];
    posArr[4]=m_config.DbPosMappingPtr()[db][1];
    while(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Focus)||(time.elapsed()<10))
    {QCoreApplication::processEvents();}
    m_devCtl->move5Motors(spsArr,posArr);

    //打开快门
    time.restart();
    ui->checkBox_useConfigPos->isChecked()?shutterPos=ui->lineEdit_shutterPos->text().toInt():shutterPos=m_config.shutterOpenPosRef();
    while(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_X)||m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Y)||
          m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Color)||m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Light_Spot)||(time.elapsed()<10))
    {QCoreApplication::processEvents();}
    m_devCtl->openShutter(durationTime,shutterPos);
}

void MainWindow::moveCastTest(DotInfo dotBegin,DotInfo dotEnd,int spotSlot ,int colorSlot,int stepAngle,int db,int sps)
{
    if(m_config.isEmpty()) {showDevInfo("empty config"); return;}
    while(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_X)||m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Y)||
          m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Focus)||m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Color)||
          m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Light_Spot)||m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Shutter))
    {QCoreApplication::processEvents();}

    //移动焦距电机到调节位置
    quint8 spsArr[5]={0};
    qint32 posArr[5]={0};
    if(!m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Focus))
    {
        spsArr[2]=sps;
        posArr[2]=m_config.focusPosForSpotAndColorChangeRef();
        m_devCtl->move5Motors(spsArr,posArr);
    }

    //调整颜色和光斑
    QTime time;
    time.start();
    memset(spsArr,0,sizeof(spsArr));
    memset(posArr,0,sizeof(posArr));
    spsArr[3]=sps;spsArr[4]=sps;
    posArr[3]=m_config.switchColorMotorPosPtr()[colorSlot];
    posArr[4]=m_config.switchColorMotorPosPtr()[spotSlot];

    while(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Focus)||(time.elapsed()<10))
    {QCoreApplication::processEvents();}
    m_devCtl->move5Motors(spsArr,posArr);

    //调整焦距
    time.restart();
    memset(spsArr,0,sizeof(spsArr));
    memset(posArr,0,sizeof(posArr));
    spsArr[2]=sps;
    posArr[2]=getFocusMotorPosByDist(dotBegin.focalDistance,spotSlot);
    while(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Color)||m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Light_Spot)||(time.elapsed()<10))
    {QCoreApplication::processEvents();}
    m_devCtl->move5Motors(spsArr,posArr);

    //调整DB同时移动到指定位置
    time.restart();
    memset(spsArr,0,sizeof(spsArr));
    memset(posArr,0,sizeof(posArr));
    spsArr[0]=spsArr[1]=spsArr[3]=spsArr[4]=sps;
    posArr[0]=dotBegin.motorXPos;
    posArr[1]=dotBegin.motorYPos;
    posArr[3]=m_config.DbPosMappingPtr()[db][0];
    posArr[4]=m_config.DbPosMappingPtr()[db][1];
    while(m_statusData.isMotorBusy(UsbDev::DevCtl::MotorId_Focus)||(time.elapsed()<10))
    {QCoreApplication::processEvents();}
    m_devCtl->move5Motors(spsArr,posArr);


    float stepAngleX,stepAngleY;
    int stepCount;
    int AngleX=dotBegin.coordX-dotEnd.coordX;
    int AngleY=dotBegin.coordY-dotEnd.coordY;
    if(std::abs(AngleX)>std::abs(AngleY))
    {
        stepAngleX=stepAngle;
        stepCount=AngleX/stepAngle;
        stepAngleY=AngleY/stepCount;
    }

    else
    {
        stepAngleY=stepAngle;
        stepCount=AngleY/stepAngle;
        stepAngleX=AngleX/stepCount;
    }

    DotInfo temp=dotBegin;
    QSharedPointer<int> dotArr=QSharedPointer<int>(new int[stepCount*3],[](
            int* x){delete []x;std::cout<<__LINE__<<" deleter worked"<<std::endl;});

//    for(int i=0;i<stepCount;i++)
//    {
//        temp.coordX+=stepAngleX;
//        temp.coordY+=stepAngleY;
//        getXYMotorPosAndFocalDistFromCoord(temp);
//        dotArr.data()[i][0]=temp.motorXPos;
//        dotArr.data()[i][1]=temp.motorYPos;
//        dotArr.data()[i][2]=getFocusMotorPosByDist(temp.focalDistance,spotSlot);
//    }

//    std::future<void> result = std::async(std::launch::async, [&]()
//    {
//        for(int i=0;i<stepCount;i++)
//        {
//            temp.coordX+=stepAngleX;
//            temp.coordY+=stepAngleY;
//            getXYMotorPosAndFocalDistFromCoord(temp);
//            dotArr.data()[i*3+0]=temp.motorXPos;
//            dotArr.data()[i*3+1]=temp.motorYPos;
//            dotArr.data()[i*3+2]=getFocusMotorPosByDist(temp.focalDistance,spotSlot);
//        }
//    });
//    while(!result._Is_ready()){QCoreApplication::processEvents();}

    QFuture<void> result=QtConcurrent::run([&](){
        for(int i=0;i<stepCount;i++)
        {
            temp.coordX+=stepAngleX;
            temp.coordY+=stepAngleY;
            getXYMotorPosAndFocalDistFromCoord(temp);
            dotArr.data()[i*3+0]=temp.motorXPos;
            dotArr.data()[i*3+1]=temp.motorYPos;
            dotArr.data()[i*3+2]=getFocusMotorPosByDist(temp.focalDistance,spotSlot);
        }
    });

    while(!result.isFinished()){QCoreApplication::processEvents();}

    constexpr int stepPerFrame=(512-8)/4;
    int totalframe=ceil(stepCount/stepPerFrame);
    for(int i=0;i<totalframe-1;i++)
    {
        m_devCtl->sendCastMoveData(totalframe,i,512,&dotArr.data()[(512-8)*i]);
    }
    int dataLen= (stepCount%stepPerFrame)*12+8;
    m_devCtl->sendCastMoveData(totalframe,totalframe-1,dataLen,&dotArr.data()[(512-8)*(totalframe-1)]);
    m_devCtl->startCastMove(sps,sps,sps,m_config.stepTimePtr()[sps]);
}





