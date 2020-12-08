#include "latom.h"
#include <regex>
#include <string>
#include "../../exception/CompException.h"
#include "../atommanager.h"
#include "../../stack/stack.h"
#include "lexpression.h"
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
            // execute program
        }
        else if(1)
        {
            e->eval();
        }
    }
    else
    {
        qDebug() << "Here";
        Stack& s = ComputerEngine::getInstance().getStack();
        qDebug() << "Here2";
        Lexpression* e = new Lexpression(atom);
        qDebug() << "Here3";
        s.push(e);
    }
}

