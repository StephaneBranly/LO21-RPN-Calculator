#include "linteger.h"
#include <string>
#include <regex>
#include "../CompException.h"

Engine::Linteger::Linteger(const Linteger& li):value(li.value){}

Engine::Linteger* Engine::Linteger::setLinteger(int v){
    value = v;
    return this; //je suis pas certaine la dessus.
}

//encore des erreurs
Engine::Linteger* Engine::Linteger::createExpressionFromString(const std::string s){
    regex str_expr ("[\\[0-9]+]");
    if (regex_match(s,str_expr))
       {return setLinteger(std::stoi(s,nullptr,10));}
else { throw ComputerException("Creation de Lentiere impossible avec "+s);}
}
