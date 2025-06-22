#include "my_polyline.h"

my_polyline::my_polyline()
{
    points_count = 0;
    delete [] points;
    points = nullptr;
}



void my_polyline::draw(QImage &im)
{
    QPainter painter(&im);
    QColor color;

    int r, g, b, a;
    pen.getRGBA(r, g, b, a);

    color.setRgb(r, g, b, a);

    QPen qpen;
    qpen.setWidth(pen.getWidth());
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

    painter.setPen(qpen);
    painter.drawPolyline(points, points_count);
}
