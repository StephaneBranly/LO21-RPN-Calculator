#ifndef LREALFACTORY_H
#define LREALFACTORY_H

#include "../expressionfactory.h"
#include "../expression.h"
#include "lreal.h"

namespace Engine {

// Factory reconnaissant et creant des Lreal
    class LrealFactory : public ExpressionFactory
    {
    public:
        bool isSameType(const std::string s) const;
        Lreal* createExpressionFromString(const std::string s) const;
    };
}

#endif // LREALFACTORY_H
