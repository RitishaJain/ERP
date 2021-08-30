#include "attendance.h"
#include "ui_attendance.h"
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
#include<QtWidgets>

attendance::attendance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::attendance)
{
    ui->setupUi(this);

    /*QTableWidgetItem *checkBoxItem = new QTableWidgetItem();
    checkBoxItem->setCheckState(Qt::Unchecked);   */
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
    QSqlTableModel * model = new QSqlTableModel();
    model->setTable("attendance");
    QSqlTableModel * model1 = new QSqlTableModel();
    model1->setTable("attendance");
    model1->select();
    ui->tableView->setModel(model1);
    model1->setEditStrategy(QSqlTableModel::OnFieldChange);
    model1->submitAll();
   /* for(int i=0;i<5;i++)
    {
    int row=ui->table->columnCount();
    ui->table->insertColumn(row);
    QTableWidgetItem *item = new QTableWidgetItem();
    item->data(Qt::CheckStateRole);
    ui->table->insertRow(row);
    item->setCheckState(Qt::Unchecked);
    ui->table->setItem(i,1,item);
*/

}




attendance::~attendance()
{
    delete ui;
}
void attendance::filltable()
{
    QSqlTableModel * model1 = new QSqlTableModel();
    model1->setTable("attendance");
    model1->select();
    ui->tableView->setModel(model1);
    model1->setEditStrategy(QSqlTableModel::OnFieldChange);
    model1->submitAll();    
}

void attendance::refresh()
{
    QSqlTableModel * model2 = new QSqlTableModel();
    model2->setTable("attendance");
    model2->select();
    ui->tableView->setModel(model2);
}


void attendance::on_pushButton_clicked()
{

   QSqlQueryModel *modal ;
   modal = new QSqlQueryModel(this);
   modal->setQuery(QString("SELECT * FROM login_users"), m_db);
    /*!QSqlQuery get ;
    get.exec("SELECT * FROM login_users");
    */
   /*!
    ui->tableWidget->s(modal);
    ui->tableWidget->show();
    */
    m_db.close();



}

void attendance::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void attendance::on_pushButton_7_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}



void attendance::on_calendarWidget_clicked(const QDate &date)
{
    QDate t = QDate::currentDate();
    if(date==QDate::currentDate()||(date>=t.addDays(-7)&&date<=t))
    {
        QDate d= date;
        QString da = d.toString();
        QSqlQuery ins,no,e,e1,e2,n;
        ins.exec("ALTER TABLE attendance ADD COLUMN '"+da+"'BOOLEAN DEFAULT P ");
       // n.exec("DROP TABLE t");
        //no.exec("CREATE TABLE t AS SELECT design_no FROM designs WHERE date_completed IS NULL");
      filltable();

    }
    else{
        QMessageBox::critical(
          this,
          tr("ERROR"),
          tr("Date out of bounds") );
    }
}


void attendance::on_tableView_doubleClicked(const QModelIndex &index)
{
     refresh();
}
