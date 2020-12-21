#ifndef PILE_H
#define PILE_H

#include <QWidget>
#include <list>

QT_BEGIN_NAMESPACE
namespace Ui { class Pile; }
QT_END_NAMESPACE

// Pile
class Pile : public QWidget
{
    Q_OBJECT

public:
    Pile(QWidget *parent = nullptr);
    ~Pile();
    void setMessage(const QString m="");
    void updateContent(const std::list<QString> content);
    void updateSize(size_t t);
    size_t getSize() const { return size; }
private:
    Ui::Pile *ui;
    size_t size=5;
};
#endif // PILE
