#include "q4xbkifgraphicsview.h"
#include <QMouseEvent>
#include <QDebug>

Q4xBKIFGraphicsView::Q4xBKIFGraphicsView(QWidget *parent, QGraphicsScene *scene)
    :QGraphicsView(parent)
{
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->scene()->setParent(this);
    rectItem = nullptr;
}

Q4xBKIFGraphicsView::Q4xBKIFGraphicsView(QWidget *parent, int x, int y, int w, int h, QGraphicsScene *scene)
    :QGraphicsView(parent)
{
    setFixedSize(w,h);
    move(x,y);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->scene()->setParent(this);
    rectItem = nullptr;
}

Q4xBKIFGraphicsView::~Q4xBKIFGraphicsView()
{
    delete rectItem;
    delete scene();
}

void Q4xBKIFGraphicsView::mousePressEvent(QMouseEvent *event)
{
    beginPoint.setX(event->x());
    beginPoint.setY(event->y());

    if(rectItem)
        delete rectItem;

    rectItem = scene()->addRect(QRect(beginPoint, beginPoint));

    emit getposition_pressed(event->x(), event->y());
}

void Q4xBKIFGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    lastPoint.setX(event->x());
    lastPoint.setY(event->y());

    rectItem->setRect(QRect(beginPoint, lastPoint));

    emit getposition_released(event->x(), event->y());
}

void Q4xBKIFGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    rectItem->setRect(beginPoint.x(), beginPoint.y(), event->x() - beginPoint.x(), event->y() - beginPoint.y());
}

void Q4xBKIFGraphicsView::resizeEvent(QResizeEvent *event)
{
    scene()->setSceneRect(rect());
    QGraphicsView::resizeEvent(event);
}
