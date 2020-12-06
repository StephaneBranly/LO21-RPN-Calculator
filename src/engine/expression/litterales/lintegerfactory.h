#ifndef LINTEGERFACTORY_H
#define LINTEGERFACTORY_H

#include "../expressionfactory.h"
#include "../expression.h"
#include "linteger.h"

namespace Engine {
    class LintegerFactory : public ExpressionFactory
    {
    public:
        bool isSameType(const std::string s) const;
        Linteger* createExpressionFromString(const std::string s);
    };
}

#endif // LINTEGERFACTORY_H
