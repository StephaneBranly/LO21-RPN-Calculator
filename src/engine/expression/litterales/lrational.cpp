#include "lrational.h"
#include "../CompException" //path?
#include "linteger.h"
#include <iostream>

void Engine::Lrational::simplify()
{
        if(denominateur == 1){
            //création d'une littérale entiere, et destruction de la Lrationnelle.
            Engine::Linteger::setLinteger(numerateur);//erreur
        }
        if (numerateur == 0) {
            //création de la littérale entiere nulle.
            Engine::Linteger::setLinteger(denominateur);//erreur
        }
}


void Engine::Lrational::setRational(int n, int d){
    numerateur=n;
    if (d==0) throw CompException ("Error : dénominateur invalide.");
    denominateur = d;
    simplify();
}

void Engine::Lrational::setRational(Linteger& e1, Linteger& e2){
    numerateur = e1.getvalue();
    if (e2.getvalue()==0) throw CompException ("Error : dénominateur invalide.");
    denominateur = e2.getvalue();
    simplify();
}

/*
void Engine::Lrational::afficher(){
    std::cout<<numerateur<<"/"<<denominateur<<" ";
}
*/


