#include "operatorsdefinition.h"
#include "../../exception/CompException.h"
#include "../../computerengine.h"
#include "../litterales/lprogram.h"
#include "../litterales/lexpression.h"
#include "../litterales/lnumerical.h"

void Engine::OperatorCLEAR::executeOpe(vector<Expression*> e)
{
    Stack& p = ComputerEngine::getInstance().getStack();
    p.clear();
}

void Engine::OperatorSWAP::executeOpe(vector<Expression*> e)
{
    Stack& p = ComputerEngine::getInstance().getStack();
    p.push(e[0]->getCopy());
    p.push(e[1]->getCopy());
}

void Engine::OperatorDROP::executeOpe(vector<Expression*> e)
{

}

void Engine::OperatorDUP::executeOpe(vector<Expression*> e)
{
    Stack& p = ComputerEngine::getInstance().getStack();
    p.push(e[0]->getCopy());
    p.push(e[0]->getCopy());
}

void Engine::OperatorEVAL::executeOpe(vector<Expression*> e)
{
    Expression* L1 = e[0];
    ExplicitEval* isEvaluable = dynamic_cast<ExplicitEval*>(L1);
    if(isEvaluable)
    {
        isEvaluable->explicitEval();
    }
    else
        throw ComputerException(L1->toString()+" ne peut pas être évalué de façon explicite.");
}

void Engine::OperatorSTO::executeOpe(vector<Expression*> e)
{
    Expression* L1 = e[0];
    Expression* L2 = e[1];
    Lnumerical* isNumerical = dynamic_cast<Lnumerical*>(L2);
    if(L1->getType()=="Lexpression" && (isNumerical!=nullptr || L2->getType()=="Lprogram"))
    {

        AtomManager& a = ComputerEngine::getInstance().getAtomManager();
        Lexpression* Lexp = dynamic_cast<Lexpression*>(L1);
        if(ComputerEngine::getInstance().getExpressionManager().getFactory()->getOperatorFactory()->isSameType(Lexp->getValue()))
            throw ComputerException(Lexp->getValue()+" est déja prédéfini.");
        a.addAtom(Lexp->getValue(),L2->getCopy());
    }
    else
        throw ComputerException(L2->toString()+" ne peut pas être sauvegardée dans "+L1->toString()+".");
}

void Engine::OperatorFORGET::executeOpe(vector<Expression*> e)
{
    Expression* L1 = e[0];
    if(L1->getType()=="Lexpression")
    {
        AtomManager& a = ComputerEngine::getInstance().getAtomManager();
        Lexpression* Lexp = dynamic_cast<Lexpression*>(L1);
        a.removeAtom(Lexp->getValue());
    }
    else
        throw ComputerException(L1->toString()+" n'est pas un identifiant.");
}

void Engine::OperatorTYPE::executeOpe(vector<Expression*> e)
{
    Stack& p = ComputerEngine::getInstance().getStack();
    p.push(e[0]->getCopy());
    p.push(new Lexpression(e[0]->getType()));
}
