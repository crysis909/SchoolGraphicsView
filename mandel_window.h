#ifndef MANDEL_WINDOW_H
#define MANDEL_WINDOW_H

static constexpr int MAX_ITER = 127;  //maximum iterations for calculation - influences color depth

#include <QWidget>
#include <QPointF>
#include <QImage>


class mandel_window
{
public:
    mandel_window(double left, double upper, double right, double lower, QWidget *Window);
    ~mandel_window();
    double m_x(int V_x);  //calculates the mandelcoords for this certain pixel x value
    double m_y(int V_y);  //calculates the mandelcoords for this certain pixel y value
    int Mandel(int V_x, int V_y); //calculates the mandel value (number of iterations)
    int Mandel();

    QImage *drawImage();


private:
    //the dimension of the mandelbrot area:
    QPointF leftUpper;
    QPointF rightLower;
    QImage *image;
    QWidget *W; //holds the Widget, that shows the graphics

    double X_SCALE = 3.0/750;
    double Y_SCALE = 2.0/500;
    double X_Offset;
    double Y_Offset;
    double Cx,Cy;
    double Mx,My,M_z;
};

#endif // MANDEL_WINDOW_H
