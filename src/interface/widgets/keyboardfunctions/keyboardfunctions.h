#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QWidget>
#include <QMainWindow>
#include <QSignalMapper>

QT_BEGIN_NAMESPACE
namespace Ui { class KeyboardFunctions; }
QT_END_NAMESPACE

// Clavier de fonctions
class KeyboardFunctions : public QWidget
{
    Q_OBJECT

public:
    KeyboardFunctions(QMainWindow *parent = nullptr);
    ~KeyboardFunctions();
    QDockWidget* getDock() const {return dock;}

private:
    Ui::KeyboardFunctions *ui;
    QDockWidget* dock;
    QSignalMapper* signalMapper;

public slots:
    void toggleDock(bool b);

};

#endif // FUNCTIONS_H
