#ifndef MY_RECT_H
#define MY_RECT_H
#include "my_brush.h"
#include "my_pen.h"
#include "my_point.h"
#include <QImage>
#include <QPainter>
#include <my_shape.h>


class my_rect : public my_shape
{
public:
    my_rect();

    void draw(QImage &im) override;
    virtual Type GetType() override{
        return RectType;
    }
};

#endif // MY_RECT_H
