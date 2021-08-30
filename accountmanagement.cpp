#include "accountmanagement.h"
#include "ui_accountmanagement.h"
#include "dash.h"

AccountManagement::AccountManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountManagement)
{
    ui->setupUi(this);
     ui->pushButton_2->hide();
    QSqlQuery c;
    if(c.exec("select * from admin where access = 1"))
    {
       int count=0;
       while(c.next())
       {
           count++;

       }
       if(count==1)
       {
           ui->pushButton_2->show();
       }
}
}
AccountManagement::~AccountManagement()
{
    delete ui;
}

void AccountManagement::on_pushButton_2_clicked()
{
    au=new adduser;
    au->show();
    this->close();
}

void AccountManagement::on_pushButton_3_clicked()
{
    cu=new ChangeUserName;
    cu->show();
    this->close();
}

void AccountManagement::on_pushButton_4_clicked()
{
    cph=new CHANGEPHONE;
    cph->show();
    this->close();
}

void AccountManagement::on_pushButton_6_clicked()
{
    cm=new ChangeMail;
    cm->show();
    this->close();
}

void AccountManagement::on_pushButton_7_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void AccountManagement::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}


void AccountManagement::on_pushButton_5_clicked()
{
    cp=new ChangePasS;
    cp->show();
    this->close();
}
