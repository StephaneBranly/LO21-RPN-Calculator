#include "latom.h"
#include <regex>
#include <string>
#include "../../exception/CompException.h"
#include "../atommanager.h"
#include "../../stack/stack.h"
#include "lexpression.h"
#include "lprogram.h"
#include "../../computerengine.h"

Engine::Latom* Engine::Latom::setLatom(std::string s){
    atom = s;
    return this;
}


void Engine::Latom::eval(){
    AtomManager& a = ComputerEngine::getInstance().getAtomManager();
    if(a.alreadyExists(atom))
    {
        Expression* e = a.getExpressionFromAtom(this);
        if(e->getType()=="Lprogram")
        {
            Lprogram* prog = dynamic_cast<Lprogram*>(e);
            prog->explicitEval();
        }
        else if(1)
        {
            e->eval();
        }
    }
    else
    {
        Stack& s = ComputerEngine::getInstance().getStack();
        Lexpression* e = new Lexpression(atom);
        s.push(e);
    }
}

