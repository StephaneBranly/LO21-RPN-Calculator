#include "computerengine.h"

#include "expression/litterales/linteger.h"
#include "expression/litterales/lreal.h"
#include "expression/expression.h"

Engine::ComputerEngine::Handler Engine::ComputerEngine::hand = Engine::ComputerEngine::Handler();

Engine::ComputerEngine::ComputerEngine()
{
    Expression* typeInteger = new Linteger();
    Expression* typeReal = new Lreal();
    expressionManager.registerType(typeInteger);
    expressionManager.registerType(typeReal);
};

Engine::ComputerEngine& Engine::ComputerEngine::getInstance()
{
    if (hand.instance == nullptr)
        hand.instance = new ComputerEngine;
    return *hand.instance;
};
