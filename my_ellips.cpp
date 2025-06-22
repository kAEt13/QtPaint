#include "my_ellips.h"

my_ellips::my_ellips()
{
    setCount(2); //Кол-во точек
    QPoint *point = new QPoint[points_count];
    point[0].setX(0);
    point[0].setY(0);
    point[1].setX(0);
    point[1].setY(0);
    setPoints(point); //Установка точки
    delete [] point;
    point = nullptr;
}

void my_ellips::draw(QImage &im)
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

    int x1, x2, y1, y2;
    x1 = points[0].x();
    y1 = points[0].y();
    x2 = points[1].x();
    y2 = points[1].y();

    painter.drawEllipse(x1, y1, x2 - x1, y2 - y1);
}
