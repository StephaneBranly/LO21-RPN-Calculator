#ifndef LATOMFACTORY_H
#define LATOMFACTORY_H

#include "../expressionfactory.h"
#include "../expression.h"
#include "latom.h"

namespace Engine {
    class LatomFactory : public ExpressionFactory
    {
    public:
        bool isSameType(const std::string s) const;
        Latom* createExpressionFromString(const std::string s);
    };
}
#endif // LATOMFACTORY_H
