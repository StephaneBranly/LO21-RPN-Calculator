#include "lprogram.h"
#include "../../computerengine.h"
#include "../../exception/CompException.h"

Engine::Lprogram::Lprogram(const Lprogram& p): Expression("Lprogram")
{
    for(auto it = p.content.begin(); it!=p.content.end();++it)
    {
        content.push_back((*it)->getCopy());
    }
}
const std::string Engine::Lprogram::toString() const
{
    std::string str = "[";
    for(auto it = content.begin(); it!=content.end();++it)
    {
        str+=" "+(*it)->toString();
    }
    str+=" ]";
    return str;
}


void Engine::Lprogram::eval()
{
    Engine::ComputerEngine::getInstance().getStack().push(this);
}

void Engine::Lprogram::explicitEval()
{
    for(auto it = content.begin(); it!=content.end();++it)
    {
        try {
            (*it)->eval();
        }  catch (ComputerException e) {
            throw ComputerException(e.what());
        }
    }
}
