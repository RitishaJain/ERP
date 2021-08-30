#include "designselect.h"
#include "ui_designselect.h"
#include "dash.h"
#include<QMessageBox>
#include <QSqlDatabase>
#include<QLineEdit>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QtSql>
#include <QComboBox>

design_select::design_select(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::design_select)
{
    ui->setupUi(this);
    ui->pushButton_2->hide();
    QSqlDatabase m_db;
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
 display();
 refresh();
}
void design_select::display()
{
    QSqlTableModel * model = new QSqlTableModel();
    model->setTable("designs");
    model->select();
    ui->tableView->setModel(model);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->submitAll();
}
void design_select::refresh()
{
    QSqlQuery* qry = new QSqlQuery();
    QSqlQueryModel * modal = new QSqlQueryModel();
    qry->prepare("SELECT design_no FROM designs");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox->setModel(modal);
    qDebug() <<(modal->rowCount());
}
design_select::~design_select()
{
    delete ui;
}

void design_select::on_pushButton_clicked()
{
    QString c_name = ui->lineEdit->text();
    QString dno = ui->lineEdit_2->text();
    QDate cd = QDate::currentDate();
    QSqlQuery ch, commit;
    commit.prepare("INSERT INTO designs(client,design_no,date_created)" "VALUES(:c_name,:dno,:cd)");
    commit.bindValue(":c_name",c_name);
    commit.bindValue(":dno",dno);
    commit.bindValue(":cd",cd);
    QSqlQuery pcheck;
    if(pcheck.exec("select * from designs where design_no ='"+dno +"'"))
     {
        int count=0;
        while(pcheck.next())
        {
            count++;

        }
        if(count==1)
        {
            QMessageBox::critical(
              this,
              tr("ERROR"),
              tr("Design Already Exists") );
        }
        else {
            if(commit.exec())
            {
                QMessageBox::information(
                  this,
                  tr("Successful"),
                  tr("Design Added") );
                QString cn = "cutting_";
                cn.append(dno);
                QString sn = "stich_";
                sn.append(dno);
                QString fn = "finish_";
                fn.append(dno);
                QSqlQuery c,s,f;
                c.exec("CREATE TABLE '"+cn+"'  AS SELECT id,Name FROM cutting" );
                s.exec("CREATE TABLE '"+sn+"'  AS SELECT id,Name FROM stiching" );
                f.exec("CREATE TABLE '"+fn+"'  AS SELECT id,Name FROM finishing" );
                display();
                refresh();
            }
            else {
                QMessageBox::critical(
                  this,
                  tr("ERROR"),
                  tr("Design could not be added") );
            }
        }

                 }



}



void design_select::on_pushButton_2_clicked()
{
    QString cur = ui->comboBox->currentText();

    QSqlQuery qry;
    QDate d = QDate::currentDate();
    QString date = d.toString();
    if(ui->pushButton_2->text()=="Close Design")
    {

        qry.prepare("UPDATE designs SET date_completed='"+date+"'WHERE design_no='"+cur+"'");
        qry.bindValue(":d",d);
        qry.exec();
        display();
        refresh();
    }
    else if(ui->pushButton_2->text()=="Reopen Design") {
        qry.prepare("UPDATE designs SET date_completed=NULL WHERE design_no='"+cur+"'");
        qry.exec();
        display();
        refresh();
    }


}

void design_select::on_comboBox_activated(const QString &arg1)
{
    QSqlQuery pcheck;
display();
    QString f="Close Design", c="Reopen Design";
    int count =0;
  QString curr = ui->comboBox->currentText();
  if(pcheck.exec("SELECT * FROM designs WHERE design_no ='"+curr +"' AND date_completed IS NULL "))
   {


      while(pcheck.next())
      {
          count++;

      }

}
  QString t = QString::number(count);

ui->pushButton_2->show();
  if(count==1){
display();
      ui->label_3->setText("OnGoing");
      ui->pushButton_2->setText(f);

  }
  else
  {
    ui->label_3->setText("Complete");
      ui->pushButton_2->setText(c);
display();
}
}

void design_select::on_pushButton_7_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void design_select::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}
