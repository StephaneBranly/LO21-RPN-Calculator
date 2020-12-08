#include "operatorsdefinition.h"
#include "../../exception/CompException.h"
#include "../../computerengine.h"

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

