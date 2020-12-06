#include "stack.h"
#include "../expression/expression.h"

Engine::Expression* Engine::Stack::pop()
{
    Expression* item = this->top();
    items.pop_back();
    return item;
};
