#include "cutting.h"
#include "ui_cutting.h"
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
QDate u;
cutting::cutting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cutting)
{
    ui->setupUi(this);
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

    QSqlQuery* qry = new QSqlQuery();
    QSqlQueryModel * modal = new QSqlQueryModel();
    qry->prepare("SELECT design_no FROM designs");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox->setModel(modal);
    qDebug() <<(modal->rowCount());

}

cutting::~cutting()
{
    delete ui;
}



void cutting::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void cutting::on_pushButton_7_clicked()
{
    QWidget *qp = new TYPE;
    qp->show();
    this->close();
}
 void cutting::closeEvent(QCloseEvent *event)
 {
      QMessageBox::StandardButton restbtn = QMessageBox::question(
       this,
       tr("Confirm"),
       tr("Are you sure?"),
                 QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                 QMessageBox::Yes);
      if (restbtn != QMessageBox::Yes) {
             event->ignore();
         } else {
          QSqlQuery dropp;
          dropp.prepare("DROP temp");
             event->accept();
         }
     }


 void cutting::on_pushButton_clicked()
 {     
       QString s = ui->comboBox->currentText();
       QString c ="cutting_";
       //QString st="stich_";
      // QString fi="finish_";
       c=c.append(s);
      // st=st.append(s);
      // fi=fi.append(s);
       QString h,h1,h2;
       QSqlQuery q,q1,q2;
       QDate qd=ui->calendarWidget->selectedDate();
       QString d = qd.toString();
       QString d2="\""+d+"\"";

       h="UPDATE "+c+" SET ("+d2+") =(SELECT "+d2+" FROM tempp WHERE "+c+".id = tempp.id)";
      // h1="UPDATE "+st+" SET ("+d2+") =(SELECT "+d2+" FROM tempp WHERE "+st+".id = tempp.id)";
       //h2="UPDATE "+fi+" SET ("+d2+") =(SELECT "+d2+" FROM tempp WHERE "+fi+".id = tempp.id)";
       q.exec(h);
       //q1.exec(h1);
       //q2.exec(h2);

 }

void cutting::on_calendarWidget_clicked(const QDate &date)
{   u=date;
    QString s = ui->comboBox->currentText();
    int n1=ui->comboBox->count();
    QDate t = QDate::currentDate();
    if(date==QDate::currentDate()||(date>=t.addDays(-7)&&date<=t))
    {
        QDate d= date;
        QString da = d.toString();
        QSqlQuery ins,no,e,e1,e2,n;
        QString a;
        for(int i=0;i<n1;i++)
        {
            QString temp1=ui->comboBox->itemText(i);
            QString c ="cutting_", s="stich_",fi="finish_";

            c = c.append(temp1);
           // s = s.append(temp1);
            //fi = fi.append(temp1);

            e.exec("ALTER TABLE '"+c+"' ADD COLUMN '"+da+"' INTEGER DEFAULT NULL");
            //e1.exec("ALTER TABLE '"+s+"' ADD COLUMN '"+da+"' INTEGER DEFAULT NULL");
            //e2.exec("ALTER TABLE '"+fi+"' ADD COLUMN '"+da+"' INTEGER DEFAULT NULL");
        }
        //ins.exec("ALTER TABLE attendance ADD COLUMN '"+da+"'BOOLEAN DEFAULT P ");
       // n.exec("DROP TABLE t");
        //no.exec("CREATE TABLE t AS SELECT design_no FROM designs WHERE date_completed IS NULL");



    }
    else{
        QMessageBox::critical(
          this,
          tr("ERROR"),
          tr("Date out of bounds") );
    }
    QSqlQuery dropp;
    dropp.prepare("DROP TABLE tempp");
    dropp.exec();
    QString d = date.toString();
    QString d2="\""+d+"\"";

QSqlQuery n,q;
QString ti = "cutting_";
QString tem = ti.append(s);
n.prepare("CREATE TABLE tempp AS SELECT id,name,"+d2+" FROM "+tem+" WHERE id IN (SELECT id FROM attendance WHERE "+d2+" = 'P')") ;
//n2.prepare("CREATE TABLE cutting AS SELECT * FROM emp_details WHERE dep is 'Cutting'");
n.exec();
QSqlTableModel * model = new QSqlTableModel();
model->setTable("tempp");
model->select();
ui->tableView->setModel(model);
model->setEditStrategy(QSqlTableModel::OnFieldChange);
model->submitAll();

//q.exec("UPDATE cutting_rgr SET '"+d2+"' =(SELECT '"+d2+"' FROM tempp WHERE cutting_rgr.id = tempp.id)");
}

/*void cutting::on_pushButton_2_clicked()
{
ui->lineEdit->setText("fsdfd");
    QString s = ui->comboBox->currentText();
    QString c ="cutting_";
    c=c.append(s);
    QSqlQuery q;
    QDate qd=ui->calendarWidget->selectedDate();
    QString d = qd.toString();
    QString d2="\"Sun Mar 24 2019\"";
    ui->lineEdit->setText("fsdfd");
    //q.exec("UPDATE cutting_rgr SET (Sun Mar 24 2019) =(SELECT Sun Mar 24 2019 FROM tempp WHERE cutting_rgr.id = tempp.id)");
    QString h="UPDATE cutting_rgr SET (Sun Mar 24 2019) =(SELECT (Sun Mar 24 2019 FROM tempp WHERE cutting_rgr.id = tempp.id)";
    q.exec(h);

}*/


