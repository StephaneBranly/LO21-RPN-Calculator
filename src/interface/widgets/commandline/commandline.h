#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Commandline; }
QT_END_NAMESPACE

class Commandline : public QWidget
{
    Q_OBJECT

public:
    Commandline(QWidget *parent = nullptr);
    ~Commandline();
    void addText(const QString str);
    QString getText() const;

private:
    Ui::Commandline *ui;
};
#endif // COMMANDLINE_H
