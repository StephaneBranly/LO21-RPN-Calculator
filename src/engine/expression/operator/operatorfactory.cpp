#include "operatorfactory.h"
#include "../../exception/CompException.h"

bool Engine::OperatorFactory::isSameType(const std::string s) const
{
    return operators.find(s) != operators.end();
}

Engine::Expression* Engine::OperatorFactory::createExpressionFromString(const std::string s) const
{
    if(isSameType(s))
        return operators.at(s)->getCopy();
    throw ComputerException("Il n'existe pas d'operator "+s+".");
}
Engine::Expression* Engine::OperatorFactory::getOriginalOperatorFromString(const std::string s)
{
    if(isSameType(s))
        return operators.at(s);
    throw ComputerException("Il n'existe pas d'operator "+s+".");
}

void Engine::OperatorFactory::addOperator(const std::string name, Operator* ope)
{
    operators.insert(std::pair<std::string,Operator*>(name,ope));
}

void Engine::OperatorFactory::removeOperator(const std::string name)
{
    if(isSameType(name))
    {
        delete operators.at(name);
        operators.erase(name);
    }
}
