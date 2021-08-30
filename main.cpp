#include "welcome.h"
#include "login.h"
#include <QSqlDatabase>
#include<QLineEdit>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QApplication>



void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 500);
}

int main(int argc, char *argv[])
{
    QSqlDatabase m_db;
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    QString uname=qgetenv("USERNAME");
    m_db.setDatabaseName("C:/Users/"+uname+"/Documents/ERP_FINAL/Images/DB");
    QApplication a(argc, argv);
    WELCOME we;
    we.show();
    delay();
    QThread::msleep(2000);
    we.hide();
    Login w;
    w.show();

    return a.exec();
}
