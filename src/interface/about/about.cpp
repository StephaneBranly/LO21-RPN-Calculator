#include "about.h"
#include "ui_about.h"

#include "../widgets/clickablelabel/clickablelabel.h"

About::About(QWidget *parent) :
    QDialog(parent)
  , ui(new Ui::About)
{
    ui->setupUi(this);


    ClickableLabel* link = new ClickableLabel();
    link->setText("Repository Github");
    link->installEventFilter(this);

    ui->verticalLayout->addWidget(link);
    connect(link,SIGNAL(clicked(QString)),this, SLOT(openGithub()));
}

About::~About()
{
    delete ui;
}

void About::openGithub()
{
    QDesktopServices::openUrl (QString("https://github.com/StephaneBranly/LO21-Project"));
}


