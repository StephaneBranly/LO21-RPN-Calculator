#ifndef OPERATORFACTORY_H
#define OPERATORFACTORY_H

#include "../expressionfactory.h"
#include "operator.h"

namespace Engine {

// Factory d'operateurs, contient un map de nomOperateur, Pointeur vers l'operateur
// Permet de reconnaitre si un string est un operateur, et de le generer
    class OperatorFactory : public ExpressionFactory
    {
    private:
        std::map<std::string, Operator*> operators;
    public:
        bool isSameType(const std::string s) const;
        Expression* createExpressionFromString(const std::string s) const;
        Expression* getOriginalOperatorFromString(const std::string s);
        void addOperator(const std::string name, Operator* ope);
        void removeOperator(const std::string name);
    };
}
#endif // OPERATORFACTORY_H

