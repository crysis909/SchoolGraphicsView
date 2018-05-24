#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QImage>
#include <QPushButton>
//#include <QStack>
#include <QResizeEvent>
#include "q4xbkifgraphicsview.h"
#include "mandel_window.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //Variable
//    QStack<mandel_window*> history;
    double sub_left, sub_upper;     //holds corner of selected zoom window

    //Overlay
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Q4xBKIFGraphicsView *myView;
    QGridLayout *layout;
    QWidget *widget;
    mandel_window *current_mandel;  //holds the current mandel window coords
    mandel_window *prev;
    QImage *Ima;                    //holds the mandel graphics
    QGraphicsPixmapItem *Pixm;      //Holds Pointer to Pixmap in scene
    QPushButton *next;
    QPushButton *back;

    //Functions
    void draw_mandel();  //uses current_mandel to calculate the pixels of qimage Ima
                        //and gives it to Scene

private slots:
    //Mouse
    void exitposition_pressed(int x, int y);
    void exitposition_released(int x, int y);

    //Button
//    void nextPressed();
//    void backPressed();

protected:
//    virtual void resizeEvent(QResizeEvent *event);
};

#endif // MAINWINDOW_H
