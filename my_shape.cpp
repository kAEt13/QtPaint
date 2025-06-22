#include "my_shape.h"

my_shape::my_shape()
{

}

my_pen my_shape::GetPen(){
    return pen;
}

void my_shape::SetPen(my_pen pen_n){
    pen = pen_n;
}

my_brush my_shape::GetBrush(){
    return brush;
}

void my_shape::SetBrush(my_brush brush_n){
    brush = brush_n;
}

int my_shape::getCount(){
    return points_count;
}

void my_shape::setCount(int count_new){
    points_count = count_new;
}

QPoint* my_shape::getPoints(){
    return points;
}

void my_shape::setPoints(QPoint *points_new){
    delete [] points;
    points = new QPoint[points_count];
    memcpy(points,points_new,points_count*sizeof(QPoint));
}

void my_shape::draw(QImage &im){

}
