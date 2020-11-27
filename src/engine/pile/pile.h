#ifndef PILE_H
#define PILE_H
#include "item.h"

#include <string>

namespace  Engine {

class Pile {

public :
    Pile() = default;
    ~Pile() {
        delete[] items;
    }
//    void push(Litterale& l) { //empile une nouvelle littérale
//        if (nb==nbmax) agrandissementCapacite();
//        items[nb++].setLitterale(l);
//    }
    auto pop(){
        //dépile une nouvelle littérale, voir gestion de l'exception
        //if (nb==0) ComputerException("La pile est déjà vide");
        auto L = items[nb];
        items[nb--].raz();
        return L;
    }
    bool estVide () const {return nb==0;}
    size_t taille () const {return nb;}
    Item& top () const { //obtenir une référence sur le sommet de la pile, voir gestion de l'exception
        //if (nb==0) ComputerException("La pile est vide");
        return items[nb-1].getLitterale();
    }
    //a faire? void affiche () const;
    void setnbitemtoaffiche(size_t n) {nbAffiche=n;}

private:
    Item* items=nullptr;
    size_t nb=0;
    size_t nbMax=0;
    size_t nbAffiche=0;
    std::string message="";
    void agrandissementCapacite();


};
}

#endif // PILE_H
