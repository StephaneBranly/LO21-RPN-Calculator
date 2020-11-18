#include "variables.h"
#include "ui_variables.h"

Variables::Variables(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Variables)
{
    ui->setupUi(this);
}

Variables::~Variables()
{
    delete ui;
}

