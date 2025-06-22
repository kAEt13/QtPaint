#ifndef MY_BRUSH_H
#define MY_BRUSH_H
#include "my_color.h"


class my_brush : public my_color
{
public:
    my_brush();

    my_brush(int n_style, my_color color);

    bool setStyle(int n_style);

    int getStyle(void);

    my_color getColor();

protected:
    int style;
};

#endif // MY_BRUSH_H
