#ifndef CUTTINGV_H
#define CUTTINGV_H

#include <QWidget>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>

namespace Ui {
class cuttingv;
}

class cuttingv : public QWidget
{
    Q_OBJECT

public:
    explicit cuttingv(QWidget *parent = nullptr);
    ~cuttingv();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::cuttingv *ui;
    QSqlDatabase m_db;
    void filltable();
};

#endif // CUTTINGV_H
