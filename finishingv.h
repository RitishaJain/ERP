#ifndef FINISHINGV_H
#define FINISHINGV_H

#include <QWidget>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>

namespace Ui {
class finishingv;
}

class finishingv : public QWidget
{
    Q_OBJECT

public:
    explicit finishingv(QWidget *parent = nullptr);
    ~finishingv();

private slots:
    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::finishingv *ui;
    QSqlDatabase m_db;
    void filltable();
};

#endif // FINISHINGV_H
