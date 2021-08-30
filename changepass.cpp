#include "changepass.h"
#include "ui_changepass.h"
#include "dash.h"
#include "qmessagebox.h"

ChangePasS::ChangePasS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePasS)
{
    ui->setupUi(this);
}

ChangePasS::~ChangePasS()
{
    delete ui;
}

void ChangePasS::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void ChangePasS::on_pushButton_7_clicked()
{
    QWidget *qp = new AccountManagement;
    qp->show();
    this->close();
}

void ChangePasS::on_pushButton_clicked()
{
    QString username=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    QString newpass=ui->lineEdit_3->text();
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
               up.prepare("update login_users set password ='"+newpass+"'where username='"+username+"'");
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
                         tr("Could not update record") );
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



void ChangePasS::on_pushButton_2_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();
    }
}

