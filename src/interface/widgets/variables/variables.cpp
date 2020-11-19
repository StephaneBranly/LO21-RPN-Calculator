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
}

Variables::~Variables()
{
    delete ui;
}

void Variables::toggleDock(bool b)
{
        dock->setHidden(!b);
}
