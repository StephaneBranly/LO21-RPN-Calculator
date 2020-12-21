#include "savewindow.h"
#include "ui_savewindow.h"

#include <QFileDialog>

SaveWindow::SaveWindow(QWidget *p) :
    QDialog(p)
  , ui(new Ui::SaveWindow)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(acceptedChanges()));
    connect(ui->editPath,SIGNAL(clicked()),this,SLOT(changePath()));
    connect(this,SIGNAL(needAtomValue()),p,SLOT(getAtomEditValueToSave()));
}


SaveWindow::~SaveWindow()
{
    delete ui;
}

void SaveWindow::acceptedChanges()
{
    QString pathname = ui->path->text();
    QString toSave = "";
    for(auto it = atoms.begin(); it!=atoms.end(); ++it)
    {
        if((*it)->isChecked())
        {
            buffer = (*it)->getAtomName();
            emit needAtomValue();
            toSave += " "+buffer+" '"+(*it)->getAtomName()+"' STO \n";
        }
    }
    std::ofstream file;
    toSave += "\n";
    file.open(pathname.toStdString());
    file << toSave.toStdString();
    file.close();
}

void SaveWindow::changePath()
{
    QString fname = QFileDialog::getSaveFileName(nullptr, "sav", ".", "Programs (*.txt *.comput)" );
    ui->path->setText(fname);
}

void SaveWindow::updateAtoms(const std::list<QString> progs, const std::list<QString> vars)
{
    for(auto it = atoms.begin(); it != atoms.end(); ++it)
    {
        ui->containerAtoms->removeWidget(*it);
        delete *it;
    }
    atoms.clear();
    SaveWindowItem* p;
    for(auto it = progs.begin(); it != progs.end(); ++it)
    {
        p = new SaveWindowItem(this,(*it));
        atoms.push_back(p);
        ui->containerAtoms->addWidget(p);
    }

    for(auto it = vars.begin(); it != vars.end(); ++it)
    {
        p = new SaveWindowItem(this,(*it));
        atoms.push_back(p);
        ui->containerAtoms->addWidget(p);
    }
}


SaveWindowItem::SaveWindowItem(QWidget *parent, const QString valueName) : name(valueName)
{
    layout = new QHBoxLayout(this);
    setLayout(layout);

    checkbox = new QCheckBox(this);
    label = new QLabel(name);

    layout->addWidget(label);
    layout->addWidget(checkbox);
}
