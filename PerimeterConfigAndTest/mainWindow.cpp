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
#pragma execution_character_set("utf-8")
// 不能删
static std::shared_ptr<spdlog::logger> logger=NULL;
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
    if(logger!=NULL) logger = spdlog::rotating_logger_mt("logger", "logs/perimeterConfig.txt", 1024*1024, 30);
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);                    // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                                     // 禁止拖动窗口大小
    QSettings *configIni = new QSettings("para.ini", QSettings::IniFormat);
    VID=configIni->value("ID/VID").toString();
    PID=configIni->value("ID/PID").toString();
    m_timer=new QTimer();
    connect(m_timer,&QTimer::timeout,[&](){ui->label_connectionStatus->setText("连接断开");});
    init();
}

void MainWindow::init()
{
    quint32 vid_pid=VID.toInt(nullptr,16)<<16|PID.toInt(nullptr,16);
    m_devCtl=UsbDev::DevCtl::createInstance(vid_pid);
    ui->label_VID->setText(VID);
    ui->label_PID->setText(PID);
    connect(m_devCtl,&UsbDev::DevCtl::workStatusChanged,this,&MainWindow::refreshConnectionStatus);
    connect(m_devCtl,&UsbDev::DevCtl::updateInfo,this,&MainWindow::showDevInfo);
    connect(m_devCtl,&UsbDev::DevCtl::newStatusData,this,&MainWindow::refreshStatus);
    connect(m_devCtl,&UsbDev::DevCtl::newFrameData,this,&MainWindow::refreshVideo);
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


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionchooseDevice_triggered()
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
    m_timer->start();
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
        m_devCtl->setLamp(lampId,ui->comboBox_lampNumber->currentIndex(),ui->lineEdit_lightDAOrRGB->text().toInt());
    }
    else
    {
        int rgb=ui->lineEdit_lightDAOrRGB->text().toInt(nullptr,16);
        m_devCtl->setWhiteLamp(rgb>>16,rgb>>8,rgb);
    }
}

void MainWindow::on_comboBox_lightSelect_currentIndexChanged(int index)
{
    ui->comboBox_lampNumber->setEnabled(index==1||index==2);
    index!=7?ui->label_da_RGB->setText("DA:"):ui->label_da_RGB->setText("RGB:");
}

void MainWindow::on_pushButton_testStart_clicked()
{
    quint8 db=ui->spinBox_settingDb->text().toInt();



    quint16 durationTime=ui->lineEdit_durationTime->text().toInt();
    qint32 pos=ui->lineEdit_shutterPos->text().toInt();
    m_devCtl->openShutter(durationTime,pos);

    switch (ui->comboBox_testFucntion->currentIndex())
    {
    case 0:
    {
        break;
    }
    case 1:
    {

        break;
    }
    }

}

void MainWindow::on_comboBox_spotSize_currentIndexChanged(int)
{
   spdlog::info("comboBox called");
   QString text=ui->comboBox_spotSize->currentText();
   for(auto &v:m_localConfig.spotSizeToSlot)
   {
       if(v.first==text) ui->spinBox_lightSpotHoleLoc->setValue(v.second);
   }

}

void MainWindow::on_spinBox_lightSpotHoleLoc_valueChanged(int arg1)
{
    spdlog::info("spinBox called");
    for(auto &v:m_localConfig.spotSizeToSlot)
    {
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
    for(auto &v:m_localConfig.colorToSlot)
    {
        spdlog::info(v.first.toStdString());
        if(v.first==text)
        {
            spdlog::info(v.second);
            ui->spinBox_lightColorHoleLoc->setValue(v.second);
        }
    }
}

void MainWindow::on_spinBox_lightColorHoleLoc_valueChanged(int arg1)
{
    spdlog::info("spinBox called");
    for(auto &v:m_localConfig.colorToSlot)
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


void MainWindow::on_pushButton_relativeMoveChin_clicked()
{
    moveChinMotors(UsbDev::DevCtl::MoveMethod::Relative);
}

void MainWindow::on_pushButton_absoluteMoveChin_clicked()
{
    moveChinMotors(UsbDev::DevCtl::MoveMethod::Abosolute);
}


void MainWindow::showDevInfo(QString str)
{
    ui->textBrowser_infoText->append(str);
}

void MainWindow::on_pushButton_relativeMove5Motors_clicked()
{
    move5Motors(UsbDev::DevCtl::MoveMethod::Relative);
}

void MainWindow::on_pushButton_absoluteMove5Motors_clicked()
{
    move5Motors(UsbDev::DevCtl::MoveMethod::Abosolute);
}

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

