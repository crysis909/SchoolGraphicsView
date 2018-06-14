#ifndef SCREENSHOOT_H
#define SCREENSHOOT_H

#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QResizeEvent>

class Screenshoot : public QWidget
{
    Q_OBJECT
public:
    explicit Screenshoot(QImage *image, QString x = "0 / 0" , QString y = "0 / 0" , QWidget *parent = nullptr);

private:
    QImage *_image;
    QImage _temp;
    QGridLayout *layout;
    QLabel *x_cord;
    QLabel *y_cord;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *pix;

    void init();

protected:
    virtual void resizeEvent(QResizeEvent *event);

};

#endif // SCREENSHOOT_H
