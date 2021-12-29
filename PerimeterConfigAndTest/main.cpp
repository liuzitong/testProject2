#include "mainWindow.h"
#include <QtWidgets/QApplication>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/basic_file_sink.h"
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/common.h>
#include <QDebug>
#include <settings.h>
#include <QSharedPointer>
#include <QStyleFactory>
#include <QThread>




int main(int argc, char *argv[])
{
    QApplication::setStyle(QStyleFactory::create("Fusion"));
//    spdlog::info("Welcome to spdlog!");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
