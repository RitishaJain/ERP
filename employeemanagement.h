#ifndef EMPLOYEEMANAGEMENT_H
#define EMPLOYEEMANAGEMENT_H

#include <QWidget>
#include <addemployee.h>
#include <manageemp.h>
namespace Ui {
class EmployeeManagement;
}

class EmployeeManagement : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeeManagement(QWidget *parent = nullptr);
    ~EmployeeManagement();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::EmployeeManagement *ui;
    addemployee *ae;
    ManageEmp *me;
};

#endif // EMPLOYEEMANAGEMENT_H
