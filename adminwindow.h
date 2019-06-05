#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();

private slots:
    void on_changeUserButton_clicked();
    void on_exitButton_clicked();
    void on_toStartMenuButton_clicked();
    void on_loadModelButton_clicked();
    void on_tabModelsWidget_tabCloseRequested(int index);

    void on_menuButton_clicked();

private:
    bool isAdmin = true;
    QString name = "admin";
    Ui::AdminWindow *ui;
    void setUserIconAndName();
    void setButtonsIcons();
    void addModelTab(QString modelName);
    void removeTab(int index);
    void clearTab(int index);
    void loadModelData(int index);
    void hideBackground();
    void showBackground();
};

#endif // ADMINWINDOW_H
