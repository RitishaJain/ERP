#include "type.h"
#include "ui_type.h"
#include "dash.h"


TYPE::TYPE(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TYPE)
{
    ui->setupUi(this);
}

TYPE::~TYPE()
{
    delete ui;
}

void TYPE::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void TYPE::on_pushButton_7_clicked()
{
    QWidget *qp = new ProManage;
    qp->show();
    this->close();
}

void TYPE::on_pushButton_clicked()
{
    cut=new cutting;
    cut->show();
    this->close();
}

void TYPE::on_pushButton_2_clicked()
{
    cutv=new cuttingv;
    cutv->show();
    this->close();
}
