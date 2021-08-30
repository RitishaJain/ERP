#ifndef TYPEFIN_H
#define TYPEFIN_H

#include <QWidget>
#include <finishing.h>
#include <finishingv.h>

namespace Ui {
class typefin;
}

class typefin : public QWidget
{
    Q_OBJECT

public:
    explicit typefin(QWidget *parent = nullptr);
    ~typefin();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::typefin *ui;
    finishing *fin;
    finishingv *finv;
};

#endif // TYPEFIN_H
