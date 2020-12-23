#ifndef OPERATOR_H
#define OPERATOR_H

#include "../expression.h"
#include <iostream>
#include <string>

using namespace std;

namespace Engine {

// Classe abstraite des operateurs
// Comporte une arrite qui permet de verifier automatiquement la possibilite d'executer l'operation avant de l'execute
    class Operator : public Expression {
        size_t arrity;
    public :
        Operator(const std::string type, const size_t arrity): Expression(type),arrity(arrity){}
        size_t getArrity() const {return arrity;}
        virtual void executeOpe(vector<Expression*> e) = 0;
        void eval() override;
        virtual Expression* getCopy() const override= 0;
        virtual ~Operator() = default;
    };

}
#endif // OPERATOR_H
