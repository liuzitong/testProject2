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

    void on_pushButton_relativeMoveChin_clicked();

    void on_pushButton_absoluteMoveChin_clicked();

    void on_pushButton_relativeMove5Motors_clicked();

    void on_pushButton_absoluteMove5Motors_clicked();

    void on_pushButton_resetCheckedMotors_clicked();

    void showDevInfo(QString);
    void getData();
    void getData2();
private:
    void moveChinMotors(UsbDev::DevCtl::MoveMethod);
    void move5Motors(UsbDev::DevCtl::MoveMethod);
    Ui::MainWindow *ui;
    UsbDev::DevCtl *devCtl=NULL;
    UsbDev::StatusData data;
};

#endif // MAINWINDOW_H
