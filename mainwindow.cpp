#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myView= new Q4xBKIFGraphicsView(this,10,10,450,450);
    myView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
