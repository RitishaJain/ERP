#ifndef CHANGEMAIL_H
#define CHANGEMAIL_H

#include <QWidget>

namespace Ui {
class ChangeMail;
}

class ChangeMail : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeMail(QWidget *parent = nullptr);
    ~ChangeMail();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ChangeMail *ui;
};

#endif // CHANGEMAIL_H
