#ifndef PROGRAMMES_H
#define PROGRAMMES_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Programmes; }
QT_END_NAMESPACE

class Programmes : public QWidget
{
    Q_OBJECT

public:
    Programmes(QWidget *parent = nullptr);
    ~Programmes();

private:
    Ui::Programmes *ui;
};

#endif // PROGRAMMES_H
