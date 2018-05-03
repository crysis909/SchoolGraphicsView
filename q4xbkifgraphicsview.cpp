#include "q4xbkifgraphicsview.h"
#include <QMouseEvent>
#include <QDebug>

Q4xBKIFGraphicsView::Q4xBKIFGraphicsView(QWidget *parent, QGraphicsScene *scene)
    :QGraphicsView(parent)
{
}

void Q4xBKIFGraphicsView::mousePressEvent(QMouseEvent *event)
{
    //DEBUG:
    //qDebug() << "Pressed";
    emit getposition_pressed(event->x(),event->y());
}

void Q4xBKIFGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    //DEBUG:
    //qDebug() << "Released";
    scene()->addRect(event->x(),event->y(), 10, 10);
    emit getposition_released(event->x(),event->y());

}

void Q4xBKIFGraphicsView::mouseMoveEvent(QMouseEvent *event)
{

}
