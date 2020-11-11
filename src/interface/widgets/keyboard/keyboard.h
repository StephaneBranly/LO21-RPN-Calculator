#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Keyboard; }
QT_END_NAMESPACE

class Keyboard : public QWidget
{
    Q_OBJECT

public:
    Keyboard(QWidget *parent = nullptr);
    ~Keyboard();

private:
    Ui::Keyboard *ui;
};
#endif // KEYBOARD
