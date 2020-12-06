#include "connector.h"
#include "../interface/mainwindow.h"
#include "../observer/observer.h"
#include "../engine/exception/CompException.h"

#include <QDebug>

#include <string>

Connector::Connector(Mainwindow& w, Engine::ComputerEngine& e) : window(w), engine(e)
{
    window.show();
    window.attach(this);
    engine.getInstance().attach(this);
}

void Connector::notify(const std::string &message)
{
    qDebug()<<"NOTIF recue sur le connector :" << QString::fromStdString(message) <<"\n";
    if(message=="clickEval")
    {
        const std::string content = window.getContentCommandLine().toStdString();
        try{engine.getExpressionManager().evalCommandLine(content); window.setMessage("OK"); window.clearCommandLine(); }
        catch(Engine::ComputerException e){ window.setMessage(QString::fromStdString(e.getInfo()));}
    }else if(message=="stackChanged")
    {
        const std::list<std::string> items = engine.getInstance().getStack().toStringList();
        std::list<QString> forStack;
        for(auto it = items.begin(); it!=items.end(); ++it)
            forStack.push_back(QString::fromStdString(*it));
        window.updateStack(forStack);
    }
};
