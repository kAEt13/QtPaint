#ifndef MY_PIXEL_H
#define MY_PIXEL_H
#include "my_color.h"
#include "my_point.h"
#include <QPainter>
#include <my_shape.h>

class my_pixel : public my_shape
{
public:
    my_pixel();

    void draw(QImage &im) override;
    virtual Type GetType() override{
        return PixelType;
    }
};

#endif // MY_PIXEL_H
