#include "q4xbkifgraphicsview.h"
#include <QMouseEvent>
#include <QDebug>

Q4xBKIFGraphicsView::Q4xBKIFGraphicsView(QWidget *parent, QGraphicsScene *scene)
    :QGraphicsView(parent)
{
    setScene(scene);
    rect = nullptr;
}

void Q4xBKIFGraphicsView::mousePressEvent(QMouseEvent *event)
{
    //DEBUG:
    //qDebug() << "Pressed";
    beginPoint.setX(event->x());
    beginPoint.setX(event->y());
    emit getposition_pressed(event->x(),event->y());
}

void Q4xBKIFGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    //DEBUG:
    //qDebug() << "Released";
    lastPoint.setX(event->x());
    lastPoint.setX(event->y());

    if(!rect)
    {
        rect = scene()->addRect(QRect(beginPoint,beginPoint));
    }
    else
    {
        rect->setRect(beginPoint.x(),beginPoint.y(),0,0);
    }

    emit getposition_released(event->x(),event->y());

}

void Q4xBKIFGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    rect->setRect(beginPoint.x(), beginPoint.y(), event->x() - beginPoint.x(), event->y() - beginPoint.y());
}
