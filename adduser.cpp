#include "adduser.h"
#include "ui_adduser.h"
#include "login.h"
#include<QMessageBox>
#include <QSqlDatabase>
#include<QLineEdit>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QtSql>
#include<QRegularExpression>

adduser::adduser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adduser)
{
    ui->setupUi(this);
}

adduser::~adduser()
{
    delete ui;
}

void adduser::on_pushButton_clicked()
{
    QString username=ui->lineEdit->text();
    QString emailid=ui->lineEdit_2->text();
    QString phno=ui->lineEdit_3->text();
    QString upass=ui->lineEdit_4->text();
    QString upassc=ui->lineEdit_5->text();
    if (username.isEmpty() || emailid.isEmpty() || phno.isEmpty() || upass.isEmpty() || upassc.isEmpty())
    {
        QMessageBox::critical(
          this,
          tr("ERROR"),
          tr("One or more fields empty") );
    }
    else {
    QSqlDatabase localdb= QSqlDatabase::database();
    if (!localdb.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
    int val =0;
     int phv = 0;

        QRegularExpression regex("b[A-Za-z0-9._%+-]+@[a-zA-Z0-9.-]+.[a-zA-Z]{2,4}");

        if(!regex.match(emailid).hasMatch())
        {
            QMessageBox::critical(
              this,
              tr("ERROR"),
              tr("Invalid E-mail ID") );

             }
        else {
 val++;

        }
        for(int i=0;i<phno.size();i++)
        {
            if(phno[i].isDigit())

                phv=0;
                 else
                phv=1;
            }
        if(phv==1)
        {
            QMessageBox::critical(
              this,
              tr("ERROR"),
              tr("Invalid Mobile Number") );
        }
        else {
            val++;
        }
    if(val>0&&phv==0)
    {
     QSqlQuery ins;
    ins.prepare("INSERT INTO login_users(username,password,emailid,phno)" "VALUES(:username,:upass,:emailid,:phno)");
    ins.bindValue(":username",username);
               ins.bindValue(":upass",upass);
               ins.bindValue(":emailid",emailid);
               ins.bindValue(":phno",phno);
    ins.exec();
}
    }
}

void adduser::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void adduser::on_pushButton_7_clicked()
{
    QWidget *qp = new AccountManagement;
    qp->show();
    this->close();
}

void adduser::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();

}
