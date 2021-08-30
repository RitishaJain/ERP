#ifndef ACCOUNTMANAGEMENT_H
#define ACCOUNTMANAGEMENT_H

#include <QWidget>
#include <adduser.h>
#include <changemail.h>
#include <changepass.h>
#include <changeusername.h>
#include <changephone.h>


namespace Ui {
class AccountManagement;
}

class AccountManagement : public QWidget
{
    Q_OBJECT

public:
    explicit AccountManagement(QWidget *parent = nullptr);
    ~AccountManagement();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::AccountManagement *ui;
    adduser *au;
    ChangeMail *cm;
    ChangePasS *cp;
    ChangeUserName *cu;
    CHANGEPHONE *cph;
};

#endif // ACCOUNTMANAGEMENT_H
