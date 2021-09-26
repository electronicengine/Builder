#include "mainwindow.h"
#include "windowworker.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    WindowWorker w;
    w.show();
    return a.exec();

}
