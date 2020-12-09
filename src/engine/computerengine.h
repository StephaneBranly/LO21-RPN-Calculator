#ifndef COMPUTERENGINE_H
#define COMPUTERENGINE_H

#include "expression/atommanager.h"
#include "../observer/subject.h"

#include "expression/expressionmanager.h"
#include "stack/stack.h"

namespace Engine{
class ComputerEngine: public Subject
{
private:
    Stack stack;
    ExpressionManager expressionManager;
    AtomManager atomManager;

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
    AtomManager& getAtomManager() { return atomManager; }
    static ComputerEngine &getInstance();
};
}



#endif // COMPUTERENGINE_H
