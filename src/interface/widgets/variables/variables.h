#ifndef VARIABLES_H
#define VARIABLES_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QCommandLinkButton>
#include <QLabel>
#include "../clickablelabel/clickablelabel.h"

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Variables; }
QT_END_NAMESPACE

class Variable;

class Variables : public QWidget
{
    Q_OBJECT

public:
    Variables(QMainWindow *parent = nullptr);
    ~Variables();
    QDockWidget* getDock() const {return dock;}
    void updateVars(const std::list<QString> li);

private:
    Ui::Variables *ui;
    QDockWidget* dock;
    std::list<Variable*> vars;

public slots:
    void toggleDock(bool b);
    void pushVar();
    void editVar(const QString);
signals:
    void readyToPush(const QString a);
    void editAtom(const QString s);
};

class Variable : public QWidget
{
    Q_OBJECT
public:
    Variable(Variables* v,const QString name);
private:
    Variables* parent;
    QString name;
    QString content;
    QPushButton* button;
    QHBoxLayout* layout;
    QLabel* label;
    ClickableLabel* editLabel;
};

#endif // VARIABLES_H
