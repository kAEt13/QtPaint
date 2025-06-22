#ifndef MY_SHAPE_H
#define MY_SHAPE_H

#include <my_pen.h>
#include <my_brush.h>
#include <QPoint>
#include <QImage>

enum Type{
    PixelType,
    LineType,
    RectType,
    EllipseType,
    PolylineType,
    PolygonType,
    ShapeType
};

enum ShapeProperties{
    MyShapeType,
    Line,
    Fill,
    Points
};

class my_shape
{
public:
    my_shape();

    virtual void draw(QImage &im);

    // Получить тип
    virtual Type GetType(){
        return ShapeType;
    }

    // Ручка и кисть
    my_pen GetPen();
    void SetPen(my_pen pen_n);
    my_brush GetBrush();
    void SetBrush(my_brush brush_n);

    // Точки
    void setPoints(QPoint *points_new);
    void setCount(int count_new);
    int getCount();
    QPoint* getPoints();

protected:
    //Ручка и кисть
    my_pen pen;
    my_brush brush;
    //Точки
    int points_count = 1;
    QPoint *points = new QPoint[points_count];
};

#endif // MY_SHAPE_H
