#include "my_color.h"

my_color::my_color()
{
    red = 0;
    green = 0;
    blue = 0;
    alpha = 255;
}

my_color::my_color(int r, int g, int b, int a) {
    red = r;
    green = g;
    blue = b;
    alpha = a;
}

my_color::my_color(QColor qcolor) {
    red = qcolor.red();
    green = qcolor.green();
    blue = qcolor.blue();
    alpha = qcolor.alpha();
}

bool my_color::setRGBA(int r, int g, int b, int a)
{
    //добавить проверки
    red = r;
    green = g;
    blue = b;
    alpha = a;
}

void my_color::getRGBA(int &r, int &g, int &b, int &a)
{
    r = red;
    g = green;
    b = blue;
    a = alpha;
}

