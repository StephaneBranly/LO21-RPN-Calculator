#include "programmes.h"
#include "ui_programmes.h"

#include <QMainWindow>
#include <QDockWidget>

Programmes::Programmes(QMainWindow *parent)
    : QWidget(parent)
    , ui(new Ui::Programmes)
{
    ui->setupUi(this);

    dock = new QDockWidget(parent);
    dock->setWidget(this);
    parent->addDockWidget(Qt::RightDockWidgetArea, dock);

    connect(dock, SIGNAL(visibilityChanged(bool)), parent, SLOT(updateTabDocks()));
    connect(this, SIGNAL(readyToEval(QString)), parent, SLOT(execute(QString)));
}

Programmes::~Programmes()
{
    delete ui;
}

void Programmes::toggleDock(bool b)
{
        dock->setHidden(!b);
}


void Programmes::evalProg()
{
    QPushButton* s = (QPushButton*)sender();
    emit readyToEval(s->text());
}

void Programmes::updateProgs(const std::list<QString> li)
{
    for(auto it = progs.begin(); it != progs.end(); ++it)
    {
        ui->containerProgs->removeWidget(*it);
        (*it)->disconnect(this);
        delete *it;
    }
    progs.clear();
    QPushButton* b;
    for(auto it = li.begin(); it != li.end(); ++it)
    {
        b = new QPushButton();
        b->setText(*it);
        connect(b,SIGNAL(clicked()),this,SLOT(evalProg()));
        progs.push_back(b);
        ui->containerProgs->addWidget(b);
    }
}
