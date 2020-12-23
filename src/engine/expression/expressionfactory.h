#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include <list>
#include <string>
#include "expression.h"

namespace Engine {

// Classe abstraite de Factory
class ExpressionFactory
{
public:
    ExpressionFactory()=default;
    virtual bool isSameType(const std::string s) const = 0;
    virtual Expression* createExpressionFromString(const std::string s) const = 0 ;
};
}

#endif // EXPRESSIONFACTORY_H
