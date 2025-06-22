#ifndef MY_LINE_H
#define MY_LINE_H
#include "my_point.h"
#include "my_pen.h"
#include <QImage>
#include <QPainter>
#include <my_shape.h>


class my_line : public my_shape
{
public:
    my_line();

    void draw(QImage &im) override;
    virtual Type GetType() override{
        return LineType;
    }

//    my_point start;

//    my_point end;

//    my_pen pen;
};

#endif // MY_LINE_H
