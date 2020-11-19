#ifndef VARIABLES_H
#define VARIABLES_H

#include <QWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Variables; }
QT_END_NAMESPACE

class Variables : public QWidget
{
    Q_OBJECT

public:
    Variables(QMainWindow *parent = nullptr);
    ~Variables();

private:
    Ui::Variables *ui;
    QDockWidget* dock;

public slots:
    void toggleDock(bool b);
};

#endif // VARIABLES_H
