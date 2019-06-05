#include "waitingforresults.h"
#include "ui_waitingforresults.h"

WaitingForResults::WaitingForResults(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WaitingForResults)
{
    ui->setupUi(this);
}

WaitingForResults::~WaitingForResults()
{
    delete ui;
}
