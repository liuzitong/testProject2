#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <usbdev/main/usbdev_devctl.hxx>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    UsbDev::DevCtl::createInstance();
}

MainWindow::~MainWindow()
{
    delete ui;
}
