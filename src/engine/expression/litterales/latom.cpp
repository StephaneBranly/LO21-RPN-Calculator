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

// L'evaluation d'un atom
// - empile la Lexpression si l'atom n'est pas defini
// - execute le Lprogram (de maniere explicite) si la Latom est associee a un Lprogram
// - evalue l'Expression associee a la Latom sinon
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
        else
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

