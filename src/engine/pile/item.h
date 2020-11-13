#ifndef ITEM_H
#define ITEM_H

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Engine { class Item; }
QT_END_NAMESPACE

class Item {
public :
    Item() =default;
    //~Item(); à faire
    void setLitterale (Litterale& l) {lit = &l;}
    Litterale& getLitterale () {return *lit;}
    const Litterale& getLitterale () const { return *lit; }
    void raz() {lit = nullptr;}


private :
    Litterale* lit = nullptr;
};


#endif // ITEM_H
