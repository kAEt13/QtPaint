#include "my_pixel.h"
#include <qDebug>

my_pixel::my_pixel()
{
//    in_color.getRGBA(red, green, blue, alpha);
//    in_point.getXY(x, y);

    QPoint *point = new QPoint[points_count];
    point[0].setX(0);
    point[0].setY(0);
    setPoints(point); //Установка точки
    delete [] point;
    point = nullptr;
}

void my_pixel::draw(QImage &im)
{
    QPainter painter(&im);
    QColor color = pen.GetColor().toQColor();

    QPen pen;
    pen.setWidth(1);
    pen.setColor(color);

    painter.setPen(pen);
    painter.drawPoint(getPoints()[0].x(),getPoints()[0].y());
}
