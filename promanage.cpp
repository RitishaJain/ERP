#include "promanage.h"
#include "ui_promanage.h"
#include "dash.h"

ProManage::ProManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProManage)
{
    ui->setupUi(this);
}

ProManage::~ProManage()
{
    delete ui;
}

void ProManage::on_pushButton_3_clicked()
{
    tp=new TYPE;
    tp->show();
    this->close();
}

void ProManage::on_pushButton_clicked()
{
    tps=new typest;
    tps->show();
    this->close();
}

void ProManage::on_pushButton_2_clicked()
{
    tpf=new typefin;
    tpf->show();
    this->close();
}

void ProManage::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void ProManage::on_pushButton_7_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}
