#ifndef MY_POLYLINE_H
#define MY_POLYLINE_H
#include "my_pen.h"
#include <QImage>
#include <QPainter>
#include <my_shape.h>


class my_polyline : public my_shape
{
public:
    my_polyline();

    void draw(QImage &im) override;
    virtual Type GetType() override{
        return PolylineType;
    }
};

#endif // MY_POLYLINE_H
