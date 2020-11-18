#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>

#include "../observer/subject.h"

#include "widgets/keyboard/keyboard.h"
#include "widgets/pile/pile.h"
#include "widgets/commandline/commandline.h"
#include "widgets/variables/variables.h"
#include "widgets/programmes/programmes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Mainwindow; }
QT_END_NAMESPACE

class Mainwindow : public QMainWindow, public Subject
{
    Q_OBJECT

public:
    Mainwindow(QWidget *parent = nullptr);
    ~Mainwindow();

private:
    Ui::Mainwindow *ui;
    Commandline* commandline;
    Pile* pile;
    Keyboard* keyboard;
    QDockWidget* dockkeyboard;
    Programmes* programmes;
    QDockWidget* dockprogrammes;
    Variables* variables;
    QDockWidget* dockvariables;

public slots:
    void clickEval();
};
#endif // MAINWINDOW_H
