#include "screenshoot.h"
#include <QDebug>

Screenshoot::Screenshoot(QImage *image, QString x, QString y, QWidget *parent) : QWidget(parent), _image(image)
{
    init();
    x_cord->setText(x);
    y_cord->setText(y);
    pix = scene->addPixmap(QPixmap::fromImage(*_image));
}

void Screenshoot::init()
{
    layout = new QGridLayout(this);
    x_cord = new QLabel("-2.0 / -1.0", this);
    y_cord = new QLabel("1.0 / 1.0", this);
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene,this);

    layout->addWidget(view);
    layout->addWidget(x_cord);
    layout->addWidget(y_cord);

    layout->addWidget(view, 1, 0, 1, 4);
    layout->addWidget(x_cord, 0, 0, Qt::AlignLeft);
    layout->addWidget(y_cord, 2, 3, Qt::AlignRight);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    setLayout(layout);
}

void Screenshoot::resizeEvent(QResizeEvent *event)
{
    *_image = _image->scaled(view->size());
    pix = scene->addPixmap(QPixmap::fromImage(*_image));
    QWidget::resizeEvent(event);
}
