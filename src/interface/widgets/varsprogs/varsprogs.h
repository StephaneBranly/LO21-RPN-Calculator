#ifndef VARSPROGS_H
#define VARSPROGS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Varsprogs; }
QT_END_NAMESPACE

class Varsprogs : public QWidget
{
    Q_OBJECT

public:
    Varsprogs(QWidget *parent = nullptr);
    ~Varsprogs();

private:
    Ui::Varsprogs *ui;
};

#endif // VARSPROGS_H
