#include "typest.h"
#include "ui_typest.h"
#include "dash.h"

typest::typest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::typest)
{
    ui->setupUi(this);
}

typest::~typest()
{
    delete ui;
}

void typest::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void typest::on_pushButton_7_clicked()
{
    QWidget *qp = new ProManage;
    qp->show();
    this->close();
}

void typest::on_pushButton_clicked()
{
    st=new stitching;
    st->show();
    this->close();
}

void typest::on_pushButton_2_clicked()
{
    stv=new stitchingv;
    stv->show();
    this->close();
}
