#include "commandline.h"
#include "ui_commandline.h"

Commandline::Commandline(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Commandline)
{
    ui->setupUi(this);
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
