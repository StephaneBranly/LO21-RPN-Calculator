#include "src/interface/mainwindow.h"
#include "src/connector/connector.h"
#include "expressionmanager.h"
#include "expression.h"
#include <QApplication>
using namespace Engine;

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    Mainwindow& w = *(new Mainwindow);
    Connector c(w);
    return a.exec();

}
