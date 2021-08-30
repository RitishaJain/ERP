#ifndef CUTTING_H
#define CUTTING_H

#include <QWidget>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>




namespace Ui {
class cutting;
}

class cutting : public QWidget
{
    Q_OBJECT

public:
    explicit cutting(QWidget *parent = nullptr);
    ~cutting();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();



    void on_calendarWidget_clicked(const QDate &date);



    void on_pushButton_clicked();

private:
    Ui::cutting *ui;
    QSqlDatabase m_db;
    void closeEvent(QCloseEvent *event);


};

#endif // CUTTING_H
