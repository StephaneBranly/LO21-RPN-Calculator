#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "widgets/keyboard/keyboard.h"
#include "widgets/pile/pile.h"
#include "widgets/commandline/commandline.h"
#include "widgets/varsprogs/varsprogs.h"

//#include <QtUiTools>

Mainwindow::Mainwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mainwindow)
{
    ui->setupUi(this);
    ui->LeftColumn->addWidget(new Pile(this));
    ui->LeftColumn->addWidget(new Commandline(this));
    ui->LeftColumn->addWidget(new Keyboard(this));
    ui->RightColumn->addWidget(new Varsprogs(this));
}

Mainwindow::~Mainwindow()
{
    delete ui;
}

