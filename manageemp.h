#ifndef MANAGEEMP_H
#define MANAGEEMP_H
#include <QWidget>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>

#include <QWidget>

namespace Ui {
class ManageEmp;
}

class ManageEmp : public QWidget
{
    Q_OBJECT

public:
    explicit ManageEmp(QWidget *parent = nullptr);
    ~ManageEmp();
    int noemp;

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ManageEmp *ui;
    QSqlDatabase m_db;
    void filltable();
};

#endif // MANAGEEMP_H
