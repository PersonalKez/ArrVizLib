#include "myview.h"

#include <QGraphicsView>

MyView::MyView(QGraphicsScene *scene, QWidget *parent)
    :QGraphicsView(scene, parent){

}

void MyView::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;
    if(event->angleDelta().y() > 0){
        scale(scaleFactor, scaleFactor);
    } else {
        scale(1/scaleFactor, 1/scaleFactor);
    }
}
