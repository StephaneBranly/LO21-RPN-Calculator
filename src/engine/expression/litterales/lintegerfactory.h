#ifndef LINTEGERFACTORY_H
#define LINTEGERFACTORY_H

#include "../expressionfactory.h"
#include "../expression.h"
#include "linteger.h"

namespace Engine {

    // Factory reconnaissant et creant les Linteger
    class LintegerFactory : public ExpressionFactory
    {
    public:
        bool isSameType(const std::string s) const;
        Linteger* createExpressionFromString(const std::string s) const;
    };
}

#endif // LINTEGERFACTORY_H
