#ifndef OPERATOR_H
#define OPERATOR_H

#include "../expression/expression.h"
#include "../stack/stack.h"
#include "../exception/CompException.h"
#include "../computerengine.h"

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
        std::string type = "OperatorPLUS";
    public :
        void eval()
        {
           Stack p = ComputerEngine::getInstance().getStack();
           if (p.size() < arrity)
               throw ComputerException ("La pile ne contient pas assez de valeurs à additioner");
           Expression* L1 = p.top();
           p.pop();
           Expression* L2 = p.top();
           p.pop();
           try {
//               Expression* result = Expression::createCopy(L1);
//               p.push(result);
           } catch (ComputerException e) {
               throw ComputerException(e);
           }
       }
        const std::string toString() const {return "+";}
    };

    class OperatorMinus : public Operator {
        size_t arrity=2;
        std::string type = "OperatorMINUS";
    public :
        void eval()
        {
           Stack p = ComputerEngine::getInstance().getStack();
           if (p.size() < arrity)
               throw ComputerException ("La pile ne contient pas assez de valeurs à soustraire");
           Expression* L1 = p.top();
           p.pop();
           Expression* L2 = p.top();
           p.pop();
           try {
//               Expression* result = Expression::createCopy(L1);
//               p.push(result);
           } catch (ComputerException e) {
               throw ComputerException(e);
           }
       }
        const std::string toString() const {return "-";}
    };

    class OperatorMult : public Operator {
        size_t arrity=2;
        std::string type = "OperatorMULT";
    public :
        void eval()
        {
           Stack p = ComputerEngine::getInstance().getStack();
           if (p.size() < arrity)
               throw ComputerException ("La pile ne contient pas assez de valeurs à multiplier");
           Expression* L1 = p.top();
           p.pop();
           Expression* L2 = p.top();
           p.pop();
           try {
//               Expression* result = Expression::createCopy(L1);
//               p.push(result);
           } catch (ComputerException e) {
               throw ComputerException(e);
           }
       }
       const std::string toString() const { return "*";}
    };

    class OperatorDiv : public Operator {
        size_t arrity=2;
        std::string type = "OperatorDIV";
    public :
        void eval()
        {
           Stack p = ComputerEngine::getInstance().getStack();
           if (p.size() < arrity)
               throw ComputerException ("La pile ne contient pas assez de valeurs à diviser");
            Expression* L1 = p.top();
            p.pop();
            Expression* L2 = p.top();
            p.pop();
            try {
//                Expression* result = Expression::createCopy(L1);
//                p.push(result);
            } catch (ComputerException e) {
            throw ComputerException(e);
            }
       }
    const std::string toString() const {return "/";}
};
}
#endif // OPERATOR_H
