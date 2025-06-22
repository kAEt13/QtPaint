#ifndef ROWCOUNTDIALOG_H
#define ROWCOUNTDIALOG_H

#include <QDialog>
#include <QPoint>

namespace Ui {
class rowCountDialog;
}

class rowCountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit rowCountDialog(int point_count, QPoint **in_points, QWidget *parent = nullptr);
    ~rowCountDialog();

private slots:
    void on_btn_save_points_clicked();

private:
    Ui::rowCountDialog *ui;
    int point_count;
    QPoint **points = nullptr;
};

#endif // ROWCOUNTDIALOG_H
