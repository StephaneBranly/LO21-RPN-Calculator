#include "lreal.h"
#include <regex>
#include "ComputerException"

Engine::LReal* Engine::LReal::setReal(float r){
    real = r;
    return this; //par sure
}

Engine::LReal* Engine::LReal::createExpressionFromString(const std::string s){
        regex str_expr ("[0-9]*\\.[0-9]*"); //unkneow type regex
        if (regex_match(s,str_expr))
           {return setReal(std::stoi(s,nullptr,10));}
    else { throw ComputerException("Creation de Lentiere impossible avec "+s);}
}
