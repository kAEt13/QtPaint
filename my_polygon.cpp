#include "my_polygon.h"

my_polygon::my_polygon()
{

}

void my_polygon::draw(QImage &im)
{
    QPainter painter(&im);
    QColor color;

    int r, g, b, a;
    pen.getRGBA(r, g, b, a);

    color.setRgb(r, g, b, a);

    QPen qpen;
    qpen.setWidth(5);
    qpen.setColor(color);

    switch (pen.getStyle())
    {
        case 0:
            qpen.setStyle(Qt::NoPen);

            break;
        case 1:
            qpen.setStyle(Qt::SolidLine);

            break;
        case 2:
            qpen.setStyle(Qt::DashLine);

            break;
        //
    }

    QBrush qbrush;
    brush.getRGBA(r, g, b, a);
    color.setRgb(r, g, b, a);
    qbrush.setColor(color);

    switch (brush.getStyle())
    {
        case 0:
            qbrush.setStyle(Qt::NoBrush);

            break;
        case 1:
            qbrush.setStyle(Qt::SolidPattern);

            break;
        //
    }

    painter.setPen(qpen);
    painter.setBrush(qbrush);

    painter.drawPolygon(points, points_count);
}


