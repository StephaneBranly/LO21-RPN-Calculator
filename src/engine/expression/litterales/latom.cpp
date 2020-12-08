#include "latom.h"
#include <regex>
#include <string>
#include "../../exception/CompException.h"
#include "../atommanager.h"
#include "../../stack/stack.h"
#include "lexpression.h"
#include "../../computerengine.h"

Engine::Latom* Engine::Latom::setLatom(std::string s){
    atom = s;
    return this;
}


void Engine::Latom::eval(){
//    if (isVarId()) {
//        Engine::ComputerEngine::getInstance().getStack().push(this);
//    }
//    if (isProgId()) {
//        //eval prog
//        //coder un getProgId (string id) dans ProgManager
//    }else {
//        Engine::ComputerEngine::getInstance().getStack().push(new Lexpression(atom));
//    }
}

