#include "mainWindow.h"
#include <QtWidgets/QApplication>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/basic_file_sink.h"
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/common.h>
#include <QDebug>
#include <local_config.h>
int main(int argc, char *argv[])
{
//    auto rotating_logger = spdlog::rotating_logger_mt("logger", "logs/perimeterConfig_logger.txt", 1024*1024, 30);
//    auto logger = spdlog::get("logger");
////            for (int i = 0; i < 3; ++i)
////                logger->info("{} * {} equals {:>10}", i, i, i*i);
//    spdlog::trace("Welcome to spdlog!");
//	QApplication a(argc, argv);
//    MainWindow w;
//	w.show();
//	return a.exec();
    LocalConfig config;
    config.ShowAndWrite();

}
