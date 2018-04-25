#include "q4xbkifgraphicsview.h"
#include <QMouseEvent>
#include <QMessageBox>

Q4xBKIFGraphicsView::Q4xBKIFGraphicsView(QWidget *parent, int x, int y, int w, int h)
  :QGraphicsView(parent)
{
  setFixedSize(w,h);
  move(x,y);
}

void Q4xBKIFGraphicsView::mousePressEvent(QMouseEvent *event)
{
/*//DEBUG:
 *     QMessageBox msgBox;
      msgBox.setText("The mouse Button has ben pressed");
      msgBox.exec();
*/
    emit getposition(event->x(),event->y());
}
