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
    save = new QPushButton("Save", this);
    screenshot = new QPushButton("Screen", this);
    layout = new QGridLayout();
    widget = new QWidget(this);
    Ima = new QImage(800,600,QImage::Format_RGB888);
    Pixm = nullptr;
    prev = nullptr;

    //Layout
    layout->addWidget(myView, 1, 0, 1, 4);
    layout->addWidget(next, 0, 3, Qt::AlignRight);
    layout->addWidget(back, 0, 2, Qt::AlignAbsolute);
    layout->addWidget(save, 0, 4, Qt::AlignAbsolute);
    layout->addWidget(screenshot, 0, 5, Qt::AlignAbsolute);
    layout->addWidget(ui->label_x, 0, 0, Qt::AlignLeft);
    layout->addWidget(ui->label_y, 2, 3, Qt::AlignRight);

    //Default values
    ui->label_x->setText("-2.0 / -1.0");
    ui->label_y->setText("1.0 / 1.0");

    myView->show();

    //Connects
    connect(myView, SIGNAL(getposition_pressed(int, int)), this, SLOT(exitposition_pressed(int, int)));
    connect(myView, SIGNAL(getposition_released(int, int)), this, SLOT(exitposition_released(int, int)));
    connect(next, SIGNAL(pressed()), this, SLOT(nextPressed()));
    connect(back, SIGNAL(pressed()), this, SLOT(backPressed()));
    connect(save, SIGNAL(pressed()), this, SLOT(savePressed()));
    connect(screenshot, SIGNAL(pressed()), this, SLOT(screenPressed()));

    //Set Layout and Widget
    widget->setLayout(layout);
    setCentralWidget(widget);
    draw_mandel();
}

MainWindow::~MainWindow()
{
    delete screen;
    delete Ima;
    delete Pixm;
    delete current_mandel;
    delete myView;
    delete layout;
    delete widget;
    delete ui;

    for (auto &window : mandelliste_Back)
        delete window;
    mandelliste_Back.clear();

    for (auto &window : mandelliste_Forward)
        delete window;
    mandelliste_Forward.clear();
}

void MainWindow::draw_mandel()
{
    //calculates pixels:
    for (int row = 0; row < Ima->height(); row++)
        for (int column = 0; column < Ima->width(); column++)
            Ima->setPixelColor(column,row,
                               current_mandel->calculate_color(current_mandel->Mandel(column,row)));
    //Crash at col 266 and row 380 || col 568 and row 600

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
    ycord = QString::number(current_mandel->m_x(x)) + "/" +
            QString::number(current_mandel->m_y(y));

    ui->label_y->setText(ycord);

    //store new values of corner:
    sub_left  = current_mandel->m_x(x);
    sub_upper = current_mandel->m_y(y);
}

void MainWindow::exitposition_released(int x, int y)
{    
    xcord = QString::number(current_mandel->m_x(x)) + "/" +
            QString::number(current_mandel->m_y(y));

    ui->label_x->setText(xcord);

    //store new values of corner:
    double sub_right = current_mandel->m_x(x);
    double sub_lower = current_mandel->m_y(y);

    //update mandel_window:
    if(current_mandel)
        mandelliste_Back.append(current_mandel);

    current_mandel = new mandel_window(sub_left, sub_upper, sub_right, sub_lower,myView);
    draw_mandel();
}

void MainWindow::nextPressed()
{
    if(mandelliste_Forward.isEmpty()) return;

    if(current_mandel)
        mandelliste_Back.append(current_mandel);

    current_mandel = mandelliste_Forward.last(); // save the last mandelliste

    mandelliste_Forward.remove(mandelliste_Forward.length()-1); //deletes last mandelliste

    draw_mandel();
}

void MainWindow::backPressed()
{
    if(mandelliste_Back.isEmpty()) return ;

    if(current_mandel)
        mandelliste_Forward.append(current_mandel);

    current_mandel = mandelliste_Back.last(); //save the last mandel window

    mandelliste_Back.remove(mandelliste_Back.length()-1); // removes the last Pointer from the List

    draw_mandel();
}

void MainWindow::savePressed()
{   
    QByteArray ba;
    QBuffer buffer(&ba);
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Images (*.png *.jpg)"));

    buffer.open(QIODevice::WriteOnly);
    bool erro = Ima->save(&buffer, "PNG", 100);

    if(erro)
    {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly))
            return;

        QDataStream out(&file);
        out.writeRawData(buffer.data(), buffer.size());

        file.close();

        msgBox.setText("The picture was successful saved");
        msgBox.exec();
    }
    else
    {
        msgBox.setText("There is a problem, the picture wasn't saved");
        msgBox.exec();
    }

}

void MainWindow::screenPressed()
{
    screen = new Screenshoot(Ima, xcord, ycord);
    screen->show();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Ima = new QImage(Ima->bits(), scene->width(), scene->height(), QImage::Format_RGB888);
    QMainWindow::resizeEvent(event);
    draw_mandel();
}
