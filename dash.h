#ifndef DASH_H
#define DASH_H

#include <QWidget>

#include <promanage.h>
#include <planning.h>
#include <accountmanagement.h>
#include <attendance.h>
#include <employeemanagement.h>
#include <designselect.h>


namespace Ui {
class Dash;
}

class Dash : public QWidget
{
    Q_OBJECT

public:
    explicit Dash(QWidget *parent = nullptr);
    ~Dash();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_label_6_linkActivated(const QString &link);

private:
    Ui::Dash *ui;   
    ProManage *pmg;
    Planning *plng;
    AccountManagement *acmng;
    attendance *atd;
    EmployeeManagement *memp;
    QSqlDatabase m_db;
    design_select *ds;


};

#endif // DASH_H
