#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mandel_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Init
    scene = new QGraphicsScene();
    myView = new Q4xBKIFGraphicsView(this, scene);
    layout = new QGridLayout();
    widget = new QWidget(this);

    //Layout
    layout->addWidget(myView, 0, 0, 1, 1);
    layout->addWidget(ui->label_x, 1, 0, 1, 1, Qt::AlignLeft);
    layout->addWidget(ui->label_y, 1, 0, 1, 1, Qt::AlignRight);

    //Default values
    resize(800,600);
    ui->label_x->setText("X: 0");
    ui->label_y->setText("Y: 0");

    myView->show();

    //Connects
    connect(myView, SIGNAL(getposition_pressed(int, int)), this, SLOT(exitposition_pressed(int, int)));
    connect(myView, SIGNAL(getposition_released(int, int)), this, SLOT(exitposition_released(int, int)));

    //Set Layout and Widget
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
    mandel_window mw(-2,-1,1,1,myView);
    ui->label_x->setText(QString::number(mw.m_x(x))+" / "+QString::number(mw.m_y(y)));
}

void MainWindow::exitposition_released(int x, int y)
{
    mandel_window mw(-2,-1,1,1,myView);
    ui->label_y->setText(QString::number(mw.m_x(x))+" / "+QString::number(mw.m_y(y)));
}
