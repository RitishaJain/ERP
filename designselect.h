#ifndef DESIGN_SELECT_H
#define DESIGN_SELECT_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class design_select;
}

class design_select : public QWidget
{
    Q_OBJECT

public:
    explicit design_select(QWidget *parent = nullptr);
    ~design_select();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_2_clicked();
    void display();
    void refresh();



    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::design_select *ui;

};

#endif // DESIGN_SELECT_H
