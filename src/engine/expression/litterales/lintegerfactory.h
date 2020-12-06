#ifndef LINTEGERFACTORY_H
#define LINTEGERFACTORY_H

#include "../expressionfactory.h"
#include "../expression.h"

namespace Engine {
    class LintegerFactory : public ExpressionFactory
    {
    public:
        bool isSameType(const std::string s) const;
        Expression* createExpressionFromString(const std::string s);
    };
}

#endif // LINTEGERFACTORY_H
