#include "q4xbkifgraphicsview.h"

Q4xBKIFGraphicsView::Q4xBKIFGraphicsView(QWidget *parent, int x, int y, int w, int h)
  :QGraphicsView(parent)
{
  setFixedSize(w,h);
  move(x,y);
}

void Q4xBKIFGraphicsView::mousePressEvent(QMouseEvent *event)
{

}
