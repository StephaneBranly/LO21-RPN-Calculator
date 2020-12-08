#include "atommanager.h"


bool Engine::AtomManager::alreadyExists(const std::string name)
{
    if(atoms.at(name)) return true;
    return false;
}
Engine::Expression* Engine::AtomManager::getExpressionFromAtom(const Latom* a)
{
    return atoms.at(a->getValue());
}
Engine::Expression* Engine::AtomManager::getExpressionFromString(const std::string s)
{
    return atoms.at(s);
}
void Engine::AtomManager::removeAtom(const std::string name)
{
    atoms.erase(name);
}
void Engine::AtomManager::addAtom(const std::string name, Expression* expression)
{
    atoms.insert(std::pair<std::string,Expression*>(name,expression));
}

