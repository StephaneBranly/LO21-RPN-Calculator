#include "operatorarithmetic.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"
#include "../litterales/linteger.h"

Engine::OperatorPLUS::OperatorPLUS()
{
    registerAction("Linteger", "Linteger", new SumIntInt);
}

void Engine::OperatorArithmetic::registerAction(std::string type1, std::string type2, Action *a)
{
    tuple<string, string> t = make_tuple(type1,type2);
    opes.insert(make_pair(t,a));
}

void Engine::OperatorArithmetic::executeOpe()
{
    Stack& p=ComputerEngine::getInstance().getStack();
    Expression* L1=p.top();
    p.pop();
    Expression* L2=p.top();
    p.pop();

    tuple<string,string> t = make_tuple(L1->getType(),L2->getType());
    if (opes.find(t) != opes.end())
    {
        p.push(opes.at(t)->executeAction(L1,L2));
    }
    else
    {
        throw ComputerException("Action "+toString()+" impossible entre "+L1->getType()+" et "+L2->getType());
    }
}

Engine::Expression* Engine::SumIntInt::executeAction(Expression* L1,Expression* L2)
{
    return (new Linteger(dynamic_cast<Linteger*>(L1)->getValue()+dynamic_cast<Linteger*>(L2)->getValue()));
}
