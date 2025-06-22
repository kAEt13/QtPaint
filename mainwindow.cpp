#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "my_pixel.h"
#include <QColorDialog>
#include "my_line.h"
#include "my_rect.h"
#include "my_ellips.h"
#include <QInputDialog>
#include <QDir>
#include <QDialog>
#include <rowcountdialog.h>
#include "my_polyline.h"
#include "my_polygon.h"
#include "QMessageBox"
#include <QCryptographicHash>
#include <QFileDialog>

QPoint* points = nullptr;
int points_cnt;

int obj_cnt = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->draw_widget->createImage(ui->draw_widget->width(), ui->draw_widget->height());
    ui->draw_widget->img.fill(Qt::white);

//    QPainter painter(&ui->draw_widget->img);
//    painter.setPen(Qt::NoPen);

//    // Grass
//    painter.setBrush(QColor("#C5FF95"));
//    painter.drawRect(0, 400, 800, 400);

//    // Sky
//    painter.setBrush(QColor("#1679AB"));
//    painter.drawRect(0, 0, 800, 400);

//    // House body
//    painter.setBrush(QColor("#074173"));
//    painter.drawRect(300, 200, 200, 200);

//    // House top
//    painter.setBrush(QColor("#074173"));
//    const QPoint points[3] = {
//         QPoint(300, 200),
//         QPoint(500, 200),
//         QPoint(400, 100)
//     };
//    painter.drawPolygon(points, 3);

//    // House Door
//    painter.setPen(QPen(QColor("#5DEBD7"),
//                                4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
//    painter.drawRect(450, 300, 30, 100);

//    // House Window
//    painter.setPen(QPen(QColor("#5DEBD7"),
//                                4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
//    painter.drawRect(350, 250, 50, 50);

//    painter.drawRect(350, 250, 25, 25);
//    painter.drawRect(375, 275, 25, 25);

//    // House Truba
//    painter.setPen(Qt::NoPen);
//    painter.setBrush(QColor("#074173"));
//    painter.drawRect(450, 100, 25, 100);

//    ui->draw_widget->repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_draw_btn_clicked(bool no_shapes_arr_changing)
{

    my_shape* new_shape;
    if (ui->spin_type->currentText() == "Пиксель") {
        new_shape = new my_pixel;

        new_shape->setPoints(new QPoint(ui->spinBox_x1->value(), ui->spinBox_y1->value()));
        new_shape->SetPen(my_pen(3, 1, color_pen));
        new_shape->draw(ui->draw_widget->img);
    } else if (ui->spin_type->currentText() == "Линия") {
        new_shape = new my_line;

        QPoint *points_line = new QPoint[2];
        points_line[0] = QPoint(ui->spinBox_x1->value(), ui->spinBox_y1->value());
        points_line[1] = QPoint(ui->spinBox_x2->value(), ui->spinBox_y2->value());

        new_shape->setPoints(points_line);
        new_shape->SetPen(my_pen(3, 1, color_pen));

        new_shape->draw(ui->draw_widget->img);

    } else if (ui->spin_type->currentText() == "Прямоугольник") {
        new_shape = new my_rect;

        QPoint *points_rect = new QPoint[2];
        points_rect[0] = QPoint(ui->spinBox_x1->value(), ui->spinBox_y1->value());
        points_rect[1] = QPoint(ui->spinBox_x2->value(), ui->spinBox_y2->value());

        // brush
        new_shape->SetBrush(my_brush(1, color_brush));
        // pen
        new_shape->SetPen(my_pen(3, 1, color_pen));

        new_shape->setPoints(points_rect);

        new_shape->draw(ui->draw_widget->img);
    } else if (ui->spin_type->currentText() == "Эллипс") {
        new_shape = new my_ellips;

        QPoint *points_ellips = new QPoint[2];
        points_ellips[0] = QPoint(ui->spinBox_x1->value(), ui->spinBox_y1->value());
        points_ellips[1] = QPoint(ui->spinBox_x2->value(), ui->spinBox_y2->value());
        // brush
        new_shape->SetBrush(my_brush(1, color_brush));
        // pen
        new_shape->SetPen(my_pen(3, 1, color_pen));
        new_shape->setPoints(points_ellips);

        new_shape->draw(ui->draw_widget->img);
    } else if (ui->spin_type->currentText() == "Ломанная") {
        if (points == nullptr) {
            QMessageBox::critical(nullptr, "Error", "<font color='red'>Сначала установите точки.</font>");
            return;
        }
        new_shape = new my_polyline;

        new_shape->setCount(points_cnt);
        new_shape->setPoints(points);
        new_shape->SetPen(my_pen(3, 1, color_pen));
        new_shape->draw(ui->draw_widget->img);

    } else if (ui->spin_type->currentText() == "Полигон") {
        if (points == nullptr) {
            QMessageBox::critical(nullptr, "Error", "<font color='red'>Сначала установите точки.</font>");
            return;
        }
        new_shape = new my_polygon;

        new_shape->setCount(points_cnt);
        new_shape->setPoints(points);
        new_shape->SetPen(my_pen(3, 1, color_pen));
        new_shape->SetBrush(my_brush(1, color_brush));
        new_shape->draw(ui->draw_widget->img);

    }

    if (!no_shapes_arr_changing) Shapes_array.append(new_shape);

    ui->draw_widget->repaint();
    // new item in table
    obj_cnt += 1;
    ui->table_objects->setRowCount(obj_cnt);
    ui->table_objects->setItem(obj_cnt - 1, 0, new QTableWidgetItem(ui->spin_type->currentText()));
}


