#include "computerengine.h"

namespace Engine{
ComputerEngine::Handler ComputerEngine::hand = ComputerEngine::Handler();

ComputerEngine &ComputerEngine::getInstance()
{
    if (hand.instance == nullptr)
        hand.instance = new ComputerEngine;
    return *hand.instance;
};
}
