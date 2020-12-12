#include "lexpression.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"
#include "lprogram.h"

void Engine::Lexpression::eval(){
    Engine::ComputerEngine::getInstance().getStack().push(this);
}

void Engine::Lexpression::explicitEval(){
    AtomManager a = Engine::ComputerEngine::getInstance().getAtomManager();
    if(a.alreadyExists(expression))
    {
        Expression* e = a.getExpressionFromString(expression);
        if(e->getType()=="Lprogram")
        {
            Lprogram* p = dynamic_cast<Lprogram*>(e);
            p->explicitEval();
        }
        else
            e->eval();
    }
    else
        throw ComputerException(expression+" n'existe pas en tant qu'atom.");
}
