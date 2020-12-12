#ifndef PROGRAMMES_H
#define PROGRAMMES_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Programmes; }
QT_END_NAMESPACE

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
    std::list<QPushButton*> progs;

public slots:
    void toggleDock(bool b);
    void evalProg();
signals:
    void readyToEval(QString a);
};

#endif // PROGRAMMES_H
