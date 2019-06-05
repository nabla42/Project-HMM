#ifndef STARTHMMWINDOW_H
#define STARTHMMWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class StartHMMWindow;
}

class StartHMMWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartHMMWindow(QWidget *parent = 0);
    void setAdmin(bool isAdmin);
    void setName(QString name);
    void setUserName(QString name);
    ~StartHMMWindow();

private slots:
    void on_radioAuto_clicked();
    void on_radioExists_clicked();
    void on_loadTextButton_clicked();
    void on_chooseModelButton_clicked();
    void on_workButton_clicked();
    void on_exitButton_clicked();
    void on_changeUserButton_clicked();

private:
    bool isAdmin;
    QString name;
    Ui::StartHMMWindow *ui;
    void setUserIcon();
    void initAdminMode();
    void initUserMode();
    bool readyToWork();
    void waitForResults();
};

#endif // STARTHMMWINDOW_H
