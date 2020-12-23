#include "operator.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"


// L'evaluation regarde s'il y a assez d'items dans la pile (en comparant avec l'arrite)
// Puis appele l'execution de l'operateur en envoyant les elements depiles
// S'occupe de rempiler en cas d'erreur
void Engine::Operator::eval()
{
    Stack& p = ComputerEngine::getInstance().getStack();
    if(p.size()<getArrity())
        throw ComputerException("Il n'y a pas assez d'items pour executer "+toString()+".");
    else{
        vector<Expression*> l;
        for(size_t i=0;i<getArrity();i++) l.push_back(p.pop());
        try {
            executeOpe(l);
            for(auto it=l.begin();it!=l.end();++it) delete (*it);
        }  catch (ComputerException c) {
            for(auto it=l.rbegin();it!=l.rend();++it) p.push(*it);
            throw ComputerException(c.what());
        }
    }
    delete this;
}

