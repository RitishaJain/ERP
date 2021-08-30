#ifndef ADDEMPLOYEE_H
#define ADDEMPLOYEE_H

#include <QWidget>

namespace Ui {
class addemployee;
}

class addemployee : public QWidget
{
    Q_OBJECT

public:
    explicit addemployee(QWidget *parent = nullptr);
    ~addemployee();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::addemployee *ui;
};

#endif // ADDEMPLOYEE_H
