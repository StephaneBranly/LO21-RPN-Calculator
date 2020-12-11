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
}

Variables::~Variables()
{
    delete ui;
}

void Variables::toggleDock(bool b)
{
        dock->setHidden(!b);
}


void Variables::updateVars(const std::list<QString> li)
{
////    vars.clear();
//    while(!ui->containerVars->isEmpty()) {
//      delete ui->containerVars->takeAt(0);
//    }
//    QPushButton* b;
//    for(auto it = li.begin(); it != li.end(); ++it)
//    {
//        b = new QPushButton(this);
//        b->setText(*it);
//        vars.push_back(b);
//        ui->containerVars->addWidget(b);
//    }
}
