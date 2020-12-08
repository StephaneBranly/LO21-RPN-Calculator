#ifndef COMPUTERENGINE_H
#define COMPUTERENGINE_H

#include "expression/progmanager.h"
#include "expression/varmanager.h"
#include "../observer/subject.h"

#include "expression/expressionmanager.h"
#include "stack/stack.h"

namespace Engine{
class ComputerEngine: public Subject
{
private:
    Stack stack;
    ExpressionManager expressionManager;
    VarManager varManager;
    ProgManager progManager;

    struct Handler
    {
        ComputerEngine *instance = nullptr;
        ~Handler() { delete instance; }
    };
    static Handler hand;

public:
    ComputerEngine();

    Stack& getStack(){ return stack;}
    ExpressionManager& getExpressionManager(){ return expressionManager; }
    static ComputerEngine &getInstance();

    VarManager& getVarManager() { return varManager; }
    ProgManager& getProgManager() { return progManager; }
};
}



#endif // COMPUTERENGINE_H
