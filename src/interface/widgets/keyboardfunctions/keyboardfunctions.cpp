#include "keyboardfunctions.h"
#include "ui_keyboardfunctions.h"

#include <QDockWidget>
#include <QDebug>
#include <QMainWindow>

KeyboardFunctions::KeyboardFunctions(QMainWindow *parent)
    : QWidget(parent)
    , ui(new Ui::KeyboardFunctions)
{
    ui->setupUi(this);

    dock = new QDockWidget(parent);
    dock->setWidget(this);
    parent->addDockWidget(Qt::LeftDockWidgetArea, dock);

    signalMapper = new QSignalMapper(this);
    foreach(QObject *obj, children())
    {
        if(obj->metaObject()->className() == ui->ButtonCLEAR->metaObject()->className() )
        {
                connect(obj, SIGNAL(clicked()), signalMapper, SLOT(map()));
                signalMapper->setMapping(obj, static_cast<QPushButton*>(obj)->text());
        }
    }
    connect(signalMapper, SIGNAL(mapped(QString)),parent, SLOT(addToCommandline(QString)));
    connect(dock, SIGNAL(visibilityChanged(bool)), parent, SLOT(updateTabDocks()));
}

KeyboardFunctions::~KeyboardFunctions()
{
    delete ui;
}

void KeyboardFunctions::toggleDock(bool b)
{
        dock->setHidden(!b);
}
