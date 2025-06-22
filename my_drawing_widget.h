#ifndef MY_DRAWING_WIDGET_H
#define MY_DRAWING_WIDGET_H

#include <QWidget>
#include <QPainter>

class my_drawing_widget : public QWidget
{
    Q_OBJECT
public:
    explicit my_drawing_widget(QWidget *parent = nullptr);
    QImage img;
    void createImage(int size_x, int size_y);

signals:

private:
    bool isImgCreated;

protected:
    void paintEvent(QPaintEvent *);
};

#endif // MY_DRAWING_WIDGET_H
