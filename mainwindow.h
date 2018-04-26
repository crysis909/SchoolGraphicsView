#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QMainWindow>
#include "q4xbkifgraphicsview.h"

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
    Ui::MainWindow *ui;
    Q4xBKIFGraphicsView *myView;
    QGridLayout *layout;
    QWidget *widget;

private slots:
    void exitposition(int x,int y);
};

#endif // MAINWINDOW_H
