#include "lrationnelle.h"
#include "CompException"
#include <iostream>

void Engine::Lrationnelle::simplification()
{
        if(denominateur == 1){
            //création d'une littérale entiere, et destruction de la Lrationnelle.
            setLentiere(numerateur);
        }
        if (numerateur == 0) {
            //création de la littérale entiere nulle.
            setLentiere(denominateur);
        }
}

Engine::Lrationnelle::Lrationnelle(int n, int d){
    setRationelle(n,d);
}

void Engine::Lrationnelle::setRationelle(int n, int d){
    numerateur=n;
    if (d==0) throw CompException ("Error : dénominateur invalide.");
    denominateur = d;
    simplification();
}

void Engine::Lrationnelle::setrationnelle(Lentiere& e1, Lentiere& e2){
    numerateur = e1.getvalue();
    if (e2.getvalue()==0) throw CompException ("Error : dénominateur invalide.");
    denominateur = e2.getvalue();
    simplification();
}

void Engine::Lrationnelle::afficher(){
    std::cout<<numerateur<<"/"<<denominateur<<" ";
}

