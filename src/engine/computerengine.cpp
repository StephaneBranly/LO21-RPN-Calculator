#include "computerengine.h"

Engine::ComputerEngine::Handler Engine::ComputerEngine::hand = Engine::ComputerEngine::Handler();

Engine::ComputerEngine& Engine::ComputerEngine::getInstance()
{
    if (hand.instance == nullptr)
        hand.instance = new ComputerEngine;
    return *hand.instance;
};
