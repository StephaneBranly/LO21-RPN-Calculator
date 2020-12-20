#include "variables.h"
#include "ui_variables.h"

#include <QMainWindow>
#include <QDockWidget>

Variables::Variables(QMainWindow *parent)
    : QWidget(parent)
    , ui(new Ui::Variables)
{
    ui->setupUi(this);

    dock = new QDockWidget(parent);
    dock->setWidget(this);
    parent->addDockWidget(Qt::RightDockWidgetArea, dock);

    connect(dock, SIGNAL(visibilityChanged(bool)), parent, SLOT(updateTabDocks()));
    connect(this, SIGNAL(readyToPush(QString)), parent, SLOT(execute(QString)));
    connect(this, SIGNAL(editAtom(QString)), parent, SLOT(editAtom(QString)));
}

Variables::~Variables()
{
    delete ui;
}

void Variables::toggleDock(bool b)
{
        dock->setHidden(!b);
}

void Variables::pushVar()
{
    QPushButton* s = (QPushButton*)sender();
    emit readyToPush(s->text());
}

void Variables::updateVars(const std::list<QString> li)
{
    for(auto it = vars.begin(); it != vars.end(); ++it)
    {
        ui->containerVars->removeWidget(*it);
        (*it)->disconnect(this);
        delete *it;
    }
    vars.clear();
    Variable* v;
    for(auto it = li.begin(); it != li.end(); ++it)
    {
        v = new Variable(this,(*it));
        vars.push_back(v);
        ui->containerVars->addWidget(v);
    }
}


void Variables::editVar(const QString s)
{
    emit editAtom(s);
}

Variable::Variable(Variables* v,const QString name):parent(v), name(name)
{
    layout = new QHBoxLayout(this);

    setLayout(layout);
    button = new QPushButton(this);
    button->setText(name);

    editLabel = new ClickableLabel(this);
    editLabel->setText("Editer");
    editLabel->setRefName(name);
    editLabel->installEventFilter(this);

    connect(button,SIGNAL(clicked()),parent,SLOT(pushVar()));
    layout->addWidget(button);
    connect(editLabel,SIGNAL(clicked(QString)),parent, SLOT(editVar(QString)));

    layout->addWidget(editLabel);
}
