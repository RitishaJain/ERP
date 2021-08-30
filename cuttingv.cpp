#include "cuttingv.h"
#include "ui_cuttingv.h"
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

cuttingv::cuttingv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cuttingv)
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

cuttingv::~cuttingv()
{
    delete ui;
}

void cuttingv::filltable()
{

}

void cuttingv::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void cuttingv::on_pushButton_7_clicked()
{
    QWidget *qp = new TYPE;
    qp->show();
    this->close();
}

void cuttingv::on_comboBox_activated(const QString &arg1)
{    QSqlTableModel * model = new QSqlTableModel();
     QString se = ui->comboBox->currentText();
     QString name = "cutting_";
     name=name.append(se);
     model->setTable(name);
     model->select();
     ui->tableView->setModel(model);
     model->setEditStrategy(QSqlTableModel::OnFieldChange);
     model->submitAll();
}
