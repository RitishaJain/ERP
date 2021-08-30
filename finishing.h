#ifndef FINISHING_H
#define FINISHING_H

#include <QWidget>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>

namespace Ui {
class finishing;
}

class finishing : public QWidget
{
    Q_OBJECT

public:
    explicit finishing(QWidget *parent = nullptr);
    ~finishing();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_clicked();

private:
    Ui::finishing *ui;
    QSqlDatabase m_db;
    void filltable();
};

#endif // FINISHING_H
