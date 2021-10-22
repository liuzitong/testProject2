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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool ok1,ok2=false;
    quint32 vid_pid=VID.toInt(&ok1,16)<<16|PID.toInt(&ok2,16);
    qDebug("vid_pid is:%x",vid_pid);
    devCtl=UsbDev::DevCtl::createInstance(vid_pid);
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
}
