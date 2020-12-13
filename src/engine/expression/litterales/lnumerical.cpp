#include "lnumerical.h"
#include "../../computerengine.h"

void Engine::Lnumerical::eval(){
    Engine::ComputerEngine::getInstance().getStack().push(this->simplifyType());
}


//Regarder ici si on peut simplifier notre valeur (exemple Lrational avec den = 1 ou real avec partie decimales negatives
