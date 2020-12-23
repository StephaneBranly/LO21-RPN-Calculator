#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class About; }
QT_END_NAMESPACE


// Fenetre d'infos
class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();
private:
    Ui::About *ui;
public slots:
    void openGithub();
};
#endif // ABOUT_H
