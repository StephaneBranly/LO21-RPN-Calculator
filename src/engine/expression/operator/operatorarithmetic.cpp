#include "operatorarithmetic.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"
#include "../litterales/linteger.h"
#include "../litterales/lreal.h"
#include "../litterales/lrational.h"

//Constructeurs des opérateurs
//opérateur +
Engine::OperatorPLUS::OperatorPLUS()
{
    //9 actions à implémenter
    registerAction("Linteger", "Linteger", new SumIntInt);
    registerAction("Linteger", "Lreal", new SumIntReal);
    registerAction("Lreal", "Linteger", new SumIntReal);
    registerAction("Lreal", "Lreal", new SumIntReal);
}

//opérateur -
Engine::OperatorMINUS::OperatorMINUS()
{
    //9 actions à implémenter
    registerAction("Linteger", "Linteger", new SubIntInt);
    registerAction("Linteger", "Lreal", new SubIntReal);
    registerAction("Lreal", "Linteger", new SubIntReal);
    registerAction("Lreal", "Lreal", new SubIntReal);
}

//opérateur *
Engine::OperatorMUL::OperatorMUL()
{
    //9 actions à implémenter
    registerAction("Linteger", "Linteger", new MulIntInt);
    registerAction("Linteger", "Lreal", new MulIntReal);
    registerAction("Lreal", "Linteger", new MulIntReal);
    registerAction("Lreal", "Lreal", new MulIntReal);
}

//opérateur /
Engine::OperatorDIV::OperatorDIV()
{
    //9 actions à implémenter
    registerAction("Linteger", "Linteger", new DivIntInt);
    registerAction("Linteger", "Lreal", new DivIntReal);
    registerAction("Lreal", "Linteger", new DivIntReal);
    registerAction("Lreal", "Lreal", new DivIntReal);
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

//Redéfinition de la méthode pour chaque action
//Operator +
Engine::Expression* Engine::SumIntInt::executeAction(Expression* L1,Expression* L2)
{
    return (new Linteger(dynamic_cast<Linteger*>(L1)->getValue()+dynamic_cast<Linteger*>(L2)->getValue()));
}

Engine::Expression* Engine::SumIntReal::executeAction(Expression* L1,Expression* L2)
{
    return (new Lreal(dynamic_cast<Lnumerical*>(L1)->getValue()+dynamic_cast<Lnumerical*>(L2)->getValue()));
}

//Operator -
Engine::Expression* Engine::SubIntInt::executeAction(Expression* L1,Expression* L2)
{
    return (new Linteger(dynamic_cast<Linteger*>(L1)->getValue()-dynamic_cast<Linteger*>(L2)->getValue()));
}

Engine::Expression* Engine::SubIntReal::executeAction(Expression* L1,Expression* L2)
{
    return (new Lreal(dynamic_cast<Lnumerical*>(L1)->getValue()-dynamic_cast<Lnumerical*>(L2)->getValue()));
}

//Operator *
Engine::Expression* Engine::MulIntInt::executeAction(Expression* L1,Expression* L2)
{
    return (new Linteger(dynamic_cast<Linteger*>(L1)->getValue()*dynamic_cast<Linteger*>(L2)->getValue()));
}

Engine::Expression* Engine::MulIntReal::executeAction(Expression* L1,Expression* L2)
{
    return (new Lreal(dynamic_cast<Lnumerical*>(L1)->getValue()*dynamic_cast<Lnumerical*>(L2)->getValue()));
}

//Operator /
Engine::Expression* Engine::DivIntInt::executeAction(Expression* L1,Expression* L2)
{
    return (new Lrational(dynamic_cast<Linteger*>(L1)->getValue(),dynamic_cast<Linteger*>(L2)->getValue()));
}

Engine::Expression* Engine::DivIntReal::executeAction(Expression* L1,Expression* L2)
{
    return (new Lreal(dynamic_cast<Lnumerical*>(L1)->getValue()/dynamic_cast<Lnumerical*>(L2)->getValue()));
}


