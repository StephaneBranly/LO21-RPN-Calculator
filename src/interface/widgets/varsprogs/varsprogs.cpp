#include "varsprogs.h"
#include "ui_varsprogs.h"

Varsprogs::Varsprogs(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Varsprogs)
{
    ui->setupUi(this);
}

Varsprogs::~Varsprogs()
{
    delete ui;
}

