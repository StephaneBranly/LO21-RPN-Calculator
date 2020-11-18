#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Keyboard; }
QT_END_NAMESPACE

class Keyboard : public QWidget
{
    Q_OBJECT

public:
    Keyboard(QMainWindow *parent = nullptr);
    ~Keyboard();

private:
    Ui::Keyboard *ui;
    QDockWidget* dock;

public slots:
    void toggleDock();

};
#endif // KEYBOARD
