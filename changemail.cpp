#include "changemail.h"
#include "ui_changemail.h"
#include "dash.h"
#include "qmessagebox.h"

ChangeMail::ChangeMail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeMail)
{
    ui->setupUi(this);
}

ChangeMail::~ChangeMail()
{
    delete ui;
}

void ChangeMail::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void ChangeMail::on_pushButton_7_clicked()
{
    QWidget *qp = new AccountManagement;
    qp->show();
    this->close();
}

void ChangeMail::on_pushButton_2_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();}
}

void ChangeMail::on_pushButton_clicked()
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
        QString password=ui->lineEdit_2->text();
        QString newemail=ui->lineEdit_3->text();
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
                   up.prepare("update login_users set emailid ='"+newemail+"'where username='"+username+"'");
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

