#include "mainWindow.h"
#include <QtWidgets/QApplication>
#include <spdlog/spdlog.h>
#include "spdlog/sinks/basic_file_sink.h"
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/common.h>
#include <QDebug>
int main(int argc, char *argv[])
{
//    std::shared_ptr<spdlog::logger> logger;
//    try {
//       logger = spdlog::basic_logger_mt("file_logger", "logs/perimeterConfig11.txt");
//    }
//    catch (spdlog::spdlog_ex ex)
//    {
//        qDebug()<<ex.what();
//    }

//    logger.get()->trace("1234");
//    logger.get()->flush();


    auto rotating_logger = spdlog::rotating_logger_mt("logger", "logs/perimeterConfig_logger.txt", 1024*1024, 30);
    auto logger = spdlog::get("logger");
            for (int i = 0; i < 1000000; ++i)
                logger->info("{} * {} equals {:>10}", i, i, i*i);
    SPDLOG_TRACE(logger, "Enabled only #ifdef SPDLOG_TRACE_ON..{} ,{}", 1, 3.23);
    spdlog::trace("Welcome to spdlog!");
	QApplication a(argc, argv);
    MainWindow w;
	w.show();
	return a.exec();

}
