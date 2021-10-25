#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "UsbViewerQt.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    VID="FFFF";PID="A60D";
    ui->statusBar->showMessage(QString("VID:%1   PID:%2").arg(VID).arg(PID));
    quint32 vid_pid=VID.toInt(nullptr,16)<<16|PID.toInt(nullptr,16);
    qDebug("vid_pid is:%x",vid_pid);
    devCtl=UsbDev::DevCtl::createInstance(vid_pid);
    connect(devCtl,&UsbDev::DevCtl::newStatusData,this,&MainWindow::getData);
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
    connect(devCtl,&UsbDev::DevCtl::newStatusData,this,&MainWindow::getData2);
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
