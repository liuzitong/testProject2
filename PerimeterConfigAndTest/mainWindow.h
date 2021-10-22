#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <usbdev/main/usbdev_devctl.hxx>

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
    void on_pushButton_clicked();

    void on_actionchooseDevice_triggered();

private:
    Ui::MainWindow *ui;
    UsbDev::DevCtl *devCtl;

};

#endif // MAINWINDOW_H
