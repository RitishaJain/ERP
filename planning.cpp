#include "planning.h"
#include "ui_planning.h"
#include "dash.h"


Planning::Planning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Planning)
{
    ui->setupUi(this);
}

Planning::~Planning()
{
    delete ui;
}



void Planning::on_pushButton_8_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}

void Planning::on_pushButton_7_clicked()
{
    QWidget *qp = new Dash;
    qp->show();
    this->close();
}


void Planning::on_pushButton_clicked()
{

}

void Planning::on_pushButton_2_clicked()
{
    ds=new design_select;
    ds->show();
    this->close();
}
