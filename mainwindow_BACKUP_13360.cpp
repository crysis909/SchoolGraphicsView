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
<<<<<<< HEAD
    layout->addWidget(myView,0,0,Qt::AlignTop);
    layout->addWidget(ui->graphicsView,0,1,Qt::AlignTop);
    layout->addWidget(ui->label_x,0,1,Qt::AlignLeft);
    layout->addWidget(ui->label_y,0,1,Qt::AlignJustify);

    //Set default Text
    ui->label_x->setText("X: 0");
    ui->label_y->setText("Y: 0");

    //Connects
    connect(myView,SIGNAL(getposition(int,int)),this,SLOT(exitposition(int,int)));

    myView->show();

    //Set Widget and Layout to Mainwindow
=======
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
>>>>>>> 0cc46292035c4fcd1d53dfe9addb15a1c59e5903
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete myView;
    delete layout;
    delete widget;
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
