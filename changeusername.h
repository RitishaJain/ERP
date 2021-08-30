#ifndef CHANGEUSERNAME_H
#define CHANGEUSERNAME_H

#include <QWidget>

namespace Ui {
class ChangeUserName;
}

class ChangeUserName : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeUserName(QWidget *parent = nullptr);
    ~ChangeUserName();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ChangeUserName *ui;
};

#endif // CHANGEUSERNAME_H
