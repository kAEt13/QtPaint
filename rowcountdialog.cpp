#include "rowcountdialog.h"
#include "ui_rowcountdialog.h"
#include <qDebug>
#include <QMessageBox>

rowCountDialog::rowCountDialog(int in_point_count, QPoint **in_points, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rowCountDialog)
{
    ui->setupUi(this);

    ui->table_points->setRowCount(in_point_count);
    point_count = in_point_count;
    points = in_points;
}

rowCountDialog::~rowCountDialog()
{
    delete ui;
}

void rowCountDialog::on_btn_save_points_clicked()
{
    for (int i = 0; i < point_count; i++) {
        if (!ui->table_points->item(i, 0) ||
                !ui->table_points->item(i, 1)) {
            QMessageBox msgBox;
            msgBox.setText("Не все поля заполнены.");
            msgBox.exec();
            reject();
            return;
        }
        bool ok1, ok2;
        int test1 = ui->table_points->item(i, 0)->text().toInt(&ok1);
        int test2 = ui->table_points->item(i, 1)->text().toInt(&ok2);

        if (test1 <= 0 || test2 <= 0) {
            QMessageBox msgBox;
            msgBox.setText("Координаты меньше нуля.");
            msgBox.exec();
            reject();
            return;
        }

        if (i == point_count - 1 and ((test1 == ui->table_points->item(0, 0)->text().toInt(&ok1) and
                       test2 == ui->table_points->item(0, 1)->text().toInt(&ok1)))) {
            QMessageBox msgBox;
            msgBox.setText("Координаты повторяются.");
            msgBox.exec();
        }

        if (i >= 1 and ((test1 == ui->table_points->item(i - 1, 0)->text().toInt(&ok1) and
                       test2 == ui->table_points->item(i - 1, 1)->text().toInt(&ok1)))) {
            QMessageBox msgBox;
            msgBox.setText("Координаты повторяются.");
            msgBox.exec();
        }

        if (test1 > 800 || test2 > 800) {
            QMessageBox msgBox;
            msgBox.setText("Координаты больше окна.");
            msgBox.exec();
            reject();
            return;
        }
        if (!ok1 || !ok2) {
            QMessageBox msgBox;
            msgBox.setText("Используйте цифры.");
            msgBox.exec();
            reject();
            return;
        }
    }

    *points = new QPoint[point_count];
    for (int i = 0; i < point_count; i++) {
        int cur_x = ui->table_points->item(i, 0)->text().toInt();
        int cur_y = ui->table_points->item(i, 1)->text().toInt();

        (*points)[i].setX(cur_x);
        (*points)[i].setY(cur_y);

        accept();
    }
}

