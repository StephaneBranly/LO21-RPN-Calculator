#include "commandline.h"
#include "ui_commandline.h"

#include <QtDebug>

Commandline::Commandline(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Commandline)
{
    ui->setupUi(this);
    connect(ui->ButtonExe,SIGNAL(clicked()),parent,SLOT(clickEval()));
}

Commandline::~Commandline()
{
    delete ui;
}


QString Commandline::getText() const
{
    return this->ui->TextEdit->text();
}
void Commandline::addText(const QString str)
{
    this->ui->TextEdit->insert(str);
}
void Commandline::clearText()
{
    this->ui->TextEdit->clear();
}
void Commandline::backspace()
{
    this->ui->TextEdit->backspace();
}
