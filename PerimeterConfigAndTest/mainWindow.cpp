#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UsbViewer/UsbViewerQt.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小
    VID="FFFF";PID="A60D";
    ui->statusBar->showMessage(QString("VID:%1   PID:%2").arg(VID).arg(PID));
    quint32 vid_pid=VID.toInt(nullptr,16)<<16|PID.toInt(nullptr,16);
    devCtl=UsbDev::DevCtl::createInstance(vid_pid);
    connect(devCtl,&UsbDev::DevCtl::updateInfo,this,&MainWindow::showDevInfo);
//    connect(devCtl,&UsbDev::DevCtl::newStatusData,this,&MainWindow::getData);
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
    ui->statusBar->showMessage(QString("VID:%1   PID:%2").arg(VID).arg(PID));
    delete devCtl;
    quint32 vid_pid=VID.toInt(nullptr,16)<<16|PID.toInt(nullptr,16);
    devCtl=UsbDev::DevCtl::createInstance(vid_pid);
//    connect(devCtl,&UsbDev::DevCtl::newStatusData,this,&MainWindow::getData2);
}

void MainWindow::getData()
{
    qDebug()<<"getData";
    data=devCtl->takeNextPendingStatusData();
}

void MainWindow::getData2()
{
    qDebug()<<"getData2";
    data=devCtl->takeNextPendingStatusData();
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
//   ui->groupBox_resetMotor->
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
    devCtl->moveChinMotors(speed,value,method);
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
    devCtl->move5Motors(speed,value,method);
}
