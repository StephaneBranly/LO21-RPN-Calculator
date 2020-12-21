#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QWidget>
#include <QtGui>
#include <qobject.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Commandline; }
QT_END_NAMESPACE

// Ligne de commande
class Commandline : public QWidget
{
    Q_OBJECT

public:
    Commandline(QWidget *parent = nullptr);
    ~Commandline();
    void addText(const QString str);
    void clearText();
    void backspace();
    void updateText();
    QString getText() const;

private:
    Ui::Commandline *ui;
    QString textContent;
    QTimer* clock;
    bool cursor=false;
public slots:
    void toggleCursor(){ cursor=!cursor; updateText();}
};
#endif // COMMANDLINE_H
