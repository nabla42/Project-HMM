#ifndef CHOOSE_USER_H
#define CHOOSE_USER_H

#include <QDialog>

namespace Ui {
class Choose_User;
}

class Choose_User : public QDialog
{
    Q_OBJECT

public:
    explicit Choose_User(QWidget *parent = nullptr);
    ~Choose_User();

private:
    Ui::Choose_User *ui;
};

#endif // CHOOSE_USER_H
