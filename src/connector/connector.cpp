#include "connector.h"
#include "../interface/mainwindow.h"
#include "../observer/observer.h"

#include <QDebug>

Connector::Connector(Mainwindow& w) : window(w)
{
    window.show();
    window.attach(this);
}

void Connector::notify(const std::string &message)
{
    qDebug()<<"NOTIF recue sur le connector :" << QString::fromStdString(message) <<"\n";
};
