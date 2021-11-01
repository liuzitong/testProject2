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
    qDebug("vid_pid is:%x",vid_pid);
    devCtl=UsbDev::DevCtl::createInstance(vid_pid);
//    connect(devCtl,&UsbDev::DevCtl::newStatusData,this,&MainWindow::getData);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionchooseDevice_triggered()
{
    qDebug()<<"helloworld";
    auto* dialog=new UsbViewerQt(this);
    dialog->setModal(true);
    if(dialog->exec()==QDialog::Accepted)
    {
        qDebug()<<"accepted";
        VID=dialog->VID;
        PID=dialog->PID;
        qDebug()<<VID<<" "<<PID;
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
    qint32 value[2];
    quint8 speed[2];
    value[0] = ui->lineEdit_posChinHoz->text().toInt();
    value[1] = ui->lineEdit_posChinVert->text().toInt();
    speed[0] = ui->lineEdit_speedChinHoz->text().toInt();
    speed[1] = ui->lineEdit_speedChinVert->text().toInt();

    devCtl->moveChinMotors(speed,value,UsbDev::DevCtl::MoveMethod::Relative);
//   /* bool ret=*/devCtl->moveChinMotors(speed,value,UsbDev::DevCtl::MoveMethod::Relative);
//    if(ret) ui->textBrowser_infoText->append("move command excuted successfully!");
}
