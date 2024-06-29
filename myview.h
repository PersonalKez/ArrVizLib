#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWheelEvent>


class Q_DECL_EXPORT MyView: public QGraphicsView
{
public:
    MyView(QGraphicsScene *scene, QWidget *parent = nullptr);
protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif // MYVIEW_H
