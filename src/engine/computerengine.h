#ifndef COMPUTERENGINE_H
#define COMPUTERENGINE_H


#include "../observer/subject.h"

#include "expression/expressionmanager.h"
#include "stack/stack.h"

namespace Engine{
class ComputerEngine: public Subject
{
private:
    Stack stack;
    ExpressionManager expressionManager;

    struct Handler
    {
        ComputerEngine *instance = nullptr;
        ~Handler() { delete instance; }
    };
    static Handler hand;

public:
    ComputerEngine();

    Stack getStack(){ return stack; }
    ExpressionManager& getExpressionManager(){ return expressionManager; }

    static ComputerEngine &getInstance();
};
}



#endif // COMPUTERENGINE_H
