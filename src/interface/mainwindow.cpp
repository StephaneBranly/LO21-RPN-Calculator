#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widgets/keyboardnumeric/keyboardnumeric.h"
#include "widgets/pile/pile.h"
#include "widgets/commandline/commandline.h"
#include "widgets/variables/variables.h"
#include "widgets/programmes/programmes.h"

#include <QDebug>
#include <QDockWidget>

Mainwindow::Mainwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mainwindow)
{
    ui->setupUi(this);

    pile = new Pile(this);
    commandline = new Commandline(this);
    keyboardnumeric = new KeyboardNumeric(this);
    programmes = new Programmes(this);
    variables = new Variables(this);

    connect(ui->actionClavier_numerique, SIGNAL(changed()),keyboardnumeric,SLOT(toggleDock()));
    connect(ui->actionProgrammes, SIGNAL(changed()),programmes,SLOT(toggleDock()));
    connect(ui->actionVariables, SIGNAL(changed()),variables,SLOT(toggleDock()));

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
