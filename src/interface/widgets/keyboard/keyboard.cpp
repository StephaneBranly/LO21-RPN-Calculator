#include "keyboard.h"
#include "ui_keyboard.h"

Keyboard::Keyboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Keyboard)
{
    ui->setupUi(this);
}

Keyboard::~Keyboard()
{
    delete ui;
}

