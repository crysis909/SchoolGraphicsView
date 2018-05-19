#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Init
    scene = new QGraphicsScene();
    myView = new Q4xBKIFGraphicsView(this, scene);
    mandelWindow = new mandel_window(-2,-1,1,1,myView);
    layout = new QGridLayout();
    widget = new QWidget(this);

    //Layout
    layout->addWidget(myView, 1, 0, 1, 1);
    layout->addWidget(ui->label_x, 0, 0, 1, 1, Qt::AlignLeft);
    layout->addWidget(ui->label_y, 2, 0, 1, 1, Qt::AlignRight);

    //Default values
    resize(800,600);
    ui->label_x->setText("0 / 0");
    ui->label_y->setText("0 / 0");

    myView->show();

    //Connects
    connect(myView, SIGNAL(getposition_pressed(int, int)), this, SLOT(exitposition_pressed(int, int)));
    connect(myView, SIGNAL(getposition_released(int, int)), this, SLOT(exitposition_released(int, int)));

    //Set Layout and Widget
    widget->setLayout(layout);
    setCentralWidget(widget);

    myView->scene()->addPixmap(QPixmap::fromImage(*mandelWindow->drawImage()));
}

MainWindow::~MainWindow()
{
    delete mandelWindow;
    delete myView;
    delete layout;
    delete widget;
    delete ui;
}

void MainWindow::exitposition_pressed(int x, int y)
{
    ui->label_x->setText(QString::number(mandelWindow->m_x(x)) + " / " + QString::number(mandelWindow->m_y(y)));
}

void MainWindow::exitposition_released(int x, int y)
{
    ui->label_y->setText(QString::number(mandelWindow->m_x(x)) + " / " + QString::number(mandelWindow->m_y(y)));
}
