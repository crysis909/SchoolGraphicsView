#ifndef Q4XBKIFGRAPHICSVIEW_H
#define Q4XBKIFGRAPHICSVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>

class Q4xBKIFGraphicsView : public QGraphicsView
{
public:
    Q4xBKIFGraphicsView(QWidget *parent,int x,int y,int w,int h);
};

#endif // Q4XBKIFGRAPHICSVIEW_H
