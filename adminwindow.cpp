#include "entrypoint.h"
#include "starthmmwindow.h"
#include "tabpage.h"

#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    hideBackground();
    setUserIconAndName();
    setButtonsIcons();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::setUserIconAndName() {
    ui->labelUserPic->setPixmap(QPixmap(QString("C:\\QtProjects\\HMM\\images\\user.png")));
    ui->labelUserName->setText(name);
}

void AdminWindow::setButtonsIcons() {
    ui->loadModelButton->setIcon(QIcon(QString("C:\\QtProjects\\HMM\\images\\open.png")));
    ui->saveModelButton->setIcon(QIcon(QString("C:\\QtProjects\\HMM\\images\\save.png")));
    ui->deleteModelButton->setIcon(QIcon(QString("C:\\QtProjects\\HMM\\images\\delete.png")));
    ui->toStartMenuButton->setIcon(QIcon(QString("C:\\QtProjects\\HMM\\images\\home.png")));
}

void AdminWindow::hideBackground() {
    ui->noModelsIconLabel->setHidden(true);
    ui->noModelsLabel->setHidden(true);
}

void AdminWindow::showBackground() {
    ui->noModelsIconLabel->setHidden(false);
    ui->noModelsLabel->setHidden(false);
    ui->noModelsIconLabel->setPixmap(QPixmap(QString("C:\\QtProjects\\HMM\\images\\no_loaded_models.png")));
}

void AdminWindow::on_changeUserButton_clicked()
{
    EntryPoint epw;
    this->destroy();
    epw.show();
    epw.exec();
}

void AdminWindow::on_exitButton_clicked()
{
    this->destroy();
}

void AdminWindow::on_toStartMenuButton_clicked()
{
    StartHMMWindow *sw = new StartHMMWindow();
    sw->setAdmin(isAdmin);
    sw->setName(name);
    sw->setUserName(name);
    sw->show();
    this->destroy();
}

void AdminWindow::on_loadModelButton_clicked()
{
    QFileDialog *fd = new QFileDialog();
    QString modelName = "from_file"; //fd->getOpenFileName();
    if (ui->tabModelsWidget->isHidden()) {
        ui->tabModelsWidget->setTabText(0, modelName);
        ui->tabModelsWidget->setHidden(false);
        hideBackground();
    }
    else
        addModelTab(modelName);
    //loadModelData();
}

void AdminWindow::addModelTab(QString modelName) {
    TabPage *newModelTab = new TabPage();
    //QTabWidget *newModelTab = new QTabWidget();
    //newModelTab->addTab(new QWidget(), "Статистика");
    //newModelTab->addTab(new QWidget(), "Текст с ошибками");
    //newModelTab->addTab(new QWidget(), "Исправленный текст");
    //newModelTab->addTab(new QWidget(), "Список исправленных слов");
    //newModelTab->addTab(new QWidget(), "Граф");
    ui->tabModelsWidget->addTab(newModelTab, modelName);
}

void AdminWindow::on_tabModelsWidget_tabCloseRequested(int index)
{
    int tabsCount = ui->tabModelsWidget->count();
    if (tabsCount > 1)
        removeTab(index);
    else {
        ui->tabModelsWidget->setTabText(index, "New*");
        ui->tabModelsWidget->setHidden(true);
        showBackground();
    }
}

void AdminWindow::removeTab(int index) {
    ui->tabModelsWidget->removeTab(index);
}

void AdminWindow::clearTab(int index) {

}

void AdminWindow::loadModelData(int index) {

}

void AdminWindow::on_menuButton_clicked()
{
    //QMenu btnMenu = new QMenu();
    //btnMen
}
