#include "arrvizlib.h"

#include "myview.h"
#include <binlog/binlog.hpp>
#include <QGraphicsView>
#include <QHeaderView>
#include <QScrollBar>

ArrVizLib::ArrVizLib()
{
    this->tableWidget = new QTableWidget();
    this->scene = new QGraphicsScene();
    this->view = new MyView(scene);
    this->scene->addWidget(this->tableWidget);
}

ArrVizLib::~ArrVizLib()
{
}

// convert your N-dimensional array to 1D first, cast as string, and provide dimensions as second arg
void ArrVizLib::visualiseArr(std::vector<std::string> values, std::vector<int> dimensions, std::vector<int> coords)
{
    BINLOG_INFO("CONSTRUCTING ARRAY, values: {}, dimensions: {}, at coordinate slice {}", values, dimensions, coords);

    int index = coords.size() > 2? getStartingVal(dimensions, coords)[2] : 0;

    this->tableWidget->setRowCount(dimensions[0]);
    this->tableWidget->setColumnCount(dimensions[1]);

    double totalY = 0;
    for(int j=0;j<dimensions[1];j++){
        double totalX = 0;
        for(int i=0;i<dimensions[0];i++){
            QTableWidgetItem *text = new QTableWidgetItem(QString::fromStdString(values[index]));
            text->setFont(QFont("Courier",10));
            this->tableWidget->setItem(totalX, totalY, text);
            totalX ++;
            index ++;
        }
        totalY += 1;
    }

    // no headers visible
    this->tableWidget->horizontalHeader()->hide();
    this->tableWidget->verticalHeader()->hide();
    this->tableWidget->setFrameShape(QFrame::NoFrame);
    this->tableWidget->horizontalScrollBar()->setStyleSheet("QScrollBar {height:0px;}");
    this->tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar {width:0px;}");
    this->view->resize(QSize(200,200));
    this->view->show();
}

void ArrVizLib::placeCursor(double y, double x){
    BINLOG_INFO("Placing cursors at {},{}", y,x);
    MyView *cursorView = new MyView(this->scene);
    const QPalette palette;
    cursorView->scale(2,2);
    cursorView->resize(QSize(200,200));
    this->tableWidget->item(x,y)->setBackground(palette.midlight());
    cursorView->centerOn((this->tableWidget->visualItemRect(this->tableWidget->item(x-1,y-1)).center()));
    cursorView->show();
}


// supply full set of multi-dimensional coords here with 0-indexing, but dimensions as absolute quantities, i.e. 2x2 -> {2,2}
// only enter if co-ords are 3 or higher dimensional
std::vector<int> ArrVizLib::getStartingVal(std::vector<int> dimensions, std::vector<int> coords){
    // get X and Y first so we can focus the cursor on them
    std::vector<int> xy = std::vector<int>(coords.begin(), coords.begin()+2);
    // now recursive multiplications to get the 'starting' val to render the 2d matrix slice
    // the equation is fairly easy...
    // for dimensions [Xn,Yn,Zn,Tn,In...], starting val = XYZTIn+XYZTn+XYZn
    int startVal = 0;
    for(int i = 0; i < coords.size()-2; i++){
        int interim = 1;
        for(int j = 0; j < i+2 ; j++){
            interim = interim*dimensions[j];
        }
        interim = interim*coords[i+2];
        startVal += interim;
    }
    xy.push_back(startVal);
    return xy;
}

void ArrVizLib::spawnArrayVisualisation(std::vector<std::string> matVals, std::vector<int> matDims, std::vector<int> coords, std::vector<int> cursor){
    this->visualiseArr(matVals,matDims, coords);
    this->placeCursor(cursor[0], cursor[1]);
}
