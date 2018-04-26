#include "q4xbkifgraphicsview.h"
#include <QMouseEvent>
#include <QDebug>

Q4xBKIFGraphicsView::Q4xBKIFGraphicsView(QWidget *parent, int x, int y, int w, int h)
    :QGraphicsView(parent)
{
    setFixedSize(w,h);
    move(x,y);
}

void Q4xBKIFGraphicsView::mousePressEvent(QMouseEvent *event)
{
    //DEBUG:
    //qDebug() << "Pressed";
    emit getposition(event->x(),event->y());
}

void Q4xBKIFGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    //DEBUG:
    //qDebug() << "Released";
    emit getposition(event->x(),event->y());
}
