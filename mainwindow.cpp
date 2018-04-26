#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_x->setText("X: 0");
    ui->label_y->setText("Y: 0");

    myView= new Q4xBKIFGraphicsView(this,10,10,450,450);
    myView->show();

    connect(myView,SIGNAL(getposition(int,int)),this,SLOT(exitposition(int,int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exitposition(int x, int y)
{
    ui->label_x->setText("X: " + QString::number(x));
    ui->label_y->setText("Y: " + QString::number(y));
}
