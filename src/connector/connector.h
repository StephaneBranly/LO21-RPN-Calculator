#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "../interface/mainwindow.h"
#include "../observer/observer.h"
#include <string>

class Connector : public Observer
{
public:
    Connector(Mainwindow& w);
    void notify(const std::string &message);
private:
    Mainwindow& window;
};

#endif // CONNECTOR_H
