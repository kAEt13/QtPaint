#include "my_pen.h"

my_pen::my_pen()
{
    width = 1;

    style = 1;
}

my_pen::my_pen(int in_width, int in_style, my_color in_color) {
    width = in_width;
    style = in_style;
    color = in_color;
}

bool my_pen::setWidth(int n_width)
{
    //
    width = n_width;

    return true;
}

int my_pen::getWidth(void)
{
    return width;
}

bool my_pen::setStyle(int n_style)
{
    //
    style = n_style;

    return true;
}

int my_pen::getStyle(void)
{
    return style;
}

bool my_pen::setRGBA(int r, int g, int b, int a)
{
    color.red = r;
    color.green = g;
    color.blue = b;
    color.alpha = a;
}

void my_pen::getRGBA(int &r, int &g, int &b, int &a)
{
    r = color.red;
    g = color.green;
    b = color.blue;
    a = color.alpha;
}
