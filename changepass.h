#ifndef CHANGEPASS_H
#define CHANGEPASS_H

#include <QWidget>

namespace Ui {
class ChangePasS;
}

class ChangePasS : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePasS(QWidget *parent = nullptr);
    ~ChangePasS();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChangePasS *ui;
};

#endif // CHANGEPASS_H
