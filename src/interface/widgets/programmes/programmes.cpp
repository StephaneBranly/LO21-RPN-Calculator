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
}

Programmes::~Programmes()
{
    delete ui;
}

void Programmes::toggleDock(bool b)
{
        dock->setHidden(!b);
}
