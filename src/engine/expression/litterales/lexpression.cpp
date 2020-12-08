#include "lexpression.h"
#include "../../computerengine.h"

void Engine::Lexpression::eval(){
    Engine::ComputerEngine::getInstance().getStack().push(this);
}
