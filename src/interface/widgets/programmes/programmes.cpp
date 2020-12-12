#include "programmes.h"
#include "ui_programmes.h"

#include <QMainWindow>
#include <QDockWidget>

Programmes::Programmes(QMainWindow *parent)
    : QWidget(parent)
    , ui(new Ui::Programmes)
{
    ui->setupUi(this);

    dock = new QDockWidget(parent);
    dock->setWidget(this);
    parent->addDockWidget(Qt::RightDockWidgetArea, dock);

    connect(dock, SIGNAL(visibilityChanged(bool)), parent, SLOT(updateTabDocks()));
    connect(this, SIGNAL(readyToEval(QString)), parent, SLOT(execute(QString)));
    connect(this, SIGNAL(editAtom(QString)), parent, SLOT(editAtom(QString)));
}

Programmes::~Programmes()
{
    delete ui;
}

void Programmes::toggleDock(bool b)
{
        dock->setHidden(!b);
}


void Programmes::evalProg()
{
    QPushButton* s = (QPushButton*)sender();
    emit readyToEval(s->text());
}

void Programmes::updateProgs(const std::list<QString> li)
{
    for(auto it = progs.begin(); it != progs.end(); ++it)
    {
        ui->containerProgs->removeWidget(*it);
        (*it)->disconnect(this);
        delete *it;
    }
    progs.clear();
    Program* p;
    for(auto it = li.begin(); it != li.end(); ++it)
    {
        p = new Program(this,(*it));
        progs.push_back(p);
        ui->containerProgs->addWidget(p);
    }
}


void Programmes::editProg(const QString s)
{
    emit editAtom(s);
}

Program::Program(Programmes* v,const QString name):parent(v), name(name)
{
    layout = new QHBoxLayout();

    setLayout(layout);
    button = new QPushButton();
    button->setText(name);

    editLabel = new ClickableLabel();
    editLabel->setText("Editer");
    editLabel->setRefName(name);
    editLabel->installEventFilter(this);

    connect(button,SIGNAL(clicked()),parent,SLOT(evalProg()));
    layout->addWidget(button);
    connect(editLabel,SIGNAL(clicked(QString)),parent, SLOT(editProg(QString)));

    layout->addWidget(editLabel);
}
