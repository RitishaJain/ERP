#include "welcome.h"
#include "ui_welcome.h"

WELCOME::WELCOME(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WELCOME)
{
    ui->setupUi(this);
}

WELCOME::~WELCOME()
{
    delete ui;
}
