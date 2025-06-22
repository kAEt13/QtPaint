#ifndef MY_PEN_H
#define MY_PEN_H
#include "my_color.h"


class my_pen
{
public:
    my_pen();

    my_pen(int width, int style, my_color color);

    bool setWidth(int n_width);
    int getWidth(void);

    bool setStyle(int n_style);
    int getStyle(void);

    my_color GetColor(){
        return color;
    };
    void SetColor(my_color color_n){
        color = color_n;
    };

    bool setRGBA(int r, int g, int b, int a);

    void getRGBA(int &r, int&g, int &b, int &a);



protected:
    int width;

    int style;
    my_color color;
};

#endif // MY_PEN_H
