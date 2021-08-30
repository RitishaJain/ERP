#include "manageemp.h"
#include "ui_manageemp.h"
#include "dash.h"
#include<QMessageBox>
#include <QSqlDatabase>
#include<QLineEdit>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QtSql>
#include<QRegularExpression>
#include "employeemanagement.h"
ManageEmp::ManageEmp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageEmp)
{
    ui->setupUi(this);

    QSqlDatabase m_db;
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString uname=qgetenv("USERNAME");
    m_db.setDatabaseName("C:/Users/"+uname+"/Documents/ERP_FINAL/Images/DB");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
    filltable();
}

ManageEmp::~ManageEmp()
{
    delete ui;
}
void ManageEmp::filltable()
{
    int num_row, r, c;
    QSqlQuery empq(m_db);
    if(!empq.exec("SELECT count(id) as num_rows FROM emp_details")) qDebug() <<empq.lastError().text();
    empq.first();
    num_row = empq.value(0).toInt();
    ui->tableWidget->setRowCount(num_row);

    if(!empq.exec("SELECT id, Name, DOB, emailID, Mobile_no, salary, dep FROM emp_details ORDER BY id")) qDebug() <<empq.lastError().text();
    for(r=0, empq.first(); empq.isValid(); empq.next(), r++)
    {
        for(c=0; c<7; ++c)
        {
            ui->tableWidget->setItem(r,c, new QTableWidgetItem(empq.value(c).toString()));
        }

}
}

void ManageEmp::on_pushButton_7_clicked()
{
    QWidget *qp = new EmployeeManagement;
    qp->show();
    this->close();
}

void ManageEmp::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void ManageEmp::on_pushButton_2_clicked()
{
    QSqlQuery* query=new QSqlQuery();
    int cr;
    cr=ui->tableWidget->currentRow();
    QString str;
    QTableWidgetItem* itm = ui->tableWidget->item(cr,0);
    if (itm)
    str = itm->text();
    query->prepare("DELETE FROM emp_details WHERE id = '" + str + "'");
    query->exec();
    if (query->exec())
    {
        QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
        filltable();
    }
}


