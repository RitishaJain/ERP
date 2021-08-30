#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>

namespace Ui {
class WELCOME;
}

class WELCOME : public QWidget
{
    Q_OBJECT

public:
    explicit WELCOME(QWidget *parent = nullptr);
    ~WELCOME();

private:
    Ui::WELCOME *ui;
};

#endif // WELCOME_H
