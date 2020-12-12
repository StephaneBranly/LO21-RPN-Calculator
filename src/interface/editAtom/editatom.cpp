#include "editatom.h"
#include "ui_editatom.h"

EditAtom::EditAtom(QWidget *parent) :
    QDialog(parent)
  , ui(new Ui::EditAtom)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(acceptedChanges()));
    connect(this,SIGNAL(updateAtom(QString)),parent,SLOT(execute(QString)));
}

void EditAtom::setAtomName(const QString v)
{
    oldName = v;
    ui->inputID->setText(v);
}
void EditAtom::setAtomValue(const QString v)
{
    ui->inputValue->setText(v);
}



EditAtom::~EditAtom()
{
    delete ui;
}

void EditAtom::acceptedChanges()
{
    QString newName = ui->inputID->text().toUpper();
    QString newValue = ui->inputValue->text();
    QString maj = "'"+oldName+"' FORGET "+newValue+" '"+newName+"' STO";
    emit updateAtom(maj);
}

