#include "mainWindow.h"
#include <QtWidgets/QApplication>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/basic_file_sink.h"
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/common.h>
#include <QDebug>
#include <local_data.h>
#include <QSharedPointer>
#include <QStyleFactory>
#include <QThread>



int main(int argc, char *argv[])
{
    qDebug()<<"thread running:"<<QThread::currentThreadId()<<endl;
    auto rotating_logger = spdlog::rotating_logger_mt("logger", "logs/perimeterConfig_logger.txt", 1024*1024, 30);
    auto logger = spdlog::get("logger");
//            for (int i = 0; i < 3; ++i)
//                logger->info("{} * {} equals {:>10}", i, i, i*i);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    spdlog::info("Welcome to spdlog!");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

}
