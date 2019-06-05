#ifndef WAITINGFORRESULTS_H
#define WAITINGFORRESULTS_H

#include <QMainWindow>

namespace Ui {
class WaitingForResults;
}

class WaitingForResults : public QMainWindow
{
    Q_OBJECT

public:
    explicit WaitingForResults(QWidget *parent = 0);
    ~WaitingForResults();

private:
    Ui::WaitingForResults *ui;
};

#endif // WAITINGFORRESULTS_H
