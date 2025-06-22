#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QRandomGenerator>
#include <QDebug>
#include "my_color.h"
#include "my_brush.h"
#include <my_shape.h>
#include <my_pen.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




private slots:
    void on_draw_btn_clicked(bool no_shapes_arr_changing = false);

    void on_btn_color_pen_clicked();

    void on_btn_color_brush_clicked();

    void on_set_points_clicked();

    void on_btn_clear_clicked();

    void on_spin_type_currentIndexChanged(int index);

    void on_spin_type_currentIndexChanged(const QString &arg1);

    void on_pushButton_save_clicked();

    void on_pushButton_open_clicked();

private:
    Ui::MainWindow *ui;

    my_color color_pen;
    my_color color_brush;
    const int bin_spacer = 286331153; //Разделитель объектов
    const int bin_ender = 999999;
    QVector<my_shape*> Shapes_array;
};
#endif // MAINWINDOW_H
