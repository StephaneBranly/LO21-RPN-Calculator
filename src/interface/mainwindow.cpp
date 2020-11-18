#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widgets/keyboard/keyboard.h"
#include "widgets/pile/pile.h"
#include "widgets/commandline/commandline.h"
#include "widgets/varsprogs/varsprogs.h"

//#include <QtUiTools>
#include <QDebug>
#include <QDockWidget>

Mainwindow::Mainwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mainwindow)
{
    ui->setupUi(this);

    pile = new Pile(this);
    commandline = new Commandline(this);
    keyboard = new Keyboard(this);

    QDockWidget *dockKeyboard = new QDockWidget(this);
    dockKeyboard->setWidget(keyboard);
    addDockWidget(Qt::BottomDockWidgetArea, dockKeyboard);

    ui->mainLayout->addWidget(pile);
    ui->mainLayout->addWidget(commandline);
//    ui->LeftColumn->addWidget(commandline);
//    ui->LeftColumn->addWidget(keyboard);
//    ui->RightColumn->addWidget(new Varsprogs(this));
}

Mainwindow::~Mainwindow()
{
    delete ui;
}


void Mainwindow::clickEval()
{
    notify("clickEval");
}
