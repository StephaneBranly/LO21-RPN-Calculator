#ifndef EDITATOM_H
#define EDITATOM_H

#include <QDialog>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class EditAtom; }
QT_END_NAMESPACE

// Fenetre d'edition d'atoms
class EditAtom : public QDialog
{
    Q_OBJECT

public:
    explicit EditAtom(QWidget *parent = 0);
    ~EditAtom();
    void setAtomName(const QString);
    void setAtomValue(const QString);
private:
    Ui::EditAtom *ui;
    QString oldName;
private slots:
    void acceptedChanges();
signals:
    void updateAtom(const QString s);
};

#endif // EDITATOM_H