void MainWindow::on_btn_color_pen_clicked()
{
    color_pen = my_color(QColorDialog().getColor());
    QString btnStyle = QString("background-color: rgb(%1, %2, %3);").arg(QString::number(color_pen.red), QString::number(color_pen.green), QString::number(color_pen.blue));
    ui->btn_color_pen->setStyleSheet(btnStyle);
}


void MainWindow::on_btn_color_brush_clicked()
{
    color_brush = my_color(QColorDialog().getColor());
    QString btnStyle = QString("background-color: rgb(%1, %2, %3);").arg(QString::number(color_brush.red), QString::number(color_brush.green), QString::number(color_brush.blue));
    ui->btn_color_brush->setStyleSheet(btnStyle);
}


void MainWindow::on_set_points_clicked()
{
    bool ok;
    points_cnt = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
                              tr("Количество точек:"), 0, 1, 100000, 1, &ok);
    if (!ok) return;
    if (points_cnt <= 2) {
        QMessageBox::information(this, "Ошибка", "Должно быть больше 2 точек");
        return;
    }

    rowCountDialog *dialog = new rowCountDialog(points_cnt,
                                                &points, this);
    dialog->exec();
}


void MainWindow::on_btn_clear_clicked()
{
    Shapes_array.clear();
    ui->draw_widget->img.fill(Qt::white);
    ui->draw_widget->repaint();
    ui->table_objects->clear();
    ui->table_objects->setRowCount(0);
    obj_cnt = 0;
}


void MainWindow::on_spin_type_currentIndexChanged(int index)
{

}


