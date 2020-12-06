#include "computerengine.h"

#include "expression/litterales/lintegerfactory.h"
#include "expression/litterales/lreal.h"
#include "expression/expression.h"

Engine::ComputerEngine::Handler Engine::ComputerEngine::hand = Engine::ComputerEngine::Handler();

Engine::ComputerEngine::ComputerEngine()
{
    expressionManager.getFactory()->registerFactory(new LintegerFactory);
};

Engine::ComputerEngine& Engine::ComputerEngine::getInstance()
{
    if (hand.instance == nullptr)
        hand.instance = new ComputerEngine;
    return *hand.instance;
};
