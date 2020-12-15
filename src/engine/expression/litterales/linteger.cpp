#include "linteger.h"
#include <string>
#include <regex>
#include "../../exception/CompException.h"

Engine::Linteger::Linteger(const Linteger& li): Lnumerical("Linteger"),value(li.value){}

Engine::Linteger::Linteger(const std::string s): Lnumerical("Linteger"){
    value = std::stoi(s,nullptr,10);
}

Engine::Linteger* Engine::Linteger::setLinteger(int v){
    value = v;
    return this;
}
