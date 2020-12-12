#ifndef VARIABLES_H
#define VARIABLES_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Variables; }
QT_END_NAMESPACE

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
    std::list<QPushButton*> vars;

public slots:
    void toggleDock(bool b);
    void pushVar();
signals:
    void readyToPush(QString a);
};

#endif // VARIABLES_H
