#include "operatorsdefinition.h"
#include "../../exception/CompException.h"
#include "../../computerengine.h"

void Engine::OperatorCLEAR::eval()
{
    Stack& p = ComputerEngine::getInstance().getStack();
    p.clear();
}

