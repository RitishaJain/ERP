#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include <QSqlDatabase>
#include<QLineEdit>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
/*!
connOpen();
if(!mydb.open())
    QMessa    geBox::critical(
      this,
      tr("ERROR"),
      tr("Database Connection Failure") );

connClose();
*/
}
Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
//QSqlDatabase m_db;
//m_db = QSqlDatabase::addDatabase("QSQLITE");
//QString uname=qgetenv("USERNAME");
//m_db.setDatabaseName("C:/Users/"+uname+"/Documents/ERP_FINAL/Images/DB");

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
    QSqlQuery pcheck;
    QSqlQuery a ;
    a.exec("DROP TABLE admin");
    if(pcheck.exec("select * from login_users where username ='"+username +"' AND password = '" +password+"'"))
     {
        int count=0;
        while(pcheck.next())
        {
            count++;

        }
        if(count==1)
        {
            QSqlQuery z;
            z.exec("CREATE TABLE admin AS SELECT * FROM login_users WHERE username ='"+username+"'");
            dashb=new Dash;
            dashb->show();
            this->close();
        }
        else {
            QMessageBox::critical(
              this,
              tr("ERROR"),
              tr("Invalid Username/Password") );
        }

                 }

}



