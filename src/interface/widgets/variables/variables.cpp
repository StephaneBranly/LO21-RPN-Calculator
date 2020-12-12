#include "variables.h"
#include "ui_variables.h"

#include <QMainWindow>
#include <QDockWidget>

Variables::Variables(QMainWindow *parent)
    : QWidget(parent)
    , ui(new Ui::Variables)
{
    ui->setupUi(this);

    dock = new QDockWidget(parent);
    dock->setWidget(this);
    parent->addDockWidget(Qt::RightDockWidgetArea, dock);

    connect(dock, SIGNAL(visibilityChanged(bool)), parent, SLOT(updateTabDocks()));
    connect(this, SIGNAL(readyToPush(QString)), parent, SLOT(atomToEval(QString)));
}

Variables::~Variables()
{
    delete ui;
}

void Variables::toggleDock(bool b)
{
        dock->setHidden(!b);
}

void Variables::pushVar()
{
    QPushButton* s = (QPushButton*)sender();
    emit readyToPush(s->text());
}

void Variables::updateVars(const std::list<QString> li)
{
    for(auto it = vars.begin(); it != vars.end(); ++it)
    {
        ui->containerVars->removeWidget(*it);
        (*it)->disconnect(this);
        delete *it;
    }
    vars.clear();
    QPushButton* b;
    for(auto it = li.begin(); it != li.end(); ++it)
    {
        b = new QPushButton();
        b->setText(*it);
        connect(b,SIGNAL(clicked()),this,SLOT(pushVar()));
        vars.push_back(b);
        ui->containerVars->addWidget(b);
    }
}
