#include "dash.h"
#include "ui_dash.h"
#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include <QSqlDatabase>
#include<QLineEdit>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QtSql>
#include<QRegularExpression>



Dash::Dash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dash)
{
    ui->setupUi(this);
    QSqlDatabase localdb= QSqlDatabase::database();

    if (!localdb.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
    QSqlQuery query("SELECT Count(*) FROM emp_details");
    query.first();
    int no = query.value(0).toInt();
    QString n = QString::number(no);
    ui->label_6->setStyleSheet("qproperty-alignment: AlignCenter;""font: 75 18pt MS Shell Dlg 2;""color: rgb(255, 255, 255);");
    ui->label_6->setText(n);
    QDate d= QDate::currentDate();
    QString d1=d.toString();
    QString d2="\""+d1+"\"";
    QSqlQuery query1("SELECT Count(*) FROM attendance WHERE "+d2+" = 'P'");
//    query1.addBindValue(d1);
//    query1.addBindValue("\"");
    query1.first();
    int no1 = query1.value(0).toInt();
    QString n1 = QString::number(no1);
    ui->label_7->setStyleSheet("qproperty-alignment: AlignCenter;""font: 75 18pt MS Shell Dlg 2;""color: rgb(255, 255, 255);");
    ui->label_7->setText(n1);
    QSqlQuery query2("SELECT Count(*) FROM designs");
    query2.first();
    int no2 = query2.value(0).toInt();
    QString n2 = QString::number(no2);
    ui->label_9->setStyleSheet("qproperty-alignment: AlignCenter;""font: 75 18pt MS Shell Dlg 2;""color: rgb(255, 255, 255);");
    ui->label_9->setText(n2);
    QSqlQuery query3("SELECT Count(*) FROM designs WHERE date_completed IS NOT NULL");
    query3.first();
    int no3 = query3.value(0).toInt();
    QString n3 = QString::number(no3);
    ui->label_8->setStyleSheet("qproperty-alignment: AlignCenter;""font: 75 18pt MS Shell Dlg 2;""color: rgb(255, 255, 255);");
    ui->label_8->setText(n3);
}

Dash::~Dash()
{
    delete ui;
}


void Dash::on_pushButton_clicked()
{
    memp=new EmployeeManagement;
    memp->show();
    this->hide();
}

void Dash::on_pushButton_2_clicked()
{
    pmg=new ProManage;
    pmg->show();
    this->close();
}

void Dash::on_pushButton_3_clicked()
{
    ds=new design_select;
    ds->show();
    this->close();
}

void Dash::on_pushButton_4_clicked()
{
    acmng=new AccountManagement;
    acmng->show();
    this->close();
}



void Dash::on_pushButton_5_clicked()
{
       QWidget *login  = new Login;
       login->show();
       this->close();
}

void Dash::on_pushButton_6_clicked()
{
    atd=new attendance;
    atd->show();
    this->close();
}


