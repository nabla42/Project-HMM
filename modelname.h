#ifndef MODELNAME_H
#define MODELNAME_H

#include <QDialog>

namespace Ui {
class ModelName;
}

class ModelName : public QDialog
{
    Q_OBJECT

public:
    explicit ModelName(QWidget *parent = nullptr);
    ~ModelName();

private:
    Ui::ModelName *ui;
};

#endif // MODELNAME_H
