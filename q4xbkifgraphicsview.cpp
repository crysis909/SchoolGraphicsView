#include "q4xbkifgraphicsview.h"
#include <QMessageBox>

Q4xBKIFGraphicsView::Q4xBKIFGraphicsView(QWidget *parent, int x, int y, int w, int h)
  :QGraphicsView(parent)
{
  setFixedSize(w,h);
  move(x,y);
}

void Q4xBKIFGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QMessageBox msgBox;
      msgBox.setText("The mouse Button has ben pressed");
      msgBox.exec();

}
