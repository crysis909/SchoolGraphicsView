#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QImage>
#include <QPushButton>
#include <QVector>
#include <QResizeEvent>
#include <QMessageBox>
#include <QBuffer>
#include <QFile>
#include <QFileDialog>

#include "q4xbkifgraphicsview.h"
#include "mandel_window.h"
#include "screenshoot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void resizeImage();

private:
    //Variable
    QVector <mandel_window*> mandelliste_Back;
    QVector <mandel_window*> mandelliste_Forward;

    double sub_left, sub_upper;     //holds corner of selected zoom window

    //Overlay
    Q4xBKIFGraphicsView *myView;
    QGraphicsPixmapItem *Pixm;      //Holds Pointer to Pixmap in scene
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    mandel_window *current_mandel;  //holds the current mandel window coords
    mandel_window *prev;
    QGridLayout *layout;
    QPushButton *next;
    QPushButton *back;
    QPushButton *save;
    QPushButton *screenshot;
    QMessageBox msgBox;
    Screenshoot *screen;
    QWidget *widget;
    QString xcord = "-2.0 / -1.0";
    QString ycord = "1.0 / 1.0";
    QImage *Ima;                    //holds the mandel graphics

    //Functions
    void draw_mandel();  //uses current_mandel to calculate the pixels of qimage Ima
                        //and gives it to Scene

private slots:
    //Mouse
    void exitposition_pressed(int x, int y);
    void exitposition_released(int x, int y);

    //Button
    void nextPressed();
    void backPressed();
    void savePressed();
    void screenPressed();

protected:
    virtual void resizeEvent(QResizeEvent *event);
};

#endif // MAINWINDOW_H
