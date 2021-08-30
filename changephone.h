#ifndef CHANGEPHONE_H
#define CHANGEPHONE_H

#include <QWidget>

namespace Ui {
class CHANGEPHONE;
}

class CHANGEPHONE : public QWidget
{
    Q_OBJECT

public:
    explicit CHANGEPHONE(QWidget *parent = nullptr);
    ~CHANGEPHONE();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CHANGEPHONE *ui;
};

#endif // CHANGEPHONE_H
