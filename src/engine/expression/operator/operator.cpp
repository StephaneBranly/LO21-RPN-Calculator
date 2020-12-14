#include "operator.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"

void Engine::Operator::eval()
{
    Stack& p = ComputerEngine::getInstance().getStack();
    if(p.size()<getArrity())
        throw ComputerException("Il n'y a pas assez d'items pour executer "+toString());
    else{
        vector<Expression*> l;
        for(size_t i=0;i<getArrity();i++) l.push_back(p.pop());
        try {
            executeOpe(l);
            for(auto it=l.begin();it!=l.end();++it) delete (*it);
        }  catch (ComputerException c) {
            for(auto it=l.begin();it!=l.end();++it) p.push(*it);
            throw ComputerException(c.getInfo());
        }
    }

}

