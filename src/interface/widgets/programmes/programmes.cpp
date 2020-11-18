#include "programmes.h"
#include "ui_programmes.h"

Programmes::Programmes(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Programmes)
{
    ui->setupUi(this);
}

Programmes::~Programmes()
{
    delete ui;
}

