#ifndef VARIABLES_H
#define VARIABLES_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Variables; }
QT_END_NAMESPACE

class Variables : public QWidget
{
    Q_OBJECT

public:
    Variables(QWidget *parent = nullptr);
    ~Variables();

private:
    Ui::Variables *ui;
};

#endif // VARIABLES_H
