#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include<QMessageBox>
#include <dash.h>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT


public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();



private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    Dash *dashb;


};

#endif // LOGIN_H

