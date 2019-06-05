#include "choose_user.h"
#include "ui_choose_user.h"

Choose_User::Choose_User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choose_User)
{
    ui->setupUi(this);
}

Choose_User::~Choose_User()
{
    delete ui;
}

