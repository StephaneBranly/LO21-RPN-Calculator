#include "lrational.h"
#include "linteger.h"
#include <iostream>
#include "../../exception/CompException.h"

void Engine::Lrational::simplify()
{
        if(denominator == 1){
            //création d'une littérale entiere, et destruction de la Lrationnelle.
//            Engine::Linteger::setLinteger(numerator);//erreur
        }
        if (numerator == 0) {
            //création de la littérale entiere nulle.
//            Engine::Linteger::setLinteger(denominator);//erreur
        }else {
            int r;
            r= PGCD(numerator,denominator);
            numerator = numerator/r;
            denominator = denominator/r;
            if(denominator<0){
                numerator = -numerator;
                denominator = -denominator;
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
    numerator=n;
    if (d==0) throw ComputerException("Error : dénominateur invalide.");
    denominator = d;
    simplify();
}

void Engine::Lrational::setRational(Linteger& e1, Linteger& e2){
    numerator = e1.getValue();
    if (e2.getValue()==0) throw ComputerException("Error : dénominateur invalide.");
    denominator = e2.getValue();
    simplify();
}
