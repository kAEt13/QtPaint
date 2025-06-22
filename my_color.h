#ifndef MY_COLOR_H
#define MY_COLOR_H

#include <QColor>

class my_color
{
public:
    my_color();

    my_color(int r, int g, int b, int a);

    my_color(QColor qcolor);

    bool setRGBA(int r, int g, int b, int a);

    void getRGBA(int &r, int&g, int &b, int &a);

    QColor toQColor() {
        QColor color;
        color.setRgb(red, green, blue, alpha);
        return color;
    }

    int red;
    int green;
    int blue;
    int alpha;
};

#endif // MY_COLOR_H
