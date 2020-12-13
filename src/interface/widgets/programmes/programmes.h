#ifndef PROGRAMMES_H
#define PROGRAMMES_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QCommandLinkButton>
#include <QLabel>
#include "../clickablelabel/clickablelabel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Programmes; }
QT_END_NAMESPACE

class Program;

class Programmes : public QWidget
{
    Q_OBJECT

public:
    Programmes(QMainWindow *parent = nullptr);
    ~Programmes();
    QDockWidget* getDock() const {return dock;}
    void updateProgs(const std::list<QString> li);

private:
    Ui::Programmes *ui;
    QDockWidget* dock;
    std::list<Program*> progs;

public slots:
    void toggleDock(bool b);
    void evalProg();
    void editProg(const QString);
signals:
    void readyToEval(QString a);
    void editAtom(const QString s);
};

class Program : public QWidget
{
    Q_OBJECT
public:
    Program(Programmes* v,const QString name);
private:
    Programmes* parent;
    QString name;
    QString content;
    QPushButton* button;
    QHBoxLayout* layout;
    QLabel* label;
    ClickableLabel* editLabel;
};


#endif // PROGRAMMES_H
