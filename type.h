#ifndef TYPE_H
#define TYPE_H

#include <QWidget>
#include <cutting.h>
#include <cuttingv.h>


namespace Ui {
class TYPE;
}

class TYPE : public QWidget
{
    Q_OBJECT

public:
    explicit TYPE(QWidget *parent = nullptr);
    ~TYPE();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TYPE *ui;
    cutting *cut;
    cuttingv *cutv;
};

#endif // TYPE_H
