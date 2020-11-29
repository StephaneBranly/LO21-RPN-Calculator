#ifndef PROGRAMMES_H
#define PROGRAMMES_H

#include <QWidget>
#include <QMainWindow>

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

private:
    Ui::Programmes *ui;
    QDockWidget* dock;

public slots:
    void toggleDock(bool b);
};

#endif // PROGRAMMES_H
