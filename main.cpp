#include "src/interface/mainwindow.h"
#include "src/connector/connector.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mainwindow& w = *(new Mainwindow);
    Connector c(w);
    return a.exec();
}
