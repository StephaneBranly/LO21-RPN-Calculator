#include "keyboardnumeric.h"
#include "ui_keyboardnumeric.h"

#include <QDockWidget>
#include <QMainWindow>
#include <QDebug>

KeyboardNumeric::KeyboardNumeric(QMainWindow *parent)
    : QWidget(parent)
    , ui(new Ui::KeyboardNumeric)
{
    ui->setupUi(this);

    dock = new QDockWidget(parent);
    dock->setWidget(this);
    parent->addDockWidget(Qt::BottomDockWidgetArea, dock);

    signalMapper = new QSignalMapper(this);
    foreach(QObject *obj, children())
    {
        if(obj->metaObject()->className() == ui->ButtonEval->metaObject()->className() )
        {
                connect(obj, SIGNAL(clicked()), signalMapper, SLOT(map()));
                signalMapper->setMapping(obj, static_cast<QPushButton*>(obj)->text());
        }
    }
    connect(signalMapper, SIGNAL(mapped(QString)),parent, SLOT(addToCommandline(QString)));
    connect(dock, SIGNAL(visibilityChanged(bool)), parent, SLOT(updateTabDocks()));
}
KeyboardNumeric::~KeyboardNumeric()
{
    delete ui;
}

void KeyboardNumeric::toggleDock(bool b)
{
        dock->setHidden(!b);
}
