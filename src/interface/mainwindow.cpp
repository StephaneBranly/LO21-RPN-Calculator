#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widgets/keyboard/keyboard.h"
#include "widgets/pile/pile.h"
#include "widgets/commandline/commandline.h"
#include "widgets/variables/variables.h"
#include "widgets/programmes/programmes.h"

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
    programmes = new Programmes(this);
    variables = new Variables(this);

    QDockWidget *dockKeyboard = new QDockWidget(this);
    dockKeyboard->setWidget(keyboard);
    addDockWidget(Qt::BottomDockWidgetArea, dockKeyboard);

    QDockWidget *dockProgrammes = new QDockWidget(this);
    dockProgrammes->setWidget(programmes);
    addDockWidget(Qt::RightDockWidgetArea, dockProgrammes);

    QDockWidget *dockVariables = new QDockWidget(this);
    dockVariables->setWidget(variables);
    addDockWidget(Qt::RightDockWidgetArea, dockVariables);

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
