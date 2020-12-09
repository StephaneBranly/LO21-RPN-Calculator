#include "computerengine.h"

#include "expression/litterales/lintegerfactory.h"
#include "expression/litterales/lrealfactory.h"
#include "expression/litterales/latomfactory.h"
#include "expression/litterales/lexpressionfactory.h"
#include "expression/expression.h"

#include <QDebug>

Engine::ComputerEngine::Handler Engine::ComputerEngine::hand = Engine::ComputerEngine::Handler();

Engine::ComputerEngine::ComputerEngine()
{
    expressionManager.getFactory()->registerFactory(new LintegerFactory);
    expressionManager.getFactory()->registerFactory(new LrealFactory);
    expressionManager.getFactory()->registerFactory(new LatomFactory);
    expressionManager.getFactory()->registerFactory(new LexpressionFactory);
};

Engine::ComputerEngine& Engine::ComputerEngine::getInstance()
{
    if (hand.instance == nullptr)
        hand.instance = new ComputerEngine;
    return *hand.instance;
};
