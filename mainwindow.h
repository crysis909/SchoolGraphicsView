#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QMainWindow>
#include <QGraphicsScene>
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
     QGraphicsScene *scene;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Q4xBKIFGraphicsView *myView;
    QGridLayout *layout;
    QWidget *widget;
    mandel_window *mandelWindow;

private slots:
    void exitposition_pressed(int x, int y);
    void exitposition_released(int x, int y);
};

#endif // MAINWINDOW_H
