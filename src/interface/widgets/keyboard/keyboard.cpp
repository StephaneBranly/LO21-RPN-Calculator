#include "keyboard.h"
#include "ui_keyboard.h"

#include <QDockWidget>
#include <QMainWindow>

Keyboard::Keyboard(QMainWindow *parent)
    : QWidget(parent)
    , ui(new Ui::Keyboard)
{
    ui->setupUi(this);

    dock = new QDockWidget(parent);
    dock->setWidget(this);
    parent->addDockWidget(Qt::BottomDockWidgetArea, dock);

    connect(ui->ButtonEval, SIGNAL(clicked()),parent,SLOT(clickEval()));
}

Keyboard::~Keyboard()
{
    delete ui;
}



void Keyboard::toggleDock()
{
        dock->setHidden(!dock->isHidden());
}
