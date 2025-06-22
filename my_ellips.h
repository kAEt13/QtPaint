#ifndef MY_ELLIPS_H
#define MY_ELLIPS_H
#include "my_brush.h"
#include "my_pen.h"
#include "my_rect.h"
#include <QImage>
#include <QPainter>

class my_ellips : public my_rect
{
public:
    my_ellips();

    void draw(QImage &im) override;
    virtual Type GetType() override{
        return EllipseType;
    }
};

#endif // MY_ELLIPS_H
