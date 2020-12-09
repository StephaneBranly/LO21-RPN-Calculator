#include "atommanager.h"
#include "../exception/CompException.h"

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
void Engine::AtomManager::removeAtom(const std::string name)
{
    atoms.erase(name);
}
void Engine::AtomManager::addAtom(const std::string name, Expression* expression)
{
    atoms.insert(std::pair<std::string,Expression*>(name,expression));
}

