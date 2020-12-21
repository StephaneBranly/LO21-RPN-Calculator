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
    foreach(QObject *obj, children()) // Automatisation de la connexion des boutons a l'ajout de leur nom dans la command Line
    {
        if(obj->metaObject()->className() == ui->groupBox->metaObject()->className() )
        {
            foreach(QObject *obj2, obj->children())
            {
                if(obj2->metaObject()->className() == ui->ButtonCOS->metaObject()->className() )
                {
                        connect(obj2, SIGNAL(clicked()), signalMapper, SLOT(map()));
                        signalMapper->setMapping(obj2, static_cast<QPushButton*>(obj2)->text());
                }
            }
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
