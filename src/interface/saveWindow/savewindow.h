#ifndef SAVEWINDOW_H
#define SAVEWINDOW_H

#include <QDialog>
#include <QtGui>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>

#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class SaveWindow; }
QT_END_NAMESPACE

class SaveWindowItem;

// Fenetre de sauvegarde
class SaveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SaveWindow(QWidget *p);
    ~SaveWindow();
    void setBuffer(const QString s) { buffer = s; }
    QString getBuffer() const { return buffer; }
private:
    Ui::SaveWindow *ui;
    std::list<SaveWindowItem*> atoms;
    QString buffer;
public slots:
    void updateAtoms(const std::list<QString> progs, const std::list<QString> vars);
private slots:
    void acceptedChanges();
    void changePath();
signals:
    void needAtomValue();
};

// Items composant cette fenetre
class SaveWindowItem : public QWidget
{
    Q_OBJECT
public:
    explicit SaveWindowItem(QWidget *parent = 0, const QString valueName="");
    bool isChecked() const { return checkbox->isChecked(); }
    QString getAtomName() const { return name; }
private:
    QString name;
    QCheckBox* checkbox;
    QHBoxLayout* layout;
    QLabel* label;
};
#endif // SAVEWINDOW_H
