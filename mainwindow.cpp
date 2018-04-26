#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Init
    myView = new Q4xBKIFGraphicsView(this,10,10,450,450);
    layout = new QGridLayout(this);
    widget = new QWidget(this);

    //Layout
    layout->addWidget(myView,1,1,2,2);
    layout->addWidget(ui->graphicsView,1,3,2,1);
    layout->addWidget(ui->label_x,3,4,2,1);
    layout->addWidget(ui->label_y,3,5,2,1);

    ui->label_x->setText("X: 0");
    ui->label_y->setText("Y: 0");

    myView->show();

    connect(myView,SIGNAL(getposition(int,int)),this,SLOT(exitposition(int,int)));

    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete layout;
    delete widget;
    delete myView;
    delete ui;
}

void MainWindow::exitposition(int x, int y)
{
    ui->label_x->setText("X: " + QString::number(x));
    ui->label_y->setText("Y: " + QString::number(y));
}
