#include "stack.h"
#include "../computerengine.h"
#include "../expression/expression.h"

#include <QDebug>
Engine::Expression* Engine::Stack::pop()
{
    Expression* item = this->top();
    items.pop_back();
    ComputerEngine::getInstance().notify("stackChanged");
    return item;
};


void Engine::Stack::push(Expression* item)
{
    items.push_back(item);
    ComputerEngine::getInstance().notify("stackChanged");
}

void Engine::Stack::clear()
{
    items.clear();
    ComputerEngine::getInstance().notify("stackChanged");
}
void Engine::Stack::swap()
{
    Expression* L1=pop();
    Expression* L2=pop();
    push(L1);
    push(L2);
}
std::list<std::string> Engine::Stack::toStringList()
{
    std::list<std::string> result;
    for(auto it = items.begin(); it!=items.end(); ++it)
        result.push_back((*it)->toString());

    return result;
}
