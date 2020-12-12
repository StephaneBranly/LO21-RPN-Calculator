#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <list>

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
    const QString getContentCommandLine() const { return commandline->getText(); }
    const QString getAtomToEval(){ return atomToEvalName; }
    void setMessage(const QString m){ pile->setMessage(m);}
    void updateAtoms(const std::list<std::tuple<QString,QString,QString>> l);   
private:
    Ui::Mainwindow *ui;
    Commandline* commandline;
    Pile* pile;
    KeyboardNumeric* keyboardnumeric;
    KeyboardFunctions* keyboardfunctions;
    Programmes* programmes;
    Variables* variables;
    QString atomToEvalName;
protected:
    void keyPressEvent(QKeyEvent *ev);

public slots:
    void clickEval();
    void addToCommandline(const QString str);
    void updateTabDocks();
    void updateStack(const std::list<QString> m){ pile->updateContent(m);}
    void clearCommandLine(){ commandline->clearText(); }
    void atomToEval(const QString a);
};
#endif // MAINWINDOW_H
