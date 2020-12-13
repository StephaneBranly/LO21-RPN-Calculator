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

Engine::Expression* Engine::Lreal::simplifyType(){
    if (roundf(this->real) == this->real)
        return new Linteger(roundf(this->real));
    else return this;
}
