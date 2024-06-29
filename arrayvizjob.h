#ifndef ARRAYVIZJOB_H
#define ARRAYVIZJOB_H

#include <string>
#include <vector>
#include <QtCore/qglobal.h>

class Q_DECL_EXPORT ArrayVizJob
{
public:
    ArrayVizJob();
    int visualiseArrayWorker(int argc, char *argv[], std::vector<std::string> matVals, std::vector<int> matDims, std::vector<int> coords, std::vector<int> cursor);
private:
    int visualiseArrayJob(int argc, char *argv[], std::vector<std::string> matVals, std::vector<int> matDims, std::vector<int> coords, std::vector<int> cursor);

};

#endif // ARRAYVIZJOB_H
