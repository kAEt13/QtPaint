#include "my_line.h"

my_line::my_line()
{
    setCount(2);
    QPoint *point = new QPoint[points_count];
    point[0].setX(0);
    point[0].setY(0);
    point[1].setX(0);
    point[1].setY(0);
    setCount(2); //Кол-во точек
    setPoints(point); //Установка точки
    delete [] point;
    point = nullptr;
}

void my_line::draw(QImage &im)
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
    int x1, y1, x2, y2;
    x1 = points[0].x();
    y1 = points[0].y();
    x2 = points[1].x();
    y2 = points[1].y();

    painter.drawLine(x1, y1, x2, y2);
}
