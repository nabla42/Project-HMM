#include "modelname.h"
#include "ui_modelname.h"

ModelName::ModelName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModelName)
{
    ui->setupUi(this);
}

ModelName::~ModelName()
{
    delete ui;
}
