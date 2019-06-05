#include "entrypoint.h"
#include "starthmmwindow.h"
#include "ui_entrypoint.h"
#include "QTimer"

EntryPoint::EntryPoint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EntryPoint)
{
    ui->setupUi(this);
}

EntryPoint::~EntryPoint()
{
    delete ui;
}

void EntryPoint::on_btnEntrance_clicked()
{
      QMessageBox *mess = new QMessageBox();

      this->ui->lineEditUserName->setText("admin");
      this->ui->lineEditPassword->setText("admin");

      QString userName = this->ui->lineEditUserName->text();
      QString password = this->ui->lineEditPassword->text();

      bool isAdmin;

      if (userName == "admin" && password == "admin")
      {
          isAdmin = true;
          showWindow(isAdmin, userName);
      }
      else if (userName == "ivanovama" && password == "mary3456")
      {
          isAdmin = false;
          showWindow(isAdmin, userName);
      }
      else
      {
          mess->setText("Неверное имя пользователя или неправильный пароль");
          mess->setIcon(QMessageBox::Critical);
          mess->show();
      }
}

void EntryPoint::showWindow(bool isAdmin, QString userName) {
    StartHMMWindow *sw = new StartHMMWindow;
    sw->setAdmin(isAdmin);
    sw->setName(userName);
    sw->setUserName(userName);
    sw->show();
    this->close();
}
