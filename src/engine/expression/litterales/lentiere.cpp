#include "lentiere.h"
#include <string>
#include <regex>

Engine::Lentiere::Lentiere()
{


}

void Engine::Lentiere::setLentiere(int v){
    value = v;
}

Engine::Lentiere* Engine::Lentiere::createExpressionFromString(const std::string s){
    if (regex_match(s,regex([\\[0-9]+]););)
       {setLentiere(std::stoi(s,nullptr,10););}
}


