#ifndef PLANNING_H
#define PLANNING_H

#include <QWidget>
#include <designselect.h>

namespace Ui {
class Planning;
}

class Planning : public QWidget
{
    Q_OBJECT

public:
    explicit Planning(QWidget *parent = nullptr);
    ~Planning();

private slots:


    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Planning *ui;
    design_select *ds;
};

#endif // PLANNING_H
