#ifndef TYPEST_H
#define TYPEST_H

#include <QWidget>
#include <stitching.h>
#include <stitchingv.h>

namespace Ui {
class typest;
}

class typest : public QWidget
{
    Q_OBJECT

public:
    explicit typest(QWidget *parent = nullptr);
    ~typest();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::typest *ui;
    stitching *st;
    stitchingv *stv;
};

#endif // TYPEST_H
