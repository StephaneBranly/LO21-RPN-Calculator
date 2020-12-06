#include "lnumerical.h"
#include "../../stack/stack.h" //problème sur le path
#include "ComputerEngine"

void Engine::Lnumerical::eval(){
    Engine::ComputerEngine::getInstance().getStack().push(this);
}
