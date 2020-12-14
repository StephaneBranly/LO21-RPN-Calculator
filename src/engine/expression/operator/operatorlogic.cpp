#include "operatorlogic.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"
#include "../litterales/linteger.h"
#include "../litterales/lreal.h"
#include "../litterales/lrational.h"


bool Engine::OperatorAnd::test(Lnumerical* E1, Lnumerical* E2) const {
    return(E2->getValue()&&E1->getValue());
}

bool Engine::OperatorOr::test(Lnumerical* E1, Lnumerical* E2) const {
     return(E2->getValue() || E1->getValue());
}

bool Engine::OperatorEq::test(Lnumerical* E1, Lnumerical* E2) const {
     return(E2->getValue()==E1->getValue());
}

bool Engine::OperatorNot::test(Lnumerical* E1, Lnumerical* E2) const {
    return(E1->getValue()==0);
}

bool Engine::OperatorGeq::test(Lnumerical* E1, Lnumerical* E2) const {
    return(E2->getValue()>=E1->getValue());
}

bool Engine::OperatorGt::test(Lnumerical* E1, Lnumerical* E2) const {
     return(E2->getValue()>E1->getValue());
}

bool Engine::OperatorLt::test(Lnumerical* E1, Lnumerical* E2) const {
    return(E2->getValue()<E1->getValue());
}

bool Engine::OperatorDiff::test(Lnumerical* E1, Lnumerical* E2) const {
     return(E2->getValue()!=E1->getValue());
}

bool Engine::OperatorLeq::test(Lnumerical* E1, Lnumerical* E2) const {
    return(E2->getValue()<=E1->getValue());
}

void Engine::OperatorLogic::executeOpe(vector<Expression*> l)
{
    Stack& p=ComputerEngine::getInstance().getStack();
    Expression* L1=l[0];
    Expression* L2=nullptr;
    Lnumerical* L2num=nullptr;
    Lnumerical* L1num=dynamic_cast<Lnumerical*>(L1);
    if(L1num==nullptr)
        throw ComputerException(L1->toString()+" n'est pas du bon type pour l'operation "+toString());
    if(getArrity()==2)
    {
        L2=l[1];
        L2num = dynamic_cast<Lnumerical*>(L2);
        if(L2num==nullptr)
            throw ComputerException(L2->toString()+" n'est pas du bon type pour l'operation "+toString());
    }
    if(test(L1num,L2num)) p.push(new Linteger(1));
    else p.push(new Linteger(0));
}











