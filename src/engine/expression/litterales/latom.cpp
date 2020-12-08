#include "latom.h"
#include <regex>
#include <string>
#include "../../exception/CompException.h"
#include "ProgManager.h"
#include "VarManager.h"
#include "../../stack/stack.h"
#include "lexpression.h"
#include "../../computerengine.h"



Engine::Latom* Engine::Latom::setLatom(std::string s){
    atom = s;
    return this;
}

Engine::Latom::Latom(const std::string s):atom(s){}

bool Engine::Latom::isVarId(){
    for(auto it = VarManager::variables.begin(); it = VarManager::variables.end() ; ++it)
    {
        if (atom == *it){return true;}
        else {return false;}
    }
}

bool Engine::Latom::isProgId(){
    for(auto it = ProgManager::programmes.begin(); it = VarManager::programmes.end() ; ++it)
    {
        if (atom == *it){return true;}
        else {return false;}
    }
}

void Engine::Latom::eval(){
    if (isVarId()) {
        Engine::ComputerEngine::getInstance().getStack().push(this);
    }
    if (isProgId()) {
        //eval prog
        //coder un getProgId (string id) dans ProgManager
    }else {
        new Lexpression(atom);
    }
}
