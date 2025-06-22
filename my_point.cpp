#include "my_point.h"

my_point::my_point()
{
    x = 0;
    y = 0;
}

my_point::my_point(int in_x, int in_y)
{
    x = in_x;
    y = in_y;
}

void my_point::setX(int new_x)
{
    x = new_x;
}

void my_point::setY(int new_y)
{
    y = new_y;
}

void my_point::setXY(int new_x, int new_y)
{
    x = new_x;
    y = new_y;
}

int my_point::getX(void)
{
    return x;
}

int my_point::getY(void)
{
    return y;
}

void my_point::getXY(int &n_x, int &n_y)
{
    n_x = x;
    n_y = y;
}
