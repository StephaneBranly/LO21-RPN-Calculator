#include "clickablelabel.h"


ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)

: QLabel(parent) {
    setStyleSheet("color: #4040F0;");
}

ClickableLabel::~ClickableLabel() {}
void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked(refName);
}
