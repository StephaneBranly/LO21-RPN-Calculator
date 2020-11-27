#ifndef OPERATOR_H
#define OPERATOR_H
#include "expression.h"
#include "pile.h"
#include "CompException.h"
#include <iostream>

namespace Engine {
    class Operator : public Expression {
        static size_t arrite;
    public : 
        size_t getArrite () {return arrite;}
    };

    class Operatorplus : public Operator {
    public :

        auto eval()
        {
           if (Pile::getInstance::taille() < getArrite())
               throw ComputerException ("La pile ne contient pas assez de valeurs à additioner");
               auto L1 = Pile::pop();
               auto L2 = Pile::pop();
           }

        }

    };
}
#endif // OPERATOR_H
