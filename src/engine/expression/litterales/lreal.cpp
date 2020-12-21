#include "lreal.h"
#include <regex>
#include <string>
#include "../../exception/CompException.h"
#include <numeric>
#include <cmath>

Engine::Lreal* Engine::Lreal::setReal(double r){
    real = r;
    return this;
}

Engine::Lreal::Lreal(const std::string s):  Lnumerical("Lreal"){
    real = stod(s); // Conversion de String vers Double
}

Engine::Expression* Engine::Lreal::simplifyType(){
    if (roundf(this->real) == this->real) // On regarde s'il la partie decimale est nulle
        return new Linteger(roundf(this->real));
    else return this;
}
