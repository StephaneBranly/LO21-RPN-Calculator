#ifndef PILE_H
#define PILE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Pile; }
QT_END_NAMESPACE

class Pile : public QWidget
{
    Q_OBJECT

public:
    Pile(QWidget *parent = nullptr);
    ~Pile();

private:
    Ui::Pile *ui;
};
#endif // PILE
