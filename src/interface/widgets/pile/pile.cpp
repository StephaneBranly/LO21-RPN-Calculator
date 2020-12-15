#include "pile.h"
#include "ui_pile.h"

Pile::Pile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Pile)
{
    ui->setupUi(this);
    ui->ContentTab->setColumnCount(1);
    ui->ContentTab->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ContentTab->horizontalHeader()->setVisible(false);
    ui->ContentTab->setAlternatingRowColors(true);
    ui->ContentTab->setStyleSheet("alternate-background-color: rgba(0,0,0,0.1);background-color: rgba(255,255,255,0.1);");
    ui->ContentTab->horizontalHeader()->setStretchLastSection(true);
    updateSize(10);


}

Pile::~Pile()
{
    delete ui;
}


void Pile::setMessage(const QString m)
{
   this->ui->Message->setText(m);
}

void Pile::updateContent(const std::list<QString> content)
{
    for(size_t i=0; i<size; i++)
        ui->ContentTab->item(i,0)->setText("");

    size_t nb=0;
    for(auto it=content.begin(); it!=content.end()  && nb<size; ++it)
    {
        ui->ContentTab->item(size-nb-1,0)->setText(*it);
        nb++;
    }
}

void Pile::updateSize(size_t t)
{
    size=t;
    ui->ContentTab->setRowCount(size);
    QStringList labels;
    for(size_t i=size; i>0; i--)
    {
        QString str=QString::number(i);
        str+=":";
        labels<<str;

        // création de l'item de chaque ligne
        ui->ContentTab->setItem(i-1,0, new QTableWidgetItem(""));
    }
    ui->ContentTab->setVerticalHeaderLabels(labels);
    ui->ContentTab->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
