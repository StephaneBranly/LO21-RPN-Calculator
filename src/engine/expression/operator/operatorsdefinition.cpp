#include "operatorsdefinition.h"
#include "../../exception/CompException.h"
#include "../../computerengine.h"
#include "../litterales/lprogram.h"
#include "../litterales/lexpression.h"

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
    if(L1->getType()=="Lprogram")
    {
        Lprogram* L = dynamic_cast<Lprogram*>(L1);
        L->explicitEval();
    }else if(L1->getType()=="Lexpression")
    {
        Lexpression* L = dynamic_cast<Lexpression*>(L1);
//        L->explicitEval();
    }
    else
        throw ComputerException(L1->getType()+" ne peut pas être évalué de façon explicite.");

}

