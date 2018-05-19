#include "mandel_window.h"
#include <QDebug>

mandel_window::mandel_window(double left, double upper, double right, double lower, QWidget *Window)
{
    image = new QImage(800,600,QImage::Format_RGB32);
//  image = new QImage(Window->width(),Window->height(),QImage::Format_RGB32);

    leftUpper.setX(left);
    leftUpper.setY(upper);

    rightLower.setX(right);
    rightLower.setY(lower);

    W=Window;
}

mandel_window::~mandel_window()
{
    delete image;
}

double mandel_window::m_x(int V_x)
{
    return (leftUpper.x() + V_x * ((rightLower.x() - leftUpper.x()) / W->width()));
}

double mandel_window::m_y(int V_y)
{
    return (leftUpper.y() + V_y * ((rightLower.y() - leftUpper.y()) / W->height()));
}

int mandel_window::Mandel(int V_x, int V_y)
{
    double Cx = m_x(V_x);
    double Cy = m_y(V_y);
    double Mx = 0;
    double My = 0;
    double M_z = 0;
    int iterations = 0;

    while(M_z < 4 && iterations < MAX_ITER)
    {
        double Mxi = Mx * Mx - My * My + Cx;
        My = 2 * Mx * My + Cy;
        Mx = Mxi;
        M_z = Mx * Mx + My * My;
        iterations++;
    }

    return iterations;
}

int mandel_window::Mandel()
{
    Mx=0;
    My=0;
    M_z=0;
    int iterations=0;
    while(M_z<4 && iterations<MAX_ITER)
    {
        double Mxi=Mx*Mx-My*My+Cx;
        My=2*Mx*My+Cy;
        Mx=Mxi;
        M_z=Mx*Mx+My*My;
        iterations++;
    }
    return iterations;
}

QImage *mandel_window::drawImage()
{
    for(int row=0;row<500;row++)
    {
        for(int col=0;col<750;col++)
        {
            //Mandelbrot Berechnung
            Cx=(col-500)*X_SCALE;
            Cy=(row-250)*Y_SCALE;
            int farbnr= Mandel();
            int red=0,green=0,blue=0;
            switch( farbnr%3)
            {
            case 0: red=farbnr;break;
            case 1: green=farbnr;break;
            case 2: blue=farbnr;break;
            };

            image->setPixelColor(col,row,QColor(red,green,blue));
        }
    }
    return image;
}
