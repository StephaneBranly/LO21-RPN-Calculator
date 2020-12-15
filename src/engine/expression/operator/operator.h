#ifndef OPERATOR_H
#define OPERATOR_H

#include "../expression.h"
#include <iostream>
#include <string>

using namespace std;

namespace Engine {
    class Operator : public Expression {
        size_t arrity;
    public :
        Operator(const std::string type, const size_t arrity): Expression(type),arrity(arrity){}
        size_t getArrity() const {return arrity;}
        virtual void executeOpe(vector<Expression*> e) = 0;
        void eval() override;
        virtual Expression* getCopy() const override= 0;
    };

}
#endif // OPERATOR_H
