#include "stack.h"
#include "../expression/expression.h"

namespace Engine
{
    Expression* Stack::pop()
    {
        Expression* item = this->top();
        items.pop_back();
        return item;
    };
}
