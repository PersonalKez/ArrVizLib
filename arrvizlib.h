#ifndef ARRVIZLIB_H
#define ARRVIZLIB_H

#include "ArrVizLib_global.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTableWidget>

class ARRVIZLIB_EXPORT ArrVizLib
{

public:
    ArrVizLib();
    ~ArrVizLib();
    void visualiseArr(std::vector<std::string> values, std::vector<int> dimensions, std::vector<int> coords);
    void placeCursor(double x, double y);
    void spawnArrayVisualisation(std::vector<std::string> matVals, std::vector<int> matDims, std::vector<int> coords, std::vector<int> cursor);
private:
    std::vector<int> getStartingVal(std::vector<int> dimensions, std::vector<int> coords);
    QTableWidget *tableWidget;
    QGraphicsScene *scene;
    QGraphicsView *view;
};

#endif // ARRVIZLIB_H
