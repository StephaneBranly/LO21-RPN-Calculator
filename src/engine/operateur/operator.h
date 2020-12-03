#ifndef OPERATOR_H
#define OPERATOR_H

#include "expression.h"
#include "pile.h"
#include "CompException.h"
#include <iostream>
#include <string>

using namespace std;

namespace Engine {
    class Operator : public Expression {
        static size_t arrite;
    public :
        size_t getArrite () {return arrite;}
    };

    class OperatorPlus : public Operator {
        size_t arrite=2;
    public :
        auto eval()
        {
           Pile p = Computeur::GetInstance::GetPile();
           if (p.taille() < arrite)
               throw ComputerException ("La pile ne contient pas assez de valeurs à additioner");
               Expression L1 = p.top();
               p.pop();
               Expression L2 = p.top();
               p.pop();
               try {
                   p.push(L1+L2);
               } catch (ComputerException e) {
                   throw e.getInfo();
               }
           }
        string toString() {return "+";}
    };

    class OperatorMoins : public Operator {
        size_t arrite=2;
    public :
        auto eval()
        {
           Pile p = Computeur::GetInstance::GetPile();
           if (p.taille() < arrite)
               throw ComputerException ("La pile ne contient pas assez de valeurs à soustraire");
               Expression L1 = p.top();
               p.pop();
               Expression L2 = p.top();
               p.pop();
               try {
                   p.push(L1-L2);
               } catch (ComputerException e) {
                   throw e.getInfo();
               }
           }
        string toString() {return "-";}
    };

    class OperatorMult : public Operator {
        size_t arrite=2;
    public :
        auto eval()
        {
           Pile p = Computeur::GetInstance::GetPile();
           if (p.taille() < arrite)
               throw ComputerException ("La pile ne contient pas assez de valeurs à multiplier");
               Expression L1 = p.top();
               p.pop();
               Expression L2 = p.top();
               p.pop();
               try {
                   p.push(L1*L2);
               } catch (ComputerException e) {
                   throw e.getInfo();
               }
           }
        string toString() {return "*";}
    };

    class OperatorDiv : public Operator {
        size_t arrite=2;
    public :
        auto eval()
        {
           Pile p = Computeur::GetInstance::GetPile();
           if (p.taille() < arrite)
               throw ComputerException ("La pile ne contient pas assez de valeurs à diviser");
               Expression L1 = p.top();
               p.pop();
               Expression L2 = p.top();
               p.pop();
               try {
                   p.push(L1/L2);
               } catch (ComputerException e) {
                   throw e.getInfo();
               }
           }
        string toString() {return "/";}
    };
}
#endif // OPERATOR_H
