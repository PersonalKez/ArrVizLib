#include "arrayvizjob.h"
#include "arrvizlib.h"
#include <QApplication>
#include <binlog/binlog.hpp>
#include <fstream>

ArrayVizJob::ArrayVizJob() {}

int ArrayVizJob::visualiseArrayJob(int argc, char *argv[], std::vector<std::string> matVals, std::vector<int> matDims, std::vector<int> coords, std::vector<int> cursor)
{
    QApplication a(argc,argv);
    BINLOG_INFO("QApp started... vizualisation array");

    std::ofstream logfile("log.blog", std::ofstream::out|std::ofstream::binary);
    binlog::consume(logfile);
    ArrVizLib *w = new ArrVizLib();
    w->spawnArrayVisualisation(matVals, matDims, coords, cursor);
    return a.exec();
}

int ArrayVizJob::visualiseArrayWorker(int argc, char *argv[], std::vector<std::string> matVals, std::vector<int> matDims, std::vector<int> coords, std::vector<int> cursor){

    std::thread task(&ArrayVizJob::visualiseArrayJob, this, argc, argv, matVals, matDims, coords, cursor);
    task.join();
    return 1;
}

