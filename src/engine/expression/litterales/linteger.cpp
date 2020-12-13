#include "linteger.h"
#include <string>
#include <regex>
#include "../../exception/CompException.h"

Engine::Linteger::Linteger(const Linteger& li):value(li.value){}

Engine::Linteger::Linteger(const std::string s){
    value = std::stoi(s,nullptr,10);
}

Engine::Linteger* Engine::Linteger::setLinteger(int v){
    value = v;
    return this;
}
