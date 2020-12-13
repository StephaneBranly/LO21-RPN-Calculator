#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class ClickableLabel : public QLabel {

Q_OBJECT

public:
    void setRefName(QString s){ refName = s; }
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel();

signals:
    void clicked(QString t);

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    QString refName="";

};

#endif // CLICKABLELABEL_H
