#include "src/interface/mainwindow.h"
#include "src/engine/computerengine.h"
#include "src/connector/connector.h"

#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Mainwindow& w = *(new Mainwindow);
    Engine::ComputerEngine e = Engine::ComputerEngine::getInstance();
    Connector c(w,e);
    return a.exec();
}
