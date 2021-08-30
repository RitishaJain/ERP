#ifndef STITCHING_H
#define STITCHING_H

#include <QWidget>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
namespace Ui {
class stitching;
}

class stitching : public QWidget
{
    Q_OBJECT

public:
    explicit stitching(QWidget *parent = nullptr);
    ~stitching();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_pushButton_clicked();

private:
    Ui::stitching *ui;
    QSqlDatabase m_db;
    void filltable();
};

#endif // STITCHING_H
