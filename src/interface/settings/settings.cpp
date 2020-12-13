#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent)
  , ui(new Ui::Settings)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(acceptedChanges()));
    connect(this,SIGNAL(stackSizeChanged(int)),parent,SLOT(updateSizeStack(int)));
}


Settings::~Settings()
{
    delete ui;
}

void Settings::acceptedChanges()
{
    qDebug()<<"acceptedChanged";
    int size = ui->spinBox->value();
    emit stackSizeChanged(size);
}
void Settings::setInputValue(const size_t s)
{
    ui->spinBox->setValue(s);
}
