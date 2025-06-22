#include "my_brush.h"

my_brush::my_brush()
{
    style = 1;
}

my_brush::my_brush(int in_n_style, my_color in_color)
{
    style = in_n_style;
    in_color.getRGBA(red, green, blue, alpha);
}

bool my_brush::setStyle(int n_style)
{
    //добавить проверки
    style = n_style;

    return true;
}

int my_brush::getStyle(void)
{
    return style;
}

my_color my_brush::getColor() {
    return my_color(red, green, blue, alpha);
}