void MainWindow::on_spin_type_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "Пиксель") {
        ui->btn_color_pen->setEnabled(true);
        ui->btn_color_brush->setEnabled(false);
        ui->spinBox_x1->setEnabled(true);
        ui->spinBox_y1->setEnabled(true);
        ui->spinBox_x2->setEnabled(false);
        ui->spinBox_y2->setEnabled(false);
        ui->set_points->setEnabled(false);
    } else if (arg1 == "Линия") {
        ui->btn_color_pen->setEnabled(true);
        ui->btn_color_brush->setEnabled(false);
        ui->spinBox_x1->setEnabled(true);
        ui->spinBox_y1->setEnabled(true);
        ui->spinBox_x2->setEnabled(true);
        ui->spinBox_y2->setEnabled(true);
        ui->set_points->setEnabled(false);
    } else if (arg1 == "Прямоугольник") {
        ui->btn_color_pen->setEnabled(true);
        ui->btn_color_brush->setEnabled(true);
        ui->spinBox_x1->setEnabled(true);
        ui->spinBox_y1->setEnabled(true);
        ui->spinBox_x2->setEnabled(true);
        ui->spinBox_y2->setEnabled(true);
        ui->set_points->setEnabled(false);
    } else if (arg1 == "Эллипс") {
        ui->btn_color_pen->setEnabled(true);
        ui->btn_color_brush->setEnabled(true);
        ui->spinBox_x1->setEnabled(true);
        ui->spinBox_y1->setEnabled(true);
        ui->spinBox_x2->setEnabled(true);
        ui->spinBox_y2->setEnabled(true);
        ui->set_points->setEnabled(false);
    } else if (arg1 == "Ломанная") {
        ui->btn_color_pen->setEnabled(true);
        ui->btn_color_brush->setEnabled(false);
        ui->spinBox_x1->setEnabled(false);
        ui->spinBox_y1->setEnabled(false);
        ui->spinBox_x2->setEnabled(false);
        ui->spinBox_y2->setEnabled(false);
        ui->set_points->setEnabled(true);
    } else if (arg1 == "Полигон") {
        ui->btn_color_pen->setEnabled(true);
        ui->btn_color_brush->setEnabled(true);
        ui->spinBox_x1->setEnabled(false);
        ui->spinBox_y1->setEnabled(false);
        ui->spinBox_x2->setEnabled(false);
        ui->spinBox_y2->setEnabled(false);
        ui->set_points->setEnabled(true);
    }
}


void MainWindow::on_pushButton_save_clicked()
{
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this, "Сохранить как .bin", "C:/Users/student/Desktop", "Binary files (*.bin)"); //Путь до файла
    if(fileName.isEmpty())
    {
        QMessageBox::information(this, "Ошибка", "Файл не выбран");
    }
    else
    {
        QFile file;
        file.setFileName(fileName);
        file.open(QIODevice::WriteOnly);

        QByteArray buff;

        QCryptographicHash hash(QCryptographicHash::Md5); // Хэш

        char *mas;
        int sz_int = sizeof(int);
        mas = new char[sz_int];

        int size = ui->table_objects->rowCount();
        memcpy(mas, &size, size_t(sz_int));
        buff.append(mas, sz_int);

        int int_count = 1;
        for(int i = 0; i < size; i++){
            memcpy(mas, &bin_spacer, size_t(sz_int));
            buff.append(mas, sz_int);
            int_count+=1;
            my_shape* current_shape = Shapes_array[i];
            for(int j = 0; j < 4; j++) {
                ShapeProperties property = static_cast<ShapeProperties>(j);
                switch (property)  {
                case MyShapeType:{
                    qDebug() << int_count << " " << current_shape->GetType();
                    int ShapeType = current_shape->GetType();
                    memcpy(mas,&ShapeType,size_t(sz_int));
                    buff.append(mas, sz_int);
                    int_count+=1;
                    break;}
                case Line:{
                    my_pen pen = current_shape->GetPen();

                    int width = pen.getWidth();
                    memcpy(mas,&width,size_t(sz_int));
                    buff.append(mas, sz_int);
                    int_count+=1;
                    int Style = pen.getStyle();
                    memcpy(mas,&Style,size_t(sz_int));
                    buff.append(mas, sz_int);
                    int_count+=1;
                    int r,g,b,a;
                    pen.GetColor().getRGBA(r,g,b,a);

                    memcpy(mas,&r,size_t(sz_int));
                    buff.append(mas, sz_int);
                    int_count+=1;
                    memcpy(mas,&g,size_t(sz_int));
                    buff.append(mas, sz_int);
                    int_count+=1;

                    memcpy(mas,&b,size_t(sz_int));
                    buff.append(mas, sz_int);
                    int_count+=1;

                    memcpy(mas,&a,size_t(sz_int));
                    buff.append(mas, sz_int);
                    int_count+=1;

                    break;}
                case Fill:{
                    my_brush brush = current_shape->GetBrush();

                    int Style = brush.getStyle();
                    memcpy(mas,&Style,size_t(sz_int));
                    buff.append(mas, sz_int);
                    int_count+=1;

                    int r,g,b,a;
                    brush.getRGBA(r,g,b,a);

                    memcpy(mas,&r,size_t(sz_int));
                    buff.append(mas, sz_int);
                    int_count+=1;

                    memcpy(mas,&g,size_t(sz_int));
                    buff.append(mas, sz_int);
                    int_count+=1;

                    memcpy(mas,&b,size_t(sz_int));
                    buff.append(mas, sz_int);
                    int_count+=1;

                    memcpy(mas,&a,size_t(sz_int));
                    buff.append(mas, sz_int);
                    int_count+=1;
                    break;}
                case Points:{
                    int amount = current_shape->getCount();
                    memcpy(mas,&amount,size_t(sz_int));
                    buff.append(mas, sz_int);
                    int_count+=1;
                    int x,y;
                    QPoint *points;
                    points = current_shape->getPoints();
                    for(int k = 0; k<amount; k++){
                        x = points[k].x();
                        y = points[k].y();
                        memcpy(mas,&x,size_t(sz_int));
                        buff.append(mas, sz_int);
                        int_count+=1;
                        memcpy(mas,&y,size_t(sz_int));
                        buff.append(mas, sz_int);
                        int_count+=1;
                    }
                    break;}
                default:
                    // error
                    break;
                }
            }
            memcpy(mas, &bin_spacer, size_t(sz_int));
            buff.append(mas, sz_int);
            int_count+=1;
        }
        memcpy(mas, &bin_ender, size_t(sz_int));
        buff.append(mas, sz_int);
        int_count+=1;
        hash.addData(buff);
        file.write(hash.result(), 16);
        file.write(buff, sz_int * (int_count));
        file.close();
        delete [] mas;
    }
}


