#include "operatorsdefinition.h"
#include "../../exception/CompException.h"
#include "../../computerengine.h"
#include "../litterales/lprogram.h"
#include "../litterales/lexpression.h"
#include "../litterales/lnumerical.h"

void Engine::OperatorCLEAR::executeOpe()
{
    Stack& p = ComputerEngine::getInstance().getStack();
    p.clear();
}

void Engine::OperatorSWAP::executeOpe()
{
    Stack& p = ComputerEngine::getInstance().getStack();
    p.swap();
}

void Engine::OperatorDROP::executeOpe()
{
    Stack& p = ComputerEngine::getInstance().getStack();
    p.pop();
}

void Engine::OperatorDUP::executeOpe()
{
    Stack& p = ComputerEngine::getInstance().getStack();
    Expression* copy = p.top()->getCopy();
    p.push(copy);
}

void Engine::OperatorEVAL::executeOpe()
{
    Stack& p = ComputerEngine::getInstance().getStack();
    Expression* L1 = p.pop();
    ExplicitEval* isEvaluable = dynamic_cast<ExplicitEval*>(L1);
    if(isEvaluable)
    {
        isEvaluable->explicitEval();
    }
    else
        throw ComputerException(L1->toString()+" ne peut pas être évalué de façon explicite.");
}

void Engine::OperatorSTO::executeOpe()
{
    Stack& p = ComputerEngine::getInstance().getStack();
    Expression* L1 = p.pop();
    Expression* L2 = p.pop();
    Lnumerical* isNumerical = dynamic_cast<Lnumerical*>(L2);
    if(L1->getType()=="Lexpression" && (isNumerical!=nullptr || L2->getType()=="Lprogram"))
    {

        AtomManager& a = ComputerEngine::getInstance().getAtomManager();
        Lexpression* Lexp = dynamic_cast<Lexpression*>(L1);
        if(ComputerEngine::getInstance().getExpressionManager().getFactory()->getOperatorFactory()->isSameType(Lexp->getValue()))
            throw ComputerException(Lexp->getValue()+" est déja prédéfini.");
        a.addAtom(Lexp->getValue(),L2);
    }
    else
        throw ComputerException(L2->toString()+" ne peut pas être sauvegardée.");
}

void Engine::OperatorFORGET::executeOpe()
{
    Stack& p = ComputerEngine::getInstance().getStack();
    Expression* L1 = p.pop();
    if(L1->getType()=="Lexpression")
    {
        AtomManager& a = ComputerEngine::getInstance().getAtomManager();
        Lexpression* Lexp = dynamic_cast<Lexpression*>(L1);
        a.removeAtom(Lexp->getValue());
    }
    else
        throw ComputerException(L1->toString()+" n'est pas un identifiant.");
}
