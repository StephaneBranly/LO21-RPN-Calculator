#ifndef LEXPRESSIONFACTORY_H
#define LEXPRESSIONFACTORY_H

#include "../expressionfactory.h"
#include "../expression.h"
#include "lexpression.h"

namespace Engine {
class LexpressionFactory : public ExpressionFactory
    {
    public:
        bool isSameType(const std::string s) const;
        Lexpression* createExpressionFromString(const std::string s) const;
    };
};

#endif // LEXPRESSIONFACTORY_H
