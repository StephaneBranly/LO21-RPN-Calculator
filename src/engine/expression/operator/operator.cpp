#include "operator.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"

void Engine::Operator::eval()
{
    Stack& p = ComputerEngine::getInstance().getStack();
    if(p.size()<getArrity())
        throw ComputerException("Il n'y a pas assez d'items pour executer "+toString());
    executeOpe();
}

