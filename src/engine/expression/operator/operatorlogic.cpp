#include "operatorlogic.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"
#include "../litterales/linteger.h"
#include "../litterales/lreal.h"
#include "../litterales/lrational.h"


bool Engine::OperatorAnd::test(Expression* E1, Expression* E2) const {
    Lnumerical* a=dynamic_cast<Lnumerical*>(E1);
    Lnumerical* b=dynamic_cast<Lnumerical*>(E2);
    return(a->getValue()&&b->getValue());
}

bool Engine::OperatorOr::test(Expression* E1, Expression* E2) const {
    Lnumerical* a=dynamic_cast<Lnumerical*>(E1);
    Lnumerical* b=dynamic_cast<Lnumerical*>(E2);
     return(a->getValue() || b->getValue());
}

bool Engine::OperatorEq::test(Expression* E1, Expression* E2) const {
    Lnumerical* a=dynamic_cast<Lnumerical*>(E1);
    Lnumerical* b=dynamic_cast<Lnumerical*>(E2);
     return(a->getValue()==b->getValue());
}

bool Engine::OperatorNot::test(Expression* E1, Expression* E2) const {
    Lnumerical* a=dynamic_cast<Lnumerical*>(E1);
    return(a->getValue()==0);
}

bool Engine::OperatorGeq::test(Expression* E1, Expression* E2) const {
    Lnumerical* a=dynamic_cast<Lnumerical*>(E1);
    Lnumerical* b=dynamic_cast<Lnumerical*>(E2);
    return(a->getValue()>=b->getValue());
}

bool Engine::OperatorGt::test(Expression* E1, Expression* E2) const {
    Lnumerical* a=dynamic_cast<Lnumerical*>(E1);
    Lnumerical* b=dynamic_cast<Lnumerical*>(E2);
     return(a->getValue()>b->getValue());
}

bool Engine::OperatorLt::test(Expression* E1, Expression* E2) const {
    Lnumerical* a=dynamic_cast<Lnumerical*>(E1);
    Lnumerical* b=dynamic_cast<Lnumerical*>(E2);
    return(a->getValue()<b->getValue());
}

bool Engine::OperatorDiff::test(Expression* E1, Expression* E2) const {
    Lnumerical* a=dynamic_cast<Lnumerical*>(E1);
    Lnumerical* b=dynamic_cast<Lnumerical*>(E2);
     return(a->getValue()!=b->getValue());
}

bool Engine::OperatorLeq::test(Expression* E1, Expression* E2) const {
    Lnumerical* a=dynamic_cast<Lnumerical*>(E1);
    Lnumerical* b=dynamic_cast<Lnumerical*>(E2);
    return(a<=b);
}

void Engine::OperatorLogic::executeOpe()
{
    Stack& p=ComputerEngine::getInstance().getStack();
    Expression* L1=p.top();
    p.pop();
    Expression* L2=p.top();
    if(getArrity()==2) p.pop();
    if(test(L1,L2)) p.push(new Linteger(1));
    else p.push(new Linteger(0));

}











