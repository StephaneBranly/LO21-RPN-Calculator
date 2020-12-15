#include "commandline.h"
#include "ui_commandline.h"

#include <QtDebug>
#include <QtGui>
#include <qobject.h>

Commandline::Commandline(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Commandline)
{
    ui->setupUi(this);
    connect(ui->ButtonExe,SIGNAL(clicked()),parent,SLOT(clickEval()));

    clock = new QTimer(this);
    QObject::connect(clock, SIGNAL(timeout()), this, SLOT(toggleCursor()));
    clock->start(500); //time specified in ms
}

Commandline::~Commandline()
{
    delete ui;
}


QString Commandline::getText() const
{
    return textContent;
}
void Commandline::addText(const QString str)
{
    textContent+=str;
    updateText();
}
void Commandline::clearText()
{
    textContent="";
    updateText();
}
void Commandline::backspace()
{
    if(textContent.length())
    {
        textContent = textContent.chopped(1);
        updateText();
    }
}
void Commandline::updateText()
{
    this->ui->TextEdit->clear();
    this->ui->TextEdit->insert(textContent);
    if(cursor)
        this->ui->TextEdit->insert("_");
}
