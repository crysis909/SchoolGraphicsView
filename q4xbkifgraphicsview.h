#ifndef Q4XBKIFGRAPHICSVIEW_H
#define Q4XBKIFGRAPHICSVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPoint>

class Q4xBKIFGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    Q4xBKIFGraphicsView(QWidget *parent, QGraphicsScene *scene = nullptr);

signals:
    void getposition_pressed(int x,int y);
    void getposition_released(int x,int y);

private:
    QPoint beginPoint;
    QPoint lastPoint;
    QGraphicsRectItem *rect;

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
};

#endif // Q4XBKIFGRAPHICSVIEW_H
