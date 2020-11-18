#include "keyboardfunctions.h"
#include "ui_keyboardfunctions.h"

#include <QDockWidget>
#include <QMainWindow>

KeyboardFunctions::KeyboardFunctions(QMainWindow *parent)
    : QWidget(parent)
    , ui(new Ui::KeyboardFunctions)
{
    ui->setupUi(this);

    dock = new QDockWidget(parent);
    dock->setWidget(this);
    parent->addDockWidget(Qt::LeftDockWidgetArea, dock);
}

KeyboardFunctions::~KeyboardFunctions()
{
    delete ui;
}

void KeyboardFunctions::toggleDock()
{
        dock->setHidden(!dock->isHidden());
}
