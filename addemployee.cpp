#include "addemployee.h"
#include "ui_addemployee.h"
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
#include <employeemanagement.h>

addemployee::addemployee(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addemployee)
{
    ui->setupUi(this);
    ui->comboBox->hide();

}

addemployee::~addemployee()
{
    delete ui;
}

void addemployee::on_pushButton_clicked()
{
    QString ename = ui->lineEdit->text();
    QString emid = ui->lineEdit_3->text();
    QDate dob = ui->dateEdit->date();
    QString eid = ui->lineEdit_2->text();
    QString phno = ui->lineEdit_4->text();
    QString salary = ui->lineEdit_5->text();
    QString dep="";
    if(ui->radioButton->isChecked())
    dep="Cutting";
    if(ui->radioButton_3->isChecked())
    dep="Stitching";
    if(ui->radioButton_2->isChecked())
    dep="Finishing";
    if (ename.isEmpty() || dob.isNull() || eid.isEmpty() || phno.isEmpty() || salary.isEmpty() || dep.isEmpty())
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
QString dep;
if(ui->radioButton->isChecked())
    dep="Cutting";
else if(ui->radioButton_2->isChecked())
    dep="Finishing";
else if(ui->radioButton_3->isChecked())
    dep="Stiching";

int val=0, phv=0;

QRegularExpression regex("\\b[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,4}\\b");

if(!regex.match(eid).hasMatch())
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
else { if(phno>999999999)
    val++;
}
if(val>0 && phv==0)
{
QSqlQuery in;
in.prepare("INSERT INTO attendance (id,Name,dept)" "VALUES(:emid,:ename,:dep)");
in.bindValue(":emid",emid);
in.bindValue(":ename",ename);
in.bindValue(":dep",dep);
in.exec();
QSqlQuery ins;
ins.prepare("INSERT INTO emp_details(id,Name,DOB,emailID,Mobile_no,salary,dep)" "VALUES(:emid,:ename,:dob,:eid,:phno,:salary,:dep)");
ins.bindValue(":emid",emid);
ins.bindValue(":ename",ename);
ins.bindValue(":dob",dob);
           ins.bindValue(":eid",eid);
           ins.bindValue(":phno",phno);
           ins.bindValue(":salary",salary);
           ins.bindValue(":dep",dep);

   if(ins.exec())
{
    QMessageBox::information(
      this,
      tr("Success"),
      tr("Record Added!!") );
//    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
//        widget->clear();
//    }
    QSqlQuery d1,d2,d3,u1,u2,u3;
    d1.prepare("DROP TABLE stiching");
        d2.prepare("DROP TABLE cutting");
            d3.prepare("DROP TABLE finishing");
    d1.exec();
    d2.exec();
    d3.exec();
    u1.prepare("CREATE TABLE stiching AS SELECT * FROM emp_details WHERE dep is 'Stiching'");

    u2.prepare("CREATE TABLE cutting AS SELECT * FROM emp_details WHERE dep is 'Cutting'");

    u3.prepare("CREATE TABLE finishing AS SELECT * FROM emp_details WHERE dep is 'Finishing'");
    QSqlQuery* qry = new QSqlQuery();
        QSqlQueryModel * modal = new QSqlQueryModel();
        qry->prepare("SELECT design_no FROM designs");
        qry->exec();
        modal->setQuery(*qry);
        ui->comboBox->setModel(modal);
        qDebug() <<(modal->rowCount());
        int c = ui->comboBox->count();
        for(int i =0;i<c;i++)
        {
            QString a = ui->comboBox->itemText(i);
            QString cu="cutting_",fi="finish_",st="stich_";
            cu=cu.append(a);
            fi=fi.append(a);
            st=st.append(a);
            QSqlQuery r,t,y;
            if(dep=="Cutting")
            {
            r.prepare("INSERT INTO '"+cu+"' (id,Name)" "VALUES (:emid,:ename)");
            r.bindValue(":emid",emid);
                    r.bindValue(":ename",ename);
                    r.exec();
            }
             if(dep=="Finishing")
             {
                    t.prepare("INSERT INTO '"+fi+"' (id,Name)" "VALUES (:emid,:ename)");
                    t.bindValue(":emid",emid);
                            t.bindValue(":ename",ename);
                            t.exec();
             }
                if(dep=="Stiching")
                {
                            y.prepare("INSERT INTO '"+st+"' (id,Name)" "VALUES (:emid,:ename)");
                            y.bindValue(":emid",emid);
                                    y.bindValue(":ename",ename);
                                    y.exec();
                }


        }

    u1.exec();
    u2.exec();
   u3.exec();

}

else {
    QMessageBox::critical(
      this,
      tr("ERROR"),
      tr("Could not save record.Check ID") );

}
}
foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
    widget->clear();

}
}
}










void addemployee::on_pushButton_7_clicked()
{
    QWidget *qp = new EmployeeManagement;
    qp->show();
    this->close();
}

void addemployee::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}


void addemployee::on_pushButton_2_clicked()
{
    foreach(QLineEdit *widget, this->findChildren<QLineEdit*>()) {
        widget->clear();

    }
}
