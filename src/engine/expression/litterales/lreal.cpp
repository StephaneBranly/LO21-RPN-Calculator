#include "lreal.h"
#include <regex>
#include <string>
#include "../../exception/CompException.h"

Engine::Lreal* Engine::Lreal::setReal(float r){
    real = r;
    return this; //par sure
}

Engine::Lreal::Lreal(const std::string s){
    real = stod(s);
}
