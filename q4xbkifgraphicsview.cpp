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

    emit getposition_pressed(event->x(), event->y());
}

void Q4xBKIFGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    emit getposition_released(event->x(), event->y());
}

void Q4xBKIFGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    int w = event->x() - beginPoint.x();
    int h = event->y() - beginPoint.y();

    if(w > h * 3/2)
        h = w * 2/3;
    else
        w = h * 3/2;

    if(!rectItem)
        rectItem=scene()->addRect(beginPoint.x(), beginPoint.y(), w, h);
    else
        rectItem->setRect(beginPoint.x(), beginPoint.y(), w, h);
}

void Q4xBKIFGraphicsView::resizeEvent(QResizeEvent *event)
{
    scene()->setSceneRect(rect());
    QGraphicsView::resizeEvent(event);
}
