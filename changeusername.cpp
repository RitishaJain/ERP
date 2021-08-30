#include "changeusername.h"
#include "ui_changeusername.h"
#include "dash.h"
#include "QMessageBox"

ChangeUserName::ChangeUserName(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeUserName)
{
    ui->setupUi(this);
}

ChangeUserName::~ChangeUserName()
{
    delete ui;
}

void ChangeUserName::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void ChangeUserName::on_pushButton_7_clicked()
{
    QWidget *qp = new AccountManagement;
    qp->show();
    this->close();
}

void ChangeUserName::on_pushButton_clicked()
{
    QSqlDatabase localdb= QSqlDatabase::database();

    if (!localdb.open())
    {
        qDebug() << "Error: connection with database fail";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
        QString username=ui->lineEdit->text();
        QString password=ui->lineEdit_3->text();
        QString newuser=ui->lineEdit_2->text();
        QSqlQuery pch;
        if(pch.exec("select * from login_users where username ='"+username +"' AND password = '" +password+"'"))
        {
            {
               int count=0;
               while(pch.next())
               {
                   count++;

               }
               if(count==1)
               {
                   QSqlQuery up;
                   up.prepare("update login_users set username='"+newuser+"'where username='"+username+"'");
                   if(up.exec())
                   {
                       QMessageBox::information(
                         this,
                         tr("Success"),
                         tr("Record Added!!") );
                       foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                           widget->clear();
                   }
                   }
                       else
                           {
                           QMessageBox::critical(
                             this,
                             tr("ERROR"),
                             tr("Could not save record") );
                       }
               }
               else {
                   QMessageBox::critical(
                     this,
                     tr("ERROR"),
                     tr("Invalid Username/Password") );
               }


        }
}
}

void ChangeUserName::on_pushButton_2_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();}
}
