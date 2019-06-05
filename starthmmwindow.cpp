#include "adminwindow.h"
#include "waitingforresults.h"
#include "entrypoint.h"

#include "starthmmwindow.h"
#include "ui_starthmmwindow.h"

StartHMMWindow::StartHMMWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartHMMWindow)
{
    ui->setupUi(this);
    ui->radioAuto->setChecked(true);
    ui->groupBoxForExisting->setEnabled(false);
    setUserIcon();
}

StartHMMWindow::~StartHMMWindow()
{
    delete ui;
}

void StartHMMWindow::setAdmin(bool isAdmin) {
    this->isAdmin = isAdmin;
}

void StartHMMWindow::setName(QString name) {
    this->name = name;
}

void StartHMMWindow::setUserIcon() {
    ui->labelUserPic->setPixmap(QPixmap(QString("C:\\QtProjects\\HMM\\images\\user.png")));
}

void StartHMMWindow::setUserName(QString name) {
    ui->labelUserName->setText(name);
}

void StartHMMWindow::on_radioAuto_clicked()
{
    ui->groupBoxForExisting->setEnabled(false);
}

void StartHMMWindow::on_radioExists_clicked()
{
    ui->groupBoxForExisting->setEnabled(true);
}

void StartHMMWindow::on_loadTextButton_clicked()
{
    QFileDialog *fd = new QFileDialog();
    QString fileName = fd->getOpenFileName();
    ui->textFileEdit->setText(fileName);
}

void StartHMMWindow::on_chooseModelButton_clicked()
{
    QFileDialog *fd = new QFileDialog();
    QString fileName = fd->getOpenFileName();
    ui->modelEdit->setText(fileName);
}

bool StartHMMWindow::readyToWork() {
    return !ui->textFileEdit->text().isEmpty();
}

void StartHMMWindow::on_workButton_clicked()
{
    if (readyToWork())
        if (isAdmin)
           initAdminMode();
        else
            initUserMode();
    else {
        QMessageBox *mess = new QMessageBox();
        mess->setWindowTitle("Ошибка");
        mess->setIcon(QMessageBox::Critical);
        mess->setText("Необходимо выбрать текстовый файл.");
        mess->show();
    }
}

void StartHMMWindow::waitForResults() {

}

void StartHMMWindow::initAdminMode() {
    //waitForResults();

    //WaitingForResults *wr = new WaitingForResults();
    //wr->show();

    AdminWindow *aw = new AdminWindow();
    aw->show();
    this->close();
}

void StartHMMWindow::initUserMode() {

}

void StartHMMWindow::on_exitButton_clicked()
{
    this->destroy();
}

void StartHMMWindow::on_changeUserButton_clicked()
{
    EntryPoint epw;
    this->destroy();
    epw.show();
    epw.exec();
}
