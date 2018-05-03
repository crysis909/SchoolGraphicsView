#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Init
    scene = new QGraphicsScene(this);
    myView = new Q4xBKIFGraphicsView(this);
    myView->setScene(scene);
    layout = new QGridLayout(this);
    widget = new QWidget(this);

    //Layout
    layout->addWidget(myView,0,0,1,1);
    layout->addWidget(ui->graphicsView,0,1);
    layout->addWidget(ui->label_x,1,1,1,1,Qt::AlignLeft);
    layout->addWidget(ui->label_y,1,1,1,1,Qt::AlignRight);

    //Default values
    ui->label_x->setText("X: 0");
    ui->label_y->setText("Y: 0");

    myView->show();

    //Connects
    connect(myView,SIGNAL(getposition_pressed(int,int)),this,SLOT(exitposition_pressed(int,int)));
    connect(myView,SIGNAL(getposition_released(int,int)),this,SLOT(exitposition_released(int,int)));

    //Set Layout and Widget
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

void MainWindow::exitposition_pressed(int x, int y)
{
    ui->label_x->setText("X: " + QString::number(x));
    ui->label_y->setText("Y: " + QString::number(y));
}

void MainWindow::exitposition_released(int x, int y)
{
    ui->label_x->setText("X: " + QString::number(x));
    ui->label_y->setText("Y: " + QString::number(y));
}
