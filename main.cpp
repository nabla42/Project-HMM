#include "entrypoint.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EntryPoint w;
    w.show();

    return a.exec();
}
