#ifndef OPERATOR_H
#define OPERATOR_H

#include "../expression/expression.h"
#include "../stack/stack.h"
#include "../exception/CompException.h"
#include <iostream>
#include <string>

using namespace std;

namespace Engine {
    class Operator : public Expression {
        static size_t arrity;
    public :
        size_t getArrity () {return arrity;}
    };

    class OperatorPlus : public Operator {
        size_t arrity=2;
    public :
        void eval()
        {
           Stack p = Computer::getInstance().getStack();
           if (p.size() < arrity)
               throw ComputerException ("La pile ne contient pas assez de valeurs à additioner");
           Expression* L1 = p.top();
           p.pop();
           Expression* L2 = p.top();
           p.pop();
           try {
               Expression* result = new Expression((*L1)+(*L2));
               p.push(result);
           } catch (ComputerException e) {
               throw ComputerException(e);
           }
       }
        string toString() {return "+";}
    };

    class OperatorMinus : public Operator {
        size_t arrity=2;
    public :
        void eval()
        {
           Stack p = Computer::getInstance().getStack();
           if (p.size() < arrity)
               throw ComputerException ("La pile ne contient pas assez de valeurs à soustraire");
           Expression* L1 = p.top();
           p.pop();
           Expression* L2 = p.top();
           p.pop();
           try {
               Expression* result = new Expression((*L1)-(*L2));
               p.push(result);
           } catch (ComputerException e) {
               throw ComputerException(e);
           }
       }
        string toString() {return "-";}
    };

    class OperatorMult : public Operator {
        size_t arrity=2;
    public :
        void eval()
        {
           Stack p = Computer::getInstance().getStack();
           if (p.size() < arrity)
               throw ComputerException ("La pile ne contient pas assez de valeurs à multiplier");
           Expression* L1 = p.top();
           p.pop();
           Expression* L2 = p.top();
           p.pop();
           try {
               Expression* result = new Expression((*L1)*(*L2));
               p.push(result);
           } catch (ComputerException e) {
               throw ComputerException(e);
           }
       }
        string toString() {return "*";}
    };

    class OperatorDiv : public Operator {
        size_t arrity=2;
    public :
        void eval()
        {
           Stack p = Computer::getInstance::getStack();
           if (p.size() < arrity)
               throw ComputerException ("La pile ne contient pas assez de valeurs à diviser");
            Expression* L1 = p.top();
            p.pop();
            Expression* L2 = p.top();
            p.pop();
            try {
                Expression* result = new Expression((*L1)/(*L2));
                p.push(result);
            } catch (ComputerException e) {
            throw ComputerException(e);
            }
       }
    string toString() {return "/";}
};
}
#endif // OPERATOR_H
