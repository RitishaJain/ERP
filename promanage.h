#ifndef PROMANAGE_H
#define PROMANAGE_H

#include <QWidget>
#include <type.h>
#include <typefin.h>
#include <typest.h>

namespace Ui {
class ProManage;
}

class ProManage : public QWidget
{
    Q_OBJECT

public:
    explicit ProManage(QWidget *parent = nullptr);
    ~ProManage();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::ProManage *ui;
    TYPE *tp;
    typest *tps;
    typefin *tpf;
};

#endif // PROMANAGE_H
