#ifndef Q4XBKIFGRAPHICSVIEW_H
#define Q4XBKIFGRAPHICSVIEW_H

#include <QPoint>
#include <QObject>
#include <QWidget>
#include <QResizeEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

class Q4xBKIFGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    Q4xBKIFGraphicsView(QGraphicsScene *scene, QWidget *parent = nullptr);
    Q4xBKIFGraphicsView(int x, int y, int w, int h, QGraphicsScene *scene, QWidget *parent = nullptr);
    ~Q4xBKIFGraphicsView();

signals:
    void getposition_pressed(int x, int y);
    void getposition_released(int x, int y);

private:
    QPoint beginPoint;
    QPoint lastPoint;
    QGraphicsRectItem *rectItem;

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
};

#endif // Q4XBKIFGRAPHICSVIEW_H
