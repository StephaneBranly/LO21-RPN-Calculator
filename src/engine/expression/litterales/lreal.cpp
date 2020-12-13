#include "lreal.h"
#include <regex>
#include <string>
#include "../../exception/CompException.h"
#include <numeric>
#include <cmath>

Engine::Lreal* Engine::Lreal::setReal(float r){
    real = r;
    return this;
}

Engine::Lreal::Lreal(const std::string s){
    real = stod(s);
}

Engine::Linteger* Engine::Lreal::simplifyType(){
    if (roundf(this->getfloatvalue()) == this->getfloatvalue())
        return new Linteger(roundf(this->getfloatvalue()));
}
