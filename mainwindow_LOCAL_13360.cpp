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

void MainWindow::exitposition(int x, int y)
{
    ui->label_x->setText("X: " + QString::number(x));
    ui->label_y->setText("Y: " + QString::number(y));
}
