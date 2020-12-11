#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class Settings; }
QT_END_NAMESPACE

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
