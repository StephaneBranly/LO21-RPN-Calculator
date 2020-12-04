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
    void setMessage(const QString m="");
private:
    Ui::Pile *ui;
};
#endif // PILE
