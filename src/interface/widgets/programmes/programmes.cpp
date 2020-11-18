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
    parent->addDockWidget(Qt::BottomDockWidgetArea, dock);
}

Programmes::~Programmes()
{
    delete ui;
}

void Programmes::toggleDock()
{
        dock->setHidden(!dock->isHidden());
}
