#include "typefin.h"
#include "ui_typefin.h"
#include "dash.h"

typefin::typefin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::typefin)
{
    ui->setupUi(this);
}

typefin::~typefin()
{
    delete ui;
}

void typefin::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void typefin::on_pushButton_7_clicked()
{
    QWidget *qp = new ProManage;
    qp->show();
    this->close();
}

void typefin::on_pushButton_clicked()
{
    fin=new finishing;
    fin->show();
    this->close();
}

void typefin::on_pushButton_2_clicked()
{
    finv=new finishingv;
    finv->show();
    this->close();
}
