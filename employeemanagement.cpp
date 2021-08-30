#include "employeemanagement.h"
#include "ui_employeemanagement.h"
#include "login.h"

EmployeeManagement::EmployeeManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeManagement)
{
    ui->setupUi(this);
}

EmployeeManagement::~EmployeeManagement()
{
    delete ui;
}

void EmployeeManagement::on_pushButton_2_clicked()
{
    ae=new addemployee;
    ae->show();
    this->close();
}

void EmployeeManagement::on_pushButton_clicked()
{
    me=new ManageEmp;
    me->show();
    this->close();
}

void EmployeeManagement::on_pushButton_7_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void EmployeeManagement::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}
