#include "changephone.h"
#include "ui_changephone.h"
#include "dash.h"
#include "qmessagebox.h"
CHANGEPHONE::CHANGEPHONE(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CHANGEPHONE)
{
    ui->setupUi(this);
}

CHANGEPHONE::~CHANGEPHONE()
{
    delete ui;
}

void CHANGEPHONE::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void CHANGEPHONE::on_pushButton_7_clicked()
{
    QWidget *qp = new AccountManagement;
    qp->show();
    this->close();
}

void CHANGEPHONE::on_pushButton_2_clicked()
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
        QString newph=ui->lineEdit_3->text();
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
                   up.prepare("update login_users set phno='"+newph+"'where username='"+username+"'");
                   if(up.exec())
                   {
                       QMessageBox::information(
                         this,
                         tr("Success"),
                         tr("Number Updated!!") );
                       foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
                           widget->clear();
                   }
                   }
                       else
                           {
                           QMessageBox::critical(
                             this,
                             tr("ERROR"),
                             tr("Could not update") );
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


void CHANGEPHONE::on_pushButton_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();}
}
