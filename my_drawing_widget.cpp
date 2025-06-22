#include "my_drawing_widget.h"
#include <QDebug>

my_drawing_widget::my_drawing_widget(QWidget *parent) : QWidget(parent)
{

}

void my_drawing_widget::paintEvent(QPaintEvent *) {
    if (isImgCreated) {
        QPainter painter(this);
        painter.drawImage(0, 0, img);
    }
}

void my_drawing_widget::createImage(int size_x, int size_y)
{
    if (isImgCreated == false)
    {
        img = QImage(size_x, size_y, QImage::Format_ARGB32_Premultiplied);
        isImgCreated = true;
    }
    else
    {
        //
    }
}
