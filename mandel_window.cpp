#include "mandel_window.h"
#include <QDebug>

mandel_window::mandel_window(double left, double upper, double right, double lower, QWidget *Window)
{
    leftUpper.setX(left);
    leftUpper.setY(upper);

    rightLower.setX(right);
    rightLower.setY(lower);

    W = Window;
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

QColor mandel_window::calculate_color(int f)
// distributes the bits of f to three colors :
// xxxxxxxx xxxxxxxx rgbrgbrg brgbrgbr
{
    int AMPLIFY = 7;
    int count = MAX_ITER;

    //calculates the amount of bits to shift left to amplify brightness of color:
    while(count)
    {
        count >>= 3;
        AMPLIFY--;
    }
    //colors to zero:
    int red = 0;
    int green = 0;
    int blue = 0;

    //calculate colors like scheme in description:
    for(int i = 0; i < 6; i++) { red   += (f& (0x00000001 << (i * 3))) >> (i * 2); }
    for(int i = 0; i < 5; i++) { green += (f&  0x0000002  << (i * 3))  >> (i * 2); }
    for(int i = 0; i < 5; i++) { blue  += (f&  0x00000004 << (i * 3))  >> (i * 2 + 1); }

    //maximize brightness:
    red   <<= AMPLIFY;
    green <<= AMPLIFY;
    blue  <<= AMPLIFY;

    return(QColor(red, green, blue));
}

QDebug operator<<(QDebug d, const mandel_window *window)
{
    d << "LeftUpper: " << window->leftUpper << " RightLower: " << window->rightLower;
    return d;
}
