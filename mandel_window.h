#ifndef MANDEL_WINDOW_H
#define MANDEL_WINDOW_H

#define MAX_ITER 256  //maximum iterations for calculation - influences color depth

#include <QWidget>

class mandel_window
{
public:
    mandel_window(double left, double upper, double right, double lower, QWidget * Window);
    double m_x(int V_x);  //calculates the mandelcoords for this certain pixel x value
    double m_y(int V_y);  //calculates the mandelcoords for this certain pixel y value
    int Mandel(int V_x, int V_y); //calculates the mandel value (number of iterations)

private:
    //the dimension of the mandelbrot area:
    double X1;
    double X2;
    double Y1;
    double Y2;
    QWidget * W; //holds the Widget, that shows the graphics
};

#endif // MANDEL_WINDOW_H
