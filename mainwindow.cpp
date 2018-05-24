#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Init
    scene = new QGraphicsScene();
    myView = new Q4xBKIFGraphicsView(scene, this);
    current_mandel = new mandel_window(-2.0,-1.0,1.0,1.0,myView);
    next = new QPushButton("-->", this);
    back = new QPushButton("<--", this);
    layout = new QGridLayout();
    widget = new QWidget(this);
    Ima = new QImage(842,454,QImage::Format_RGB888);
    Pixm = nullptr;
    prev = nullptr;

    //Layout
    layout->addWidget(myView, 1, 0, 1, 4);
    layout->addWidget(next, 0, 3, Qt::AlignRight);
    layout->addWidget(back, 0, 2, Qt::AlignAbsolute);
    layout->addWidget(ui->label_x, 0, 0, Qt::AlignLeft);
    layout->addWidget(ui->label_y, 2, 3, Qt::AlignRight);

    //Default values
    ui->label_x->setText("0 / 0");
    ui->label_y->setText("0 / 0");

    myView->show();

    //Connects
    connect(myView, SIGNAL(getposition_pressed(int, int)), this, SLOT(exitposition_pressed(int, int)));
    connect(myView, SIGNAL(getposition_released(int, int)), this, SLOT(exitposition_released(int, int)));
    connect(next, SIGNAL(pressed()), this, SLOT(nextPressed()));
    connect(back, SIGNAL(pressed()), this, SLOT(backPressed()));

    //Set Layout and Widget
    widget->setLayout(layout);
    setCentralWidget(widget);
    draw_mandel();
}

MainWindow::~MainWindow()
{
    for (auto &window : history)
        delete window;


    delete Ima;
    delete Pixm;
    delete current_mandel;
    delete myView;
    delete layout;
    delete widget;
    delete ui;
}

void MainWindow::draw_mandel()
{
    //calculates pixels:
    for (int row = 0; row < Ima->height(); row++)
        for (int column = 0; column < Ima->width(); column++)
            Ima->setPixelColor(column,row,
                               current_mandel->calculate_color(current_mandel->Mandel(column,row)));

    //gives temp to scene
    if(!Pixm)
    {
        scene->removeItem(Pixm);
        delete Pixm;
    }

    Pixm = scene->addPixmap(QPixmap::fromImage(*Ima));
}

void MainWindow::exitposition_pressed(int x, int y)
{
    ui->label_y->setText(QString::number(current_mandel->m_x(x)) + "/" +
                         QString::number(current_mandel->m_y(y)));

    //store new values of corner:
    sub_left  = current_mandel->m_x(x);
    sub_upper = current_mandel->m_y(y);
}

void MainWindow::exitposition_released(int x, int y)
{    
    ui->label_x->setText(QString::number(current_mandel->m_x(x)) + "/" +
                         QString::number(current_mandel->m_y(y)));

    //store new values of corner:
    double sub_right = current_mandel->m_x(x);
    double sub_lower = current_mandel->m_y(y);

    //update mandel_window:
    if(current_mandel)
    {
        history.append(current_mandel);
        index = history.length();
    }

    current_mandel = new mandel_window(sub_left, sub_upper, sub_right, sub_lower,myView);
    draw_mandel();

}

void MainWindow::nextPressed()
{
    if(index < history.length())
    {
        current_mandel = history[++index];
        draw_mandel();
    }
    qDebug() << index;
}

void MainWindow::backPressed()
{
    if(index > 0)
    {
        current_mandel = history[--index];
        draw_mandel();
    }
    qDebug() << index;
}

//void MainWindow::resizeEvent(QResizeEvent *event)
//{
//    QImage temp = Ima->scaled(scene->width(),scene->height());  //Image resize to Scene size
//    Ima = &temp;
//    QMainWindow::resizeEvent(event);
//}
