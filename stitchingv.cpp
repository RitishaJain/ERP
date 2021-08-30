#include "stitchingv.h"
#include "ui_stitchingv.h"
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

stitchingv::stitchingv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stitchingv)
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
    filltable();
}

stitchingv::~stitchingv()
{
    delete ui;
}

void stitchingv::filltable()
{
  /*QSqlTableModel * modal = new QSqlTableModel();
  QSqlQuery* qry = new QSqlQuery();
  qry->prepare("SELECT * FROM stich");
  qry->exec();
  QString n = "stiching";
  modal->setTable(n);
  modal->select();*/
  //ui->tableView->setModel(modal);
//ui->tableView->setModel(modal);
//qDebug() <<(modal->rowCount());

}

void stitchingv::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void stitchingv::on_pushButton_7_clicked()
{
    QWidget *qp = new typest;
    qp->show();
    this->close();
}

void stitchingv::on_comboBox_activated(const QString &arg1)
{
    QSqlTableModel * model = new QSqlTableModel();
        QString se = ui->comboBox->currentText();
        QString name = "stich_";
        name=name.append(se);
        model->setTable(name);
        model->select();
        ui->tableView->setModel(model);
        model->setEditStrategy(QSqlTableModel::OnFieldChange);
        model->submitAll();
}
