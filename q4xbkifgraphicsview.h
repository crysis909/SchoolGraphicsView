#ifndef Q4XBKIFGRAPHICSVIEW_H
#define Q4XBKIFGRAPHICSVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>

class Q4xBKIFGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    Q4xBKIFGraphicsView(QWidget *parent,int x,int y,int w,int h);

signals:
    void getposition(int x,int y);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // Q4XBKIFGRAPHICSVIEW_H
