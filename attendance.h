#ifndef ATTENDANCE_H
#define ATTENDANCE_H
#include <QWidget>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>



namespace Ui {
class attendance;
}

class attendance : public QWidget
{
    Q_OBJECT

public:

    explicit attendance(QWidget *parent = nullptr);
    ~attendance();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_table_activated(const QModelIndex &index);

    void on_calendarWidget_clicked(const QDate &date);

    void on_calendarWidget_activated(const QDate &date);

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::attendance *ui;
    QSqlDatabase m_db;
    void filltable();
    void refresh();
};

#endif // ATTENDANCE_H
