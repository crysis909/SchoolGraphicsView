#ifndef MANDEL_WINDOW_H
#define MANDEL_WINDOW_H

static constexpr int MAX_ITER = 256;  //maximum iterations for calculation - influences color depth

#include <QWidget>
#include <QPointF>
#include <QColor>
#include <QDebug>

class mandel_window
        //holds the coords of the selected mandel area
        //and calculates the values and colors
{
public:
    mandel_window(double left, double upper, double right, double lower, QWidget * Window);
    double m_x(int V_x);  //calculates the mandelcoords for this certain pixel x value
    double m_y(int V_y);  //calculates the mandelcoords for this certain pixel y value
    int Mandel(int V_x, int V_y); //calculates the mandel value (number of iterations)
    QColor calculate_color(int f); //tries to distribute the mandel value to rgb evenly

    friend QDebug operator<< (QDebug d, const mandel_window *window); //For debugging

private:
    //the dimension of the mandelbrot area:
    QPointF leftUpper;
    QPointF rightLower;
    QWidget *W; //holds the Widget, that shows the graphics
};





#endif // MANDEL_WINDOW_H
