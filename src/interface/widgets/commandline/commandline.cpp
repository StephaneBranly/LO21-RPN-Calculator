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

