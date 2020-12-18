#ifndef EXPRESSIONABSTRACTFACTORY_H
#define EXPRESSIONABSTRACTFACTORY_H

#include "expressionfactory.h"
#include "operator/operatorfactory.h"
#include "expression.h"
#include "operator/operatorsdefinition.h"

namespace Engine {
class ExpressionAbstractFactory
{
private:
    OperatorFactory* operatorFactory;
    std::list<ExpressionFactory*> factories;
public:
    ExpressionAbstractFactory();
    Expression* createExpressionFromString(const std::string s) const;
    void registerFactory(ExpressionFactory* factory){ factories.push_back(factory); }
    OperatorFactory* getOperatorFactory() const { return operatorFactory; }
};
}
#endif // EXPRESSIONABSTRACTFACTORY_H
