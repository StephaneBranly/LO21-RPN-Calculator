#include "lnumerical.h"
#include "../../computerengine.h"

void Engine::Lnumerical::eval(){
    Engine::ComputerEngine::getInstance().getStack().push(this);
}
