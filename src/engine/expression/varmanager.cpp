#include "varmanager.h"
#include "litterales/latom.h"

bool Engine::VarManager::isVarId(std::string s){
    for(auto it = variables.begin(); it == variables.end() ; ++it)
    {
        if (s == (*it)->Latom::getvalue()){return true;}

    }
    {return false;}
}


//it est de type Latom*
//getValue de it.
