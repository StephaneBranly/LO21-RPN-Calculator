#include "lnumerical.h"
#include "../../computerengine.h"

// L'evaluation d'une Lnumerical correspond juste a l'empilement de celle ci
void Engine::Lnumerical::eval(){
    Engine::ComputerEngine::getInstance().getStack().push(this->simplifyType());
}
