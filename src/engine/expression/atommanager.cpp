#include "atommanager.h"
#include "../exception/CompException.h"
#include "../computerengine.h"

bool Engine::AtomManager::alreadyExists(const std::string name)
{
    return atoms.find(name) != atoms.end();
}
Engine::Expression* Engine::AtomManager::getExpressionFromAtom(const Latom* a)
{
    if(alreadyExists(a->getValue()))
        return atoms.at(a->getValue());
    throw ComputerException("Il n'existe pas d'atom "+a->getValue());
}
Engine::Expression* Engine::AtomManager::getExpressionFromString(const std::string s)
{
    if(alreadyExists(s))
        return atoms.at(s);
    throw ComputerException("Il n'existe pas d'atom "+s);
}
void Engine::AtomManager::removeAtom(const std::string s)
{
    if(alreadyExists(s))
    {
        atoms.erase(s);
        ComputerEngine::getInstance().notify("atomsChanged");
    }
    else
        throw ComputerException("Il n'existe pas d'atom "+s);
}

void Engine::AtomManager::addAtom(const std::string name, Expression* expression)
{
    if(alreadyExists(name))
        removeAtom(name);
    atoms.insert(std::pair<std::string,Expression*>(name,expression));
    ComputerEngine::getInstance().notify("atomsChanged");
}


std::list<std::tuple<std::string,std::string,std::string>> Engine::AtomManager::toTupleStringList()
{
    std::tuple<std::string,std::string,std::string> tu;
    std::list<std::tuple<std::string,std::string,std::string>> list;
    for(auto it = atoms.begin(); it!=atoms.end();++it)
    {
        tu = make_tuple((*it).first,(*it).second->toString(),(*it).second->getType());
        list.push_back(tu);
    }
    return list;
}
