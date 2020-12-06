#ifndef PILE_H
#define PILE_H

#include <QWidget>
#include <list>

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
    void updateContent(const std::list<QString> content);
    void updateSize(size_t t);
private:
    Ui::Pile *ui;
    size_t size=5;
};
#endif // PILE
