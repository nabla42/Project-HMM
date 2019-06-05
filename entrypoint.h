#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class EntryPoint;
}

class EntryPoint : public QDialog
{
    Q_OBJECT

public:
    explicit EntryPoint(QWidget *parent = 0);
    ~EntryPoint();

private slots:
    void on_btnEntrance_clicked();

private:
    void showWindow(bool isAdmin, QString userName);
    Ui::EntryPoint *ui;
};

#endif // ENTRYPOINT_H