void MainWindow::on_pushButton_open_clicked()
{
    char *mas; //Объявляем массив
    int sz_int = sizeof(int); //Записываем сколько займет int
    mas =new char[sz_int]; //Выделяем память
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Открыть .bin", "C:/Users/student/Desktop", "Binary files(*.bin)");

    if(fileName.isEmpty())
    {
        QMessageBox::information(this, "Ошибка", "Файл не выбран");
    } else {
        QFile file;
        file.setFileName(fileName);
        file.open(QIODevice::ReadOnly);

        QByteArray buff;
        QCryptographicHash hash(QCryptographicHash::Md5);

        buff = file.read(16);
        QString checksum;
        checksum.append(buff);

        buff = file.readAll();
        hash.addData(buff);
        QString checksum_new;
        checksum_new.append(hash.result());
        file.close();
        if(checksum != checksum_new){
            QMessageBox::information(this, "Ошибка", "Неверный формат файла");
            return;
        } else {
            on_btn_clear_clicked();

            file.open(QIODevice::ReadOnly);
            buff = file.read(16);
            int sz_int = sizeof(int);
            int size;
            file.read(mas, sz_int);
            memcpy(&size, mas, size_t(sz_int));
            for(int i = 0; i < size; i ++) {
                int readInt;
                file.read(mas, sz_int);
                memcpy(&readInt, mas, size_t(sz_int));
                if(readInt == bin_spacer) {
                    bool error_exit = false;
                    readInt = 0;
                    while (readInt != bin_spacer)  {
                        //Тип объекта
                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        if(readInt == bin_ender){
                            break;
                        }
                        Type current_shape = static_cast<Type>(readInt);
                        my_shape *new_shape;
                        switch(current_shape){
                        case PixelType:
                            new_shape = new my_pixel;
                            break;
                        case LineType:
                            new_shape = new my_line;
                            break;
                        case RectType:
                            new_shape = new my_rect;
                            break;
                        case EllipseType:
                            new_shape = new my_ellips;
                            break;
                        case PolylineType:
                            new_shape = new my_polyline;
                            break;
                        case PolygonType:
                            new_shape = new my_polygon;
                            break;
                        default:
                            qDebug() << current_shape;
                            QMessageBox::information(this, "Ошибка", "Неверный тип фигуры");
                            break;
                        }
                        //Обводка
                        my_pen pen;
                        my_color color;

                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        int size = readInt;
                        pen.setWidth(size);

                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        int style = readInt;
                        pen.setStyle(style);

                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        int r = readInt;
                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        int g = readInt;
                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        int b = readInt;
                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        int a = readInt;
                        color.setRGBA(r,g,b,a);
                        pen.SetColor(color);
                        new_shape->SetPen(pen);

                        //Заливка
                        my_brush brush;

                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        style = readInt;
                        brush.setStyle(style);

                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        r = readInt;
                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        g = readInt;
                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        b = readInt;
                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        a = readInt;
                        color.setRGBA(r,g,b,a);
                        brush.setRGBA(r, g, b, a);
                        new_shape->SetBrush(brush);

                        //Точки
                        int points_count;
                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        points_count = readInt;
                        qDebug() << "points cnt :" << points_count;
                        new_shape->setCount(points_count);
                        QPoint* points;
                        points = new QPoint[points_count];
                        int x,y;
                        for(int i = 0; i<points_count; i++){
                            file.read(mas, sz_int);
                            memcpy(&readInt, mas, size_t(sz_int));
                            x = readInt;
                            qDebug() << x;
                            file.read(mas, sz_int);
                            memcpy(&readInt, mas, size_t(sz_int));
                            y = readInt;
                            qDebug() << y;
                            points[i].setX(x);
                            points[i].setY(y);
                        }
                        new_shape->setPoints(points);
                        delete [] points;
                        points = nullptr;
                        Shapes_array.append(new_shape);
                        file.read(mas, sz_int);
                        memcpy(&readInt, mas, size_t(sz_int));
                        if(readInt != bin_spacer){
                            error_exit = true;
                            break;
                        }

                    }

                    if(error_exit){
                        QMessageBox::information(this, "Ошибка", "Ошибка");
                    }

                } else {
                    QMessageBox::information(this, "Ошибка", "Нет первого разделителя");
                }

            }

            file.close();
            delete [] mas;
            for(int index = 0; index < Shapes_array.size(); index++) {
                my_shape* current_shape = Shapes_array[index];
                color_pen = my_color(current_shape->GetPen().GetColor());
                color_brush = my_color(current_shape->GetBrush().getColor());

                Type currentType = current_shape->GetType();

                switch (currentType) {
                case PixelType:
                    ui->spin_type->setCurrentIndex(0);
                    ui->spinBox_x1->setValue(current_shape->getPoints()[0].x());
                    ui->spinBox_y1->setValue(current_shape->getPoints()[0].y());
                    break;
                case LineType:
                    ui->spin_type->setCurrentIndex(1);
                    ui->spinBox_x1->setValue(current_shape->getPoints()[0].x());
                    ui->spinBox_y1->setValue(current_shape->getPoints()[0].y());
                    ui->spinBox_x2->setValue(current_shape->getPoints()[1].x());
                    ui->spinBox_y2->setValue(current_shape->getPoints()[1].y());
                    break;
                case RectType:
                    qDebug() << current_shape->getPoints()[0].x() << " " << current_shape->getPoints()[0].y();
                    qDebug() << current_shape->getPoints()[1].x() << " " << current_shape->getPoints()[1].y();
                    ui->spin_type->setCurrentIndex(2);
                    ui->spinBox_x1->setValue(current_shape->getPoints()[0].x());
                    ui->spinBox_y1->setValue(current_shape->getPoints()[0].y());
                    ui->spinBox_x2->setValue(current_shape->getPoints()[1].x());
                    ui->spinBox_y2->setValue(current_shape->getPoints()[1].y());
                    break;
                case EllipseType:
                    ui->spin_type->setCurrentIndex(3);
                    ui->spinBox_x1->setValue(current_shape->getPoints()[0].x());
                    ui->spinBox_y1->setValue(current_shape->getPoints()[0].y());
                    ui->spinBox_x2->setValue(current_shape->getPoints()[1].x());
                    ui->spinBox_y2->setValue(current_shape->getPoints()[1].y());
                    break;
                case PolylineType:
                    ui->spin_type->setCurrentIndex(4);
                    points_cnt = current_shape->getCount();
                    points = current_shape->getPoints();
                    break;
                case PolygonType:
                    ui->spin_type->setCurrentIndex(5);
                    points_cnt = current_shape->getCount();
                    points = current_shape->getPoints();
                    break;
                default:
                    QMessageBox::information(this, "Ошибка", "Неверный тип фигуры в конце");
//                    return;
                    break;
                }
                on_draw_btn_clicked(true);
            }
        }
    }
}

