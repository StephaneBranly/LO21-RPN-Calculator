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
    ComputerEngine::getInstance().notify("stackChanged");
    items.push_back(item);
}
