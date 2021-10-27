#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <usbdev/main/usbdev_devctl.hxx>
#include <usbdev/main/usbdev_statusdata.hxx>
#include <QStandardItemModel>

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

    void on_actionchooseDevice_triggered();

    void getData();

    void getData2();
private:
    Ui::MainWindow *ui;
    UsbDev::DevCtl *devCtl;
    UsbDev::StatusData data;
};

#endif // MAINWINDOW_H
