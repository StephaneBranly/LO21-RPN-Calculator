#include "latom.h"
#include <regex>
#include <string>
#include "../../exception/CompException.h"

Engine::Latom* Engine::Latom::setLatom(std::string s){
    atom = s;
    return this;
}

Engine::Latom::Latom(const std::string s):atom(s){}
