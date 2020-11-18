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
    QString c = getText();
    if(!c.endsWith(" ",Qt::CaseInsensitive))
    {
        if(str.length() && str[0].isDigit() && c.length() && c[c.length()-1].isDigit())
            this->ui->TextEdit->insert(str);
        else
            this->ui->TextEdit->insert(" "+str);
    }
    else
        this->ui->TextEdit->insert(str);
}
