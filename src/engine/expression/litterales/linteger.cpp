#include "linteger.h"
#include <string>
#include <regex>
#include "../../exception/CompException.h"

Engine::Linteger::Linteger(const Linteger& li): Lnumerical("Linteger"),value(li.value){}

Engine::Linteger::Linteger(const std::string s): Lnumerical("Linteger"){
    try {
        value = std::stoi(s);
    }
    catch (const std::invalid_argument& ia) {
        throw ComputerException("Error, argument invalide.");
    }
    catch (const std::out_of_range& oor){
        throw ComputerException("Error, valeur trop grande.");
    }
    catch (const ComputerException& e )
    {
        throw ComputerException("Error");
    }
}



Engine::Linteger* Engine::Linteger::setLinteger(int v){
    value = v;
    return this;
}

