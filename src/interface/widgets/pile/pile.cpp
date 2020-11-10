#include "pile.h"
#include "ui_pile.h"

Pile::Pile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Pile)
{
    ui->setupUi(this);
}

Pile::~Pile()
{
    delete ui;
}

