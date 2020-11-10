#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "keyboard.h"

//#include <QtUiTools>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->LeftColumn->addWidget(new Keyboard(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

