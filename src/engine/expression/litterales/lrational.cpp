#include "lrational.h"
#include "linteger.h"
#include <iostream>
#include "../../exception/CompException.h"

void Engine::Lrational::simplify()
{
        if(denominateur == 1){
            //création d'une littérale entiere, et destruction de la Lrationnelle.
//            Engine::Linteger::setLinteger(numerateur);//erreur
        }
        if (numerateur == 0) {
            //création de la littérale entiere nulle.
//            Engine::Linteger::setLinteger(denominateur);//erreur
        }else {
            int r;
            r= PGCD(numerateur,denominateur);
            numerateur = numerateur/r;
            denominateur = denominateur/r;
            if(denominateur<0){
                numerateur = -numerateur;
                denominateur = -denominateur;
                    }
        }
}


int Engine::Lrational::PGCD(int a, int b){
    while(b!=0){
        int c=a%b;
        a=b;
        b=c;
    }
    return a;
   }


void Engine::Lrational::setRational(int n, int d){
    numerateur=n;
    if (d==0) throw ComputerException("Error : dénominateur invalide.");
    denominateur = d;
    simplify();
}

void Engine::Lrational::setRational(Linteger& e1, Linteger& e2){
    numerateur = e1.getValue();
    if (e2.getValue()==0) throw ComputerException("Error : dénominateur invalide.");
    denominateur = e2.getValue();
    simplify();
}
