#include "keyboardnumeric.h"
#include "ui_keyboardnumeric.h"

#include <QDockWidget>
#include <QMainWindow>

KeyboardNumeric::KeyboardNumeric(QMainWindow *parent)
    : QWidget(parent)
    , ui(new Ui::KeyboardNumeric)
{
    ui->setupUi(this);

    dock = new QDockWidget(parent);
    dock->setWidget(this);
    parent->addDockWidget(Qt::BottomDockWidgetArea, dock);

    connect(ui->ButtonEval, SIGNAL(clicked()),parent,SLOT(clickEval()));
}

KeyboardNumeric::~KeyboardNumeric()
{
    delete ui;
}

void KeyboardNumeric::toggleDock()
{
        dock->setHidden(!dock->isHidden());
}
