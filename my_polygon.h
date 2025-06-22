#ifndef MY_POLYGON_H
#define MY_POLYGON_H
#include "my_polyline.h"
#include "my_brush.h"
#include <QImage>
#include <QPainter>


class my_polygon : public my_polyline
{
public:
    my_polygon();

    void draw(QImage &im) override;

    virtual Type GetType() override{
        return PolygonType;
    }

};

#endif // MY_POLYGON_H
