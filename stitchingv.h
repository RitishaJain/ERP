#ifndef STITCHINGV_H
#define STITCHINGV_H

#include <QWidget>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>
#include <QTableView>
#include <QKeyEvent>
namespace Ui {
class stitchingv;
}

class stitchingv : public QWidget
{
    Q_OBJECT

public:
    explicit stitchingv(QWidget *parent = nullptr);
    ~stitchingv();
    void filltable();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();


    void on_comboBox_activated(const QString &arg1);

private:
    Ui::stitchingv *ui;
    QSqlDatabase m_db;



};

#endif // STITCHINGV_H
