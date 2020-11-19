#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>

#include "../observer/subject.h"

#include "widgets/keyboardnumeric/keyboardnumeric.h"
#include "widgets/keyboardfunctions/keyboardfunctions.h"
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
    KeyboardNumeric* keyboardnumeric;
    KeyboardFunctions* keyboardfunctions;
    Programmes* programmes;
    Variables* variables;
protected:
    void keyPressEvent(QKeyEvent *ev);

public slots:
    void clickEval();
    void addToCommandline(QString str);
};
#endif // MAINWINDOW_H
