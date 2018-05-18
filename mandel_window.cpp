#include "mandel_window.h"

mandel_window::mandel_window(double left, double upper, double right, double lower, QWidget *Window)
{
    leftUpper.setX(left);
    leftUpper.setY(upper);

    rightLower.y().setX(right);
    rightLower.y().setY(lower);

    W=Window;
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
