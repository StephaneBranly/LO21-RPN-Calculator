#include "lreal.h"
#include <regex>
#include "../../exception/CompException.h"

Engine::LReal* Engine::LReal::setReal(float r){
    real = r;
    return this; //par sure
}

Engine::LReal* Engine::LReal::createExpressionFromString(const std::string s){
        std::regex str_expr("[0-9]*\\.[0-9]*");
        if (regex_match(s,str_expr))
           return setReal(std::stoi(s,nullptr,10));
    else { throw ComputerException("Creation de Lentiere impossible avec "+s);}
}

bool Engine::LReal::isSameType(const std::string s) const
{
        std::regex str_expr("[0-9]*\\.[0-9]*");
        return (regex_match(s,str_expr));
};
