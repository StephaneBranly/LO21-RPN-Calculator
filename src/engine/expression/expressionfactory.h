#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include <list>
#include <string>
#include "expression.h"

namespace Engine {
class ExpressionFactory
{
public:
    ExpressionFactory()=default;
    virtual bool isSameType(const std::string s) const = 0;
    virtual Expression* createExpressionFromString(const std::string s) = 0 ;
};

class ExpressionAbstractFactory
{
private:
    std::list<ExpressionFactory*> factories;
public:
    ExpressionAbstractFactory()=default;
    Expression* createExpressionFromString(const std::string s);
    void registerFactory(ExpressionFactory* factory){ factories.push_back(factory); }
};

}

#endif // EXPRESSIONFACTORY_H
