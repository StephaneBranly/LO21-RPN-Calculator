#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widgets/keyboardnumeric/keyboardnumeric.h"
#include "widgets/keyboardfunctions/keyboardfunctions.h"
#include "widgets/pile/pile.h"
#include "widgets/commandline/commandline.h"
#include "widgets/variables/variables.h"
#include "widgets/programmes/programmes.h"

#include <QDebug>
#include <QDockWidget>
#include <QKeyEvent>

Mainwindow::Mainwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mainwindow)
{
    setFocusPolicy(Qt::StrongFocus);
    ui->setupUi(this);
    pile = new Pile(this);
    commandline = new Commandline(this);
    keyboardfunctions = new KeyboardFunctions(this);
    programmes = new Programmes(this);
    variables = new Variables(this);
    keyboardnumeric = new KeyboardNumeric(this);
    settings = new Settings(this);

    connect(ui->a_keyboardnumeric, SIGNAL(toggled(bool)),keyboardnumeric,SLOT(toggleDock(bool)));
    connect(ui->a_keyboardfunctions, SIGNAL(toggled(bool)),keyboardfunctions,SLOT(toggleDock(bool)));
    connect(ui->a_programs, SIGNAL(toggled(bool)),programmes,SLOT(toggleDock(bool)));
    connect(ui->a_vars, SIGNAL(toggled(bool)),variables,SLOT(toggleDock(bool)));
    connect(ui->actionSettings, SIGNAL(changed()), this, SLOT(openSettingsWindow()));
    ui->mainLayout->addWidget(pile);
    ui->mainLayout->addWidget(commandline);

    setFocusPolicy(Qt::StrongFocus);
}

Mainwindow::~Mainwindow()
{
    delete ui;
}


void Mainwindow::clickEval()
{
    notify("clickEval");
}

void Mainwindow::updateTabDocks()
{
    ui->a_keyboardfunctions->setChecked(!keyboardfunctions->getDock()->isHidden());
    ui->a_keyboardnumeric->setChecked(!keyboardnumeric->getDock()->isHidden());
    ui->a_programs->setChecked(!programmes->getDock()->isHidden());
    ui->a_vars->setChecked(!variables->getDock()->isHidden());
}

void Mainwindow::addToCommandline(QString str)
{
    QString c = commandline->getText();
    if(!c.endsWith(" ",Qt::CaseInsensitive))
    {
        if(str.contains(QRegExp("[!=<>\\d.\' ]")))
            commandline->addText(str);
        else
            commandline->addText(" "+str+" ");
    }
    else if(!str.contains(QRegExp(" ")))
        commandline->addText(str);
}

void Mainwindow::keyPressEvent(QKeyEvent *ev)
{
    QString text = ev->text();
    if(text.contains(QRegExp("^[A-Za-z]+$")))
        commandline->addText(text.toUpper());
    else if(text.contains(QRegExp("[!=<>-\\d*-+/.\[\\]']")))
        addToCommandline(text);
    else
    {
        switch(ev->key())
        {
            case Qt::Key_Return:
            case Qt::Key_Enter:
                notify("clickEval");
                break;
            case Qt::Key_Delete:
            case Qt::Key_Backspace:
                commandline->backspace();
                break;
            case Qt::Key_Space:
                addToCommandline(" ");
                break;
            default:
                qDebug()<<"\nTouche non geree\n";
        }
    }
}

void Mainwindow::openSettingsWindow()
{
        settings->show();
}
